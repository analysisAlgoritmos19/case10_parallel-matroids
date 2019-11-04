#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <omp.h>

typedef struct Matroid {
    void *S;
    void *I[20];
    void* (*function) (void *);
    int type_size;
    int size_of_s;
    int size_of_i;
}Matroid;

int is_even(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check; //required

    if(true_number_to_check % 2 == 0)

        return true_number_to_check;

    else

        return false;
}

char is_letter(void* char_to_check){

    char true_char_to_check = *(char*) char_to_check;

    if(isalpha(true_char_to_check)) {
        return true_char_to_check;
    }
    else
        return false;
}

int is_odd(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check; //required

    if(true_number_to_check % 2 != 0)

        return true_number_to_check;

    else

        return false;
}


void print_I_char(Matroid *matroid){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* char_to_print= ((matroid->I[i]));
        printf("%c\n",  char_to_print);
    }
}

void print_I_int(Matroid *matroid){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* number_to_print= ((matroid->I[i]));
        printf("%d\n",  number_to_print);
    }
}

void print_I_float(Matroid *matroid){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* float_to_print= ((matroid->I[i]));
        printf("%f\n",  float_to_print);
    }
}

void print_I_string(Matroid *matroid){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* string_to_print= ((matroid->I[i]));
        printf("%s\n",  string_to_print);
    }
}



void evaluate_matroid(Matroid *matroid, int size_of_s){

    int counter = 0;

    void *element_in_s = matroid->S;

    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        printf("El procesador %d hace la iteracion %d y el contador es %d \n", omp_get_thread_num(), element_in_s_index , counter);

        void* value_to_send = element_in_s + (element_in_s_index * matroid->type_size);

        void * function_result = matroid->function(value_to_send);

        if(function_result){
            matroid->I[counter] = function_result;
            counter++;
        }
    }
    matroid->size_of_i = counter;
}


void evaluate_array_matroid(Matroid* ptr_array_matroid, int sizeArray) {
#pragma omp parallel for
    for (int matroid_index = 0; matroid_index < sizeArray; matroid_index++) {
        printf("%d \n", omp_get_thread_num());
        evaluate_matroid(ptr_array_matroid + matroid_index, ptr_array_matroid->size_of_s);
    }
}

void* intersection_of_two(void* list[], Matroid* ptr_matroid, int list_size){

    void * array_intersection[ptr_matroid->size_of_i];
    int counter = 0;

    printf("El elemento en la lista es %d \n", list[0]);

    printf("list_size %d \n", list_size);

    for (int element_in_list = 0; element_in_list < list_size ; ++element_in_list) {
        for (int element_matroid = 0; element_matroid < ptr_matroid->size_of_i ; ++element_matroid) {
            if(list[element_in_list] == ptr_matroid->I[element_matroid]){
                printf("Interseccion");
                array_intersection[counter] = ptr_matroid->I[element_matroid];
                counter++;
                break;
            }
        }
    }
    printf("El numero es %d \n", array_intersection[1]);
    return array_intersection;
}

void * intersection(Matroid* ptr_array_matroid, int amount_of_matroids){

    void* list[ptr_array_matroid->size_of_i];

    int list_size = ptr_array_matroid->size_of_i;


    for (int element_in_ptr = 0; element_in_ptr < list_size ; ++element_in_ptr) {
        list[element_in_ptr] = ptr_array_matroid->I[element_in_ptr];
    }

    for(int matroid_index = 1; matroid_index < amount_of_matroids; matroid_index++){

        int counter = 0;

        printf("El elemento en la lista es %d \n", list[0]);

        printf("list_size %d \n", list_size);

        for (int element_in_list = 0; element_in_list < list_size ; ++element_in_list) {
            for (int element_matroid = 0; element_matroid < (ptr_array_matroid + matroid_index)->size_of_i ; ++element_matroid) {
                if(list[element_in_list] == (ptr_array_matroid + matroid_index)->I[element_matroid]){
                    printf("Interseccion");
                    list[counter] = (ptr_array_matroid + matroid_index)->I[5];
                    counter++;
                    break;
                }
            }

        }
        /*printf("El numero es %d \n", array_intersection[1]);
        return array_intersection;*/



        intersection_of_two(list, ptr_array_matroid + matroid_index, (ptr_array_matroid + matroid_index - 1)->size_of_i );
    }
    return list;
}

int main() {

    Matroid test_array[3];

    Matroid test1, test2, test3;

    int array1[] = {2, 6, 10, 13, 16, 20};
    int array2[] = {1,2,3,4,5,10};
    int array3[] = {8, 7, 10, 33, 99, 22};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test1.type_size = 4;
    test2.type_size = 4;
    test3.type_size = 4;

    test1.size_of_s = sizeof(array1) / sizeof(array1[0]);
    test1.size_of_s = sizeof(array2) / sizeof(array2[0]);
    test1.size_of_s = sizeof(array3) / sizeof(array3[0]);

    test1.function = is_even;
    test2.function = is_even;
    test3.function = is_even;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    //Change size in matroid->I.

    evaluate_array_matroid(test_array, 3);

    print_I_int(&test_array[0]);

    print_I_char(&test_array[1]);

    print_I_int(&test_array[2]);

    //intersection_of_two(test_array[0].I, &test_array[2], test_array[0].size_of_i);

    printf("Largo de la lista 1.I %d", test_array[0].size_of_i);

    void * list = intersection(test_array,3);

    printf("El primer elemento de list es %d", list);

    for (int i = 0; i < 1 ; ++i) {
        void* number_to_print = list;
        printf("%d\n",  number_to_print);
    }
}
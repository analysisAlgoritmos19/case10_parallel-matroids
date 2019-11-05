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
    #pragma omp parallel for
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* char_to_print= ((matroid->I[i]));
        printf("%c\n",  char_to_print);
    }
}

void print_I_int(Matroid *matroid){
    printf("Esto pertenece a la matroid %d \n", matroid);
#pragma omp parallel for
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* number_to_print= ((matroid->I[i]));
        printf("%d\n",  number_to_print);
    }
}

void print_I_float(Matroid *matroid){
    printf("Esto pertenece a la matroid %d \n", matroid);
#pragma omp parallel for
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* float_to_print= ((matroid->I[i]));
        printf("%f\n",  float_to_print);
    }
}

void print_I_string(Matroid *matroid){

    printf("Esto pertenece a la matroid %d \n", matroid);
#pragma omp parallel for
    for (int i = 0; i < matroid->size_of_i ; ++i) {
        void* string_to_print= ((matroid->I[i]));
        printf("%s\n",  string_to_print);
    }
}

void evaluate_matroid(Matroid *matroid, int size_of_s){

    int counter = 0;

    void *element_in_s = matroid->S;
#pragma omp parallel for
    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {
        //Este print es importante muestra el funcionamineto del parallel pero estorba para el resultado
        //printf("El procesador %d hace la iteracion %d y el contador es %d \n", omp_get_thread_num(), element_in_s_index , counter);

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
        //printf("%d \n", omp_get_thread_num());
        evaluate_matroid(ptr_array_matroid + matroid_index, (ptr_array_matroid+matroid_index)->size_of_s);
    }
}

int intersection_of_two(void* list, Matroid* ptr_matroid,int list_size){

    void * array_intersection[ptr_matroid->size_of_i];
    int counter = 0;

    printf("El elemento en la lista es %d \n", *(int*)list);

    printf("list_size %d \n", list_size);

    for (int element_in_list = 0; element_in_list < list_size ; ++element_in_list) {
        printf("Interseccion es %d\n", (*(int*)(list+(element_in_list*4))));
        for (int element_matroid = 0; element_matroid < ptr_matroid->size_of_i ; ++element_matroid) {
            if((*(int*)list+(element_in_list*4)) == ptr_matroid->I[element_matroid]){
                printf("Interseccion que entro es %d\n", (*(int*)(list+element_in_list)));
                array_intersection[counter] = ptr_matroid->I[element_matroid];
                counter++;
            }
        }
    }
    printf("El numero es %d \n", array_intersection[0]);
    list = array_intersection;
    return counter;
}

void * intersection_aux(Matroid* ptr_array_matroid, int amount_of_matroids){
    void* list = ptr_array_matroid->I;

    int list_size = ptr_array_matroid->size_of_i;

    for(int matroid_index = 1; matroid_index < amount_of_matroids; matroid_index++){
        list_size = intersection_of_two(&list, ptr_array_matroid + matroid_index, list_size);
    }
    for (int j = 0; j < list_size ; ++j) {
        printf("El elemento %d pertenece a la interseccion \n", *(int*)(list+list_size));
    }
}

void *intersection(Matroid* ptr_array_matroid, int amount_of_matroids){

    void* list[ptr_array_matroid->size_of_i];

    int list_size = ptr_array_matroid->size_of_i + 1;

    void* list_aux[ptr_array_matroid->size_of_i];
#pragma omp parallel for
    for (int element_in_ptr = 0; element_in_ptr < list_size ; ++element_in_ptr) {
        list[element_in_ptr] = ptr_array_matroid->I[element_in_ptr];
    }

    for(int matroid_index = 1; matroid_index < amount_of_matroids; matroid_index++){
        int counter = 0;
#pragma omp parallel for collapse(2)
        for (int element_in_list = 0; element_in_list < list_size ; ++element_in_list) {
            for (int element_matroid = 0; element_matroid < (ptr_array_matroid + matroid_index)->size_of_i ; ++element_matroid) {
                if(list[element_in_list] == (ptr_array_matroid + matroid_index)->I[element_matroid]){
                    //printf("Interseccion en el nucleo %d \n", omp_get_thread_num());
                    list_aux[counter] = (ptr_array_matroid + matroid_index)->I[element_matroid];
                    counter++;
                }
            }
        }

        list_size = counter;
        //printf("El largo de list_size despues del for es %d\n", list_size);
        for (int i = 0; i < list_size ; ++i) {
            list[i] = list_aux[i];
        }

        /*printf("El numero es %d \n", array_intersection[1]);
        return array_intersection;*/
        //intersection_of_two(list, ptr_array_matroid + matroid_index, (ptr_array_matroid + matroid_index - 1)->size_of_i );
    }

    //imprimir la interseccion

    printf("\nEl resultado de la interseccion es: \n");
    for (int j = 0; j < list_size ; ++j) {
        printf("El elemento %d pertenece a la interseccion \n", list[j]);
    }
}

int main() {

    Matroid test_array1[3];

    Matroid testEvaluation1, testEvaluation2, testEvaluation3;

    int arrayIntEven[] = {10, 4, 7};
    char lettersArray[] = {'a','?' ,'/', '2'};
    int arrayIntOdd[] = {3,5,10,25,40};

    testEvaluation1.S = arrayIntEven;
    testEvaluation2.S = lettersArray;
    testEvaluation3.S = arrayIntOdd;

    testEvaluation1.type_size = 4;
    testEvaluation2.type_size = 1;
    testEvaluation3.type_size = 4;

    testEvaluation1.size_of_s = sizeof(arrayIntEven) / sizeof(arrayIntEven[0]);
    testEvaluation2.size_of_s = sizeof(lettersArray) / sizeof(lettersArray[0]);
    testEvaluation3.size_of_s = sizeof(arrayIntOdd) / sizeof(arrayIntOdd[0]);

    testEvaluation1.function = is_even;
    testEvaluation2.function = is_letter;
    testEvaluation3.function = is_odd;

    test_array1[0] = testEvaluation1;
    test_array1[1] = testEvaluation2;
    test_array1[2] = testEvaluation3;

    evaluate_array_matroid(test_array1, 3);

    print_I_int(&test_array1[0]);

    print_I_char(&test_array1[1]);

    print_I_int(&test_array1[2]);


    printf("\nDe aqui en adelante es la interseccion de los matroids\n");

    //Con esto se hace la interseccion de matroids
    Matroid test_array[5];

    Matroid test1, test2, test3, test4, test5;

    int array1[] = {2, 6, 10, 13, 16, 20};
    int array2[] = {1,2,6,4,5,10};
    int array3[] = {8, 7, 2, 33, 6, 10};
    int array4[] = {9,4,2,10,42,6,3};
    int array5[] = {2,6,10,5,3,1};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;
    test4.S = array4;
    test5.S = array5;

    test1.type_size = 4;
    test2.type_size = 4;
    test3.type_size = 4;
    test4.type_size = 4;
    test5.type_size = 4;

    test1.size_of_s = sizeof(array1) / sizeof(array1[0]);
    test2.size_of_s = sizeof(array2) / sizeof(array2[0]);
    test3.size_of_s = sizeof(array3) / sizeof(array3[0]);
    test4.size_of_s = sizeof(array4) / sizeof(array4[0]);
    test5.size_of_s = sizeof(array5) / sizeof(array5[0]);

    test1.function = is_even;
    test2.function = is_even;
    test3.function = is_even;
    test4.function = is_even;
    test5.function = is_even;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;
    test_array[3] = test4;
    test_array[4] = test5;

    //Change size in matroid->I.
    evaluate_array_matroid(test_array, 5);

    print_I_int(&test_array[0]);

    print_I_int(&test_array[1]);

    print_I_int(&test_array[2]);

    print_I_int(&test_array[3]);

    print_I_int(&test_array[4]);

    //intersection_of_two(test_array[0].I, &test_array[2], test_array[0].size_of_i);

    intersection(test_array,5);
    return 0;
}
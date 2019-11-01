#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Matroid {
    void *S;
    void *I[6];
    void* (*function) (void *);
    int type_size;
}Matroid;


int is_pair(void* number_to_check){

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


void print_I_char(Matroid *matroid, int array_size){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < array_size ; ++i) {
        void* char_to_print= ((matroid->I[i]));
        printf("%c\n",  char_to_print);
    }
}

void print_I_int(Matroid *matroid, int array_size){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < array_size ; ++i) {
        void* number_to_print= ((matroid->I[i]));
        printf("%d\n",  number_to_print);
    }
}

void print_I_float(Matroid *matroid, int array_size){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < array_size ; ++i) {
        void* float_to_print= ((matroid->I[i]));
        printf("%f\n",  float_to_print);
    }
}

void print_I_string(Matroid *matroid, int array_size){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < array_size ; ++i) {
        void* string_to_print= ((matroid->I[i]));
        printf("%s\n",  string_to_print);
    }
}



void evaluate_matroid(Matroid *matroid, int size_of_s){

    int counter = 0;

    void *element_in_s = matroid->S;

    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        void* value_to_send = element_in_s + (element_in_s_index * matroid->type_size);

        void * function_result = matroid->function(value_to_send);

        if(function_result){
            matroid->I[counter] = function_result;
            counter++;
        }

    }
}


void evaluate_array_matroid(Matroid* ptr_array_matroid, int sizeArray, int size_of_s) {

    for (int matroid_index = 0; matroid_index < sizeArray; matroid_index++) {

        evaluate_matroid(ptr_array_matroid + matroid_index , size_of_s);
    }
}


int main() {

    Matroid matroid2;

    int* a = (int*) calloc(4, sizeof(int));
    a[0] = 5;

    matroid2.S = a;

    matroid2.S[1];

    printf("Probando calloc: %d\n",*(int *)matroid2.S);


    Matroid test_array[3];

    Matroid test1, test2, test3;

    int array1[] = {2, 6, 10, 13, 16, 20};
    char array2[] = {'a', 'b', '3', '%', '5', '*'};
    int array3[] = {8, 7, 10, 33, 99, 22};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test1.type_size = 4;
    test2.type_size = 1;
    test3.type_size = 4;

    test1.function = is_pair;
    test2.function = is_letter;
    test3.function = is_pair;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    //Change size in matroid->I.

    evaluate_array_matroid(test_array, 3, 6);

    print_I_int(&test_array[0], 5);

    print_I_char(&test_array[1],2);

    print_I_int(&test_array[2],3);
}
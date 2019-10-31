#include <stdio.h>
#include <stdbool.h>

typedef struct Matroid {
    void *S;
    void *I[6];
    void* (*function) (void *);
}Matroid;


int is_pair(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check; //required

    if(true_number_to_check % 2 == 0)
        return true_number_to_check;
    else
        return false;
}

void show_elements_in_I(Matroid *matroid, int array_size, int data_type_size){

    printf("Esto pertenece a la matroid %d \n", matroid);
    for (int i = 0; i < array_size ; ++i) {
        void* number_to_print= ((matroid->I[i]));
        printf("%d \n",  number_to_print);
    }
};


int evaluate_matroid(Matroid *matroid, int size_of_s, int type_size){

    int counter = 0;

    void *element_in_s = matroid->S;

    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        void* value_to_send = element_in_s + (element_in_s_index * type_size);

        if(matroid->function(value_to_send)){
            matroid->I[counter] = matroid->function(value_to_send);
            counter++;
        }

    }
    return counter;
}


void evaluate_array_matroid(Matroid* ptr_array_matroid, int sizeArray, int size_of_s, int type_size) {

    for (int matroid_index = 0; matroid_index < sizeArray; matroid_index++) {

            int counter = evaluate_matroid(ptr_array_matroid + matroid_index , size_of_s, type_size);

            show_elements_in_I(ptr_array_matroid + matroid_index, counter, type_size);
        }
}


int main() {

    Matroid test_array[3];

    Matroid test1, test2, test3;

    int array1[] = {2, 6, 10, 13, 16, 20};
    int array2[] = {4, 5, 6, 15, 17, 21};
    int array3[] = {8, 7, 10, 33, 99, 22};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test1.function = is_pair;
    test2.function = is_pair;
    test3.function = is_pair;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    //Change size in matroid->I.

    evaluate_array_matroid(test_array, 3, 6, 4);
}
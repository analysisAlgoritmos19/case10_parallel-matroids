#include <stdio.h>
#include <stdbool.h>

typedef struct Matroid {
    void *S;
    void *I;
    void* (*function) (void *);
}Matroid;


int is_pair(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check;

    if(true_number_to_check % 2 == 0)

        return true_number_to_check;
    else

        return (int) false;
}

int evaluate_matroid(Matroid* matroid, int size_of_s, int type_size){

    int counter = 0;

    void* arrayI [size_of_s];

    void *element_in_s = matroid->S;

    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        void* result_of_function = matroid->function(element_in_s+(element_in_s_index*type_size));

        printf("El valor de result es %d \n", result_of_function);

        if (result_of_function) {

            arrayI[counter] = (element_in_s + (element_in_s_index * type_size));

            counter++;
        }
    }
    matroid->I = arrayI[0];

    return counter;
}

void evaluate_array_matroid(Matroid* ptr_array_matroid, int sizeArray, int size_of_s, int type_size) {

    //int original = ptr_array_matroid;
    for (int matroid_index = 0; matroid_index < sizeArray; matroid_index++) {

        printf("La distancia es %d en el nucleo %d \n", ptr_array_matroid + matroid_index);

            evaluate_matroid(ptr_array_matroid + matroid_index , size_of_s, type_size);
            //ptr_array_matroid++;
        }
}



int main() {

    Matroid test_array[3];

    Matroid test1, test2, test3;

    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    int array3[] = {7, 8, 9};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test1.function = is_pair;
    test2.function = is_pair;
    test3.function = is_pair;


    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    evaluate_array_matroid(test_array, 3, 3, 4);

    printf("El primer valor de I es %d \n", (*(int*)(test_array[1].I)));

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matroid {
    void *S;
    void *I;
    void* (*function) (void *);
    int type_size;
};

bool is_pair(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check;

    //printf("este es el int: %d \n", true_number_to_check);

    if(true_number_to_check % 2 == 0)
        return true;
    else
        return false;
}


int evaluate_matroid(struct Matroid* matroid, int size_of_s){

    //printf("El valor de matroid  es: %d\n",matroid);

    int counter = 0;

    void *arrayI [size_of_s];

    void* element_in_s = matroid->S;

    int num = *(int *)element_in_s;

    //printf("El valor de num es: %d\n",num);


    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        if (matroid->function(element_in_s)){
            arrayI[counter]  = element_in_s;
            printf("El valor del elemento es %d \n", *(int*) arrayI[counter]);
            counter++;
        }
        element_in_s = element_in_s+matroid->type_size;
    }
    printf("El valor de arrayI es %d \n", arrayI);

    printf("El valor de arrayI es %d \n", arrayI[0]);

    printf("El valor de arrayI es %d \n", *(arrayI));
    matroid->I = arrayI[0];
    int result =  *(int *)matroid->I;

    //printf("El valor de matroid es%d \n", matroid);
    return counter;
}

void evaluate_array_matroid(struct Matroid* ptr_array_matroid, int sizeArray, int size_of_s){

    {
        for (int matroid_index = 0; matroid_index < sizeArray; matroid_index++) {

            evaluate_matroid(ptr_array_matroid, size_of_s);

            ptr_array_matroid++;
        }
}


int main() {
    struct Matroid test_array[3];

    struct Matroid test1, test2, test3;

    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    int array3 [] = {7,8,9};


    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test1.type_size = 4;
    test2.type_size = 4;
    test3.type_size = 4;

    //int arrayI2 = {0, 0, 0};

    //test1.I = arrayI2;

    //test_array[0] = test1;
    //test_array[1] = test2;
    //test_array[2] = test3;

    test1.function = is_pair;

    test2.function = is_pair;

    test3.function = is_pair;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    evaluate_array_matroid(test_array, 3,3);

    //test3.function = is_pair;
    //printf("El valor de test1 es: %d\n", test2);

    printf("El primer valor de I es %d \n",*(int*)(test_array[1].I));
    //printf("El primer valor de I es %d \n",*(int*) test2.I);

    //evaluate_matroid(test2, 3);
}

    //int size_of_matroids_list = sizeof(test_array) / sizeof(test_array[0]);

    //printf("%d",size_of_matroids_list);

/*    for (int i = 0; i < 3; ++i) {

        int* result = (int*) test_array[i].I;

        for (int j = 0; j < 3; ++j) {

            int * offset = result + j ;

            //printf("%d\n", *offset);
        }
    }

    //test1.function = &is_pair;


    //functionPtr fnptr = (functionPtr)test1.function;
    //if(fnptr(1))
      //  printf("Lo logre");



    //test1.function = *(void**)(&is_pair);

    //test1.function(3);


    //printf("%d", sizeof(test_array));

    for (int i = 0; i < 3; ++i) {

        struct Matroid matroid_element;

        matroid_element = *(test_array + i);

        void * element = matroid_element.S; //lib hasta aqui.
        int * newelement = (int * )element + i;

        //printf("%d\n",*newelement);

    }
}*/
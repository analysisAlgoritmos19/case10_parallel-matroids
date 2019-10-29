#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matroid {

    void *S;
    void *I;
    void* (*function) (void *);
};

bool is_pair(void* number_to_check){

    int true_number_to_check = *(int*) number_to_check;

    printf("este es el int: %d \n", true_number_to_check);

    if(true_number_to_check % 2 == 0)
        return true;
    else
        return false;
}


int evaluate_matroid (struct Matroid matroid, int size_of_s){

    printf("El valor de matroid S es: %d\n",matroid.S);

    int counter = 0;

    void *arrayI [size_of_s];

    void* element_in_s = matroid.S;

    int num = *(int *)element_in_s;

    printf("El valor de num es: %d\n",num);


    for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

        if (matroid.function(element_in_s)){
            arrayI[counter]  = element_in_s;
            counter++;
        }
        element_in_s = element_in_s+4;
    }
    matroid.I = arrayI;
    int result =  *(int *)matroid.I + 4;
    printf("El valor de matroid I es: %d\n", matroid.I);
    printf("El valor de result es: %d \n", result);
    return counter;
}




int main() {

    //struct Matroid test_array[3];


    struct Matroid test1,test2,test3;

    int array1 [] = {1,2,3};
    int array2 [] = {4,5,6};
    //int array3 [] = {7,8,9};


    test1.S = array1;
    test2.S = array2;
    //test3.S = array3;

    int arrayI2 = {0,0,0};

    test1.I = arrayI2;

    //test_array[0] = test1;
    //test_array[1] = test2;
    //test_array[2] = test3;

    test1.function = is_pair;

    test2.function = is_pair;

    //test3.function = is_pair;

    printf("El valor de test1 es: %d\n",test2);


    evaluate_matroid(test2,3);

    //int size_of_matroids_list = sizeof(test_array) / sizeof(test_array[0]);

    //printf("%d",size_of_matroids_list);

/*    for (int i = 0; i < 3; ++i) {

        int* result = (int*) test_array[i].I;

        for (int j = 0; j < 3; ++j) {

            int * offset = result + j ;

            printf("%d\n", *offset);
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

        printf("%d\n",*newelement);

    }
*/


}
#include <stdio.h>

struct Matroid {

    void *S;
    void *I;
    void *w;
};

void evaluate_matroids (struct Matroid matroids_list[], int size_of_s){

    int size_of_matroids_list = sizeof(matroids_list) / sizeof(matroids_list[0]);

    #pragma omp parallel for

    for (int matroid_index = 0; matroid_index < size_of_matroids_list; ++matroid_index) {

        struct Matroid matroid_element;

        matroid_element = *(matroids_list + matroid_index);

        #pragma omp parallel for

        for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

            void * element_in_s = matroid_element.S + element_in_s_index;

        }



    }

}


int main() {

    //void **ptr; // Declaring the pointer variable 'ptr' of data type int

    //int balance[5] = {100, 2, 3, 7, 150};

    //testMatroid.S = (void **) balance;

    //int *test = (int *) testMatroid.S;

    //ptr= (void**) &balance[0]; // Assigning address of variable 'a' to pointer variable 'ptr'

    //printf("The value inside pointer is= %d",*((int *)testMatroid.S+3)); // See the value is printed using *ptr;


    struct Matroid test_array[3];

    struct Matroid test1,test2,test3;

    int array1 [] = {1,2,3};
    int array2 [] = {4,5,6};
    int array3 [] = {7,8,9};

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    //printf("%d", sizeof(test_array));

    for (int i = 0; i < 3; ++i) {

        struct Matroid matroid_element;

        matroid_element = *(test_array + i);

        void * element = matroid_element.S; //lib hasta aqui.

        int * newelement = (int * )element + i;

        printf("%d\n",*newelement);

    }

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matroid {

    void *S;
    void *I;
    void *function;
};

bool is_pair(int number_to_check){
    if(number_to_check % 2 == 0)
        return true;
    else
        return false;
}

typedef bool (*functionPtr)(int);


void evaluate_matroids (struct Matroid matroids_list[], int size_of_matroid_list, int size_of_s){ //intentar sacar el tamano de s

    //int size_of_matroids_list = sizeof(matroids_list) / sizeof(matroids_list[0]); //works

    #pragma omp parallel for

    for (int matroid_index = 0; matroid_index < size_of_matroid_list; ++matroid_index) {

        struct Matroid matroid_element;

        matroid_element = *(matroids_list + matroid_index);

        functionPtr fnptr = (functionPtr)matroid_element.function; //use the 'generic' function pointer in order to implement the function.

        int counter = 0;

        #pragma omp parallel for

        for (int element_in_s_index = 0; element_in_s_index < size_of_s ; ++element_in_s_index) {

            void *element_in_s = matroid_element.S + element_in_s_index;

            if (fnptr((int) element_in_s)) {

                matroid_element.I[counter];
                counter++;
            }
        }

    }

}

int main() {

    struct Matroid test_array[3];

    struct Matroid test1,test2,test3;

    int array1 [] = {1,2,3};
    int array2 [] = {4,5,6};
    int array3 [] = {7,8,9};

    int array4 [3];
    int array5 [3];
    int array6 [3];

    test1.S = array1;
    test2.S = array2;
    test3.S = array3;
    test1.I = array4;
    test2.I = array5;
    test3.I = array6;

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    test1.function = &is_pair;

    test2.function = &is_pair;

    test3.function = &is_pair;



    //evaluate_matroids(test_array,3,3);

    //int size_of_matroids_list = sizeof(test_array) / sizeof(test_array[0]);

    //printf("%d",size_of_matroids_list);

    for (int i = 0; i < 3; ++i) {

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
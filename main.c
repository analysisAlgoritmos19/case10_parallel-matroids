#include <stdio.h>

struct Matroid {

    void *S;
    void *I;
    void (*W) (void*,...);
};

void sum(int value1){
    printf("%d\n", value1);
}

int main() {


    struct Matroid test_array[3];

    struct Matroid test1,test2,test3;

    int array1[] = {1,2,3};
    int array2[] = {4,5,6};
    int array3[] = {7,8,9};

    test1.S =  array1;
    test2.S =  array2;
    test3.S =  array3;

    void (*test) (int) = sum;

//printf("%d\n", test);

    test(4);

    test1.W = test;

    void (*test6) (int) = test1.W;

    test6(5);

    test_array[0] = test1;
    test_array[1] = test2;
    test_array[2] = test3;

    int longitud = sizeof(test_array) / sizeof(test_array[0]);

    printf("%d\n", longitud);

    for (int i = 0; i < 3; ++i) {

        int* result = (int*) test_array[i].S;

        int * offset = result;

        for (int j = 0; j < 3; ++j) {

            printf("%d\n", *offset);

            offset++;
        }
    }


    void **ptr; // Declaring the pointer variable 'ptr' of data type int

    char a = 'b'; // Declaring a normal variable 'a' and assigning value 10 to it.

    //printf("%d", a);

    ptr= (void**) &a; // Assigning address of variable 'a' to pointer variable 'ptr'

    printf("The value inside pointer is= %c",*ptr); // See the value is printed using *ptr;

}
#include <stdio.h>

struct Matroid {

    void *S;
    void *I;
    void *w;
};


int main() {

    void **ptr; // Declaring the pointer variable 'ptr' of data type int

    char a = 'b'; // Declaring a normal variable 'a' and assigning value 10 to it.

    printf("%d", a);

    //ptr= (void**) &a; // Assigning address of variable 'a' to pointer variable 'ptr'

    //printf("The value inside pointer is= %c",*ptr); // See the value is printed using *ptr;

}
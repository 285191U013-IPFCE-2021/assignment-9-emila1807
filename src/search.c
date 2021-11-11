#include "search.h"
#include <stdbool.h>
#include <stdio.h>//Is this required to be here?


/* The program uses a recursive function to locate X inside of an array*/

bool search(int a[], int n, int x){//This is the recursive function
    int recurssion;//Declaration of function
 
    n--;
 
    if (n >= 0) {//If loop
        if (a[n] == x)
            return n;
        else
            recurssion = search(a, n, x);
    }
    else
        return -1;
 
    return recurssion;//Returns the value inside the integer
}
 
int main(void) {
    int a[] = {5, 10, 50, 25, 9};//The array
    int size = sizeof(a) / sizeof(a[0]);
    int x = 50;//The X value we are looking for inside the array
    int n = 5;//This number indicates how many values will be scanned in the array
    int index;//Int that helps us search trough the array and store the value
 
    index = search(a, n, x);
 
    if (index != -1)
        printf("The X value %d is present at index %d", x, index);//Succes!
    else
        printf("The X value %d is not present in the array", x);/* Either the X value is not present in the array or there the N integer is too low */
 
    return 0;
}

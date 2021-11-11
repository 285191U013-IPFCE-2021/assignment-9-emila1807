#include "sum.h"
#include <stdio.h>//Is this required to be here?
#include <assert.h>

//Calculate array size
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// Return sum of elements in A[0..N-1]
// using recursion.

int sum(int a[], int n)
{

    assert(n >= 0);//Just a simple check to make sure the program works as intended

if (n <= 0)
{
    return 0;
}
    return (sum(a, n - 1) + a[n - 1]);//Recursive function since sum is called inside it's own function
}
    
    
    /* This was a main function used for testing the program while i was working on it, i left it in here for my 
    * own convineince but it is made inactive due to all of the code being included inside the comment.
    
    int main()
{

    int a[] = { 1, 2, 3, 4, 5 };
    //calculate array size
    int N = ARRAY_SIZE(arr);
    printf("%d\n", sum(arr, n));

return 0;
} 

*/
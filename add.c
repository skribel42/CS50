#include <stdio.h>
#include <cs50.h>
//function prototype / header
int sum(int a, int b);


int main(void)
{
    int a = get_int("enter a number: ");
    int b = get_int("enter another number: ");

    int result = sum(a, b); // compute the sum
    printf("The sum of %i and %i = %i\n", a, b, result);
}

//  return type, funtion name (input type, variablename, ...))
int sum(int a, int b) //not related to a and b in the main function
{
    int temp = a + b; //storing sumof a and b in a variable called temp
    return temp; // returns the value stored in temp
}

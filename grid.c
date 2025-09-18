#include <stdio.h>
#include <cs50.h>
/*
Here's a sample program that prints a grid
*/
int main(void)
{
    //variables to represent the size of grid
    int rows = get_int("Enter the number of rows: "); //asking for input
    int columns = get_int("Enter the number of columns: ");
    // nested for loops below
    /// row: outer for-loop
    for(int row=0; row < rows; row++)
    {

        //columns: inner for-loop
        for(int col=0; col < columns; col++)
        {
            printf("| (%i, %i) |", row, col);

        }

        printf("\n");
    }

}

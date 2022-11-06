#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        // Putting space before the Brick for each row till the last.
        for (int j = 1; j <= n-i; j++)
        {
            printf(" ");
        }

        // Printing Bricks.
        for (int k = 1; k <= i; k++)
        {
            //
            printf("#  #");
        }
        // Go down a line.
        printf("\n");
    }
}
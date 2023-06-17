
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints the last digit of a randmoly generated number
 * and whether it is is greater than 5, less than 6, or 0.
 *
 * Return: Always 0.
 */
int main(void)
{       
        int n;
        srand(time(0));
        n = rand() - RAND_MAX / 2;

        if ((n % 10) > 5)
        {
                   printf("Last digit of %d is %d and is greater than 5\n", n, n %  10);
        }
        Else if ((n % 10) < 6 && (n % 10) != 0)
        }
                    Printf(“Last digit of %d is %d and is less than 6 and not 0\n,
                                                                                              
                                 n, n % 10);
        }
        else
        {
                    Printf(“Last digit of %d is %d and is o\n”,
                                  n, n % 10);
         }
         return (0);
}

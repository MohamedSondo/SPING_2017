#include <stdio.h>
#include <string.h>


// int main(int argc, char const *argv[])
// {


// 	char fname[30], lname[30];
// 	//printf("this will print to the screen\n");

// 	printf("what is you fname?\n");
// 	scanf("%s%s", fname);//,lname);
// 	printf("what is you lname?\n");
// 	scanf("%s%s", fname);//,lname);
// 	printf(" your name is %s %c %c \n\n", fname,lname);

// 	return 0;
// }


#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long factorial = 1;

    printf("Enter an integer: ");
    scanf("%d",&n);

    // show error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}
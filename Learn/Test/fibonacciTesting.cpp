#include <stdio.h>
#include <string.h>

/*
    Fahri Fadhil Muhammad
    NIM : 2802454770

    #Question 0: Pseuco-code

    - Receiving input from the user (assuming NIM digit would be 10 at max);
    - Function must return the sumCount of all match 'fibonacci' value
    - Must use recursion? (as per the instruction, even tho array storing search prolly would do better)

    = Thought process:
    - After inputting, keep the NIM in char-type. (i use char type to reduce memory capacity)
    - Then throw the value to a translator that turns char into int by using of ascii. (any char that not 0-9 will be -1)
    - Then the translated value will undergo a recursive functions that determins if the value is fibonaccior not.
    - I'll use two recursive, the normal fibonacci func, adn the checkForFibonacci func.
    - The function will repeat to search the fibonacci from 1 until the output exceed the value in array.
    - Then the output will give 0 or 1 to be added to the total count (1 if the value match a certain fibonacci value).

    ? Alternative:
    - since we're checking per digit in the NIM, just check the value if its match the 1 digit fibonacci (1, 2, 3, 5, 8)

*/

int fibonacci(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int checkforFibonacci(int x, int i)
{
    int currNum = fibonacci(i);
    if (currNum > x)
        return 0;
    if (currNum == x)
        return 1;
    return checkforFibonacci(x, i + 1);
}

void translate(int i, char x, int *arr)
{
    if (x >= '0' && x <= '9')
    {
        arr[i] = x - '0';
    }
    else
    {
        arr[i] = -1;
    }
}

int main()
{
    char nim[11];
    scanf("%s", nim);

    int n = strlen(nim);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        translate(i, nim[i], arr);
    }

    int fibonacciCount = 0;

    for (int i = 0; i < n; i++)
    {
        fibonacciCount += checkforFibonacci(arr[i], 1);
    }

    printf("%d\n", fibonacciCount);

    return 0;
}
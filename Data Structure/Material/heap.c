#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100];
int n = 0;

void insert(int num) {
    arr[n] = num;

    int idx = n;
    while (idx >  1 && arr[idx/2] > num)
    {
        if (arr[idx/2 > num])
        {
            int temp = arr[idx];
            arr[idx] = arr[idx/2];
            arr[idx/2] = temp;

            idx/=2;
        }
    }  
    n++; 
}

void deleteMin() {
    arr[0] = arr[n-1];
    int idx = 1;
    int idxMin;
    if (arr[idx*2] > arr[idx*2+1])
    {
        idxMin = idx*2;
    } else {
        idxMin = idx*2+1;
    }
    
    

}

int findMin() {
    return arr[0];
}

int main() {
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    insert(5);

    return 0;
}
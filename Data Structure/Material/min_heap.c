#include <stdio.h>
#include <stdlib.h>

int arr[100];
int n = 0;   

void insert(int num) {
    n++;
    arr[n] = num;

    int idx = n;
    while (idx > 1 && arr[idx] < arr[idx / 2]) {

        int temp = arr[idx];
        arr[idx] = arr[idx / 2];
        arr[idx / 2] = temp;

        idx /= 2;
    }
}

void deleteMin() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    arr[1] = arr[n];
    n--;

    // Heapify down
    int idx = 1;
    while (idx * 2 <= n) {
        int child = idx * 2;

        // Choose the smaller child
        if (child + 1 <= n && arr[child + 1] < arr[child]) {
            child++;
        }

        // If parent is already smaller, stop
        if (arr[idx] <= arr[child]) break;

        // Swap
        int temp = arr[idx];
        arr[idx] = arr[child];
        arr[child] = temp;

        idx = child;
    }
}

int findMin() {
    if (n == 0) return -1; // Or some error signal
    return arr[1];
}

void printHeap() {
    printf("Heap: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    insert(5);

    printHeap(); // Should print a min-heap

    printf("Min: %d\n", findMin());

    deleteMin();
    printHeap(); // Root (min) removed

    return 0;
}
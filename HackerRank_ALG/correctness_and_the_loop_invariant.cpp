#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

void print(int N, int arr[]) {
    for (int i = 0; i < N; i++) {
        printf("%d",arr[i]);
        printf(" ");
    }
}

void insertionSort(int N, int arr[]) {
    for (int i = 1; i < N; i++) {
        int val = arr[i], pre = i - 1;
        while (pre >= 0 && val < arr[pre]) {
            arr[pre + 1] = arr[pre];
            pre -= 1;
        }
        arr[pre + 1] = val;
    }
    print(N, arr);
}

/*void insertionSort(int N, int arr[]) {
    int i, j;
    int value;
    for(i = 1; i < N; i++)
    {
        value = arr[i];
        j = i - 1;
        while(j > 0 && value < arr[j])
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = value;
    }
    for(j = 0; j < N; j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}*/
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}

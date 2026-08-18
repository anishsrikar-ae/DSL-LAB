#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int arr[], int n){

    for(int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printArray(arr, n);
}

int printArray(int arr[],int n){
    printf("Sorted Array: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int SelectionSort(int arr[], int n){
    for (int i = 0; i<n; i++){
        int low = i;
        for (int j=i; j<n; j++){
            if (arr[j]<arr[low]){
                low = j;
            }
        }

        int temp = arr[low];
        arr[low] = arr[i];
        arr[i] = temp;

    }
    printArray(arr, n);
}

int InsertionSort(int arr[], int n){
    for(int i=1; i< n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printArray(arr, n);
}


int main()
{
    int n, key;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int array[n];

    printf("Enter Elements: ");
    for(int i =0; i<n; i++){
        scanf("%d", &array[i]);
    }

    printf("unsorted Array: ");
    for (int i=0; i<n; i++){
        printf("%d ", array[i]);
    }

    printf("\n1. Bubble Sort");
    printf("2. Selection Sort");
    printf("3. Insertion Sort");
    printf("\nEnter choice: ");
    scanf("%d", &key);

    switch(key){
    case 1:
        BubbleSort(array, n);
        break;
    case 2:
        SelectionSort(array, n);
        break;

    case 3:
        InsertionSort(array, n);
        break;
    default:
        printf("Invalid Input!");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int n, int key){
    int low =0;
    int high = n-1;
    int mid = (low + high)/2;
    int index = -1;

    while (low<high){
        if (arr[mid]<key){
            low = mid + 1;
            mid = (low + high)/2;
        }
        else if (arr[mid]>key){
            high = mid - 1;
            mid = (low + high)/2;
        }
        else if (arr[mid]==key){
            index = mid;
            return index;
        }
    }
    return index;

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

    printf("Enter key: ");
    scanf("%d", &key);

    int index = BinarySearch(array, n, key);

    if (index>=0){
        printf("Element was found at index %d", index);
    }
    else{
        printf("Element was not found!");
    }

    return 0;
}

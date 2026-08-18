#include <stdio.h>
#include <stdlib.h>

recursiveSelectionSort(int *p, int n){
    if (n==1){
        return;
    }
    int *smallest = p;


    for(int i=0; i<n; i++){
        if (*(smallest)>= *(p+i)){
            smallest = p+i;
        }
    }
    int temp = *p;
    *p = *smallest;
    *smallest = temp;

    return  recursiveSelectionSort(p+1, n-1);

}


int main()
{
    int n;

    scanf("%d", &n);

    int *p = (int *)malloc(n*sizeof(int));

    if (p==NULL){
        printf("Memory Allocation Failed.");
        return 1;
    }

    for(int i=0; i<n; i++){
        scanf("%d", p+i);
    }
    recursiveSelectionSort(p, n);

    printf("Sorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }

    return 0;
}

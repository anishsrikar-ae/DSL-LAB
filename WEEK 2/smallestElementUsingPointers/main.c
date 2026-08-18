#include <stdio.h>
#include <stdlib.h>

int smallest(int *p, int n){
    int smallestEle = 0;

    for(int i=0; i<n; i++){
        if (*(p+smallestEle) >= *(p+i)){
            smallestEle = i;
        }
    }

    return smallestEle;

}


int main()
{
    int n;

    scanf("%d", &n);

    int *p = (int *)malloc(n*sizeof(int));

    if (p == NULL){
        printf("Memory Allocation Failed.");
        return 1;

    }

    for(int i=0; i<n; i++){
        scanf("%d", p+i);
    }

    int pos = smallest(p, n);

    printf("Smallest Element is at %d: ", pos);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int ** createArray(int a, int b){
    int **p = (int **)malloc(a*sizeof(int *));

    for(int i=0; i<a; i++){
        *(p+i) = (int *)malloc(b*sizeof(int));
    }
    if (p == NULL){
        printf("Memory Allocation Failed.");
        return 1;
    }

    printf("\nEnter Elements: \n\n");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("\nElement [%d][%d]: ", i+1, j+1);
            scanf("%d", (*(p+i)+j));
        }
    }
    return p;
}

void printArray(int **p, int a, int b){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("\nElement [%d][%d]: %d", i+1, j+1, *(*(p+i)+j));
        }
    }
}

int ** productArrays(int **p, int **q, int a, int b, int n, int m){
    if (b!=n){
        printf("INVALID DIMENSIONS.");
        return;
    }

    int **product = (int **)malloc(a*sizeof(int *));
    for(int i=0; i<a; i++){
        *(product+i) = (int *)malloc(m*sizeof(int));
    }
    if(product==NULL){
        printf("Memory Allocation Failed.");
        exit(1);
    }

    for(int i=0; i<a;i++){
        for(int j=0; j<m;j++){
            *(*(product+i)+j)=0;
            for(int k=0; k<b; k++){
                *(*(product+i)+j) += (*(*(p+i)+k)) * (*(*(q+k)+j));
            }
        }
    }
    return product;
}


int main()
{
    int n, m;

    printf("\nEnter Number of Rows and Columns of First Matrix: ");
    scanf("%d%d", &n, &m);

    int **p = createArray(n, m);
    printArray(p,n,m);


    int a, b;

    printf("\nEnter Number of Rows and Columns of Second Matrix: ");
    scanf("%d%d", &a, &b);
    int **q = createArray(a, b);
    printArray(q, a, b);

    int **prod = productArrays(p, q, n, m, a, b);
    printArray(prod, n, b);

    return 0;
}

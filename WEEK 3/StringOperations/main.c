#include <stdio.h>
#include <stdlib.h>

void concat(char* str, char* str2, char* newString){
    int i=0,j=0;
    while (*(str+i) != '\0'){

        newString[i] = *(str+i);
        i++;
    }
    while(*(str2+j)!='\0'){
        newString[i+j] = *(str2+j);
        j++;
    }
    newString[i+j] = '\0';
}

int compareString(char* str, char* str2){
    int i=0, j=0;

    while(*(str+i)!= '\0' && *(str2+j)!='\0'){
        if (*(str+i) != *(str2+j)){
            if (*(str+i) >= *(str2+j)){
                return 1;
            }else{
                return -1;
            }
        }
        i++, j++;
    }
    return 0;
}



int main()
{

    char str[100],str2[100], newString[200];

    printf("Enter a String: ");
    gets(str);
    printf("Entered String: ");
    puts(str);

    int i=0;

    while(*(str+i) != '\0'){
        i++;
    }

    printf("Length of String: %d", i);


    printf("\n\nEnter String to perform operations: ");
    gets(str2);

    concat(str, str2, newString);
    int res=compareString(str, str2);

    printf("\nConcatenated String: ");
    puts(newString);

    printf("\nThe two strings are: %d", res);

    return 0;
}

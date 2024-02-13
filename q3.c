#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void swapStr(char a[100], char b[100]) {
    char c[100];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}

int main(){

    int i, j, n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    char str[100][100];
    printf("Enter Strings: ");
    for(i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    pid_t p1 = fork();

    if(p1 == 0) {
        printf("Child Process 1 : Bubble Sort\n");
        for(i = 0; i < n; i++) {
            for(j = 0; j < n-i-1; j++) {
                if(strcmp(str[j], str[j+1]) > 0) {
                    swapStr(str[j], str[j+1]);
                }
            }
       }

       for(i = 0; i < n; i++) {
            printf("%s ", str[i]);
       }
       printf("\n");
    } 

    else {
      wait(NULL);
      pid_t p2 = fork();
      
      if(p2 == 0) {
        int pos;
        printf("Child Process 2: Selection Sort\n");
        for(i = 0; i < n; i++) {
            pos = i;
            for(j = i + 1; j < n; j++) {
                if(strcmp(str[j], str[pos]) < 0) {
                    pos = j;
                }
            }
            swapStr(str[i], str[pos]);
        }
        
       for(i = 0; i < n; i++) {
            printf("%s ", str[i]);
        }
        printf("\n");
    
    } else {

        wait(NULL);
        printf("Unsorted: ");
        for(i = 0; i < n; i++) {
            printf("%s ", str[i]);
        }
        printf("\n");
    
        wait(NULL);
        }

    }

    return 0;
}

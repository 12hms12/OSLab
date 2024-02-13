#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{
    pid_t child = fork();
    int i,j;
    pid_t *status;

    if(child == 0){
        printf("Child Process\nSorted Strings: ");
        for(i=1;i<argc-1;i++){
            for(j=i+1;j<argc ; j++){
                if(strcmp(argv[i],argv[j])>0){
                    char *temp = argv[i];
                    argv[i] = argv[j];
                    argv[j] = temp;
                }
            }
        }

        for(i=1;i<argc;i++){
            printf("%s ",argv[i]);
        }
        printf("\n");
    }

    else if(child > 0 ){
        wait(status);
        printf("Parent Process\nUnsorted String: ");
        for(i=1;i<argc;i++){
            printf("%s ",argv[i]);
        }
    }

    else 
        printf("\nForking Failed. ");

    return 0;
}
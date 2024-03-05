#include <stdlib.h>
#include <stdio.h>

typedef struct memory_block {
    int size;
} memory_block;

// Function to implement first fit
int *FirstFit(memory_block *mem, int n, int size) {
    for (int i = 0; i < n; i++) {
        if (/*!mem[i].allocated && */ mem[i].size >= size) {
            mem[i].size -= size;
            //mem[i].allocated = 1;
            return i;
        }
    }
    return -1;
}

int main() {
    int num;
    int i;
    printf("Enter number of Memory Blocks: ");
    scanf("%d", &num);

    memory_block *mem = (memory_block *)malloc(num * sizeof(memory_block));

    // Initializing Memory
    for (i = 0; i < num; i++) {
        printf("Enter size of Block %d: ",i);
        scanf("%d",&mem[i].size);
    }

    int nop;
    printf("Enter Number of processes: ");
    scanf("%d", &nop);

    int process_size[nop];
    printf("Enter size of processes:\n");
    for (i = 0; i < nop; i++) {
        printf("Process %d: ", i);
        scanf("%d", &process_size[i]);
    }

    for (i = 0; i < nop; i++) {
        int alloc_mem = FirstFit(mem, num, process_size[i]);
        if (alloc_mem  >= 0) {
            printf("Process %d memory allocated in Block %d\n", i, alloc_mem);
        } else {
            printf("Process %d memory allocation failed\n", i);
        }
    }

    return 0;
}

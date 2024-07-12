#include <stdio.h>
#include <string.h>

void bestFit(int blockSize[], int m, int n, int processSize[]){
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for(int i=0; i<n; i++){
        int bestdlx = -1;
        
        for(int j=0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                if(bestdlx == -1){
                    bestdlx = j;
                }

                else if(blockSize[bestdlx] > blockSize[j]){
                    bestdlx = j;
                }
            }
        }

        if(bestdlx == -1){
            allocation[i] = bestdlx;
            blockSize[bestdlx] = blockSize[bestdlx] - processSize[i];
        }
    }

    printf("Process NO\t\tProcess Size\t\tBlock No\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t", i+1, processSize[i]);

        if(allocation[i] != -1){
            printf("%d", allocation[i] + 1);
        }
        else{
            printf("Not Allocated");
        }
        printf("\n");
    }

    printf("Free Blocks");
    for(int j=0; j<m; j++){
        printf("%d", blockSize[j]);
    }
}
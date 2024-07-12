#include <stdio.h>
#include <string.h>

void worstFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for(int i=0; i<n; i++){
        int wstdlx = -1;

        for(int j=0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                if(wstdlx == -1 || blockSize[wstdlx] < blockSize[j]){
                    wstdlx = j;
                }
            }
        }

        if(wstdlx != -1){
            allocation[i] = wstdlx;
            blockSize[wstdlx] = blockSize[wstdlx] - processSize[wstdlx];
        }
    }

    printf("Process No\t\tProcess Size\t\tBlock No.");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d", i+1, processSize[i]);
        if(allocation[i] != -1){
            printf("%d", allocation[i] + 1);
        }
        else{
            printf("Not allocated");
        }
        printf("\n");
    }

    printf("Free Blocks\n");
    for(int j=0; j<m; j++) printf("%d->", blockSize[j]);

}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
    return 0;
}


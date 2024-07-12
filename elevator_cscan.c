#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FLOORS 100 

int calculateTotalSeekTime(int *floors, int num_of_passengers){
    int totalSeekTime = 0;
    int currentTrack = 0;
    int direction = 1;

    for(int i=0; i < num_of_passengers -1; i++){
        for(int j=0; j < num_of_passengers - i - 1; j++){
            if(floors[j] > floors[j+1]){
                int temp = floors[j];
                floors[j] = floors[j+1];
                floors[j+1] = temp;
            }
        }
    }

    for(int i=0; i<num_of_passengers; i++){
        while(currentTrack >= 0 && currentTrack <= 199){
            if(floors[i] == currentTrack){
                totalSeekTime += abs(currentTrack - floors[i]);
                floors[i] = -1; 
                break;
            }

            currentTrack += direction;
            totalSeekTime++;
        }

        if(currentTrack == 200){
            direction = 1;
            currentTrack = 0;
        }
    }
    return totalSeekTime;
}



int main(){
    int floors[MAX_FLOORS];
    int num_of_passengers;

    printf("Enter number of passengers");
    scanf("%d", &num_of_passengers);

    if(num_of_passengers <= 0 || num_of_passengers > MAX_FLOORS){
        printf("Invalid number of passengers");
        return 1;
    }

    printf("Enter the floors");
    for(int i=0; i<num_of_passengers; i++){
        scanf("%d", &floors[i]);
    }

    int totalSeekTime = calculateTotalSeekTime(floors, num_of_passengers);
    printf("Total time using CSCAN: %d", totalSeekTime);

    return 0;
}
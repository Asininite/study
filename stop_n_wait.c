#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 3
#define TOTAL_PACKETS 5

int simulate_acknowledgement() {
    return rand() % 10 < 7; // 70% chance of successful ACK
}

int main() {
    srand(time(0));

    int packet = 1;
    int ack_received;

    while (packet <= TOTAL_PACKETS) {
        printf("Sender : sending packet %d\n", packet);

        // Simulate waiting for acknowledgment
        sleep(1);
        ack_received = simulate_acknowledgement();

        if (ack_received) {
            printf("Receiver : ACK for packet %d received\n\n", packet);
            packet++; // Move to the next packet
        } else {
            printf("Receiver : ACK for packet %d lost! Retransmitting...\n\n", packet);
            sleep(TIMEOUT); // Wait before retransmitting
        }
    }

    printf("All packets sent successfully!\n");
    return 0;
}

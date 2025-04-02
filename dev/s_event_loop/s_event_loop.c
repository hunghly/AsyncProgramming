#include <stdio.h>
#include <stdbool.h>

// Simulated event handler
void handleEvent() {
    // In a real application, this function would process real events.
    printf("Handling an event!\n");
}

int main() {
    bool running = true;
    int eventCount = 0;

    while (running) {
        // Simulate checking for events.
        printf("Checking for events...\n");

        // Simulate an event if eventCount is less than 5.
        if (eventCount < 5) {
            handleEvent();
            eventCount++;
        } else {
            // Stop the loop once enough events have been processed.
            running = false;
        }
    }
    
    printf("Event loop terminated.\n");
    return 0;
}

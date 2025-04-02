#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create structure for event type
typedef enum {
    EVENT_TIMER,
    EVENT_IO
} EventType;

// Event structure
typedef struct {
    EventType type;
    int id;
} Event;

void handleTimerEvent(Event* event) {
    printf("Handling TIMER event w/ id %d\n", event->id);
}

void handleIOEvent(Event* event) {
    printf("Handling IO event w/ id %d\n", event->id);
}

int main() {
    const int eventCount = 10;
    Event events[eventCount];

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Populate events with random types
    for (int i = 0; i < eventCount; i++) {
        events[i].id = i;
        // Randomly assign an event type (0 for timer, 1 for I/O)
        if (rand() % 2 == 0)
            events[i].type = EVENT_TIMER;
        else
            events[i].type = EVENT_IO;
    }

    // Event loop
    int currentEvent = 0;
    while (currentEvent < eventCount) {
        Event event = events[currentEvent];
        printf("Checking event with id: %d\n", event.id);

        switch(event.type) {
            case EVENT_TIMER:
                handleTimerEvent(&event);
                break;
            case EVENT_IO:
                handleIOEvent(&event);
                break;
            default:
                printf("Unknown event type\n");
        }
        currentEvent++;
    }
    printf("All events processed.\n");
    return 0;
}
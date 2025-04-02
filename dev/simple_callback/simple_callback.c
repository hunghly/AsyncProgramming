#include <stdio.h>

// Define a function that matches the expected callback signature
void greet(const char* name) {
    printf("Hello, %s!\n", name);
}

void goodbye(const char* name) {
    printf("Goodbye %s!\n", name);
}

// Function that takes a callback
void process(void (*callback)(const char*), const char* name) {
    printf("Processing name...\n");
    callback(name); // Call the function passed as an argument
}

int main() {
    process(greet, "Alice");
    process(goodbye, "Bob");
    return 0;
}

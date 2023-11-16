#include <stdio.h>
#include "include/library.h"

int main() {
    // Create a library structure
    struct Library library;
    int keepRunning=1;
    
    // Perform user action to initialize the library
    performUserAction(&library, &keepRunning);

    // Check if the program should continue running
    if (keepRunning == 1) {
        // Perform library-related actions based on user input
        performLibraryActions(&library);
    }

    return 0;
}
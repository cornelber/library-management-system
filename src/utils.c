#include <stdio.h>

#include "../include/utils.h"
#include "../include/book.h"
#include "../include/library.h"


// Print a template with the given content
void printTemplate(const char *content) {
    // Define the width of the border
    int border_width = 35;

    // Print the top border
    printf("\n%s\n", "|--------------");

    // Print the content with a left margin
    printf("%s%s\n", "  ",content);

    // Print the bottom border
    printf("%s\n\n", "|--------------");
}

// Set default display settings
void setDefaultDisplaySettings(struct DisplaySettings *settings) {
    // Initialize display settings with default values
    settings->option[0] = 1;
    settings->option[1] = 1;
    settings->option[2] = 0;
    settings->option[3] = 1;
    settings->option[4] = 0;
    settings->option[5] = 1;
    settings->option[6] = 0;
    settings->option[7] = 0;
}

// Swap the positions of two books
void swapBooks(struct Book *book1, struct Book *book2) {
    // Use a temporary variable to swap books
    struct Book temp = *book1;
    *book1 = *book2;
    *book2 = temp;
}

// Perform sorting on the library books based on a given criteria and sort order
void performSort(struct Library *library, int sortOrder, float *criteria) {
    for(int i = 0; i < library->numBooks - 1; i++) {
        for(int j = 0; j < library->numBooks - i - 1; j++) {
            if(sortOrder == 1) {
                if(criteria[j] > criteria[j+1]) {
                    swapBooks(&library->books[j], &library->books[j+1]);
                }
            } else {
                if(criteria[j] > criteria[j+1]) {
                    swapBooks(&library->books[j], &library->books[j+1]);
                }
            }
        }
    }
}
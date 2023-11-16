#ifndef LIBRARY_H
#define LIBRARY_H

#include "../config/settings.h"
#include "book.h"
#include "utils.h"

// Struct Declarations
// ===================
struct Library {
    struct Book books[MAX_BOOKS];  
    int numBooks;  
};


struct DisplaySettings;

// Function Declarations
// ===================
void initializeLibrary(struct Library *library, int hidePrompts);
void addBooksToLibrary(struct Library *library, int hidePrompts);
void displayLibrary(const struct Library *library, const struct DisplaySettings *settings);
void performUserAction(struct Library *library, int *programRunning);
void performLibraryActions(struct Library *library);
void customizeLibraryBookDisplay(struct DisplaySettings *settings);
void deleteBook(struct Library *library, int idx);
void addNewBook(struct Library *library);
void sortLibrary(struct Library *library, int *successfullySorted);
void displayLibraryStatistics(const struct Library *library);

#endif // LIBRARY_H
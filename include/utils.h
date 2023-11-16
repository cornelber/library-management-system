#ifndef UTILS_H
#define UTILS_H

#include "../config/settings.h"

// Struct Declarations
// ===================
struct Book;
struct Library;

struct DisplaySettings {
    int option[MAX_SETTINGS];
};

// Function Declarations
// ===================
void printTemplate(const char *content);
void setDefaultDisplaySettings(struct DisplaySettings *settings);
void swapBooks(struct Book *book1, struct Book *book2);
void performSort(struct Library *library, int sortOrder, float *criteria);

#endif // UTILS_H
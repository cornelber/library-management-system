#ifndef BOOK_H
#define BOOK_H

#include "../config/settings.h"
#include "book.h"
#include "utils.h"


// Struct Declarations
// ===================
struct Reviews {
    int storyPoints;
    int charactersPoints;
    int writingStylePoints;
    int overallPerReaderScore;
};

struct Book {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    char bookGenre[MAX_GENRE_SIZE];
    int releaseYear;
    int pages;
    float price;
    struct Reviews reviews[MATRIX_SIZE][MATRIX_SIZE];
    float avgOverallReviewScore;
};

// Function Declarations
// ===================
void initializeBook(struct Book *book, int hidePrompts);
void displayBook(const struct Book *book, const struct DisplaySettings *settings);

#endif // BOOK_H
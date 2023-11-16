#include <stdio.h>
#include "../include/book.h"

// Initialize a book with user-provided or default values
void initializeBook(struct Book *book, int hidePrompts) {
    // Prompt the user for book details
    if(hidePrompts != 1) {
        printf("\nEnter title: ");
    }
    scanf(" %99[^\n]", book->title);

    if(hidePrompts != 1) {
        printf("Enter author: ");
    }
    scanf(" %49[^\n]", book->author);

    if(hidePrompts != 1) {
        printf("Enter book genre: ");
    }
    scanf(" %19[^\n]", book->bookGenre);

    if(hidePrompts != 1) {
        printf("Enter release year: ");
    }
    scanf("%d", &book->releaseYear);

    if(hidePrompts != 1) {
        printf("Enter pages of the book: ");
    }
    scanf("%d", &book->pages);

    if(hidePrompts != 1) {
        printf("Enter book price: $");
    }
    scanf("%f", &book->price);

    // Prompt readers for review
    if(hidePrompts != 1) {
        printTemplate("Book Reviews\nRate from 0 to 5 - story, characters, writing style");
    }

    int tempReader = 1;
    for(int i=0; i < MATRIX_SIZE; i++) {
        for(int j=0; j < MATRIX_SIZE; j++) {
            if(hidePrompts != 1) {
                printf("\nReader %d\n", tempReader++);
            }

            if(hidePrompts != 1) {
                printf("Story [0 - 5]: ");
            }
            scanf("%d", &book->reviews[i][j].storyPoints);

            if(hidePrompts != 1) {
                printf("Characters [0 - 5]: ");
            }
            scanf("%d", &book->reviews[i][j].charactersPoints);

            if(hidePrompts != 1) {
                printf("Writing Style [0 - 5]: ");
            }
            scanf("%d", &book->reviews[i][j].writingStylePoints);
        }
    }

    // Calculate overall score per reader
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            book->reviews[i][j].overallPerReaderScore = (book->reviews[i][j].storyPoints + book->reviews[i][j].charactersPoints + book->reviews[i][j].writingStylePoints) / 3;
        }
    }

    
    // Calculate average overall score
    float sumOverall = 0.0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            sumOverall += book->reviews[i][j].overallPerReaderScore;
        }
    }

    book->avgOverallReviewScore = sumOverall / (MATRIX_SIZE * MATRIX_SIZE);
}

// Display book details based on user-defined settings
void displayBook(const struct Book *book, const struct DisplaySettings *settings) {
    printf("\n");
    if(settings->option[0] == 1) {
        printf("Title: %s\n", book->title);
    }

    if(settings->option[1] == 1) {
        printf("Author: %s\n", book->author);
    };

    if(settings->option[2] == 1) {
        printf("Genre: %s\n", book->bookGenre);
    };

    if(settings->option[3] == 1) {
        printf("Release year: %d\n", book->releaseYear);
    };

    if(settings->option[4] == 1) {
        printf("Pages: %d\n", book->pages);
    };

    if(settings->option[5] == 1) {
        printf("Price: $%.2f\n", book->price);
    };

    if(settings->option[6] == 1) {
        printf("Book Reviews:\n");
        int tempReader = 1;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            for (int j = 0; j < MATRIX_SIZE; ++j) {
                printf("Reader %d: Story=%d, Characters=%d, Writing Style=%d\n",
                    tempReader, book->reviews[i][j].storyPoints, book->reviews[i][j].charactersPoints, 
                    book->reviews[i][j].writingStylePoints
                );
                tempReader++;
            }
        }
    }

    if(settings->option[7] == 1) {
        printf("Average Overall Score: %.2f\n", book->avgOverallReviewScore);
    }
}
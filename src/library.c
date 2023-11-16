#include <stdio.h>
#include "../include/book.h"
#include "../include/library.h"

// Initialize the library with user-defined or default values
void initializeLibrary(struct Library *library, int hidePrompts) {
    if(hidePrompts != 1) {
        printf("How many books do you want to add: ");
    };
    scanf("%d", &library->numBooks);
};

// Display details of all books in the library based on settings
void displayLibrary(const struct Library *library, const struct DisplaySettings *settings) {
    for(int i = 0; i < library->numBooks; i++) {
        displayBook(&library->books[i], settings);
    }
}

// Add books to the library
int addBooksToLibrary(struct Library *library, int hidePrompts) {
    for (int i = 0; i < library->numBooks; i++) {
        if(hidePrompts != 1) {
            printf("\nEnter details for book %d.\n", i + 1);
        }

        // Create a temporary book to store the details
        struct Book addedBook;
        initializeBook(&addedBook, hidePrompts);

        // Check if there is space in the library
        if (library->numBooks < MAX_BOOKS) {
            // Add the book to the library
            library->books[i] = addedBook;
            if(hidePrompts != 1) {
                printTemplate("Book added to the library successfully.");
            }
        } else {
            if(hidePrompts != 1) {
                printTemplate("Library is full. Cannot add more books."); 
            }
            return 0; 
        }
    }
    
    if(library->numBooks < MAX_BOOKS || hidePrompts == 1) {
        printTemplate("Books added to the library successfully.");
    } else {
        printTemplate("Library is full. Cannot add more books.");
    }

    return 1;
}

// Perform user action to initialize the library
void performUserAction(struct Library *library, int *programRunning) {
    int userChoice;
    int hidePrompts;

    printf("Choose an action:\n");
    printf("1. - Enter manual book details\n");
    printf("2. - Import books from in.txt file\n");
    printf("Enter choice: ");
    scanf("%d", &userChoice);
    
    switch (userChoice) {
    case U_MANUAL_ADD_BOOKS:
        hidePrompts = 0;
        initializeLibrary(library, hidePrompts);
        addBooksToLibrary(library, hidePrompts);

        if (!addBooksToLibrary(library, hidePrompts)) {
            *programRunning = 0; 
            printTemplate("Error: Unable to add books to the library.");
        } else {
            *programRunning = 1;
        }
        break;
    case U_IMPORT_BOOKS:
        hidePrompts = 1;
        
        // Open the file for reading
        FILE *file = fopen("in.txt", "r");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        // Redirect stdin to read from the file
        if (freopen("in.txt", "r", stdin) == NULL) {
            perror("Error reopening file");
            return;
        }

        // Initialize and add books from in.txt file
        initializeLibrary(library, hidePrompts);
        addBooksToLibrary(library, hidePrompts);
        
        // Close the file after reading
        fclose(file);

        // Switch back to standard input
        if (freopen("/dev/tty", "r", stdin) == NULL) {
            perror("Error reopening stdin");
            return;
        }
        *programRunning = 1;
        break;
    default:
        *programRunning = 0;
        printf("Invalid choice. Exiting...\n");
        break;
    }
}

// Perform various actions on the library based on user input
void performLibraryActions(struct Library *library) {
    int libraryOperation;
    int exit = 1;

    struct DisplaySettings displaySettings;
    setDefaultDisplaySettings(&displaySettings); 

    while(exit == 1) {
        // Display the menu
        printTemplate("Choose an operations.");
        printf("1. Display Library\n"); 
        printf("2. Sort Library \n"); 
        printf("3. Library Statistics\n");
        printf("4. Add a new Book to Library\n"); 
        printf("5. Delete Book from Library\n"); 
        printf("6. Customize Library Book Display\n"); 
        printf("7. Exit operations\n"); 

        // Get user input
        printf("\nEnter your choice: ");
        scanf("%d", &libraryOperation);

        switch (libraryOperation) {
        case M_DISPLAY:
            printTemplate("Display Library Details.");
            displayLibrary(library, &displaySettings);
            break;
        case M_SORT:
            int sorted = 1;
            printTemplate("Sort the library by overall reviews score or price.");

            sortLibrary(library, &sorted);

            if(sorted == 1) {
                printTemplate("Displayed Sorted Library by chosen criteria.");
                displayLibrary(library, &displaySettings);
            }
            break;
        case M_STATISTICS:
            printTemplate("Library Statistics.");
            displayLibraryStatistics(library);
            break;
        case M_ADD_BOOK:
            printTemplate("Adding a new Book to the Library.");
            addNewBook(library);
            break;
        case M_DELETE_BOOK:
            int bookIndexToDelete;

            printTemplate("\nDelete a Book from the Library.\n");
            printf("\nLibrary Details:\n");
            for(int i = 0; i < library->numBooks; i++) {
                printf("%d. Book - %s\n", i+1, library->books[i].title);
            }
            
            printf("\nEnter the position of the book you want to delete: ");
            scanf("%d", &bookIndexToDelete);

            deleteBook(library, bookIndexToDelete);
            break;
        case M_CUSTOMIZE_DISPLAY:
            printTemplate("Customize Book Display Preferences.");
            customizeLibraryBookDisplay(&displaySettings);
            printf("\nBook Display Preferences Modified\n");
            break;
        case M_EXIT_MENU:
            exit = 0;
            printf("Exiting operations.\n");
            break;
        default:
            printf("Invalid selected option.\n");
            break;
        }
    }
}

// Library Operations
// ===================

// Customize the display settings for library books
void customizeLibraryBookDisplay (struct DisplaySettings *settings) {
    printf("\nEnter your preferences for displaying book information:\n");

    // Prompt for showing book title
    printf("Show book title (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[0]);

    // Prompt for showing book author
    printf("Show book author (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[1]);

    // Prompt for showing book genre
    printf("Show book genre (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[2]);

    // Prompt for showing book release year
    printf("Show book release year (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[3]);

    // Prompt for showing book pages
    printf("Show pages count of the book (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[4]);

    // Prompt for showing book price
    printf("Show book price (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[5]);

    // Prompt for showing book reviews
    printf("Show book reviews (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[6]);

    // Prompt for showing book average overall score
    printf("Show book average overall score (1 for YES, 0 for NO): ");
    scanf("%d", &settings->option[7]);
}

// Delete a book from the library at the specified index
void deleteBook(struct Library *library, int idx) {
    // Check if index is valid
    if(idx < 1 || idx > library->numBooks) {
        printf("Invalid index for deletion.\n");
        return;
    }

    // Move books to fill the gap
    for(int i = idx - 1; i < library->numBooks; i++) {
        library->books[i] = library->books[i+1];
    };

    // Decrease the number of books in the library
    library->numBooks--;

    printf("Book at index %d deleted successfully.\n", idx);
}

// Add a new book to the library
void addNewBook(struct Library *library) {
    if(library->numBooks < MAX_BOOKS) {
        struct Book addedNewBook;
        int hidePrompts=0;

        printf("\nEnter details for the new book:\n");
        initializeBook(&addedNewBook, hidePrompts);

        library->books[library->numBooks++] = addedNewBook;
        printf("New book added to the library successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

// Sort the library based on user-defined criteria
void sortLibrary(struct Library *library, int *successfullySorted) {
    int sortOrder;
    int sortCriteria;

    printf("Configure sorting options:\n");
    printf("1. Sort books in ascending order\n");
    printf("2. Sort books in descending order\n");
    printf("3. Go back\n");
    printf("Enter your choice: ");
    scanf("%d", &sortOrder);

    if(sortOrder < ASCENDING || sortOrder > DESCENDING) {
        printf("Invalid sorting options.\n");
        *successfullySorted = 0;
        return;
    }

    printf("\nSelect the sorting criteria in %s order:\n", sortOrder == ASCENDING ? "ascending" : "descending");
    printf("1. Sort by average overall score of reviews\n");
    printf("2. Sort by price\n");
    printf("Enter your choice: ");
    scanf("%d", &sortCriteria);

    switch (sortCriteria) {
    case BY_SCORE:
        performSort(library, sortOrder, &library->books->avgOverallReviewScore);
        break;
    case BY_PRICE:
        performSort(library, sortOrder, &library->books->price);
        break;
    default:
        printf("Invalid criteria option.\n");
        break;
    }
}

// Display statistics about the library
void displayLibraryStatistics(const struct Library *library) {
    if (library->numBooks == 0) {
        printf("Library is empty. No statistics available.\n");
        return;
    }

    printf("Total Number of Books: %d\n", library->numBooks);
    
    // Calculate and show total inventory value
    float totalInventoryValue = 0.0;
    for(int i = 0; i < library->numBooks; i++) {
        totalInventoryValue += library->books[i].price;
    }
    printf("Total value of inventory: %.2f\n", totalInventoryValue);
}
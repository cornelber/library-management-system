#ifndef SETTINGS_H
#define SETTINGS_H

#define MAX_TITLE_SIZE 100
#define MAX_AUTHOR_SIZE 50
#define MAX_GENRE_SIZE 20
#define MATRIX_SIZE 2
#define MAX_BOOKS 100
#define MAX_SETTINGS 10

enum SortOrder {
    ASCENDING = 1,
    DESCENDING = 2
};

enum SortCriteria {
    BY_SCORE = 1,
    BY_PRICE = 2
};

enum LibraryOperation {
    M_DISPLAY = 1,
    M_SORT = 2,
    M_STATISTICS = 3,
    M_ADD_BOOK = 4,
    M_DELETE_BOOK = 5,
    M_CUSTOMIZE_DISPLAY = 6,
    M_EXIT_MENU = 7
};

enum UserOperation {
    U_MANUAL_ADD_BOOKS = 1,
    U_IMPORT_BOOKS = 2
};

#endif // SETTINGS_H
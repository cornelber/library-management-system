# Library Management System

# Table of Contents
1. [Library Management System](#library-management-system)
   - [Introduction](#introduction)
   - [Building and Running](#building-and-running)
     - [Prerequisites](#prerequisites)
       - [Windows Subsystem for Linux (WSL)](#windows-subsystem-for-linux-wsl)
       - [Linux](#linux)
     - [Downloading the Code](#downloading-the-code)
     - [Compile and Execute](#compile-and-execute)
   - [Project Structure](#project-structure)
   - [How the Program Works](#how-the-program-works)
     - [`settings.h`](#settingsh)
     - [`utils.h` and `utils.c`](#utilsh-and-utilsc)
     - [`book.h` and `book.c`](#bookh-and-bookc)
     - [`library.h` and `library.c`](#libraryh-and-libraryc)
     - [`main.c`](#mainc)
   - [Workflow](#workflow)
     - [Initialization](#initialization)
     - [User Interaction](#user-interaction)
     - [Library Operations](#library-operations)
     - [Utility Functions](#utility-functions)
   - [Example Input File (`in.txt`)](#example-input-file-intxt)
   - [Conclusion](#conclusion)

## Library Management System

### Introduction

This project is a simple library management system written in C. The system allows users to perform various operations such as adding books to the library, displaying book details, sorting the library, and more. The code is organized into several files, each serving a specific purpose. This document will provide a detailed explanation of how the program works and how to use it.

### Building and Running

#### Prerequisites

Before building and running the Library Management System, ensure that you have the following prerequisites installed on your system:

- **WSL (Windows Subsystem for Linux):**
  - Follow the official [Microsoft WSL installation guide](https://learn.microsoft.com/en-us/windows/wsl/install).

- **GCC (GNU Compiler Collection):**
  - The program relies on GCC for compilation. Install GCC based on your operating system:

#### Windows Subsystem for Linux (WSL)

1. Install WSL:
   - Follow the official [Microsoft WSL installation guide](https://learn.microsoft.com/en-us/windows/wsl/install).
2. Open a WSL Terminal:
   - Once WSL is installed, open a WSL terminal by searching for "Ubuntu" or your preferred Linux distribution in the Start menu.
3. Install GCC in WSL:
   - Use the package manager specific to your WSL distribution. For example, on Ubuntu, run:
     ```bash
     sudo apt-get update
     sudo apt-get install gcc
     ```

#### Linux

1. Open a Terminal:
   - Navigate to the directory containing the source code.
2. Install GCC:
   - Use the package manager specific to your distribution. For example, on Ubuntu or Debian-based systems, run:
     ```bash
     sudo apt-get install gcc
     ```

#### Downloading the Code

1. **Clone the Repository:**
   - Open a web browser and visit the [Library Management System GitHub repository](https://github.com/cornelber/library-management-system).
   - Click on the "Code" button and copy the repository URL.
   - In the terminal or PowerShell, navigate to the desired directory and run:
     ```bash
     git clone <repository_url>
     ```

2. **Change Directory:**
   - Navigate to the cloned repository:
     ```bash
     cd library-management-system
     ```

#### Compile and Execute

1. **Compile the Program:**
   - Run the following command to compile the program:
     ```bash
     gcc main.c src/library.c src/book.c src/utils.c -o main.exe
     ```

2. **Execute the Compiled Program:**
   - Run the following command to execute the compiled program:
     ```bash
     ./main.exe
     ```

### Project Structure

- **config**
  - `settings.h`: Contains constant values and enums used throughout the program.

- **include**
  - `library.h`: Header file for the Library structure and related functions.
  - `book.h`: Header file for the Book structure and related functions.
  - `utils.h`: Header file for utility functions and the DisplaySettings structure.

- **src**
  - `library.c`: Implementation of functions related to library operations.
  - `book.c`: Implementation of functions related to book operations.
  - `utils.c`: Implementation of utility functions.

- **`main.c`**: The main file where the program starts execution.

- **`in.txt`**: A sample input file for importing books into the library.

### How the Program Works

#### `settings.h`

This file contains constant values and enums used for settings, sorting criteria, sort order, library operations, and user operations.

#### `utils.h` and `utils.c`

These files provide utility functions used throughout the program. Functions include printing templates, setting default display settings, swapping books, and performing sorting on the library.

#### `book.h` and `book.c`

These files define the Book structure and implement functions related to book operations. Functions include initializing a book, displaying book details based on user-defined settings, and performing operations related to book reviews.

#### `library.h` and `library.c`

These files define the Library structure and implement functions related to library operations. Functions include initializing the library, adding books, displaying library details, performing user actions, and more.

#### `main.c`

The main file initializes a Library structure and handles user actions to perform various operations on the library. Users can choose to add books manually or import books from a file, display library details, sort the library, and perform other operations.

### Workflow

#### Initialization

1. **Create a Library Structure:**
   - Initialize an instance of the `struct Library` to represent the library.
     ```c
     struct Library library;
     ```

2. **Perform User Action:**
   - Call `performUserAction` to interact with the user and initialize the library based on their choice.
     ```c
     int keepRunning = 1;
     performUserAction(&library, &keepRunning);
     ```

#### User Interaction

1. **Choose Action:**
   - Users choose actions like adding books manually, importing from a file, or other library operations.
     ```c
     // Example: Adding books manually
     case U_MANUAL_ADD_BOOKS:
     hidePrompts = 0;
     initializeLibrary(library, hidePrompts);
     addBooksToLibrary(library, hidePrompts);
     break;
     ```

2. **Library Operations:**
   - Based on user input, perform various library operations such as displaying details, sorting, adding new books, or customizing display preferences.
     ```c
     performLibraryActions(&library);
     ```

#### Library Operations

1. **Display Library Details:**
   - Display details of all books in the library based on user-defined settings.
     ```c
     void displayLibrary(const struct Library *library, const struct DisplaySettings *settings) {
         // Implementation details...
     }
     ```

2. **Add Books to the Library:**
   - Allow users to add books to the library, either manually or by importing from a file.
     ```c
     int addBooksToLibrary(struct Library *library, int hidePrompts) {
         // Implementation details...
     }
     ```

3. **Sort Library:**
   - Sort the library based on user-defined criteria.
     ```c
     void sortLibrary(struct Library *library, int *successfullySorted) {
         // Implementation details...
     }
     ```

4. **Customize Display Preferences:**
   - Allow users to customize the display settings for library books.
     ```c
     void customizeLibraryBookDisplay(struct DisplaySettings *settings) {
         // Implementation details...
     }
     ```

5. **Delete Book**
   - Delete a book from the library at the specified index
     ```c
     void deleteBook(struct Library *library, int idx) {
         // Implementation details...
     }
     ```

6. **Library Statistics:**
   - Display statistics about the library
     ```c
     void displayLibraryStatistics(const struct Library *library) {
         // Implementation details...
     }
     ```

#### Utility Functions

1. **Printing Templates:**
   - Use utility functions like `printTemplate` for consistent template-based printing.
     ```c
     void printTemplate(const char *content) {
         // Implementation details...
     }
     ```

2. **Default Display Settings:**
   - Set default display settings using the `setDefaultDisplaySettings` function.
     ```c
     void setDefaultDisplaySettings(struct DisplaySettings *settings) {
         // Implementation details...
     }
     ```

4. **Sorting Utility:**
   - Swap books and perform sorting using utility functions.
     ```c
     void swapBooks(struct Book *book1, struct Book *book2) {
         // Implementation details...
     }

     void performSort(struct Library *library, int sortOrder, float *criteria) {
         // Implementation details...
     }
     ```

The workflow involves initializing the library, interacting with the user, performing library operations, and utilizing utility functions for consistency.

## Example Input File (`in.txt`)

The `in.txt` file serves as a sample data source for importing books into the library. Users can customize this file with their book details to test the import functionality. Ensure the data in this file follows the expected format as specified in the program.

1. **Number of Books to Add:** Specifies the number of books to add to the library.

2. **Book Details Format for Each Book:**
   - **Title:** The title of the book.
   - **Author:** The author of the book.
   - **Genre:** The genre of the book.
   - **Release Year:** The year the book was released.
   - **Number of Pages:** The total number of pages in the book.
   - **Price:** The price of the book.
   - **Review Ratings:** Ratings for story, characters, and writing style (on a scale of 0 to 5) provided by multiple readers.

### Example Data

```plaintext
1
Inheritance: The Lost Bride Trilogy
Nora Roberts
Paranormal
2023
448
14
4
4
3
3
3
2
4
4
4
5
4
3
```

## Conclusion

This documentation provides a comprehensive overview of the project structure, explaining the purpose of each file and offering clear instructions on how to compile and run the program. Users can seamlessly interact with the system through the command line, facilitating efficient management of a library of books.

**Note:**
This project serves as a faculty project and can be further developed and enhanced based on specific requirements. Students and developers are encouraged to explore additional features and improvements to deepen their understanding of software development practices.

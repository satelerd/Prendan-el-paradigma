// The following is the code to manage the university library system.
// The system should be able to add, remove and edit books.
// The books are organized by building, campus, section and shelf.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Open the .csv file and we read the data
int read_csv()
{
    FILE *fp = fopen("file_path", "r");
}

// function to print the start menu
int menu()
{
}

// Function to add a new book
int add_book(fp)
{
}

// Function to remove a book
int remove_book(fp)
{
}

// Function to add a campus
int add_campus(fp)
{
}

// Function to remove a campus (it should only be possible if the campus has no books)
int remove_campus(fp)
{
}

// Function to edit a book
int edit_book(fp)
{
}

// Funtion to change a book from one campus to another
int change_campus(fp)
{
}

// Function to change a book from one section to another
int change_section(fp)
{
}

// Function to change a book from one shelf to another
int change_shelf(fp)
{
}

// Function to add a section
int add_section(fp)
{
}

// Function to delete a section
int delete_section(fp)
{
}

// Function to add a shelf
int add_shelf(fp)
{
}

// Function to delete a shelf (it should only be possible if the shelf has no books)
int delete_shelf(fp)
{
}

// Function to search for a book and print the information associated with it
int search_book(fp)
{
}

// Function to close and save the .csv file
int close_file(fp)
{
}

// the main function that calls the functions
int main()
{
    int option;
    do
    {
        option = menu();
        switch (option)
        {
        case 1:
            add_book(fp);
            break;
        case 2:
            remove_book(fp);
            break;
        case 3:
            add_campus(fp);
            break;
        case 4:
            remove_campus(fp);
            break;
        case 5:
            edit_book(fp);
            break;
        case 6:
            change_campus(fp);
            break;
        case 7:
            change_section(fp);
            break;
        case 8:
            change_shelf(fp);
            break;
        case 9:
            add_section(fp);
            break;
        case 10:
            delete_section(fp);
            break;
        case 11:
            add_shelf(fp);
            break;
        case 12:
            delete_shelf(fp);
            break;
        case 13:
            search_book(fp);
            break;
        case 14:
            close_file(fp);
            break;
        }
    } while (option != 14);
    return 0;
}
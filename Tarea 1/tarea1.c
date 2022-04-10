// The following is the code to manage the university library system.
// The system should be able to add, remove and edit books.
// The books are organized by building, campus, section and shelf.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define READ_ONLY "a+"

// declare the functions
char menu();

int add_book(FILE *fp);
int remove_book(FILE *fp, char *filename);
int add_campus();
int remove_campus();
int edit_book();
int change_campus();
int change_section();
int change_shelf();
int add_section();
int delete_section();
int add_shelf();
int delete_shelf();
void search_book();
int close_file();

void libro_index(FILE *myfile);
void display_info(FILE *myfile);

FILE *openingFile(char *filename)
{
    FILE *fp;
    fp = fopen(filename, READ_ONLY);
    return fp;
}

// the main function that calls the functions
int main(int argc, char *argv[])
{
    // Open the csv file
    char filename[1024] = "inventario.csv";
    FILE *fp = openingFile(filename);

    // Display the menu
    int option;
    option = menu();

    // switch to call the functions
    switch (option)
    {
    case 1:
        printf("Agregar libro");
        add_book(fp);
        break;
    case 2:
        printf("Eliminar libro");
        remove_book(fp, filename);
        break;
    case 3:
        printf("Agregar campus");
        add_campus();
        break;
    case 4:
        printf("Eliminar campus");
        remove_campus();
        break;
    case 5:
        printf("Editar libro");
        edit_book();
        break;
    case 6:
        printf("Cambiar campus");
        change_campus();
        break;
    case 7:
        printf("Cambiar seccion");
        change_section();
        break;
    case 8:
        printf("Cambiar estante");
        change_shelf();
        break;
    case 9:
        printf("Agregar seccion");
        add_section();
        break;
    case 10:
        printf("Eliminar seccion");
        delete_section();
        break;
    case 11:
        printf("Agregar estante");
        add_shelf();
        break;
    case 12:
        printf("Eliminar estante");
        delete_shelf();
        break;
    case 13:
        printf("Buscar libro");
        search_book();
        break;
    case 14:
        printf("Salir");
        close_file();
        break;
    default:
        printf("Opcion invalida");
        break;
    }
    return 0;
}

// Functions to manage the main menu

// Function to search for a book and print the information associated with it
void search_book()
{
    char book_for_search;
    printf("Ingrese el titulo del libro que desea buscar: ");
    scanf("%s", &book_for_search);

    // loop through the books names to search for the book
    for (int i = 0; i < 999; i++)
    {
    }
    return;
}

// Function to add a new book
int add_book(FILE *fp)
{
    char book[70], author[50], section[50], building[4], campus[50];
    int year, shelf, floor;

    if (!fp)
    {
        printf("Can't open file\n");
        return 0;
    }
    // ask for the information
    printf("\nIngresa el nombre del libro (Los espacios se ingresan con guión bajo): \n");
    scanf("%s", &book);
    printf("\nIngresa el nombre del autor:\n");
    scanf("%s", &author);
    printf("\nIngresa el año del libro:\n");
    scanf("%d", &year);
    printf("\nIngresa el numero del estante donde esta el libro:\n");
    scanf("%d", &shelf);
    printf("\nIngresa el tipo de seccion del libro:\n");
    scanf("%s", &section);
    printf("\nIngresa el piso donde esta el libro: \n");
    scanf("%d", &floor);
    printf("\nIngresa el edificio donde esta el libro:\n");
    scanf("%s", &building);
    printf("\nIngresa la sede donde esta el libro:\n");
    scanf("%s", &campus);

    fprintf(fp, "%s, %s, %d,%d,%s,%d,%s,%s\n", book, author, year, shelf, section, floor, building, campus);
    printf("\n¡Nuevo libro agregado con exito!");

    fclose(fp);
    return 0;
}

// Function to remove a book
int remove_book(FILE *fp, char *filename)
{
    FILE *file, *temp;

    int book_to_remove;
    char temp_filename[1000];
    char buffer[2000];

    file = fp;
    strcpy(temp_filename, "temp____");
    strcat(temp_filename, filename);

    printf("\nIngresa el ID del libro que quieres eliminar: \n");
    scanf("%d", &book_to_remove + 1);

    temp = fopen(temp_filename, "w");

    if (fp == NULL)
    {
        printf("\nError al abrir el archivo");
        return 1;
    }

    bool keep_reading = true;
    int cont = 1;
    do
    {
        fgets(buffer, 2048, file);
        if (feof(file))
            keep_reading = false;
        else if (cont != book_to_remove)
            fputs(buffer, temp);
        cont++;
    } while (keep_reading);

    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename, filename);
    printf("¡Libro eliminado con exito!");
    return 0;
}
// Function to add a campus
int add_campus()
{
}

// Function to remove a campus (it should only be possible if the campus has no books)
int remove_campus()
{
}

// Function to edit a book
int edit_book()
{
}

// Funtion to change a book from one campus to another
int change_campus()
{
}

// Function to change a book from one section to another
int change_section()
{
}

// Function to change a book from one shelf to another
int change_shelf()
{
}

// Function to add a section
int add_section()
{
}

// Function to delete a section
int delete_section()
{
}

// Function to add a shelf
int add_shelf()
{
}

// Function to delete a shelf (it should only be possible if the shelf has no books)
int delete_shelf()
{
}

// Function to search for a book and print the information associated with it
// int search_book()
// {
//     dict values[999];
// }

// Function to close and save the .csv file
int close_file()
{
}

// function to print the start menu
char menu()
{
    int num;
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("Bienvenido a la biblioteca de la UAI\n");
    printf("Lo siguiente son las opciones para usar el sistema, escribe el numero de la opcion que deseas\n");
    printf("1. Agregar libro\n");
    printf("2. Eliminar libro\n");
    printf("3. Agregar campus\n");
    printf("4. Eliminar campus\n");
    printf("5. Editar libro\n");
    printf("6. Cambiar campus\n");
    printf("7. Cambiar seccion\n");
    printf("8. Cambiar estante\n");
    printf("9. Agregar seccion\n");
    printf("10. Eliminar seccion\n");
    printf("11. Agregar estante\n");
    printf("12. Eliminar estante\n");
    printf("13. Buscar libro\n");
    printf("14. Salir\n");
    // get the input of the user and return it
    printf("\n");
    printf("Elige una opcion: ");
    scanf("%d", &num);
    printf("------------------------------------------------------\n");
    printf("\n");

    return num;
}

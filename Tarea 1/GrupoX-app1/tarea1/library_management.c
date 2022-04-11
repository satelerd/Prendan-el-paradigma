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
#define READ_ONLY "r"

// declare the functions
char menu();

int add_book(FILE *fp);
int remove_book(FILE *fp, char *filename);
int add_campus();
int remove_campus();
int add_section();
int delete_section();
int add_shelf();
int delete_shelf();
int search_book(FILE *fp);
int edit_book();
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

    printf("Este es un trabajo realizado por el grupo Prendan el Paradigma\n");
    printf("Conformado por:\n");
    printf("\t-Daniel Sateler\n");
    printf("\t-Sebastian Diaz\n");
    printf("\t-Maximiliano Mardones\n");
    printf("Esperamos que lo disfruten!\n");

    int first_time = 1;
    // loop until the user wants to exit
    while (1)
    {
        if (first_time == 0)
        {
            // ask the user if he wants to continue
            char continue_;
            printf("\n\nDesea realizar otra operacion? (s/n): ");
            scanf("%s", &continue_);
            if (continue_ == 'n')
            {
                printf("Muchas gracias! Que tenga un buen día!\n");
                break;
            }
        }
        first_time = 0;

        // Display the menu
        int option;
        option = menu();
        // switch to call the functions
        switch (option)
        {
        case 1:
            printf("Agregar libro");
            add_book(fp);
            continue;
        case 2:
            printf("Eliminar libro");
            remove_book(fp, filename);
            continue;
        case 3:
            printf("Agregar campus");
            add_campus();
            continue;
        case 4:
            printf("Eliminar campus");
            remove_campus();
            continue;
        case 5:
            printf("Agregar seccion");
            add_section();
            continue;
        case 6:
            printf("Eliminar seccion");
            delete_section();
            continue;
        case 7:
            printf("Agregar estante");
            add_shelf();
            continue;
        case 8:
            printf("Eliminar estante");
            delete_shelf();
            continue;
        case 9:
            printf("Buscar libro");
            search_book(fp);
            continue;
        case 10:
            printf("Editar libro");
            edit_book();
            continue;
        case 11:
            printf("Salir");
            // close_file();
            break;
        default:
            printf("Opcion invalida");
        }
    }
    return 0;
}

// Functions to manage the main menu

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
int search_book(FILE *fp)
{
    char book_for_search;
    printf("\nIngrese el titulo del libro que desea buscar: ");
    scanf("%s", &book_for_search);

    char buffer[2000];
    bool found = false;
    while (!found && !feof(fp))
    {
        fgets(buffer, 2000, fp);
        if (strstr(buffer, book_for_search))
        {
            printf("\n%s", buffer);
            found = true;
        }
    }
    if (!found)
        printf("\nNo se encontro el libro");
    else
        // print the information of the book
        printf("\n");
    printf("Libro encontrado");
    return 0;
}

int edit_book()
{
    char option;
    char book, author, section, building, campus;
    int year, shelf, floor;
    printf("\n");
    printf("Para editar un libro, tendra que elegir que opción quiere editar\n");
    printf("Las opciones son:\n");
    printf("1. Nombre del libro  -  2. Autor  -  3. Año  -  4. Estante  -  5. Seccion  -  6. Piso  -  7. Edificio  -  8. Campus\n");
    scanf("%i", &option);
    switch (option)
    {
    case 1:
        printf("Editar nombre del libro ");
        scanf("%i", &book);
        printf("\n Se ha editado el nombre del libro");
        break;
    case 2:
        printf("Editar autor, ingrese nuevo autor: ");
        scanf("%s", &author);
        printf("\n Se ha editado el autor");
        break;
    case 3:
        printf("Editar año, ingrese nuevo año: ");
        scanf("%d", &year);
        printf("\n Se ha editado el año");
        break;
    case 4:
        printf("Editar estante, ingrese nuevo estante: ");
        scanf("%d", &shelf);
        printf("\n Se ha editado el estante");
        break;
    case 5:
        printf("Editar seccion, ingrese nueva seccion: ");
        scanf("%s", &section);
        printf("\n Se ha editado la seccion");
        break;
    case 6:
        printf("Editar piso, ingrese nuevo piso: ");
        scanf("%d", &floor);
        printf("\n Se ha editado el piso");
        break;
    case 7:
        printf("Editar edificio, ingrese nuevo edificio: ");
        scanf("%s", &building);
        printf("\n Se ha editado el edificio");
        break;
    case 8:
        printf("Editar campus, ingrese nuevo campus: ");
        scanf("%s", &campus);
        printf("\n Se ha editado el campus");
        break;
    default:
        printf("Opcion invalida");
        break;
    }
}

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
    printf("\n");
    printf("1. Agregar libro\n");
    printf("2. Eliminar libro\n");
    printf("3. Agregar campus\n");
    printf("4. Eliminar campus\n");
    printf("5. Agregar seccion\n");
    printf("6. Eliminar seccion\n");
    printf("7. Agregar estante\n");
    printf("8. Eliminar estante\n");
    printf("9. Buscar libro\n");
    printf("10. Editar libro\n");
    printf("11. Salir\n");
    // get the input of the user and return it
    printf("\n");
    printf("Elige una opcion: ");
    scanf("%d", &num);
    printf("------------------------------------------------------\n");
    printf("\n");

    return num;
}

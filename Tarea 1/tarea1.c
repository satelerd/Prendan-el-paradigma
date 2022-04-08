// The following is the code to manage the university library system.
// The system should be able to add, remove and edit books.
// The books are organized by building, campus, section and shelf.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// declare the functions
char menu();
void read_csv();
int add_book();
int remove_book();
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

typedef struct key_value
{
    char title[100];
    char author[100];
    char year[10];
    char shelf[10];
    char section[10];
    char floor[10];
    char building[10];
    char campus[100];
} dict;

// the main function that calls the functions
int main()
{
    dict values[999];
    read_csv(values);

    int option;
    option = menu();

    // switch to call the functions
    switch (option)
    {
    case 1:
        printf("Agregar libro\n");
        add_book();
        break;
    case 2:
        printf("Eliminar libro\n");
        remove_book();
        break;
    case 3:
        printf("Agregar campus\n");
        add_campus();
        break;
    case 4:
        printf("Eliminar campus\n");
        remove_campus();
        break;
    case 5:
        printf("Editar libro\n");
        edit_book();
        break;
    case 6:
        printf("Cambiar campus\n");
        change_campus();
        break;
    case 7:
        printf("Cambiar seccion\n");
        change_section();
        break;
    case 8:
        printf("Cambiar estante\n");
        change_shelf();
        break;
    case 9:
        printf("Agregar seccion\n");
        add_section();
        break;
    case 10:
        printf("Eliminar seccion\n");
        delete_section();
        break;
    case 11:
        printf("Agregar estante\n");
        add_shelf();
        break;
    case 12:
        printf("Eliminar estante\n");
        delete_shelf();
        break;
    case 13:
        printf("Buscar libro\n");
        search_book(values);
        break;
    case 14:
        printf("Salir\n");
        close_file();
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }
    return 0;
}

// Functions and variables to manage the main menu

// Open the .csv file and we read the data
void read_csv(dict *values)
{
    FILE *inventory = fopen("inventario.csv", "r");
    if (inventory == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    char line[500];

    while (fgets(line, sizeof(line), inventory))
    {
        char buff[1024];
        int row_count = 0;
        int field_count = 0;

        int i = 0;
        while (fgets(buff, sizeof(buff), inventory))
        {
            // printf("%s\n", buff);
            field_count = 0;

            char *field = strtok(buff, ",");
            // create a variable that stores the number of " found
            int num_of_quotes = 0;

            while (field)
            {
                if (field_count == 0)
                    strcpy(values[i].title, field);
                else if (field_count == 1)
                    strcpy(values[i].author, field);
                else if (field_count == 2)
                    strcpy(values[i].year, field);
                else if (field_count == 3)
                    strcpy(values[i].shelf, field);
                else if (field_count == 4)
                    strcpy(values[i].section, field);
                else if (field_count == 5)
                    strcpy(values[i].floor, field);
                else if (field_count == 6)
                    strcpy(values[i].building, field);
                else if (field_count == 7)
                    strcpy(values[i].campus, field);

                field = strtok(NULL, ",");
                field_count++;
            }
            i++;
        }

        // now print the values for (int j = 0; j < i; j++)
        // for (int j = 0; j < i; j++)
        // {
        //     printf("%s\n", values[j].title);
        //     printf("%s\n", values[j].author);
        //     printf("%s\n", values[j].year);
        //     printf("%s\n", values[j].shelf);
        //     printf("%s\n", values[j].section);
        //     printf("%s\n", values[j].floor);
        //     printf("%s\n", values[j].building);
        //     printf("%s\n", values[j].campus);
        // }

        // printf("\n");
        // printf("\n");
    }

    // return the values
    // fclose(inventory);
    return;
}

// Function to search for a book and print the information associated with it
void search_book(dict *values)
{
    char book_for_search;
    printf("Ingrese el titulo del libro que desea buscar: ");
    scanf("%s", &book_for_search);

    // loop through the books names to search for the book
    for (int i = 0; i < 999; i++)
    {
        // // convert values[i].title from a pointer to a string
        // char book_name;
        // mbtowc(book_name, values[i].title, strlen(values[i].title));

        // // printf("%s\n", values[i].title);
        // if (book_name == book_for_search)
        // {
        //     printf("Titulo: %s\n", values[i].title);
        // }
    }
    return;
}

// Function to add a new book
int add_book()
{
}

// Function to remove a book
int remove_book()
{
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

// The following is the code to manage the university library system.
// The system should be able to add, remove and edit books.
// The books are organized by building, campus, section and shelf.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// declare the functions
char menu();
int read_csv();
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
int search_book();
int close_file();

// the main function that calls the functions
int main()
{
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
        search_book();
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

// Open the .csv file and we read the data
int read_csv()
{
    FILE *fp = fopen("file_path", "r");
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
int search_book()
{
    // char tem_max[10];
    // char titu[30];
    // char autor[30];
    // int stant_num[3];
    // char stant_sec[25];
    // int piso[4];
    // int anio[4];
    // char edif[3];
    // char sede[100];
    // int i = 0; // <--- i is 0

    // printf("Ingrese el nombre del libro: ");
    // scanf("%[^\n]%*c", titu);

    // FILE *stream = fopen("inventario.csv", "r");

    // char line[1024];
    // while (fgets(line, 1024, stream))
    // {
    //     char *tmp = strdup(line);
    //     if (i > 0)
    //     { // <--- i is still 0
    //         strcpy(titu, strtok(tmp, ",\n"));
    //         strcpy(autor, strtok(NULL, ","));
    //         strcpy(anio, strtok(NULL, ","));
    //         strcpy(stant_num, strtok(NULL, ","));
    //         strcpy(stant_sec, strtok(NULL, ","));
    //         strcpy(piso, strtok(NULL, ","));
    //         strcpy(edif, strtok(NULL, ","));
    //         strcpy(sede, strtok(NULL, ","));

    //         if (strcmp(city, titu) == 0)
    //         {
    //             printf("Libro - Autor - Año - Num Estante - Sec Estante - Piso - Edificio - Sede\n");
    //             printf("%s - %s - %s - %s - %s - %s - %s - %s\n", titu, autor, anio, stant_num, stant_sec, piso, edif, sede);
    //         }
    //         i++; // <--- now you do i++
    //         free(tmp);
    //     }
    //     else
    //     {
    //         printf("ERROR");
    //     }
    //     fclose(stream);
    // }
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

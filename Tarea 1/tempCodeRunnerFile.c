    char tem_max[10];
    char titu[30];
    char autor[30];
    int stant_num[3];
    char stant_sec[25];
    int piso[4];
    int anio[4];
    char edif[3];
    char sede[100];
    int i = 0; // <--- i is 0

    printf("Ingrese el nombre del libro: ");
    scanf("%[^\n]%*c", titu);

    FILE *stream = fopen("inventario.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);
        if (i > 0)
        { // <--- i is still 0
            strcpy(titu, strtok(tmp, ",\n"));
            strcpy(autor, strtok(NULL, ","));
            strcpy(anio, strtok(NULL, ","));
            strcpy(stant_num, strtok(NULL, ","));
            strcpy(stant_sec, strtok(NULL, ","));
            strcpy(piso, strtok(NULL, ","));
            strcpy(edif, strtok(NULL, ","));
            strcpy(sede, strtok(NULL, ","));

            if (strcmp(city, titu) == 0)
            {
                printf("Libro - Autor - Año - Num Estante - Sec Estante - Piso - Edificio - Sede\n");
                printf("%s - %s - %s - %s - %s - %s - %s - %s\n", titu, autor, anio, stant_num, stant_sec, piso, edif, sede);
            }
            i++; // <--- now you do i++
            free(tmp);
        }
        else
        {
            printf("ERROR");
        }
        fclose(stream);
    }
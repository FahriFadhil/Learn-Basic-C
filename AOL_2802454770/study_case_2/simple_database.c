#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    # PSEUDO_CODE
    This is for the Second Study Case, Simple Database Manipulation
    -- It'll still work on any dynamic data count (including 4000 data or more).
    *note: the last line of the data will need a '\n' to make the count lines function works.

    - Display Menu
    Displaying all data from top and gave limitter according to user input.
    *flaw: im using the %{num}{char} formatter for the data so it's right-aligned. I've tried using -%{num}{char} to make it left-aligned, but there some issue i cannot found so i'll stick with the right-aligned design, and hey it's still look dope.

    - Row Search
    User picks one of columns to search the data and output whole row of matching value, if multiple founded print-all.

    - Sort Data
    User pick a column for the pivot of sorting, then decide if it should asc or desc.
    *note: Sorted data will affect the whole database until the user exits the program, so exporting will output sorted data (if sorted beforehand by the user).

    - Export Database
   Export a new file for the client, containg all the modified data by the user (sorted).
   *flaw: if the same name file already been created beforehand, that file will be rewritten.

    - Exit
    Exit...
 */

typedef struct Data
{
    char location[255];
    char city[255];
    int price;
    int room;
    int bathroom;
    int carPark;
    char type[255];
    char furnish[255];
} D;

typedef enum SORT_ORDER
{
    ASC,
    DESC
} SO;

int countLines(FILE *fp)
{
    int count = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    rewind(fp);
    return count;
}

void fetchData(FILE *fp, D *list, int n)
{
    char header[1024];
    fgets(header, sizeof(header), fp);

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, " %[^,], %[^,], %d, %d, %d, %d, %[^,], %[^\n]",
               list[i].location,
               list[i].city,
               &list[i].price,
               &list[i].room,
               &list[i].bathroom,
               &list[i].carPark,
               list[i].type,
               list[i].furnish);
    }
}

void swap(D *a, D *b)
{
    D temp = *a;
    *a = *b;
    *b = temp;
}

int compare(D params, D pivot, int choice, SO order)
{
    int result = 0;
    switch (choice)
    {
    case 1:
        result = strcmp(params.location, pivot.location);
        break;
    case 2:
        result = strcmp(params.city, pivot.city);
        break;
    case 3:
        result = params.price - pivot.price;
        break;
    case 4:
        result = params.room - pivot.room;
        break;
    case 5:
        result = params.bathroom - pivot.bathroom;
        break;
    case 6:
        result = params.carPark - pivot.carPark;
        break;
    case 7:
        result = strcmp(params.type, pivot.type);
        break;
    case 8:
        result = strcmp(params.furnish, pivot.furnish);
        break;
    default:
        break;
    }

    return (order == ASC) ? result : -result;
}

int partition(D *list, int low, int high, int choice, SO order)
{
    D pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (compare(list[j], pivot, choice, order) < 0)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }

    swap(&list[i + 1], &list[high]);
    return i + 1;
}

void quickSort(D *list, int low, int high, int choice, SO order)
{
    if (low < high)
    {
        int pi = partition(list, low, high, choice, order);

        quickSort(list, low, pi - 1, choice, order);
        quickSort(list, pi + 1, high, choice, order);
    }
}

void printHeader()
{
    printf("%30s %16s %12s %12s %16s %16s %12s %13s\n",
           "| Location |",
           "| City |",
           "| Price |",
           "| Rooms |",
           "| Bathrooms |",
           "| Parking Lot |",
           "| Type |",
           "| Furnish |");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printRow(D *list, int i)
{
    printf("%30s %16s %12d %12d %16d %16d %12s %13s\n",
           list[i].location,
           list[i].city,
           list[i].price,
           list[i].room,
           list[i].bathroom,
           list[i].carPark,
           list[i].type,
           list[i].furnish);
}

void searchData(D *list, int n, int choice)
{
    switch (choice)
    {
    case 1:
    {
        char location[255];
        printf(">> Enter Location Name to search (case sensitive): ");
        scanf(" %[^\n]", location);
        system("clear");

        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(list[i].location, location) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (strcmp(list[i].location, location) == 0)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Location: %s\n", location);
        }
        break;
    }
    case 2:
    {
        char city[255];
        printf(">> Enter City Name to search (case sensitive): ");
        scanf(" %[^\n]", city);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(list[i].city, city) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (strcmp(list[i].city, city) == 0)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for City: %s\n", city);
        }
        break;
    }
    case 3:
    {
        int price;
        printf(">> Enter Price Range to search (price will range 50K from initial choice): ");
        scanf("%d", &price);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (list[i].price >= (price - 50000) && list[i].price <= (price + 50000))
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (list[i].price >= (price - 50000) && list[i].price <= (price + 50000))
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Ideal Price of %d\n", price);
        }
        break;
    }
    case 4:
    {
        int room;
        printf(">> Enter number of Rooms to search: ");
        scanf("%d", &room);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (list[i].room == room)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (list[i].room == room)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found Ideal Room of %d\n", room);
        }
        break;
    }
    case 5:
    {
        int bathroom;
        printf(">> Enter number of Bathrooms to search: ");
        scanf("%d", &bathroom);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (list[i].bathroom == bathroom)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (list[i].bathroom == bathroom)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Ideal Bathroom of %d\n", bathroom);
        }
        break;
    }
    case 6:
    {
        int carPark;
        printf(">> Enter number of Car Parks to search: ");
        scanf("%d", &carPark);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (list[i].carPark == carPark)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (list[i].carPark == carPark)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Ideal Park Space of: %d\n", carPark);
        }
        break;
    }
    case 7:
    {
        char type[255];
        printf(">> Enter Type to search (case sensitive): ");
        scanf(" %[^\n]", type);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(list[i].type, type) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (strcmp(list[i].type, type) == 0)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Type: %s\n", type);
        }
        break;
    }
    case 8:
    {
        char furnish[255];
        printf(">> Enter Furnish to search (case sensitive): ");
        scanf(" %[^\n]", furnish);
        system("clear");
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(list[i].furnish, furnish) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            printf("Data found. Detail of data:\n");
            printHeader();
            for (int i = 0; i < n; i++)
            {
                if (strcmp(list[i].furnish, furnish) == 0)
                {
                    printRow(list, i);
                }
            }
        }
        else
        {
            printf("No matches found for Furnish: %s\n", furnish);
        }
        break;
    }
    default:
        printf("Invalid choice. Returning to menu...\n");
        break;
    }
}

void sortData(D *list, int n, int choice, SO order)
{
    if (choice >= 1 && choice <= 8)
    {
        quickSort(list, 0, n - 1, choice, order);

        printf("Preview of sorted data (sorting affects the database ordering):\n");
        printHeader();
        int limit = (n < 10) ? n : 10;
        for (int i = 0; i < limit; i++)
        {
            printRow(list, i);
        }
    }
    else
    {
        printf("Invalid choice. Returning to menu...\n");
    }
}

int writeFile(D *list, int n, char *filename)
{
    FILE *flush = fopen(filename, "w");
    if (flush == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    fprintf(flush, "");
    fclose(flush);

    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "Location,City,Price,Room,Bathroom,CarPark,Type,Furnish\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n", list[i].location,
                list[i].city,
                list[i].price,
                list[i].room,
                list[i].bathroom,
                list[i].carPark,
                list[i].type,
                list[i].furnish);
    }
    fclose(file);
    return 0;
}

int menu()
{
    int choice;
    printf("What do you want to do?\n");
    printf("1. Display data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your choice : ");
    scanf("%d", &choice);
    return choice;
}

void displayMenu(D *list, int n)
{
    int rows = 0;
    printf(">> Number of rows: ");
    scanf("%d", &rows);
    getchar();

    if (rows > n)
    {
        printf("You requested more rows than available! Showing all %d rows.\n", rows);
        rows = n;
    }

    system("clear");
    printf("Showing %d rows.\n", rows);
    printHeader();
    for (int i = 0; i < rows; i++)
    {
        printRow(list, i);
    }

    printf("\n");
}

void searchMenu(D *list, int n)
{
    printf(">> Choose column to search by\n");
    printf("1. Location\n");
    printf("2. City\n");
    printf("3. Price\n");
    printf("4. Room\n");
    printf("5. Bath\n");
    printf("6. Park\n");
    printf("7. Type\n");
    printf("8. Furnish\n");
    printf(">> Choose column (num): ");

    int validity = 0;
    int choice;
    do
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 8)
        {
            validity = 1;
        }
        else
        {
            printf(">> Choice is not valid, Choose column (num):");
            getchar();
        }
    } while (validity == 0);

    searchData(list, n, choice);
    printf("\n");
}

void sortMenu(D *list, int n)
{
    printf(">> Choose column to be sorted\n");
    printf("1. Location\n");
    printf("2. City\n");
    printf("3. Price\n");
    printf("4. Room\n");
    printf("5. Bath\n");
    printf("6. Park\n");
    printf("7. Type\n");
    printf("8. Furnish\n");
    printf(">> Choose column (num): ");

    int numValidity = 0;
    int choice;
    do
    {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 8)
        {
            numValidity = 1;
        }
        else
        {
            printf(">> Choice is not valid, Choose column (num):");
            getchar();
        }
    } while (numValidity == 0);

    printf(">> Sort by Ascending or Descending ? (asc/desc) : ");

    int charValidity = 0;
    char order[16];
    do
    {
        scanf("%s", order);
        if (strcmp(order, "asc") == 0 || strcmp(order, "desc") == 0)
        {
            charValidity = 1;
        }
        else
        {
            printf(">> Choice is not valid, Choose sort (asc/desc): ");
            getchar();
        }
    } while (charValidity == 0);

    system("clear");
    sortData(list, n, choice, strcmp(order, "asc") == 0 ? ASC : DESC);
    printf("\n");
}

void exportMenu(D *list, int n)
{
    char filename[255];
    printf(">> Write a name for your database copy (letters and numbers only, no special characters): ");
    scanf(" %[^\n]", filename); // Use " %[^\n]" to safely read the filename input

    system("clear");
    strcat(filename, ".csv");
    int successCode = writeFile(list, n, filename);
    printf("%s", successCode == 0 ? strcat(filename, " successfully downloaded!\n") : "Something wrong, couldn't read file\n");
    printf("\n");
}

int main()
{
    FILE *fp = fopen("file(in).csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int n = countLines(fp) - 1;
    D hotelsList[n];
    fetchData(fp, hotelsList, n);
    fclose(fp);

    int REPEAT = 1;
    while (REPEAT == 1)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            displayMenu(hotelsList, n);
            break;
        case 2:
            searchMenu(hotelsList, n);
            break;
        case 3:
            sortMenu(hotelsList, n);
            break;
        case 4:
            exportMenu(hotelsList, n);
            break;
        case 5:
            REPEAT = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

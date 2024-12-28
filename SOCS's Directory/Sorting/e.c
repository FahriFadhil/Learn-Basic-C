#include <stdio.h>
#include <string.h>

typedef struct imGonnaNameThisVariableTheWeirdestWayPossibleJustCauseICanAndImInTheMoodRightNowAnywaySoILetMyFreeWillConquerThisVarNameOhPoorBoy
{
    char cityName[1001];
    double temperature;
    char temperatureType;
} C;

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

double fahrenheitToCelcius(double x)
{
    return (x - 32) * 5 / 9;
}
double celciusToFahrenheit(double x)
{
    return (x * 9 / 5) + 32;
}

void swap(C *a, C *b)
{
    C temp = *a;
    *a = *b;
    *b = temp;
}

int partition(C arr[], int low, int high)
{
    int pivot = arr[high].temperature;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].temperature < pivot || (arr[j].temperature == pivot && strcmp(arr[j].cityName, arr[high].cityName) < 0))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(C arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        perror("No File Found");
        return 0;
    }

    int n = countLines(fp);
    C cityList[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, " %[^#]#%lf#%c", cityList[i].cityName, &cityList[i].temperature, &cityList[i].temperatureType);
    }
    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        if (cityList[i].temperatureType == 'F')
        {
            cityList[i].temperature = fahrenheitToCelcius(cityList[i].temperature);
        }
    }

    quickSort(cityList, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (cityList[i].temperatureType == 'F')
        {
            cityList[i].temperature = celciusToFahrenheit(cityList[i].temperature);
        }
        printf("%s is %.2lf%c\n", cityList[i].cityName, cityList[i].temperature, cityList[i].temperatureType);
    }

    return 0;
}
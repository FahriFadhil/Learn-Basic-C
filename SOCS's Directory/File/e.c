#include <stdio.h>
#include <stdlib.h>

int calculatePerimeter(int size, int *nums)
{
    int perimeter = 0; //? 28

    perimeter += 2 * (size * 2);       // 12
    perimeter += 2 * nums[0];          // 4
    perimeter += 2 * nums[size - 1];   // 6
    for (int i = 0; i < size - 1; i++) // 2 - 4 = -2
    {
        if (nums[i] > nums[i + 1])
        {
            perimeter += 2 * (nums[i] - nums[i + 1]);
        }
        else if (nums[i] < nums[i + 1])
        {
            perimeter += 2 * (nums[i + 1] - nums[i]);
        }
        else
        {
            perimeter += 0;
        }
    }

    return perimeter;
}

int calculateArea(int cubes)
{
    return cubes * 4;
}

int main()
{
    char filename[] = "testdata.in";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    int t;
    fscanf(file, "%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, cubes = 0;
        fscanf(file, "%d", &n);
        int nums[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(file, "%d", &nums[i]);
            cubes += nums[i];
        }
        printf("Case #%d: %d %d\n", tc + 1, calculatePerimeter(n, nums), calculateArea(cubes));
    }

    fclose(file);
    return 0;
}
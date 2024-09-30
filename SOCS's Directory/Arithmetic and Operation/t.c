// #include <stdio.h>

// int main()
// {
//     int a, b, c, d, e, f, g, h, i, j;
//     scanf("MATH6025 %d:20-%d:00\n", &a, &b);
//     scanf("MATH6025 %d:20-%d:00\n", &c, &d);
//     scanf("COMP6047 %d:20-%d:00\n", &e, &f);
//     scanf("COMP6047 %d:20-%d:00\n", &g, &h);
//     scanf("CHAR6013 %d:20-%d:00", &i, &j);
//     printf("MATH6025 %02d:20-%02d:00\n", a - 1, b - 1);
//     printf("MATH6025 %02d:20-%02d:00\n", c - 1, d - 1);
//     printf("COMP6047 %02d:20-%02d:00\n", e - 1, f - 1);
//     printf("COMP6047 %02d:20-%02d:00\n", g - 1, i - 1);
//     printf("CHAR6013 %02d:20-%02d:00\n", i - 1, j - 1);
//     return 0;
// }

#include <stdio.h>

void adjust_time(int *hour, int minutes)
{
    *hour -= 1;
    if (*hour < 0)
    {
        *hour = 23;
    }
}

int main()
{
    char course_code[11];
    int start_hour, start_minute, end_hour, end_minute;

    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d:%d-%d:%d", course_code, &start_hour, &start_minute, &end_hour, &end_minute);

        adjust_time(&start_hour, start_minute);
        adjust_time(&end_hour, end_minute);

        printf("%s %02d:%02d-%02d:%02d\n", course_code, start_hour, start_minute, end_hour, end_minute);
    }

    return 0;
}

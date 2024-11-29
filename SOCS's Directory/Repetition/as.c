// #include <stdio.h>

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     for (int tc = 0; tc < t; tc++)
//     {
//         int n, sum = 0;
//         scanf("%d", &n);

//         char key[n], ans[n];
//         scanf("%s", key);
//         scanf("%s", ans);

//         for (int i = 0; i < n; i++)
//         {
//             if (key[i] == ans[i])
//             {
//                 sum++;
//             }
//         }
//         printf("Case #%d: %.0lf\n", tc + 1, (double)((double)sum / n) * 100);
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        scanf("%d", &n);

        char s[105], k[105];
        scanf("%s", s);
        scanf("%s", k);

        int correct = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == k[i])
            {
                correct++;
            }
        }
        int grade = (correct * 100) / n;
        printf("Case #%d: %d\n", tc, grade);
    }

    return 0;
}

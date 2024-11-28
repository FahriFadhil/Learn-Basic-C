#include <stdio.h>
#include <stdlib.h>

typedef struct Mahasiswa
{
    char name[255];
    char studentId[10];
    char study[255];
    double gpa;
    int satPoints;
    int serviceHours;
} M;

M mhs[255];

void scanMahasiswa(int i)
{
    printf("Masukkan Data Mahasiswa ke-%d\n", i + 1);
    printf("Masukkan Nama Mahasiswa: ");
    scanf("%s", mhs[i].name);
    printf("Masukkan NIM Mahasiswa: ");
    scanf("%s", mhs[i].studentId);
    printf("Masukkan Program Studi Mahasiswa: ");
    scanf("%s", mhs[i].study);
    printf("Masukkan Nilai IPK Mahasiswa: ");
    scanf("%lf", &mhs[i].gpa);
    printf("Masukkan Nilai SAT Mahasiswa: ");
    scanf("%d", &mhs[i].satPoints);
    printf("Masukkan Jam Comserve Mahasiswa: ");
    scanf("%d", &mhs[i].serviceHours);
    printf("\n");
}

void printAllMahasiswa(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Data Mahasiswa ke-%d\n", i + 1);
        printf("Nama Mahasiswa: %s\n", mhs[i].name);
        printf("NIM Mahasiswa: %s\n", mhs[i].studentId);
        printf("Program Studi Mahasiswa: %s\n", mhs[i].study);
        printf("Nilai IPK Mahasiswa: %.2lf\n", mhs[i].gpa);
        printf("Nilai SAT Mahasiswa: %d\n", mhs[i].satPoints);
        printf("Jam Comserve Mahasiswa: %d\n", mhs[i].serviceHours);
        printf("\n");
    }
}

void printMahasiswa(int i, int bool)
{
    bool == 1 ? printf("Data Mahasiswa ke-%d\n", i + 1) : printf("");
    printf("Nama Mahasiswa: %s\n", mhs[i].name);
    printf("NIM Mahasiswa: %s\n", mhs[i].studentId);
    printf("Program Studi Mahasiswa: %s\n", mhs[i].study);
    printf("Nilai IPK Mahasiswa: %.2lf\n", mhs[i].gpa);
    printf("Nilai SAT Mahasiswa: %d\n", mhs[i].satPoints);
    printf("Jam Comserve Mahasiswa: %d\n", mhs[i].serviceHours);
    printf("\n");
}

void sortMahasiswaFromHighestGPA(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mhs[j].gpa < mhs[j + 1].gpa)
            {
                M temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

void titleFormatter(char str[255])
{
    printf("===== ===== %s ===== =====", str);
}
void spacer()
{
    printf("\n");
}

int main()
{
    int n;
    printf("Masukkan Jumlah Mahasiswa: ");
    scanf("%d", &n);

    double avPassingGPA = 0;
    int passingStudent = 0;
    double avNotPassingGPA = 0;
    int notPassingStudent = 0;

    spacer();

    for (int i = 0; i < n; i++)
    {
        scanMahasiswa(i);
    }
    sortMahasiswaFromHighestGPA(n);

    double highestGPA = mhs[0].gpa;
    int highestSatPoints = mhs[0].satPoints;
    int highestServiceHours = mhs[0].serviceHours;

    for (int i = 0; i < n; i++)
    {
        if (mhs[i].satPoints > highestSatPoints)
        {
            highestSatPoints = mhs[i].satPoints;
        }
        if (mhs[i].serviceHours > highestServiceHours)
        {
            highestServiceHours = mhs[i].serviceHours;
        }
    }

    spacer();
    titleFormatter("Data Mahasiswa yang Lulus");
    spacer();
    spacer();
    for (int i = 0; i < n; i++)
    {
        if (mhs[i].gpa >= 2.75 && mhs[i].satPoints >= 120 && mhs[i].serviceHours >= 30)
        {
            printMahasiswa(i, 0);
            passingStudent++;
            avPassingGPA += mhs[i].gpa;
        }
    }
    if (passingStudent > 0)
    {
        avPassingGPA /= passingStudent;
    }
    titleFormatter("Data Mahasiswa yang Tidak Lulus");
    spacer();
    spacer();
    for (int i = 0; i < n; i++)
    {
        if (mhs[i].gpa < 2.75 || mhs[i].satPoints < 120 || mhs[i].serviceHours < 30)
        {
            printMahasiswa(i, 0);
            notPassingStudent++;
            avNotPassingGPA += mhs[i].gpa;
        }
    }
    if (notPassingStudent > 0)
    {
        avNotPassingGPA /= notPassingStudent;
    }

    printf("• Rata-Rata IPK Mahasiswa yang Lulus: %.2lf\n", avPassingGPA);
    printf("• Rata-Rata IPK Mahasiswa yang Tidak Lulus: %.2lf\n", avNotPassingGPA);
    spacer();
    printf("• Jumlah Mahasiswa yang Lulus: %d\n", passingStudent);
    printf("• Jumlah Mahasiswa yang Tidak Lulus: %d\n", notPassingStudent);
    spacer();

    titleFormatter("Data Mahasiswa Diurutkan dari IPK Tertinggi");
    spacer();
    spacer();
    printAllMahasiswa(n);

    titleFormatter("Mahasiswa Dengan IPK Tertinggi");
    spacer();
    spacer();
    for (int i = 0; i < n; i++)
    {
        if (mhs[i].gpa == highestGPA)
        {
            printMahasiswa(i, 0);
        }
    }

    titleFormatter("Mahasiswa Dengan Point SAT Tertinggi");
    spacer();
    spacer();
    for (int i = 0; i < n; i++)
    {
        if (mhs[i].satPoints == highestSatPoints)
        {
            printMahasiswa(i, 0);
        }
    }

    titleFormatter("Mahasiswa Dengan Jam Comserv Tertinggi");
    spacer();
    spacer();
    for (int i = 0; i < n; i++)
    {
        if (mhs[i].serviceHours == highestServiceHours)
        {
            printMahasiswa(i, 0);
        }
    }

    return 0;
}
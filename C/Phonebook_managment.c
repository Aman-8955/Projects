#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define clrscr() system("cls")
FILE *file;
struct data
{
    int sr;
    char name[10];
    long long int phone_number;
} d;
int chack()
{
    int i = 0;
    file = fopen("file.txt", "r");
    while (fread(&d, 1, sizeof(struct data), file))
    {
        i++;
    }
    fclose(file);
    return i;
}
void ch1()
{
    int i = 1;
    clrscr();
    file = fopen("file.txt", "r");
    printf("Sr no.\t\tName\t\tNumber\n");
    while (fread(&d, 1, sizeof(struct data), file))
    {
        printf("\n%d\t\t%s\t\t%lld", i, d.name, d.phone_number);
        i++;
    }
    fclose(file);
}
void ch2()
{
    clrscr();
    printf("Enter Name:- ");
    fflush(stdin);
    gets(d.name);
    printf("Enter Number:- ");
    scanf("%lld", &d.phone_number);
    file = fopen("file.txt", "a+");
    fwrite(&d, 1, sizeof(struct data), file);
    fclose(file);
    printf("Data Saved......\n");
}
void ch3()
{
    int i = 1, num;
    clrscr();
    printf("How many contact you want to save:- ");
    scanf("%d", &num);
    file = fopen("file.txt", "a+");
    while (i <= num)
    {
        clrscr();
        printf("%d:-\n", i);
        printf("Enter Name:- ");
        fflush(stdin);
        gets(d.name);
        printf("Enter Number:- ");
        scanf("%lld", &d.phone_number);
        fwrite(&d, 1, sizeof(struct data), file);
        i++;
    }
    fclose(file);
    printf("Data Saved......\n");
}
void ch4()
{
}
void ch5()
{
    clrscr();
    file = fopen("file.txt", "w");
    fclose(file);
    printf("All Data Deleted......");
}
void ch7()
{
    int choice;
    long long int number;
    char str[10];
    clrscr();
    printf("*****Find Contact*****\n\n");
    printf("[1]Using Name\n[2]Using Number");
    printf("\n\nEnter Your choice:- ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        clrscr();
        fflush(stdin);
        printf("Enter Name:- ");
        gets(str);
        file = fopen("file.txt", "r");
        while (fread(&d, sizeof(struct data), 1, file))
        {
            if (d.name != str)
            {
            }
            else
            {
                printf("\n\nYour Data = %s\t%lld", d.name, d.phone_number);
            }
        }
        fclose(file);
        break;
    case 2:
        clrscr();
        printf("Enter Number:-");
        scanf("%lld", &number);
        file = fopen("file.txt", "r");
        while (fread(&d, sizeof(struct data), 1, file))
        {
            if (d.phone_number == number)
            {
                printf("\n\nYour Data = %s\t%lld", d.name, d.phone_number);
            }
        }
        fclose(file);
        break;
    default:
        printf("\n\nYou Entered Wrong value......");
        break;
    }
}
void def()
{
    file = fopen("file.txt", "r");
    if (file == NULL)
    {
        fclose(file);
        file = fopen("file.txt", "w");
        fclose(file);
        if (file == NULL)
        {
            printf("Error.........");
            exit(0);
        }
    }
    else
    {
        fclose(file);
    }
}
void main()
{
    int num, back;
    def();
menu:
    clrscr();
    printf("Made by Aman Ali\nContact list limit-100\n");
    printf("\n*****Menu*****");
    printf("\n\n[1]All Contact\n[2]Add Contect(one)\n[3]Add Contact(more than one)\n[4]Delete Contect(one)\n[5]Delete Contect(all)\n[6]Edit Contact\n[7]Find\n[8]Total Contacts\n[9]Exit\n\n");
    printf("\nEnter your choice:- ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        ch1();
        goto back;
        break;
    case 2:
        ch2();
        goto back;
        break;
    case 3:
        ch3();
        goto back;
        break;
    case 4:
        break;
    case 5:
        ch5();
        goto back;
        break;
    case 6:
        break;
    case 7:
        ch7();
        goto back;
        break;
    case 8:
        clrscr();
        printf("Total Contact= %d\n\n", chack());
        goto back;
        break;
    case 9:
        exit(3);
        break;

    default:
        clrscr();
        printf("Your entered value is wrong......");
    back:
        printf("\n\n[1]Main menu\n[2]Exit");
        printf("\n\nEnter your key:- ");
        scanf("%d", &back);
        switch (back)
        {
        case 1:
            goto menu;
            break;
        case 2:
            exit(1);
            break;

        default:
            clrscr();
            printf("\nWrong key");
            goto back;
            break;
        }

        break;
    }
    // getch();
}

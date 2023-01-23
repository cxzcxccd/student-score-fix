#include<stdio.h>
#include<string.h>
void Input(char str[][80], int n);
void Sort(char str[][80], int n);
void Print(char str[][80], int n);
int main()
{
    char str[10][80];
    Input(str, 10);
    Sort(str, 10);
    Print(str, 10);
    return 0;
}
void Input(char str[][80], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        gets(str[i]);
    }
}
void Sort(char str[][80], int n)
{
    char temp[80];
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) >= 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}
void Print(char str[][80], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
}

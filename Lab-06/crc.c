/*
    Write a program for error detecting code using CRC-CCITT (16bit) 
*/

#include <stdio.h>

char msg[50], gen[50], rem[50], quo[50], temp[50];
void caltrans(int);
void crc(int);
void calrem();
void shiftl();

int main()
{
    int n, i = 0;
    char ch, flag = 0;
    printf("Enter the Polynomial: ");
    while ((ch = getc(stdin)) != '\n')
        msg[i++] = ch;
    n = i;
    for (i = 0; i < 16; i++)
        msg[n++] = '0';
    msg[n] = '\0';
    printf("Modified Polynomial: %s", msg);
    for (i = 0; i <= 16; i++)
        gen[i] = '0';
    gen[0] = gen[4] = gen[11] = gen[16] = '1';
    gen[17] = '\0';
    printf("\nGenerator: %s", gen);
    crc(n);
    printf("\nQuotient: %s", quo);
    printf("\nChecksum: %s", rem);
    caltrans(n);
    printf("\nFinal Codeword: %s", msg);
    printf("\nEnter transmitted Frame: ");
    scanf("\n%s", msg);
    crc(n);
    for (i = 0; i < 16; i++)
        if (rem[i] != '0')
            flag = 1;
        else
            continue;
    if (flag == 1)
        printf("\nError Detected");
    else
        printf("\nNo Error Detected, Received Frame is correct.");
}

void crc(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        temp[i] = msg[i];
    for (i = 0; i < 16; i++)
        rem[i] = msg[i];

    for (i = 0; i < n - 16; i++)
    {
        if (rem[0] == '1')
        {
            quo[i] = '1';
            calrem();
        }
        else
        {
            quo[i] = '0';
            shiftl();
        }
        rem[16] = msg[17 + i];
        rem[17] = '\0';
        for (j = 0; j <= 17; j++)
            temp[j] = rem[j];
    }
    quo[n - 16] = '\0';
}

void calrem()
{
    int i, j;
    for (i = 1; i <= 16; i++)
        rem[i - 1] = ((int)temp[i] - 48) ^ ((int)gen[i] - 48) + 48;
}

void shiftl()
{
    int i;
    for (i = 1; i <= 16; i++)
        rem[i - 1] = rem[i];
}

void caltrans(int n)
{
    int i, k = 0;
    for (i = n - 16; i < n; i++)
        msg[i] = ((int)msg[i] - 48) ^ ((int)rem[k++] - 48) + 48;
    msg[i] = '\0';
}

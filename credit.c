#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    long creditn;
    do
    {
        creditn = get_long("Credit Card Number: ");
    }
    while (creditn < 0);

    int ndigits;
    long credita = creditn;
    int count = 0;
    int i = 0;
    int r, j, etotal, ototal, ftotal, sedigit, w, nonmtwo, m;
    while (creditn > 0)
    {
        count++;
        creditn = creditn / 10;
    }
    ndigits = count;

    int arr[count];
    int earr[count];
    int oarr[count];
    for (m = 0; m < count; m++)
    {
        arr[m] = 0;
        earr[m] = 0;
        oarr[m] = 0;
    }
    i = 0;
    while (credita != 0)
    {
        r = credita % 10;
        arr[i] = r;
        i++;
        credita = credita / 10;
    }
    int first2 = (arr[count - 1] * 10) + arr[count - 2];
    int first = arr[count - 1];
    i = 0;
    for (w = 1; w < count; w += 2)
    {
        sedigit = (arr[w] * 2);
        while (sedigit != 0)
        {
            r = sedigit % 10;
            oarr[i] = r;
            i++;
            sedigit = sedigit / 10;
        }
    }
    i = 0;
    for (w = 0; w < count; w += 2)
    {
        nonmtwo = arr[w];
        while (nonmtwo != 0)
        {
            r = nonmtwo % 10;
            earr[i] = r;
            i++;
            nonmtwo = nonmtwo / 10;
        }
    }
    ototal = 0;
    for (i = 0; i < count; i++)
    {
        ototal += oarr[i];
    }
    etotal = 0;
    for (i = 0; i < count; i++)
    {
        etotal += earr[i];
    }
    ftotal = etotal + ototal;
    if (ftotal % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if ((ndigits == 15) && (first2 == 34 || first2 == 37))
    {
        printf("AMEX\n");
    }
    else if ((ndigits == 16) && (first2 == 51 || first2 == 52 || first2 == 53 || first2 == 54 || first2 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((ndigits == 13 || ndigits == 16) && (first == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

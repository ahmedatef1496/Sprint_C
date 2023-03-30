#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "stdtypes.h"
#include "sort.h"
#include "LCS.h"

int main()
{

    uint8_t counter;
    // int32_t arr[30] ;
    int32_t *arr;
    uint8_t n;
    int8_t insertionSortflag,lcsflag ;
    while (1)
    {
        system("cls");
        arr=array_scanDynamic(&n);
        printArray(arr, n);
        insertionSortflag=insertionSort(arr, n);
        if (insertionSortflag==-1)
        {
            printf("empty array \n");
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();
            continue;
        }
        else if (insertionSortflag==-2)
        {
            printf(" length of array more than 10\n");
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();
            continue;
        }
        printf("\n-----------after sorting-----------\n\n");
        printArray(arr, n);

        lcsflag=lcsGetSize(arr,n,&counter);;
        if (lcsflag==-1)
        {
            printf("empty array \n");
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();
            continue;
        }
        else if (lcsflag==-2)
        {
            printf(" length of array more than 10\n");
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();
            continue;
        }
        else if (lcsflag==-3)
        {
            printf("all array elements are not consecutive at all \n");
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();
        }
        else if  (lcsflag==0)
        {
            printf("\nLongest Consecutive Subsequence(LCS) =%d\n  ",counter);
            printf("\n-----------------------------------\n");
            printf("\nplease enter any key to try again \n  ");
            getch();

        }

    }
    return 0;
}

#include "stdtypes.h"
#include "sort.h"
#include "LCS.h"
void printArray(int32_t *array, uint8_t arraySize)
{
    int i;
    printf("------------array print------------\n\n");
    for (i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n-----------------------------------\n");
}

int32_t* array_scanDynamic(uint8_t*parraySize)
{
    uint8_t i,arraySize;
    printf("enter total numbers\n");
    scanf("%d",&arraySize);

    int32_t*arr=(int32_t*)malloc(arraySize*sizeof(int32_t));
    if(arr==0)
    {
        return 0;
    }

    printf("enter  numbers\n");
    for(i=0; i<arraySize; i++)
    {
        scanf("%d",&arr[i]);
    }


    *parraySize=arraySize;
    return arr;
}



int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    int32_t i, j;
    int32_t key;
    int8_t flag=0;
    if (arraySize<1)
    {
        flag=-1;
    }
    else if (arraySize>10)
    {
        flag=-2;
    }
    else
    {
        for (i = 1; i < arraySize; i++)
        {
            key = array[i];
            j = i - 1;

            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
    return flag ;
}

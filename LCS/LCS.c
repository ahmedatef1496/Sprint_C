#include "stdtypes.h"
#include "sort.h"
#include "LCS.h"

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    int8_t count=1;
    int8_t flag=0;
    *sizeofLCS=0;
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

        for(int i=0 ; i<arraySize-1; i++)
        {
            if(array[i] == array[i+1])
            {
                continue;
            }
            else if (array[i] + 1 == array[i + 1])
            {
                count++;
            }
            else
            {
                count=1;
            }

            if(count > *sizeofLCS)
            {

                *sizeofLCS=count;
            }



        }

        if (*sizeofLCS<2)
        {
            flag=-3;
        }
    }

    return flag;
}

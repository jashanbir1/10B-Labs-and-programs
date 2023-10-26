#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0)
    {
        return &arr[0];
    }
   
    const int* val = min(arr, arrSize-1);
    //int* val1;
    if(*val > arr[arrSize - 1])
    {
        return arr + arrSize-1;
    }
    else
    {
        return val;
    }
    
}



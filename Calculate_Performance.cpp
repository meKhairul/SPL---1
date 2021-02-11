#include "header.h"

double Calculate_Performance(double B,int arr[])
{
    int l = B*10,x=100;
    for(int i=0;i<=136;i++)
    {
        if(arr[i]==l)
        {
            x=i;break;
        }
    }
    return x;
}

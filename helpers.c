/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include<stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0, max = n - 1, mid;
    while ((max - min + 1) > 0)
    {
        mid = (max - min + 1)/ 2 + min;
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] < value)
        {       
            min = mid + 1;
        }
        else if (values[mid] > value)
        {
            max = mid - 1;
        }
    }
    return false;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i,j,min;
  for ( i = 0; i < n - 1; i++)
    {
        for( j = i + 1; j < n; j++)
        {
            if (values[i] > values[j])
            {
                min = values[j];
                values[j] = values[i];
            }
            else 
            {
                min = values[i];
            } 
            values[i] = min;
        } 
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", values[i]);
    }
 
}

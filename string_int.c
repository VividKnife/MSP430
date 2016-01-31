
//******************************************************************************
//
//  Description: This file contains the tostring fuction
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
//******************************************************************************

//------------------------------------------------------------------------------
#include "msp430.h"
#include "functions.h"
#include "macros.h"


//******************************************************************************
//
//  Description: This function put numb into an arry
//
//
//  shufan kang
//  Sep 2015
//  Built with IAR Embedded Workbench Version: 6.30.2
// input: the arry, and the number
//******************************************************************************






void toString(char string[], int num)
{
    int i, rem, length = CLEAR, n;
 
    n = num;
    while (n != CLEAR)
    {
        length++;
        n /= SDIV;
    }
    for (i = CLEAR; i < length; i++)
    {
        rem = num % SDIV;
        num = num /SDIV;
        string[length - (i + ONE)] = rem + '0';
    }
    string[length] = '\0';
}
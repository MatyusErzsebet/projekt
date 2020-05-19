#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "jatek.h"
#include "jatek.c"

int main()
{
    printf("Milyen szinten szeretned kezdeni a jatekot?\n kezdo:1\n kozepes:2\n halado:3\n");
    int option;
    scanf("%i", &option);
    jatek(option);

}



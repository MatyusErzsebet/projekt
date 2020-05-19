#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char **palya);
void jatek(int szint);


#endif // JATEK_H_INCLUDED

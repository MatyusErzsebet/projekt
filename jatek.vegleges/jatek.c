#include "jatek.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
int hossz, szel, elet = 1;

char** beolvasPalya(const char* fajlNev)
{    int i,j;
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	//ellenorzes
	for ( i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}
	for ( i = 0; i < hossz; ++i) {
		for (j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
		}
	}
	return palya;
}

void kirajzolPalya(char** palya)
{   int i,j;
	for ( i = 0; i < hossz; ++i) {
		for (j = 0; j < szel; ++j) {
			if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
				printf("%c",177);
			}
			else if (palya[i][j] == '3' || j==szel-1) {
				printf("%c",177);
			}
                else if (palya[i][j] == '3' || j==0) {
				printf("%c",177);
                }
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("%c", 240);
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				printf("P");
			}
			if (palya[i][j] == '$') {
				printf("$");
			}

			if (palya[i][j] == 'F') {
				printf("F");
			}
		}
		printf("\n");
	}
}

void jatek(int szint)
{
    srand(time(NULL));
    int i, j;
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	if(szint==1)
	palya = beolvasPalya("kezdo.txt");
	else if(szint==2)
        palya = beolvasPalya("kozepes.txt");
    else if(szint==3)
        palya = beolvasPalya("halado.txt");
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya);
    int szornyX,szornyY;
        szornyX = 2 + rand() % (hossz - 3);
        szornyY = 1 + rand() % (szel - 2);
    palya[szornyX][szornyY] = 'R';
    palya[hossz-2][szel-2]='$';
	while (1) {
        printf("elet: %i\n", elet);
		currentTime = time(NULL);
		kirajzolPalya(palya);
		char option = getch();
        elozoX = jatekosX;
        elozoY = jatekosY;
        if (option == 'd')
        {
            jatekosY++;
            if(palya[jatekosX][jatekosY]=='1'|| palya[jatekosX][jatekosY]=='3')
            {
                jatekosY--;
                elet--;
            }
        }
        else if (option == 's')
        {
            jatekosX++;
            if(palya[jatekosX][jatekosY]=='1'|| palya[jatekosX][jatekosY]=='3')            {
                jatekosX--;
                elet--;
            }
        }
            else if (option == 'a')
            {
                jatekosY--;
            if(palya[jatekosX][jatekosY]=='1'|| palya[jatekosX][jatekosY]=='3')            {
                jatekosY++;
                elet--;
            }
            }
            else if (option == 'w')
            {
                jatekosX--;
                if(palya[jatekosX][jatekosY]=='1'|| palya[jatekosX][jatekosY]=='3')
            {
                jatekosX++;
                elet--;
            }
            }

		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}

		if (palya[jatekosX][jatekosY] == '0')//helyes lepes
            {
                palya[jatekosX][jatekosY] = 'P';
                palya[elozoX][elozoY] = '0';
            }
            else if (palya[jatekosX][jatekosY] == '*')   // fal->nem mehet arra de veszit egy eletet
            {
                jatekosX=elozoX;
                jatekosY=elozoY;
                palya[jatekosX][jatekosY] = 'P';
                elet--;
            }
            else if (palya[jatekosX][jatekosY] == 'F')   //food-kap egy plusz eletet
            {
                palya[jatekosX][jatekosY] = 'P';
                palya[elozoX][elozoY] = '0';
                elet++;
            }

            else if (palya[jatekosX][jatekosY] == 'R')   //szorny->vege
            {
                printf("vesztettel, a jateknak vege ");
                exit(0);
            }
            else if (palya[jatekosX][jatekosY] == '$')   //cel
            {   system("CLS");


                if(szint<3)
                {
                    printf("gratulalok, celba ertel %i darab elettel\n", elet);
                    jatek(szint + 1);
                }
                else
                {printf("Gratulalok megnyerted a jatekot");
                    Sleep(300);
                    exit(1);
                }
            }
            if(elet==0)
            {
                printf("vesztettel, a jateknak vege ");
                exit(0);
            }

        system("CLS");
	}
}

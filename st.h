#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct opis{
char imie[15],nazwisko[20],cechy_sz[6][30];
int status,id,wiek,wzrost,waga;
struct opis *next;
}opis;


typedef struct przestepstwa{
char miasto[40];
int id[100],dzien,miesiac,rok,nr;
struct przestepstwa *next;
}przewa;


void dod_przest();
void dod_miejsca();
void status();
void wysz_przest();
void wysz_m_p();
int usuwanie();

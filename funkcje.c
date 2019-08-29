#include "st.h"

int id_przest(){
    FILE *fil;
    char znak,zwraca[5];
    int i,k,zwroc,wiersz=0;
    if((fil=fopen("opisy.txt","r")) == NULL) return 0;
    while((znak=getc(fil)) != EOF){
        if(znak=='\n') wiersz++;
    }
    fseek(fil,0,0);
    for(i=0;i<wiersz;i++){
        k=0;
        while((znak=getc(fil)) != ' '){
            zwraca[k]=znak;
            k++;
        }
        while((znak=getc(fil)) != '\n');
    }
    zwroc=atoi(zwraca);
    zwroc++;
    return zwroc;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void dod_przest(){
int i,n,k,cechy,j,spr,suma=0,strl,dl,sprf,floa=0,liczenie=0,ktory_id=0;
char proba[30],znak,pom;
double w=0;
FILE *file,*idd;
opis *lista,*wsk,*wynik;
wsk=malloc(sizeof(opis));
wynik=NULL;
system("cls");
if((idd=fopen("opisy.txt","rt"))==NULL){
    printf("Blad pliku");
}
wsk=NULL;
for(;;){
printf("\nIlu chcesz przestepcow dodac? ");
scanf("%s", proba);
dl=strlen(proba);
suma=0;
for(i=0;i<dl;i++){
    if(isdigit(proba[i])) suma++;
}
if(suma==dl){
    n=atoi(proba);
    break;
}
else printf("\nPodaj liczbe");
}
for(i=0;i<n;i++){
    lista=malloc(sizeof(opis));
    for(;;){
    printf("\nPodaj imie: ");
    scanf("%s",lista->imie);
    strl=strlen(lista->imie);
    suma=0;
    for(spr=0;spr<strl;spr++){
        if(isalpha(lista->imie[spr]))suma++;
        }
    if(suma==strl){
        if(islower(lista->imie[0])) lista->imie[0]-=32;
        for(j=1;j<suma;j++){
            if(isupper(lista->imie[j])) lista->imie[j]+=32;
        }
        break;
    }
    else printf("Imie nie moze posiadac cyfry ");
    }
    for(;;){
    printf("\nPodaj nazwisko:");
    scanf("%s",lista->nazwisko);
    strl=strlen(lista->nazwisko);
    suma=0;
    for(spr=0;spr<strl;spr++){
        if(isalpha(lista->nazwisko[spr]))suma++;
        }
    if(suma==strl){
        if(islower(lista->nazwisko[0])) lista->nazwisko[0]-=32;
        for(j=1;j<suma;j++){
            if(isupper(lista->nazwisko[j])) lista->nazwisko[j]+=32;
        }
        break;
    }
    else printf("Imie nie moze posiadac cyfry ");
    }
   for(;;){
    printf("\nPodaj wzrost:");
    scanf("%s",proba);
    dl=strlen(proba);
    sprf=0;
    floa=0;
    for(k=0;k<dl;k++){
        if(isdigit(proba[k]))sprf++;
    }
    if(sprf==dl){
        lista->wzrost=atoi(proba);
        break;
    }
        else printf("Zle wprowadzone dane");
    }
    for(;;){
    printf("\nPodaj wage: ");
    scanf("%s",proba);
    dl=strlen(proba);
    sprf=0;
    floa=0;
    for(k=0;k<dl;k++){
        if(isdigit(proba[k]))sprf++;
    }
    if(sprf==dl){
        lista->waga=atoi(proba);
        break;
    }
        else printf("Zle wprowadzono dane");
    }
    for(;;){
    printf("\nPodaj wiek: ");
    scanf("%s",proba);
    dl=strlen(proba);
    sprf=0;
    for(k=0;k<dl;k++){
        if(isdigit(proba[k]))sprf++;
    }
    if(sprf==dl){
        lista->wiek=atoi(proba);
        break;
    }
        printf("Zle wprowadzono dane");
    }
    for(;;){
    printf("\nPodaj status( 1 jesli zostal zlapany, 0 jesli nie): ");
    scanf("%s",proba);
    dl=strlen(proba);
    if(dl!=1) printf("Zle wprowadzone dane");
    else if(proba[0]=='1' || proba[0]=='0'){
        lista->status=atoi(proba);
        break;
    }
    else printf("Zle wprowadzone dane");
    }
    for(;;){
        printf("\nIle ma cech szczegolnych?(max 5) ");
        scanf("%s", proba);
        suma=0;
        dl=strlen(proba);
        for(j=0;j<dl;j++){
            if(isdigit(proba[j])) suma++;
        }
        if(suma==dl){
        spr=atoi(proba);
        if(spr>5) printf("Mozesz podac max 5 cech");
        else if(spr<5){
            cechy = atoi(proba);
            break;
            }
        }
        else printf("Zle wprowadzone dane");
    }
    for(j=0;j<cechy;j++){
        for(;;){
        printf("Podaj %d ceche szczegolna ",j+1);
        fflush(stdin);
        gets(proba);
        dl=strlen(proba);
        if(dl<30) break;
        else printf("Blad, nie trzeba tak duzo podawac, skroc dlugosc slowa cechy szczegolnej");
        }
        for(k=0;k<dl;k++){
            if(proba[k]==' ') proba[k]='_';
        }
        proba[dl]='\0';
        strcpy(lista->cechy_sz[j],proba);
    }
    lista->cechy_sz[cechy][0]='0';
if(ktory_id==0) ktory_id = id_przest();
else ktory_id++;
lista->id=ktory_id;
lista->next=NULL;
if(wsk==NULL) {
    wsk=lista;
    wynik=wsk;
    }
if(wsk!=NULL){
    wsk->next =lista;
    wsk=wsk->next;
    wsk->next=NULL;
    }
    system("cls");
}
if((file=fopen("opisy.txt","a"))==NULL) printf("Blad pliku");
while(wynik!=NULL){
    fprintf(file,"%d ",wynik->id);
    fprintf(file,"%s ",wynik->imie);
    fprintf(file,"%s ",wynik->nazwisko);
    fprintf(file,"%d ",wynik->wzrost);
    fprintf(file,"%d ",wynik->waga);
    fprintf(file,"%d ",wynik->wiek);
    for(i=0;wynik->cechy_sz[i][0]!='0';i++){
        fprintf(file,"%s ",wynik->cechy_sz[i]);
    }
    fprintf(file,"%d\n",wynik->status);
    wynik=wynik->next;
    }
fclose(file);
return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int sprawdzenie_id(int liczba){
char znak,proba[20];
int ile_id=0,*tab_id,i,k,spr=0;
FILE *idd;
    if((idd=fopen("opisy.txt","rt"))==NULL){
    printf("Blad pliku");
}
while((znak=getc(idd))!=EOF){
    if(znak=='\n') ile_id++;
}
tab_id=malloc(sizeof(int)*ile_id);
fseek(idd,0,0);

for(i=0;i<ile_id;i++){
    k=0;
    while((znak=getc(idd))!=' '){
        proba[k]=znak;
        k++;
    }
    proba[k]='\0';
    tab_id[i]=atoi(proba);
    while((znak=getc(idd))!='\n');
}
for(i=0;i<ile_id;i++){
    if(liczba==tab_id[i]) spr++;
}
return spr;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int nr_przest(){
    FILE *fil;
    char znak,zwraca[5];
    int i,k,zwroc,wiersz=0;
    if((fil=fopen("miejsca.txt","r")) == NULL) return 0;
    while((znak=getc(fil)) != EOF){
        if(znak=='\n') wiersz++;
    }
    fseek(fil,0,0);
    for(i=0;i<wiersz;i++){
        k=0;
        while((znak=getc(fil)) != ' '){
            zwraca[k]=znak;
            k++;
        }
        while((znak=getc(fil)) != '\n');
    }
    zwroc=atoi(zwraca);
    zwroc++;
    return zwroc;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void dod_miejsca(){
int ile,i,n,k,j,prawda,suma=0,dl=0,ilosc,ktory_nr=0,spr=0;
FILE *file;
char pyt,proba[20];
przewa *doda,*nast,*wynik;
nast=NULL;
wynik=NULL;
system("cls");
for(;;){
printf("\nIlu chcesz dodac miejsc przestepstw? ");
scanf("%s", proba);
dl=strlen(proba);
suma=0;
for(i=0;i<dl;i++){
    if(isdigit(proba[i])) suma++;
}
if(suma==dl){
    ilosc=atoi(proba);
    break;
}
else printf("\nPodaj liczbe");
}

for(k=0;k<ilosc;k++){
doda=malloc(sizeof(przewa));
    for(;;){
        suma=0;
        printf("\nPodaj miasto w ktorym popelniono przestepstwo ");
        scanf("%s", doda->miasto);
        dl=strlen(doda->miasto);
        for(i=0;i<dl;i++){
            if(isalpha(doda->miasto[i]))suma++;
        }
        if(suma==dl){
            if(islower(doda->miasto[0])) doda->miasto[0]-=32;
            for(j=1;j<suma;j++){
                if(isupper(doda->miasto[j])) doda->miasto[j]+=32;
            }
            break;
        }
        else printf("\nPodales zla nazwe miasta, sprobuj ponownie\n");
    }
    if(ktory_nr == 0) ktory_nr=nr_przest();
    else ktory_nr++;
    doda->nr=ktory_nr;
    for(;;){
        printf("\nPodaj rok w ktorym popelniono przestepstwo ");
        scanf("%s",proba);
        dl=strlen(proba);
        if(dl==4){
            if(isdigit(proba[0]) && isdigit(proba[1]) && isdigit(proba[2]) && isdigit(proba[3])){
                    doda->rok=atoi(proba);
                    break;
            }
        }
        else printf("\nZle wprowadzone dane\n");
    }
    for(;;){
        printf("\nPodaj miesiac w ktorym popelniono przestepstwo (1 - 12) ");
        scanf("%s",proba);
        dl=strlen(proba);
        if(dl==1){
            if(isdigit(proba[0])){
                if((atoi(proba))<0) printf("\nZle wprowadzone dane\n");
                else if((atoi(proba))>12) printf("\nZle wproawdzone dane\n");
                else {
                    doda->miesiac=atoi(proba);
                    break;
                }
            }
        }
        else if(dl==2){
            if((isdigit(proba[0])) && (isdigit(proba[1])))
                if((atoi(proba))<0) printf("\nZle wprowadzone dane\n");
                else if((atoi(proba))>12) printf("\nZle wproawdzone dane\n");
                else {
                    doda->miesiac=atoi(proba);
                    break;
                }
        }
        else printf("\nZle wprowadzone dane\n");
    }
    for(;;){
        printf("\nPodaj dzien w ktorym popelniono przestepstwo ");
        scanf("%s",proba);
        dl=strlen(proba);
        if(dl==1){
            if(isdigit(proba[0])){
                if((atoi(proba))<0) printf("\nZle wprowadzone dane\n");
                else if((atoi(proba))>9) printf("\nZle wproawdzone dane\n");
                else {
                    doda->dzien=atoi(proba);
                    break;
                }
            }
            else printf("\nTo nie jest liczba\n");
        }
        else if(dl==2 && (doda->miesiac==1 || doda->miesiac==3 || doda->miesiac==5 || doda->miesiac==7 || doda->miesiac==8 || doda->miesiac==10 ||doda->miesiac==12)){
            if((isdigit(proba[0])) && (isdigit(proba[1]))){
                if((atoi(proba))<0) printf("\nZle wprowadzonadata\n");
                else if((atoi(proba))>31) printf("\nTen miesiac nie ma az tylu dni\n");
                else{
                    doda->dzien=atoi(proba);
                    break;
                }
            }
            else printf("\nTo nie jest liczba\n");
        }
        else if(dl==2 && (doda->miesiac==4 || doda->miesiac==6 || doda->miesiac==9 || doda->miesiac==11)){
            if((isdigit(proba[0])) && (isdigit(proba[1]))){
                if((atoi(proba))<0) printf("\nZle wprowadzona data\n");
                else if((atoi(proba))>31) printf("\nTen miesiac nie ma az tylu dni\n");
                else {
                    doda->dzien=atoi(proba);
                    break;
                }
            }
            else printf("\nTo nie jest liczba\n");
        }
        else if(dl==2 && doda->miesiac==2 && doda->rok%4==0 && doda->rok%100!=0){
            if((isdigit(proba[0])) && (isdigit(proba[1]))){
                if((atoi(proba))<0) printf("\nZle wprowadzona data\n");
                else if((atoi(proba))>29) printf("\nTen miesiac nie ma az tylu dni\n");
                else {
                    doda->dzien=atoi(proba);
                    break;
                }
            }
            else printf("\nTo nie jest liczba\n");
        }
        else{
            if((isdigit(proba[0])) && (isdigit(proba[1]))){
                if((atoi(proba))<0) printf("\nZle wprowadzona data\n");
                else if((atoi(proba))==29) printf("To nie jest rok przestepny\n");
                else if((atoi(proba))>29) printf("\nTen miesiac nie ma az tylu dni\n");
                else {
                    doda->dzien=atoi(proba);
                    break;
                }
            }
            else printf("\nTo nie jest liczba\n");
        }
    }
    for(;;){
    printf("\nIlu przestepcow bralo udzial w zdarzeniu? ");
    scanf("%s",proba);
        dl=strlen(proba);
        suma=0;
        for(i=0;i<dl;i++){
            if(isdigit(proba[i])) suma++;
        }
        if(suma==dl && atoi(proba)!=0){
            ile=atoi(proba);
            break;
        }
        else printf("\nZle wprowadzone dane\n");
    }
    for(i=0;i<ile;i++){
     for(;;){
        printf("\nPodaj %d id przestepcy ",i+1);
        spr=0;
        scanf("%s",proba);
        dl=strlen(proba);
        suma=0;
        for(n=0;n<dl;n++){
            if(isdigit(proba[n])) suma++;
        }
        if(suma==dl){
            if(sprawdzenie_id(atoi(proba))){
                doda->id[i]=atoi(proba);
                for(n=0;n<i;n++){
                    if(doda->id[n]==doda->id[i]) spr=1;
                }
                if(spr==1) printf("\nNie mozna powtorzyc tego samego id\n");
                if(spr==0) break;
            }
            else printf("\nNie ma takiego przestepcy\n");
        }
        else printf("\nZle wprowadzone dane lub podanie id przestepcy ktory nie istnieje\n");
        doda->id[i+1]==0;
     }
    }
    doda->next=NULL;
    if(nast==NULL){
        nast=doda;
        wynik=nast;
    }
    if(nast!=NULL){
        nast->next=doda;
        nast=nast->next;
        nast->next=NULL;
    }
    system("cls");
}

if((file=fopen("miejsca.txt","a"))==NULL){
    printf("Plik nie wczytany");
}
while(wynik!=NULL){
    fprintf(file,"%d ",wynik->nr);
    fprintf(file,"%s ",wynik->miasto);
    fprintf(file,"%d %d %d ",wynik->dzien,wynik->miesiac,wynik->rok);
    for(i=0;(wynik->id[i])!=0;i++){
        if((wynik->id[i+1])==0) fprintf(file,"%d\n",wynik->id[i]);
        else fprintf(file,"%d ",wynik->id[i]);
    }
    wynik=wynik->next;
}
fclose(file);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void status(){
 FILE *przest;
    int i=0,linia=0,k,*wiersz,ile_wierszy=0,ile,n,wybor,suma,dl,licz;
    char znak,id[10];
    opis *wsk,*lista,*wynikp;
    lista=NULL;
    for(;;){
        suma=0;
        printf("\nPodaj id przestepcy ");
        scanf("%s",id);
        dl=strlen(id);
        for(i=0;i<dl;i++){
            if(isdigit(id[i])) suma++;
        }
        if(suma==dl){
            licz=atoi(id);
            break;
        }
        if(suma!=dl) printf ("Zle wprowadzone dane\n\n");
    }
    if((przest=fopen("opisy.txt","r"))== NULL) printf("\nBlad pliku");

    while((znak = getc(przest)) != EOF)
   {
      if(znak =='\n'){
        ile_wierszy++;
      }
   }
   i=0;
    wiersz=malloc(sizeof(int)*ile_wierszy);
    fseek(przest,0,0);
    while((znak = getc(przest)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
   fseek(przest,0, 0);
   i=0;

    for(k=0;k<ile_wierszy;k++){
    wsk=malloc(sizeof(opis));
    ile=wiersz[i]-6;
    i++;
    fscanf(przest,"%d ",&wsk->id);
    fscanf(przest,"%s ",wsk->imie);
    fscanf(przest,"%s ",wsk->nazwisko);
    fscanf(przest,"%d ",&wsk->wzrost);
    fscanf(przest,"%d ",&wsk->waga);
    fscanf(przest,"%d",&wsk->wiek);

    for(n=0;n<ile;n++)
        {
        fscanf(przest,"%s",wsk->cechy_sz[n]);
    }

    wsk->cechy_sz[n+1][0]='\0';
    fscanf(przest,"%d ",&wsk->status);
    wsk->next=NULL;
    if(lista==NULL){
        lista=wsk;
        wynikp=lista;
    }
    else{
    lista->next =wsk;
    lista=lista->next;
    lista->next=NULL;
    }
}

fclose(przest);
if((przest=fopen("opisy.txt","w"))==NULL) printf("Blad pliku2");

while(wynikp!=NULL){
    fprintf(przest,"%d ",wynikp->id);
    fprintf(przest,"%s ",wynikp->imie);
    fprintf(przest,"%s ",wynikp->nazwisko);
    fprintf(przest,"%d ",wynikp->wzrost);
    fprintf(przest,"%d ",wynikp->waga);
    fprintf(przest,"%d ",wynikp->wiek);
    for(i=0;wynikp->cechy_sz[i][0]!='\0';i++){
        fprintf(przest,"%s ",wynikp->cechy_sz[i]);
    }
    if(wynikp->id==licz){
        if(wynikp->status==0){
            printf("\nStatus osoby %s %s zostal zmieniony.\nAktualny status: Zlapany",wynikp->imie,wynikp->nazwisko);
            wynikp->status=1;
        }
        else if(wynikp->status==1) {
            printf("\nStatus osoby %s %s zostal zmieniony.\nAktualny status: Na wolnosci",wynikp->imie,wynikp->nazwisko);
            wynikp->status=0;
        }
    }
    fprintf(przest,"%d\n",wynikp->status);
    wynikp=wynikp->next;
    }
fclose(przest);
free(wiersz);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void wieki(opis *HEAD){
 opis *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;
   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if(poprz->wiek<poprz->next->wiek){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }
      while(poprz->next->next!=NULL){
        if(poprz->wiek<poprz->next->wiek && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if(poprz->wiek<poprz->next->wiek && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((poprz->next->wiek)<(poprz->next->next->wiek)){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if(poprz->wiek>=poprz->next->wiek) poprz=poprz->next;
      }
}

while(wynik!=NULL){
    printf("id: %d ",wynik->id);
    printf("\nimie :%s ",wynik->imie);
    printf("\nwynik: %s ",wynik->nazwisko);
    printf("\nwzrost: %d ",wynik->wzrost);
    printf("\nwaga: %d ",wynik->waga);
    printf("\nwiek: %d",wynik->wiek);
    for(n=0;wynik->cechy_sz[n][0]!='\0';n++)
        {
        printf("\ncecha %d:%s",n+1,wynik->cechy_sz[n]);
    }
    if(wynik->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
    if(wynik->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void waga(opis *HEAD){
 opis *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;
   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if(poprz->waga<poprz->next->waga){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }
      while(poprz->next->next!=NULL){
        if(poprz->waga<poprz->next->waga && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if(poprz->waga<poprz->next->waga && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((poprz->next->waga)<(poprz->next->next->waga)){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if(poprz->waga>=poprz->next->waga) poprz=poprz->next;
      }
}

while(wynik!=NULL){
    printf("id: %d ",wynik->id);
    printf("\nimie :%s ",wynik->imie);
    printf("\nwynik: %s ",wynik->nazwisko);
    printf("\nwzrost: %d ",wynik->wzrost);
    printf("\nwaga: %d ",wynik->waga);
    printf("\nwiek: %d",wynik->wiek);
    for(n=0;wynik->cechy_sz[n][0]!='\0';n++)
        {
        printf("\ncecha %d:%s",n+1,wynik->cechy_sz[n]);
    }
    if(wynik->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
    if(wynik->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void wzrost(opis *HEAD){
 opis *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;
   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if(poprz->wzrost<poprz->next->wzrost){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }
      while(poprz->next->next!=NULL){
        if(poprz->wzrost<poprz->next->wzrost && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if(poprz->wzrost<poprz->next->wzrost && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((poprz->next->wzrost)<(poprz->next->next->wzrost)){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if(poprz->wzrost>=poprz->next->wzrost) poprz=poprz->next;
      }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
while(wynik!=NULL){
    printf("id: %d ",wynik->id);
    printf("\nimie :%s ",wynik->imie);
    printf("\nwynik: %s ",wynik->nazwisko);
    printf("\nwzrost: %d ",wynik->wzrost);
    printf("\nwaga: %d ",wynik->waga);
    printf("\nwiek: %d",wynik->wiek);
    for(n=0;wynik->cechy_sz[n][0]!='\0';n++)
        {
        printf("\ncecha %d:%s",n+1,wynik->cechy_sz[n]);
    }
    if(wynik->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
    if(wynik->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void imie(opis *HEAD){
 opis *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;
   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if((strcmp(poprz->imie,poprz->next->imie))>0){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }
      while(poprz->next->next!=NULL){
        if((strcmp(poprz->imie,poprz->next->imie))>0 && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if((strcmp(poprz->imie,poprz->next->imie))>0 && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((strcmp(poprz->next->imie,poprz->next->next->imie))>0){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if((strcmp(poprz->imie,poprz->next->imie))<=0) poprz=poprz->next;
      }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
while(wynik!=NULL){
    printf("id: %d ",wynik->id);
    printf("\nimie :%s ",wynik->imie);
    printf("\nwynik: %s ",wynik->nazwisko);
    printf("\nwzrost: %d ",wynik->wzrost);
    printf("\nwaga: %d ",wynik->waga);
    printf("\nwiek: %d",wynik->wiek);
    for(n=0;wynik->cechy_sz[n][0]!='\0';n++)
        {
        printf("\ncecha %d:%s",n+1,wynik->cechy_sz[n]);
    }
    if(wynik->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
    if(wynik->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void nazwisko(opis *HEAD){
 opis *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;
   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if((strcmp(poprz->nazwisko,poprz->next->nazwisko))>0){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }
      while(poprz->next->next!=NULL){
        if((strcmp(poprz->nazwisko,poprz->next->nazwisko))>0 && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if((strcmp(poprz->nazwisko,poprz->next->nazwisko))>0 && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((strcmp(poprz->next->nazwisko,poprz->next->next->nazwisko))>0){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if((strcmp(poprz->nazwisko,poprz->next->nazwisko))<=0) poprz=poprz->next;
      }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
while(wynik!=NULL){
    printf("id: %d ",wynik->id);
    printf("\nimie :%s ",wynik->imie);
    printf("\nwynik: %s ",wynik->nazwisko);
    printf("\nwzrost: %d ",wynik->wzrost);
    printf("\nwaga: %d ",wynik->waga);
    printf("\nwiek: %d",wynik->wiek);
    for(n=0;wynik->cechy_sz[n][0]!='\0';n++)
        {
        printf("\ncecha %d:%s",n+1,wynik->cechy_sz[n]);
    }
    if(wynik->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
    if(wynik->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void miejsca(przewa *HEAD){
 przewa *wynik,*lista,*poprz,*pom,*pom2,*nast;
  int i,n;
  lista=HEAD;

   if(lista){
       poprz=lista;
       wynik=poprz;
       if(poprz->next->next==NULL){
            if((strcmp(poprz->miasto,poprz->next->miasto))>0){
                    nast=poprz->next;
                    poprz->next=nast->next;
                    nast->next=poprz;
                    wynik=nast;
                    poprz=wynik;

                }
       }

      while(poprz->next->next!=NULL){
        if((strcmp(poprz->miasto,poprz->next->miasto))>0 && poprz==wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik=nast;
                poprz=wynik;
            }
            if((strcmp(poprz->miasto,poprz->next->miasto))>0 && poprz!=wynik){
                nast=poprz->next;
                poprz->next=nast->next;
                nast->next=poprz;
                wynik->next=nast;
                poprz=wynik;
            }
                if((strcmp(poprz->next->miasto,poprz->next->next->miasto))>0){
                    nast=poprz->next->next;
                    pom=poprz->next;
                    pom2=nast->next;
                    poprz->next=nast;
                    nast->next=pom;
                    pom->next=pom2;
                    poprz=wynik;
                }
if((strcmp(poprz->miasto,poprz->next->miasto))<=0) poprz=poprz->next;
      }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
while(wynik!=NULL){
    printf("\nNr :%d ",wynik->nr);
    printf("\nMiasto: %s ",wynik->miasto);
    printf("\nData: %d.%d.%d ",wynik->dzien,wynik->miesiac,wynik->rok);
    for(n=0;wynik->id[n]!=0;n++);
    printf("\nIlosc przestepcow, ktorzy brali udzial: %d",n);
    printf("\n\n");
    wynik=wynik->next;
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void wysz_przest(){
FILE *miej,*przest;
    int i=0,linia=0,k,*wiersz,ile_wierszy=0,ile,n,wybor;
    char znak;
    opis *wsk,*lista,*wynikp;
    przewa *wskm,*listam,*wynikm;
    listam=NULL;
    lista=NULL;
    wynikm=NULL;
    wynikp=NULL;
    if((miej=fopen("miejsca.txt","r"))== NULL) printf("\nBlad pliku");
    if((przest=fopen("opisy.txt","r"))== NULL) printf("\nBlad pliku");

    while((znak = getc(przest)) != EOF)
   {
      if(znak =='\n'){
        ile_wierszy++;
      }
   }
    wiersz=malloc(sizeof(int)*ile_wierszy);
    fseek(przest,0,0);
    while((znak = getc(przest)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
   fseek(przest,0, 0);
   i=0;
    while(!feof(przest)){
        wsk=malloc(sizeof(opis));
    ile=wiersz[i]-6;
    i++;
    fscanf(przest,"%d ",&wsk->id);
    fscanf(przest,"%s ",wsk->imie);
    fscanf(przest,"%s ",wsk->nazwisko);
    fscanf(przest,"%d ",&wsk->wzrost);
    fscanf(przest,"%d ",&wsk->waga);
    fscanf(przest,"%d",&wsk->wiek);
    for(n=0;n<ile;n++)
        {
        fscanf(przest,"%s",wsk->cechy_sz[n]);
    }
    wsk->cechy_sz[n+1][0]='\0';
    fscanf(przest,"%d ",&wsk->status);
    wsk->next=NULL;
    if(lista==NULL){
        lista=wsk;
        wynikp=lista;
    }
    if(lista!=NULL){
    lista->next =wsk;
    lista=lista->next;
    lista->next=NULL;
    }
}
free(wiersz);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
i=0;
ile_wierszy=0;
linia=0;
while((znak = getc(miej)) != EOF){
      if(znak =='\n'){
        ile_wierszy++;
      }
   }
    wiersz=malloc(sizeof(int)*ile_wierszy);
    fseek(miej,0,0);
    while((znak = getc(miej)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
   fseek(miej,0, 0);
   i=0;

    for(k=0;k<ile_wierszy;k++){
    wskm=malloc(sizeof(przewa));
    ile=wiersz[i]-4;
    i++;
    fscanf(miej,"%d",&wskm->nr);
    fscanf(miej,"%s",wskm->miasto);
    fscanf(miej,"%d",&wskm->dzien);
    fscanf(miej,"%d",&wskm->miesiac);
    fscanf(miej,"%d",&wskm->rok);
    for(n=0;n<ile;n++){
        fscanf(miej,"%d",&wskm->id[n]);
    }
    wskm->id[ile]=0;
    wskm->next=NULL;
    if(listam==NULL){
        listam=wskm;
        wynikm=listam;
    }
    else{
    listam->next=wskm;
    listam=listam->next;
    listam->next=NULL;
    }
}

printf("\t\t\tSORTOWANIE");
printf("\n1: Jezeli chcesz wedlug nazwiska");
printf("\n2: Jezeli chcesz wedlug imienia");
printf("\n3: Jezeli chcesz wedlug wzrostu");
printf("\n4: Jezeli chcesz wedlug waga");
printf("\n5: Jezeli chcesz wedlug wieku");
printf("\n6: Jezeli chcesz wedlug miejsca zbrodni");
printf("\n");
scanf("%d",&wybor);
system("cls");
switch(wybor){
case 1:
    nazwisko(wynikp);
    break;
case 2:
    imie(wynikp);
    break;
case 3:
    wzrost(wynikp);
    break;
case 4:
    waga(wynikp);
    break;
case 5:
    wieki(wynikp);
    break;
case 6:
    miejsca(wynikm);
    break;
default: printf("Zle wprowadzona liczba, sprobuj ponownie pozniej");
}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void sz_przest(opis *headp, przewa *headm){
    char imie[15], nazwisko[20],znak[5];
    int dl,i,licz=0,n,prawda,spr_else=0;
    przewa *listam;
    opis *listap;
    system("cls");
    printf("1. Szukaj wedlug imienia\n2. Szukaj wedlug nazwiska\n");
    scanf("%s",znak);
    printf("\n\n");
    if(znak[0]=='1'){
        printf("Podaj imie (lub jego poczatek): ");
        scanf("%s",imie);
        dl=strlen(imie);
        if(islower(imie[0])) imie[0]-=32;
        for(i=1;i<=dl;i++){
        if(isupper(imie[i])) imie[i]+=32;
        }
        listap=headp;
        system("cls");
        while(listap!=NULL){
            licz=0;
            for(i=0;i<dl;i++){
                if(imie[i]==listap->imie[i]) licz++;
            }
            if(licz==dl){
                spr_else++;
                printf("\n\nID: %d ",listap->id);
                printf("\nImie: %s ",listap->imie);
                printf("\nNazwisko: %s ",listap->nazwisko);
                printf("\nWzrost: %d ",listap->wzrost);
                printf("\nWaga: %d ",listap->waga);
                printf("\nWiek: %d ",listap->wiek);
                for(n=0;listap->cechy_sz[n][0]!='\0';n++)
                    {
                    printf("\nCecha szcegolna %d: %s ",n+1,listap->cechy_sz[n]);
                }
                if(listap->status == 0) printf("\nstatus: Na wolnosci\n\n");
                if(listap->status == 1) printf("\nstatus: Zlapany\n\n");
                listam=headm;
                printf("\nOto miejsca, w ktorych ten przestepca bral udzial: ");

                i=0;
                while(listam!=NULL){
                    for(n=0;listam->id[n]!=0;n++){
                        if(listam->id[n]==listap->id){
                            i++;
                            printf("\n%d: %s",i,listam->miasto);
                        }
                    }
                    listam=listam->next;
                }
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            }
            listap=listap->next;
        }
    }
    else if(znak[0]=='2'){
        printf("Podaj nazwisko (lub jego poczatek): ");
        scanf(" %s",nazwisko);
        dl=strlen(nazwisko);
        if(islower(nazwisko[0])) nazwisko[0]-=32;
        for(i=1;i<=dl;i++){
        if(isupper(nazwisko[i])) nazwisko[i]+=32;
        }
        listap=headp;
        system("cls");
        while(listap!=NULL){
            licz=0;
            for(i=0;i<dl;i++){
                if(nazwisko[i]==listap->nazwisko[i]) licz++;
            }
            if(licz==dl){
                spr_else++;
                printf("\n\nID: %d ",listap->id);
                printf("\nImie: %s ",listap->imie);
                printf("\nNazwisko: %s ",listap->nazwisko);
                printf("\nWzrost: %d ",listap->wzrost);
                printf("\nWaga: %d ",listap->waga);
                printf("\nWiek: %d ",listap->wiek);
                for(n=0;listap->cechy_sz[n][0]!='\0';n++)
                    {
                    printf("\nCecha szcegolna %d: %s ",n+1,listap->cechy_sz[n]);
                }
                if(listap->status == 0) printf("\nstatus: Na wolnosci\n\n\n\n");
                if(listap->status == 1) printf("\nstatus: Zlapany\n\n\n\n");
                listam=headm;
                printf("\nOto miejsca, w ktorych ten przestepca bral udzial: ");
                i=0;
                while(listam!=NULL){
                    for(n=0;listam->id[n]!=0;n++){
                        if(listam->id[n]==listap->id){
                            i++;
                            printf("\n%d: %s",i,listam->miasto);
                        }
                    }
                    listam=listam->next;
                }
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            }
            listap=listap->next;
        }
    }
    else{
        printf("\nBlad wyboru");
        return;
    }
    if(spr_else == 0 ) printf("\nBrak danej osoby w bazie");
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void sz_miej(opis *headp, przewa *headm){
char miasto[40];
int dl,i,licz=0,spr_else=0;
opis *listap;
przewa *listam;
system("cls");
printf("\t\tPodaj nazwe miasta\n");
scanf("\t\t%s",miasto);
dl=strlen(miasto);
if(islower(miasto[0])) miasto[0]-=32;
for(i=1;i<=dl;i++){
    if(isupper(miasto[i])) miasto[i]+=32;
}
listam=headm;
while(listam!=NULL){
    licz=0;
    for(i=0;i<dl;i++){
        if(miasto[i]==listam->miasto[i]) licz++;
    }
if(licz==dl){
    spr_else++;
    printf("\n\nMiasto: %s\nNr_przestepstwa: %d",listam->miasto,listam->nr);
    printf("\nPrzestepcy ktorzy brali udzial w tym przestepstwie:\n");
    for(i=0;listam->id[i]!=0;i++){
        listap=headp;
        while(listap!=NULL){
            if(listap->id==listam->id[i]){
                printf("\nImie: %s\nNazwisko: %s\n",listap->imie,listap->nazwisko);
            }
        listap=listap->next;
        }
    }
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
listam=listam->next;
}
if(spr_else == 0) printf("\nNie ma takiego miasta");
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void wysz_m_p(){
    FILE *miej,*przest;
    int i=0,linia=0,k,*wiersz,ile_wierszy=0,ile,n,wybor;
    char znak;
    opis *wsk,*lista,*wynikp;
    przewa *wskm,*listam,*wynikm;
    listam=NULL;
    lista=NULL;
    wynikp=NULL;
    wynikm=NULL;
    if((miej=fopen("miejsca.txt","r"))== NULL) printf("\nBlad pliku");
    if((przest=fopen("opisy.txt","r"))== NULL) printf("\nBlad pliku");

    while((znak = getc(przest)) != EOF)
   {
      if(znak =='\n'){
        ile_wierszy++;
      }
   }
    wiersz=malloc(sizeof(int)*ile_wierszy);
    fseek(przest,0,0);
    while((znak = getc(przest)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
   fseek(przest,0, 0);
   i=0;
    while(!feof(przest)){
        wsk=malloc(sizeof(opis));
    ile=wiersz[i]-6;
    i++;
    fscanf(przest,"%d ",&wsk->id);
    fscanf(przest,"%s ",wsk->imie);
    fscanf(przest,"%s ",wsk->nazwisko);
    fscanf(przest,"%d ",&wsk->wzrost);
    fscanf(przest,"%d ",&wsk->waga);
    fscanf(przest,"%d",&wsk->wiek);
    for(n=0;n<ile;n++)
        {
        fscanf(przest,"%s",wsk->cechy_sz[n]);
    }
    wsk->cechy_sz[n+1][0]='\0';
    fscanf(przest,"%d ",&wsk->status);
    wsk->next=NULL;
    if(lista==NULL){
        lista=wsk;
        wynikp=lista;
    }
    if(lista!=NULL){
    lista->next =wsk;
    lista=lista->next;
    lista->next=NULL;
    }
}
free(wiersz);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
i=0;
ile_wierszy=0;
linia=0;
while((znak = getc(miej)) != EOF){
      if(znak =='\n'){
        ile_wierszy++;
      }
   }
    wiersz=malloc(sizeof(int)*ile_wierszy);
    fseek(miej,0,0);
    while((znak = getc(miej)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
   fseek(miej,0, 0);
   i=0;

    for(k=0;k<ile_wierszy;k++){
    wskm=malloc(sizeof(przewa));
    ile=wiersz[i]-4;
    i++;
    fscanf(miej,"%d",&wskm->nr);
    fscanf(miej,"%s",wskm->miasto);
    fscanf(miej,"%d",&wskm->dzien);
    fscanf(miej,"%d",&wskm->miesiac);
    fscanf(miej,"%d",&wskm->rok);
    for(n=0;n<ile;n++){
        fscanf(miej,"%d",&wskm->id[n]);
    }
    wskm->id[ile]=0;
    wskm->next=NULL;
    if(listam==NULL){
        listam=wskm;
        wynikm=listam;
    }
    else{
    listam->next=wskm;
    listam=listam->next;
    listam->next=NULL;
    }
}

system("cls");
printf("\t\tWyszukiwanie");
printf("\n\n1: Szukaj przestepcy");
printf("\n2: Szukaj wedlug nazwy miasta\n");
scanf("%d",&wybor);
switch(wybor){
case 1: sz_przest(wynikp,wynikm);
break;
case 2: sz_miej(wynikp,wynikm);
break;
default: printf("Zle podana liczba");
getchar();getchar();
}
free(wiersz);
fclose(miej);
fclose(przest);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void usu_miej(){
char nr[10],znak,proba[10];
int i,dl,suma,licz,ile=0,k,spr=0,ile_w,linia=0,*wiersz,n;
przewa *wskm,*listam,*wynikm;
listam=NULL;
FILE *fil;
system("cls");
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
for(;;){
suma=0;
printf("Podaj nr przestepstwa ");
scanf("%s",nr);
dl=strlen(nr);
for(i=0;i<dl;i++){
    if(isdigit(nr[i])) suma++;
}
if(suma==dl){
    licz=atoi(nr);
    break;
}
else("Zle wprowadzone dane\n\n");
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
if((fil=fopen("miejsca.txt","r"))== NULL) printf("\nBlad pliku");

while((znak=getc(fil))!=EOF){
    if(znak=='\n') ile++;
}
fseek(fil,0,0);

for(i=0;i<ile;i++){
    k=0;
    while((znak=getc(fil))!=' '){
        proba[k]=znak;
        k++;
    }
    proba[k]='\0';
    if(licz==atoi(proba))spr=1;
    while((znak=getc(fil))!='\n');
}
if(spr==0){
    printf("Nie istnieje taki numer przestepstwa");
    return;
}
wiersz=malloc(sizeof(int)*ile);
i=0;
fseek(fil,0,0);
    while((znak = getc(fil)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
i=0;
fseek(fil,0,0);
for(k=0;k<ile;k++){
    wskm=(przewa*)malloc(sizeof(przewa));
    ile_w=wiersz[i]-4;
    i++;
    fscanf(fil,"%d",&wskm->nr);
    fscanf(fil,"%s",wskm->miasto);
    fscanf(fil,"%d",&wskm->dzien);
    fscanf(fil,"%d",&wskm->miesiac);
    fscanf(fil,"%d",&wskm->rok);

    for(n=0;n<ile_w;n++){
        fscanf(fil,"%d",&wskm->id[n]);
    }
    wskm->id[ile_w]=0;
    wskm->next=NULL;

    if(listam==NULL && wskm->nr!=licz){
        listam=wskm;
        wynikm=listam;
    }
    else if(wskm->nr!=licz){
    listam->next=wskm;
    listam=listam->next;
    listam->next=NULL;
    }
}
fclose(fil);
if((fil=fopen("miejsca.txt","w"))== NULL) printf("\nBlad pliku");
while(wynikm!=NULL){
    fprintf(fil,"%d ",wynikm->nr);
    fprintf(fil,"%s ",wynikm->miasto);
    fprintf(fil,"%d %d %d ",wynikm->dzien,wynikm->miesiac,wynikm->rok);

    for(i=0;(wynikm->id[i])!=0;i++){
        if((wynikm->id[i+1])==0) fprintf(fil,"%d\n",wynikm->id[i]);
        else fprintf(fil,"%d ",wynikm->id[i]);
    }
    wynikm=wynikm->next;
}
fclose(fil);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void usu_prz(){
char id[10],znak,proba[10];
int i,dl,suma,licz,ile=0,k,spr=0,ile_w,linia=0,*wiersz,n;
opis *wsk,*lista,*wynikp;
przewa *wskm,*listam,*wynikm;
listam=NULL;
lista=NULL;
wynikm=NULL;
FILE *fil;
system("cls");
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
for(;;){
suma=0;
printf("Podaj id przestepcy ");
scanf("%s",id);
dl=strlen(id);
for(i=0;i<dl;i++){
    if(isdigit(id[i])) suma++;
}
if(suma==dl){
    licz=atoi(id);
    break;
}
else("Zle wprowadzone dane\n\n");
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
if((fil=fopen("opisy.txt","r"))== NULL) printf("\nBlad pliku");

while((znak=getc(fil))!=EOF){
    if(znak=='\n') ile++;
}
fseek(fil,0,0);

for(i=0;i<ile;i++){
    k=0;
    while((znak=getc(fil))!=' '){
        proba[k]=znak;
        k++;
    }
    proba[k]='\0';
    if(licz==atoi(proba))spr=1;
    while((znak=getc(fil))!='\n');
}
if(spr==0){
    printf("Nie istnieje takie id");
    return;
}
wiersz=malloc(sizeof(int)*ile);
i=0;
fseek(fil,0,0);
    while((znak = getc(fil)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
i=0;
fseek(fil,0,0);
for(k=0;k<ile;k++){
   wsk=malloc(sizeof(opis));
    ile_w=wiersz[i]-6;
    i++;
    fscanf(fil,"%d ",&wsk->id);
    fscanf(fil,"%s ",wsk->imie);
    fscanf(fil,"%s ",wsk->nazwisko);
    fscanf(fil,"%d ",&wsk->wzrost);
    fscanf(fil,"%d ",&wsk->waga);
    fscanf(fil,"%d ",&wsk->wiek);
    for(n=0;n<ile_w;n++)
        {
        fscanf(fil,"%s",wsk->cechy_sz[n]);
    }
    wsk->cechy_sz[n+1][0]='\0';
    fscanf(fil,"%d ",&wsk->status);
    wsk->next=NULL;
    if(lista==NULL && wsk->id!=licz){
        lista=wsk;
        wynikp=lista;
    }
    else if(wsk->id!=licz){
    lista->next =wsk;
    lista=lista->next;
    lista->next=NULL;
    }
}
fclose(fil);
if((fil=fopen("opisy.txt","w"))== NULL) printf("\nBlad pliku");
wsk=wynikp;
while(wynikp!=NULL){
    fprintf(fil,"%d ",wynikp->id);
    fprintf(fil,"%s ",wynikp->imie);
    fprintf(fil,"%s ",wynikp->nazwisko);
    fprintf(fil,"%d ",wynikp->wzrost);
    fprintf(fil,"%d ",wynikp->waga);
    fprintf(fil,"%d ",wynikp->wiek);
    for(i=0;wynikp->cechy_sz[i][0]!='\0';i++){
        fprintf(fil,"%s ",wynikp->cechy_sz[i]);
    }
    fprintf(fil,"%d\n",wynikp->status);
    wynikp=wynikp->next;
    }
fclose(fil);
free(wiersz);

if((fil=fopen("miejsca.txt","r"))== NULL) printf("\nBlad pliku");
ile=0;

while((znak=getc(fil))!=EOF){
    if(znak=='\n') ile++;
}

fseek(fil,0,0);
wiersz=malloc(sizeof(int)*ile);
i=0;
    while((znak = getc(fil)) != EOF){
      if(znak == ' ') ++linia;
      if(znak =='\n'){
        wiersz[i]=linia;
        linia=0;
        i++;
      }
   }
i=0;
fseek(fil,0,0);

for(k=0;k<ile;k++){

    if(feof(fil))break;
    wskm=(przewa*)malloc(sizeof(przewa));
    spr=0;
    ile_w=wiersz[i]-4;
    i++;

    fscanf(fil,"%d",&wskm->nr);
    fscanf(fil,"%s",wskm->miasto);
    fscanf(fil,"%d",&wskm->dzien);
    fscanf(fil,"%d",&wskm->miesiac);
    fscanf(fil,"%d",&wskm->rok);
    for(n=0;n<ile_w;n++){
        fscanf(fil,"%d",&wskm->id[n]);
        if(wskm->id[n]==licz) spr=2;
    }
    wskm->id[ile_w]=0;
    wskm->next=NULL;
    if(listam==NULL && spr!=2){
        listam=wskm;
        wynikm=listam;
    }
    else if(spr!=2){
    listam->next=wskm;
    listam=listam->next;
    listam->next=NULL;
    }
}
fclose(fil);
if((fil=fopen("miejsca.txt","w"))== NULL) printf("\nBlad pliku");
while(wynikm!=NULL){
    fprintf(fil,"%d ",wynikm->nr);
    fprintf(fil,"%s ",wynikm->miasto);
    fprintf(fil,"%d %d %d ",wynikm->dzien,wynikm->miesiac,wynikm->rok);

    for(i=0;(wynikm->id[i])!=0;i++){
        if((wynikm->id[i+1])==0) fprintf(fil,"%d\n",wynikm->id[i]);
        else fprintf(fil,"%d ",wynikm->id[i]);
    }
    wynikm=wynikm->next;
}
fclose(fil);
free(wiersz);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int usuwanie(){
    int dl,wybor;
    char odp[3];
    system("cls");
    for(;;){
    printf("\t\tUWAGA\nUsuwania nie mozna cofnac. Jestes pewien ze chcesz usuwac? (T/N) ");
    scanf("%s",odp);
    dl=strlen(odp);
    if(dl==1){
            if(odp[0]=='t' || odp[0]=='T') break;
            else if(odp[0]=='n' || odp[0]=='N') return 0;
            else printf("Zle wprowadzone dane");
        }
    else printf("Zle wprowadzone dane");
    getchar();getchar();
    system("cls");
    }
    system("cls");
    for(;;){
    printf("Wybierz numer by :\n1. Usunac przestepce\n2. Usunac miejsce przestepstwa\n0. Wyjsc do menu\n");
    printf("\n.Pamietaj ze usuwajac przestepce usuwasz tez miejsca zbrodni\nw ktorych on uczestniczyl\n");
    scanf("%d",&wybor);
    switch(wybor){
    case 1: usu_prz();
    return 0;
    break;
    case 2: usu_miej();
    return 0;
    break;
    case 0: return 0;
    break;
    default: printf("Zle wprowadzona liczba. Sprobuj ponownie");
    }
    getchar();getchar();
    system("cls");
    }
}

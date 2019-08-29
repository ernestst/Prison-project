#include "st.h"

int main(){
int wybor,i;
for(;;){
printf("REJESTR SKAZANYCH\nNacisnij numer i ENTER by wybrac jedna z podanych opcji\n");
printf("\n1: Dodawanie przestepcow");
printf("\n2: Dodawanie miejsca");
printf("\n3: Zmiana statusu przestepcy");
printf("\n4: Sortowanie bazy danych");
printf("\n5: Przeszukanie baze wedlug okreslonego przestepcy lub miejsca zbrodni");
printf("\n6: Usuwanie przestepcow lub miejsca zbrodni");
printf("\n0: by wyjsc z programu\n");
scanf("%d", &wybor);
switch(wybor){
case 1: dod_przest();
break;
case 2: dod_miejsca();
break;
case 3: status();
break;
case 4: wysz_przest();
break;
case 5: wysz_m_p();
break;
case 6: usuwanie();
break;
case 0: return 0;
break;
default:printf("Zle wprowadzona liczba, sprobuj ponownie ");
}
getchar();getchar();
system("cls");
}
return 0;
}

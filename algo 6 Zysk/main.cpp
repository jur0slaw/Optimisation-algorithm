#include <iostream>

using namespace std;


struct dzien{
    int wartosc;
    int dzien;
};


struct zysk{
    dzien kupna;
    dzien sprzedazy;
    int zysk;
};

zysk max_zysk(int * tab,int rozmiar,int maxcena){

    zysk temp;

    dzien k,s;

    int cena = tab[0];
    int zysk = 0;

    for(int i = 1 ; i < rozmiar; i++){

            if(tab[i]-cena>zysk){
                zysk = tab[i]-cena;
                s.wartosc = tab[i];
                s.dzien = i;
            }
        if(tab[i]<cena){
                cena = tab[i];
                k.wartosc = cena;
                k.dzien = i;
            }

    }

    temp.kupna=k;
    temp.sprzedazy=s;
    temp.zysk = s.wartosc-k.wartosc;

    return temp;
}




int main()
{
    int c[]= {5,10,4,11,7};
    zysk x = max_zysk(c,5,0);

    cout << "Nalezy zakupic akcje dnia: " << x.kupna.dzien+1 << " o cenie: " << x.kupna.wartosc << " i sprzedac dnia: " << x.sprzedazy.dzien+1 << " o cenie: " << x.sprzedazy.wartosc;



    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;


int licznik=0;
int pliki[4];




void transformuj(int  tab[][2], int * tab2,int rozmiar, int kol){
    for(int i=0;i<rozmiar;i++){
        tab2[i] = tab[i][kol];
    }
}


void algorytm(int tab[5][11],int * miejsce, int * czas, int w, int elem, string pliki[5][11]){

    for(int k = 0;k<elem;k++){
       // tab[k][0] = 0;
       // pliki[k][0]+=33;

    }
    for(int l = 0; l < w ; l++){
        tab[0][l] = 0;
        pliki[0][l]+=33;
    }

    for(int i=1;i<elem;i++){

        for(int j=0;j<w;j++){
            if(miejsce[i-1]>j){
                tab[i][j]=tab[i-1][j];
                pliki[i][j]=pliki[i-1][j];
            }
            else{
                    if(tab[i-1][j]>(tab[i-1][j-miejsce[i-1]]+czas[i-1])){
                        tab[i][j]=tab[i-1][j];
                        pliki[i][j]=pliki[i-1][j];
                    }else{
                        tab[i][j]=tab[i-1][j-miejsce[i-1]]+czas[i-1];
                        pliki[i][j]+=pliki[i-1][j-miejsce[i-1]];
                        pliki[i][j]+=i-1+49 ;
                        pliki[i][j]+="," ;
                    }
                }

        }
    }

}

int main()
{

    int t[4][2] = {{10,5},{5,2},{20,6},{50,3}};

    int koszt[4];
    int miejsce[4];

    transformuj(t,koszt,4,0);
    transformuj(t,miejsce,4,1);



    string pliki[5][11];
    int v[5][11];

    algorytm(v,miejsce,koszt,11,5,pliki);

    for(int i = 0 ; i < 6;i++){
        for(int j = 0 ; j < 12 ; j++){
            if(i==0){
                if(j!=0)
                    cout << j-1 << "  ";
                else
                    cout << "   ";
            }else{
                if(j==0){
                    cout<< i-1 << "  ";
                }else{
                    cout << v[i-1][j-1] << " ";
                    if(v[i-1][j-1]/10<1){
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }

     cout << endl;

     for(int i = 0 ; i < 6;i++){
        for(int j = 0 ; j < 12 ; j++){
            if(i==0){
                if(j!=0)
                    cout << j-1 << " ";
                else
                    cout << "   ";
            }else{
                if(j==0){
                    cout<< i-1 << "  ";
                }else{
                    cout << pliki[i-1][j-1] << " ";
                }
            }
        }
        cout << endl;
    }

     cout << endl;

     cout << pliki[4][0];

    return 0;
}

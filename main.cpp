#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

bool czydopliku = false;
ofstream wynik;

void wypisz(int n, int *a, int *b)
{
        int tmp = 0;
        for (int i = 0; i < n; i++) {

                tmp = b[a[i]-1]; b[a[i]-1] = b[i]; b[i] = tmp;
        }
        for (int i = 0; i < n; i++){
                if(czydopliku) wynik << b[i] << " "; else cout << b[i] << " ";
        }
        //cout << endl;
        for (int i = n-1; i >= 0; i--) {
                tmp = b[a[i]-1]; b[a[i]-1] = b[i]; b[i] = tmp;
        }
        return;
}

int main()
{
        wynik.open("wynik.txt");
        int n = 0;
        cout << "Program wypisuje nieporzadki n-elementowego zbioru." << endl;
        cout << "(Dodatkowo w nawiasach podaje wykonane transpozycje od lewej do prawej)" << endl;
        cout << "Gdzie wypisac wyniki? 1 - na ekran 2 - do pliku" << endl;
        cin >> n;
        if(n==2) czydopliku = true;
        n = 0;
        cout << "Podaj n: ";
        cin >> n;
        cout << "Rozpoczynam wypisywanie nieporzadkow dla zbioru ";
        for(int i=0; i<n; i++){
            cout << i+1 << " ";
        }
        cout << ":" << endl;
        int a[1024];
        int b[1024];
        for (int i = 1; i <= n; i++){
            a[i-1] = i;
            b[i-1] = i;
        }
        int ilosc = 0;
        bool czynieporzadek = false;
        do{
            czynieporzadek = true;
            for (int i = 0; i < n; i++) {
                if(a[i]==i+1){
                    if(i+1==n){
                        czynieporzadek = false;
                        break;
                    }
                    bool czyIstniejeTakieJ = false;
                    for (int j = i+1; j < n; j++) {
                        if(a[j]==i+1){
                            czyIstniejeTakieJ = true;
                            break;
                        }
                    }
                    if(!czyIstniejeTakieJ){
                        czynieporzadek = false;
                        break;
                    }
                }
            }

            if(czynieporzadek){
                ilosc++;
                //cout << ilosc << ". ";
                wypisz(n, a, b);
                if(czydopliku) wynik << " ("; else cout << " (";
                for (int i = 0; i < n-1; i++) if(czydopliku) wynik << a[i] << " "; else cout << a[i] << " ";
                if(czydopliku) wynik << a[n-1] << ")" << endl; else cout << a[n-1] << ")" << endl;
            }
            a[n-1]--;
            for(int i = 1; n-i-1>=0 ; ){
                if( a[n-i] == 0 ){
                    a[n-i-1]--;
                    a[n-i] = n-i+1;
                    i++;
                } else break;
            }
        }while(a[0] == 1);
        if(czydopliku) wynik << "Ilosc nieporzadkow: " << ilosc << endl; else cout << "Ilosc nieporzadkow: " << ilosc << endl;
        if(czydopliku) cout << "Plik wyniki.txt jest juz gotowy!" << endl;
        wynik.close();
        cin >> n;

        return 0;
}

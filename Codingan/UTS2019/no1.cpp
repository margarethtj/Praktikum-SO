#include <iostream>
using namespace std;

void cetaklangkah(int n, int akhir) {
    if (n >= akhir){
        cetaklangkah(n, akhir+1);
        for(int j = n; j >= akhir; j--) {
            cout << j;
            if(j != akhir) {
                cout << " * ";
            }
            else {
                cout << "!";
            }
        }
        cout << endl;
    }
    
}

int hasil;
void faktorial(int n, int akhir){
    if (n >= akhir){
        int pengali;
            for(int i = n; i >= akhir; i--) {
                if (i != akhir){
                    cout << i;
                    cout << " * ";
                }
                else {
                    if (i == 1){
                        hasil = 1;
                    }
                    else {
                        hasil *= i;
                    }
                    cout << hasil << endl;
                }
            }
        faktorial(n, akhir+1);
    }
    
}

int main(){
    // input n
    int n;
    cout << "n = ";
    cin >> n;

    if(n < 0) {
        cout << "Gaboleh Negatif!" << endl;
    }
    else {
        cetaklangkah(n, 1);
        faktorial(n, 1);
    }
}
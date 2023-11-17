#include <iostream>
#include <string>

using namespace std;

int main() {
    // membuat variabel
    int x;
    int y;

    // inputan
    cout << "X : ";
    cin >> x;
    cout << "Y : ";
    cin >> y;

    // membuat array
    int arr[y][x];

    // mengisi array
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    // ngeprint isi array dengan cara biasa
    cout << endl;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

   
    // ngeprint isi array dilakukan oleh pointer saja
    cout << endl;
    int *pointer = arr[0];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cout << *pointer << " ";
            pointer += 1;
        }
        cout << endl;
    }

    // ngeprint semua kolom ganjil, dan semua kolom genap
    cout << endl;

    // kolom ganjil
    cout << "Kolom Ganjil : \n";
    int *pointer2 = arr[0];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (j % 2 == 0) {
            cout << *pointer2 << " ";
            }
            pointer2 += 1;
        }
        cout << endl;
    }

    // kolom genap
    cout << "Kolom Genap : \n";
    int *pointer3 = arr[0];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (j % 2 != 0) {
            cout << *pointer3 << " ";
            }
            pointer3 += 1;
        }
        cout << endl;
    }
    cout << "SAM BABI";
    return 0;
}

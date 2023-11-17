// Format awal harus ada ini
#include <iostream>
#include <string>

using namespace std;

int main() {
    // variabel (mirip java)
    double x;
    string y;
    bool hai;
    string kata;

    // inputan 
    cout << "Insert Number : ";
    cin >> y; 
    getline(cin, y); // inputan int ke string, harus di getline supaya ga eror
    cout << "Insert String : ";
    //cin >> kata; // cin string cuman baca sebelum spasi (jadi cuman satu kata saja)
    getline(cin, kata); // untuk dapatkan satu string semua kalimat (getline harus string)

    // casting double ke integer
    double z = 10.9982;
    int c;
    c = (int) z;
    cout << (c+5) << endl;

    // casting string ke integer
    string a = "190";
    c = stoi(a); // string to integer (stoi)
    cout << (c+10) << endl;

    // if else (konsep ternery)
    bool d = c == 200 ? false : true; // if c = 200, maka keluarin false. kalau bukan 200 ya true.
    cout << d;

    // print
    cout << "Hello world!!" << endl; // endl ini buat bisa enter
    cout << "Babi\n"; // \n juga bisa dipake buat enter
    cout << "Y = " << y << endl;
    cout << "Kata = " << kata << endl;

    // POINTER (penunjuk yang menyimpan suatu alamat, dan memakai alamat itu untuk merujuk ke isi dari alamat itu.)
    // tipe ne pointer dengan tipene data ne harus sama.
    int x = 10;
    int *y = &x; // menyimpan di pointer(*) y yg isinya itu alamat(&) dari x
    int **z = &y; // z menyimpan alamat dari y (z butuh masuk 2x untuk dapet value x, maka **)

    cout << "Isi X : " << x << endl; 
    cout << "Alamat X : " << &x << endl; 
    cout << "Isi dari Y : " << y << endl; // isine alamat dari x
    cout << "Isi dari alamat yang disimpan X : " << *y << endl; // ngambil isi x pakai y(alamate x)
    cout << "Alamat Y : " << &y << endl;
    cout << "Isi Z : " << z << endl;
    cout << "Alamat Z : " << &z << endl;
    cout << "Isi dari isi Z : " << *z << endl; // ngambil isi y pakai z(alamate y)
    cout << "Isi dari isi dari Z : " << **z << endl; // ngambil isi x pakai z(alamate y(alamate x))

    int a = 10;
    int *b = &a; // b isinya alamat dari a
    int *c = b; // c ambil isi b, c isinya alamat dari a(yg diambil dari b(alamate a))
    int **d = &c; // isi d adalah alamat dari c
    *c = 190; // a nya diganti nilainya menjadi 190
    // c simpen alamat dari a, berarti *c itu masuk ke a, jadi disini yg diubah adalah a nya

    cout << **d << endl; // hasilnya 190
    cout << *b << endl; // hasilnya 190
    cout << a; // hasilnya 190

    
    **d = 50; // a nya diganti nilainya menjadi 50
    // d simpen alamate c(alamate a(nyimpen value 10 yg diganti jadi 50)).

    cout << **d << endl; // hasilnya 50
    cout << *c << endl; // hasilnya 50
    cout << a; // hasilnya 50


    int *b = &a; // disini b* merupakan deklarasi aja, dia akan menyimpan alamate a
    b* = 100; // disini b* = a, dia akan ambil value dari a (dia masuk sebanyak jumlah bintang e).


    // POINTER ARRAY 
    int arr[5] = {10,17,22,1,9};

    cout << arr; // arr adalah alamat objek pertama dari arraynya (alamatnya 10).
    cout << *arr; // output 10, yg merupakan value dari alamat objek pertama.
    cout << arr+1; // arr+1 adalah alamat objek kedua dari arraynya (alamatnya 17).


    int arr[5] = {10,17,22,1,9};
    int *pointer = arr;
    
    pointer += 3;
    cout << *pointer; // output 1, karena arr(10), arr+1(17), jadi kalau arr+3 ya jadwaban e 1
    
    pointer += 5;
    cout << *pointer; // outputnya ya gajelas bisa 35724 atau berapa gitu pokokenya itu artinya tembus dari array yg kita pny.


    // pointer disimpan ke dalam array
    // array 1d
    int x = 10;
    int y = 100;
    int *arr[2] = {&x, &y};
    int **pointer = arr+1;
    cout << **pointer = arr+1; // outputnya 100 yaitu item kedua dari array.

    // array 2d
    int x = 10;
    int y = 100;
    int arr[2][2] = {{x, y}, {y, x}};
    int *pointer = arr[0];
    cout << *pointer; // outputnya 10, ambil dari x yang merupakan item pertama di array

    pointer += 2;
    cout << *pointer; // outputnya 100, ambil dari y yang merupakan item ketiga di array

    int *pointer = &arr[0][0];
    cout << *pointer; // outputnya 10, ambil dari index 0,0


    // RANDOM
    rand()%10; // berarti keluarnya pasti antara 0-9

    return 0;
}
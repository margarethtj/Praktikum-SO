#include <iostream>

using namespace std;

// membuat function
void print(string name) {
    cout << "Nama saya " << name;
}

class person{
    int salaries; // dee private (defaultnya private)

    public: // semua yang dibawah public, akan menjadi public
    string name;
    int age;
    int salary;
    person(){
        this->name="AAA";
        this->age=10;
        this->salary=100;
    }
    // constructor
    person(string name, int age) {
        this -> name = name;
        this -> age = age;
    }
    person(person &pers) { // reference : nyimpen alamat e
        this -> name = pers.name; // this itu dikasik panah soal e dee nuju ke alamat pointer name itu.
        this -> age = pers.age;
    } 

    // getter setter
    void setSalary(int salaries) {
        this -> salaries = salaries;
    }
    int getSalary() {
        return this -> salaries;
    }

    // print function
    void print() {
        cout << "Nama saya : " << this -> name << endl;
        cout << "Umur saya : " << this -> age << endl;
    }
    
    // membuat method kosongan
    void printkedua();
};

class person2 {
    public :
    string status;

    person2() {
        this->status = "Jomblo";
    }

    person2(string status) {
        this->status = status;
    }
};

// mengisi method yang belom diisi
void person :: printkedua() {
    cout << "tsting";
}

// inheritance
class people : public person, public person2{ // ini dia people extends person dan person2 (dee pny 2 parent)
    public :
    string phone;

    // constructor
    people(string name, int age, int salary, string phone, string status) {
        this -> name = name;
        this -> age = age;
        this -> salary = salary;
        this -> phone = phone;
        this -> status = status;
    }

    void print() {
        person :: print();
        cout << "Gaji saya : " << this -> salary << endl;
        cout << "No telp syaa : " << this -> phone << endl;
    }
};



int main() {
    print("Babi");
    person maxi("Maxi", 13);
    // maxi.name = "Maxi babi";
    // maxi.age = 19;

    person leo(maxi);

    cout << endl << maxi.name << " " << maxi.age << endl; 
    cout << endl << leo.name << " " << leo.age << endl;

    // cara print data maxi menggunakan function print
    maxi.print();
    maxi.printkedua();
    
    // get set salary
    maxi.setSalary(1000);
    cout << maxi.getSalary() << endl;

    // structure ini mirip dengan class, dee secara default public. tempatnya ada di dalam main.
    struct { // struct itu adalah array yang ada method dan tipe datanya banyak
        int coba;
        int hello;
        void print() {
            cout << this -> coba << endl;
        }
        
        private : // kalo di struct, taruk private di bawah, setelah public
            int secret;
    } val, leo2, sam, amel; // deklarasi object, jadi maksute val leo sam amel smuane punya variabel dan function di dalem e struct

    int x,y,z;
    val.coba = 10;
    // val.secret = 15; // butuh getter setter buat akses private ini
    cout << val.coba << endl;
    val.print();

    return 0;
}
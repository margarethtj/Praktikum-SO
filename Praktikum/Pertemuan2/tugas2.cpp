#include <iostream>

using namespace std;

// mendeklarasi kelas kosongan
class gudang;
class admin;
class boss;
class employee;

// class pekerja
class pekerja {
    // variabel
    string password;
    int salary;

    public:
    string email;
    string nama;
    int umur;

    // constructor
    pekerja() {
        this -> setPassword("");
        this -> setSalary(0);
        this -> email = "";
        this -> nama = "";
        this -> umur = 0;
    }
    pekerja(string password, int salary, string email, string nama, int umur) {
        this -> setPassword(password);
        this -> setSalary(salary);
        this -> email = email;
        this -> nama = nama;
        this -> umur = umur;
    }
    pekerja(pekerja &pek) {
        this -> setPassword(pek.getPassword());
        this -> setSalary(pek.getSalary());
        this -> email = pek.email;
        this -> nama = pek.nama;
        this -> umur = pek.umur;
    }

    // getter setter
    void setPassword(string password) {
        this -> password = password;
    }
    string getPassword() {
        return this -> password;
    }
    void setSalary(int salary) {
        this -> salary = salary;
    }
    int getSalary() {
        return this -> salary;
    }
};

// CLASS BOSS
class boss : public pekerja {
    string barang;

    public:
    // constructor
    boss() {
        this -> setPassword("");
        this -> setSalary(0);
        this -> email = "";
        this -> nama = "";
        this -> umur = 0;
        this -> barang = "siuuu";
    }
    boss(string password, int salary, string email, string nama, int umur, string ) {
        this -> setPassword(password);
        this -> setSalary(salary);
        this -> email = email;
        this -> nama = nama;
        this -> umur = umur;
        this -> barang = barang;
    }
    boss(boss &bos) {
        this -> setPassword(bos.getPassword());
        this -> setSalary(bos.getSalary());
        this -> email = bos.email;
        this -> nama = bos.nama;
        this -> umur = bos.umur;
        this -> barang = bos.barang;
    }

    // getter setter
    void setPassword(string password) {
        pekerja :: setPassword(password);
    }
    string getPassword() {
        return pekerja :: getPassword();
    }
    void setSalary(int salary) {
        pekerja :: setSalary(salary);
    }
    int getSalary() {
        return pekerja :: getSalary();
    }
    void setBarang(string barang) {
        this -> barang = barang;
    }
    string getBarang() {
        return this -> barang;
    }

    // function kosng memutarkan kembali kata
    string balikKataKembali(employee &e, gudang &g, admin &m, boss &b);

    // function kosong pengecekan dan mengoutputkan data employee
    void output(employee &e, gudang &g, admin &m, boss &b);

    // function kosong pengecekan dan menghitung total gaji
    void totalGaji(employee &e, employee &l, gudang &g, admin &m, boss &b);
};

// CLASS EMPLOYEE
class employee : public pekerja {
    public:
    // constructor
    employee() {
        this -> setPassword("");
        this -> setSalary(0);
        this -> email = "";
        this -> nama = "";
        this -> umur = 0;
    }
    employee(string password, int salary, string email, string nama, int umur) {
        this -> setPassword(password);
        this -> setSalary(salary);
        this -> email = email;
        this -> nama = nama;
        this -> umur = umur;
    }
    employee(employee &emp) {
        this -> setPassword(emp.getPassword());
        this -> setSalary(emp.getSalary());
        this -> email = emp.email;
        this -> nama = emp.nama;
        this -> umur = emp.umur;
    }

    // getter setter
    void setPassword(string password) {
        pekerja :: setPassword(password);
    }
    string getPassword() {
        return pekerja :: getPassword();
    }
    void setSalary(int salary) {
        pekerja :: setSalary(salary);
    }
    int getSalary() {
        return pekerja :: getSalary();
    }

    // function kosong get barang
    string getBarang(gudang &g, admin &m, boss &b);
};

// CLASS ADMIN
class admin : public pekerja {
    public:
    // constructor
    admin() {
        this -> setPassword("");
        this -> setSalary(0);
        this -> email = "";
        this -> nama = "";
        this -> umur = 0;
    }
    admin(string password, int salary, string email, string nama, int umur) {
        this -> setPassword(password);
        this -> setSalary(salary);
        this -> email = email;
        this -> nama = nama;
        this -> umur = umur;
    }
    admin(admin &adm) {
        this -> setPassword(adm.getPassword());
        this -> setSalary(adm.getSalary());
        this -> email = adm.email;
        this -> nama = adm.nama;
        this -> umur = adm.umur;
    }

    // getter setter
    void setPassword(string password) {
        pekerja :: setPassword(password);
    }
    string getPassword() {
        return pekerja :: getPassword();
    }
    void setSalary(int salary) {
        pekerja :: setSalary(salary);
    }
    int getSalary() {
        return pekerja :: getSalary();
    } 

    // function kosong membalikkan kata
    string balikKata(boss &b);
};

// CLASS GUDANG
class gudang : public pekerja {
    public:
    // constructor
    gudang() {
        this -> setPassword("");
        this -> setSalary(0);
        this -> email = "";
        this -> nama = "";
        this -> umur = 0;
    }
    gudang(string password, int salary, string email, string nama, int umur) {
        this -> setPassword(password);
        this -> setSalary(salary);
        this -> email = email;
        this -> nama = nama;
        this -> umur = umur;
    }
    gudang(gudang &gud) {
        this -> setPassword(gud.getPassword());
        this -> setSalary(gud.getSalary());
        this -> email = gud.email;
        this -> nama = gud.nama;
        this -> umur = gud.umur;
    }

    // getter setter
    void setPassword(string password) {
        pekerja :: setPassword(password);
    }
    string getPassword() {
        return pekerja :: getPassword();
    }
    void setSalary(int salary) {
        pekerja :: setSalary(salary);
    }
    int getSalary() {
        return pekerja :: getSalary();
    }

    // function kosong merandom employee
    employee random(employee arr[]);

    // function kosong get barang dari admin
    string getBarang(admin &m, boss &b);
};

// mengisi function kosong di class admin untuk membalik kata
string admin :: balikKata(boss &b) {
    string barang = b.getBarang();
    string hasil = "";
    for(int i = barang.length()-1; i >= 0; i--) {
        hasil = hasil + barang[i];
    }
    return hasil;
}

// mengisi function kosong di class gudang untuk mengambil barang dari admin
string gudang :: getBarang(admin &m, boss &b) {
    return m.balikKata(b);
}

// mengisi function kosong di class gudang untuk merandom employee
employee gudang :: random(employee arr[]){
    int index= rand() %3;
    return arr[index];
}

// mengisi function kosong di class employee untuk mengambil barang dari gudang
string employee :: getBarang(gudang &g, admin &m, boss &b) {
    return g.getBarang(m, b);
}

// mengisi function kosong di class boss untuk membalikkan kata 
string boss :: balikKataKembali(employee &e, gudang &g, admin &m, boss &b) {
    string barang = e.getBarang(g, m, b);
    string hasil = "";
    for(int i = barang.length()-1; i >= 0; i--) {
        hasil = hasil + barang[i];
    }
    return hasil;
}

// mengisi function kosong di class boss untuk mengonfirmasi kata dan mengoutputkan data employee
void boss :: output(employee &e, gudang &g, admin &m, boss &b) {
    if (getBarang() == balikKataKembali(e, g, m, b)) {
        cout << "Email : " << e.email << endl;
        cout << "Nama : " << e.nama << endl;
        cout << "Umur : " << e.umur << endl;
        cout << "Salary : " << e.getSalary() << endl;
        cout << "Password : " << e.getPassword() << endl;
        cout << endl;
    }
    else {
        cout << "Pegawai tidak ditemukan!" << endl;
    }
}

// mengisi function kosong di class boss untuk mengonfirmasi kata dan mengoutputkan total gaji
void boss :: totalGaji(employee &e, employee &l, gudang &g, admin &m, boss &b) {
    if (getBarang() == balikKataKembali(e, g, m, b)) {
        // melakukan penghitungan gaji
        int total = e.getSalary() + l.getSalary();
        cout << "Total Gaji : " << total << endl;
    }
    else {
        cout << "Perhitungan gaji tidak ditemukan!" << endl;
    }
}

// MAIN
int main() {
    // Structure Perusahaan
    struct perusahaan {
        boss maxi = *new boss("passmaxi", 14, "bossmaxi@gmail.com", "Maxi", 19, "barangnya");
        employee sam = *new employee("passsam", 10, "empsam@gmail.com", "Sam", 21);
        employee leo = *new employee("passleo", 15, "empleo@gmail.com", "Leo", 22);
        employee hans = *new employee("passhans", 20, "emphans@gmail.com", "Hans", 25);
        employee listOFemployee[3] = {
            sam,
            leo,
            hans
        };
        gudang willy = *new gudang("passwilly", 40, "gudwilly@gmail.com", "Willy", 30);
        gudang vincent = *new gudang("passvincent", 50, "gudvincent@gmail.com", "Vincent", 20); 
        admin margareth = *new admin("passmargareth", 100, "admargareth@gmail.com", "Margareth", 19);
    };
    perusahaan p;

    // Boss Maxi ngirim nama barang ke Admin Margareth
    string balikBarang = p.margareth.balikKata(p.maxi);

    // Gudang mengambil hasil pembalikan yang telah dilakukan oleh Admin
    string barangW = p.willy.getBarang(p.margareth, p.maxi);
    string barangV = p.vincent.getBarang(p.margareth, p.maxi);

    // Gudang merandom employee
    employee emp1 = p.willy.random(p.listOFemployee);
    employee emp2 = p.vincent.random(p.listOFemployee);

    // Gudang ngirim ke Employee randoman
    string barangEmp1 = emp1.getBarang(p.willy, p.margareth, p.maxi);
    string barangEmp2 = emp2.getBarang(p.vincent, p.margareth, p.maxi);

    // Boss mengoutputkan data dari employee yang randoman
    p.maxi.output(emp1, p.willy, p.margareth, p.maxi);
    p.maxi.output(emp2, p.vincent, p.margareth, p.maxi);
    
    // Boss mengoutputkan hasil total gaji kedua employee
    p.maxi.totalGaji(emp1, emp2, p.willy, p.margareth, p.maxi);

    return 0;
}
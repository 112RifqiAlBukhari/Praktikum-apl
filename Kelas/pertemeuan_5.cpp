#include<iostream>
using namespace std;

int main() {
    // * untuk mengambil value 
    // & untuk mengambil alamat
// int a = 10;
// int *b = &a;
// cout << "alamat dari a adalah " << &a << endl;

// cout << a;

// pas by value
# include <iostream>
using namespace std;
struct Address{
string kota;
string provinsi;
string negara;
};
 

// deklarasi variabel dengan struct
Address address1, address2;
// mengisi value address1
address1.kota = "Samarinda";
address1.provinsi = "Kalimantan Timur";
address1.negara = "Indonesia";
// mengcopy value address1 ke address2
address2 = address1;
// mengganti property kota dari samarinda ke ikn
address2.kota = "ikn";
// value address1
cout<< address1.kota<<endl;
// value address2
cout<< address2.kota;



return 0;

}
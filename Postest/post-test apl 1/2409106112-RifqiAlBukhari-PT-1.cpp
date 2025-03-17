#include <iostream>
using namespace std;

int main() {
    string username_user = "rifqi al bukhari";
    string password_user = "2409106112"; 
    string username, password;
    int sandi, memilih, digit, asli, membalik, faktor,pilih_1;
    while(true){
            cout << "================ SELAMAT DATANG GANTENG ====================" << endl;
            cout << "[1] login " << endl;
            cout << "[2] exit " << endl;
            cout << "pilih : " ;
            cin >> pilih_1;

            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "inputan salah" << endl;
            }
            if(pilih_1 == 1){ 
                cout << endl;
                cout << "Masukkan username : ";
                cin.ignore();
                getline(cin, username);
                cout << "Masukkan password : ";
                cin >> password;
                cout << " " << endl;
            
            
            
            
            if (username == username_user && password == password_user){
                cout << "Masukkan sandi yang ingin diverifikasi : ";
                cin >> sandi;
                cout << " " << endl;
            
            if (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "inputan salah" << endl;
                }

            else if (sandi < 100) {
                cout << "Nilai yang diinputkan tidak boleh kurang dari 100 " << endl;
                cout << "silahkan login ulang " << endl;
            } else if (sandi > 99999) {
                cout << "Inputan tidak boleh lebih dari 99999" << endl;
                cout << "silahkan login ulang " << endl;
            } else if (sandi > 100){
                cout << "Berhasil! Silakan pilih menu." << endl;
                
                while (true) {
                    cout << " " << endl;
                    cout << "================= MENU ================ " << endl;
                    cout << "[1] Cek verifikasi sandi adalah bilangan prima" << endl;
                    cout << "[2] Cek verifikasi kode sandi habis dibagi 2 dan 3 tetapi tidak dengan 5" << endl;
                    cout << "[3] Cek verifikasi sandi bilangan palindrome" << endl;
                    cout << "[4] Cek verifikasi sandi bilangan komposit" << endl;
                    cout << "[5] EXIT" << endl;
                    cout << "Pilih : ";
                    cin >> memilih;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "inputan salah" << endl;
                    }
                    
                    if(memilih == 5){
                        cout << "kembali ke beranda " << endl;
                    break;
                    }
                    
                    switch (memilih) {
                        case 1:{ 
                            if(sandi % 2 == 1){
                                cout << "INI ADALAH BILANGAN PRIMA" << endl;
                            } else if (sandi % 2 == 0) {
                                cout << "Bukan bilangan prima" << endl;
                                        break;
                                    }
                                    break;
                                }
                        
                        case 2:{
                            if (sandi % 2 == 0 && sandi % 3 == 0 && sandi % 5 != 0) {
                                cout << "BENAR, sandi habis dibagi 2 dan 3 tetapi tidak dengan 5" << endl;
                            } else {
                                cout << "SALAH" << endl;
                                break;
                                }
                                break;
                            }

                        case 3:{
                            membalik = 0;
                            asli = sandi;
                            while (asli > 0) {
                                digit = asli % 10;
                                membalik = membalik * 10 + digit;
                                asli /= 10;
                            }
                            if (sandi == membalik) {
                                cout << "Ini adalah bilangan palindrome" << endl;
                            } else {
                                cout << "Bukan bilangan palindrome" << endl;
                            }
                            break;
                        }
                        
                        case 4:{
                            faktor = 0;
                            for (int i = 1; i <= sandi; i++) {
                                if (sandi % i == 0) {
                                    faktor++;
                                }
                            }
                            if (faktor > 2) {
                                cout << "Ini adalah bilangan komposit" << endl;
                            } else {
                                cout << "Bukan bilangan komposit (berarti bilangan prima)" << endl;
                            }
                            break;
                        }

                        
                        default:
                            cout << "Inputan salah, silakan pilih menu yang tersedia." << endl;
                            break;
                        }
                    }
                    }
                }else{
                    cout << "!username atau password salah!" << endl;
                    cout << "silahkan login ulang " << endl;
                }
        }else{cout << "Inputan salah, silakan pilih menu yang tersedia." << endl;}
        
    if(pilih_1 == 2){
            cout << "terimakasih sudah menggunakan program saya! " << endl;
            cout << "PROGRAM BERHENTI" << endl;
            break;
        }
    }
    return 0;
}

        




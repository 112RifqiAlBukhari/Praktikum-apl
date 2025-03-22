// #include <iostream>
// using namespace std;

// // cara 1 buat struct
// // struct mahasiswa
// // {
// //     /* data */
// //     string nama;
// //     int nim;
// // };
// // // cara ke 2
// // typedef struct
// // {
// //     /* data */
// //     string nama;
// //     int nim;
// // }mahasiswa;



// int main(){
    
//     struct  Nilai
//     {
//         int uts;
//         int uas;
//     };

//     struct Data
//     {
//         string nama;
//         long long  nim; // long long untuk angka yang di inputkan tidak mines atau supaya lebih panjang angka yang bisa di
//     };
    
    
//     struct Mahasiswa
//     {
//         Data data;
//         Nilai nilai;
//     };
    
//     // ada array nya
//     Mahasiswa mahasiswa [10];

//     for (int i=0; i < 10; i++) {
//         cout << "nama : "; cin >> mahasiswa[i].data.nama;
//     }

//     for (int i=0; i < 10; i++) {
//         cout << mahasiswa[i].data.nama;
//     }



//     // mahasiswa[0].data.nama = "pace";
//     // mahasiswa[1].data.nim = 2409106112;

//     // cout << mahasiswa[0].data.nama << endl;
//     // cout << mahasiswa[1].data.nim  << endl;






//     // Mahasiswa mahasiswa;
//     // mahasiswa.data.nama = "rifqi";
//     // cout << mahasiswa.data.nama << endl;
//     // mahasiswa.nilai.uts=80; 
//     // cout << mahasiswa.nilai.uts << endl;



//     // struct inisialisasi
//     // Mahasiswa mahasiswa;

//     // // menambahkan data di struct
//     // mahasiswa.nama = "rifqi";
//     // mahasiswa.nim = 112;

//     // // menampilkan elemen di dalam struct
//     // cout << mahasiswa.nama << endl;
//     // cout << mahasiswa.nim << endl;
    


//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

// Struct untuk menu
struct MenuItem {
    string nama;
};

// Struct untuk pengguna (bisa admin ataupun user)
struct User {
    string username;
    string password;
};

int main(){
    // Data admin (tidak bisa diubah, hanya untuk login admin)
    const int adminCount = 2;
    User admin[adminCount] = { {"rifqi al bukhari", "2409106112"},
                               {"rifqi", "112"} };

    // Array untuk menyimpan data user yang mendaftar (maksimal 10 user)
    User users[10];
    int userCount = 0;

    // Array menu dalam bentuk struct, masing-masing kapasitas 10
    const int menuCapacity = 10;
    MenuItem menuPS[menuCapacity];
    MenuItem menuMakanan[menuCapacity];
    MenuItem menuMinuman[menuCapacity];
    int panjangPS = 0, panjangMakanan = 0, panjangMinuman = 0;

    // Array pesanan dari user
    MenuItem pesananPS[menuCapacity];
    MenuItem pesananMakanan[menuCapacity];
    MenuItem pesananMinuman[menuCapacity];
    int pesanPS = 0, pesanMakanan = 0, pesanMinuman = 0;

    int pilih_1, pilih_2, pilih_3, pilih_4, pilih_5, pilih_6, pilih_7;
    int index;
    int mencoba = 3;
    bool login_sukses = false;
    string username, password;

    while(true){
        // Menu Utama
        cout << "=================== SELAMAT DATANG =================" << endl;
        cout << "| [1] ADMIN "  << endl;
        cout << "| [2] USER "   << endl;
        cout << "| [3] EXIT "   << endl;
        cout << "=====================================================" << endl;
        cout << "Silahkan pilih : ";
        cin >> pilih_1;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Inputan salah" << endl;
            continue;
        }
        cout << endl;
        
        if(pilih_1 == 1){
            // Bagian login admin
            while(mencoba > 0 && !login_sukses){
                cout << "================= SILAHKAN LOGIN ADMIN ==================" << endl;
                cout << "Masukkan username : ";
                cin >> ws; // membersihkan buffer spasi
                getline(cin, username);
                cout << "Masukkan password : ";
                cin >> password;
                
                // Cek kecocokan login admin
                for(int i = 0; i < adminCount; i++){
                    if(username == admin[i].username && password == admin[i].password){
                        login_sukses = true;
                        break;
                    }
                }
                
                if(login_sukses){
                    cout << "\nLogin sukses\n" << endl;
                    // Menu admin
                    while(true){
                        cout << "============ HALO ADMIN GANTENG ===========\n";
                        cout << "| [1] Lihat MENU\n";
                        cout << "| [2] Tambah MENU\n";
                        cout << "| [3] Edit MENU\n";
                        cout << "| [4] Hapus MENU\n";
                        cout << "| [5] Kembali ke Beranda\n";
                        cout << "===========================================\n";
                        cout << "Silahkan pilih : ";
                        cin >> pilih_2;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Inputan salah\n" << endl;
                            continue;
                        }
                        
                        switch(pilih_2){
                            case 1:{
                                // Lihat Menu
                                while(true){
                                    cout << "\n========== LIHAT MENU ==========" << endl;
                                    cout << "| [1] MENU PS" << endl;
                                    cout << "| [2] MENU MAKANAN" << endl;
                                    cout << "| [3] MENU MINUMAN" << endl;
                                    cout << "| [4] Kembali" << endl;
                                    cout << "================================" << endl;
                                    cout << "Silahkan pilih : ";
                                    cin >> pilih_4;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "Inputan salah" << endl;
                                        continue;
                                    }
                                    switch(pilih_4){
                                        case 1:
                                            if(panjangPS == 0){
                                                cout << "Belum ada menu PS.\n" << endl;
                                            } else {
                                                cout << "\n----- Daftar Menu PS -----" << endl;
                                                for(int i = 0; i < panjangPS; i++){
                                                    cout << i+1 << ". " << menuPS[i].nama << endl;
                                                }
                                                cout << "--------------------------\n" << endl;
                                            }
                                            break;
                                        case 2:
                                            if(panjangMakanan == 0){
                                                cout << "Belum ada menu Makanan.\n" << endl;
                                            } else {
                                                cout << "\n----- Daftar Menu Makanan -----" << endl;
                                                for(int i = 0; i < panjangMakanan; i++){
                                                    cout << i+1 << ". " << menuMakanan[i].nama << endl;
                                                }
                                                cout << "-------------------------------\n" << endl;
                                            }
                                            break;
                                        case 3:
                                            if(panjangMinuman == 0){
                                                cout << "Belum ada menu Minuman.\n" << endl;
                                            } else {
                                                cout << "\n----- Daftar Menu Minuman -----" << endl;
                                                for(int i = 0; i < panjangMinuman; i++){
                                                    cout << i+1 << ". " << menuMinuman[i].nama << endl;
                                                }
                                                cout << "-------------------------------\n" << endl;
                                            }
                                            break;
                                        case 4:
                                            goto keluar_menu_admin;
                                        default:
                                            cout << "Inputan salah" << endl;
                                            break;
                                    }
                                }
                                keluar_menu_admin:
                                break;
                            }
                            case 2:{
                                // Tambah Menu
                                while(true){
                                    cout << "\n========== TAMBAH MENU ==========" << endl;
                                    cout << "| [1] MENU PS" << endl;
                                    cout << "| [2] MENU MAKANAN" << endl;
                                    cout << "| [3] MENU MINUMAN" << endl;
                                    cout << "| [4] Kembali" << endl;
                                    cout << "=================================" << endl;
                                    cout << "Silahkan pilih : ";
                                    cin >> pilih_5;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "Inputan salah" << endl;
                                        continue;
                                    }
                                    switch(pilih_5){
                                        case 1:
                                            if(panjangPS < menuCapacity){
                                                cout << "Masukkan nama menu PS: ";
                                                cin.ignore();
                                                getline(cin, menuPS[panjangPS].nama);
                                                panjangPS++;
                                                cout << "Menu PS berhasil ditambahkan.\n" << endl;
                                            } else {
                                                cout << "Kapasitas penuh.\n" << endl;
                                            }
                                            break;
                                        case 2:
                                            if(panjangMakanan < menuCapacity){
                                                cout << "Masukkan nama menu Makanan: ";
                                                cin.ignore();
                                                getline(cin, menuMakanan[panjangMakanan].nama);
                                                panjangMakanan++;
                                                cout << "Menu Makanan berhasil ditambahkan.\n" << endl;
                                            } else {
                                                cout << "Kapasitas penuh.\n" << endl;
                                            }
                                            break;
                                        case 3:
                                            if(panjangMinuman < menuCapacity){
                                                cout << "Masukkan nama menu Minuman: ";
                                                cin.ignore();
                                                getline(cin, menuMinuman[panjangMinuman].nama);
                                                panjangMinuman++;
                                                cout << "Menu Minuman berhasil ditambahkan.\n" << endl;
                                            } else {
                                                cout << "Kapasitas penuh.\n" << endl;
                                            }
                                            break;
                                        case 4:
                                            goto keluar_menu_admin;
                                        default:
                                            cout << "Inputan salah" << endl;
                                            break;
                                    }
                                }
                                break;
                            }
                            case 3:{
                                // Edit Menu
                                while(true){
                                    cout << "\n========== EDIT MENU ==========" << endl;
                                    cout << "| [1] MENU PS" << endl;
                                    cout << "| [2] MENU MAKANAN" << endl;
                                    cout << "| [3] MENU MINUMAN" << endl;
                                    cout << "| [4] Kembali" << endl;
                                    cout << "================================" << endl;
                                    cout << "Silahkan pilih : ";
                                    cin >> pilih_6;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "Inputan salah" << endl;
                                        continue;
                                    }
                                    switch(pilih_6){
                                        case 1:
                                            if(panjangPS == 0){
                                                cout << "Tidak ada menu PS untuk diedit.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangPS; i++){
                                                    cout << i+1 << ". " << menuPS[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan diubah: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangPS){
                                                    cout << "Masukkan nama menu baru: ";
                                                    cin.ignore();
                                                    getline(cin, menuPS[index-1].nama);
                                                    cout << "Menu berhasil diubah.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 2:
                                            if(panjangMakanan == 0){
                                                cout << "Tidak ada menu Makanan untuk diedit.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangMakanan; i++){
                                                    cout << i+1 << ". " << menuMakanan[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan diubah: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangMakanan){
                                                    cout << "Masukkan nama menu baru: ";
                                                    cin.ignore();
                                                    getline(cin, menuMakanan[index-1].nama);
                                                    cout << "Menu berhasil diubah.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 3:
                                            if(panjangMinuman == 0){
                                                cout << "Tidak ada menu Minuman untuk diedit.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangMinuman; i++){
                                                    cout << i+1 << ". " << menuMinuman[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan diubah: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangMinuman){
                                                    cout << "Masukkan nama menu baru: ";
                                                    cin.ignore();
                                                    getline(cin, menuMinuman[index-1].nama);
                                                    cout << "Menu berhasil diubah.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 4:
                                            goto keluar_menu_admin;
                                        default:
                                            cout << "Inputan salah.\n" << endl;
                                            break;
                                    }
                                }
                                break;
                            }
                            case 4:{
                                // Hapus Menu
                                while(true){
                                    cout << "\n========== HAPUS MENU ==========" << endl;
                                    cout << "| [1] MENU PS" << endl;
                                    cout << "| [2] MENU MAKANAN" << endl;
                                    cout << "| [3] MENU MINUMAN" << endl;
                                    cout << "| [4] Kembali" << endl;
                                    cout << "================================" << endl;
                                    cout << "Silahkan pilih : ";
                                    cin >> pilih_7;
                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "Inputan salah" << endl;
                                        continue;
                                    }
                                    switch(pilih_7){
                                        case 1:
                                            if(panjangPS == 0){
                                                cout << "Tidak ada menu PS untuk dihapus.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangPS; i++){
                                                    cout << i+1 << ". " << menuPS[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan dihapus: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangPS){
                                                    for(int i = index - 1; i < panjangPS - 1; i++){
                                                        menuPS[i] = menuPS[i+1];
                                                    }
                                                    panjangPS--;
                                                    cout << "Menu berhasil dihapus.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 2:
                                            if(panjangMakanan == 0){
                                                cout << "Tidak ada menu Makanan untuk dihapus.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangMakanan; i++){
                                                    cout << i+1 << ". " << menuMakanan[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan dihapus: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangMakanan){
                                                    for(int i = index - 1; i < panjangMakanan - 1; i++){
                                                        menuMakanan[i] = menuMakanan[i+1];
                                                    }
                                                    panjangMakanan--;
                                                    cout << "Menu berhasil dihapus.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 3:
                                            if(panjangMinuman == 0){
                                                cout << "Tidak ada menu Minuman untuk dihapus.\n" << endl;
                                            } else {
                                                for(int i = 0; i < panjangMinuman; i++){
                                                    cout << i+1 << ". " << menuMinuman[i].nama << endl;
                                                }
                                                cout << "Masukkan nomor menu yang akan dihapus: ";
                                                cin >> index;
                                                if(index > 0 && index <= panjangMinuman){
                                                    for(int i = index - 1; i < panjangMinuman - 1; i++){
                                                        menuMinuman[i] = menuMinuman[i+1];
                                                    }
                                                    panjangMinuman--;
                                                    cout << "Menu berhasil dihapus.\n" << endl;
                                                } else {
                                                    cout << "Inputan tidak valid.\n" << endl;
                                                }
                                            }
                                            break;
                                        case 4:
                                            goto keluar_menu_admin;
                                        default:
                                            cout << "Inputan salah.\n" << endl;
                                            break;
                                    }
                                }
                                break;
                            }
                            case 5:{
                                cout << "\nKembali ke Beranda...\n" << endl;
                                login_sukses = false;
                                mencoba = 3;
                                goto keluar_admin;
                                break;
                            }
                            default:
                                cout << "Inputan tidak valid.\n" << endl;
                                break;
                        }
                    }
                    keluar_admin:
                    break;
                } else {
                    mencoba--;
                    cout << "Login gagal, sisa percobaan: " << mencoba << "\n" << endl;
                    if(mencoba <= 0){
                        cout << "Anda telah melewati batas login. Program berhenti.\n" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(pilih_1 == 2){
            // Fitur User: Registrasi dan Login
            int pilihUser;
            bool userLoggedIn = false;
            string userName, userPassword;
            while(true){
                cout << "============ USER AREA ============" << endl;
                cout << "[1] Daftar (Register)" << endl;
                cout << "[2] Login" << endl;
                cout << "[3] Kembali ke Beranda" << endl;
                cout << "Silahkan pilih : ";
                cin >> pilihUser;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Inputan salah\n" << endl;
                    continue;
                }
                if(pilihUser == 1){
                    // Registrasi user
                    if(userCount < 10){
                        cout << "Masukkan username: ";
                        cin >> userName;
                        cout << "Masukkan password: ";
                        cin >> userPassword;
                        users[userCount].username = userName;
                        users[userCount].password = userPassword;
                        userCount++;
                        cout << "Registrasi berhasil! Silakan login.\n" << endl;
                    } else {
                        cout << "Kapasitas pengguna penuh.\n" << endl;
                    }
                }
                else if(pilihUser == 2){
                    // Login user
                    cout << "Masukkan username: ";
                    cin >> userName;
                    cout << "Masukkan password: ";
                    cin >> userPassword;
                    bool found = false;
                    for(int i = 0; i < userCount; i++){
                        if(users[i].username == userName && users[i].password == userPassword){
                            found = true;
                            break;
                        }
                    }
                    if(found){
                        userLoggedIn = true;
                        cout << "Login berhasil!\n" << endl;
                        break;
                    }
                    else{
                        cout << "Username atau password salah.\n" << endl;
                    }
                }
                else if(pilihUser == 3){
                    break;
                }
                else{
                    cout << "Inputan salah.\n" << endl;
                }
            }
            // Setelah login user berhasil, tampilkan menu pemesanan
            while(userLoggedIn){
                cout << "============ HALO PEMBELI ============" << endl;
                cout << "[1] Pesan PS" << endl;
                cout << "[2] Pesan Makanan" << endl;
                cout << "[3] Pesan Minuman" << endl;
                cout << "[4] Lihat Pesanan" << endl;
                cout << "[5] Logout" << endl;
                cout << "Silahkan pilih : ";
                cin >> pilih_3;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Inputan salah\n" << endl;
                    continue;
                }
                switch(pilih_3){
                    case 1:
                        if(panjangPS == 0){
                            cout << "Belum ada menu PS tersedia.\n" << endl;
                        } else {
                            cout << "\n==== Daftar Menu PS ====" << endl;
                            for(int i = 0; i < panjangPS; i++){
                                cout << i+1 << ". " << menuPS[i].nama << endl;
                            }
                            cout << "Pilih nomor menu PS yang diinginkan: ";
                            cin >> index;
                            if(index > 0 && index <= panjangPS){
                                pesananPS[pesanPS++] = menuPS[index-1];
                                cout << "Pesanan berhasil ditambahkan!\n" << endl;
                            } else {
                                cout << "Nomor tidak valid.\n" << endl;
                            }
                        }
                        break;
                    case 2:
                        if(panjangMakanan == 0){
                            cout << "Belum ada menu Makanan tersedia.\n" << endl;
                        } else {
                            cout << "\n==== Daftar Menu Makanan ====" << endl;
                            for(int i = 0; i < panjangMakanan; i++){
                                cout << i+1 << ". " << menuMakanan[i].nama << endl;
                            }
                            cout << "Pilih nomor menu Makanan yang diinginkan: ";
                            cin >> index;
                            if(index > 0 && index <= panjangMakanan){
                                pesananMakanan[pesanMakanan++] = menuMakanan[index-1];
                                cout << "Pesanan berhasil ditambahkan!\n" << endl;
                            } else {
                                cout << "Nomor tidak valid.\n" << endl;
                            }
                        }
                        break;
                    case 3:
                        if(panjangMinuman == 0){
                            cout << "Belum ada menu Minuman tersedia.\n" << endl;
                        } else {
                            cout << "\n==== Daftar Menu Minuman ====" << endl;
                            for(int i = 0; i < panjangMinuman; i++){
                                cout << i+1 << ". " << menuMinuman[i].nama << endl;
                            }
                            cout << "Pilih nomor menu Minuman yang diinginkan: ";
                            cin >> index;
                            if(index > 0 && index <= panjangMinuman){
                                pesananMinuman[pesanMinuman++] = menuMinuman[index-1];
                                cout << "Pesanan berhasil ditambahkan!\n" << endl;
                            } else {
                                cout << "Nomor tidak valid.\n" << endl;
                            }
                        }
                        break;
                    case 4:
                        cout << "\n============ DAFTAR PESANAN ANDA ============" << endl;
                        if(pesanPS == 0 && pesanMakanan == 0 && pesanMinuman == 0){
                            cout << "Anda belum memesan apa pun.\n" << endl;
                        } else {
                            if(pesanPS > 0){
                                cout << "Pesanan PS:" << endl;
                                for(int i = 0; i < pesanPS; i++){
                                    cout << i+1 << ". " << pesananPS[i].nama << endl;
                                }
                                cout << endl;
                            }
                            if(pesanMakanan > 0){
                                cout << "Pesanan Makanan:" << endl;
                                for(int i = 0; i < pesanMakanan; i++){
                                    cout << i+1 << ". " << pesananMakanan[i].nama << endl;
                                }
                                cout << endl;
                            }
                            if(pesanMinuman > 0){
                                cout << "Pesanan Minuman:" << endl;
                                for(int i = 0; i < pesanMinuman; i++){
                                    cout << i+1 << ". " << pesananMinuman[i].nama << endl;
                                }
                                cout << endl;
                            }
                        }
                        break;
                    case 5:
                        cout << "\nLogout berhasil.\n" << endl;
                        userLoggedIn = false;
                        break;
                    default:
                        cout << "Inputan salah.\n" << endl;
                        break;
                }
            }
            // Kembali ke menu utama setelah user logout
        }
        else if(pilih_1 == 3){
            cout << "TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI!\n";
            break;
        }
        else{
            cout << "Inputan tidak valid.\n" << endl;
        }
    }
    return 0;
}

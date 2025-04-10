#include <iostream>
#include <string>
using namespace std;

struct menu {
    string nama_menu;
    int harga;  // fitur harga ditambahkan
};

struct login {
    string username;
    string password;
};

// Prosedur untuk menampilkan tampilan beranda
void tampilBeranda() {
    cout << "=================== SELAMAT DATANG =================" << endl;
    cout << "| [1] ADMIN " << endl;
    cout << "| [2] USER " << endl;
    cout << "| [3] EXIT " << endl;
    cout << "=====================================================" << endl;
    cout << "Silahkan pilih: ";
}

// Fungsi rekursif untuk login admin
bool login_admin(string Syarat_Login[][2], int jumlahData, int attempt) {
    if (attempt <= 0) {
        cout << "Anda sudah melebihi batas percobaan login.\n";
        return false;
    }
    
    string username, password;
    cout << "Masukkan username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Masukkan password: ";
    cin >> password;
    
    for (int i = 0; i < jumlahData; i++) {
        if (username == Syarat_Login[i][0] && password == Syarat_Login[i][1]) {
            cout << "Login sukses!\n\n";
            return true;
        }
    }
    
    cout << "Login gagal. Sisa percobaan: " << attempt - 1 << "\n\n";
    return login_admin(Syarat_Login, jumlahData, attempt - 1);
}

// Overloaded function untuk menampilkan menu
// Versi tanpa header: menampilkan nama menu dan harga
void tampilMenu(menu arr[], int jumlah) {
    if(jumlah == 0) {
        cout << "Belum ada menu.\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << arr[i].nama_menu << " - Rp" << arr[i].harga << endl;
    }
}

// Versi dengan header
void tampilMenu(string header, menu arr[], int jumlah) {
    cout << "=== " << header << " ===" << endl;
    tampilMenu(arr, jumlah);
    cout << endl;
}

// Prosedur untuk menambahkan menu ke dalam kategori tertentu
void tambahMenu(menu simpan[], int &jumlah, int kapasitas, string kategori) {
    if (jumlah >= kapasitas) {
        cout << "Kapasitas " << kategori << " penuh.\n\n";
        return;
    }
    cout << "Masukkan nama menu " << kategori << ": ";
    cin.ignore();
    getline(cin, simpan[jumlah].nama_menu);
    cout << "Masukkan harga menu " << kategori << ": Rp";
    cin >> simpan[jumlah].harga;
    jumlah++;
    cout << "Menu berhasil ditambahkan ke " << kategori << ".\n\n";
}

// Prosedur untuk mengedit menu (nama dan harga)
void editMenu(menu simpan[], int jumlah, string kategori) {
    if (jumlah == 0) {
        cout << "Tidak ada menu " << kategori << " yang bisa diubah.\n\n";
        return;
    }
    tampilMenu("Daftar Menu " + kategori, simpan, jumlah);
    int index;
    cout << "Masukkan nomor menu " << kategori << " yang akan diubah: ";
    cin >> index;
    if (index > 0 && index <= jumlah) {
        cout << "Masukkan nama menu baru: ";
        cin.ignore();
        getline(cin, simpan[index-1].nama_menu);
        cout << "Masukkan harga menu baru: Rp";
        cin >> simpan[index-1].harga;
        cout << "Menu berhasil diubah.\n\n";
    } else {
        cout << "Inputan tidak valid.\n\n";
    }
}

// Prosedur untuk menghapus menu
void hapusMenu(menu simpan[], int &jumlah, string kategori) {
    if (jumlah == 0) {
        cout << "Tidak ada menu " << kategori << " yang bisa dihapus.\n\n";
        return;
    }
    tampilMenu("Daftar Menu " + kategori, simpan, jumlah);
    int index;
    cout << "Masukkan nomor menu " << kategori << " yang akan dihapus: ";
    cin >> index;
    if (index > 0 && index <= jumlah) {
        for (int i = index - 1; i < jumlah - 1; i++) {
            simpan[i] = simpan[i + 1];
        }
        jumlah--;
        cout << "Menu berhasil dihapus.\n\n";
    } else {
        cout << "Inputan tidak valid.\n\n";
    }
}

// Prosedur untuk tampilkan menu admin
void menuAdmin(string Syarat_Login[][2], int jumlahLogin,
               menu menu_ps[], int &panjang_ps,
               menu menu_makanan[], int &panjang_makanan,
               menu menu_minuman[], int &panjang_minuman,
               const int kapasitas) {
    // Melakukan login admin secara rekursif
    if (!login_admin(Syarat_Login, jumlahLogin, 3))
        return;
    
    int pilih;
    while (true) {
        cout << "============ HALO ADMIN ===========\n";
        cout << "| [1] Lihat Menu\n";
        cout << "| [2] Tambah Menu\n";
        cout << "| [3] Edit Menu\n";
        cout << "| [4] Hapus Menu\n";
        cout << "| [5] Kembali ke Beranda\n";
        cout << "===================================\n";
        cout << "Silahkan pilih: ";
        cin >> pilih;
        cout << endl;
        
        switch (pilih) {
            case 1: {
                int memilih;
                while (true) {
                    cout << "========== LIHAT MENU ==========\n";
                    cout << "| [1] Menu PS\n";
                    cout << "| [2] Menu Makanan\n";
                    cout << "| [3] Menu Minuman\n";
                    cout << "| [4] Kembali\n";
                    cout << "================================\n";
                    cout << "Silahkan pilih: ";
                    cin >> memilih;
                    cout << endl;
                    if(memilih == 1)
                        tampilMenu("Menu PS", menu_ps, panjang_ps);
                    else if(memilih == 2)
                        tampilMenu("Menu Makanan", menu_makanan, panjang_makanan);
                    else if(memilih == 3)
                        tampilMenu("Menu Minuman", menu_minuman, panjang_minuman);
                    else if(memilih == 4)
                        break;
                    else
                        cout << "Inputan salah.\n\n";
                }
                break;
            }
            case 2: {
                int memilih;
                while (true) {
                    cout << "========== TAMBAH MENU ==========\n";
                    cout << "| [1] Menu PS\n";
                    cout << "| [2] Menu Makanan\n";
                    cout << "| [3] Menu Minuman\n";
                    cout << "| [4] Kembali\n";
                    cout << "=================================\n";
                    cout << "Silahkan pilih: ";
                    cin >> memilih;
                    cout << endl;
                    if(memilih == 1)
                        tambahMenu(menu_ps, panjang_ps, kapasitas, "PS");
                    else if(memilih == 2)
                        tambahMenu(menu_makanan, panjang_makanan, kapasitas, "Makanan");
                    else if(memilih == 3)
                        tambahMenu(menu_minuman, panjang_minuman, kapasitas, "Minuman");
                    else if(memilih == 4)
                        break;
                    else
                        cout << "Inputan salah.\n\n";
                }
                break;
            }
            case 3: {
                int memilih;
                while (true) {
                    cout << "========== EDIT MENU ==========\n";
                    cout << "| [1] Menu PS\n";
                    cout << "| [2] Menu Makanan\n";
                    cout << "| [3] Menu Minuman\n";
                    cout << "| [4] Kembali\n";
                    cout << "================================\n";
                    cout << "Silahkan pilih: ";
                    cin >> memilih;
                    cout << endl;
                    if(memilih == 1)
                        editMenu(menu_ps, panjang_ps, "PS");
                    else if(memilih == 2)
                        editMenu(menu_makanan, panjang_makanan, "Makanan");
                    else if(memilih == 3)
                        editMenu(menu_minuman, panjang_minuman, "Minuman");
                    else if(memilih == 4)
                        break;
                    else
                        cout << "Inputan salah.\n\n";
                }
                break;
            }
            case 4: {
                int memilih;
                while (true) {
                    cout << "========== HAPUS MENU ==========\n";
                    cout << "| [1] Menu PS\n";
                    cout << "| [2] Menu Makanan\n";
                    cout << "| [3] Menu Minuman\n";
                    cout << "| [4] Kembali\n";
                    cout << "================================\n";
                    cout << "Silahkan pilih: ";
                    cin >> memilih;
                    cout << endl;
                    if(memilih == 1)
                        hapusMenu(menu_ps, panjang_ps, "PS");
                    else if(memilih == 2)
                        hapusMenu(menu_makanan, panjang_makanan, "Makanan");
                    else if(memilih == 3)
                        hapusMenu(menu_minuman, panjang_minuman, "Minuman");
                    else if(memilih == 4)
                        break;
                    else
                        cout << "Inputan salah.\n\n";
                }
                break;
            }
            case 5:
                return;
            default:
                cout << "Inputan salah.\n\n";
                break;
        }
    }
}

// Fungsi/Prosedur untuk menu user (registrasi, login, pemesanan)
void menuUser(login user[], int &isi,
              menu menu_ps[], int panjang_ps,
              menu menu_makanan[], int panjang_makanan,
              menu menu_minuman[], int panjang_minuman) {
    int pilihUser;
    bool userLoggedIn = false;
    string userName, userPassword;
    while (true) {
        cout << "============ MENU USER ============\n";
        cout << "[1] Daftar (Register)\n";
        cout << "[2] Login\n";
        cout << "[3] Kembali ke Beranda\n";
        cout << "Silahkan pilih: ";
        cin >> pilihUser;
        cout << endl;
        if (pilihUser == 1) {
            if (isi < 10) {
                cout << "Masukkan username: ";
                cin >> userName;
                cout << "Masukkan password: ";
                cin >> userPassword;
                user[isi].username = userName;
                user[isi].password = userPassword;
                isi++;
                cout << "Registrasi berhasil! Silakan login.\n\n";
            } else {
                cout << "Kapasitas pengguna penuh.\n\n";
            }
        }
        else if (pilihUser == 2) {
            int attempt = 3;
            while (attempt > 0 && !userLoggedIn) {
                cout << "Masukkan username: ";
                cin >> userName;
                cout << "Masukkan password: ";
                cin >> userPassword;
                bool found = false;
                for (int i = 0; i < isi; i++) {
                    if (user[i].username == userName && user[i].password == userPassword) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    userLoggedIn = true;
                    cout << "Login berhasil!\n\n";
                } else {
                    attempt--;
                    cout << "Login gagal. Sisa percobaan: " << attempt << "\n\n";
                }
            }
            if (!userLoggedIn) {
                cout << "Kembali ke menu utama.\n\n";
                return;
            }
        }
        else if (pilihUser == 3) {
            break;
        }
        else {
            cout << "Inputan salah.\n\n";
        }
        
        // Setelah login berhasil, tampilkan menu pemesanan untuk user
        int pilihPemesanan;
        int index;
        const int kapasitasPemesanan = 10;
        // Array pesanan lokal (per kategori)
        menu pesanan_ps[kapasitasPemesanan], pesanan_makanan[kapasitasPemesanan], pesanan_minuman[kapasitasPemesanan];
        int pesan_ps = 0, pesan_makanan = 0, pesan_minuman = 0;
        
        while (userLoggedIn) {
            cout << "============ HALO PEMBELI ============\n";
            cout << "[1] Pesan PS\n";
            cout << "[2] Pesan Makanan\n";
            cout << "[3] Pesan Minuman\n";
            cout << "[4] Lihat Pesanan\n";
            cout << "[5] Keluar\n";
            cout << "Silahkan pilih: ";
            cin >> pilihPemesanan;
            cout << endl;
            
            switch (pilihPemesanan) {
                case 1:
                    if (panjang_ps == 0)
                        cout << "Belum ada menu PS tersedia.\n\n";
                    else {
                        tampilMenu("Menu PS", menu_ps, panjang_ps);
                        cout << "Pilih nomor menu PS: ";
                        cin >> index;
                        if (index > 0 && index <= panjang_ps) {
                            pesanan_ps[pesan_ps++] = menu_ps[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n\n";
                        } else
                            cout << "Nomor tidak valid.\n\n";
                    }
                    break;
                case 2:
                    if (panjang_makanan == 0)
                        cout << "Belum ada menu Makanan tersedia.\n\n";
                    else {
                        tampilMenu("Menu Makanan", menu_makanan, panjang_makanan);
                        cout << "Pilih nomor menu Makanan: ";
                        cin >> index;
                        if (index > 0 && index <= panjang_makanan) {
                            pesanan_makanan[pesan_makanan++] = menu_makanan[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n\n";
                        } else
                            cout << "Nomor tidak valid.\n\n";
                    }
                    break;
                case 3:
                    if (panjang_minuman == 0)
                        cout << "Belum ada menu Minuman tersedia.\n\n";
                    else {
                        tampilMenu("Menu Minuman", menu_minuman, panjang_minuman);
                        cout << "Pilih nomor menu Minuman: ";
                        cin >> index;
                        if (index > 0 && index <= panjang_minuman) {
                            pesanan_minuman[pesan_minuman++] = menu_minuman[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n\n";
                        } else
                            cout << "Nomor tidak valid.\n\n";
                    }
                    break;
                case 4:
                    cout << "=========== DAFTAR PESANAN ===========\n";
                    if (pesan_ps == 0 && pesan_makanan == 0 && pesan_minuman == 0)
                        cout << "Belum ada pesanan.\n\n";
                    else {
                        if (pesan_ps > 0) {
                            cout << "Pesanan PS:\n";
                            tampilMenu(pesanan_ps, pesan_ps);
                        }
                        if (pesan_makanan > 0) {
                            cout << "Pesanan Makanan:\n";
                            tampilMenu(pesanan_makanan, pesan_makanan);
                        }
                        if (pesan_minuman > 0) {
                            cout << "Pesanan Minuman:\n";
                            tampilMenu(pesanan_minuman, pesan_minuman);
                        }
                        cout << endl;
                    }
                    break;
                case 5:
                    userLoggedIn = false;
                    break;
                default:
                    cout << "Inputan salah.\n\n";
                    break;
            }
        }  // akhir while userLoggedIn
    }
}

int main(){
    const int kapasitasMenu = 10;
    // Inisialisasi array menu dan jumlah menu setiap kategori
    menu menu_ps[kapasitasMenu], menu_makanan[kapasitasMenu], menu_minuman[kapasitasMenu];
    int panjang_ps = 0, panjang_makanan = 0, panjang_minuman = 0;
    
    // Array pengguna (untuk mode user)
    login user[10];
    int isiUser = 0;
    
    // Data login admin
    string Syarat_Login[2][2] = { {"rifqi al bukhari", "2409106112"},
                                   {"rifqi", "112"} };
    
    int pilih;
    while (true) {
        tampilBeranda();
        cin >> pilih;
        cout << endl;
        if (pilih == 1) {
            // Menu Admin
            menuAdmin(Syarat_Login, 2, menu_ps, panjang_ps, menu_makanan, panjang_makanan, menu_minuman, panjang_minuman, kapasitasMenu);
        }
        else if (pilih == 2) {
            // Menu User
            menuUser(user, isiUser, menu_ps, panjang_ps, menu_makanan, panjang_makanan, menu_minuman, panjang_minuman);
        }
        else if (pilih == 3) {
            cout << "TERIMAKASIH MENGGUNAKAN PROGRAM INI! ^_^ \n";
            break;
        }
        else {
            cout << "Inputan tidak valid. Silahkan coba kembali.\n\n";
        }
    }
    
    return 0;
}


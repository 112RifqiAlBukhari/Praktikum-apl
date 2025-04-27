// #include <iostream>
// #include <string>
// #include <functional>
// #include <limits>
// using namespace std;

// // Struktur data
// struct menu {
//     string nama_menu;
//     int harga;
// };

// struct login {
//     string username;
//     string password;
// };

// // Fungsi demo pointer
// void demoAddressOf(menu *m) {
//     cout << "[Demo Address-Of] Nama menu: " << m->nama_menu
//          << ", Harga: Rp" << m->harga << endl;
// }

// void demoAlamat(menu *m) {
//     cout << "[Demo Alamat] Alamat memori menu yang dipilih adalah: "
//          << static_cast<void*>(m) << endl;
// }

// void demoDereference(menu *m) {
//     cout << "[Demo Dereference] Nama menu: " << (*m).nama_menu
//          << ", Harga: Rp" << (*m).harga << endl;
// }

// // Alias comparator
// using Comparator = function<bool(const menu&, const menu&)>;

// // Quick Sort
// int partition(menu arr[], int low, int high, Comparator cmp) {
//     menu pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; ++j) {
//         if (cmp(arr[j], pivot)) {
//             swap(arr[++i], arr[j]);
//         }
//     }
//     swap(arr[i+1], arr[high]);
//     return i + 1;
// }

// void quickSort(menu arr[], int low, int high, Comparator cmp) {
//     if (low < high) {
//         int pi = partition(arr, low, high, cmp);
//         quickSort(arr, low, pi - 1, cmp);
//         quickSort(arr, pi + 1, high, cmp);
//     }
// }

// // Merge Sort
// void merge(menu arr[], int l, int m, int r, Comparator cmp) {
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     menu *L = new menu[n1];
//     menu *R = new menu[n2];
//     for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
//     for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
//     int i = 0, j = 0, k = l;
//     while (i < n1 && j < n2) {
//         if (cmp(L[i], R[j])) arr[k++] = L[i++];
//         else arr[k++] = R[j++];
//     }
//     while (i < n1) arr[k++] = L[i++];
//     while (j < n2) arr[k++] = R[j++];
//     delete[] L;
//     delete[] R;
// }

// void mergeSort(menu arr[], int l, int r, Comparator cmp) {
//     if (l < r) {
//         int m = l + (r - l) / 2;
//         mergeSort(arr, l, m, cmp);
//         mergeSort(arr, m + 1, r, cmp);
//         merge(arr, l, m, r, cmp);
//     }
// }

// // Insertion Sort
// void insertionSort(menu arr[], int n, Comparator cmp) {
//     for (int i = 1; i < n; ++i) {
//         menu key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && cmp(key, arr[j])) {
//             arr[j + 1] = arr[j];
//             --j;
//         }
//         arr[j + 1] = key;
//     }
// }

// // Wrapper sorting
// void sortMenuNameDesc(menu arr[], int n) {
//     quickSort(arr, 0, n - 1, [](const menu &a, const menu &b) {
//         return a.nama_menu > b.nama_menu;
//     });
// }

// void sortMenuPriceAsc(menu arr[], int n) {
//     mergeSort(arr, 0, n - 1, [](const menu &a, const menu &b) {
//         return a.harga < b.harga;
//     });
// }

// void sortMenuPriceDesc(menu arr[], int n) {
//     insertionSort(arr, n, [](const menu &a, const menu &b) {
//         return a.harga > b.harga;
//     });
// }

// // Tampilan beranda
// void tampilBeranda() {
//     cout << "=================== SELAMAT DATANG =================" << endl;
//     cout << "| [1] ADMIN" << endl;
//     cout << "| [2] USER" << endl;
//     cout << "| [3] EXIT" << endl;
//     cout << "=====================================================" << endl;
//     cout << "Silahkan pilih: ";
// }

// // Admin login
// bool login_admin(string Syarat_Login[][2], int jumlahData, int attempt) {
//     if (attempt <= 0) {
//         cout << "Anda sudah melebihi batas percobaan login." << endl;
//         return false;
//     }
//     string username, password;
//     cout << "Masukkan username: ";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     getline(cin, username);
//     cout << "Masukkan password: ";
//     cin >> password;

//     for (int i = 0; i < jumlahData; ++i) {
//         if (username == Syarat_Login[i][0] && password == Syarat_Login[i][1]) {
//             cout << "Login sukses!" << endl;
//             return true;
//         }
//     }
//     cout << "Login gagal. Sisa percobaan: " << attempt - 1 << endl;
//     return login_admin(Syarat_Login, jumlahData, attempt - 1);
// }

// // Tampilkan menu
// void tampilMenu(menu arr[], int jumlah) {
//     if (jumlah == 0) {
//         cout << "Belum ada menu." << endl;
//         return;
//     }
//     for (int i = 0; i < jumlah; ++i)
//         cout << i + 1 << ". " << arr[i].nama_menu << " - Rp" << arr[i].harga << endl;
// }

// void tampilMenu(string header, menu arr[], int jumlah) {
//     cout << "=== " << header << " ===" << endl;
//     tampilMenu(arr, jumlah);
//     cout << endl;
// }

// // CRUD menu
// void tambahMenu(menu simpan[], int &jumlah, int kapasitas, string kategori) {
//     if (jumlah >= kapasitas) {
//         cout << kategori << " sudah penuh." << endl;
//         return;
//     }
//     cout << "Nama menu " << kategori << ": ";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     getline(cin, simpan[jumlah].nama_menu);
//     cout << "Harga menu (Rp): ";
//     cin >> simpan[jumlah].harga;
//     ++jumlah;
//     cout << "Menu ditambahkan ke " << kategori << "!" << endl;
// }

// void editMenu(menu simpan[], int jumlah, string kategori) {
//     if (jumlah == 0) {
//         cout << "Tidak ada menu " << kategori << " untuk diubah." << endl;
//         return;
//     }
//     tampilMenu("Daftar " + kategori, simpan, jumlah);
//     cout << "Nomor yang diubah: ";
//     int idx; cin >> idx;
//     if (idx < 1 || idx > jumlah) {
//         cout << "Pilihan tidak valid." << endl;
//         return;
//     }
//     cout << "Nama baru: ";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     getline(cin, simpan[idx-1].nama_menu);
//     cout << "Harga baru: ";
//     cin >> simpan[idx-1].harga;
//     cout << "Menu diperbarui." << endl;
// }

// void hapusMenu(menu simpan[], int &jumlah, string kategori) {
//     if (jumlah == 0) {
//         cout << "Tidak ada menu " << kategori << " untuk dihapus." << endl;
//         return;
//     }
//     tampilMenu("Daftar " + kategori, simpan, jumlah);
//     cout << "Nomor yang dihapus: ";
//     int idx; cin >> idx;
//     if (idx < 1 || idx > jumlah) {
//         cout << "Pilihan tidak valid." << endl;
//         return;
//     }
//     for (int i = idx - 1; i < jumlah - 1; ++i)
//         simpan[i] = simpan[i + 1];
//     --jumlah;
//     cout << "Menu dihapus." << endl;
// }

// // Menu Admin
// void menuAdmin(string Syarat_Login[][2], int jumlahLogin,
//                menu menu_ps[], int &panjang_ps,
//                menu menu_makanan[], int &panjang_makanan,
//                menu menu_minuman[], int &panjang_minuman,
//                int kapasitas) {
//     if (!login_admin(Syarat_Login, jumlahLogin, 3)) return;
//     while (true) {
//         cout << "\n===== ADMIN PANEL =====" << endl;
//         cout << "1. Lihat Menu" << endl;
//         cout << "2. Tambah Menu" << endl;
//         cout << "3. Edit Menu" << endl;
//         cout << "4. Hapus Menu" << endl;
//         cout << "5. Demo Pointer" << endl;
//         cout << "6. Sorting Menu" << endl;
//         cout << "7. Logout" << endl;
//         cout << "Pilihan: ";
//         int pilih; cin >> pilih;

//         if (pilih == 1) {
//             int sub;
//             do {
//                 cout << "\n[Lihat] 1.PS 2.Makanan 3.Minuman 4.Kembali: ";
//                 cin >> sub;
//                 if (sub == 1) tampilMenu("Menu PS", menu_ps, panjang_ps);
//                 else if (sub == 2) tampilMenu("Menu Makanan", menu_makanan, panjang_makanan);
//                 else if (sub == 3) tampilMenu("Menu Minuman", menu_minuman, panjang_minuman);
//             } while (sub != 4);

//         } else if (pilih == 2) {
//             int sub;
//             do {
//                 cout << "\n[Tambah] 1.PS 2.Makanan 3.Minuman 4.Kembali: ";
//                 cin >> sub;
//                 if (sub == 1) tambahMenu(menu_ps, panjang_ps, kapasitas, "PS");
//                 else if (sub == 2) tambahMenu(menu_makanan, panjang_makanan, kapasitas, "Makanan");
//                 else if (sub == 3) tambahMenu(menu_minuman, panjang_minuman, kapasitas, "Minuman");
//             } while (sub != 4);

//         } else if (pilih == 3) {
//             int sub;
//             do {
//                 cout << "\n[Edit] 1.PS 2.Makanan 3.Minuman 4.Kembali: ";
//                 cin >> sub;
//                 if (sub == 1) editMenu(menu_ps, panjang_ps, "PS");
//                 else if (sub == 2) editMenu(menu_makanan, panjang_makanan, "Makanan");
//                 else if (sub == 3) editMenu(menu_minuman, panjang_minuman, "Minuman");
//             } while (sub != 4);

//         } else if (pilih == 4) {
//             int sub;
//             do {
//                 cout << "\n[Hapus] 1.PS 2.Makanan 3.Minuman 4.Kembali: ";
//                 cin >> sub;
//                 if (sub == 1) hapusMenu(menu_ps, panjang_ps, "PS");
//                 else if (sub == 2) hapusMenu(menu_makanan, panjang_makanan, "Makanan");
//                 else if (sub == 3) hapusMenu(menu_minuman, panjang_minuman, "Minuman");
//             } while (sub != 4);

//         } else if (pilih == 5) {
//             if (panjang_ps > 0) {
//                 tampilMenu("Menu PS", menu_ps, panjang_ps);
//                 cout << "Nomor demo: "; int i; cin >> i; --i;
//                 demoAlamat(&menu_ps[i]);
//                 demoAddressOf(&menu_ps[i]);
//                 demoDereference(&menu_ps[i]);
//             } else cout << "Tidak ada PS untuk demo." << endl;

//         } else if (pilih == 6) {
//             int metode, cat;
//             do {
//                 cout << "\n================= Sorting ================ " << endl;
//                 cout << "[1] Nama secara Descending " << endl;
//                 cout << "[2] Harga secara Ascending " << endl;
//                 cout << "[3] Harga secara Descending " << endl;
//                 cout << "pilih : ";
//                 cin >> metode;
//                 if (metode >=1 && metode <=3) {
//                     cout << "Kategori: 1.PS 2.Makanan 3.Minuman 4.Kembali: ";
//                     cout << "[1] Ps " << endl;
//                     cout << "[2] Makanan " << endl;
//                     cout << "[3] Minuman " << endl;
//                     cout << "[4] kembali " << endl;
//                     cout << "pilih : ";
//                     cin >> cat;
//                     if (cat == 1) {
//                         if (metode == 1) sortMenuNameDesc(menu_ps, panjang_ps);
//                         else if (metode == 2) sortMenuPriceAsc(menu_ps, panjang_ps);
//                         else sortMenuPriceDesc(menu_ps, panjang_ps);
//                         tampilMenu("Menu PS (Sorted)", menu_ps, panjang_ps);
//                     } else if (cat == 2) {
//                         if (metode == 1) sortMenuNameDesc(menu_makanan, panjang_makanan);
//                         else if (metode == 2) sortMenuPriceAsc(menu_makanan, panjang_makanan);
//                         else sortMenuPriceDesc(menu_makanan, panjang_makanan);
//                         tampilMenu("Menu Makanan (Sorted)", menu_makanan, panjang_makanan);
//                     } else if (cat == 3) {
//                         if (metode == 1) sortMenuNameDesc(menu_minuman, panjang_minuman);
//                         else if (metode == 2) sortMenuPriceAsc(menu_minuman, panjang_minuman);
//                         else sortMenuPriceDesc(menu_minuman, panjang_minuman);
//                         tampilMenu("Menu Minuman (Sorted)", menu_minuman, panjang_minuman);
//                     }
//                 }
//             } while (metode != 4);

//         } else if (pilih == 7) {
//             break;
//         }
//     }
// }

// // Menu User
// void menuUser(login user[], int &isi,
//               menu menu_ps[], int panjang_ps,
//               menu menu_makanan[], int panjang_makanan,
//               menu menu_minuman[], int panjang_minuman) {
//     int pilihUser;
//     bool logged = false;
//     string un, pw;
//     while (true) {
//         cout << "\n===== MENU USER =====" << endl;
//         cout << "1. Register" << endl;
//         cout << "2. Login" << endl;
//         cout << "3. Kembali" << endl;
//         cout << "Pilihan: ";
//         cin >> pilihUser;
//         if (pilihUser == 1) {
//             if (isi < 10) {
//                 cout << "Username: "; cin >> un;
//                 cout << "Password: "; cin >> pw;
//                 user[isi++] = {un, pw};
//                 cout << "Registrasi sukses!\n";
//             }
//         } else if (pilihUser == 2) {
//             int att = 3;
//             while (att-- > 0 && !logged) {
//                 cout << "Username: "; cin >> un;
//                 cout << "Password: "; cin >> pw;
//                 for (int i = 0; i < isi; ++i)
//                     if (user[i].username == un && user[i].password == pw) {
//                         logged = true; break;
//                     }
//                 if (!logged) cout << "Login gagal.\n";
//             }
//             if (!logged) break;
//             int choice;
//             const int cap = 10;
//             menu p_ps[cap], p_ma[cap], p_mi[cap];
//             int c_ps=0, c_ma=0, c_mi=0;
//             while (logged) {
//                 cout << "\n[USER] 1.PS 2.Makanan 3.Minuman 4.Lihat 5.Keluar: ";
//                 cin >> choice;
//                 if (choice == 1 && panjang_ps>0) {
//                     tampilMenu("Pesan PS", menu_ps, panjang_ps);
//                     int idx; cin >> idx;
//                     p_ps[c_ps++] = menu_ps[idx-1];
//                 } else if (choice == 2 && panjang_makanan>0) {
//                     tampilMenu("Pesan Makanan", menu_makanan, panjang_makanan);
//                     int idx; cin >> idx;
//                     p_ma[c_ma++] = menu_makanan[idx-1];
//                 } else if (choice == 3 && panjang_minuman>0) {
//                     tampilMenu("Pesan Minuman", menu_minuman, panjang_minuman);
//                     int idx; cin >> idx;
//                     p_mi[c_mi++] = menu_minuman[idx-1];
//                 } else if (choice == 4) {
//                     cout << "\n-- Pesanan --\n";
//                     if (c_ps) { cout << "PS:"; tampilMenu(p_ps, c_ps); }
//                     if (c_ma) { cout << "Makanan:"; tampilMenu(p_ma, c_ma); }
//                     if (c_mi) { cout << "Minuman:"; tampilMenu(p_mi, c_mi); }
//                 } else if (choice == 5) logged = false;
//             }
//         } else break;
//     }
// }

// int main() {
//     const int capMenu = 10;
//     menu menu_ps[capMenu], menu_makanan[capMenu], menu_minuman[capMenu];
//     int ps=0, ma=0, mi=0;
//     login users[10]; int userCount=0;
//     string Syarat_Login[2][2] = {{"rifqi al bukhari","2409106112"},{"rifqi","112"}};
//     while (true) {
//         tampilBeranda(); int pilihan; cin >> pilihan;
//         if (pilihan == 1) menuAdmin(Syarat_Login,2,menu_ps,ps,menu_makanan,ma,menu_minuman,mi,capMenu);
//         else if (pilihan == 2) menuUser(users,userCount,menu_ps,ps,menu_makanan,ma,menu_minuman,mi);
//         else if (pilihan == 3) break;
//     }
//     cout << "Terima kasih!" << endl;
//     return 0;
// }

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

// fungsi addres of
void demoAddressOf(menu *m) {
    // Mengakses anggota struct lewat pointer dengan '->'
    cout << "[Demo Address-Of] "
         << "Nama menu: " << m->nama_menu
         << ", Harga: Rp"  << m->harga
         << endl;
}

void demoAlamat(menu *m) {
    // casting ke void* agar cout tahu ini pointer generik
    cout << "[Demo Alamat] Alamat memori menu yang di pilih adalah : "
         << static_cast<void*>(m)
         << endl;
}

// fungdi deference
void demoDereference(menu *m) {
    // (*m) mendereferensikan pointer m,
    // lalu akses anggota struct dengan '.'
    cout << "[Demo Dereference] "
         << "Nama menu: " << (*m).nama_menu
         << ", Harga: Rp"    << (*m).harga
         << endl;
}

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


// Quick Sort khusus untuk nama menu descending
int Quick_sortt_descending(menu arr[], int low, int high) {
    menu pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j].nama_menu > pivot.nama_menu) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Quick_sort_descending(menu arr[], int low, int high) {
    if (low < high) {
        int pi = Quick_sortt_descending(arr, low, high);
        Quick_sort_descending(arr, low, pi - 1);
        Quick_sort_descending(arr, pi + 1, high);
    }
}

// Merge Sort khusus untuk harga ascending
void merge_Sortt_ascending(menu arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    menu *L = new menu[n1];
    menu *R = new menu[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].harga < R[j].harga) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void merge_sort_ascending(menu arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_ascending(arr, l, m);
        merge_sort_ascending(arr, m + 1, r);
        merge_Sortt_ascending(arr, l, m, r);
    }
}

// Insertion Sort khusus untuk harga descending
void insertion_sort_descending(menu arr[], int n) {
    for (int i = 1; i < n; ++i) {
        menu key = arr[i];
        int j = i - 1;
        while (j >= 0 && key.harga > arr[j].harga) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Wrapper sorting tanpa comparator
void sorting_nama_menu_descending(menu arr[], int n) {
    Quick_sort_descending(arr, 0, n - 1);
}

void sorting_harga_ascending(menu arr[], int n) {
    merge_sort_ascending(arr, 0, n - 1);
}

void sorting_harga_descending(menu arr[], int n) {
    insertion_sort_descending(arr, n);
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
        cout << "| [5] demo pointer\n";
        cout << "| [6] Sorting menu\n";
        cout << "| [7] Kembali ke Beranda\n";
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
            case 5:{
            int i;
            // contoh aja di bagian ps
            if (panjang_ps > 0) {
                tampilMenu("Menu PS", menu_ps, panjang_ps);
                cout << "masukkan mau menu ke brp ?";
                cin >> i;
                i--;
                demoAlamat(&menu_ps[i]);
                demoAddressOf(&menu_ps[i]);
                demoDereference(&menu_ps[i]);
             } else {
                cout << "Tidak ada item PS untuk demo.\n";
              }
              break;
            }

            case 6:{
            int metode, pilih;
            while(true){
                cout << "\n================= Sorting ================ " << endl;
                cout << "[1] Nama secara Descending " << endl;
                cout << "[2] Harga secara Ascending " << endl;
                cout << "[3] Harga secara Descending " << endl;
                cout << "pilih : ";
                cin >> metode;
                if (metode >=1 && metode <=3) {
                cout << "=============== Kategori ============" << endl;
                cout << "[1] Ps " << endl;
                cout << "[2] Makanan " << endl;
                cout << "[3] Minuman " << endl;
                cout << "[4] kembali " << endl;
                cout << "pilih : ";
                cin >> pilih;
                    if (pilih == 1) {
                        if (metode == 1) sorting_nama_menu_descending(menu_ps, panjang_ps);
                            else if (metode == 2) sorting_harga_ascending(menu_ps, panjang_ps);
                            else sorting_harga_descending(menu_ps, panjang_ps);
                            tampilMenu("Menu PS (Sorted)", menu_ps, panjang_ps);

                        } else if (pilih == 2) {
                                if (metode == 1) sorting_nama_menu_descending(menu_makanan, panjang_makanan);
                                else if (metode == 2) sorting_harga_ascending(menu_makanan, panjang_makanan);
                                else sorting_harga_descending(menu_makanan, panjang_makanan);
                                tampilMenu("Menu Makanan (Sorted)", menu_makanan, panjang_makanan);

                        } else if (pilih == 3) {
                                if (metode == 1) sorting_nama_menu_descending(menu_minuman, panjang_minuman);
                                else if (metode == 2) sorting_harga_ascending(menu_minuman, panjang_minuman);
                                else sorting_harga_descending(menu_minuman, panjang_minuman);
                                tampilMenu("Menu Minuman (Sorted)", menu_minuman, panjang_minuman);
                                    }
                                }
                            }
                            break;
                        }

            case 7:
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


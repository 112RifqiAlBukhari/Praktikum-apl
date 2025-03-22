#include<iostream>
#include<string>
using namespace std;

struct menu{

    string nama_menu;
}; 

struct login{
    string username;
    string password;
};




int main(){

string Syarat_Login[2][2] = { {"rifqi al bukhari", "2409106112"},
                            {"rifqi", "112"}
                            };

login user[10];


const int kapasitas_menu = 10;
menu menu_ps[kapasitas_menu];
menu menu_makanan[kapasitas_menu];
menu menu_minuman[kapasitas_menu];

menu pesanan_ps[kapasitas_menu];
menu pesanan_makanan[kapasitas_menu];
menu pesanan_minuman[kapasitas_menu];

int pilih_1,pilih_2,pilih_3,pilih_4,pilih_5,pilih_6,pilih_7,pilih_8,pilih_9,pilih_10;
int index;
int mencoba = 3,panjang_ps= 0,panjang_makanan =0, panjang_minuman = 0,isi = 0,mencoba_user = 3;
int pesan_ps = 0, pesan_makanan = 0, pesan_minuman = 0;
string username,password;

bool login_sukses= false;

while (true){
    menu:
    cout << "=================== SELAMAT DATANG =================" << endl;
    cout << "| " << "[1] ADMIN "  << endl;
    cout << "| " << "[2] USER " << endl;
    cout << "| " << "[3] EXIT "  << endl;
    cout << "=====================================================" << endl;
    cout << "silahkan pilih : ";
    cin >> pilih_1;
    
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "inputan salah" << endl;
        cout << endl;
    }

    cout << endl;
    
    if(pilih_1 == 1){

        while(mencoba > 0 && !login_sukses){
            cout << "================= SILAHKAN LOGIN ==================" << endl;
            cout << "masukkan username : ";
            cin.ignore();
            getline(cin,username);
            cout << "masukkan password : ";
            cin >> password;
            
            
            for(int i=0; i < 2; i++){
                if(username == Syarat_Login[i][0] && password == Syarat_Login[i][1] ){
                    login_sukses = true;
                    break;
                }
           

            }if(login_sukses){
                cout << endl;
                cout << "login sukses" << endl;
                cout << endl;
            while (true){
                menu_admin:
                cout << "============ HALO ADMIN GANTENG =========== \n";
                cout << "| " << "[1] Lihat MENU "  << endl;
                cout << "| " << "[2] tambah menu " << endl;;
                cout << "| " << "[3] edit menu "  << endl;
                cout << "| " << "[4] hapus menu " << endl;;
                cout << "| " << "[5] exit "  << endl;
                cout << "===========================================" << endl;
                cout << "silahkan pilih : ";
                cin >> pilih_2;


                if (cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "inputan salah" << endl;
                    cout << endl;
                }

                switch (pilih_2)
                {
                case 1:{
                    while (true)
                    {
                        
                    cout << "========== LIHAT MENU =============\n";
                    cout << "| " << "[1] MENU PS "  << endl;
                    cout << "| " << "[2] MENU MEKANAN " << endl;
                    cout << "| " << "[3] MENU MINUMAN " << endl;
                    cout << "| " << "[4] EXIT " << endl;
                    cout << "===================================" << endl;
                    cout << "silahkan pilih : ";
                    cin >> pilih_4;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "inputan salah" << endl;
                        cout << endl;
                    }

                    switch (pilih_4)
                    {
                    case 1:{
                        if(panjang_ps == 0){
                            cout << "belum ada menu" << endl;
                            cout << endl; 
                                             break;
                         }else{
                            cout << endl;
                            cout << "-----------------" << endl;
                            for(int i =0; i < panjang_ps; i++){
                                cout << "|  " << "no " << i + 1 << ": " << menu_ps[i].nama_menu << "  |" << endl;   }
                         }cout << "-----------------" << endl;
                         cout << endl;
                         break;
                        }
                    case 2:{
                        if(panjang_makanan == 0){
                            cout << "belum ada menu" << endl;
                            cout << endl; 
                                             break;
                         }else{
                            cout << endl;
                            cout << "-----------------" << endl;
                            for(int i =0; i < panjang_makanan; i++){
                                cout << "|  " << "no " << i + 1 << ": " << menu_makanan[i].nama_menu << "  |" << endl;  }
                         }cout << "-----------------" << endl;
                         cout << endl;
                         break;
                        }
                    case 3:{
                        if(panjang_minuman == 0){
                            cout << "belum ada menu" << endl;
                            cout << endl; 
                                             break;
                         }else{
                            cout << endl;
                            cout << "-----------------" << endl;
                            for(int i =0; i < panjang_minuman; i++){
                                cout << "|  " << "no " << i + 1 << ": " << menu_minuman[i].nama_menu << "  |" << endl;                         }
                         }cout << "-----------------" << endl;
                         cout << endl;
                         break;
                        }
                    case 4:{
                        cout << endl;
                        cout << "keluar" << endl;
                        cout << endl;
                        goto menu_admin;
                        break;
                    }
                    default:
                    cout << endl;
                    cout << "inputan salah" << endl;
                    cout << endl;
                    break;
                }
                }
                }
                
                case 2:{
                    while (true)
                    {
                    cout << "========== TAMBAH MENU ===========\n";
                    cout <<"| " << "[1] MENU PS \n";
                    cout <<"| " << "[2] MENU MEKANAN \n";
                    cout <<"| " << "[3] MENU MINUMAN \n";
                    cout <<"| " << "[4] EXIT \n";
                    cout << "===================================" << endl;
                    cout << "silahkan pilih : ";
                    cin >> pilih_5;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "inputan salah" << endl;
                        cout << endl;
                    }

                    switch (pilih_5)
                    {
                    case 1:{
                        if(panjang_ps < kapasitas_menu){
                            cout << "masukkan nama menu : ";
                            cin.ignore();
                            getline(cin, menu_ps[panjang_ps].nama_menu);
                            panjang_ps++;
                            cout << "menu berhasil di tambahkan" << endl;
                            cout << endl;
                            break;
                        }
                            else{
                            cout << "kapasitas penuh " << endl;
                            cout << endl;
                            break;
                            }
                        }
                    

                    case 2:{
                        if(panjang_makanan < kapasitas_menu){
                            cout << "masukkan nama menu : ";
                            cin.ignore();
                            getline(cin, menu_makanan[panjang_makanan].nama_menu);
                            panjang_makanan++;
                            cout << "menu berhasil di tambahkan" << endl;
                            cout << endl;
                            break;
                        }
                             else{
                            cout << "kapasitas penuh " << endl;
                            cout << endl;
                            break;
                            }
                        }
                            
                            
                            

                    case 3:{
                        if(panjang_minuman < 10){
                        cout << "masukkan nama menu : ";
                        cin.ignore();
                        getline(cin,menu_minuman[panjang_minuman].nama_menu);
                        panjang_minuman++;
                        cout << "menu berhasil di tambahkan" << endl;
                        cout << endl;
                        break;
                    } else{
                        cout << "kapasitas penuh " << endl;
                        cout << endl;
                        break;
                    }
                    }
                    case 4:{
                        cout << endl;
                        cout << "keluar" << endl;
                        cout << endl;
                        goto menu_admin;
                        break;
                    }
                    
                    default:
                    cout << endl;
                        cout << "inputan salah" << endl;
                        cout << endl;
                        break;
                    }   
                        }
                    }

                case 3:{
                    while (true)
                    {
                    cout << "========== EDIT MENU ===========\n";
                    cout << "| " << "[1] MENU PS \n";
                    cout << "| " << "[2] MENU MEKANAN \n";
                    cout << "| " << "[3] MENU MINUMAN \n";
                    cout << "| " << "[4] EXIT \n";
                    cout << "===================================" << endl;
                    cout << "silahkan pilih : ";
                    cin >> pilih_6;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "inputan salah" << endl;
                        cout << endl;
                    }

                    switch (pilih_6)
                    {
                    case 1:{
                        if (panjang_ps == 0){
                            cout << "tidak ada menu yang bisa di update" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_ps; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_ps[i].nama_menu << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_ps){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_ps[index-1].nama_menu);
                            cout << "menu berhasil di ubah" << endl;
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid" << endl;
                            cout << endl;
                            break;
                        }
                        
                        }

                    case 2:{
                        if (panjang_makanan == 0){
                            cout << "tidak ada menu yang bisa di update" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_makanan; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_makanan[i].nama_menu << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_makanan){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_makanan[index-1].nama_menu);
                            cout << "menu berhasil di ubah" << endl;
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid" << endl;
                            cout << endl;
                            break;
                        }
                    }
                    case 3:{
                        if (panjang_minuman == 0){
                            cout << "tidak ada menu yang bisa di update" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_minuman; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_minuman[i].nama_menu << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_minuman){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_minuman[index-1].nama_menu);
                            cout << "menu berhasil di ubah" << endl;
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid" << endl;
                            cout << endl;
                            break;
                        }
                    }
                    case 4:{
                        cout << endl;
                        cout<< "keluar" << endl;
                        cout << endl;
                        goto menu_admin;
                        break;
                    }
    
                    default:
                    cout << "inputan salah \n";
                        break;
                    }
                        
                }
                }
                
                case 4:{
                    while (true)
                    {
                    cout << "========== HAPUS MENU ===========\n";
                    cout << "[1] MENU PS \n";
                    cout << "[2] MENU MEKANAN \n";
                    cout << "[3] MENU MINUMAN \n";
                    cout << "[4] EXIT \n";
                    cout << "silahkan pilih : ";
                    cin >> pilih_7;
                    
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "inputan salah" << endl;
                        cout << endl;
                    }

                    switch (pilih_7)
                    {
                    case 1:{
                        if (panjang_ps == 0){
                            cout << "tidak ada menu yang bisa di hapus" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_ps; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_ps[i].nama_menu << endl;
                            }
                        
                        }
                        cout << "masukkan nomor buah yang akan di Hapus : ";
                        cin >> index;
    
                        if(index > 0 && index <= panjang_ps){
                            for(int i = index - 1; i < panjang_ps - 1; i++){
                                menu_ps[i] = menu_ps[i + 1]; 
                            }
                            panjang_ps--;
                            cout << "menu berhasil di hapus\n";
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid \n";
                            cout << endl;
                            break;
                        }
                    }
                    case 2:{
                        if (panjang_makanan == 0){
                            cout << "tidak ada menu yang bisa di hapus" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_makanan; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_makanan[i].nama_menu << endl;
                            }
                            
                        }
                        cout << "masukkan nomor buah yang akan di Hapus : ";
                        cin >> index;
    
                        if(index > 0 && index <= panjang_makanan){
                            for(int i = index - 1; i < panjang_makanan - 1; i++){
                                menu_makanan[i] = menu_makanan[i + 1]; 
                            }
                            panjang_makanan--;
                            cout << "menu berhasil di hapus\n";
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid \n";
                            cout << endl;
                            break;
                        }
                    }
                    case 3:{
                        if (panjang_minuman == 0){
                            cout << "tidak ada menu yang bisa di hapus" << endl;
                            cout << endl;
                            break;
                        }else{
                            for(int i = 0; i < panjang_minuman; i++){
                                cout << "menu ke " << i + 1 << ": " << menu_minuman[i].nama_menu << endl;
                            }
                            
                        }
                        cout << "masukkan nomor buah yang akan di Hapus : ";
                        cin >> index;
    
                        if(index > 0 && index <= panjang_minuman){
                            for(int i = index - 1; i < panjang_minuman - 1; i++){
                                menu_minuman[i] = menu_minuman[i + 1]; 
                            }
                            panjang_minuman--;
                            cout << "menu berhasil di hapus\n";
                            cout << endl;
                            break;
                        }else{
                            cout << "inputan tidak valid \n";
                            cout << endl;
                            break;
                        }
                    }case 4:{
                        cout << endl;
                        cout << "keluar" << endl;
                        cout << endl;
                        goto menu_admin;
                        break;
                    }
                    default:
                    cout << endl;
                    cout << "inputan salah \n"; 
                    cout << endl;
                        break;
                    }
                }
                
            }
                case 5:{
                    cout << endl;
                    cout << "KEMBALI KE BERANDA" << endl;
                    cout << endl;
                    goto menu;
                    break;
                }

                default:{
                    cout << endl;
                    cout << "inputan apa tu bang?" << endl;
                    cout << endl;
                    break;
                }
            
            
            
        }
    }
        } else {
            mencoba--;
            cout << "login gagal, batas percobaan " << mencoba << endl;
    }  
    }if(!login_sukses){
        cout << "anda sudah melewati batas gagal anda, program berhenti" << endl;
        keluar:
        break;
        return 0;
    }
    
    }else if(pilih_1 == 2){
    int pilihUser;
    bool userLoggedIn = false;
    string userName, userPassword;
    while(true){
        cout << "============ MENU USER ============" << endl;
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
            if(isi < 10){
                cout << "Masukkan username: ";
                cin >> userName;
                cout << "Masukkan password: ";
                cin >> userPassword;
                user[isi].username = userName;
                user[isi].password = userPassword;
                isi++;
                cout << "Registrasi berhasil! Silakan login.\n" << endl;
            } else {
                cout << "Kapasitas pengguna penuh.\n" << endl;
            }
        }
        else if(pilihUser == 2){
            int attempt = 3; // set jumlah percobaan login user
            while(attempt > 0 && !userLoggedIn){
                cout << "Masukkan username: ";
                cin >> userName;
                cout << "Masukkan password: ";
                cin >> userPassword;
                bool found = false;
                // Looping dari 0 sampai jumlah user yang telah terdaftar (isi)
                for(int i = 0; i < isi; i++){
                    if(user[i].username == userName && user[i].password == userPassword){
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
                    attempt--;
                    cout << "Login gagal. Sisa percobaan: " << attempt << endl;
                }
            }
            if(!userLoggedIn){
                cout << "Anda telah melewati batas login. Kembali ke menu utama.\n" << endl;
                goto keluar;
                break;  
            }
        }
        else if(pilihUser == 3){
            break;
        }
        else{
            cout << "Inputan salah.\n" << endl;
        }
        
        
        while(userLoggedIn){
            cout << "============ HALO PEMBELI PS ============" << endl;
            cout << "[1] Pesan PS" << endl;
            cout << "[2] Pesan Makanan" << endl;
            cout << "[3] Pesan Minuman" << endl;
            cout << "[4] Lihat Pesanan" << endl;
            cout << "[5] Exit" << endl;
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
                    
                    if(panjang_ps == 0){
                        cout << "Belum ada menu PS tersedia.\n" << endl;
                    } else {
                        cout << "\n==== Daftar Menu PS ====" << endl;
                        for(int i = 0; i < panjang_ps; i++){
                            cout << i+1 << ". " << menu_ps[i].nama_menu << endl;
                        }
                        cout << "Pilih nomor menu PS yang diinginkan: ";
                        cin >> index;
                        if(index > 0 && index <= panjang_ps){
                            pesanan_ps[pesan_ps++] = menu_ps[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n" << endl;
                        } else {
                            cout << "Nomor tidak valid.\n" << endl;
                        }
                    }
                    break;
                case 2:
                    
                    if(panjang_makanan == 0){
                        cout << "Belum ada menu Makanan tersedia.\n" << endl;
                    } else {
                        cout << "\n==== Daftar Menu Makanan ====" << endl;
                        for(int i = 0; i < panjang_makanan; i++){
                            cout << i+1 << ". " << menu_makanan[i].nama_menu << endl;
                        }
                        cout << "Pilih nomor menu Makanan yang diinginkan: ";
                        cin >> index;
                        if(index > 0 && index <= panjang_makanan){
                            pesanan_makanan[pesan_makanan++] = menu_makanan[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n" << endl;
                        } else {
                            cout << "Nomor tidak valid.\n" << endl;
                        }
                    }
                    break;
                case 3:
                    
                    if(panjang_minuman == 0){
                        cout << "Belum ada menu Minuman tersedia.\n" << endl;
                    } else {
                        cout << "\n==== Daftar Menu Minuman ====" << endl;
                        for(int i = 0; i < panjang_minuman; i++){
                            cout << i+1 << ". " << menu_minuman[i].nama_menu << endl;
                        }
                        cout << "Pilih nomor menu Minuman yang diinginkan: ";
                        cin >> index;
                        if(index > 0 && index <= panjang_minuman){
                            pesanan_minuman[pesan_minuman++] = menu_minuman[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n" << endl;
                        } else {
                            cout << "Nomor tidak valid." << endl;
                        }
                    }
                    break;
                case 4:
                    cout << "\n============ DAFTAR PESANAN ANDA ============" << endl;
                    if(pesan_ps == 0 && pesan_makanan == 0 && pesan_minuman == 0){
                        cout << "Anda belum memesan apa pun." << endl;
                    } else {
                        if(pesan_ps > 0){
                            cout << "Pesanan PS:" << endl;
                            for(int i = 0; i < pesan_ps; i++){
                                cout << i+1 << ". " << pesanan_ps[i].nama_menu << endl;
                            }
                            cout << endl;
                        }
                        if(pesan_makanan > 0){
                            cout << "Pesanan Makanan:" << endl;
                            for(int i = 0; i < pesan_makanan; i++){
                                cout << i+1 << ". " << pesanan_makanan[i].nama_menu << endl;
                            }
                            cout << endl;
                        }
                        if(pesan_minuman > 0){
                            cout << "Pesanan Minuman:" << endl;
                            for(int i = 0; i < pesan_minuman; i++){
                                cout << i+1 << ". " << pesanan_minuman[i].nama_menu << endl;
                            }
                            cout << endl;
                        }
                    }
                    break;
                case 5:
                    cout << "Exit berhasil.\n" << endl;
                    userLoggedIn = false;
                    break;
                default:
                    cout << "Inputan salah.\n" << endl;
                    break;
            }
        }
    } 
}else if(pilih_1 == 3){
    cout << "TERIMAKASIH MENGGUNAKAN PROGRAM INI !^_^! \n";
    cout << "program berhenti \n";
    break;
}else{
    cout << "inputan ngawur" << endl;
    cout << endl;
}

}
return 0;
}
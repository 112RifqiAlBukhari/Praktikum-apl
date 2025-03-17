#include<iostream>
#include<string>
using namespace std;

int main(){

string Syarat_Login[2][2] = { {"rifqi al bukhari", "rifqi"},
                            {"rifqi", "112"}
                            };
string menu_ps[10]; 
string menu_makanan[10];
string menu_minuman[10];
string pesanan_ps[10];
string pesanan_makanan[10];
string pesanan_minuman[10];
int pilih_1,pilih_2,pilih_3,pilih_4,pilih_5,pilih_6,pilih_7,pilih_8,pilih_9,pilih_10;
int index;
int mencoba = 3,panjang_ps= 0,panjang_makanan =0, panjang_minuman = 0;
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

        while(mencoba > 0){
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
                                cout << "|  " << "no " << i + 1 << ": " << menu_ps[i] << "  |" << endl;   }
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
                                cout << "|  " << "no " << i + 1 << ": " << menu_makanan[i] << "  |" << endl;  }
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
                                cout << "|  " << "no " << i + 1 << ": " << menu_minuman[i] << "  |" << endl;                         }
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
                        cout << endl;
                        if(panjang_ps < 10){
                            cout << "masukkan nama menu : ";
                            cin.ignore();
                            getline(cin,menu_ps[panjang_ps]);
                            panjang_ps++;
                            cout << "menu berhasil di tambahkan" << endl;
                            cout << endl;
                            break;
                            } else{
                                cout << "kapasitas penuh " << endl;
                                cout << endl;
                                break;
                                }
                            }

                    case 2:{
                        if(panjang_makanan < 10){
                            cout << "masukkan nama menu : ";
                            cin.ignore();
                            getline(cin,menu_makanan[panjang_makanan]);
                            panjang_makanan++;
                            cout << "menu berhasil di tambahkan" << endl;
                            cout << endl;
                            break;
                            } else{
                            cout << "kapasitas penuh " << endl;
                            cout << endl;
                            break;
                            }
                            }
                    case 3:{
                        if(panjang_minuman < 10){
                        cout << "masukkan nama menu : ";
                        cin.ignore();
                        getline(cin,menu_minuman[panjang_minuman]);
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
                                cout << "menu ke " << i + 1 << ": " << menu_ps[i] << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_ps){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_ps[index-1]);
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
                                cout << "menu ke " << i + 1 << ": " << menu_makanan[i] << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_makanan){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_makanan[index-1]);
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
                                cout << "menu ke " << i + 1 << ": " << menu_minuman[i] << endl;                         
                               }
                        }
                        cout << "masukkan nomor buah yang akan di ubah : ";
                        cin >> index;

                        if(index > 0 && index <= panjang_minuman){
                            cout << " masukkan nama menu baru ";
                            cin.ignore();
                            getline(cin, menu_minuman[index-1]);
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
                                cout << "menu ke " << i + 1 << ": " << menu_ps[i] << endl;
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
                                cout << "menu ke " << i + 1 << ": " << menu_makanan[i] << endl;
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
                                cout << "menu ke " << i + 1 << ": " << menu_minuman[i] << endl;
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
    if(!login_sukses){
            cout << "anda sudah melewati batas gagal anda, program berhenti" << endl;
            return 0;
        }
        
        
    }
    }else if(pilih_1 == 2){
        while (true){
            cout << "============ HALO PEMBELI PSCUUU =========== \n";
            cout << "[1] pesan Ps \n";
            cout << "[2] pesan makanan \n";
            cout << "[3] pesan minum \n";
            cout << "[4] lihat pesanan \n";
            cout << "[5] EXIT  \n";
            cout << "silahkan pilih : ";
            cin >> pilih_3;

            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "inputan salah" << endl;
                cout << endl;
            }

            switch (pilih_3)
            {
            case 1:{
                    if(panjang_ps == 0){
                        cout << "Belum ada menu Ps tersedia." << endl; 
                        cout << endl;
                        break;
                    } else {
                        cout << "\n======== Daftar  PS ========\n";
                        for(int i = 0; i < panjang_ps; i++){
                            cout << i + 1 << ". " << menu_ps[i] << endl;
                        }
                        cout << "Pilih nomor ps yang di inginkan: ";
                        cin >> index;
                        if(index > 0 && index <= panjang_ps){
                            pesanan_ps[pesan_ps++] = menu_ps[index-1];
                            cout << "Pesanan berhasil ditambahkan!\n";
                            cout << endl;
                            break;
                        } else {
                            cout << "Nomor tidak valid.\n";
                            cout << endl;
                            break;
                        }
                    }
                    }
            case 2:{
                if(panjang_makanan == 0){
                    cout << "Belum ada menu makanan tersedia." << endl; 
                    cout << endl;
                } else {
                    cout << "\n======== Daftar m-Menu Makanan ========\n";
                    for(int i = 0; i < panjang_makanan; i++){
                        cout << i + 1 << ". " << menu_makanan[i] << endl;
                    }
                    cout << "Pilih nomor Menu: ";
                    cin >> index;
                    if(index > 0 && index <= panjang_ps){
                        pesanan_makanan[pesan_makanan++] = menu_ps[index-1];
                        cout << "Pesanan berhasil ditambahkan!\n";
                        cout << endl;
                        break;
                    } else {
                        cout << "Nomor tidak valid.\n";
                        cout << endl;
                        break;
                    }
                }
                }
            case 3:{
                if(panjang_minuman == 0){
                    cout << "Belum ada menu ruangan tersedia." << endl; 
                    cout << endl;
                    break;
                } else {
                    cout << "\n======== Daftar RMenu Minuman ========\n";
                    for(int i = 0; i < panjang_minuman; i++){
                        cout << i + 1 << ". " << menu_minuman[i] << endl;
                    }
                    cout << "Pilih nomor Menu: ";
                    cin >> index;
                    if(index > 0 && index <= panjang_minuman){
                        pesanan_minuman[pesan_minuman++] = menu_minuman[index-1];
                        cout << "Pesanan berhasil ditambahkan!\n";
                        cout << endl;
                        break;
                    } else {
                        cout << "Nomor tidak valid.\n";
                        cout << endl;
                        break;
                    }
                }
                
                } 
            case 4:{
                cout << "============ DAFTAR PESANAN ANDA ============\n";
            
                if (pesan_ps == 0 && pesan_makanan == 0 && pesan_minuman == 0) {
                    cout << "Anda belum memesan apa pun.\n";
                    cout << endl;
                    break;
                } else {
                    if (pesan_ps > 0) {
                        cout << "Ruangan PS yang dipesan:\n";
                        for (int i = 0; i < pesan_ps; i++) {
                            cout << i + 1 << ". " << pesanan_ps[i] << endl;
                            cout << endl;
                        }
                    }
            
                    if (pesan_makanan > 0) {
                        cout << "Makanan yang dipesan:\n";
                        for (int i = 0; i < pesan_makanan; i++) {
                            cout << i + 1 << ". " << pesanan_makanan[i] << endl;
                            cout << endl;
                        }
                    }
            
                    if (pesan_minuman > 0) {
                        cout << "Minuman yang dipesan:\n";
                        for (int i = 0; i < pesan_minuman; i++) {
                            cout << i + 1 << ". " << pesanan_minuman[i] << endl;
                            cout << endl;
                        }
                    }
                }
                cout << "=============================================\n";
                cout << endl;
                break;
                }
            case 5:{
                cout << endl;
                cout << "keluar" << endl;
                cout << endl;
                goto menu;
                break;
            }
            default:{
                cout << "inputan salah" << endl;
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
}


}

return 0;
}

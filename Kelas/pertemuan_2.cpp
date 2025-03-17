#include<iostream>
using namespace std;

int main(){
    //  string nama[4] = {"haqi", "dzaki", "melchi"};
    //  int angka[5];
    //  angka[0] = 10;
    //  angka[1] = 19;
    //  angka[2] = 30;
    //  angka[3] = 40;
    //  angka[4] = 50;

    
    // // cout << nama[0] << endl;
    // // cout << angka[2] << endl;
    // // cout << sizeof(angka) << endl;
    // // cout << sizeof(nama) << endl;
    // // int ukuran = sizeof(angka)/sizeof(angka[0]);
    // // cout << "banyak elemen array angka adalah " << ukuran << endl;


    // int ukuran = sizeof(angka)/sizeof(angka[0]);
    // for(int i = 0; i < ukuran; i++){
    //     cout << angka[i] << endl;
    // }

    // for(string y : nama){
    //     cout << y << endl;
    // }


    // int matriks[2][2] = {
    //     {1,2},
    //     {3,4}
    // };

    // cout << matriks[0][1] << endl;
    // cout << matriks[1][1] << endl;
    // cout << matriks[1][0] << endl;
    // cout << matriks[0][0] << endl;

    // int matriks[3][3][3] = {
    //    { {1,2,6},
    //      {3,4,5},
    //      {7,8,9}
    //    },
    //    { {11,12,16},
    //      {13,14,15},
    //      {17,18,19}
    //    },
    //    { {21,22,26},
    //      {23,24,25},
    //      {27,28,29}
    //    }
    // };

    // cout << matriks[0][1][2] << endl;
    // cout << matriks[1][1][2] << endl;
    // cout << matriks[1][0][2] << endl;
    // cout << matriks[0][0][2] << endl;


    int panjang = 0;
    string buah[100];

    int total_array = sizeof(buah) / sizeof(string);
    int pilihan,index;
    do{
        cout << "1. liat buah" << endl;
        cout << "2. tambah buah" << endl;
        cout << "3. edit buah" << endl;
        cout << "4. hapus buah" << endl;
        cin >> pilihan;
        switch (pilihan)

        {
        case 1:
            if(panjang == 0){
                cout << "belom ada buah" << endl;

            }else{
                for(int i =0; i < panjang; i++){
                    cout << i + 1 << ". " << buah[i] << endl; 
                }
            }
            break;
        
        default:
            break;
        }

    }while (pilihan != 5)

}
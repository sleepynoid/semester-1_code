#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
// variabel global
char nama_barang[10][20] = {
    "ikan",
    "ayam",
    "bebek"
};
int harga_barang[10] = {
    16000,
    18000,
    15000
};
int stock_barang[10] = {
    10,
    10,
    10
};
int Index = 2;
// fungsi
void view_barang() {
    printf("List Barang\n");
    for (int i=0; i <= Index; i++) {
        printf("Nama Barang %s\n",nama_barang[i]);
        printf("Harga Barang : %d\n",harga_barang[i]);
        printf("Stock Barang : %d\n",stock_barang[i]);
    }
}
void tambah_barang() {
    Index++;
    printf("Masukan Nama Barang : ");
    scanf("%s",&nama_barang[Index][0]);
    printf("Masukan Harga Barang : ");
    scanf("%d",&harga_barang[Index]);
    printf("Masukan Stock Barang: ");
    scanf("%d",&stock_barang[Index]);
}
void delete_barang() {
    char _delete[20];
    printf("Masukan Barang yang dihapus : ");
    scanf("%s",&_delete[0]);
    int _find_delete = 0;
    for (int l=0,n=0; l <= Index; l++) {
        if ((strcmp(_delete,nama_barang[l])) != 0) {
            printf("barang #%d ke #%d %s\n",l,n,nama_barang[l]);
            strcpy(nama_barang[n],nama_barang[l]);
            n++,_find_delete++;
        }
    }
    (_find_delete <= Index)? Index--:printf("Maaf Barang %s Tidak ada\n",_delete);
}
int search_by_name(string name){
    int temp_index = -1;
    for (int i = 0 ; i <= Index ; i++){
        if (name == nama_barang[i]){
            temp_index = i;
        }
    }
    return temp_index;
}
void update_barang() {
    printf("Masukan Nama Barang yang akan di Update : ");
    char nama[20];
    scanf("%s",nama);
    int n,temp_index = search_by_name(nama);
    printf("Masukan Stock %s = ",nama);
    scanf("%d",&n);
    (temp_index != -1)? stock_barang[temp_index] = n:printf("Maaf Barang %s tidak tersedia\n",nama);
    // if (temp_index != -1) {
    //     printf("Masukan Stock %s = ",nama);
    //     scanf("%d",&n);
    //     stock_barang[temp_index] = n;
    // }
    // else {
    //     printf("Maaf Barang %s tidak tersedia\n",nama);
    // }
}
int transaksi(string name,int banyak_benda) {
    printf("nama barang %s, banyak %d",name.c_str(),banyak_benda);
    
    return banyak_benda;
}

int main() {
    printf("MENU PROGRAM\n");
    printf("1. view all BARANG\n");
    printf("2. tambah BARANG\n");
    printf("3. delete BARANG\n");
    printf("4. update stok BARANG\n");
    printf("5. transaksi\n");
    printf("5. EXIT\n");
    int pilihan;
    while (pilihan != 5) {
        printf("Masukan Pilihan Anda : ");
        scanf("%d",&pilihan);
        switch (pilihan) {
        case 1:
            view_barang();
            break;
        case 2:
            tambah_barang();
            break;
        case 3:
            delete_barang();
            break;
        case 4:
            update_barang();
            break;
        case 5:
            printf("Masukan Nama Barang : ");
            string name;
            cin >> name;
            int n = search_by_name(name);
            printf("Masukan Jumlah Barang : ");
            scanf("%d",&n);
            if (n != -1) {
                transaksi(name, n);
            }
            break;
        }
    }
}

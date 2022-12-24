#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char nama_barang[10][20] = {
    "Ikan",
    "ayam",
    "bebek"
};
int harga_barang[10] = {
    5000,
    10000,
    18000
};
int stock_barang[10] = {
    10,
    10,
    10
};
int Index = 2;
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
int main() {
    printf("MENU PROGRAM\n");
    printf("1. view all BARANG\n");
    printf("2. tambah BARANG\n");
    printf("3. delete BARANG\n");
    printf("4. update stok BARANG\n");
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
        }
    }
}

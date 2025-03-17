#include "linkedlist.h"

int main() {
    List L1, L2;
    char nama[50];
    infotype nilaiUTS;
    int jumlahMahasiswa;

    CreateList(&L1);
    CreateList(&L2);

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlahMahasiswa);

    // Memasukkan data mahasiswa ke dalam list L1
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("\nMasukkan data mahasiswa ke-%d:\n", i + 1);
        printf("Nama: ");
        scanf("%s", nama);  
        printf("Nilai UTS: ");
        scanf("%d", &nilaiUTS); 

        InsertAscendingByNama(&L1, nama, nilaiUTS);
    }

    printf("\nIsi List L1 (Ascending by Nama):\n");
    PrintListAscendingByNama(L1);

    printf("\nIsi List L1 (Descending by Nilai):\n");
    PrintListDescendingByNilai(L1);

    int jumlah = CountElement(L1); // jumlah Elemen yang ada pada List 1
    printf("\nJumlah elemen dalam List L1: %d\n", jumlah);

    CopyList(&L1, &L2, 70); // Isi List 2
    printf("\nIsi List L2 setelah copy dari L1 (Nilai > 70):\n");
    PrintList(L2);

    RemoveDuplicates(&L2); // Isi List 2 setelah duplikasi
    printf("\nIsi List L2 setelah menghapus duplikat:\n");
    PrintList(L2);

    DeleteList(&L1); 
    DeleteList(&L2);

    return 0;
}
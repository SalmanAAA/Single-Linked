#include "linkedlist.h"

// Constructor untuk membuat list kosong
void CreateList(List *L) {
    L->First = NULL;
}

//Destructor untuk menghapus seluruh elemen list
void DeleteList(List *L) {
    address P = L->First;
    while (P != NULL) {
        address Q = P;
        P = P->next;
        free(Q);  // Dealokasi memori
    }
    L->First = NULL;
}

//Validator untuk memeriksa apakah list kosong
int IsEmpty(List L) {
    return L.First == NULL;
}

//Setter untuk mengisi data mahasiswa
void SetMahasiswa(address P, char *nama, infotype nilaiUTS) {
    strcpy(P->nama, nama);  // Menggunakan strcpy untuk menyalin nama
    P->nilaiUTS = nilaiUTS;
}

//PrintObject untuk menampilkan isi list
void PrintList(List L) {
    address P = L.First;
    while (P != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", P->nama, P->nilaiUTS);
        P = P->next;
    }
}

//Insert elemen secara ascending berdasarkan nama
void InsertAscendingByNama(List *L, char *nama, infotype nilaiUTS) {
    address P = (address)malloc(sizeof(ElmtList));  // Alokasi memori untuk elemen baru
    if (P == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    SetMahasiswa(P, nama, nilaiUTS);  // Mengisi data mahasiswa
    P->next = NULL;

    if (IsEmpty(*L) || strcmp(nama, L->First->nama) < 0) {
        P->next = L->First;
        L->First = P;
    } else {
        address Q = L->First;
        while (Q->next != NULL && strcmp(Q->next->nama, nama) < 0) {
            Q = Q->next;
        }
        P->next = Q->next;
        Q->next = P;
    }
}

//Insert elemen secara descending berdasarkan nilai
void InsertDescendingByNilai(List *L, char *nama, infotype nilaiUTS) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    SetMahasiswa(P, nama, nilaiUTS);  //Mengisi data mahasiswa
    P->next = NULL;

    if (IsEmpty(*L) || nilaiUTS > L->First->nilaiUTS) {
        //Jika list kosong atau elemen baru menjadi elemen pertama
        P->next = L->First;
        L->First = P;
    } else {
        //Jika tidak cari posisi yang tepat untuk elemen baru
        address Q = L->First;
        while (Q->next != NULL && Q->next->nilaiUTS > nilaiUTS) {
            Q = Q->next;
        }
        P->next = Q->next;
        Q->next = P;
    }
}

//Menghitung jumlah elemen dalam list
int CountElement(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

//Menyalin elemen dengan nilai > threshold ke list lain
void CopyList(List *L1, List *L2, infotype threshold) {
    address P = L1->First;
    while (P != NULL) {
        if (P->nilaiUTS > threshold) {
            InsertAscendingByNama(L2, P->nama, P->nilaiUTS);
        }
        P = P->next;
    }
}

//Menghapus duplikat berdasarkan nama
void RemoveDuplicates(List *L) {
    address P = L->First;
    while (P != NULL && P->next != NULL) {
        if (strcmp(P->nama, P->next->nama) == 0) {
            // Jika nama sama, hapus elemen berikutnya
            address Q = P->next;
            P->next = Q->next;
            free(Q);
        } else {
            // Jika tidak lanjut
            P = P->next;
        }
    }
}

//Menampilkan list ascending berdasarkan nama
void PrintListAscendingByNama(List L) {
    List sortedList;
    CreateList(&sortedList);

    //Salin elemen dari list L ke sortedList dengan urutan ascending berdasarkan nama
    address P = L.First;
    while (P != NULL) {
        InsertAscendingByNama(&sortedList, P->nama, P->nilaiUTS);
        P = P->next;
    }

    //Tampilkan isi sortedList
    PrintList(sortedList);

    //Hapus sortedList setelah digunakan
    DeleteList(&sortedList);
}

//Menampilkan list descending berdasarkan nilai
void PrintListDescendingByNilai(List L) {
    //Buat list sementara untuk menyimpan elemen yang sudah diurutkan
    List sortedList;
    CreateList(&sortedList);

    //Salin elemen dari list L ke sortedList dengan urutan descending berdasarkan nilai
    address P = L.First;
    while (P != NULL) {
        InsertDescendingByNilai(&sortedList, P->nama, P->nilaiUTS);
        P = P->next;
    }

    //Tampilkan isi sortedList
    PrintList(sortedList);

    //Hapus sortedList setelah digunakan
    DeleteList(&sortedList);
}
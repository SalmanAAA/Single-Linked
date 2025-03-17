#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef int infotype;

typedef struct tElmtList *address;
typedef struct tElmtList {
    char nama[50];  // Menyimpan nama mahasiswa
    infotype nilaiUTS;  // Menyimpan nilai UTS
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

void CreateList(List *L);  //Constructor
void DeleteList(List *L);  //Destructor
int IsEmpty(List L);       //Validator
void SetMahasiswa(address P, char *nama, infotype nilaiUTS);  //Setter
void PrintList(List L);  


void InsertAscendingByNama(List *L, char *nama, infotype nilaiUTS);  //Insert elemen secara ascending berdasarkan nama
void InsertDescendingByNilai(List *L, char *nama, infotype nilaiUTS);  //Insert elemen secara descending berdasarkan nilai
int CountElement(List L);  //Menghitung jumlah elemen dalam list
void CopyList(List *L1, List *L2, infotype threshold);  //Menyalin elemen dengan nilai > threshold ke list lain
void RemoveDuplicates(List *L);  //Menghapus duplikat berdasarkan nama

void PrintListAscendingByNama(List L);  //Menampilkan list ascending berdasarkan nama
void PrintListDescendingByNilai(List L);  //Menampilkan list descending berdasarkan nilai

#endif
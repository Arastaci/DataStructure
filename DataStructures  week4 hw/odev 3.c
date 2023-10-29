/* ��renci bilgilerini ekrana yazd�ran fonksiyonu yaz�n�z. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct yap�s�
	struct Ogrenci {
    char ad[50];
   	int yas;
    int numara;
    struct Ogrenci* next;
}Ogrenci;

// Yeni ��renci i�in node olu�turma
struct Ogrenci* yeniOgrenci(char ad[50], int yas, int numara) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    ogrenci->yas = yas;
    ogrenci->numara = numara;
    ogrenci->next = NULL;
    return ogrenci;
}

// ��renci bilgilerini ekrana yazd�ran fonksiyon
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Yas: %d\n", ogrenci->yas);
    printf("Numara: %d\n", ogrenci->numara);
    }

// Ba�l� listeye ��renci ekleme 
void ogrenciEkle(struct Ogrenci** headRef, struct Ogrenci* yeniOgrenci) {
    yeniOgrenci->next = *headRef;
    *headRef = yeniOgrenci;
}

// T�m ��renci bilgilerini ekrana yazd�r
void tumOgrencileriYazdir(struct Ogrenci* head) {
    struct Ogrenci* current = head;
    while (current != NULL) {
        ogrenciYazdir(current);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Ogrenci* ogrenci1 = yeniOgrenci("Saliha", 27, 201);
    struct Ogrenci* ogrenci2 = yeniOgrenci("Ece", 19, 203);

    // Ba�l� listeye ��rencileri ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // T�m ��renci bilgilerini ekrana yazd�r
    tumOgrencileriYazdir(head);

    return 0;
}


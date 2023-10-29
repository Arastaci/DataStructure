/* Öðrenci bilgilerini ekrana yazdýran fonksiyonu yazýnýz. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct yapýsý
	struct Ogrenci {
    char ad[50];
   	int yas;
    int numara;
    struct Ogrenci* next;
}Ogrenci;

// Yeni öðrenci için node oluþturma
struct Ogrenci* yeniOgrenci(char ad[50], int yas, int numara) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    ogrenci->yas = yas;
    ogrenci->numara = numara;
    ogrenci->next = NULL;
    return ogrenci;
}

// Öðrenci bilgilerini ekrana yazdýran fonksiyon
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Yas: %d\n", ogrenci->yas);
    printf("Numara: %d\n", ogrenci->numara);
    }

// Baðlý listeye öðrenci ekleme 
void ogrenciEkle(struct Ogrenci** headRef, struct Ogrenci* yeniOgrenci) {
    yeniOgrenci->next = *headRef;
    *headRef = yeniOgrenci;
}

// Tüm öðrenci bilgilerini ekrana yazdýr
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

    // Baðlý listeye öðrencileri ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // Tüm öðrenci bilgilerini ekrana yazdýr
    tumOgrencileriYazdir(head);

    return 0;
}


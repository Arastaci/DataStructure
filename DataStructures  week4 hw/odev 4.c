/* Listede ��renci ad�na g�re kay�t arama yapan fonksiyonu yaz�n�z. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct yap�s�
struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
    struct Ogrenci* next;
};

// Yeni ��renci nodeu olu�tur
struct Ogrenci* yeniOgrenci(char ad[50], char soyad[50], int numara) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    strcpy(ogrenci->soyad, soyad);
    ogrenci->numara = numara;
    ogrenci->next = NULL;
    return ogrenci;
}

// ��renci ekle
void ogrenciEkle(struct Ogrenci** headRef, struct Ogrenci* yeniOgrenci) {
    yeniOgrenci->next = *headRef;
    *headRef = yeniOgrenci;
}

// ��renci ad�na g�re kay�t ara
struct Ogrenci* ogrenciAra(struct Ogrenci* head, char arananAd[50]) {
    struct Ogrenci* current = head;
    while (current != NULL) {
        if (strcmp(current->ad, arananAd) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Aranan ad bulunamazsa NULL d�nd�r
}

// ��renci bilgilerini ekrana yazd�ran fonksiyon
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Soyad: %s\n", ogrenci->soyad);
    printf("Numara: %d\n", ogrenci->numara);
}

int main() {
    struct Ogrenci* ogrenci1 = yeniOgrenci("Esat", "Arastaci", 231020);
    struct Ogrenci* ogrenci2 = yeniOgrenci("Mehmet", "Aras", 231021);

    // Listeye ��renci ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // Aramak istedi�in ad� gir
	char arananAd[50] = "Ali";
    struct Ogrenci* bulunanOgrenci = ogrenciAra(head, arananAd);

    if (bulunanOgrenci != NULL) {
        ogrenciYazdir(bulunanOgrenci);
    } else {
        printf("Aranan isimde bir ogrenci bulunamadi.\a\n");
    }

    free(ogrenci1);
    free(ogrenci2);

    return 0;
}


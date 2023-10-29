/* Listede aranan öðrenci adýnýn yer aldýðý düðümden bir sonraki düðümü silen fonksiyonu yazýnýz*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct yapýsý
struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
    float ortalama;
    struct Ogrenci* next;
};

// Yeni öðrenci nodeu oluþtur
struct Ogrenci* yeniOgrenci(char ad[50], char soyad[50], int numara) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    strcpy(ogrenci->soyad, soyad);
    ogrenci->numara = numara;
    ogrenci->next = NULL;
    return ogrenci;
}

// Öðrenci ekle
void ogrenciEkle(struct Ogrenci** headRef, struct Ogrenci* yeniOgrenci) {
    yeniOgrenci->next = *headRef;
    *headRef = yeniOgrenci;
}

// Öðrenci adýna göre kayýt ara
struct Ogrenci* ogrenciAra(struct Ogrenci* head, char arananAd[50]) {
    struct Ogrenci* current = head;
    while (current != NULL) {
        if (strcmp(current->ad, arananAd) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Aranan ad bulunamazsa NULL döndür
}

// Öðrenci yazdýr
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Soyad: %s\n", ogrenci->soyad);
    printf("Numara: %d\n", ogrenci->numara);
}

// Belirtilen nodeu listeden çýkar 
//?
void dugumuSil(struct Ogrenci** headRef, struct Ogrenci* silinecekDugum) {
    if (*headRef == NULL) {
        return;
    }

    if (*headRef == silinecekDugum) {
        *headRef = silinecekDugum->next;
        free(silinecekDugum);
        return;
    }

    struct Ogrenci* current = *headRef;
    while (current->next != NULL && current->next != silinecekDugum) {
        current = current->next;
    }

    if (current->next == NULL) {
        return; //düðüm bulunamadi
    }

    current->next = silinecekDugum->next;
    free(silinecekDugum);
}

int main() {
    struct Ogrenci* ogrenci1 = yeniOgrenci("Esat", "Arastaci", 231020);
    struct Ogrenci* ogrenci2 = yeniOgrenci("Mehmet", "Aras", 231021);

    // Baðlý listeye öðrencileri ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // Öðrenci adýna göre arama yap
    char arananAd[50] = "Esat";
    struct Ogrenci* bulunanOgrenci = ogrenciAra(head, arananAd);

    if (bulunanOgrenci != NULL) {
        printf("Aranan ogrencinin bilgileri:\n");
        printf("===========================\n");
        ogrenciYazdir(bulunanOgrenci);

        // Düðümü sil
        dugumuSil(&head, bulunanOgrenci);

        printf("\n%s isimli ogrenci listeden silindi.\a\n", arananAd);
    } else {
        printf("Aranan isimde bir ogrenci bulunamadi.\a\n");
    }

    // Geri kalan öðrenci bilgilerini ekrana yazdýr
    printf("\nKalan ogrenci bilgileri:\n");
    printf("========================\n");
    while (head != NULL) {
        ogrenciYazdir(head);
        head = head->next;
        printf("\n");
    }

    // Belleði temizle
    free(ogrenci1);
    free(ogrenci2);

    return 0;
}


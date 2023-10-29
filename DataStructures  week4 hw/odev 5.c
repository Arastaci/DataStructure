/* Listede aranan ��renci ad�n�n yer ald��� d���mden bir sonraki d���m� silen fonksiyonu yaz�n�z*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct yap�s�
struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
    float ortalama;
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

// ��renci yazd�r
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Soyad: %s\n", ogrenci->soyad);
    printf("Numara: %d\n", ogrenci->numara);
}

// Belirtilen nodeu listeden ��kar 
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
        return; //d���m bulunamadi
    }

    current->next = silinecekDugum->next;
    free(silinecekDugum);
}

int main() {
    struct Ogrenci* ogrenci1 = yeniOgrenci("Esat", "Arastaci", 231020);
    struct Ogrenci* ogrenci2 = yeniOgrenci("Mehmet", "Aras", 231021);

    // Ba�l� listeye ��rencileri ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // ��renci ad�na g�re arama yap
    char arananAd[50] = "Esat";
    struct Ogrenci* bulunanOgrenci = ogrenciAra(head, arananAd);

    if (bulunanOgrenci != NULL) {
        printf("Aranan ogrencinin bilgileri:\n");
        printf("===========================\n");
        ogrenciYazdir(bulunanOgrenci);

        // D���m� sil
        dugumuSil(&head, bulunanOgrenci);

        printf("\n%s isimli ogrenci listeden silindi.\a\n", arananAd);
    } else {
        printf("Aranan isimde bir ogrenci bulunamadi.\a\n");
    }

    // Geri kalan ��renci bilgilerini ekrana yazd�r
    printf("\nKalan ogrenci bilgileri:\n");
    printf("========================\n");
    while (head != NULL) {
        ogrenciYazdir(head);
        head = head->next;
        printf("\n");
    }

    // Belle�i temizle
    free(ogrenci1);
    free(ogrenci2);

    return 0;
}


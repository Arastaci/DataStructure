/* Listede en uzun ismin olduğu kaydı yazdıran fonksiyonu yazınız. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct yapýsý
struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
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

// En uzun ismi bul
struct Ogrenci* enUzunIsimliOgrenci(struct Ogrenci* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Ogrenci* enUzunIsimli = head;
    int maxUzunluk = strlen(head->ad);

    struct Ogrenci* current = head->next;
    while (current != NULL) {
        int uzunluk = strlen(current->ad);
        if (uzunluk > maxUzunluk) {
            maxUzunluk = uzunluk;
            enUzunIsimli = current;
        }
        current = current->next;
    }

    return enUzunIsimli;
}

//Ýsimler ayný ise soyismi karþýlaþtýrsýn
//ekstra eklemek istedim
void soyisimkiyasi(struct Ogrenci ogrenci1, struct Ogrenci ogrenci2) {
    int len1 = strlen(ogrenci1.soyad);
    int len2 = strlen(ogrenci2.soyad);

    if (strcmp(ogrenci1.ad, ogrenci2.ad) == 0) {
        if (len1 > len2) {
            printf("%s %s\n", ogrenci1.ad, ogrenci1.soyad);
        } else if (len1 < len2) {
            printf("%s %s\n", ogrenci2.ad, ogrenci2.soyad);
        } else {
            printf("Isimler ve soyisimler esit.\n");
        }
    } else {
        printf("Isimler esit degil.\n");
    }
}

// Öðrenci bilgilerini ekrana yazdýr
void ogrenciYazdir(struct Ogrenci* ogrenci) {
    printf("Ad: %s\n", ogrenci->ad);
    printf("Soyad: %s\n", ogrenci->soyad);
    printf("Numara: %d\n", ogrenci->numara);
    printf("Uzunluk: %d\n", strlen(ogrenci->ad));
}

int main() {
    struct Ogrenci* ogrenci1 = yeniOgrenci("Esat", "Arastaci", 231020);
    struct Ogrenci* ogrenci2 = yeniOgrenci("Abdurrahmangazi", "Null", 231021);


    //öðrenci ekle
    struct Ogrenci* head = NULL;
    ogrenciEkle(&head, ogrenci1);
    ogrenciEkle(&head, ogrenci2);

    // En uzun isme sahip öðrenci
    struct Ogrenci* enUzunIsimli = enUzunIsimliOgrenci(head);

    if (enUzunIsimli != NULL) {
        printf("En uzun isme sahip ogrenci:\n");
        ogrenciYazdir(enUzunIsimli);
    } else {
        printf("Listede ogrenci bulunamadi.\a\n");
    }
 	// soyisimkiyasi(ogrenci1, ogrenci2); kafam karýþtý burada kalsýn
    free(ogrenci1);
    free(ogrenci2);

    return 0;
}


/* Klavyeden -1 girilinceye kadar girilen tek sayýlarý listenin baþýna, çift sayýlarý ise listenin sonuna
ekleyen fonksiyonu yazýnýz. */


#include <stdio.h>
#include <stdlib.h>

//Struct tanýmlamasý
struct Node {
    int data;
    struct Node* next;
}Node;

struct List {
    struct Node* head;
    struct Node* tail;
};

// Yeni node oluþturma 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Tek sayýlarý listenin baþýna, çift sayýlarý listenin sonuna ekle
void ekleTekCift(struct List* list, int data) {
    struct Node* newNode = createNode(data);

    if (data % 2 == 1) {
        // Eðer tek sayý ise baþa ekle
        if (list->head == NULL) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            newNode->next = list->head;
            list->head = newNode;
        }
    } else {
        // Eðer çift sayý ise sona ekle
        if (list->tail == NULL) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }
}
//Listeyi yazdýr
void printList(struct List* list) {
    struct Node* iter = list->head;
    while (iter != NULL) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

int main() {
    struct List liste;
    liste.head = NULL;
    liste.tail = NULL;

    int sayi;

    while (true) {
        printf("Listeye eklemek istediginiz sayilari giriniz (Cikis icin -1 yaziniz): ");
        scanf("%d", &sayi);

        if (sayi == -1)
            break;

        ekleTekCift(&liste, sayi);
    }

    printf("Liste: ");
    printList(&liste);

    return 0;
}


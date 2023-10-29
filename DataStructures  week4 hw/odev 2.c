/* Rastgele üretilmiþ 100 sayýyý baðlý listeye küçükten büyüðe doðru sýralý þekilde 
ekleyen fonksiyonu yazýnýz. */

#include <stdio.h>
#include <stdlib.h>

//Struct tanýmlamasý
struct Node {
    int data;
    struct Node* next;
}Node;

//Node oluþturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//insertSorted fonksiyonu
void insertSorted(struct Node** headRef, struct Node* newNode) {
    struct Node* current;
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Listeyi yazdýrma fonskyionu
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

 
    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % 1000; // 0 ile 999 arasýnda rastgele sayý üret
        struct Node* newNode = createNode(randomNumber);
        insertSorted(&head, newNode);
    }

 
    printf("Sirali Bagli Liste:\n");
    printList(head);

    return 0;
}


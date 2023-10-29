/* Rastgele �retilmi� 100 say�y� ba�l� listeye k���kten b�y��e do�ru s�ral� �ekilde 
ekleyen fonksiyonu yaz�n�z. */

#include <stdio.h>
#include <stdlib.h>

//Struct tan�mlamas�
struct Node {
    int data;
    struct Node* next;
}Node;

//Node olu�turma
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

//Listeyi yazd�rma fonskyionu
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
        int randomNumber = rand() % 1000; // 0 ile 999 aras�nda rastgele say� �ret
        struct Node* newNode = createNode(randomNumber);
        insertSorted(&head, newNode);
    }

 
    printf("Sirali Bagli Liste:\n");
    printList(head);

    return 0;
}


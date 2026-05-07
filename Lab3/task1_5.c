#include <stdio.h>
#include <stdlib.h>

// Структура для узла двунаправленного связного списка
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Функция для добавления узла в конец списка
struct Node *append(struct Node *head, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = head;

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;

    return head;
}

// Прямой обход списка
void printForward(struct Node *node) {
    printf("Forward traversal:  ");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Обратный обход списка
void printBackward(struct Node *node) {
    struct Node *last = node;
    if (node == NULL)
        return;

    while (last->next != NULL) {
        last = last->next;
    }

    printf("Backward traversal: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

// Освобождение выделенной памяти
void freeList(struct Node *node) {
    struct Node *temp;
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main(void) {
    struct Node *head = NULL;

    // Заполнение списока числами
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 40);

    // Вывод значений в обоих направлениях
    printForward(head);
    printBackward(head);

    // Очищистка памяти
    freeList(head);

    return 0;
}
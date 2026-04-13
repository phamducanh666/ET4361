#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// Mảng các con trỏ buckets (chỉ sử dụng nội bộ trong file này)
struct Node *buckets[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }
}

unsigned int hash(char *str) {
    unsigned int hashValue = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hashValue = hashValue * 31 + str[i];
    }
    return hashValue % TABLE_SIZE;
}

void insert(char *name, char *phone) {
    unsigned int index = hash(name);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    
    newNode->next = buckets[index];
    buckets[index] = newNode;
    printf("Da them: %-15s - %s (Bucket %d)\n", name, phone, index);
}

void search(char *name) {
    unsigned int index = hash(name);
    struct Node *temp = buckets[index];
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("[Tim kiem] Tim thay: %s - SDT: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("[Tim kiem] Khong tim thay lien he: %s\n", name);
}

void delete(char *name) {
    unsigned int index = hash(name);
    struct Node *temp = buckets[index];
    struct Node *prev = NULL;
    
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("[Xoa] Khong tim thay lien he de xoa: %s\n", name);
        return;
    }
    
    if (prev == NULL) {
        buckets[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("[Xoa] Da xoa thanh cong: %s\n", name);
}

void printTable() {
    printf("\n--- BANG BAM HIEN TAI ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node *temp = buckets[i];
        while (temp != NULL) {
            printf("[%s] -> ", temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("-------------------------\n\n");
}

// Cài đặt hàm giải phóng toàn bộ bộ nhớ của bảng băm
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *temp = buckets[i];
        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp); // Giải phóng từng node trong danh sách liên kết
            temp = next;
        }
        buckets[i] = NULL;
    }
    printf("[He thong] Da giai phong toan bo bo nho Hash Table.\n");
}

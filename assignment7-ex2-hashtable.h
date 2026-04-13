#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10

// Khai báo kiểu dữ liệu Node
struct Node {
    char name[50];
    char phone[20];
    struct Node *next;
};

// Nguyên mẫu các hàm giao tiếp
void initTable();
unsigned int hash(char *str);
void insert(char *name, char *phone);
void search(char *name);
void delete(char *name);
void printTable();
void freeTable(); // Hàm giải phóng bộ nhớ theo yêu cầu

#endif

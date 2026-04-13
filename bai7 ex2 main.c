#include <stdio.h>
#include "hashtable.h" // Nhúng thư viện tự tạo

int main() {
    initTable();
    
    printf("1. Kiem thu chèn du lieu:\n");
    insert("Nguyen Van A", "0901234567");
    insert("Tran Thi B", "0912345678");
    insert("Le Van C", "0923456789");
    insert("Pham Thi D", "0934567890");
    insert("Hoang Van E", "0945678901");
    insert("Vu Thi F", "0956789012");
    insert("Ngo Van G", "0967890123");
    insert("Do Thi H", "0978901234");
    
    printTable();
    
    printf("2. Kiem thu tim kiem:\n");
    search("Le Van C");
    search("Hoang Van E");
    search("Ton That X"); // Không tồn tại
    printf("\n");
    
    printf("3. Kiem thu xoa:\n");
    delete("Nguyen Van A");
    delete("Vu Thi F");
    printTable();
    
    // 4. Giải phóng bộ nhớ trước khi kết thúc chương trình
    freeTable();
    
    return 0;
}

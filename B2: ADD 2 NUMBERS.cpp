      --- BAI GIAI ---
        
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); // khoi tao nut gia tren stack de lam diem tua
    ListNode* curr = &dummy; // node chay cho ca 2 danh sach
    int carry = 0; // bien nho de cho truong hop tong 2 so >= 10
    
    // khi 1 trong danh sach con chua het node hoac carry chua ve 0
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int val1 = (l1 != nullptr) ? l1->val : 0; // 0 + const = const (truong hop 1 dslk da het node)
        int val2 = (l2 != nullptr) ? l2->val : 0; // 0 + const = const

        int sum = val1 + val2 + carry;
        carry = sum / 10; // lay phan chuc de lam bien nho cho lan sau
        int digit = sum % 10; // lay phan don vi de tao node moi
        
        curr->next = new ListNode(digit); // tao node moi va noi vao danh sach ket qua

      // di chuyen de xet tiep
        curr = curr->next;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2= l2->next;
    }
    return dummy.next;
}


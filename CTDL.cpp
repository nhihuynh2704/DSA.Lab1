#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    if (head == nullptr) return nullptr;

   
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    
    int middleIndex = count / 2;
    temp = head;

   
    for (int i = 0; i < middleIndex; i++) {
        temp = temp->next;
    }

    return temp; // Return the middle node
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    
    ListNode* middleNode = findMiddle(head);

    
    cout << "The value of the middle node is " << middleNode->val << endl; 

    
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

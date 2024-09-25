#include <iostream>
using namespace std;

// Definition of the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify the merging process
    ListNode dummy(0);
    ListNode* tail = &dummy; // Pointer to the last node in the merged list

    // Iterate through both lists
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1; // Append l1 node to the merged list
            l1 = l1->next;   // Move to the next node in l1
        }
        else {
            tail->next = l2; // Append l2 node to the merged list
            l2 = l2->next;   // Move to the next node in l2
        }
        tail = tail->next; // Move the tail pointer
    }

    // If there are remaining nodes in either list, append them
    if (l1 != nullptr) {
        tail->next = l1;
    }
    else {
        tail->next = l2;
    }

    return dummy.next; // Return the merged list, skipping the dummy node
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Creating the first sorted linked list: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // Creating the second sorted linked list: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Merging the two sorted linked lists
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Printing the merged linked list
    cout << "Merged sorted linked list: ";
    printList(mergedList);

    // Cleanup memory (not shown for brevity)
    // Remember to free the allocated memory for the linked lists after use
    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visitedNodes; // Set to store visited nodes

    ListNode* current = head;
    while (current != nullptr) {
        // If the current node is already in the set, there is a cycle
        if (visitedNodes.find(current) != visitedNodes.end()) {
            return true; // Cycle detected
        }
        // Add the current node to the set
        visitedNodes.insert(current);
        current = current->next; // Move to the next node
    }

    return false; // No cycle found
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating a cycle for testing: 5 -> 3
    head->next->next->next->next->next = head->next->next; // Cycle created

    // Detect if there is a cycle
    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    }
    else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Cleanup memory (this part is tricky due to the cycle)
    // For simplicity, we are not freeing memory here since it would lead to infinite loop.
    return 0;
}

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        // If there's only one node, return it as a TreeNode
        if (head->next == nullptr)
            return new TreeNode(head->val);
        
        // Use two pointers to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;
        
        while (fast && fast->next) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow is the middle node, so it will be the root
        TreeNode* root = new TreeNode(slow->val);
        
        // Disconnect the left half from the middle
        if (slow_prev)
            slow_prev->next = nullptr;
        
        // Recursively build the left and right subtrees
        root->left = sortedListToBST(head);      // Left half
        root->right = sortedListToBST(slow->next);  // Right half
        
        return root;
    }
};

// Helper function to print the binary tree (for testing purposes)
void preOrder(TreeNode* node) {
    if (!node)
        return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage
    int arr[] = {-10, -3, 0, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createLinkedList(arr, size);
    
    Solution solution;
    TreeNode* bst_root = solution.sortedListToBST(head);
    
    cout << "PreOrder Traversal of the constructed BST:" << endl;
    preOrder(bst_root);  // Expected output: 0 -10 -3 5 9
    
    return 0;
}


#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand()

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
    vector<int> arr;

public:
    Solution(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            arr.push_back(temp->val); // Store the node values in a vector
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int n = arr.size();
        int random_index = rand() % n; // Generate a random index
        return arr[random_index];
    }
};

// Main function to create a linked list and test the Solution class
int main()
{
    // Seed the random number generator
    srand(time(0));

    // Creating a simple linked list: 1 -> 2 -> 3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Instantiate the solution with the linked list head
    Solution solution(head);

    // Get a random node's value
    cout << "Random node value: " << solution.getRandom() << endl;

    // Clean up memory
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}

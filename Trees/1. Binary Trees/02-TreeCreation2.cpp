#include <iostream>
#include <vector>
using namespace std;

class Node {
    public: 
    int data;
    Node *left, *right;

    Node (int data)
    {
        this -> data = data;
        left = right = NULL;
    }
};

class Solution {
    public:
    Node* buildBinaryTree()
    {
        int val;
        cin >> val;

        if (val == -1)
            return NULL;

        Node* temp = new Node(val);

        // Create Left Subtree
        cout << "Enter the value of left child of " << temp -> data << ": ";
        temp -> left = buildBinaryTree();

        // Create Right Subtree
        cout << "Enter the value of right child of " << temp -> data << ": ";
        temp -> right = buildBinaryTree();

        return temp;
    }
};

int main()
{
    int val;

    cout << "Enter the value of root node: ";
    // Solution().buildBinaryTree();

    Solution obj = Solution();
    obj.buildBinaryTree();
}
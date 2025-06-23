#include <iostream>
#include <queue>
using namespace std;

class Node {
    int data;
    Node *left, *right;

    public:
    Node(int data)
    {
        this -> data = data;
        left = right = NULL;
    }

    // Getters
    int getData() {
        return this -> data;
    }

    Node* getLeft() {
        return this -> left;
    }

    Node* getRight() {
        return right;
    }

    // Setters
    void setData(int data) {
        this -> data = data;
    }

    void setLeft(Node *left) {
        this -> left = left;
    }

    void setRight(Node *right) {
        this -> right = right;
    }
};

int main()
{
    int val;
    queue<Node *> q;

    cout << "Enter the value of root node: ";
    cin >> val;

    Node *root = new Node(val);
    q.push(root);

    // Creation of Binary Tree 
    while (!q.empty())
    {
        int lVal, rVal; 

        Node *temp = q.front();
        q.pop();

        // Left Node
        cout << "Enter the value of left child of " << temp -> getData() << ": ";
        cin >> lVal;

        if (lVal != -1) {
            temp -> setLeft(new Node(lVal));
            q.push(temp -> getLeft());
        }

        // Right Node
        cout << "Enter the value of right child of " << temp -> getData() << ": ";
        cin >> rVal;

        if (rVal != -1) {
            temp -> setRight(new Node(rVal));
            q.push(temp -> getRight());
        }
    }
}
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};

BTNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    cout << endl;

    if (rootData == -1)
        return nullptr;

    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();

    return root;
}

BTNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    cout << endl;

    BTNode<int> *root = new BTNode<int>(rootData);
    queue<BTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();

        cout << "Enter left child of " << front->data << " :";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BTNode<int> *child = new BTNode<int>(leftChildData);
            q.push(child);
            front->left = child;
        }

        cout << "Enter right child of " << front->data << " :";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BTNode<int> *child = new BTNode<int>(rightChildData);
            q.push(child);
            front->right = child;
        }
    }
    return root;
}

void printTree(BTNode<int> *root)
{
    if (root == nullptr)
        return;

    cout << root->data << ": ";
    if (root->left != nullptr)
        cout << "L" << root->left->data << " ";
    if (root->right != nullptr)
        cout << "R" << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char const *argv[])
{
    BTNode<int> *root = takeInputLevelWise();
    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);

    // root->left = n1;
    // root->right = n2;

    printTree(root);
    return 0;
}

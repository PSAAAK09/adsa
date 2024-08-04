#include <iostream>
	
// Define the AVL tree node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height; // Height of the subtree rooted at this node
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1; // New node is initially a leaf
    return newNode;
}

// Function to get the height of a node
int getHeight(Node* node) {
    return (node ? node->height : 0);
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation (RR)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation (LL)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    if (!root)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    // Update height and balance factor
    updateHeight(root);

    // Check balance factor
    int balance = getHeight(root->left) - getHeight(root->right);

    // Perform rotations if necessary
    if (balance > 1) {
        if (key < root->left->key)
            return rightRotate(root); // Left-Left case
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root); // Left-Right case
        }
    }
    if (balance < -1) {
        if (key > root->right->key)
            return leftRotate(root); // Right-Right case
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root); // Right-Left case
        }
    }

    return root;
}

// Inorder traversal to print the tree
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    // Example: Insert keys into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    std::cout << "Inorder traversal of AVL tree: ";
    inorder(root);

    // Clean up memory (not shown in this simplified example)
    return 0;
}

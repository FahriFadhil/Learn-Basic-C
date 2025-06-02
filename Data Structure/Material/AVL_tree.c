#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
    int height;
} Node;

int height(Node *n) {
    return (n == NULL) ? 0 : n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node *n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int val) {
    if (node == NULL) return newNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0) {
            return rightRotate(root);  // LL Case
        } else {
            root->left = leftRotate(root->left);  // LR Case
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        if (getBalance(root->right) <= 0) {
            return leftRotate(root);  // RR Case
        } else {
            root->right = rightRotate(root->right);  // RL Case
            return leftRotate(root);
        }
    }

    return root;
}


void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int arr[] = {30, 20, 40, 10, 25, 50, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("In-order traversal before deletion:\n");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 40);
    root = deleteNode(root, 25);

    printf("In-order traversal after deletion:\n");
    inorder(root);
    printf("\n");

    return 0;
}

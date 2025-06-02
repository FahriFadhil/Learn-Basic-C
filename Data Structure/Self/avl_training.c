#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int val;
    int height;
    struct Node *left, *right;
} N;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(N *root) {
    return (root == NULL) ? 0 : root->height;
}

int getBalance(N *root) {
    return (root == NULL) ? 0 : height(root->left) - height(root->right);
}

N *rightRotate(N *root) {
    N *l = root->left;
    N *lr = l->right;

    l->right = root;
    root->left = lr;

    root->height = 1 + max(height(root->left), height(root->right));
    l->height = 1 + max(height(l->left), height(l->right));

    return l;
}

N *leftRotate(N *root) {
    N *r = root->right;
    N *rl = r->left;

    r->left = root;
    root->right = rl;

    root->height = 1 + max(height(root->left), height(root->right));
    r->height = 1 + max(height(r->left), height(r->right));

    return r;
}

N *createNode(int val) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->val = val;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

N *insertNode(N *root, int val) {
    if (root == NULL) return createNode(val);
    
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else if (val > root->val)
        root->right = insertNode(root->right, val);
    
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

N *findMin(N *root) {
    N *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

N *deleteNode(N *root, int val) {
    if (root == NULL) return root;

     if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else {
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        if (!root->left)
        {
            N *temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right)
        {
            N *temp = root->left;
            free(root);
            return temp;
        }
        
        N *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1)
    {
        if (getBalance(root->left) >= 0)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1)
    {
        if (getBalance(root->right) <= 0)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

void inorderTrav(N *root) {
    if (root)
    {
        inorderTrav(root->left);
        printf("%d ", root->val);
        inorderTrav(root->right);
    }
}

int main() {
    N *root = NULL;
    int arr[] = {30, 20, 40, 10, 25, 50, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);

    printf("In-order traversal before deletion:\n");
    inorderTrav(root);
    printf("\n");

    root = deleteNode(root, 40);
    root = deleteNode(root, 25);

    printf("In-order traversal after deletion:\n");
    inorderTrav(root);
    printf("\n");

    return 0;
}
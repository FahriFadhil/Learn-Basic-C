#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right, *parent;
} N;

N *createNode(int value) {
    N *newNode = (N*)malloc(sizeof(N));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

N *insert(N *curr, int value) {
    if (curr == NULL) return createNode(value);

    if (value < curr->value) 
        curr->left = insert(curr->left, value);
    else if (value > curr->value) 
        curr->right = insert(curr->right, value);

    return curr;
}

N *findMin(N *curr) {
    while (curr->left)
        curr = curr->left;
    N *temp = curr;
    return temp;
}

N *deleteNode(N *curr, int value) {
    if (!curr) return NULL;

    if (value < curr->value)
        curr->left = deleteNode(curr->left, value);
    else if (value > curr->value)
        curr->right = deleteNode(curr->right, value);
    else {
        
        if (!curr->left && !curr->right) {
            free(curr);
            return NULL;
        }
        
        if (!curr->left) {
            N *temp = curr->right;
            free(curr);
            return temp;
        }
        if (!curr->right) {
            N *temp = curr->left;
            free(curr);
            return temp;
        }

        N *temp = findMin(curr->right); 
        curr->value = temp->value;           
        curr->right = deleteNode(curr->right, temp->value); 
    }

    return curr;
}

N *search(N *curr, int value) {
    if (curr == NULL || curr->value == value)
        return curr;

    if (value < curr->value)
        return search(curr->left, value);
    else
        return search(curr->right, value);
}

void inorderTraversal(N *curr) {
    if (curr != NULL) {
        inorderTraversal(curr->left);
        printf("%d ", curr->value);
        inorderTraversal(curr->right);
    }
}

void preorderTraversal(N *curr) {
    if (curr) {
        printf("%d ", curr->value);
        preorderTraversal(curr->left);
        preorderTraversal(curr->right);
    }
}

void postorderTraversal(N *curr) {
    if (curr) {
        postorderTraversal(curr->left);
        postorderTraversal(curr->right);
        printf("%d ", curr->value);
    }
}

int main() {
    N *root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    // printf("\nIn-order Traversal (Sorted Order): ");
    // inorderTraversal(root);
    printf("\nPre-order Traversal (Sorted Order): ");
    preorderTraversal(root);
    // printf("\nPost-order Traversal (Sorted Order): ");
    // postorderTraversal(root);
    printf("\n");
    
    deleteNode(root, 60);
    
    printf("\nPre-order Traversal (Sorted Order): ");
    preorderTraversal(root);
    printf("\n");

    int searchKey = 41;
    if (search(root, searchKey))
        printf("Value %d found in BST\n", searchKey);
    else
        printf("Value %d NOT found in BST\n", searchKey);

    return 0;
}

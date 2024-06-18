#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data) {
    struct node *newnode = createnode(data);
    if (root == NULL) { // Fix: == instead of =
        root = createnode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

struct node *inorderpredecessor(struct node *root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node *delnode(struct node *root, int data) {
    struct node *ipre;
    if (root == NULL) {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL) {
        free(root);
    }
    if (data < root->data) {
        root->left = delnode(root->left, data);
    } else if (data > root->data) {
        root->right = delnode(root->right, data);
    } else {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = delnode(root->left, ipre->data);
    }
    return root;
}

void inorder(struct node *root) { // Fix: return type should be void
    if (root != NULL) { // Fix: added null check
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Insert elements into the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the binary tree: ");
    inorder(root);
    printf("\n");
    delnode(root,70);
    printf("In-order traversal of the binary tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void inorder(Node *root) {
    Node *s[MAX], *cur = root;
    int top = -1;

    while (cur || top != -1) {
        while (cur) {
            s[++top] = cur;
            cur = cur->left;
        }
        cur = s[top--];
        printf("%d ", cur->data);
        cur = cur->right;
    }
}

void preorder(Node *root) {
    if (!root) return;

    Node *s[MAX];
    int top = -1;
    s[++top] = root;

    while (top != -1) {
        Node *cur = s[top--];
        printf("%d ", cur->data);

        if (cur->right) s[++top] = cur->right;
        if (cur->left) s[++top] = cur->left;
    }
}

void postorder(Node *root) {
    if (!root) return;

    Node *s1[MAX], *s2[MAX];
    int t1 = -1, t2 = -1;
    s1[++t1] = root;

    while (t1 != -1) {
        Node *cur = s1[t1--];
        s2[++t2] = cur;

        if (cur->left) s1[++t1] = cur->left;
        if (cur->right) s1[++t1] = cur->right;
    }

    while (t2 != -1)
        printf("%d ", s2[t2--]->data);
}

Node *findParent(Node *root, int key) {
    if (!root) return NULL;

    if ((root->left && root->left->data == key) ||
        (root->right && root->right->data == key))
        return root;

    Node *p = findParent(root->left, key);
    if (p) return p;

    return findParent(root->right, key);
}

void printParent(Node *root, int key) {
    if (root && root->data == key) {
        printf("Root has no parent");
        return;
    }

    Node *p = findParent(root, key);
    if (p) printf("%d", p->data);
    else printf("Element not found");
}

int height(Node *root) {
    if (!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

int ancestors(Node *root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;

    if (ancestors(root->left, key) ||
        ancestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

void printAncestors(Node *root, int key) {
    if (!root) {
        printf("Element not found");
    } else if (root->data == key) {
        printf("Root has no ancestors");
    } else if (!ancestors(root, key)) {
        printf("Element not found");
    }
}

int countLeafNodes(Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    return countLeafNodes(root->left) +
           countLeafNodes(root->right);
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int key;

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nHeight: %d levels", height(root));
    printf("\nLeaf nodes: %d", countLeafNodes(root));

    printf("\nEnter element: ");
    scanf("%d", &key);

    printf("Parent: ");
    printParent(root, key);

    printf("\nAncestors: ");
    printAncestors(root, key);

    printf("\n");
    return 0;
}

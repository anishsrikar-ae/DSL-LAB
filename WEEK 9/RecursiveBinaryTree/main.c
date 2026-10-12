#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createTree() {
    int x;
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    Node *root = malloc(sizeof(Node));
    root->data = x;

    root->left = createTree();
    root->right = createTree();

    return root;
}

int height(Node *root) {
    if (!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

void printLevel(Node *root, int level) {
    if (!root) return;

    if (level == 1)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(Node *root) {
    int h = height(root);

    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

int main() {
    printf("Enter tree elements (-1 for NULL): ");
    Node *root = createTree();

    printf("Level-order traversal: ");
    levelOrder(root);

    return 0;


#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    int color; 
    struct Node *left, *right, *parent;
};  

struct Node *root = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = 1;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateLeft(struct Node **root, struct Node *pt) {
    struct Node *pt_y = pt->right;
    pt->right = pt_y->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_y->parent = pt->parent;

    if (pt->parent == NULL)
        *root = pt_y;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_y;
    else
        pt->parent->right = pt_y;

    pt_y->left = pt;
    pt->parent = pt_y;
}

void rotateRight(struct Node **root, struct Node *pt) {
    struct Node *pt_y = pt->left;
    pt->left = pt_y->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_y->parent = pt->parent;

    if (pt->parent == NULL)
        *root = pt_y;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_y;
    else
        pt->parent->right = pt_y;

    pt_y->right = pt;
    pt->parent = pt_y;
}

void fixViolation(struct Node **root, struct Node *pt) {
    struct Node *pt_parent = NULL;
    struct Node *pt_grandparent = NULL;

    while ((pt != *root) && (pt->color == 1) && (pt->parent->color == 1)) {
        pt_parent = pt->parent;
        pt_grandparent = pt->parent->parent;

        if (pt_parent == pt_grandparent->left) {
            struct Node *pt_uncle = pt_grandparent->right;

            if (pt_uncle != NULL && pt_uncle->color == 1) {
                pt_grandparent->color = 1;
                pt_parent->color = 0;
                pt_uncle->color = 0;
                pt = pt_grandparent;
            } else {
                if (pt == pt_parent->right) {
                    rotateLeft(root, pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->parent;
                }
                rotateRight(root, pt_grandparent);
                int temp = pt_parent->color;
                pt_parent->color = pt_grandparent->color;
                pt_grandparent->color = temp;
                pt = pt_parent;
            }
        } else {
            struct Node *pt_uncle = pt_grandparent->left;

            if ((pt_uncle != NULL) && (pt_uncle->color == 1)) {
                pt_grandparent->color = 1;
                pt_parent->color = 0;
                pt_uncle->color = 0;
                pt = pt_grandparent;
            } else {
                if (pt == pt_parent->left) {
                    rotateRight(root, pt_parent);
                    pt = pt_parent;
                    pt_parent = pt->parent;
                }
                rotateLeft(root, pt_grandparent);
                int temp = pt_parent->color;
                pt_parent->color = pt_grandparent->color;
                pt_grandparent->color = temp;
                pt = pt_parent;
            }
        }
    }
    (*root)->color = 0;
}

void insert(struct Node **root, int data) {
    struct Node *pt = createNode(data);
    *root = BSTInsert(*root, pt);
    fixViolation(root, pt);
}

int main() {
    int n, data;
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }
    return 0;
}
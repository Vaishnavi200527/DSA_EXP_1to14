#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data, ht;
    struct node* left;
    struct node* right;
};

// Function prototypes
struct node* create_node(int);
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
int height(struct node*);
struct node* search(struct node*, int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void show(struct node*);
int count_nodes(struct node*);

int main() {
    struct node* root = NULL;
    int choice, data;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        printf("\n\n------- AVL TREE --------\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Show Tree (Inorder, Preorder, Postorder)\n5. Node Count\n6. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2: 
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3: 
                printf("\nEnter data to search: ");
                scanf("%d", &data);
                struct node* result = search(root, data);
                printf(result ? "\nNode found!\n" : "\nNode not found!\n");
                break;
            case 4: 
                show(root);
                break;
            case 5: 
                printf("\nTotal nodes: %d\n", count_nodes(root));
                break;
            case 6: 
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
        printf("\nContinue? (y/n): ");
        scanf(" %c", &cont);
    }
    return 0;
}

// Create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    new_node->ht = 1;  // New node is initially at height 1
    return new_node;
}

// Height of a node
int height(struct node* n) {
    return (n == NULL) ? 0 : n->ht;
}

// Insert a node into the AVL tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    root->ht = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    return root;
}

// Delete a node from the AVL tree
struct node* delete(struct node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct node* temp = root->right;
            while (temp->left) temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Search for a node
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Show tree in different orders
void show(struct node* root) {
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
}

// Count nodes in the tree
int count_nodes(struct node* root) {
    if (root == NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

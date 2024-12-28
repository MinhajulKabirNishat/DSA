#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

// Create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a value into the BST
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) {
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } else {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// In-order traversal (prints keys in sorted order)
void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Pre-order traversal (prints keys in root-left-right order)
void preOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (prints keys in left-right-root order)
void postOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// Search for a node by key
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) {
    if (root == NULL || root->key == target) {
        return root; // Node found or tree is empty
    }
    if (target < root->key) {
        return searchNode(root->left, target); // Search in left subtree
    }
    return searchNode(root->right, target); // Search in right subtree
}

// Find the minimum node
struct BinaryTreeNode* FindMin(struct BinaryTreeNode* node) {
    while (node && node->left != NULL) {
        node = node->left; // Go to the leftmost node
    }
    return node;
}

// Find the maximum node
struct BinaryTreeNode* FindMax(struct BinaryTreeNode* node) {
    while (node && node->right != NULL) {
        node = node->right; // Go to the rightmost node
    }
    return node;
}

// Delete a node by key
struct BinaryTreeNode* Delete(struct BinaryTreeNode* root, int value) {
    if (root == NULL) {
        return root; // Tree is empty
    }
    if (value < root->key) {
        root->left = Delete(root->left, value); 
    } else if (value > root->key) {
        root->right = Delete(root->right, value); 
    } else { // Node found
        // Case 1: No childif (root->left == NULL) {
            struct BinaryTreeNode* temp = root->right;
            free(root);
            return temp;
        }
        
        else if (root->right == NULL) {
            struct BinaryTreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct BinaryTreeNode* temp = FindMin(root->right); // Get the inorder successor
        root->key = temp->key; // Copy the inorder successor's key to this node
        root->right = Delete(root->right, temp->key); // Delete the inorder successor
    }
    return root;
}

int leftHeight (_INTEGRAL_MAX_BITS)

// Main function
int main() {
    struct BinaryTreeNode* root = NULL; // Initialize the root to NULL
    int val, choice;

    while (1) {

        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search\n");
        printf("6. Find Min\n");
        printf("7. Find Max\n");
        printf("8. Delete\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insertNode(root, val);
                break;
            case 2: // In-order Traversal
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3: // Pre-order Traversal
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4: // Post-order Traversal
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5: // Search
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (searchNode(root, val) != NULL) {
                    printf("Value found: %d\n", val);
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 6: // Find Min
                {
                    struct BinaryTreeNode* minNode = FindMin(root);
                    if (minNode) {
                        printf("Minimum value: %d\n", minNode->key);
                    } else {
                        printf("Tree is empty.\n");
                    }
                }
                break;
            case 7: // Find Max
                {
                    struct BinaryTreeNode* maxNode = FindMax(root);
                    if (maxNode) {
                        printf("Maximum value: %d\n", maxNode->key);
                    } else {
                        printf("Tree is empty.\n");
                    }
                }
                break;
            case 8: // Delete
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = Delete(root, val);
                break;
            case 9: // 
                exit(0);

                case 10:
                printf("Calculate the integer variable");
                scanf("&d",value);
               

                }

                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


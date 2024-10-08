#include <stdio.h>
#define MAX 15

// Function to print tree in in-order traversal using array
void inorderTraversal(int tree[], int index, int size) {
    if (index >= size || tree[index] == -1) {
        return;
    }

    // Traverse left subtree
    inorderTraversal(tree, 2 * index + 1, size);

    // Print current node
    printf("%d ", tree[index]);

    // Traverse right subtree
    inorderTraversal(tree, 2 * index + 2, size);
}

int main() {
    int tree[MAX] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7};  // Binary Tree Representation using array (-1 means no node)

    printf("In-order traversal of the binary tree: ");
    inorderTraversal(tree, 0, MAX);
    printf("\n");

    return 0;
}

/*
Name:Riya
roll no: CO2105
Title: Binary Search Tree Traversal and Operations
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node
{
    int rollNo;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int rollNo)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->rollNo = rollNo;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a roll number
struct Node* insert(struct Node *root, int rollNo)
{
    if (root == NULL)
        return createNode(rollNo);

    if (rollNo < root->rollNo)
        root->left = insert(root->left, rollNo);
    else if (rollNo > root->rollNo)
        root->right = insert(root->right, rollNo);
    else
        printf("Duplicate roll number not allowed!\n");

    return root;
}

// Search for a roll number
struct Node* search(struct Node *root, int rollNo)
{
    if (root == NULL || root->rollNo == rollNo)
        return root;

    if (rollNo < root->rollNo)
        return search(root->left, rollNo);

    return search(root->right, rollNo);
}

// Find the minimum-valued node
struct Node* findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Delete a roll number
struct Node* deleteNode(struct Node *root, int rollNo)
{
    if (root == NULL)
        return root;

    if (rollNo < root->rollNo)
        root->left = deleteNode(root->left, rollNo);

    else if (rollNo > root->rollNo)
        root->right = deleteNode(root->right, rollNo);

    else
    {
        // Case 1 and Case 2: zero or one child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: two children
        struct Node *temp = findMin(root->right);

        root->rollNo = temp->rollNo;

        root->right = deleteNode(root->right, temp->rollNo);
    }

    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->rollNo);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->rollNo);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->rollNo);
    }
}

// Free all allocated nodes
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, rollNo;

    do
    {
        printf("\n\n===== BINARY SEARCH TREE =====\n");
        printf("1. Insert a student roll number\n");
        printf("2. Delete a student roll number\n");
        printf("3. Search for a student roll number\n");
        printf("4. Display inorder traversal\n");
        printf("5. Display preorder traversal\n");
        printf("6. Display postorder traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            freeTree(root);
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter roll number to insert: ");
                if (scanf("%d", &rollNo) != 1)
                {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                if (search(root, rollNo) != NULL)
                {
                    printf("Roll number already exists!\n");
                }
                else
                {
                    root = insert(root, rollNo);
                    printf("Roll number inserted successfully.\n");
                }
                break;

            case 2:
                printf("Enter roll number to delete: ");
                if (scanf("%d", &rollNo) != 1)
                {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                if (search(root, rollNo) == NULL)
                {
                    printf("Roll number not found!\n");
                }
                else
                {
                    root = deleteNode(root, rollNo);
                    printf("Roll number deleted successfully.\n");
                }
                break;

            case 3:
                printf("Enter roll number to search: ");
                if (scanf("%d", &rollNo) != 1)
                {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                result = search(root, rollNo);

                if (result != NULL)
                    printf("Roll number %d found in the BST.\n", rollNo);
                else
                    printf("Roll number %d not found in the BST.\n", rollNo);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                freeTree(root);
                root = NULL;
                printf("Exiting program. Memory freed successfully.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

/*

OUTPUT

===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 50
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 30
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 70
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 20
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 40
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 1
Enter roll number to insert: 45
Roll number inserted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 2
Enter roll number to delete: 45
Roll number deleted successfully.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 3
Enter roll number to search: 70
Roll number 70 found in the BST.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 3
Enter roll number to search: 90
Roll number 90 not found in the BST.


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 4
Inorder Traversal: 20 30 40 50 70 


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 5
Preorder Traversal: 50 30 20 40 70 


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 6
Postorder Traversal: 20 40 30 70 50 


===== BINARY SEARCH TREE =====
1. Insert a student roll number
2. Delete a student roll number
3. Search for a student roll number
4. Display inorder traversal
5. Display preorder traversal
6. Display postorder traversal
7. Exit
Enter your choice: 7
Exiting program. Memory freed successfully.

*/

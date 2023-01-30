#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void CreateBst(int data)
{
    struct node *temp, *root1;
    root1 = root;
    while (1)
    {
        if (root1 == NULL)
        {
            root1 = (struct node *)malloc(sizeof(struct node));
            root1->data = data;
            root1->left = NULL;
            root1->right = NULL;
            root = root1;
            break;
        }
        else
        {
            if (data < root1->data)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                if (root1->left == NULL)
                {
                    temp->data = data;
                    temp->left = NULL;
                    temp->right = NULL;
                    root1->left = temp;
                    break;
                }
                else
                {
                    root1 = root1->left;
                }
            }
            else
            {
                if (data > root1->data)
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    if (root1->right == NULL)
                    {
                        temp->data = data;
                        temp->right = NULL;
                        temp->left = NULL;
                        root1->right = temp;
                        break;
                    }
                    else
                    {
                        root1 = root1->right;
                    }
                }
            }
        }
    }
}
void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d\n\n", root->data);
    Inorder(root->right);
}

void Preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n\n", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d\n\n", root->data);
}
int height(struct node *root)
{
    int max;
    if (root != NULL)
    {
        int leftsubtree = height(root->left);
        int rightsubtree = height(root->right);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            return max = rightsubtree + 1;
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter 1 to create BST\n");
        printf("Enter 2 for inorder traversal\n");
        printf("Enter 3 for preorder traversal\n");
        printf("Enter 4 for postorder traversal\n");
        printf("Enter 5 for evaluate height of BST\n");
        printf("Enter 6 for exit\n");
        printf("Enter Your choice :\n");
        scanf("%d", &ch);
        int n, i;
        switch (ch)
        {
        case 1:
            i = 1;
            printf("Enter the no of Nodes:");
            scanf("%d", &n);
            while (i <= n)
            {
                int data;
                printf("Enter the Data : ");
                scanf("%d", &data);
                CreateBst(data);
                i++;
            } 
            break;
        case 2:
            printf("After Inorder Traversal :\t");
            Inorder(root);
            break;
        case 3:
            printf("After Preorder Traversal :\t");
            Preorder(root);
            break;
        case 4:
            printf("After Postrder Traversal :\t");
            Postorder(root);
            break;
        case 5:
            printf("The HEIGHT of TREE is : %d\n\n", height(root) - 1);
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid Choice!\n\n");
            break;
        }
    }
    return 0;
}

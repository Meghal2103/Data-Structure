#include <stdio.h>
#include <D:\Data Structure\10)Tree\queue.h>

// struct binaryTree
// {
//     struct binaryTree *left;
//     int value;
//     struct binaryTree *right;
// };

void createTree(struct binaryTree *T)
{
    int root;
    printf("Enter value of root node: ");
    scanf("%d", &root);
    T->value = root;
    Queue q;
    q.enQueue(T);
    while(!q.isEmpty())
    {
        struct binaryTree *p = q.deQueue();
        printf("Does node with value %d have left child? (Y)", p->value);
        char l;
        scanf(" %c", &l);
        if(l == 'y' ||l == 'Y')
        {
            struct binaryTree *L = (struct binaryTree *)malloc(sizeof(struct binaryTree));
            p->left = L;
            q.enQueue(L);    
            printf("Enter value of left child node: ");
            int left;
            scanf("%d", &left);
            L->value = left;
        }
        else
        {
            p->left = NULL;
        }
        printf("Does node with value %d have right child? (Y)", p->value);
        char r;
        scanf(" %c", &r);
        if(r == 'y' ||r == 'Y')
        {
            struct binaryTree *R = (struct binaryTree *)malloc(sizeof(struct binaryTree));
            p->right = R;
            q.enQueue(R);
            printf("Enter value of right child node: ");
            int right;
            scanf("%d", &right);
            R->value = right;
        }
        else
        {
            p->right = NULL;
        }
    }
};

int main()
{
    struct binaryTree t;
    createTree(&t);
}

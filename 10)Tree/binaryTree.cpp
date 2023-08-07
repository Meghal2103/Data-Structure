#include <stdio.h>
#include <D:\Data Structure\10)Tree\stack.h>

void preOrder(struct binaryTree T)
{
    printf("%d ", T.value);
    if(T.left!=NULL)
    {
        preOrder(*(T.left));
    }
    if(T.right!=NULL)
    {
        preOrder(*(T.right));
    }
};

void preOrderIterative(struct binaryTree *T)
{
    stack s;
    struct binaryTree *t = T;
    s.push(NULL);
    while(t!=NULL)
    {
        printf("%d ", (*t).value);
        if((*t).right!=NULL)
        {
            s.push((*t).right);
        }
        if((*t).left!=NULL)
        {
            t = (*t).left;
        }
        else
        {
            t = s.pop();
        }
    }
};

void postOrder(struct binaryTree T)
{    
    if(T.left!=NULL)
    {
        postOrder(*(T.left));
    }
    if(T.right!=NULL)
    {
        postOrder(*(T.right));
    }
    printf("%d ", T.value);
};

void inOrder(struct binaryTree T)
{    
    if(T.left!=NULL)
    {
        inOrder(*(T.left));
    }
    printf("%d ", T.value);
    if(T.right!=NULL)
    {
        inOrder(*(T.right));
    }
};

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
        printf("Does node with value %d have left child? (Y) ", p->value);
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
        printf("Does node with value %d have right child? (Y) ", p->value);
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
    preOrder(t);
    printf("\n");
    preOrderIterative(&t);
    // postOrder(t);
    // printf("\n");
    // inOrder(t);
}

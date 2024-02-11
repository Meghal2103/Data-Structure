#include <stdio.h>
#include <D:\Data_Structure\10)Tree\stack.h>

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

void postOrderIterative(struct binaryTree *T)
{
    stack s;
    // s.push(NULL);   
    struct binaryTree *t = T;
    while (t!=NULL || s.isEmpty() == 0)
    {
        if(t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            struct binaryTree *temp = (s.Top())->value;
            if(temp->right!=NULL)
            {
                t = temp->right;
            }
            else
            {
                printf("%d ", temp->value);
                s.pop();
                while(s.isEmpty() == 0 && temp == (s.Top())->value->right)
                {
                    temp = s.pop();
                    printf("%d ", temp->value);
                }
            }
        }
    }
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

void inOrderIterative(struct binaryTree *T)
{
    stack s;
    struct binaryTree *t = T;
    while (t!=NULL || s.isEmpty() == 0)
    {
        if(t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.pop();
            printf("%d ", t->value);
            t = t->right;
        }
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
    struct binaryTree t1,t2,t3,t4,t5,t6,t7,t8;
    t1.value = 1;
    t2.value = 2;
    t3.value = 3;
    t4.value = 4;
    t5.value = 5;
    t6.value = 6;
    t7.value = 7;
    t8.value = 8;
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = NULL;
    t4.left = NULL;
    t4.right = NULL;
    t5.left = &t7;
    t5.right = NULL;
    t6.left = &t8;
    t6.right = NULL;
    t7.left = NULL;
    t7.right = NULL;
    t8.left = NULL;
    t8.right = NULL;
    // createTree(&t);
    preOrder(t1);
    printf("\n");
    preOrderIterative(&t1);
    printf("\n");
    postOrder(t1);
    printf("\n");
    postOrderIterative(&t1);
    printf("\n");
    inOrder(t1);
    printf("\n");
    inOrderIterative(&t1);
}

// t1.left = &t2;
// t1.right = &t3;
// t2.left = &t4;
// t2.right = &t5;
// t3.left = &t6;
// t3.right = &t7;
// t4.left = NULL;
// t4.right = NULL;
// t5.left = NULL;
// t5.right = NULL;
// t6.left = NULL;
// t6.right = NULL;
// t7.left = NULL;
// t7.right = NULL;
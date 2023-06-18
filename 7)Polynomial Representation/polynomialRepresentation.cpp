#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Term
{
    public:
        int co_efficent;
        int power;
};

class polynomialRepresentation
{
    public:
        int n;
        Term *exp;
    public:
        polynomialRepresentation(int n)
        {
            this->n = n;
            exp = (Term *)malloc(sizeof(Term)*n);
        }
        int polynomialEvaluation(int x)
        {
            int sum=0;
            for(int i = 0; i < n; i++)
            {
                sum = sum + (pow(x,exp[i].power)*exp[i].co_efficent);
            }
            return sum;
        }
};

// struct sparseMatrix * polynomsilAddition(struct polynomialRepresentation a, struct polynomialRepresentation b)
// {
//     struct polynomialRepresentation *c;
//     c=(struct polynomialRepresentation *)malloc(sizeof(struct polynomialRepresentation));
//     c->n = a.n;
//     c->exp=(struct Term *)malloc((a.n+b.n)*sizeof(struct Term));
//     int i=0,j=0,k=0;
//     while(i<a.n || j<b.n) 
//     {
//         if(a.exp[i].power == b.exp[j].power && i<a.n && j<b.n)
//         {
//             c->exp[k].co_efficent=a.exp[i].co_efficent+b.exp[j].co_efficent;
//             c->exp[k].power=a.exp[i].power;
//             i++; j++; k++;
//         }
//         else if(a.exp[i].power <= b.exp[j].power && i<a.n && j<b.n)
//         {
//             c->exp[k].co_efficent=b.exp[j].co_efficent;
//             c->exp[k].power=b.exp[j].power;
//             j++; k++;
//         }
//         else
//         {
//             c->exp[k].co_efficent=a.exp[i].co_efficent;
//             c->exp[k].power=a.exp[i].power;
//             i++; k++;
//         }
//     }
//     return c;
// };

struct polynomialRepresentation* polynomsilAddition(struct polynomialRepresentation a, struct polynomialRepresentation b)
{
    struct polynomialRepresentation *c;
    c = (struct polynomialRepresentation*)malloc(sizeof(struct polynomialRepresentation));
    c->n = a.n+b.n;
    c->exp = (struct Term*)malloc((a.n + b.n) * sizeof(struct Term));
    int i = 0, j = 0, k = 0;
    while (i < a.n || j < b.n)
    {
        if (a.exp[i].power == b.exp[j].power && i < a.n && j < b.n)
        {
            c->exp[k].co_efficent = a.exp[i].co_efficent + b.exp[j].co_efficent;
            c->exp[k].power = a.exp[i].power;
            i++;
            j++;
            k++;
        }
        else if (a.exp[i].power <= b.exp[j].power && i < a.n && j < b.n)
        {
            c->exp[k].co_efficent = b.exp[j].co_efficent;
            c->exp[k].power = b.exp[j].power;
            j++;
            k++;
        }
        else
        {
            c->exp[k].co_efficent = a.exp[i].co_efficent;
            c->exp[k].power = a.exp[i].power;
            i++;
            k++;
        }
    }
    return c;
}


int main()
{
    polynomialRepresentation a = polynomialRepresentation(3);
    a.exp[0].co_efficent=5;
    a.exp[0].power=4;
    a.exp[1].co_efficent=2;
    a.exp[1].power=2;
    a.exp[2].co_efficent=5;
    a.exp[2].power=0;
    int x = a.polynomialEvaluation(1);
    printf("%d",x);
    polynomialRepresentation b = polynomialRepresentation(5);
    b.exp[0].co_efficent=6;
    b.exp[0].power=4;
    b.exp[1].co_efficent=5;
    b.exp[1].power=3;
    b.exp[2].co_efficent=9;
    b.exp[2].power=2;
    b.exp[3].co_efficent=2;
    b.exp[3].power=1;
    b.exp[4].co_efficent=3;
    b.exp[4].power=0;
    polynomialRepresentation *c;
    c=polynomsilAddition(a,b);
}


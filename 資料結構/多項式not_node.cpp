#include <ctime>
#include <iostream>
using namespace std;

class Node
{
private:
    int coef, exp;
    Node *node;
    friend class LinkedList;
};
class LinkedList
{
public:
    LinkedList();
    void insert(int coef, int exp);
    void output();
    LinkedList add(LinkedList polynomial);
    LinkedList multiply(LinkedList polynomial);

private:
    Node *first, *last;
};
LinkedList::LinkedList()
{
    first = new Node;
    last = new Node;
    first->node = NULL;
    last->node = NULL;
}
void LinkedList::insert(int coef, int exp)
{
    Node *p = new Node;
    p->coef = coef;
    p->exp = exp;
    p->node = NULL;
    if (first->node != NULL)
    {
        last->node->node = p;
    }
    else
    {
        first->node = p;
    }
    last->node = p;
}
void LinkedList::output()
{
    Node *ans = new Node;
    ans->node = first->node;
    while (ans->node != NULL)
    {
        ans = ans->node;
        if (ans->exp == 0)
        {
            cout << ans->coef;
        }
        else
        {
            cout << ans->coef << "x^" << ans->exp;
            if (ans->node != NULL && ans->node->coef > 0)
            {
                cout << "+";
            }
        }
        if (ans->node == NULL)
        {
            cout << endl;
        }
    }
}
LinkedList LinkedList::add(LinkedList polynomial)
{
    LinkedList final;
    Node *p = new Node;
    Node *q = new Node;
    p = first->node;
    q = polynomial.first->node;
    if (p == NULL && q == NULL)
    {
        return final;
    }
    else
    {
        while (true)
        {
            if (p == NULL && q == NULL)
            {
                break;
            }
            else
            {
                if (p->exp > q->exp)
                {
                    final.insert(p->coef, p->exp);
                    if (p->node == NULL)
                    {
                        while (q != NULL)
                        {
                            final.insert(q->coef, q->exp);
                            q = q->node;
                        }
                    }
                    p = p->node;
                }
                else if (p->exp < q->exp)
                {
                    final.insert(q->coef, q->exp);
                    if (q->node == NULL)
                    {
                        while (p != NULL)
                        {
                            final.insert(p->coef, p->exp);
                            p = p->node;
                        }
                    }
                    q = q->node;
                }
                else
                {
                    final.insert(p->coef + q->coef, p->exp);
                    if (p->node == NULL && q->node != NULL)
                    {
                        p = p->node;
                        q = q->node;
                        while (q != NULL)
                        {
                            final.insert(q->coef, q->exp);
                            q = q->node;
                        }
                    }
                    else if (p->node != NULL && q->node == NULL)
                    {
                        q = q->node;
                        p = p->node;
                        while (p != NULL)
                        {
                            final.insert(p->coef, p->exp);
                            p = p->node;
                        }
                    }
                    else if (p->node != NULL && q->node != NULL)
                    {
                        p = p->node;
                        q = q->node;
                    }
                }
            }
        }
        return final;
    }
}
LinkedList LinkedList::multiply(LinkedList polynomial)
{
    LinkedList ans;
    LinkedList temp1;
    Node *p = new Node;
    Node *q = new Node;
    p = first->node;
    q = polynomial.first->node;
    for (int i = 0;; i++)
    {
        LinkedList temp2;
        for (int j = 0;; j++)
        {
            temp2.insert(p->coef * q->coef, p->exp + q->exp);
            if (q->node != NULL)
            {
                q = q->node;
            }
            else
                break;
        }
        if (i == 0)
        {
            ans = temp2;
            temp1 = ans;
        }
        else
        {
            ans = temp1.add(temp2);
            temp1 = ans;
        }
        if (p->node != NULL)
        {
            p = p->node;
            q = polynomial.first->node;
        }
        else
            break;
    }
    return ans;
}
int main()
{
    clock_t start, end;
    int term1, term2, coef, exp;
    cout << "Input term of Polynomial1:";
    cin >> term1;
    cout << "Input term of Polynomial2:";
    cin >> term2;
    LinkedList polynomial1, polynomial2;
    for (int i = 0; i < term1; i++)
    {
        cout << "Term" << i + 1 << " of Polynomial1" << endl;
        cin >> coef >> exp;
        polynomial1.insert(coef, exp);
    }
    for (int i = 0; i < term2; i++)
    {
        cout << "Term" << i + 1 << " of Polynomial2" << endl;
        cin >> coef >> exp;
        polynomial2.insert(coef, exp);
    }
    cout << endl;
    cout << "Polynomial1=";
    polynomial1.output();
    cout << "Polynomial2=";
    polynomial2.output();
    start = clock();
    LinkedList ans = polynomial1.multiply(polynomial2);
    end = clock();
    cout << "Polynomial1*Polynomial2=";
    ans.output();
    cout << "Total Time=" << float(end - start) / CLOCKS_PER_SEC << endl;
}
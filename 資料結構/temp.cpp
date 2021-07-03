#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
     friend class LinkedList;
private:
    int coef;
    int exp;
    ListNode *next;
    ListNode():coef(0),exp(0),next(0){}; 
};
class LinkedList{

private:
    ListNode *first; // list的第一個node
    int size;

public:
    //ListNode *add(ListNode *p1,ListNode *p2);
    void output();
    void Addnode(int m);
    void merge();
    void Multiply(ListNode *fir,ListNode *sec);
    ListNode *getpointer() { return first; }
    void Swap(int &a, int &b);
    void bubble_sort();
    LinkedList() { size = 0; }
};

void LinkedList::Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void LinkedList::bubble_sort()
{
    ListNode *p = first,*q;
    q = p;
    ListNode *tempA = new ListNode;
    ListNode *tempB = new ListNode;
    tempA->next = new ListNode;
    for (int i = 0; i < size-1;i++)
    {
        p = q;
        for (int j = 0; j < size - i - 2;j++)
        {
            if(p->next->next==NULL)
                break;
            if(p->next->exp<p->next->next->exp)
            {
                tempA = p->next->next;
                tempB = p->next->next->next;
                p->next->next = tempB;   
                tempA->next = p->next;
                p->next = tempA;
            }
            p = p->next;
        }
    }
}
void LinkedList::Addnode(int m)
{
    srand(time(0));
    int t = m;
    int in_coef;
	int in_exp;
    ListNode *current = new ListNode;
    if(m<5)
        cin>>in_coef>>in_exp;
    else 
    {
        in_coef = rand() % 100+1;
        in_exp = m;
    }
    first = current;
    // //建立第一個節點 
    
	current->coef=in_coef;
	current->exp=in_exp;
    //first = current;
    //建立後續節點
    for(int i=1;i<m;i++)
	{
        current->next=new ListNode; //宣告新的空間
		current=current->next;
        if(m<5)
        cin >> in_coef >> in_exp;
        else
        {
            in_coef = rand() % 50 + 1;
            in_exp = --t;
        }
        current->coef=in_coef;
		current->exp=in_exp;
    }
}
void LinkedList::output()
{
    ListNode *current = new ListNode;
    current=first;
    while(current->next!=NULL)
    {
        if(current->next->coef>0)
            cout << current->coef << "x^" << current->exp<<"+";
        else  if(current->next->coef<=0)
            cout << current->coef << "x^" << current->exp;
        current = current->next;
    }
        if(current->coef!=0)
            cout << current->coef << "x^" << current->exp ;
        cout << endl;
        //cout << size<<endl;
}
void LinkedList::Multiply(ListNode*fir,ListNode*sec)
{
    ListNode *pol1 = fir;
    ListNode *pol2 = sec;
    ListNode *pol3 = new ListNode;
    ListNode *pol4 = new ListNode;
    first = pol3;
    while(pol1!=NULL)
    {
        while(pol2!=NULL)
        {
            pol3->coef = pol1->coef * pol2->coef;
            pol3->exp = pol1->exp + pol2->exp;
            size++;
            pol2 = pol2->next;
            pol3->next = new ListNode;
            pol3 = pol3->next;
        }
        
        pol2 = sec;//指回原本的頭
        pol1 = pol1->next;
    }
    bubble_sort();
    merge();
}
void LinkedList::merge()
{
    ListNode *ans;
    ans = new ListNode;
    ListNode *temp = ans;
    ListNode *current = first;
    int F_coef,F_exp;
    while(current->next!=NULL)
    {
        F_exp = current->exp;
        F_coef = current->coef;
        while(current->exp==current->next->exp)
        {
            F_coef =current->next->coef+F_coef;
            //F_exp = current->exp;
            current = current->next;
        }
        ans->next = new ListNode;
        ans->coef = F_coef;
        ans->exp = F_exp;
        ans = ans->next;
        current = current->next;
    }
    first = temp;
    current=first;
    while(current->next->next!=NULL)
    {
        if(current->next->coef>0)
            cout << current->coef << "x^" << current->exp<<"+";
        else  if(current->next->coef<0)
            cout << current->coef << "x^" << current->exp;
        current = current->next;
    }
    if(current->coef!=0)
        cout << current->coef << "x^" << current->exp;
    cout << endl;
}
int main()
{
    LinkedList pol1, pol2, pol3;
    //istNode *pol1 = NULL;
    int m, n;
    double start, end;
    cout << "Please input your first number of temrs of Polynomial"<<endl;
    cin >> m;
    pol1.Addnode(m);
    cout << "your first Polynomial is ";
    pol1.output();
    cout << "Please input your second number of temrs of Polynomial"<<endl;
    cin >> n;
    pol2.Addnode(n);
    cout << "your second Polynomial is ";
    pol2.output();
    start = clock();
    pol3.Multiply(pol1.getpointer(), pol2.getpointer());
    end = clock();
    cout << "Time :" << (end - start) / CLOCKS_PER_SEC<<"s";
}

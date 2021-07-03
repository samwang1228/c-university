#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
public:
    int coef;
    int exp;
    ListNode *next;
    ListNode():coef(0),exp(0),next(0){};
    friend class LinkedList;
    
};

class LinkedList{
    friend class ListNode;

private:
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first; // list的第一個node
    int size;

public:
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
    for (int i = 0; i < size-1;i++)
    {
        p = q;
        for (int j = 0; j < size - i - 1;j++)
        {
            if(p->exp<p->next->exp)
            {
                swap(p->coef, p->next->coef);
                swap(p->exp, p->next->exp);
            }
            p = p->next;
        }
    }
}
void LinkedList::Addnode(int m)
{
    srand(time(0));
    int in_coef;
	int in_exp;
    ListNode *current = new ListNode;
    cin>>in_coef>>in_exp;
	
	//建立第一個節點 
	current->coef=in_coef;
	current->exp=in_exp;
	//current->next=NULL;
    first = current;
    //建立後續節點
    for(int i=1;i<m;i++)
	{
		in_coef= rand()%10+1;
		in_exp= rand()%8+in_exp;
		
		current->next=new ListNode; //宣告新的空間
		current=current->next; //指向下一個
		current->coef=in_coef;
		current->exp=in_exp;
		current->next=NULL;
	}
}
void LinkedList::output()
{
    ListNode *current = new ListNode;
    current=first;
    while(current->next!=NULL)
    {
        cout << current->coef << "x^" << current->exp<<"+";
        current = current->next;
    }
        cout << current->coef << "x^" << current->exp << endl;
    //cout << size<<endl;
}
void LinkedList::Multiply(ListNode*fir,ListNode*sec)
{
    ListNode *pol1 = fir;
    ListNode *pol2 = sec;
    ListNode *pol3 = new ListNode;
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
        cout << current->coef << "x^" << current->exp<<"+";
        current = current->next;
    }
    cout << current->coef << "x^" << current->exp<<endl;
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
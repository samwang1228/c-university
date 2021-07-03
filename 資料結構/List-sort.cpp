#include <iostream>
#include<cstdlib>
#include<time.h>
# define create_Rand 5
using namespace std;
class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
     friend class LinkedList;
private:
    int coef;
    int exp;
    ListNode *next;
    ListNode():coef(-5),exp(INT_MIN),next(0){}; 
};
class LinkedList{

private:
    ListNode *first; // list的第一個node
public:
    ListNode *add(ListNode *p1,ListNode *p2);
    void output();
    void Addnode(int m);
    void Multiply(ListNode *p1,ListNode *p2);
    ListNode *getpointer() { return first; }
};
ListNode* LinkedList::add(ListNode *p1,ListNode *p2){
//     x ^ 6 + x ^ 5 + x;
//     x ^ 7 + x ^ 5;
// ans x^7 + x^6 +2x^5                                 
    ListNode *ans = new ListNode, *header,*head;
	head = ans;
	header = ans; 
    while(p1->next!=NULL  || p2->next!=NULL){
		if (p1 -> exp == p2 -> exp ){
            ans->exp = p1->exp;
            ans->coef = p1->coef + p2->coef;
            ans->next = new ListNode;
            p1=p1 -> next;
            p2=p2 ->next;
        }
        else if (p1 -> exp > p2 -> exp){
            ans -> exp = p1 -> exp;
            ans -> coef = p1 -> coef;
            ans -> next = new ListNode;
            p1=p1 -> next;
        }
        else if (p1->exp < p2 -> exp){
            ans->exp = p2->exp;
            ans->coef = p2->coef;
            ans->next = new ListNode;
            p2=p2 -> next;
        }
        ans = ans->next;
        
    }
    // while(p1->next)
    // {
    //     ans->exp = p1->exp;
    //     ans->coef = p1->coef;
    //     ans->next = new ListNode;
    //     p1 = p1->next;
    // }
    // while(p2->next)
    // {
    //     ans->exp = p2->exp;
    //     ans->coef = p2->coef;
    //     ans->next = new ListNode;
    //     p2 = p2->next;
    // }
     return header;
}

void LinkedList::Addnode(int m)
{
    srand(time(0));
    int t = m;
    int in_coef;
	int in_exp;
    ListNode *current = new ListNode;
    first = current;
    for (int i = 0; i < m; i++)
	{
        if(create_Rand>m)
        cin >> in_coef >> in_exp;
        else
        {
            in_coef = rand() % 50 + 1;
            in_exp = t--;
        }
        current->coef=in_coef;
		current->exp=in_exp;
        current->next=new ListNode; //宣告新的空間
		current=current->next; 
    }
}
void LinkedList::output()
{
    ListNode *current = new ListNode;
    current=first;
    bool fir_coef=false;
    while(current->next!=NULL)
    {
        if(current->coef!=0)
        {
            fir_coef = true;
            if (current->next->coef > 0)
                cout << current->coef << "x^" << current->exp << "+";
            else if (current->next->coef <= 0)
                cout << current->coef << "x^" << current->exp;
        }
        else //等於0的情況
        {
            if(current->next->coef>0&&fir_coef)
                cout << "+";
        }
        current = current->next;
    }
        // if(current->coef!=0)
        //     cout << current->coef << "x^" << current->exp;
        cout << endl;
}
void LinkedList::Multiply(ListNode*p1,ListNode*p2)
{
    // pol1       :x^3+5x^2+x :m
    // pol2       :3x^2+2x+5  :n
    // mult_ans[0]:3x^5+2x^4+5x^3 o(n+n)
    // add_ans [0]:3x^5+17x^4+15x^3+25x^2 o(n)
    // mult_ans[1]:15x^4+10x^3+25^2 o(n)
    // add_ans [1]:3x^5+17x^4+15x^3+25x^2 o(2n+n)
    // mult_ans[2]:3x^3+2x^2+5x   o(n)  
    // add_ans [1]:3x^5+17x^4+18x^3+27x^2+5x o(3n+n)-->(mn+n)
    // Multiply =o(mn)
    // merge    =((n+nm)*m)/2 ~=o(nm^2) or (n^2m) 看哪個為頭
	ListNode* p2_head = p2;
	ListNode* mult_ans = new ListNode;
	ListNode* add_ans = new ListNode;
    ListNode *mult_head = mult_ans;
    int count = 0;
    while(p1->next != NULL){
        while(p2->next != NULL){
            mult_ans->coef = p1->coef * p2->coef;
            mult_ans->exp = p1->exp + p2->exp;
            p2 = p2->next;
            mult_ans->next = new ListNode;
           	mult_ans = mult_ans->next;
		}
        mult_ans = mult_head;				//  乘法結果重新指回去最前，給加法
        //if(count) 
		add_ans = add(mult_ans,add_ans);	// 	回傳加法給相加結果
        //else
            //add_ans = mult_head;
        p1 = p1->next;
        ++count;
        p2 = p2_head;
	}
	first = add_ans;
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
    pol3.output();
    end = clock();
    cout << "Time :" << (end - start) / CLOCKS_PER_SEC<<"s";
}

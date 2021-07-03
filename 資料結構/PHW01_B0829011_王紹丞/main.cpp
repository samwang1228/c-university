#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
//Definition list node
class Node 
{
    friend class LinkedList ;
private :

    int value ;    // Can be any type , 
    Node *pNext ;    // Pointer to the next Node 

public :
    Node (void)
        : pNext (NULL)
    {}

    Node (int val)
        :value (val) , pNext (NULL)
    {}

    Node (int val,Node *next)
        : value (val) , pNext (next)
    {}
};


class LinkedList
{
private:
    Node * pHead ;
    Node * pTail ;

public :
    LinkedList (void) ;
    LinkedList (int val) ;
    ~LinkedList(void) ;

    void TailAppend (int val) ;        
    void Clear () ;                    
    void Print () ;                   
    void BubbleSortList () ;        
};


LinkedList::LinkedList ()
{
    pHead = pTail = NULL ;
}
LinkedList::LinkedList(int val)
{
    pHead = new Node (val) ;
    pTail = pHead ;
}

LinkedList::~LinkedList()
{
    Clear() ;
}
void LinkedList::TailAppend(int val)
{
    if (pHead == NULL)
    {
        pTail = pHead = new Node (val) ;
    }
    else
    {
        pTail->pNext = new Node (val) ;
        pTail = pTail->pNext ;
    }
}



void LinkedList::Clear()
{
    Node *pDel = pHead ;
    while (pDel != NULL)
    {
        pHead = pHead->pNext ;
        delete pDel ;
        pDel = pHead;
    }
    pTail = pHead = NULL ;
}

void LinkedList::Print()
{
    ofstream output;
    output.open("output.txt");
    Node *p = pHead ;
    if (pHead == NULL)
    {
        cout << "This list is empty"<<endl ;
        return ;
    }
    cout << "LinkedList : ";

    while (p!= NULL)
    {
        output<<p->value << " " ;
        p = p->pNext ;
    }
    cout << endl ;

}


void LinkedList::BubbleSortList()
{    
    Node *tail = pHead ;
    Node *tmp  = pHead ;
    Node* curr = pHead;
    Node* prev = pHead;
    int size = 0;
    while(tail)
    {
        tail = tail->pNext;
        size++;
    }

    for(int i=size;i>0;i--) 
    {
        curr = pHead;
        prev = pHead;
        for(int j=0;j<i-1 && curr->pNext;j++) 
        {     
            if(curr->value > curr->pNext->value) 
            {
                tmp = curr->pNext;
                curr->pNext = tmp->pNext;
                tmp->pNext = curr; 
                if(curr == pHead) 
                {
                    pHead = tmp;
                    prev = tmp;
                } 
                else
                {
                    prev->pNext = tmp;
                    prev = prev->pNext;
                }
            }
            else 
            {
                curr = curr->pNext;
                if(j!=0) prev = prev->pNext;
            }
        }
    }
}
int main()
{
    LinkedList list;
    int size=0;
    //cout<<"Please input number of size: ";
    ifstream input;
    //ofstream output;
    input.open("input.txt");
    
    int n;
    while(input>>n)
    {
    	++size;
	}
	input.close();
	input.open("input.txt");
    for (int i = 0 ; i < size ; i++)
    {
        input>>n;
        list.TailAppend(n) ;
    }
    cout << "Before Sort : "<< endl; 
    //list.Print(); 
    cout << endl <<"After Sort : "<<endl;
    list.BubbleSortList() ;
    list.Print(); 
     
    cout <<endl ; 

}    


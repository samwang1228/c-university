#include <cstdlib>
#include <iostream>
using namespace std;
class Node
{
    friend class LinkedList;

private:
    int value;   // Can be any type ,
    Node *pNext; // Pointer to the next Node
    Node(int val)
        : value(val), pNext(NULL)
    {
    }
};

class LinkedList
{
private:
    Node **adjacencyList;
    int numberOfNode;

public:
    LinkedList(int n){
        numberOfNode = n;
        adjacencyList = new Node *[n];
        for (int i = 0; i < n; i++)
        {
            adjacencyList[i] = new Node(i);
            }            
        }
    };
    void TailAppend(int i,int j);
    // void Clear();
    void Print(Node *p[],int n);
};
int main()
{
    int n, e, m1, m2;
    srand(0);
    do
    { //node數
        cout << "input node:";
        cin >> n;
    } while (n < 2);
    m2 = n;
    m1 = m2 / 2 + 0.5;
    do
    { //edge數
        cout << "input edge:";
        cin >> e;
    } while (e > n * (n - 1) / 2 || e < m1);
    Node *p[n];
    Node *phead[n];
    for (int i = 0; i < n;i++)
        *phead[i] = *p[i];
//	*phead=*p;
    LinkedList answer(n);
    int i, j;
    for (int k = 0; k < e; k++)
    {
        do
        {
            i = rand() % n;
            j = rand() % n;
        }while (i == j);
        answer.TailAppend(i,j);
    }
    answer.Print(n);
}
void LinkedList::TailAppend(int i,int j)
{
        if(adjacencyList[i]!=NULL)
            adjacencyList[i]->value = j;
        else 
        adjacencyList[i]->pNext =new Node(j);
        if(adjacencyList[i]!=NULL)
            adjacencyList[j]->value = i;
        else 
        adjacencyList[j]->pNext =new Node(i);
//         p[i] = p[i]->pNext; 
//         p[j] = new Node(i);
//         p[j] = p[j]->pNext;
}
void LinkedList::Print(Node *p[],int n)
{
    cout << "----------------"<<endl;
            for(int i=0;i<numberOfNode;i++){
                cout << i << " -> ";
                Node* temp = adjacencyList[i];
                while(temp->pNext!=0){
                    temp = temp->pNext;
                    cout << temp->value << " ";
                }
                cout << endl;
            }   
            cout << "----------------"<<endl; 
}

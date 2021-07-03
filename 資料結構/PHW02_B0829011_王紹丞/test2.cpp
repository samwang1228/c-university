#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
struct Node
{
    int val;
    Node *next;
};

struct Edge
{
    int x, y;
};

class Graph
{
    Node *getAdjListNode(int dest, Node *head)
    {
        Node *newNode = new Node;
        newNode->val = dest;
        newNode->next = head;

        return newNode;
    }

    int N;

public:
    Node **head;
    Graph(Edge edges[], int n, int N)
    {
        head = new Node *[N]();
        this->N = N;
        for (int i = 0; i < N; i++)
        {
            head[i] = NULL;
        }

        for (unsigned i = 0; i < n; i++)
        {
            int first = edges[i].x;
            int end = edges[i].y;

            Node *newNode = getAdjListNode(end, head[first]);

            head[first] = newNode;

            newNode = getAdjListNode(first, head[end]);

            head[end] = newNode;
        }
    }

    // Destructor
    ~Graph()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] head[i];
        }

        delete[] head;
    }
};
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "-->" << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    int v, e, m1, m2;
    srand(time(0));
    do
    { //node數
        cout << "input node:";
        cin >> v;
    } while (v < 2);
    m2 = v;
    m1 = m2 / 2 + 0.5;
    do
    { //edge數
        cout << "input edge:";
        cin >> e;
    } while (e > v * (v - 1) / 2 || e < m1);
    Edge edges[e];
    int i, j;
    bool test = false;
//    edges[0].x = rand()%v;
//    edges[0].y = rand()%v;
//    cout<<"i:"<<edges[0].x<<" j:"<<edges[0].y<<endl;
    for (int k = 0; k < e; k++)
    {
        do
        {
            start:
			i = rand() % v;
            j = rand() % v;
            if(k>0){
	            for (int t = 0; t < k; t++)
	            {
	                if((i==edges[t].x&&j==edges[t].y)||(i==edges[t].y&&j==edges[t].x))// cheak repeact
	                    goto start;
	            }
        	}
        } while (i == j);
        edges[k].x = i;
        edges[k].y = j;
        test = false;
        cout << "i:" << i << " j:" << j << endl;
    }
    int N = v;
    int n = sizeof(edges) / sizeof(edges[0]);

    Graph graph(edges, n, N);

    for (int i = 0; i < N; i++)
    {
        cout << i;
        printList(graph.head[i]);
    }
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class G
{
public:
	void DFS(int **a, int n);
	void DFSVisit(int **a, int n, int i);
	void BFS(int **a, int n);
	void getDFS(int **b, int n);
	void getBFS(int **b, int n);

private:
	int *Ddata;
	int *Dcolor;
	int *Dprt;
	int *Bdata;
	int *Bcolor;
	int *Bprt;
};
class Queue
{
public:
	Queue(int n);
	int empty();
	int full();
	int pop();
	void push(int item);

private:
	int size;
	int front, rear;
	int *buffer;
};
void clean(int **a, int n);
bool test(int **a, int n);
void output(int **a, int n);
int main()
{
	//srand( time(0) );
	int i, j, k, n, e, m1, **a, **d, **b;
	double m2;
	G Graph;

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

	a = new int *[n]; //建空矩陣
	d = new int *[n];
	b = new int *[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int[n];
		d[i] = new int[n];
		b[i] = new int[n];
	}

	do
	{ //建圖
		clean(a, n);
		for (k = 0; k < e; k++)
		{
			do
			{
				i = rand() % n;
				do
				{
					j = rand() % n;
				} while (i == j);//對角線無意義
			} while (a[i][j] == 1 || a[j][i] == 1);//代表無向圖對稱成立
			a[i][j] = 1;
			a[j][i] = 1;
		}
	} while (test(a, n) == true);
	//因為要求tree所以不能有forest的情況
	output(a, n);
	cout << endl;

	Graph.DFS(a, n);
	clean(d, n);
	Graph.getDFS(d, n);
	cout << "DFS：" << endl;
	output(d, n);
	cout << endl;

	Graph.BFS(a, n);
	clean(b, n);
	Graph.getBFS(b, n);
	cout << "BFS：" << endl;
	output(b, n);

	system("pause");
	return 0;
}
void clean(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++) //歸零
	{
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	}
}
void output(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++) //輸出
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
}
bool test(int **a, int n) //檢查是否為空
{
	int num, i, j;
	for (i = 0; i < n; i++)
	{
		num = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
				num++;
		}
		if (num == 0)
			return true;
	}
	return false;
}
void G::DFS(int **a, int n)
{
	int i;
	Dcolor = new int[n]; //0:white 1:gray 2:black
	Dprt = new int[n]; //first time
	Ddata = new int[n];
	for (i = 0; i < n; i++)//initialize
	{
		Ddata[i] = i;
		Dcolor[i] = 0;
		Dprt[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		if (Dcolor[i] == 0)
			DFSVisit(a, n, i);
	}
}
void G::DFSVisit(int **a, int n, int i)
{
	int j;
	Dcolor[i] = 1;
	for (j = 0; j < n; j++)
	{
		if (a[i][j] == 1 && Dcolor[j] == 0)
		{
			Dprt[j] = i + 1;
			DFSVisit(a, n, j);
		}
	}
	Dcolor[i] = 2;
}
void G::getDFS(int **b, int n)
{
	int i, k;
	for (i = 1; i < n; i++)
	{
		k = Dprt[i];
		if (k > 0)
			b[k - 1][i] = 1;
	}
}
void G::getBFS(int **b, int n)
{
	int i, k;
	for (i = 1; i < n; i++)
	{
		k = Bprt[i];
		if (k > 0)
			b[k - 1][i] = 1;
	}
}
void G::BFS(int **a, int n)
{
	int i, k;
	Queue Q(n);
	Bcolor = new int[n];
	Bprt = new int[n];
	Bdata = new int[n];
	for (i = 0; i < n; i++)
	{
		Bdata[i] = i;
		Bcolor[i] = 0;
		Bprt[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (Bcolor[i] == 0)
		{
			Q.push(i);
			Bcolor[i] = 1;
			while (!Q.empty())
			{
				k = Q.pop();
				Bcolor[k] = 2;
				for (int j = 0; j < n; j++)
				{
					if (a[k][j] && Bcolor[j] == 0)
					{
						Q.push(j);
						Bcolor[j] = 1;
						Bprt[j] = k + 1;
					}
				}
			}
		}
	}
}
Queue::Queue(int n)
{
	size = n;
	buffer = new int[n];
	front = 0;
	rear = 0;
}
void Queue::push(int item)
{
	if (full() != true)
	{
		buffer[front] = item;
		front = (front + 1) % size;
	}
	else
		cout << "Queue is full!" << endl;
}
int Queue::pop()
{
	if (empty() != true)
	{
		int item;
		item = buffer[rear];
		rear = (rear + 1) % size;
		return item;
	}
	cout << "Queue is empty!" << endl;
}
int Queue::full()
{
	return (((front + 1) % size) == rear);
}
int Queue::empty()
{
	return (rear == front);
}
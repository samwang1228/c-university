/*#include<iostream>
using namespace std;
class intList //pos 從 1 開始（陣列從0開始）
{
	public:
		intList();
		void insert(int value); //新增 value 到數列
		bool remove(int pos); //刪除 pos 位置的正整數
		bool setValue(int pos, int value); //設定 pos 位置的值為 value
	 protected:
        		bool swapValue(int &pos1, int &pos2);
	protected:
		int *data; //資料存放的動態陣列
        int *data2;
        int totalSize; //目前動態陣列的大小
		int sizeUsed; //目前有幾個正整數
		void expandSize(); //擴增動態陣列大小為兩倍
};
class searchlist : public intList
{
    public:
        searchlist() : intList(){}//初始contructor
        int search(int n);
        bool remove(int n);
};
class Sort : public intList
{
    public:
        Sort():intList(){}
        void bublesort();
};
int main()
{
    int n;
    intList ans;
    searchlist ans2;
    Sort ans3;  
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        else if (n > 0)
            ans2.insert(n);
        else if(n<0)
        {
            ans2.remove(-n);
        }
     }
}
intList::intList()
{
     totalSize=10; //目前動態陣列的大小
	 sizeUsed=0; //目前有幾個正整數
     data = new int[totalSize];
}
void intList::insert(int n)
{
    data[sizeUsed] = n;
    sizeUsed++;
    if(sizeUsed>=totalSize)
    {
        expandSize();
    }
}
void intList::expandSize ()
{
    totalSize *= 2;
    data2 = new int[totalSize];
    for (int i = 0; i <= sizeUsed;i++)
    {
        data2[i] = data[i];
    }
    delete[] data;
    data = data2;//指標可以直接相等 
}
bool intList::remove(int n)
{
        int temp = data[n - 1];
        data[n - 1] = data[sizeUsed - 1];
        data[sizeUsed - 1] = temp;
        sizeUsed--;
    return true;
}
bool searchlist::remove(int n)
{
    if(search(n)==-1)
        cout << "no" << endl;
    else 
    {
        cout << "ok" << endl;
        data[n - 1]=data[sizeUsed-1];
        sizeUsed--;
    }
    return true;
}
void Sort::bublesort()
{
    for (int i = 0; i < sizeUsed -1;i++)
    {
        for (int j = 0 ; j < sizeUsed - i - 1; j++)
        {
            if(data[j]>data[j+1])
            {
            swapValue(data[j], data[j + 1]);
            }
        }
    }
    for (int i = 0;i<sizeUsed;i++)
        cout << data[i]<<endl;
}
int  searchlist::search(int n)
{
    for (int j = 0;j<sizeUsed;j++)
    {
        if(n==data[j])
            return j;
    }
    return -1;
}
bool intList::swapValue(int &pos1, int &pos2)
{
    int temp = pos1;
    pos1 = pos2;
    pos2 = temp;
    return true;
}*/
/*不使用protected想法多三個function setsize{讓size--} int *getptr{return data} setptr(int *ptr){data=ptr}因為修改後要再存
*/#include<iostream>
using namespace std;
class intList //pos 從 1 開始（陣列從0開始）
{
	public:
		intList();
		void insert(int value); //新增 value 到數列
		void remove(int pos); //刪除 pos 位置的正整數
        		int getValue(int pos); //回傳 pos 位置的值
		bool setValue(int pos, int value); //設定 pos 位置的值為 value
        		int getSize();//sizeUsed 的 accessor
            protected:
                bool swapValue(int pos1, int pos2);
            private:
                int *data; //資料存放的動態陣列
                int *data2;
                int totalSize;     //目前動態陣列的大小
                int sizeUsed;      //目前有幾個正整數
                void expandSize(); //擴增動態陣列大小為兩倍
};
class searchlist : public intList
{
    public:
       // searchlist() : intList(){}
          int search(int n);   
};
class Sort :public searchlist
{
    public:
       // Sort():searchlist(){}
        void bublesort();
};
int main()
{
    int n;
    intList ans;
    searchlist ans2;
    Sort ans3;  
    while(cin>>n)
    {
        if(n==0)
        {
            ans3.bublesort();
            break;
        }
        else if (n > 0)
            ans3.insert(n);
        else if(n<0)
        {
            if(ans3.search(-n)==-1)
                cout << "no"<<endl;
            else
                cout << "ok" << endl;
        }
     }
}
intList::intList()
{
     totalSize=10; //目前動態陣列的大小
	 sizeUsed=-1; //目前有幾個正整數
     data = new int[totalSize];
}
void intList::insert(int n)
{
    sizeUsed++;
    if(sizeUsed>=totalSize)
        expandSize();
    data[sizeUsed] = n;
}
void intList::expandSize ()
{
    totalSize *= 2;
    data2 = new int[totalSize];
    for (int i = 0; i <= sizeUsed;i++)
        data2[i] = data[i];
    delete[] data;
    data = data2;//指標可以直接相等 
}
void intList::remove(int n)
{
    swapValue(n, getSize());
    --sizeUsed;
}
int intList:: getSize()
{
    return sizeUsed;
}
int  searchlist::search(int n)
{
    for (int j = 0;j<=getSize();j++)
    {
        if(n==getValue (j))
        {
            remove(j);
            return j;
        }
    }
    return -1;
}
bool intList::swapValue(int pos1, int pos2)
{
    int temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
    return true;
}
int intList::getValue(int pos)
{
    return data[pos];
}
void Sort::bublesort()
{
    for (int i = 0; i < getSize()-1;i++)
    {
        for (int j = 0 ; j < getSize() - i - 1; j++)
        {
            if(getValue (j)> getValue (j+1))
            {
            swapValue(j,(j+1));
            }
        }
    }
    for (int i = 0;i<getSize();i++)
        cout << getValue(i) <<" ";
}
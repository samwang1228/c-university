#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
class Sorting 
{
    public:
        void HeapSort(const int n);
        void MergeSort(int *initList,const int n);
        void QuickSort(const int left, const int right);
        Sorting() { }
        void print(int n);//從1到n
        void printAll(int n);//從0到n
        ~Sorting();
        void eqPtr(int *a)
        {
            ptr = a;
        }
        void InsertionSort(const int n);

    private:
        void adjust(const int root, const int n);
        int *ptr;
        void swap(int &a, int &b);
        void merge(int *initList,int *result, const int L,const int m,const int n );
        void MergePass(int *initList,int *result, const int n, const int subSize);
        void insert(int &e, int *a, int i);
};
int main()
{
    int size;
    int mode;
    srand(time(0));
    //int quickSize = 11;
    Sorting answer;
    LARGE_INTEGER startTime,endTime,fre;
    QueryPerformanceFrequency(&fre); //取得CPU頻率
    double times;
    //int *temp = new int[heapSize+1]{99, 12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};//[0]值沒用方便計算用
    // int *temp1 = new int[mergeSize+1]{99, 12, 2, 16, 30, 8, 28, 4, 10, 20, 6,18};//[0]值沒用方便計算用
    //int *temp2 = new int[quickSize]{12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
    cout << "Please input your size of array." << endl;
    cin >> size;
    int *temp = new int[size+1];
    int *adTemp = new int[size + 1];
    adTemp[0] = 5;
    //cout << "Please input data" << endl;
    for (int i = 0; i < size;i++)
    {
        temp[i]=(long long)(( double)(rand()*49999)/RAND_MAX)+1;
        //temp[] = randint(1, 50000);
    }
    temp[size] = INT_MAX; // in order not to out of range  
    for (int j = 0; j < size;j++)
    {
        adTemp[j + 1] = temp[j];
    }
    cout << "Please input mode of sort(1:Quick 2:Merge 3:Heap 4:insert)" << endl;
    // for (int i = 0; i < size;i++)
    // {
    //     cout << temp[i]<<" ";
    // }
    cin >> mode;
    cout << "The initial data: ";
    QueryPerformanceCounter(&startTime);
    if(mode==1)
    {
        answer.eqPtr(temp);
        answer.printAll(size);
        answer.QuickSort(0, size);
        cout << "The sorting data: ";
        answer.printAll(size);
//        cout<<temp[0];
//        cout<<temp[size-1]<<endl;
    }
    if(mode==2)
    {
        answer.eqPtr(adTemp);
      //  answer.print(size);
        answer.MergeSort(adTemp,size);
        cout << "The sorting data: ";
       // answer.print(size);
    }
    if(mode==3)
    {
        answer.eqPtr(temp);
        answer.print(size);
        cout << "The sorting data: ";
        answer.HeapSort(size);
        answer.print(size);
    }
    if(mode==4)
    {
        answer.eqPtr(adTemp);
        answer.print(size);
        cout << "The sorting data: ";
        answer.InsertionSort(size);
        answer.print(size);
    }
    QueryPerformanceCounter(&endTime);
    times=(double)(endTime.QuadPart-startTime.QuadPart)/fre.QuadPart;
    cout << fixed << setprecision(20) << times << "s" << endl;
}
void Sorting::print(int n)
{
    for (int i = 1; i <= n;i++)
        cout << setw(5)<<ptr[i]<<" ";
    cout << endl;
}
//Heap Sort start
void Sorting::adjust (const int root, const int n)
{
    int key = ptr[root];
    int i;
    for (i = 2 * root; i <= n;i*=2)
    {
        if(i<n&&ptr[i]<ptr[i+1])//選右邊
            i++;
        if(key>=ptr[i]) //代表此區間已排完
            break;
        ptr[i / 2] = ptr[i]; //將兒子往上移
    }
    //cout << i << "\n";
    ptr[i / 2] = key; //補齊位置
}
void Sorting::HeapSort(const int n)
{
    for (int i = n / 2; i >= 1;i--)//從i/2開始找
        adjust(i, n);
    //print(n);
    for (int j = n -1; j >= 1;j--)
    {
        swap(ptr[1], ptr[j+1]);//把max換到後面
        adjust(1, j);
        //print(n);
    }
    //print(n);
}
void Sorting::swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Heap Sort end
Sorting::~Sorting()
{
    delete []ptr;
}
//Merge Sort start
void Sorting::merge(int *initList,int *result,const int L,const int m,const int n )
{
    int i1, i2, iResult;
    for (i1 = L, iResult = L, i2 = m + 1; i1 <= m && i2 <= n;iResult++)
    {
        //兩個list i1(前半) i2(後半)
        if(initList[i1]<=initList[i2])//較大的放進result並且將位置往後移
        {
            result[iResult] = initList[i1];
            i1++;
        }
        else 
        {
            result[iResult] = initList[i2];
            i2++;
        }
    }
    if(i1<=m) //copy data
    {
        for (; i1 <=m;i1++)
        {
            result[iResult] = initList[i1];
            ++iResult;
        }
    }
    else if(i2<=n) //copy data
    {
        for (; i2 <=n;i2++)
        {
            result[iResult] = initList[i2];
            ++iResult;
        }
    }
}
void Sorting::MergePass(int *initList,int *result,const int n, const int subSize)
{
    int i;
    for (i = 1; i <= n - 2 * subSize + 1; i += 2 * subSize)
        merge(initList,result, i, i + subSize - 1, i + 2 * subSize - 1);
    if((i+subSize-1)<n) //already not half pair
        merge(initList,result, i, i + subSize-1 , n);
    else //copy data
    {
        for (int j = i; j <=n;j++)
            result[j] = initList[j];
    }
}

   
void Sorting::MergeSort(int *initList,const int n)
{
    int *temp = new int[n+1];
    for (int L = 1; L < n;L *= 2)
    {
        MergePass(initList,temp, n, L);
        //cout << "L:"  << L << " ";
        L *= 2;
        //print(n);
        MergePass(temp,initList, n, L);
        //cout << "L:"  << L << " ";
        //print(n);
    }
    ptr = initList;
    delete[] temp;
}

//Merge Sort end

//Quick Sort start
void Sorting:: QuickSort ( const int left, const int right)
{
	if ( left<right ){
		int i=left,
			j=right+1,
			pivot=ptr[left];
		do{
			do i++; while( ptr[i]<pivot ); //選左邊比樞紐大的
			do j--; while( ptr[j]>pivot ); //選右邊比樞紐小的
			if ( i<j ) swap( ptr[i],ptr[j] ); 
		}while( i<j );
		swap ( ptr[left],ptr[j] ); //把樞紐移位切割成兩個list
		
		QuickSort(left,j-1 );
		QuickSort(j+1,right );
	}
}
void Sorting::printAll(int n)
{
    for (int i = 0; i < n; i++)
        cout <<setw(5)<< ptr[i] << " ";
    cout << endl;
}
void Sorting::InsertionSort(const int n)
{
    for (int j = 2; j <= n;j++)
    {
        int temp = ptr[j];
        insert(temp, ptr, j - 1);
    }

}
void Sorting::insert(int &e, int *a, int i)
{
    a[0] = e;
    while(e<a[i])//if break 代表e為最大
    {
        a[i + 1] = a[i]; //往後移空位置
        i--;
    }
    a[i + 1] = e;
}
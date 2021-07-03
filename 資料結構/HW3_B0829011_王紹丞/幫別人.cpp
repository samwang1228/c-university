#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class Permutation
{
public:
    void insertionsort(int *a, const int size);
    void printarray(int *a, int size);
    void quicksort(int *a,int left,int right);
    void swap(int *x, int *y);
    int partition(int *a, int left, int right);

private:

};
void Permutation::insertionsort(int *a, const int size)
{
    for (int i = 1; i < size; i++)
    {
        int e = a[i]; //設立一變數用來儲存目前要處理資料的最後一個元素
        int j = i - 1;
        while (e < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = e;
    }
}
void Permutation::printarray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
    }
}
void Permutation::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Permutation::partition(int *a,int left,int right)
{
    int pivot = a[right];
    int i = right + 1;
    for (int j = left; j < right;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    i++;
    swap(&a[i],&a[right]);
    return i;
    cout << "a";
}
void Permutation::quicksort(int *a,int left,int right)
{
    if(left<right)
    {
        int pivot = partition(a, left, right);
        quicksort(a, left, pivot - 1);
        quicksort(a, pivot + 1, right);
    }
}
int main()
{
    Permutation  insort,prt, qs;
    int size = 7;
    int a[] = {5, 3, 4, 2, 1, 7, 6, INT_MAX};
    insort.insertionsort(a, 7);
    prt.printarray(a, 7);
    cout << endl;
    qs.quicksort(a, 0,size);
    prt.printarray(a, size);
    return 0;
}
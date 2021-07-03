#include <iostream>
#include <cmath>
using namespace std;
class IntList {
    public:
    IntList(); //初始化那三個成員變數 pointer new 一個 
    
    void insert(int value); //新增 value 到數列 的最後一個 sizeused++!!!!!!!
            //sizedused=totalsize 請把陣列變大
            //寫在 expandSize
            //呼叫exapnd size
            //再執行insert 
    bool remove(int pos); //刪除 pos 位置的正整數
            //sizeused--!!!
            int getValue(int pos); //回傳 pos-1標誌的值 
    bool setValue(int pos, int value); //設定 pos 位置的值為 value
            int getSize();//sizeUsed 的 accessor
            void setsizeUsed(int newsizeUsed);
            int* getdataptr();
            void setdataptr(int *pointer);
    protected:
            bool swapValue(int pos1, int pos2);
    private:
    int *data; //資料存放的動態陣列 //new一個動態陣列 size自己決定 建議10 
    int totalSize; //目前動態陣列的大小 //可以放100 (new值) 
    int sizeUsed; //目前有幾個正整數 //只放49 
    void expandSize();   
}; 
//Derived: searchList
//繼承 intList
//新增功能如下
//可以搜尋某一數值是否存在
//如果存在，回傳位置
//如果有數值重複/*出現很多次傳第一個出現的*/，回傳第一個位置
//如果不存在，回傳 -1
class SearchList:public IntList {
public:
 SearchList();
 int search(int value);
 bool remove(int value);
};
//程式不斷輸入 正整數 代表輸入該正整數至 intList
//如果程式輸入 –x，代表刪除數值為 x 的正整數。（注意，public member function 僅有刪除某位置的函數）。
//如果成功刪除，顯示 ok\n，如果找不到顯示 no\n
//如果輸入 0 程式結束   
int main(){
 SearchList object;
 int x;
    while(cin>>x){
        if(x==0){
        break;
        }
        else if(x>0){
        object.insert(x);
        }
        else{
        int v=abs(x); 
        object.remove(v);
        }
    }
}
IntList::IntList(){
  data=new int[10];
  totalSize=10;
  sizeUsed=0; 
}
void IntList::insert(int value){
 if(totalSize==sizeUsed){
  expandSize();
 }
 data[sizeUsed]=value;
 sizeUsed++;
}
bool IntList::remove(int pos){
 if(pos<=sizeUsed){
    cout<<data[pos-1]<<endl;
    data[pos-1]=data[sizeUsed-1];
    data[sizeUsed-1]=0;
    sizeUsed--;
    return true;
 }
 else{
  cout<<"no\n";
  return false;
 }
}
int IntList::getValue(int pos){
 return data[pos-1];
}
bool IntList::setValue(int pos, int value){
 data[pos-1]=value;
 if(pos==sizeUsed+1){
  sizeUsed++;
 }
 return true;
}
int IntList::getSize(){
 return sizeUsed;
}
bool IntList::swapValue(int pos1, int pos2){
 if(pos1-1<=sizeUsed || pos2-1<=sizeUsed){
  return false;
 }
 int temp=data[pos1-1];
 data[pos1-1]=data[pos2-1];
 data[pos2-1]=temp;
 return true;
}
void IntList::expandSize(){
 int *newptr;
 newptr=new int[totalSize*2];
 for(int i=0;i<sizeUsed;i++){
  newptr[i]=data[i];
 } 
 delete []data;
 data=newptr;
}
void IntList::setsizeUsed(int newsizeUsed){
 sizeUsed=newsizeUsed;
}
int* IntList::getdataptr(){
 return data;
}
void IntList::setdataptr(int *pointer){
 data=pointer;
}
//derived class SearchList();
SearchList::SearchList():IntList(){
 /*empty*/ 
}
int SearchList::search(int value){
 int *ptr=getdataptr();
 int i;
 for(i=0;i<getSize();i++){
    if(ptr[i]==value){
    return (i+1);
    break;
  }
 }
  return -1; 
}
bool SearchList::remove(int value){
    int *ptr=getdataptr();
    int SZ=getSize();
    int position=search(value);
    if(position>=0){
    ptr[position-1]=ptr[SZ-1];
    ptr[SZ-1]=0;
    setsizeUsed(SZ-1);
    cout<<"ok\n";
    setdataptr(ptr);
    return true;
 }
 else{
  //並沒有該value
  cout<<"no\n";
  return false;
 }
}
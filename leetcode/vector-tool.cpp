#include<iostream>
#include<vector>
#include<algorithm>
#include <typeinfo>
#include<cstring>
using namespace std;
int main()
{
    vector<int> number = {5, 6, 7, 8, 9, 10};
    vector<int> number2;
    number2 = number; //vector 的複製
    number.clear();//vector的清空
    auto cut = vector<int>(number2.begin() + 2, number2.begin() + 5); //從[2]開始切割到[4] 複製至cut
    cout << cut[0]<<" "<<cut[cut.size()-1]<<endl;
    //cout << typeid(cut[0]).name(); //查詢type
    // i：int，整數。
    // f：float，單精度浮點數。
    // d：double，雙精度浮點數。
    // Ss：String，字串。
    // c：字元。
    vector<string> name = {"Sam"};
    vector<string> verb = {"likes","printing"};
    name.insert(name.end(), verb.begin(), verb.end());//vector的合併
    for (int i = 0; i < name.size();i++)
    {
        cout << name[i] << " ";
    }
    vector<int> numbers = {1,5,4,3,5,6,3,2,3,2,4,2,6,3};
    auto result = find_if(numbers.begin(),numbers.end(),[](auto element){
    return element > 5;
    }); //將numbers第一個大於5的數複製過去 同等於下面
    // auto morethan5(int element){
    //      return element > 5;
    // }
    // auto result = find_if(numbers.begin(), numbers.end(), morethan5);
    auto index = distance(numbers.begin(),result);
    cout <<"nubers="<<*result<<" index=["<<index<<"]"<<endl;
    for(auto& number:numbers){
    number *= 2; //將numbers*2
    }
    //我故意把他分拆，以證明他是真的改動了數字
    for(auto& number:numbers)
    cout << number<< " ";
    cout << "\n";
    vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //刪除第[2]到第[7]個變數
    n.erase(n.begin()+2, n.begin()+8);
    for (int i = 0; i < n.size();i++)
    {
        cout << n[i] << " ";
    }
}
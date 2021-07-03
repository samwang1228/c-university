#include<iostream>
using namespace std;
void inputscore(int score[][4],int size1)
{
    for (int i = 0; i < size1;i++){//輸入每個同學的成績
        cout << "please input the " << i + 1 << " Student ID:";
        cin >> score[i][0];
        cout << "please input the " << i + 1 << " Chinese Score:";
        cin >> score[i][1];
         cout << "please input the " << i + 1 << " English Score:";
        cin >> score[i][2];
         cout << "please input the " << i + 1 << " Math Score:";
        cin >> score[i][3];
    }
}
void outputscore(int score[][4],int size1)//輸出每個同學的成績
{
    for (int i = 0; i < size1;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            cout << score[i][j]<<" ";
        }
        cout << endl;
    }
}
void sort(int score[][4],int size)//排名
{
    int sum1[5] = {};//用來排序總分大小
    int sum2[5] = {};//用來找該位學生的學號位置
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            sum1[i] += score[i][j];
            sum2[i] += score[i][j];
        }
    }
    for (int j = 0; j < size-1; j++){
        for (int t = 0; t < size-1-j;t++)
        {
            if(sum1[t]<=sum1[t+1]){
                int temp =sum1[t];
               sum1[t] =sum1[t + 1];
               sum1[t + 1] = temp;
            }
        }
    }
        for (int j = 0; j < size;j++)
        {
            for (int i = 0; i < size;i++)
            {
                 if(sum1[j]==sum2[i])
                 {
                     cout << "no." << j+1  << " is " << score[i][0] << " and total is " << sum1[j]<<endl;
                    
                 }
            }
        }
}
int main()
{
    int n;
    cout << "The number of student";
    cin >> n;
    int x[n][4];
    inputscore(x, n);
    outputscore(x, n);
    sort(x, n);
}
#include<fstream>//ifstream read open
#include<iostream>//cout
#include<cstring>//使用strcat
using namespace std;
int main()
{
    ifstream file;
    //ifstream instream;
    //ofstream outstream;
    char file_name[30];
    int x;
    char buffer[90];
    char file_type[5] = {".txt"};
    while(cin >> file_name>>x)
    {
    strcat(file_name, file_type);//字串的合併
    file.open(file_name);

    //file.read(buffer, sizeof(buffer));//讀入檔案資料存進buffer 
    //outstream.open("outfile.txt");
    /*int x, y, z;
    instream >> x >> y >> z;
    outstream <<"the sum is "<< (x + y + z);
    instream.close();
    outstream.close();*/
}

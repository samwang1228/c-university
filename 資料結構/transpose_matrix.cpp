# include<iostream>
# include<assert.h>
using namespace std;
struct Trituple{        //自定義資料結構：矩陣元素的行，列，值；
	int row,col;
	int value;
};
class SparseMatrix{    //稀疏矩陣
private:
	int Rows,Cols,Terms;   //行數，列數，非零元素的個數
	Trituple *smArray;   //存非零元素的三元陣列
	int maxTerms;    //三元組最大可容納的元素個數
public:
	SparseMatrix(int maxrows,int maxcols,int maxterms);  //建構函式
	SparseMatrix(SparseMatrix& SM);      //賦值建構函式
	~SparseMatrix(); //解構函式
	SparseMatrix Transpose(SparseMatrix &b);     //矩陣轉置
	friend ostream& operator<<(ostream& ostr,SparseMatrix& SM); //矩陣的輸出過載函式
	friend istream& operator>>(istream& istr,SparseMatrix& SM); //矩陣的輸入過載函式
};
SparseMatrix::SparseMatrix(int maxrows,int maxcols,int maxterms){     //建構函式：構造一個大小為maxTerm的三元組，行列數和非零元素個數都置零
	if(maxterms<1){
		cerr<<"矩陣初始化錯誤！"<<endl;
		exit(1);
	}
	smArray=new Trituple[maxterms];
	cout << maxterms;
	assert(smArray!=NULL);
	Rows=Cols=Terms=0;
}
SparseMatrix::SparseMatrix(SparseMatrix& SM){  //複製建構函式
	Rows=SM.Rows;      //賦值矩陣的性質
	Cols=SM.Cols;
	Terms=SM.Terms;
	maxTerms=SM.maxTerms;
	smArray=new Trituple[maxTerms];  //構造三元組並賦與SM相同的值
	assert(smArray!=NULL);
	for(int i=0;i<Terms;i++)
		smArray[i]=SM.smArray[i];
}
SparseMatrix::~SparseMatrix(){   //解構函式：釋放所有儲存
	delete[]smArray;
}
ostream& operator<<(ostream& ostr,SparseMatrix& SM){  
	ostr<<"# Rows="<<SM.Rows<<endl;    //輸出該矩陣的性質
	ostr<<"# Cols="<<SM.Cols<<endl;
	ostr<<"# Terms="<<SM.Terms<<endl;
	for(int i=0;i<SM.Terms;i++)   //輸出該矩陣非零元素的位置及值
		ostr<<i+1<<": "<<"triple<"<<SM.smArray[i].row<<","<<SM.smArray[i].col<<">="<<
		SM.smArray[i].value<<endl;
	return ostr;
}
istream& operator>> (istream& istr,SparseMatrix& SM){  //輸入運算子過載
	cout<<"Please enter number of rows,columns,and terms of Matrix"<<endl;
	istr>>SM.Rows>>SM.Cols>>SM.Terms;  //輸入元素的性質
	if(SM.Terms>SM.maxTerms){
		cerr<<"Numbers of Terms overflow!"<<endl;
		exit(1);
	}
	for(int i=0;i<SM.Terms;i++){   
		cin>>SM.smArray[i].row>>SM.smArray[i].col>>SM.smArray[i].value;
	}
	return istr;
}
SparseMatrix SparseMatrix::Transpose(SparseMatrix &b){   //轉置函式
	int *rowSize=new int[Cols]; //轉置矩陣每行非零元素的個數
	//int *rowStart=new int[Cols]; //轉置矩陣每行第一個非零元素對應其三元組的下標
    //rowStart[0] = 0;
    if (Terms > 0)
    {
        int i, j,total=0;
        for (i = 0; i < Cols; i++) //對rowSize陣列賦值
            rowSize[i] = 0;
        for (i = 0; i < Terms; i++)
            rowSize[smArray[i].col]++;
        //  for (int i = 0; i < 6;i++)
        // {
        //     cout << rowSize[i]<<" ";
        // }
        for (i = 1; i < Cols; i++)
        {
            //rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            total = rowSize[i-1] + total; //累加rowsize值
            rowSize[i - 1] = total - rowSize[i - 1];//因為用rowsize[i]會干擾後面的運算所以要從i-1開始
            if(i==Cols-1)
                rowSize[i] = total;//因為是計算[i-1]所以最後一個for不會跑到要額外討論
       
        }
		 rowSize[0] = 0;
		 for (int i = 0; i < 6;i++)
        {
            cout << rowSize[i]<<" ";
        }
            for (i = 0; i < Terms; i++)
            {                                      //遍歷三元組a，把各個元素按rowStart陣列存在b中相應的位置
                j = rowSize[smArray[i].col];       //a陣列中行號按從小到大的順序排列，所以相同列最先遇到的元素肯定處在相應轉置矩陣相應行中的最前面
                b.smArray[j].row = smArray[i].col; //把該元素按照找到的下標j存入b中
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                rowSize[smArray[i].col]++; //因為該值已經存入b，所以轉置矩陣的該行下一個元素在b中對應的下標為rowStart[smArray[i].col]++；
            }
     }
	delete[] rowSize; //釋放new申請的儲存空間
	return b;
}
int main()
{
    SparseMatrix ans(5,5,8);
    cin >> ans;
    SparseMatrix ans2 = ans;
    ans.Transpose(ans2);
    cout << ans2;
	//ans.~SparseMatrix();
}
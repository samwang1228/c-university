# include<iostream>
# include<stdlib.h>
# include<iomanip>
using namespace std;
class Trituple{       
	friend class SparseMatrix;
public:
	int row,col,value;
};
class SparseMatrix{    //稀疏矩陣
private:
	int Rows,Cols,Terms;   
	Trituple *smArray;   //存非零元素的三元陣列
public:
	SparseMatrix(int maxrows,int maxcols,int maxterms);  
    SparseMatrix() {}
	SparseMatrix Transpose();     //矩陣轉置
	friend ostream& operator<<(ostream& ostr,SparseMatrix& SM); 
	friend istream& operator>>(istream& istr,SparseMatrix& SM); 
};
SparseMatrix::SparseMatrix(int maxrows,int maxcols,int maxterms){     //建構函式：構造一個大小為maxTerm的三元組，行列數和非零元素個數都置零
    Rows = maxrows;
	Cols = maxcols;
	Terms = maxterms;
	smArray=new Trituple[maxterms];
}
ostream& operator<<(ostream& ostr,SparseMatrix& SM){  
	ostr<<"# Rows="<<SM.Rows<<endl;   
	ostr<<"# Cols="<<SM.Cols<<endl;
	ostr<<"# Terms="<<SM.Terms<<endl;
    ostr << "T : Triple<Rows,Cols,Value>" << endl;
    for(int i=0;i<SM.Terms;i++)   
		ostr<<i+1<<" :"<<" Triple<"<<setw(4)<<SM.smArray[i].row<<setw(5)<<SM.smArray[i].col<<setw(6)<<
		SM.smArray[i].value<<">"<<endl;
	return ostr;
}
istream &operator>> (istream& istr,SparseMatrix& SM){  
	cout<<"Please enter number of rows,columns,and terms of Matrix"<<endl;
	int r, c, t;
	istr>>r>>c>>t; 
    SM = SparseMatrix(r, c, t);
    for(int i=0;i<SM.Terms;i++){   
		istr>>SM.smArray[i].row>>SM.smArray[i].col>>SM.smArray[i].value;
	}
	return istr;
}
SparseMatrix SparseMatrix::Transpose(){   //轉置函式
	SparseMatrix b(Rows,Cols,Terms);
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
		for (i = 1; i < Cols; i++)
        {
            //rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            total = rowSize[i-1] + total; //累加rowsize值
            rowSize[i - 1] = total - rowSize[i - 1];//因為用rowsize[i]會干擾後面的運算所以要從i-1開始
            if (i == Cols - 1)
                rowSize[i] = total; //因為是計算[i-1]所以最後一個for不會跑到要額外討論
        }
		 rowSize[0] = 0;
            for (i = 0; i < Terms; i++)
            {                                      //遍歷三元組a，把各個元素按rowStart陣列存在b中相應的位置
                j = rowSize[smArray[i].col];       //a陣列中行號按從小到大的順序排列，所以相同列最先遇到的元素肯定處在相應轉置矩陣相應行中的最前面
                b.smArray[j].row = smArray[i].col; //把該元素按照找到的下標j存入b中
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                rowSize[smArray[i].col]++; //因為該值已經存入b，所以轉置矩陣的該行下一個元素在b中對應的下標為rowStart[smArray[i].col]++；
            }
     }
	delete[] rowSize; 
    return b;
}
int main()
{
    SparseMatrix ans,ans2;
    cin >> ans; 
    ans2=ans.Transpose();
    cout << ans2;
}

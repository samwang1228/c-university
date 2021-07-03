# include<iostream>
# include<stdlib.h>
# include<iomanip>
using namespace std;
class Trituple{       
	friend class SparseMatrix;
public:
	int row,col,value;
};
class SparseMatrix{    //�}���x�}
private:
	int Rows,Cols,Terms;   
	Trituple *smArray;   //�s�D�s�������T���}�C
public:
	SparseMatrix(int maxrows,int maxcols,int maxterms);  
    SparseMatrix() {}
	SparseMatrix Transpose();     //�x�}��m
	friend ostream& operator<<(ostream& ostr,SparseMatrix& SM); 
	friend istream& operator>>(istream& istr,SparseMatrix& SM); 
};
SparseMatrix::SparseMatrix(int maxrows,int maxcols,int maxterms){     //�غc�禡�G�c�y�@�Ӥj�p��maxTerm���T���աA��C�ƩM�D�s�����ӼƳ��m�s
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
SparseMatrix SparseMatrix::Transpose(){   //��m�禡
	SparseMatrix b(Rows,Cols,Terms);
    int *rowSize=new int[Cols]; //��m�x�}�C��D�s�������Ӽ�
	//int *rowStart=new int[Cols]; //��m�x�}�C��Ĥ@�ӫD�s����������T���ժ��U��
    //rowStart[0] = 0;
    if (Terms > 0)
    {
        int i, j,total=0;
        for (i = 0; i < Cols; i++) //��rowSize�}�C���
            rowSize[i] = 0;
        for (i = 0; i < Terms; i++)
            rowSize[smArray[i].col]++;
		for (i = 1; i < Cols; i++)
        {
            //rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            total = rowSize[i-1] + total; //�֥[rowsize��
            rowSize[i - 1] = total - rowSize[i - 1];//�]����rowsize[i]�|�z�Z�᭱���B��ҥH�n�qi-1�}�l
            if (i == Cols - 1)
                rowSize[i] = total; //�]���O�p��[i-1]�ҥH�̫�@��for���|�]��n�B�~�Q��
        }
		 rowSize[0] = 0;
            for (i = 0; i < Terms; i++)
            {                                      //�M���T����a�A��U�Ӥ�����rowStart�}�C�s�bb����������m
                j = rowSize[smArray[i].col];       //a�}�C���渹���q�p��j�����ǱƦC�A�ҥH�ۦP�C�̥��J�쪺�����֩w�B�b������m�x�}�����椤���̫e��
                b.smArray[j].row = smArray[i].col; //��Ӥ������ӧ�쪺�U��j�s�Jb��
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                rowSize[smArray[i].col]++; //�]���ӭȤw�g�s�Jb�A�ҥH��m�x�}���Ӧ�U�@�Ӥ����bb���������U�Ь�rowStart[smArray[i].col]++�F
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


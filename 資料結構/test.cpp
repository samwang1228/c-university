#include<stdio.h>
#include<malloc.h>
#include<Error.h>
#include<stdlib.h>
#include<Windows.h>


//节点定义
struct Node
{
	int Coefficient;	//系数
	int Exponent;		//指数
	Position Next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;		//以次幂(指)数降序排序的多项式
typedef PtrToNode Position;			//节点

//链表移动
Position Advance(Position P)
{
	return P->Next;
}

//多项式项数
int NumberOfPolynomialTerms(Polynomial Py)
{
	Position Tmp;
	int Num = 0;

	if(Py == NULL)
		return Num;

	Tmp = Py->Next;
	while(Tmp != NULL)
	{
		Tmp = Advance(Tmp);
		Num++;
	}

	return Num;
}

void Insert(int Coefficient,int Exponent, Polynomial L, Position P)
{
	Position TmpCell;

	TmpCell = (Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		perror("Out of space");
		exit(1);
	}

	TmpCell->Coefficient = Coefficient;
	TmpCell->Exponent = Exponent;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

Polynomial UnionOfLinkList(Polynomial L1, Polynomial L2)
{
	Polynomial TmpPoly;
	Position P,Polyi,Polyj;
	
	TmpPoly = (struct Node*)malloc(sizeof(struct Node));
	if(TmpPoly == NULL)
	{
		perror("Out of Space");
		exit(1);
	}

	TmpPoly->Next = NULL;
	P = TmpPoly;
	Polyi = L1->Next;
	Polyj = L2->Next;
	
	while(Polyi && Polyj)
	{
		if(Polyi->Exponent > Polyj->Exponent)
		{
			//PFL;
			Insert(Polyi->Coefficient,Polyi->Exponent,TmpPoly,P);
			Polyi = Advance(Polyi);
	
			P = Advance(P);
		}
		else if(Polyi->Exponent < Polyj->Exponent)
		{
			Insert(Polyj->Coefficient,Polyj->Exponent,TmpPoly,P);
			Polyj = Advance(Polyj);
	
			P = Advance(P);
		}
		else
		{
			Insert(Polyi->Coefficient+Polyj->Coefficient,Polyj->Exponent,TmpPoly,P);
	
			Polyi = Advance(Polyi);
			Polyj = Advance(Polyj);
	
			P = Advance(P);
		}
	}//end while
	
	while(Polyi != NULL)
	{
		Insert(Polyi->Coefficient,Polyi->Exponent,TmpPoly,P);
		Polyi = Advance(Polyi);
	
		P = Advance(P);
	}
	while(Polyj != NULL)
	{
		Insert(Polyj->Coefficient,Polyj->Exponent,TmpPoly,P);
		Polyj = Advance(Polyj);
	
		P = Advance(P);
	}

	return TmpPoly;
}

//多项式相乘       算法时间复杂度 O(M^2N),其中M是具有较小项数的多项式的项数
Polynomial MulPolynomialM2N(Polynomial P1,Polynomial P2)
{
	Polynomial Tmp1,Tmp2,TmpPoly;
	Position Pre;

	int Num = NumberOfPolynomialTerms(P1);
	struct Node **PolyProd = (struct Node **)malloc(sizeof(struct Node*)*Num);

	//选取较小项数的多项式
	if(NumberOfPolynomialTerms(P1)>NumberOfPolynomialTerms(P2))
		return MulPolynomialM2N(P2,P1);

	Tmp1 = P1->Next;
	for(int i=0;Tmp1 != NULL;i++)            //以较小项数的多项式每一项分别乘以较大项数的多项式   (乘法时间）O(MN)
	{
		//申请内存
		PolyProd[i] = (struct Node *)malloc(sizeof(struct Node));
		if(PolyProd[i] == NULL)
		{
			perror("Out of Space");
			exit(1);
		}

		PolyProd[i]->Next = NULL;
		Pre = PolyProd[i];					//移动节点
		Tmp2 = P2->Next;
		while(Tmp2 != NULL)
		{
			Insert(Tmp1->Coefficient*Tmp2->Coefficient,Tmp1->Exponent + Tmp2->Exponent,PolyProd[i],Pre);
			Pre = Advance(Pre);
			Tmp2 = Advance(Tmp2);
		}
		Tmp1 = Advance(Tmp1);
	}

	TmpPoly = (struct Node*)malloc(sizeof(struct Node));
	if(TmpPoly == NULL)
	{
		perror("Out of Space");
		exit(1);
	}

	TmpPoly->Next = NULL;

	for(int i=0;i<Num;i++)			//（求并时间）O((N+N)+(2N+N)+(3N+N)+……+(MN+N)) = O(M^2N)
	{
		TmpPoly = UnionOfLinkList(TmpPoly,PolyProd[i]);
	}
	return TmpPoly;
}

void PrintfPolynomial(Polynomial P)
{
	Position Ps = P->Next;
	while(Ps->Next != NULL)
	{
		if(Ps->Next->Coefficient<0)
			printf("%d*X^%d",Ps->Coefficient,Ps->Exponent);
		else
			printf("%d*X^%d+",Ps->Coefficient,Ps->Exponent);		//格式输出

		Ps=Advance(Ps);
	}

	if(Ps->Exponent == 0)
	{
		printf("%d",Ps->Coefficient);		//格式输出
	}
	else
	{
		printf("%d*X^%d",Ps->Coefficient,Ps->Exponent);		//格式输出
	}
}

Polynomial CreatePolynomial(int n)
{
	Polynomial head=(struct Node *)malloc(sizeof(struct Node)),p,pre=head;//head指向头结点，p指向新开辟的节点
	int coef; //系数
	int exp;	//指数
	if(NULL==head)
	{
		printf("开辟头结点失败\n");
		exit(-1);
	}
	head->Next=NULL;
	for(int i=0;i<n;i++)
	{
		if(NULL==(p=(struct Node *)malloc(sizeof(struct Node))))
		{
			printf("新结点malloc失败\n");
			exit(-1);
		}
		printf("请输入第%d个系数:",i+1);
		scanf("%d",&coef);
		printf("请输入第%d个指数:",i+1);
		scanf("%d",&exp);
		
		p->Coefficient=coef;
		p->Exponent=exp;  //更新节点数据
		p->Next=NULL;
		//插入节点
		pre->Next=p;
		pre=p;	
	}
	return  head;	//这里是返回堆的内存区 不是局部变量
}

int main()
{
	printf("  链表实现多项式的乘法   \n");
	printf("----by senly----\n\n");
	
	int n;
	
	printf("请输入A(X)的项数(降幂排列)\n");
	scanf("%d",&n);
	Polynomial head_a=CreatePolynomial(n);
	printf("A(X)=");
	PrintfPolynomial(head_a);

	printf("\n请输入B(X)的项数(降幂排列)\n");
	scanf("%d",&n);
	Polynomial head_b=CreatePolynomial(n);
	printf("B(X)=");
	PrintfPolynomial(head_b);
	printf("\n");

	Polynomial head_e=MulPolynomialM2N(head_a,head_b);
	printf("\nE(X)=A(X)*B(X)=");
	PrintfPolynomial(head_e);
	printf("\n");
	
	system("pause");
	return 0;
}
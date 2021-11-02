#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std ;
void multiply_matrix(int **a,int **b,int **c,int n);
void Add(int **a, int **b, int **c, int n);
int main(){
	int **a,**b,**c,n;
	n = 100;
    a = (int **)malloc(n * sizeof(int *));
    for (int i=0 ; i<n; i++){
		a[i] = (int*)malloc(n*sizeof(int));
	}
	c= (int **)malloc(n * sizeof(int *));
	for (int i=0 ; i<n; i++){
		c[i] = (int*)malloc(n*sizeof(int));
	}
	b = (int **)malloc(n * sizeof(int *));
	for (int i=0 ; i<n ; i++){
		b[i] = (int*)malloc(n*sizeof(int));
	}
	while(n<=3000)
	{
	double start_time, end_time;
	start_time = clock();

	a = (int **)realloc(a, sizeof(int *) * n);
	for (int i = 0; i < n;i++)
		a[i] = (int *)malloc(sizeof(int) * n);

	b = (int **)realloc(b, sizeof(int *) * n);
	for (int i = 0; i < n;i++)
		b[i] = (int *)malloc(sizeof(int) * n);

	c = (int **)realloc(c, sizeof(int *) * n);
	for (int i = 0; i < n;i++)
		c[i] = (int *)malloc(sizeof(int) * n);
	
	for(int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			a[i][j] = 1;
		}
	}

	for(int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			b[i][j] = 1;
		}
	}
	
	//select your type
	// -------------------------
	
	// multiply_matrix(a,b,c,n);
	Add(a,b,c,n);

	//--------------------------
	//
	// for(int i=0 ; i<n ; i++){
	// 	for(int j=0 ; j<n ; j++){
	// 		cout <<c[i][j]<<" ";
	// 	}
	// 	cout << endl;
	// }
	end_time = clock();
	//cout << CLOCKS_PER_SEC<<endl;
	cout << double((end_time - start_time)  )<< endl;
	n+= 100;
	}
} 
void multiply_matrix(int **a,int **b,int **c,int n){
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            for (int k = 0; k < n;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void Add(int **a,int **b,int **c,int n){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			c[i][j] = a[i][j]+b[i][j];
		}
	}
}

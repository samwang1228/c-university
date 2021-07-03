#include <iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std ;
void Add(int **a,int **b,int **c,int n);
int main(){
	int **a,**b,**c,n;
	n = 100;
		a = new int *[n];
	for (int i=0 ; i<n; i++){
		a[i] = new int [n];
	}
		c = new int *[n];
	for (int i=0 ; i<n; i++){
		c[i] = new int [n];
	}
		b = new int *[n];
	for (int i=0 ; i<n ; i++){
		b[i] = new int [n];
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
	
	Add(a,b,c,n);
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
void Add(int **a,int **b,int **c,int n){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			c[i][j] = a[i][j]+b[i][j];
		}
	}
}

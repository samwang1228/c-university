#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int T;
  char letter;
  int num;
  while( scanf( "%d", &T ) != EOF ){
    getchar();
    for( int i = 1 ; i <= T ; i++ ){
      printf( "Case %d: ", i );
      while( letter = getchar() ){
        if( letter == '\n' ){
          printf( "\n" );
          break;
        }
        scanf( "%d", &num );
        for( int j = 0 ; j < num ; j++ )
          printf( "%c", letter );
      }
    }
  }
  return 0;
}
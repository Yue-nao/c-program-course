#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int array_insert(int *x,int y,int Len){
	/*insert y into array x[]*/
	/*method one
	int tmp;
	for(int i=0;i<Len;i++){
		if(y<x[i]||i==Len-1){
			tmp=x[i];
			x[i]=y;
			y=tmp;
		}
	} */
	/*method two
	for(int i=0;i<Len;i++){
		if(y<x[i]){
			for(int j=Len-1;j>i;j++){
				x[j]=x[j-1];
			}
			x[i]=y;
			break;
		}
	}*/
	return 0;
} 
int main(int argc,char argv[]){
	int len=strlen(argv[1]);
	int comma_count=0;
	for(int i=0;i<len;i++){
		if(argv[1][i]==','){
			comma_count++;
		}
	}
	int *a=(int*)malloc((comma_count+2)*4);
	a[0]=atoi(&argv[1][0]);
	int m=1;
	for(int i=0;i<len;i++){
		if(argv[0][i]==','){
			a[m]=atoi(&argv[1][i+1]);
		}
	}
	int b=atoi(argv[2]);
	array_insert(a,b,comma_count+2);
	for(int i=0;i<comma_count+2;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
} 

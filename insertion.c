#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int array_insert(int *x,int y,int Len){
	/*insert y into array x[]*/
	int tmp=Len-1;
	for(int i=0;i<Len-1;i++){
		if(y<x[i]){
			tmp=i;
			break;
		}
	}
	for(int i=Len-1;i>tmp;i--){
		x[i]=x[i-1];
	}
	x[tmp]=y; 
	return 0;
}
int printf_array(int *x,int len){
	for(int i=0;i<len;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
	return 0;
}
int main(int argc,char *argv[]){
	int len=strlen(argv[1]);
	int comma_count=0;
	for(int i=0;i<len;++i){
		if(argv[1][i]==','){
			comma_count++;
		}
	}
	int *a=(int*)malloc((comma_count+2)*4);
	a[0]=atoi(&argv[1][0]);
	int m=1;
	for(int i=0;i<len;i++){
		if(argv[1][i]==','){
			a[m]=atoi(&argv[1][i+1]);
			m++;
		}
	}
	printf_array(a,m);
	int b=atoi(argv[2]);
	array_insert(a,b,m+1);
	printf_array(a,m+1);
	free(a); 
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int array_sort(int *x,int len){
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(x[i]>x[j]){
				int tmp=x[i];
				x[i]=x[j];
				x[j]=tmp;
			}
		}
	}
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
	array_sort(a,m);
	printf_array(a,m);
	free(a); 
	return 0;
} 

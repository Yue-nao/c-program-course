#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min_value_location(int *a,int len)
{
	int location=0;
	int tmp=a[0];
	for(int i=1;i<len;i++)
	{
		if(a[i]<tmp)
		{
			location=i;
			tmp=a[i];
		}
	}
	a[location]=a[0];
	a[0]=tmp;
	return 0;
}
int printf_array(int *x,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
	return 0;
}
int main(int argc,char *argv[])
{
	int len=strlen(argv[1]);
	int comma_count=0;
	for(int i=0;i<len;++i)
	{
		if(argv[1][i]==',')
		{
			comma_count++;
		}
	}
	int *a=(int*)malloc((comma_count+1)*4);
	a[0]=atoi(&argv[1][0]);
	int m=1;
	for(int i=0;i<len;i++)
	{
		if(argv[1][i]==',')
		{
			a[m]=atoi(&argv[1][i+1]);
			m++;
		}
	}
	printf_array(a,m);
	for(int i=0;i<m-1;i++)
	{
		min_value_location(a+i,m-i);
	}
	min_value_location(a,m);
	printf_array(a,m);
	free(a); 
	a=NULL; 
	return 0;
}

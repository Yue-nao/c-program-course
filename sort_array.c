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
	printf("The min value is %d\n",tmp);
	printf("The index is %d\n",location); 
	return 0;
} 
int array_sort(int *x,int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(x[i]>x[j])
			{
				int tmp=x[i];
				x[i]=x[j];
				x[j]=tmp;
			}
		}
	}
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
	min_value_location(a,m);
	array_sort(a,m);
	printf_array(a,m);
	free(a); 
	a=NULL; 
	return 0;
} 

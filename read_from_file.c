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
int sort_array(int *a,int len)
{
        for(int i=0;i<len-1;i++)
        {
                min_value_location(a+i,len-i);
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
int print_file(char *filename)
{
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Error: open file failed");
		return 1;
	}//check whether the file exists	
	char a[200];
	//fgets(a,sizeof(a),fp);//read the top line of the file
	char *p=fgets(a,sizeof(a),fp);
	while(p!=NULL)//if the last line was read,fgets() will return NULL
	{
		int m[10];
		int len=0;
		char *token=strtok(a,",\n");
		while(token!=NULL)
		{
			m[len]=atoi(token);
			len++;
			token=strtok(NULL,",\n");
		}
		sort_array(m,len);
		printf_array(m,len);
		p=fgets(a,sizeof(a),fp);
	}
	fclose(fp);
	return 0;
}
int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("Please input a filename:");
		return 1;
	}
	char *filename=argv[1];
	print_file(filename);
	return 0;
} 

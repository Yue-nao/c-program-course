#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int print_file(char *filename)
{
	FILE *fp=fopen(filename,"r");
	char a[200];
	fgets(a,200,fp);
	printf("%s",a);
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

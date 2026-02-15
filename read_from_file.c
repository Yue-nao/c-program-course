#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		char *token=strtok(a,",");
		while(token!=NULL)
		{
			int tmp=atoi(token);
			printf("%d ",tmp);
			token=strtok(NULL,",");
		}
		printf("\n");
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

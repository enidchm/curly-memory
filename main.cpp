#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    else return 0;
}
void moveczf(char *p)
{
	while(*p!='\0')
	{
		*p=*(p+1);
		p++;
	}
}
void moveczs(float *p,float *end)
{
	while(p!=end)
	{
		*p=*(p+1);
		p++;
	}
}
int main()
{
	char str[100];
	char czf[100]={'\0'}; 
	float czs[100];
	printf("please input a string, but only + - * / can be included:\n");
	scanf("%s",str);

	int czfxb=0; 
	for(int i=0;i<strlen(str);i++)
	{
		if(isOperator(str[i]))
		{  
		    czf[czfxb]=str[i]; 
		    czfxb++;
	    }
    }
}
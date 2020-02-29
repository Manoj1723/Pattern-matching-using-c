#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[100],pat[50];
int i,j,c,m,k,t,flag=0;
void stringmatch()
{
m=c=j=0;
if(pat[0]=='*')
pat[0]=0;
for(i=1;i<strlen(pat);i++)
{
	if(pat[i]=='*')
	pat[i]=pat[i-1];
}
i=0;
while(str[c]!='\0')
{
if((pat[i]==str[c])||(pat[i]=='.'))
{
for(k=0;str[k]!='\0';k++)
{
	if((pat[i]==str[m])||(pat[i]=='.'))
	{
	m++;
	i++;
		t=1;
	}
	else
	{
		t=0;
		m=0;i=j;
		break;
	}
}
if(t)
{
	flag=1;
	return;
}
else
{
	i++;
	m++;
	c=m;
}
}
else
{
	i++;
	j++;
}
}
}
int main()
{
printf("\nEnter a main string \n");
gets(str);
printf("\nEnter a pattern string \n");
gets(pat);
for(i=0;i<=strlen(pat);i++)
{
	if(pat[i]=='.')
	{
		if(pat[i+1]=='*')
		{
			printf("Pattern Match\n");
			exit(0);
		}
	}
}
if(strlen(pat)>=strlen(str))
stringmatch();
if(flag==1)
printf("\nPattern Match\n");
else
printf("\nPattern not match\n");
return 0;
}

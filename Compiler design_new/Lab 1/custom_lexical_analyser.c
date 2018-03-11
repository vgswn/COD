#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int iskey(char *s)
{
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i;
    for(i=0;i<32;i++)
    {
    	if(strcmp(s,keywords[i])==0)
    	{
    		return 1;
    	}
    }
    return 0;
}
int isnum(char *s)
{
	int i,l;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(!(s[i]>=48&&s[i]<=57))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	FILE *fp=fopen("inp.txt","r");
	if(fp==NULL)
	{
		printf("Error in reading file\n");
		exit(0);
	}
	char ch;
	char str[1005];
	while(!feof(fp))
	{
		fscanf(fp," %[^\n]s",str);
		if(str[0]=='#')
		{
			continue;
		}
		//printf("%s\n",str);
		int i,l,j;
		l=strlen(str);
		char buf[1005];
		j=0;
		for(i=0;i<l;i++)
		{
			ch=str[i];
			if(ch=='/'&&i+1<l&&str[i+1]=='/')
			{
				break;
			}
			if(ch=='"')
			{
				j=0;
				buf[j++]=str[i];
				i++;
				while(i<l&&str[i]!='"')
				{
					buf[j++]=str[i++];
				}
				buf[j++]=str[i++];
				buf[j]='\0';
				if(iskey(buf))
				{
					printf("%s is a keyword\n",buf);
				}
				else
				{
					printf("%s is a constant\n",buf);
				}
				j=0;
			}
			if(ch==';')
			{
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}
				printf("%c is a symbol\n",ch);
			}
			else if(ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}'||ch==',')
			{
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}
				printf("%c is a symbol\n",ch);				
			}
			else if(ch=='+'||ch=='-'||ch=='/'||ch=='%'||ch=='*'||ch=='=')
			{
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}
				printf("%c is a operator\n",ch);				
			}
			else if(ch=='<'||ch=='>'||ch=='!')
			{
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}
				if(i+1<l&&str[i+1]=='=')
				{
					i++;
					printf("%c= is a operator\n",ch);
				}
				else
				{
					printf("%c is a operator\n",ch);
				}
			}
			else if(ch=='&'||ch=='|')
			{
				if(i+1<l&&(str[i+1]=='&'||str[i+1]=='|'))
				{
					printf("%c%c is a operator\n",ch,str[i+1]);
					i++;
				}
				else
				{
					printf("%c is a operator\n",ch);
				}
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}
			}
			else if(ch==' ')
			{
				if(j>0)
				{
					buf[j]='\0';
					j=0;
					if(iskey(buf))
					{
						printf("%s is a keyword\n",buf);
					}
					else if(isnum(buf))
					{
						printf("%s is a constant\n",buf);
					}
					else
					{
						printf("%s is a identifier\n",buf);
					}
				}				
			}
			else if(ch!=9&&ch!='"')
			{
				buf[j++]=ch;
			}
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<dij.h>
#include<interface.h>
void makemanu()
{
	printf("------------------------------------\n");
	printf("	Route Finding System\n");
	
}
void inteRFace()
{
	makemanu();
	printf("\tWelecome!\n");
	system("pause");
	system("cls");
	while(1){
	printf("Import new map(Y) or Using the initial map(Any other key)\n");
	system("cls");
	char a[10];
	gets(a);
	int b;
	if(a=='Y')
	{
		printf("please enter the file name:\n");
		system("cls");
		gets(a);
		FILE *fp=fopen(a, "r");
		b=read_map(fp);
	}
	else
	{
		FILE *fp=fopen("../Final_Map.map", "r");
		b=read_map(fp);
	}
	if(b==0)
	{
		printf("File reading failure\nDo you want to read again?(Y/Any other key)\n");
		system("cls");
		gets(a);
		if(a=='Y')continue;
		else break;
	}
	if(b==1)
	{
		printf("please enter the start node ID:\n");
		gets(a);
		long long x=0,y=1;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]>'9'||a[i]<'0')
			{
				if(i==0)
				{
					if(a[i]=='-')
					{
						y=-1;continue;
					}
					else{
						flag1=1;
						break;
					}
				}
				flag1=1;
				break;
			}
			if(a[i]<='9'&&a[i]>='0')
			{
				X=X*10+buf[i]-'0';
			}
		}x=x*y;
		
	}
	}

}

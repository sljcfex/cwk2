#include<stdio.h>
#include<string.h>
#include"dij.h"
#include"interface.h"
#include <stdlib.h>

struct edge e[maxn];
struct add_edge ae[maxn];
int cn;
double tr[maxn],dis[maxn];
int cnt;
int head[maxn],pos[maxn],pre[maxn];
long long node[maxn];
int b=-1;
char a[20];
long long u,v,x2,x1;
double inf=0x3f3f3f3f;
void tile()
{
	printf("------------------------------------\n");
	printf("	Route Finding System\n");
	
}
void welcome()
{
    printf("\tWelecome!\n");
    system("pause");
   // system("cls");
}

void load_map()
{
    printf("Import new map(Y) or Using the initial map(Any other key)\n");
    getchar();
    gets(a);
    //system("cls");
    if(a[0]=='Y')
    {
        printf("please enter the file name:\n");

        gets(a);
        //system("cls");
        FILE *fp=fopen(a, "r");
        b=read_map(fp);
    }
    else
    {
        FILE *fp=fopen("../Final_Map.map", "r");
        b=read_map(fp);
    }
    if(b==-1)
    {
        printf("File reading failure\nDo you want to read again?(Y/Any other key)\n");

        gets(a);

        if(a[0]=='Y')load_map();
        else return;
    }
    else{
        printf("loading successful!\n");
    }
}

void read_node_st()
{
    printf("please enter the start node ID:\n");
   // system("cls");
   //getchar();
    scanf("%s",a);
    long long x=0,y=1;
    int flag1=0;
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
            x=x*10+a[i]-'0';
        }
    }x1=x*y;
    if(flag1==1){
        u=-1;
        printf("The input contains invalid characters, please re-enter(Y) or exit(any other key) \n");
        scanf("%s",a);
        if(a[0]=='Y')
        {
            read_node_st();
        }
        else return;
    }
    u= find2(x1,0,cn);
    if(u==-1){
        printf("Cannot find this node, please re-enter(Y) or exit(any other key) \n");
        scanf("%s",a);
        if(a[0]=='Y')
        {
            read_node_st();
        }
        else return;
    }

}
void read_node_ed()
{
    printf("please enter the end node ID:\n");
    // system("cls");
   // getchar();
    scanf("%s",a);
    long long x=0,y=1;
    int flag1=0;
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
            x=x*10+a[i]-'0';
        }
    }x2=x*y;
    if(flag1==1){
        v=-1;
        printf("The input contains invalid characters, please re-enter(Y) or exit(any other key) \n");
        gets(a);
        if(a[0]=='Y')
        {
            read_node_st();
        }
        else return;
    }
    v= find2(x2,0,cn);
    if(v==-1){
        printf("Cannot find this node, please re-enter(Y) or exit(any other key) \n");
        gets(a);
        if(a[0]=='Y')
        {
            read_node_st();
        }
        else return;
    }
}
void makemanu()
{
    printf("1.Query the shortest circuit between two points\n");
    printf("2.Load the map file\n");
    printf("3.Draw current map\n");
    printf("0.exit\n");
}

void inteRFace()
{
	tile();
	welcome();
    system("cls");
	while(1){
        makemanu();
      //  system("cls");
        int key;
        scanf("%d",&key);
        switch (key) {
            case 0:
                printf("exit\n");
              //  system("cls");
                return;
            case 1:
                if(b==-1)
                {
                    printf("No map loading\n");
                    continue;
                }
                if(b==0){
                    read_node_st();
                    if(u==-1)
                    {
                        return;
                    }
                    read_node_ed();
                    if(v==-1)
                    {
                        return;
                    }
                    dijkstra(u);
                    if(dis[v]>inf)printf("There's no path between N1 and N2!\n");
                    else{
                        printf("The shortest path from Node%lld to Node%lld is %lf\n",x1,x2,dis[v]);
                        printf("the path is:\n");
                    }


                }
                break;
            case 2:
                load_map();
                break;
            default:
                printf("Please enter valid characters\n");
                break;
        }
	}
}

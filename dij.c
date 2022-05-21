#include<stdio.h>
#include<string.h>
#include<dij.h>
#define ls rt<<1
#define rs rt<<1|1
#define maxn 10000
void quick_sort(long long *num,int l,int r){
	if(l+1>=r){
		return ;
	}
	int first=l,last=r-1,key=num[first];
	while(first<last){
		while(first<last&&num[last]>=key){
			--last;
		}
		num[first]=num[last];
		while(first<last&&num[first]<key){
			++first;
		}
		num[last]=num[first];
	}
	num[first]=key;
	quick_sort(num,l,first);
	quick_sort(num,first+1,r);
}

int find2(long long x,int l,int r)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(x>node[mid])return find2(x,mid+1,r);
	else return find2(x,l,mid);
}

void add(int u,int v,double w)
{
    static int c=0;
	e[++c].w=w;
	e[c].v=v;
	e[c].nxt=head[u];
	head[u]=c;
}

void pushup(int rt)
{
	if(tr[ls]<=tr[rs])
	{
		tr[rt]=tr[ls];
		pos[rt]=pos[ls];
	}
	else {
		tr[rt]=tr[rs];
		pos[rt]=pos[rs];
	}
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		tr[rt]=inf;
		pos[rt]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(rt);
}

void update(int l,int r,int rt,int p,double w)
{
	if(l==r)
	{
		tr[rt]=w;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)update(l,mid,ls,p,w);
	else update(mid+1,r,rs,p,w);
	pushup(rt);
}

void dijkstra(int s) {
    build(1,cn,1);
    update(1,cn,1,s,0);
    for(int i=0;i<=maxn;i++)dis[i]=inf;
    dis[s]=0;
    while (tr[1]!=inf) {
        int u=pos[1];
        update(1,cn,1,u,inf);
        for (int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;double w=e[i].w;
            if (dis[u]+w<dis[v])
                dis[v]=dis[u]+w,update(1,cn,1,v,dis[v]),pre[i]=v;
        }
    }
}

int read_map(FILE *file)
{
	if (file == NULL)
    {
        printf("File opened failed, exit.");
        return -1;
    }
    char temp[55];
    memset(temp,'\0',50);
    char buf[200];
   int k=0;
   while ( (fgets(buf, 200, file)) != NULL) {

    	if(buf[1]=='l')
    	{
    		int flag=1; 
    		long long u,v;
    		double w;
    		for(int i=0;i!='>';i++)
    		{
    			if(buf[i]=='n'&&flag&&buf[i+1]=='o')
    			{
					long long Y=1;
    				long long X=0;
    				int cnt1=1;
    				for(int j=i+5;buf[j]!=' ';j++)
    				{
    					if(buf[j]=='-') {
                            Y= -1;
                            continue;
                        }
    					if(buf[j]>='0'&&buf[j]<='9')
    						X=X*10+buf[j]-'0';
						cnt1++;	
					}X=X*Y;
					u=X;
					flag=0;
					continue;
				}
				if(buf[i]=='n'&&!flag&&buf[i+1]=='o')
    			{
					long long Y=1;
    				long long X=0;
    				int cnt1=1;
    				for(int j=i+5;buf[j]!=' ';j++)
    				{
    					
    					if(buf[j]=='-') {
                            Y= -1;
                            continue;
                        }
    					if(buf[j]>='0'&&buf[j]<='9')
    						X=X*10+buf[j]-'0';
						cnt++;	
					}X=X*Y;
					v=X;
					i=i+cnt1+4;
					flag=1;
					continue;
				}
				if(buf[i]=='l'&&buf[i+1]=='e')
				{
					double X=0,Y=0,tt=1;
					int ct=1;
					for(int j=i;buf[j]!=' ';j++)
					{	
						if(buf[j]=='.')
						{
							ct=0;
							continue;
						}
						if(buf[j]>='0'&&buf[j]<='9'&&ct)
    					X=X*10+buf[j]-'0';
    					if(buf[j]>='0'&&buf[j]<='9'&&!ct)
    					Y=Y*10+buf[j]-'0',tt*=10;
					}
					w=X+Y/tt;
				}
			}
			ae[k].u=u,ae[k].v=v,ae[k].w=w;k++;
		}
       if(buf[1]=='n')
       {
           long long Y=1;
           long long X=0;
           for(int i=9;buf[i]!=' ';i++)
           {
               if(buf[i]=='-') {
                   Y = -1;
                   continue;
               }
               if(buf[i]>='0'&&buf[i]<='9')
                   X=X*10+buf[i]-'0';
           }
           X=X*Y;
           node[cn]=X;
           cn++;
       }
   }
   quick_sort(node,0,cn-1);
   for(int i=0;i<k;i++)
   {
       int U= find2(ae[i].u,0,cn-1);
       int V= find2(ae[i].v,0,cn-1);
       add(U,V,ae[i].w);
       add(V,U,ae[i].w);
   }
    return 0;
}

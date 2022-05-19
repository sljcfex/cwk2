#include<stdio.h>

#define ls rt<<1
#define rs rt<<1|1
typedef long long ll;
const int maxn=10000;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	int v,nxt;
	ll w;
}e[maxn];
ll tr[maxn];
int head[maxn],pos[maxn],pre[maxn];
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
void update(int l,int r,int rt,int p,ll w)
{
	if(l==r)
	{
		tr[rt]=w;
		return;
	}
	int mid=(l+r)>>1;
	if(p<mid)update(l,mid,ls,p,w);
	else update(mid+1,r,rs,p,w);
	pushup(rt);
}
void dijkstra(int s) {
    build(1,n,1); 
	update(1,n,1,s,0);
    memset(dis,0x3f,sizeof(dis)),dis[s]=0;
    while (tr[1]!=inf) {
        int u=pos[1]; 
		update(1,n,1,u,inf);
        for (int i=head[u];i;i=e[i].nxt) 
		{
            int v=e[i].v,w=e[i].w;
            if (dis[u]+w<dis[v]) 
                dis[v]=dis[u]+w,update(1,n,1,v,dis[v]),pre[i]=v;
        }
    }
}
int main()
{
	return 0;
}

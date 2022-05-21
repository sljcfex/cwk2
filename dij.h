#include<stdio.h>
#include<string.h>
#include<dij.h>
#define ls rt<<1
#define rs rt<<1|1

#define maxn 10000
const double inf=0x3f3f3f3f;
struct edge{
    int v,nxt;
    double w;
}e[maxn];
struct add_edge{
    long long u,v;
    double w;
}ae[maxn];
int cn=0;
double tr[maxn],dis[maxn];
int cnt=0;
int head[maxn],pos[maxn],pre[maxn];
long long node[maxn];
void quick_sort(long long *num,int l,int r);
int find2(long long x,int l,int r);
void add(int u,int v,double w);
void pushup(int rt);
void build(int l,int r,int rt);
void update(int l,int r,int rt,int p,double w);
void dijkstra(int s) ;
int read_map(FILE *file);
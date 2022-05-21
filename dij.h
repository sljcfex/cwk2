#ifndef _DIJ_H_
#define _DIJ_H_
#include<stdio.h>
#include<string.h>

#define ls rt<<1
#define rs rt<<1|1

#define maxn 10000

struct edge{
    int v,nxt;
    double w;
};

struct add_edge{
    long long u,v;
    double w;
};



extern struct edge e[maxn];
extern struct add_edge ae[maxn];
extern int cn;
extern double tr[maxn],dis[maxn];
extern int cnt;
extern int head[maxn],pos[maxn],pre[maxn];
extern long long node[maxn];
void quick_sort(long long *num,int l,int r);
int find2(long long x,int l,int r);
void add(int u,int v,double w);
void pushup(int rt);
void build(int l,int r,int rt);
void update(int l,int r,int rt,int p,double w);
void dijkstra(int s) ;
int read_map(FILE *file);
#endif
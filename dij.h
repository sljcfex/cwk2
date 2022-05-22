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
};//Store edge information

struct add_edge{
    long long u,v;
    double w;
};//Store edge information

struct add_node{
    long long id;
    double lat,lon;
};//Store node information
extern int k;
extern struct add_node ad[maxn];
extern struct edge e[maxn];
extern struct add_edge ae[maxn];
extern int cn;
extern double tr[maxn],dis[maxn];
extern int cnt;
extern int head[maxn],pos[maxn],pre[maxn];
extern long long node[maxn];
void quick_sort(long long *num,int l,int r);//quick sort, Prepare for binary lookup
int find2(long long x,int l,int r);//binary lookup
void add(int u,int v,double w);//add edge
void pushup(int rt);//Store segment tree data
void build(int l,int r,int rt);//Build a line segment tree
void update(int l,int r,int rt,int p,double w);//Updated the shortest circuit information
void dijkstra(int s) ;//For the short circuit
int read_map(FILE *file);//Read map file
#endif
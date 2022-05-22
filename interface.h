#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include<stdio.h>
#include<string.h>

#include <stdlib.h>
extern int b;
extern char a[20];
extern long long u,v,x2,x1;
void makemanu();
void inteRFace();//User operation area
void load_map();
void welcome();
void read_node_st();//Read the beginning
void read_node_ed();//read the ending
void tile();

#endif
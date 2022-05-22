#include<stdio.h>
#include<string.h>
#include"dij.h"
#include"interface.h"
#include <stdlib.h>
#include <SDL2/SDL.h>

struct edge e[maxn];
struct add_edge ae[maxn];
struct add_node ad[maxn];
int cn;
int k;
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

}

void load_map()
{
    printf("Import new map(Y) or Using the initial map(Any other key)\n");
    scanf("%s",a);
    //system("cls");
    if(a[0]=='Y'&&a[1]=='\0')
    {
        printf("please enter the file name:\n");

        scanf("%s",a);
        //system("cls");
        FILE *fp=fopen(a, "r");
        b=read_map(fp);
    }
    else
    {
        FILE *fp=fopen("Final_Map.map", "r");
        b=read_map(fp);
    }
    if(b==-1)
    {
        printf("File reading failure\nDo you want to read again?(Y/Any other key)\n");

        scanf("%s",a);

        if(a[0]=='Y'&&a[1]=='\0')load_map();
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
        if(a[0]=='Y'&&a[1]=='\0')
        {
            read_node_st();
        }
        else return;
    }
    u= find2(x1,0,cn);
    if(u==-1){
        printf("Cannot find this node, please re-enter(Y) or exit(any other key) \n");
        scanf("%s",a);
        if(a[0]=='Y'&&a[1]=='\0')
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
        scanf("%s",a);
        if(a[0]=='Y'&&a[1]=='\0')
        {
            read_node_st();
        }
        else return;
    }
    v= find2(x2,0,cn);
    if(v==-1){
        printf("Cannot find this node, please re-enter(Y) or exit(any other key) \n");
        scanf("%s",a);
        if(a[0]=='Y'&&a[1]=='\0')
        {
            read_node_ed();
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

void print_pre(int i){
    if(i==u)return;
    print_pre(pre[i]);
    printf("-->%lld",node[i]);
}
#define  print_ERROR(TEXT) printf("%s ERROR: %s\n",TEXT,SDL_GetError())
void event_loop(){
    while (1){
        SDL_Event event;
        if(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                break;
            }
        }
    }
}
SDL_Renderer *renderer;
void draw(){
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawLineF(renderer,40,5,40,520);
    SDL_RenderDrawLineF(renderer,40,520,680,520);
    double x11,x22,y11,y22;
    float x111,x222,y111,y222;
    for(int i=0;i<=cn;i++)
    {
        x11 = ad[i].lat;
        y11 = ad[i].lon;
        x11 -= 53.8;
        x11 *= 65000.0;
        y11 -= 1.53;
        y11 *= 25000.0;
        x111 = (float) x11-50;
        y111 = (float) y11-350;
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderDrawPointF(renderer,x111,y111);
        SDL_RenderPresent(renderer);
    }
    for(int i=0;i<=k;i++) {
        int flag1 = 0;
        int flag2 = 0;
        long long u1 = ae[i].u;
        long long v1 = ae[i].v;
        for (int j = 0; j <= cn; j++) {
            if (u1 == ad[j].id) {
                x11 = ad[j].lat;
                y11 = ad[j].lon;
                x11 -= 53.8;
                x11 *= 65000.0;
                y11 -= 1.53;
                y11 *= 25000.0;
                x111 = (float) x11-50;
                y111 = (float) y11-350;
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                SDL_RenderDrawPointF(renderer,x111,y111);
                SDL_RenderPresent(renderer);
                flag1 = 1;
            }
            if (v1 == ad[j].id) {
                x22 = ad[j].lat;
                y22 = ad[j].lon;
                x22 -= 53.8;
                x22 *= 65000.0;
                y22 -= 1.53;
                y22 *= 25000.0;
                flag2 = 1;
                x222 = (float) x22-50;
                y222 = (float) y22-350;
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                SDL_RenderDrawPointF(renderer,x222,y222);
                SDL_RenderPresent(renderer);
            }
            if (flag1 && flag2)
            {
                SDL_SetRenderDrawColor(renderer,0,255,0,255);
                SDL_RenderDrawLineF(renderer,x111,y111,x222,y222);
                break;
            }
        }
        if(!flag1||!flag2)continue;

    }
    SDL_RenderPresent(renderer);
}
void draw1(int g)
{
    if(pre[g]==u)
    {
        double x11,x22,y11,y22;
        float x111,x222,y111,y222;
        int flag1=0,flag2=0;
        long long u2=node[g],v2=node[pre[g]];
        for (int j = 0; j <= cn; j++) {
            if (u2 == ad[j].id) {
                x11 = ad[j].lat;
                y11 = ad[j].lon;
                x11 -= 53.8;
                x11 *= 65000.0;
                y11 -= 1.53;
                y11 *= 25000.0;
                x111 = (float) x11 - 50;
                y111 = (float) y11 - 350;
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
                SDL_RenderDrawPointF(renderer, x111, y111);
                SDL_RenderPresent(renderer);
                flag1=1;
            }
            if (v2 == ad[j].id) {
                x22 = ad[j].lat;
                y22 = ad[j].lon;
                x22 -= 53.8;
                x22 *= 65000.0;
                y22 -= 1.53;
                y22 *= 25000.0;
                x222 = (float) x22-50;
                y222 = (float) y22-350;
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
                SDL_RenderDrawPointF(renderer,x222,y222);
                SDL_RenderPresent(renderer);
                flag2=1;
            }
            if (flag1 && flag2)
            {
                SDL_SetRenderDrawColor(renderer,255,0,0,255);
                SDL_RenderDrawLineF(renderer,x111,y111,x222,y222);
                break;
            }
        }
        return;
    }
    draw1(pre[g]);
    double x11,x22,y11,y22;
    float x111,x222,y111,y222;
    long long u1=node[g];
    long long v1 = node[pre[g]];
    int flag1=0,flag2=0;
    for (int j = 0; j <= cn; j++) {
        if (u1 == ad[j].id) {
            x11 = ad[j].lat;
            y11 = ad[j].lon;
            x11 -= 53.8;
            x11 *= 65000.0;
            y11 -= 1.53;
            y11 *= 25000.0;
            x111 = (float) x11 - 50;
            y111 = (float) y11 - 350;
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            SDL_RenderDrawPointF(renderer, x111, y111);
            SDL_RenderPresent(renderer);
            flag1=1;
        }
        if (v1 == ad[j].id) {
            x22 = ad[j].lat;
            y22 = ad[j].lon;
            x22 -= 53.8;
            x22 *= 65000.0;
            y22 -= 1.53;
            y22 *= 25000.0;
            x222 = (float) x22-50;
            y222 = (float) y22-350;
            SDL_SetRenderDrawColor(renderer,255,0,255,255);
            SDL_RenderDrawPointF(renderer,x222,y222);
            SDL_RenderPresent(renderer);
            flag2=1;
        }
        if (flag1 && flag2)
        {
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
            SDL_RenderDrawLineF(renderer,x111,y111,x222,y222);
            break;
        }
    }

}
void sdl2(int g)
{
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("can not init video, %s",SDL_GetError());
    }
    SDL_Window  *window = SDL_CreateWindow(
            "Map",SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,700,550,
            SDL_WINDOW_SHOWN);
    if(window==NULL){
        printf("cannot create window,%s",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer==NULL){
        printf("cannot create renderer,%s",SDL_GetError());
    }
    SDL_Surface *scream=SDL_GetWindowSurface(window);
    SDL_Rect r={0,0,700,550};
    SDL_FillRect(scream,&r,0xffffffff);
    draw();
    draw1(g);
    event_loop();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
void sdl1()
{
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("can not init video, %s",SDL_GetError());
    }
    SDL_Window  *window = SDL_CreateWindow(
            "Map",SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,700,550,
            SDL_WINDOW_SHOWN);
    if(window==NULL){
        printf("cannot create window,%s",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer==NULL){
        printf("cannot create renderer,%s",SDL_GetError());
    }
    SDL_Surface *scream=SDL_GetWindowSurface(window);
    SDL_Rect r={0,0,700,550};
    SDL_FillRect(scream,&r,0xffffffff);
    draw();
    event_loop();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
void inteRFace()
{
    welcome();
    system("cls");
	while(1){
        tile();
        //  system("cls");

        makemanu();
      //  system("cls");
        int key=0;
        int key1=1;
        scanf("%s",&a);
        for(int i=0;i< strlen(a);i++)
        {
            if(a[i]>'9'||a[i]<'0')
            {
                key1=0;
                printf("Please enter valid characters\n");
            }
            if(a[i]<='9'&&a[i]>=0)
            {
                key=key*10+a[i]-'0';
            }
        }
        if(!key1)continue;
        switch (key) {
            case 0:
                printf("exit\n");
                printf("exit successful!\n");
              //  system("cls");
                system("pause");
                return;
            case 1:
                if(b==-1)
                {
                    printf("No map loading\n");
                    system("pause");
                    break;
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
                    if(dis[v]>=inf)printf("There's no path between N1 and N2!\n");
                    else{
                        printf("The shortest path from Node%lld to Node%lld is %lf\n",x1,x2,dis[v]);
                        printf("the path is:\n");
                        printf("%lld",node[u]);
                        print_pre(v);
                        printf("\n");
                        printf("to show the path on the map(Y) or not(any other key)\n");
                        scanf("%s",&a);
                        if(a[0]=='Y'&&a[1]=='\0'){
                            sdl2(v);
                        }
                    }
                }system("pause");
                break;
            case 2:
                load_map();
                system("pause");
                break;
            case 3:
                if(b==-1)
                {
                    printf("No map loading\n");
                    system("pause");
                    break;
                }
                sdl1();
                system("pause");
                break;
            default:
                printf("Please enter valid characters\n");
                system("pause");
                break;
        }
        system("cls");
	}
}

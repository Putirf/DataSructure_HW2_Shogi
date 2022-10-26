#ifndef SHOGI_H_
#define SHOGI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <termios.h>  
#include <unistd.h>  
#include <errno.h>  
#include <string.h>
#include <ev.h>
#include <sys/io.h>

typedef struct {
    bool alivechange ;//0 die/ 1 alive
    bool change ;//0 No chane/ 1 change
    int side ;//X Y;
    int kind ;
}Chess;
extern const Chess InitialBroad[9][9];
extern Chess BroadSeat[9][9];

//??Ｗ??閮剖??
#define CLEAR() printf("\033[2J")//清屏
#define CLEARLINE() printf("\033[k")//清除从光标到行尾的内容
#define MOVEUP(x) printf("\033[%dA", (x))// 光标上移n行
#define MOVEDOWN(x) printf("\033[%dB", (x))// 光标下移n行
#define MOVELEFT(y) printf("\033[%dD", (y))// 光标右移n列
#define MOVERIGHT(y) printf("\033[%dC",(y))// 光标左移n列
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))// 设置光标位置（y行,x列）
#define HIDE_CURSOR() printf("\033[?25l")// 隐藏光标
#define SHOW_CURSOR() printf("\033[?25h")// 显示光标
//閮剖??憿????
#define SET_FRONT_COLOR(color) printf("\033[%dm",(color))
#define SET_BACKGROUND_COLOR(color) printf("\033[%dm",(color))

//?????航??
#define FRONT_BLACK 30
#define FRONT_RED 31
#define FRONT_GREEN 32
#define FRONT_YELLOW 33
#define FRONT_BLUE 34
#define FRONT_PURPLE 35
#define FRONT_DEEP_GREEN 36
#define FRONT_WHITE 37

//?????航??
#define BACKGROUND_BLACK 40
#define BACKGROUND_RED 41
#define BACKGROUND_GREEN 42
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLUE 44
#define BACKGROUND_PURPLE 45
#define BACKGROUND_DEEP_GREEN 46
#define BACKGROUND_WHITE 47

#define PAUSE fgetc(stdin);//system("pause")

#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)  

//set Broad Edge size
#define BroadMaxX 40
#define BroadMaxY 40

//撘瑕?嗅????亥????? char -> int
#define Foot        1953460038  //甇亙??
#define Car         7496003     //擐?頠?
#define Horse       1936879432  //獢?擐?
#define Silver      1986816339  //???撠?
#define Gold        1684827975  //???撠?
#define King        1735289163  //???撠?
#define Horn        1852993352  //閫?敶?
#define DragonHorse 1734439492  //樴?擐?
#define FlyingCar   1769565254  //憌?頠?
#define DragonKing   1869046084  //樴????
#define Empty       -1442840544 //蝛箸??

#define NONE    1162760014
#define X   -973078440
#define Y   -1862270887
#define y   16777337
#define n   16777326
#define f   687865958
#define b   687865954
#define p   687865968

//Play.c
extern int side;//which side now X Y 
extern bool Gamecontinue;
extern int Rownow,Columnnow,Rowtogo,Columntogo;
extern int GraveXlast, GraveYlast;
extern bool Domove;
extern char YN[2];
extern int yorn;
extern int GraveX[20],GraveY[20] ;

#endif

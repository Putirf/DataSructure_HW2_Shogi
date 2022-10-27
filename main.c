#include "shogi.h"
#include "Print.h"
#include "Play.h"
#include "Rule.h"
char fNAME[50] = "GAME.txt";

int choose;
int Read_Old_Game();

int main(int argc, char * argv[]){
    int ch;

    while ((ch = getopt(argc, argv, "s:nl:")) != -1){//判斷cmd的輸入
        switch (ch) {
            case 's':
                strcpy(fNAME,optarg);
                break;
            case 'n':
                Play_Chess();
                break;

            case 'l':
                strcpy(fNAME,optarg);
                Read_Old_Game();
                break;
            abort();
            break;
        }
    }
    
    return 0;        
}

int Read_Old_Game(){
    side = X;
    FILE *fp;
    int countstep = 0;
    char fb[2];
    int forb;
    int fileend;
    CLEAR();
    SHOW_CURSOR();
    set_disp_mode(1);
    fp = fopen(fNAME,"r");
    if(fp == NULL){
            printf("FILEOPENERROR1");
    }
    else{
        for(int i =0;i<=8;i++){
            for(int j =0;j<=8;j++){
                BroadSeat[i][j] = InitialBroad[i][j];
            }
        }
        fseek(fp,0,SEEK_END);
        fileend = ftell(fp);
        Option:
        Print_Broad();
        printf("enter(f:forward b:backward 0:exit):");
        fflush(stdin);
        scanf("%s",fb);
        if(strcmp(fb,"b")==0||strcmp(fb,"B")==0){
            if(countstep == 0){
                printf("this is the begining");
                sleep(2);
                goto Option;
            }
            else{
                Chess tmp;
                fseek(fp,(countstep-1)*6*sizeof(int),SEEK_SET);
                fscanf(fp,"%d %d %d %d %d %d",&Rowtogo,&Columntogo,&Rownow,&Columnnow,&tmp.kind,&tmp.side);
                countstep --;
                move(0);
                BroadSeat[Rownow][Columnnow].alivechange = 0;
                BroadSeat[Rownow][Columnnow].change = 0;
                BroadSeat[Rownow][Columnnow].side = tmp.side;
                BroadSeat[Rownow][Columnnow].kind = tmp.kind;
                if(side == X){
                side = Y;
                }      
                else if(side == Y){
                side = X;
                }  
                goto Option;
            }

        }
        else if(strcmp(fb,"F")==0||strcmp(fb,"f")==0){ 
                Chess tmp;
                if(feof(fp)){
                    printf("this is the last step of this game");
                    sleep(1);
                    goto Option;
                }
                else{
                    fseek(fp,countstep*6*sizeof(int),SEEK_SET);
                    fscanf(fp,"%d %d %d %d %d %d ",&Rownow,&Columnnow,&Rowtogo,&Columntogo,&tmp.kind,&tmp.side);
                    move();
                    countstep ++;
                    if(side == X){
                side = Y;
                }      
                else if(side == Y){
                side = X;
                }  
                    goto Option;
                }
        }
        else if(strcmp(fb,"0")==0){
        fclose(fp);
                return 0;
        }
        else{
            goto Option;
        }
    }

}



//gcc -o main main.c Play.c Play.h Print.c Print.h Rule.c Rule.h shogi.h -lm -lev


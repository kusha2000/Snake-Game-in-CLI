#include<stdio.h>
#include<conio.h>
#include<time.h>
int height=15;weight=30,x=0,y=0,sx=1,sy=1,pre=4,gameover=0,eat=1,count=1,test,score=0;
int main(){
    while(gameover!=1){
        draw();
        snake();
        //sleep(0.01);
        test++;

    }



    return 0;
}
void draw(){
    system("cls");
    for(int i=0;i<height;i++){
        for(int j=0;j<weight;j++){

            while(eat==1){
                srand(time(0)+test+count);
                x=rand()%height;
                y=rand()%weight;
                //printf("X:%d\nY:%d\n",x,y);
                if(x==0 || y==0 || x==height-1 || y==weight-1){

                }else{
                    eat=0;
                    break;
                }
            }


            if(i==0 || i==height-1 || j==0 || j==weight-1){
                printf("#");
            }else if(i==x && j==y){
                printf("*");
            }else if(i==sx && j==sy){
                printf("0");
            }else{
                printf(" ");
            }




            /*if(i==x && j==y ){
                printf("*");
                //j++;

            }


            if(i==0 || i==height-1){
                printf("#");
            }else{
                if(j==0 || j==weight-1){
                    printf("#");
                }else{
                    printf(" ");
                }

            }
            if(i==sx && j==sy){
                //printf("i:%d sx:%d j:%d sy:%d ",i,sx,j,sy);
                printf("0");
                //j++;
            }*/

            if(x==sx && y==sy){
                eat=1;
                i=height;
                j=weight;
                score+=10;
                //count++;

            }
            if(sx==0 || sx==height-1 || sy==0 || sy==weight-1){
                gameover=1;
            }


        }
        printf("\n");
    }
    printf("\nScore:%d\n",score);
    if(gameover==1){
        printf("\nGame Over\n");
    }
}

void snake(){
    if(kbhit()){
        switch(getch()){
            case 'w':
                sx--;
                pre=1;
                break;
            case 'a':
                sy--;
                pre=2;
                break;
            case 's':
                sx++;
                pre=3;
                break;
            case 'd':
                sy++;
                pre=4;
                break;
            default:
                break;
        }
    }else{
        if(pre==1){
            sx--;
        }else if(pre==2){
            sy--;
        }else if(pre==3){
            sx++;
        }else if(pre==4){
            sy++;
        }

    }


}

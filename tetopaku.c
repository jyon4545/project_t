#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>


#define FIELD_WIDTH (10)
#define FIELD_HEIGHT (20)

#define SHAPE_WIDTH_MAX 4
#define SHAPE_HEIGHT_MAX 4

enum{
    SHAPE_I,
    SHAPE_O,
    SHAPE_S,
    SHAPE_Z,
    SHAPE_J,
    SHAPE_L,
    SHAPE_T,
    SHAPE_MAX
};

typedef struct{
    int width,height;
    int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
} SHAPE;

typedef struct{
    int x,y;
    SHAPE shape;
}MINO;

SHAPE shapes[SHAPE_MAX] = {

    //SHAPE_I
    {
        4,4,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0},
                {0,0,0,0}
            }
    },
    //SHAPE_O
    {
        2,2,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {1,1},
                {1,1}
            }
    },
    //SHAPE_S
    {
        3,3,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {0,1,1},
                {1,1,0},
                {0,0,0}
            }
    },

    //SHAPE_Z
    {
        3,3,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {1,1,0},
                {0,1,1},
                {0,0,0}
            }
    },

    //SHAPE_J
    {
        3,3,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {1,0,0},
                {1,1,1},
                {0,0,0}
            }
    },
    //SHAPE_L
    {
        3,3,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {0,0,1},
                {1,1,1},
                {0,0,0}
            }
    },

    //SHAPE_T
    {
        3,3,        //int width,height;
                //int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
            {     
                {0,1,0},
                {1,1,1},
                {0,0,0}
            }
    },
};



int field[FIELD_HEIGHT][FIELD_WIDTH];
int screen[FIELD_HEIGHT][FIELD_WIDTH];
MINO mino;

int MinoIntersectFIeld(){
    int x,y;
    
    for(y=0;y<mino.shape.height;y++){
        for(x=0;x<mino.shape.width;x++){
            if(mino.shape.pattern[y][x]){
                if((mino.y+y<0) || (mino.y + y>= FIELD_HEIGHT)
                    || (mino.x+x<0) || (mino.x + x>= FIELD_WIDTH)){
                    return 1;                    
                    }
            }
        }
    }

    return 0;
}

void DrowScreen()
{   
    memcpy(screen ,field,sizeof field);
    int x,y;
    
    for(y=0;y<mino.shape.height;y++){
        for(x=0;x<mino.shape.width;x++){
            if(mino.shape.pattern[y][x]){
                screen[mino.y + y][mino.x + x] |=1;
            }
        }
    }

    system("cls");

    for(y=0;y<FIELD_HEIGHT;y++){
        printf("■");
            for(x=0;x<FIELD_WIDTH;x++){
                printf("%s",screen[y][x] ? "■":"　");
        }
        printf("■");
        printf("\n");
    }
    for (x=0;x<FIELD_WIDTH+2;x++){
        printf("■");
    }
    
}

void Initmino(){

    int x;
    randomize();
    x = random(SHAPE_MAX);
    mino.shape = shapes[x];
    mino.x = (FIELD_HEIGHT - mino.shape.width) / 2;
    mino.y = 0; 

}

void Init(){
    memset(field,0,sizeof field);
    Initmino();
    DrowScreen();
}

int main(void){
    randomize();
    Init();
    while(1){
        if(kbhit()){
            MINO lastMino = mino;
            switch(getch()){
            case 'w':
                break;
            case 's':
                mino.y++;
                break;
            case 'a':
                mino.x--;
                break;
            case 'd':
                mino.x++;
                break;
            }
            
            if(MinoIntersectFIeld()){
                mino = lastMino;
            }
            
            DrowScreen();

        }
    }
}
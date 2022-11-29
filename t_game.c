#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILED_YOKO 10
#define FIELD_TATE 20

#define MINO_YOKO 4
#define MINO_TATE 4

typedef struct 
{
    int tate,yoko;
    int size_m[MINO_TATE][MINO_YOKO];
} MINO;

typedef struct
{
    int x;
    int y;
    MINO mino_type; 
}MY_MINO;

enum {
    MINO_I,
    MINO_O,
    MINO_S,
    MINO_Z,
    MINO_L,
    MINO_T,
    MINO_J,
    MINO_MAX,
};

MINO mino_type[MINO_MAX] = {
    //MINO_I
    {
        4, 4, // TATE,YOKO
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
        }},

    //MINO_O
    {
        2,2, // TATE,YOKO
    {
        {1,1},
        {1,1}
    }
	}, 

    //MINO_S,
    {3,3, // TATE,YOKO
    {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 0}

    }},

    //MINO_Z,
    {3,3, // TATE,YOKO
    {
        {1, 1, 0},
        {0, 1, 1},
        {0, 0, 0}
    }},

    //MINO_L,
    { 3,3,// TATE,YOKO
    {
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    }}, 
    
    //MINO_T
    {3,3, // TATE,YOKO
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
    }}, 
    
    
    //MINO_J
    {3,3, // TATE,YOKO
    {
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    }},
    
};

    MY_MINO mymino;
    int field[FIELD_TATE][FILED_YOKO];
    int screen[FIELD_TATE][FILED_YOKO];

void DrowScreen()
{
    memcpy(screen, field, sizeof field);
    int i, j;
    int x,y;
    for(y=0;y<mymino.mino_type.yoko;y++){
        for(x = 0;x<mymino.mino_type.tate;x++){
            if(mymino.mino_type.size_m[y][x]){
                screen[mymino.y + y ][mymino.x + x] = 1;
        }

        }
    }
    for (j = 0; j < FIELD_TATE; j++)
    {
        printf("??");
        for (i = 0; i < FILED_YOKO; i++)
        {
            if(screen[y][x]){
                printf("??");
            }else{
                printf("　");
            }
        }
        printf("??");
        printf("\n");
    }

    for (i = 0; i < FILED_YOKO + 2; i++)
    {
        printf("??");
    }
}


void Init(){
    DrowScreen();
}

int main(void)
{
	randomize();
	int a = random(6);
    Init();
	getch();
}
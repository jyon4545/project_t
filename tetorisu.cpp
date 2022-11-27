#include <conio.h>
#include <stdio.h>

#define FILED_YOKO 10
#define FIELD_TATE 20

void DrowScreen()
{
    int i, j;
    for (j = 0; j < FIELD_TATE; j++){
        printf("¡");   
        for (i = 0; i < FILED_YOKO; i++)
        {
            printf("@");
        }
        printf(" ");
        printf("\n");
    }
    for (i=0;i<FILED_YOKO+2;i++){
        printf("");
    }
}
int main(void)
{
    DrowScreen();
}
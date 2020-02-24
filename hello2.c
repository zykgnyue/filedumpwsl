#include <stdio.h>
void inpswap(int*x,int*y);

int main()
{
        int x1=23,y1=0xAA;



        int B=-12345;
        int *p;
        p=&B; //B的存储地址给p
        *p= 56789;
        char *pc;
        pc =(char*)&B;

        printf("%d = %8.8x\n",p[0],p[0]);

        printf("%d = %x\n",(char)pc[0],pc[0]&0xFF);

        x1=0x23;
        y1=0xAA;
        printf("before swap: %x,%x\n",x1,y1);
        inpswap(&x1,&y1);

        printf("after swap: %x,%x\n",x1,y1);
        printf("%d,%d\n",x1,y1);
        //A:170,35
        //B:AA,23
}

void inpswap(int*x,int*y)
{
        *x=*x^*y;
        *y=*x^*y;
        *x=*x^*y;
}
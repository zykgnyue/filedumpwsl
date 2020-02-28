//2.46 2.51
#include <stdio.h>
void printfloat(float x1);
void printdouble(double x1);

void printbin(unsigned char *buf,size_t maxlen);
void printbyte(unsigned char *p, size_t len);
void printbyte_reverse(unsigned char *p, size_t len);
void  print_ulongbin(unsigned long data1,size_t ulen);
void missile();

int main()
{
    printf("patriot missile 0.1s\n");
    missile();
    return 0;

}


void missile()
{
    float xf01=0.1f;
    float xf00;
    unsigned int *fp00=(unsigned int *)&xf00;
    double xd01=(double)1.0/10.0;
    double f2d01=xf01;
    printf("float2double 0.1 toward even\n");
    printbyte_reverse((unsigned char *)&f2d01,sizeof(xf01));

    printf("float 0.1\n");
    printfloat(xf01);
    printbyte_reverse((unsigned char *)&xf01,sizeof(xf01));

    printf("accurate double 0.1\n");
    printdouble(xd01);
    printbyte_reverse((unsigned char *)&xd01,sizeof(xd01));
 
    printf("error double 0.1-float 0.1 toward even\n");
    f2d01 -= xd01;
    printdouble(f2d01);
    printbyte_reverse((unsigned char *)&f2d01,sizeof(f2d01));
    printf("Metter(t_even)=%lf\n",f2d01*(100.0*3600.0*10.0*2000.0));
 
    //round down
    xf00=xf01;
    *fp00 -=1;
    printf("float 0.1 round down\n");
    printfloat(xf00);
    printbyte_reverse((unsigned char *)&xf00,sizeof(xf00));

    f2d01 = xd01-xf00;
    printf("error double 0.1-float 0.1 toward 0\n");
    printdouble(f2d01);
    printbyte_reverse((unsigned char *)&f2d01,sizeof(f2d01));

    printf("Metter(t_0)=%lf\n",f2d01*(100.0*3600.0*10*2000.0));



}

#define DF_FSIGN(x) ((x)>>(sizeof(float)*8U-1U)&0x01U)
#define DF_FEXP(x) ((x)>>(sizeof(float)*8U-1U-8U)&0xffU)
#define DF_FFRAC(x) ((x)&(~(0x0F8UL<<23)))
#define DF_FMNOR(x)   ((x)|0x01UL<<24)

#define DF_DSIGN(x) ((x)>>(sizeof(double)*8U-1)&0x01U)
#define DF_DEXP(x) ((x)>>(sizeof(double)*8U-1-11)&0x7ffU)
#define DF_DFRAC(x) ((x)&(~(0xfffUL<<52)))
#define DF_DMNOR(x)   ((x)|(1UL<<53))

void printfloat(float x1)
{
    unsigned int *fp=(unsigned int *) &x1;
    unsigned int flt=*fp;
    unsigned long signe=DF_FSIGN(flt);
    unsigned long exp=DF_FEXP(flt);
    unsigned long frac=DF_FFRAC(flt);
    unsigned long Ecode=0;
    unsigned long Mcode=0;
    unsigned long Bias=(1U<<(8-1))-1;
    signed short Ecode1;
    if(exp==0U)
    {
        //denormalized
        Ecode1=-Bias+1;
        Mcode=frac;
        printf("sign=%c\n",signe!=0? '-' : '+');
        printf("E=%d\n",Ecode1);
        printf("0.");//0.
    }else if(exp==0xffUL && frac == 0UL){
        printf("INF \n");
        return;

    }else if(exp==0xffUL && frac != 0UL){
        //special INF
        printf("NAN \n");
        return;

    }else{
        //normalized 
        Ecode1=-Bias+exp;
        Mcode =frac;//1 is not add
        printf("sign=%c\n",signe!=0? '-' : '+');
        printf("E=%d\n",Ecode1);
        printf("1.");  //1bit more
    }
    //printf fraction
    print_ulongbin(flt,(sizeof(x1)*8U-9U)); 


}

void  print_ulongbin(unsigned long data1,size_t ulen)
{
    unsigned int ui1;
    unsigned long mask;
    unsigned char x=1;
    for(ui1=0;ui1<ulen;ui1++)
    {
        if((ui1%4)==0)
        {
            printf(" ");
        }
        mask = 0x01UL<<(ulen-ui1-1);
        x=((data1&mask)!=0);
        printf("%u",x);

    }
    printf("\n");

}

void printdouble(double x1)
{
    unsigned long *fp=(unsigned long *) &x1;
    unsigned long flt=*fp;
    unsigned long signe=DF_DSIGN(flt);
    unsigned long exp=DF_DEXP(flt);
    unsigned long frac=DF_DFRAC(flt);
    unsigned long Ecode=0;
    unsigned long Mcode=0;
    //w=11
    unsigned long Bias=(1U<<(11-1))-1;
    signed short Ecode1;
    if(exp==0U)
    {
        //denormalized
        Ecode1=-Bias+1;
        Mcode=frac;
        printf("sign=%c\n",signe!=0? '-' : '+');
        printf("E=%d\n",Ecode1);
        printf("0.");//0.
    }else if(exp==0x7ffUL && frac == 0UL){
        printf("INF \n");
        return;

    }else if(exp==0x7ffUL && frac != 0UL){
        //special INF
        printf("NAN \n");
        return;

    }else{
        //normalized 
        Ecode1=-Bias+exp;
        Mcode =frac;//1 is not add
        printf("sign=%c\n",signe!=0? '-' : '+');
        printf("E=%d\n",Ecode1);
        printf("1.");  //1bit more
    }
    //printf fraction
    print_ulongbin(flt,(sizeof(x1)*8U-12U)); 
    

}

void printbyte(unsigned char *p, size_t len)
{

    size_t ui1;
    for(ui1=0;ui1<len;ui1++)
    {
        printf("%2.2x ",(unsigned char)p[ui1]);

    }

    printf("\n");

}

void printbyte_reverse(unsigned char *p, size_t len)
{

    size_t ui1;
    for(ui1=0;ui1<len;ui1++)
    {
        printf("%2.2x ",(unsigned char)p[len-ui1-1]);

    }

    printf("\n");

}

// print binary of the char 
// char with visible ascii
void printbin(unsigned char *buf,size_t maxlen)
{
    int i,j;
    for(i=0;i<maxlen;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%c",(buf[i]&(0x80>>j))!=0?'1':'0');
            if(j!=0 && (j%4)==0)
            {
                printf("%c",'-');

            }
        }
        printf(" ");
    }
    printf("\n");

}
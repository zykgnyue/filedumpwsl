#include <stdio.h>

int main(){
	unsigned uBig=0x00123456;
	int varBig=(0x00123456 >>32);
	
        //compiler shfit 0
	//signed shift constant  by compiler
	varBig=(0x87123456 >>32); //sarl	$4, -4(%rbp)
	//code4output varBig result
	printf("signed shfitRight32 %d,0x%8.8x\n",varBig,varBig);

        varBig=0x87123456;
        varBig >>=4;
        printf("signed >>4 %d,0x%8.8x\n",varBig,varBig);

        varBig >>=40; //sarl	%cl, -4(%rbp)
        printf("signed >>40 %d,0x%8.8x\n",varBig,varBig);

        uBig=0x87123456U;
        uBig >>=4;    //shrl	$4, -8(%rbp)
        printf("signed >>4 %u,0x%8.8x\n",uBig,uBig);


}

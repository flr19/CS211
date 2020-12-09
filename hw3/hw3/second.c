#include <stdio.h>
#include <stdlib.h>
void parity(short int num ) {
    unsigned short int var=1;
    int noparity=0;
    int count=0;
    unsigned short int result=0;
    for(int i=0;i<8*sizeof(short int);i++) {
        result=var&num;
        if(result>0) {
            count++;
           
            if(count==2) {
                noparity++;
                count=0;
            }
        }
        else if(result==0) {
            count=0;
        }
        var=var<<1;
    }
    printf("%d\n",noparity);
    
}

void noOfOnes (short int num) {
    unsigned short int var=1;
    unsigned short int result=1;
    int count=0;
    for(int i=0;i<8*sizeof(short int);i++) {
        result=var & num;
        if(result>0) {
            count++;
         }
        var=var<<1;
       // printf("count is %d\n",count);
    }
    
     if(count%2==0) {
        printf("Even-Parity\t");
    }
    else {
        printf("Odd-Parity\t");
    }
    
}

int main(int argc, char* argv[])
{
    unsigned short int num;
    num=atoi(argv[1]);
    noOfOnes(num);
    parity(num);
    
}

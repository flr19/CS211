#include <stdio.h>
#include <stdlib.h>
void palindrome(unsigned short int num) {
    int i=0;
    int j=15;
    unsigned short int a=1;
    unsigned short int b=32768;
    while(j>7) {
        if((a&num)==0 && (b&num)==0) {
            //printf("1st loop %d\n",j);
            j--;
            
           
        }
        else if((a&num)>0 && (b&num)>0) {
           // printf("2nd loop %d\n",j);
            j--;
            
        }
        else {
            //printf("3rd loop %d\n",j);
            printf("Not-Palindrome\n");
           // printf("%d\n",j);
            return;
        }
        a=a<<1;
        b=b>>1;
        i++;
    
    }
    printf("Is-Palindrome\n");
}
int main(int argc, char* argv[])
{
    unsigned short int num;
    num=atoi(argv[1]);
    palindrome(num);
}

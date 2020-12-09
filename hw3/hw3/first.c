#include <stdio.h>
int get (short int num,int n) { //same
    unsigned short int a=1;
    a=a<<n;
  //  printf("var is %hd\n",var);
    unsigned short int result=num & a;
    if(result>0) {
        return 1;
    }
    else {
        return 0;
    }
    
}
unsigned short int set(short int num, int n,int setbit) {
    unsigned short int a=1;
    a=a<<n;
   
    unsigned short int result=a & num;
    if(result>0 && setbit==0) {
        num=num-a;
    }
    else if(result==0 && setbit==1) {
        num=num+a;
    }
    return num;

}

unsigned short int comp(short int num, int n) {
    unsigned short int a=1;
    a=a<<n;
   
    unsigned short int result=a & num;
    if(result>0) {
        num=num-a;
    }
    else if(result==0) {
        num=num+a;
    }
    return num;

}


int main(int argc, char* argv[])
{
    if (argc == 1)
	{
		printf("error\n");
		return -1;
	}
    char * filename = argv[1];
	FILE * fp = fopen (filename, "r");
	if (!fp) 
	{
		printf("error\n");
		return -1;
	}
    unsigned short int num;
    fscanf(fp,"%hd\n",&num);
    char *str;
    unsigned short int nbit;
    int setbit;
    int printnum;
    while(1) {
        int n=fscanf(fp, "%s\t%hd\t%d\n",str,&nbit,&setbit);
        if(n!=3) {
            break;
        }
        if(str[0]=='g') {
            printnum=get(num,nbit);
            printf("%d\n",printnum);
        }
        else if(str[0]=='s') {
            num=set(num,nbit,setbit);
            printf("%d\n",num);
        }
        else {
            num=comp(num,nbit);
            printf("%d\n",num);
        }
    }
    return 0;
}

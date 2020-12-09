#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read(char ** str,short int regs[]) {
    if(strcmp(str[0],"read")==0) {
        if(str[1][0]=='a') {
            scanf("%hi",&regs[0]);
        }
        if(str[1][0]=='b') {
            scanf("%hi",&regs[1]);
        }
        if(str[1][0]=='c') {
            scanf("%hi",&regs[2]);
        }
        if(str[1][0]=='d') {
            scanf("%hi",&regs[3]);
        }
    }
}
void print(char ** str,short int regs[]) {
    if(strcmp(str[0],"print")==0) {
        if(str[1][0]=='a') {
            printf("%hi",regs[0]);
        }
        else if(str[1][0]=='b') {
            printf("%hi",regs[1]);
        }
        else if(str[1][0]=='c') {
            printf("%hi",regs[2]);
        }
        else if(str[1][0]=='d') {
            printf("%hi",regs[3]);
        }
		else {
			printf("%s",str[1]);
		}
    }
}
void ops(char ** str, short int * reg){
    int x_ptr=0;
    int y_ptr=0;
    int count = -999;
    if (str[1][0]=='a'|| str[1][0]=='b'|| str[1][0]=='c'|| str[1][0]=='d'){
 
        if (str[1][0]=='a'){
            x_ptr = 0;
        }
        else if (str[1][0]=='b'){
            x_ptr = 1;
        }
        else if (str[1][0]=='c'){
            x_ptr = 2;
        }
        else if (str[1][0]=='d'){
            x_ptr = 3;
        }
      
    }
	  else {
            count=atoi(str[1]);
        }
 
    if (str[2][0]=='a'){
        y_ptr = 0;
    }
    else if (str[2][0]=='b'){
        y_ptr = 1;
    }
    else if (str[2][0]=='c'){
        y_ptr = 2;
    }
    else if (str[2][0]=='d'){
        y_ptr = 3;
    }
    
 
    if(strcmp (str[0], "mov")==0){
        if(count!=-999){
            reg[y_ptr]=count;
        }
        else {
            reg[y_ptr]=reg[x_ptr];
        }
        
    }
    else if(strcmp(str[0], "add")==0){
        if(count!=-999) {
            reg[y_ptr]=count+reg[y_ptr];
        }
        else {
            reg[y_ptr]=reg[x_ptr]+reg[y_ptr];
        }
    
    }
    else if(strcmp(str[0], "sub")==0){
        if(count!=-999){
            reg[y_ptr]=reg[y_ptr]-count;
        }
        else{
            reg[y_ptr]=reg[y_ptr]-reg[x_ptr];
        }   
    }
    else if(strcmp(str[0], "mul")==0){
        if(count!=-999){
            reg[y_ptr]=count*reg[y_ptr];
        }
        else{
            reg[y_ptr]=reg[x_ptr]*reg[y_ptr];
        }   
    }
    else if(strcmp(str[0], "div")==0){
        if(count!=-999){
            reg[y_ptr]=count/reg[y_ptr];
        }
        else{
            reg[y_ptr]=reg[x_ptr]/reg[y_ptr];
        }   
    }
}

int jump(char ** str,short int * reg) {
    int line=atoi(str[1]);
    int x=0;
    int y=0;
    if(strcmp(str[0],"jmp")==0) {
        return line;
    }
    int xptr=4;
    int yptr=4;
    //str 2 is x str 3 is y
    if(str[2][0]=='a') {
        xptr=0;
    }
    else if(str[2][0]=='b') {
        xptr=1;
    }
    else if(str[2][0]=='c') {
        xptr=2;
    }
    else if(str[2][0]=='d') {
        xptr=3;
    }
    //for str 3
    if(str[3][0]=='a') {
        yptr=0;
    }
    else if(str[3][0]=='b') {
        yptr=1;
    }
    else if(str[3][0]=='c') {
        yptr=2;
    }
    else if(str[3][0]=='d') {
        yptr=3;
    }
    //putting variables in x and y
    if(xptr==4) {
        x=atoi(str[2]);
    }
    else{
        x=reg[xptr];
    }
    if(yptr==4) {
        y=atoi(str[3]);
    }
    else{
        y=reg[yptr];
    }


    if(strcmp(str[0],"jle")==0) {
        if(x<=y) {
            return line;
        }
        else {
            return 0;
        }
    }
    else if(strcmp(str[0],"je")==0) {
        if(x==y) {
            return line;
        }
    }
    else if(strcmp(str[0],"jne")==0) {
        if(x!=y) {
            return line;
        }
    }
    else if(strcmp(str[0],"jg")==0) {
        if(x>y) {
            return line;
        }
    }
    else if(strcmp(str[0],"jge")==0) {
        if(x>=y) {
            return line;
        }
    }
    else if(strcmp(str[0],"jl")==0) {
        if(x<y) {
            return line;
        }
    }
}
// int jump (char **str, short int * reg) {
//  // int line=str[1][0];
//  // int count=0;
//  int xptr=0;
//  int yptr=0;
//  int num=0;
//  int num2=0;
//  if(strcmp(str[0],"jmp")==0) {
//      return (atoi)(str[1]);
//  }
//  else if(strcmp(str[0],"je")==0) {
//      if(isalpha(str[2][0])) {
//          if str[2][0]=='a'){
//              num=reg[0];
//          }
//          else if str[2][0]=='b'){
//              num=reg[1];
//          }
//          else if str[2][0]=='c'){
//              num=reg[2];
//          }
//          else if str[2]=='d'){
//              num=reg[3];
//          }
//          if(isalpha(str[3][0])) {
//              if str[3][0]=='a'){
//              num2=reg[0];
//          }
//          else if str[3][0]=='b'){
//              num2=reg[1];
//          }
//          else if str[3][0]=='c'){
//              num2=reg[2];
//          }
//          else if str[3]=='d'){
//              num2=reg[3];
//          }
//      }
//      else if(isdigit(str[3][0])) {
//              num2=atoi(str[3]);
//          }
            
 
//  }
// }
//  else if(strcmp(str[0],"jne")==0) {
 
//  }
//  else if(strcmp(str[0],"jg")==0) {
 
//  }
//  else if(strcmp(str[0],"jge")==0) {
 
//  }
//  else if(strcmp(str[0],"jl")==0) {
 
//  }
//  else if(strcmp(str[0],"jle")==0) {
 
//  }
 
 
// }
 
 
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
    
    
    // fscanf(fp,"%s ",str);
    // printf("%s\n",str);
    // fscanf(fp," %s\n",b);
    // printf("%s\n",b);
    char c; 
    //int count = 0; 
    char **str=(char **) malloc(6*sizeof(char*));
    for(int i=0; i<6; i++){
        str[i] = (char *)malloc(12*sizeof(char ));
    }
    short int regs[4]={0,0,0,0};
    int i=0;
    int arrayindex=0;
    int indicator=77;
    int jmp=0;
    int jmpcheck=0;
    int first=0;
    while((c = fgetc(fp)) != EOF) 
    { 
        if(jmp!=0) {
            if(first==0) {
                fp = fopen (filename, "r");
                first=1;
            }
            else if(c=='\n') {
                jmpcheck++;
            }
            if(jmpcheck==jmp) {
                jmp=0;
                first=0;
                jmpcheck=0;
            }
            continue;
        }
        else if(c == ' ' ) 
        { 
            str[i][arrayindex]='\0';
            i++;
            arrayindex=0; 
        } 
        else if(c=='\n') 
        { 
            if(indicator==77) {
                continue;
            }
            str[i][arrayindex]='\0';
            printf("%c", c); 
            if(strcmp(str[0],"read")==0) {
                read(str,regs);
                indicator=77;
            }
            else if(strcmp(str[0],"print")==0) {
                print(str,regs);
                indicator=77;
            }
            else if(strcmp(str[0],"add")==0 || strcmp(str[0],"sub")==0 || strcmp(str[0],"mul")==0 || strcmp(str[0],"mov")==0 || strcmp(str[0],"div")==0) {
                ops(str,regs);
                indicator=77;
            }
            else if(str[0][0]=='j') {
                jmp= jump(str,regs);
                indicator=77;
            }
            arrayindex=0;
            i=0;
            
        }
        else{
            str[i][arrayindex]=c;
            arrayindex++;
            indicator=0;
        } 
    } 
    for(int i=0;i<6;i++) {
        free(str[i]);
    } 
    free(str);
     fclose(fp);
    
   
    
        
    
}

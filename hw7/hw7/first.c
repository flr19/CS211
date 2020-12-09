#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//make linked list
//node : name,val int, next ptr
//functions access node and give value(use while ptr to get name==whatever) return . val of that node
//inseert a node
typedef struct node {
    char* name;
    int val;
    struct node* next;
}node;

void deletearraychar(char** arr,int rows){
    for(int i=0;i<rows;i++) {
        free(arr[i]);
    }
    free(arr);
}

void deletearrayint(int** arr,int rows){
    for(int i=0;i<rows;i++) {
        free(arr[i]);
    }
    free(arr);
}

void delete(node* linkedlist) {
    if(linkedlist!=NULL) {
        delete(linkedlist->next);
        free(linkedlist->name);
        free(linkedlist);
    }
    
    return;
    
}

//adding to temps
node* push( int num,node* first,char* nodename) {
    //printf("pushh\n");
    if(first==NULL) {
        node *temp=(node*) malloc(sizeof(node));
        temp->val=num;
        temp->next=NULL;
       // temp->name=nodename;
       temp->name=malloc(10*sizeof(char));
       strcpy(temp->name,nodename);
       //printf("nodes %s\n",temp->name);
        return temp;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->val=num;
    temp->next=NULL;
   temp->name=malloc(10*sizeof(char));
      strcpy(temp->name,nodename);
     //  printf("nodes 2 %s\n",temp->name);
       node* ptr=first;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
        
    }
    ptr->next=temp;
    return first;
}



int* decToBinary(int inputsizee,int n) {
    //array size is actually no of inputs
    int *binarynum=(int*)malloc((inputsizee)*sizeof(int));
    int i = 0; 
    for(int j=0;j<inputsizee;j++) {
        binarynum[j]=0;
    }
    while (n > 0) { 
        //print("%d\n",n);
        // storing remainder in binary array 
        binarynum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    return binarynum;
}

int* reverse(int* array,int cols ) {
    int temp=0;
    for(int j=0;j<(cols/2);j++) {
        temp=array[j];
        array[j]=array[cols-j-1];
        array[cols-j-1]=temp;
    }
    return array;
}

int** populatearray(int size,int norows) {
    //size being input size
    int** num=(int**) malloc((norows)*sizeof(int*));
    // for(int i=0;i<norows;i++) {
    //     num[i]=(int*)malloc((size)*sizeof(int));
    // }
    
    
  //  int* binary=(int*)malloc((size)*sizeof(int));
    for(int j=0;j<norows;j++) {
            // binary=decToBinary(size,j); //returns 0 1 2 3 in binary based on row number
            num[j]=reverse(decToBinary(size,j), size); ///what is this
    }
    return num;
    
}

int andd(int input1,int input2){
  if(input1==1&&input2==1){
    return 1;
  }

  return 0;
}

int orgate(int input1,int input2){
  if(input1==1||input2==1){
    return 1;
  }

  return 0;
}

int nandgate(int input1,int input2){
  if(input1==1&&input2==1){
    return 0;
  }

  return 1;
}

int norgate(int input1,int input2){
  if(input1==1||input2==1){
    return 0;
  }

  return 1;
}

int xorgate(int input1,int input2){
	if(input1!=input2) {
        return 1;
    }
    return 0;
}

int getval(char* str,char** array,int charsize,int** num,int currRow,node* queue) { //add node* queue
    //if first letter is capital or small
    //if small its temp so its in queue,while ququeue.name!=str
    //else its in array
    //if its in array then for loop thru array and once u have index which is ur curr str then return index
    //for queue return number itself
    //once u have index use that as column for num array and use currRow for the row
    //and return the element
   // printf("%s\n",str);
    if(str[0]<='Z' && str[0]>='A') {
        int index=0;
        for(int i=0;i<charsize;i++) {
            if(strcmp(array[i],str)==0) {
                index=i;
            }
        }
        int number=num[currRow][index];
        return number;
    }
    else {
        node *ptr=queue;
        while(strcmp(str,ptr->name)!=0) {
            ptr=ptr->next;
        }
        return ptr->val;
    }
}



int main(int argc, char* argv[])
{
    if(argc!=2) {
        printf("error\n");
        return 1;
    }
    char * filename = argv[1];
    FILE * fp = fopen (filename, "r");
    if (!fp) 
    {
        printf("error\n");
        return -1;
    }
    int inputsize;
    fscanf(fp,"INPUTVAR %d",&inputsize);
    int i=0;
    char** inputs=(char**) malloc(inputsize*sizeof(char*));
     for(int i=0;i<inputsize;i++) {
         inputs[i]=(char*)malloc((10)*sizeof(char));
    }
    while(i!=inputsize) {
        fscanf(fp," %s",inputs[i]);
        i++;
    }
    fscanf(fp,"\n");
    // for(int i=0;i<inputsize;i++) {
    //     printf("%s",inputs[i]);
    // }
    //use row number to get column number of array
    //already have col number now want tow number u want to access
    //going one row at a time
    //in the 1010 array

    int outputsize;
    fscanf(fp,"OUTPUTVAR %d",&outputsize);
    //printf("%d\n",outputsize);
    int j=0;
    char** outputs=(char**) malloc(outputsize*sizeof(char*));
     for(int i=0;i<outputsize;i++) {
        outputs[i]=(char*)malloc((10)*sizeof(char));
    }
    while(j!=outputsize) {
        fscanf(fp," %s",outputs[j]);
        j++;
    }
    fscanf(fp,"\n");
    // for(int i=0;i<outputsize;i++) {
    //     printf("%s",outputs[i]);
    // }
    int rows=pow(2,inputsize);
   int** array=populatearray(inputsize,rows);
//     printf("pop array\n");
//        for(int i=0;i<rows;i++) {
//        printf("\n");
//        for(int j=0;j<inputsize;j++) {
//            printf("%d\t",array[i][j]);
//        }
//    }
   int **finaloutput=(int**) malloc(rows*sizeof(int*));
   for(int i=0;i<rows;i++) {
       finaloutput[i]=(int*) malloc(outputsize*sizeof(int));
   }

    
    int val1;
    int val2;
    int output;
    char oprn[10];
    char * var1 = malloc(10*sizeof(char));
    char * var2 = malloc(10*sizeof(char));
    char * var3 = malloc(10*sizeof(char));
    int indexinoutput;
    char c = 'a';
    node* linkedlist=NULL;
    for(int i=0;i<rows;i++) {
        delete(linkedlist);
        linkedlist=NULL;
        fp = fopen (filename, "r");
        c = fgetc(fp);
        while(c!='\n'){
            c = fgetc(fp);
        }
        c = fgetc(fp);
        while(c!='\n'){
            c = fgetc(fp);
        }
            
        while(1) {
            // not reads 2 words, others read 3 words
            
           
            if(fscanf(fp, "%s ", oprn)==EOF){
			    break;
            }
            if(strcmp(oprn,"NOT")==0) {
                    //if its small letter for last arg store result in queue or else store in output
                    //for output arr get index of col ,row(i),outputarr[i][col]
                    //create outputarray output variable numbers(cols) and rows same as inputarr
                    fscanf(fp," %s %s",var1,var3);
                    fscanf(fp,"\n");
                    if(getval(var1,inputs,inputsize,array,i,linkedlist)==1) {
                        output=0;
                    }
                    else {
                        output=1;
                    }
                    
            }
            else if(strcmp(oprn,"AND")==0 || strcmp(oprn,"OR")==0 || strcmp(oprn,"NAND")==0 || strcmp(oprn,"NOR")==0 || strcmp(oprn,"XOR")==0) {
                fscanf(fp," %s %s %s",var1,var2,var3);
                val1=getval(var1,inputs,inputsize,array,i,linkedlist);
                val2=getval(var2,inputs,inputsize,array,i,linkedlist);
                //output=andd(val1,val2);
                char firstletter=var3[0];

                if(strcmp(oprn,"AND")==0) {
                    output=andd(val1,val2);
                }
                else if(strcmp(oprn,"OR")==0) {
                    output=orgate(val1,val2);
                }
                else if(strcmp(oprn,"NAND")==0) {
                    output=nandgate(val1,val2);
                }
                else if(strcmp(oprn,"NOR")==0) {
                    output=norgate(val1,val2);
                }
                else if(strcmp(oprn,"XOR")==0) {
                    output=xorgate(val1,val2);
                }
            }
                
                //after all the ops are done
                if(var3[0]<='Z' && var3[0]>='A') {
                    for(int k=0;k<outputsize;k++) {
                        if(strcmp(var3,outputs[k])==0) {
                            finaloutput[i][k]=output;
                            break;
                        }
                    }
                    
                }
                else {
                    linkedlist=push(output,linkedlist,var3);
                    node* ptr=linkedlist;
                    while(ptr!=NULL) {
                        //printf("lalala %d",ptr->val);
                        ptr=ptr->next;
                        
                    }

                    //printf("cool\n");
                }
            
            
            
        }
       
    }

    
   //printf("aaaaa\n");

    for(int i=0;i<rows;i++) {
        for(int j=0;j<inputsize;j++) {
            printf("%d ",array[i][j]);
        }
        for(int k=0;k<outputsize;k++) {
            if(k==outputsize-1) {
                printf("%d\n",finaloutput[i][k]);
                continue;
            }
            printf("%d ",finaloutput[i][k]);
        }
    }
    delete(linkedlist);
    deletearrayint(array,rows);
    deletearraychar(outputs,outputsize);
    deletearraychar(inputs,inputsize);
    deletearrayint(finaloutput,rows);
    free(var1);
    free(var2);
    free(var3);
    fclose(fp);
}

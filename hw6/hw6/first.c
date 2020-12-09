#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node {
    long long int val;
    struct node* next;
}node;

void delete(node * queue){
	if(queue!=NULL)
	{
		if(queue->next!=NULL)
			delete(queue->next);
		free(queue);
	}
	return;
}

void printqueue(node * queue){
    printf("Queue begins ->\n");
    while(queue!=NULL){
        printf("%lli",queue->val);
        queue=queue->next;
        printf("->");
    }
    printf("\n");
    return;

}

long long int** deletearraylong(long long int **mat, int row, int col)
{
	//printf("helloi\n");
	for(int i=0; i<row; i++){
		free(mat[i]);
	}
	free(mat);
	//mat=NULL;
	return mat;
}

node** deletearraynode(node **mat, int row, int col)
{
	//printf("helloi\n");
	for(int i=0; i<row; i++){
		free(mat[i]);
	}
	free(mat);
	//mat=NULL;
	return mat;
}

node* push(long long int num,node* first) {
    if(first==NULL) {
        node *temp=(node*) malloc(sizeof(node));
        temp->val=num;
        temp->next=NULL;
        first=temp;
        return first;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->val=num;
    temp->next=NULL;
       node* ptr=first;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
        
    }
    ptr->next=temp;
    return first;
}

long long int pop(node** queue) {
    node *first=(*queue);
    (*queue)=(*queue)->next;
    long long int num=first->val;
    free(first);
    return num;
}

void poppi(long long int select,node** first) {
    node *prev=NULL;
    node * queue = (*first);
    while(queue->val!=select) {
        prev=queue;
        queue=queue->next;
    }
    if(prev==NULL){
        (*first) = (*first)->next;
        free(queue);
        return;
    }
    prev->next=queue->next;
    free(queue);
    return;


}

long long binarytodecimal(int arr[],int size) {
    long long decimalval=0;
    int power=0;
    for(int i=size-1;i>=0;i--) {
        decimalval=decimalval+(pow(2,power)*arr[i]);
        power++;
    }
    return decimalval;
}

int* hextobinary (char hexval[],int size) {
    int* num=(int*)malloc(48*sizeof(int));
    for(int i=0;i<48;i++) {
        num[i]=0;
    }
    int j=47;
    for(int i=size-1;i>=0;i--) {
        if(hexval[i]=='x') {
            break;
        }
        switch (hexval[i]) {
        case '0':
            num[j]=0;
            j--;
            num[j]=0;
            j--;
            num[j]=0;
           j--;
            num[j]=0;
             j--;
            break;
        case '1':
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
            j--;
            break;
        case '2':
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            break;
        case '3':
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            break;
        case '4':
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            break;
        case '5':
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            break;
        case '6':
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            break;
        case '7':
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            break;
        case '8':
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            break;
        case '9':
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            break;
        case 'A':
        case 'a':
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            break;
        case 'B':
        case 'b':
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            break;
        case 'C':
        case 'c':
            num[j]=0;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            break;
        case 'D':
        case 'd':
            num[j]=1;
             j--;
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            break;
        case 'E':
        case 'e':
            num[j]=0;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            break;
        case 'F':
        case 'f':
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            num[j]=1;
             j--;
            break;
        
        }
         
    }
    // for(int i=0;i<48;i++) {
    //     printf("%d",num[i]);
    // }
  //  printf("\n");
  //  free(num);
    return num;
}

int main(int argc, char* argv[])
{
    if(argc!=6) {
        printf("error\n");
        return 1;
    }
    long long int cachesize=atoi(argv[1]);
    char *assoc=argv[2];
    char *replc=argv[3];
    char *tracefile=argv[5];
    long long int blocksize=atoi(argv[4]);
    int sets=0;
    int lines=0;
    if(strcmp(argv[2], "direct") == 0){
        lines = 1;
        sets = cachesize / blocksize;
    }
    else if(strcmp(argv[2], "assoc") == 0){
        sets = 1;
        lines = cachesize / blocksize;
    }
    else{
        sscanf(argv[2], "assoc:%d", &lines);
        sets = cachesize / lines / blocksize;
    }
    int offsetsize=log(blocksize)/log(2);
   // printf("offset is %d\n",offsetsize);
    int indexsize=log(sets)/log(2);
   // printf("set number %d\n",sets);
   // printf("sets is %d\n",indexsize);
    int tagsize=48-indexsize-offsetsize;
    //printf("tagsize is %d\n",tagsize);
    long long int** matrix=(long long**)malloc(sets*sizeof(long long int*));
    for(int i=0;i<sets;i++) {
        matrix[i]=(long long int *)malloc((lines)*sizeof(long long int));
    }
    for(int i=0;i<sets;i++) {
        for(int j=0;j<lines;j++) {
            matrix[i][j]=-1;
        }
    }
    node** policy=(node**) malloc(sets*sizeof(node*));
     for(int i=0;i<sets;i++) {
        policy[i]=NULL;
    }
    //scanf("%d %s %s %d %s",&cachesize,assoc,replc,&blocksize,tracefile);
  //  printf("%d\n", blocksize);
    FILE * fp = fopen (tracefile, "r");
    
    if (!fp) 
    {
        printf("error\n");
        return 1;
    }
    char status;
    char address[20];
    unsigned long int firstco;
    int num[48];
    for(int i=0;i<48;i++) {
        num[i]=0;
    }
    int hit=0;
    int miss=0;
    int write=0;
    int read =0;
    while(1) {
        //printf("here\n");
        int n=fscanf(fp, "%lx: %c %s",&firstco,&status,address);
       
      //  printf("%d",n);
      //  printf("ok loop\n");
        if(n!=3) {
            break;
        }
        
        int* binary=hextobinary(address,strlen(address));
        
        //int setbits[indexsize];
        //printf("start %d\n",binary[48-1-offsetsize]);

        //setting decimal array for set bits
        // int indexofsetbit=0;
        //     for (int j=48-offsetsize-indexsize;j<=48-1-offsetsize;j++) {
        //        // printf("index %d\n",j);
        //        if(indexofsetbit==indexsize) {
        //            break;
        //        }
        //        setbits[indexofsetbit]=binary[j];
        //        indexofsetbit++;
        //         //printf("index val %d\n",binary[j]);
        //     }
        long long int decimalset = binarytodecimal(&binary[tagsize], indexsize);
      
       // printf("dec val %lld\n", decimalset);
        
        //setting decimal array for tag bit
        // int tagbits[tagsize];
        // for(int i=0;i<tagsize;i++) {
        //     tagbits[i]=binary[i];
        // }
        // printf("tag val\n");
        // for(int i=0;i<tagsize;i++) {
        //     printf("%d",tagbits[i]);
        // }
        // printf("over here\n");
        long long int tagbitsdecimal=binarytodecimal(binary,tagsize);
      
        //check if tag is in row of set
        
        for(int i=0;i<lines;i++) {
            if(i==lines-1 && matrix[decimalset][i]!=-1 && tagbitsdecimal!=matrix[decimalset][i]) {
                miss++;
                    //if its w write and read
                //if its r just read
                if(status=='W') {
                    write++;
                    read++;
                }
                else if(status=='R') {
                    read++;
                }
                    long long int number=pop(&policy[decimalset]);
                     policy[decimalset] =push(tagbitsdecimal,policy[decimalset]);
                  //  printf("what happen\n");
                    for(int j=0;j<lines;j++) {
                        //change set to decimalset
                        if(number==matrix[decimalset][j]) {
                            matrix[decimalset][j]=tagbitsdecimal;
                            
                            break;
                        }
                    }
                    //printqueue(policy[decimalset]);
                    break;
                

            } 
            else if(matrix[decimalset][i]==-1) {
                miss++;
                //miss
                //if its w write and read
                //if its r just read
                if(status=='W') {
                    write++;
                    read++;
                }
                else if(status== 'R' ) {
                    read++;
                }
                matrix[decimalset][i]=tagbitsdecimal;
                policy[decimalset] =push(tagbitsdecimal,policy[decimalset]);
               
                break;
            }
            else {
                if(matrix[decimalset][i]==tagbitsdecimal) {
                    //hit
                    //if w write if its r nothing
                    hit++;
                    if(status=='W' ) {
                        write++;
                    }
                    if(strcmp(argv[3],"lru")==0) {
                    
                    poppi(tagbitsdecimal,&policy[decimalset]);
                     policy[decimalset] =push(tagbitsdecimal,policy[decimalset]);
                     
                     break;
                     //mistake here?? goes back to for loop
                    }
                }
            }
        }
        free(binary);
        
    //    free(setbits);
    //    printf("free2\n");
    //    free(tagbits);
    //    printf("free\n");
        
    }
    
    printf("Memory reads: %d\n",read);
        printf("Memory writes: %d\n",write);
        printf("Cache hits: %d\n",hit);
        printf("Cache misses: %d\n",miss);
       for(int i=0;i<sets;i++) {
           delete(policy[i]);
       }
       free(policy);
       deletearraylong(matrix,sets,lines);
       
    
    

}

    //associaticity
    // if(strcmp(assoc,"direct")==0) {

    // }
    // else if(strcmp(assoc,"assoc")==0) {

    // }
    // else if(strcmp(assoc[0],"a")==0 && strcmp(assoc[1],"s")==0 && strcmp(assoc[2],"s")==0 && strcmp(assoc[3],"o")==0 && strcmp(assoc[4],"c")==0 && strcmp(assoc[5],":")==0) {

    // }
    // else {
    //     //error
    // }


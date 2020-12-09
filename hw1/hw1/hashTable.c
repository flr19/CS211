 #include <stdio.h>
#include <stdlib.h>
#define NOOFBUCKETS 10000
typedef struct Node {
    int data;
    struct Node* next;
} Node;
int hashCode(int item) {
    int key=item%NOOFBUCKETS;
    if(key<0) {
        key=key+NOOFBUCKETS;
    }
    return key;
}

struct Node* linkedlistsortedinsert(int key,struct Node *head) {
    Node *curr=head;
     
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    /* If the tree is empty, return a new Node */
     if (curr == NULL) {

        temp->data = key;
        temp->next=NULL;
        // temp=NULL;
        // free(temp);
        return temp;
     }
    /* Otherwise, recur down the tree */
    if (key < curr->data) {

        temp->data = key;
        temp->next=curr;
        // temp=NULL;
        // free(temp);
        return temp;
     }
    else{ //locate node before point of insertion
        struct Node *prev=NULL;

        while(curr!=NULL && curr->data<=key) {
            prev=curr;
            curr=curr->next;
            
        }
        temp->data = key;
        temp->next=curr;
        prev->next=temp;
        // temp=NULL;
        // free(temp);
        return head;
    }

}

void freeNodes(Node *head)
{ 
    struct Node *prev;
    //free(prev);
    while (head != NULL) 
    { 
        prev = head;
        head = head -> next;
        free(prev);
    } 
   // free(head);
    //free(prev);
}



int insert(int val,struct Node * map[]) {
    int key=hashCode(val);
    struct Node* hashNode=(struct Node*) malloc(sizeof(struct Node));
    if(map[key]==NULL) {
        map[key]=hashNode;
        //printf("ok\t key %d\t value %d\n",key,val);

        hashNode->next=NULL;
        hashNode->data=val;
        hashNode=NULL;
        free(hashNode);
        return 0;
    }
    else { 
       map[key]=linkedlistsortedinsert(val,map[key]);
        //printf("colission\t key %d\t value %d\n",key,val);
      // hashNode=NULL;
        free(hashNode);
       return 1;
    }

}
void printList(struct Node* curr) 
{ 
    while (curr != NULL) { 
        printf("%d\t", curr->data); 
        curr = curr->next; 
    } 
    printf("\n");
} 

void printhashtable(struct Node *map[]) {
    printf("print ht\n");
    for(int i=0;i<NOOFBUCKETS;i++) {
        printList(map[i]);
    }
}

int search(int val,struct Node * map[]) {
    int key=hashCode(val);
    int count=0;
    if(map[key]==NULL) {
        return count;
    }
    else {
        Node *temp=map[key];
        while(temp!=NULL && temp->data<val) {
            temp=temp->next;
        }
        if (temp==NULL) {
            return count;
        }
        else{
            while(temp!=NULL && temp->data==val) {
                count++;
                temp=temp->next;
            }
            return count;
        }
    }
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
    char oprn;
	int val;
    struct Node *hashtable[NOOFBUCKETS]={NULL}; 
    int collisionCount=0;
    int searchCount=0;
	while(1){
		int n = fscanf(fp, "%c\t%d\n", &oprn, &val);
        //printf("%c\t%d\n",oprn,val);
		
		if(n!=2) {
			break;
        }
        if(oprn=='i') {
            if( insert(val,hashtable)) {
                
                collisionCount++;
            }
         }
        if(oprn=='s') {
            if(search(val,hashtable)>0) {
                searchCount++;
            } 
        }
    }
   // printhashtable(hashtable);
    printf("%d\n",collisionCount);
    printf("%d\n",searchCount);
    for(int i=0;i<NOOFBUCKETS;i++) {
        freeNodes(hashtable[i]);
    }
    return 0;
 }

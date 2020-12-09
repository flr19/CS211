#include <stdio.h>
#include <stdlib.h>
int size=0;
typedef struct Node {
    int num;
    struct Node* next;
} Node;
int printList(struct Node* curr) 
{ 
    while (curr != NULL) { 
        printf("%d\t", curr->num); 
        curr = curr->next; 
    } 
    printf("\n");
    return 0;
} 
// int *newNode(struct Node *ptr,int key) 
// { 
//     ptr =  (struct Node *)malloc(sizeof(struct Node)); 
//     ptr->num = key; 
//     ptr->next = NULL; 
//     return 0; 
// } 

struct Node* insert(Node* head, int key) 
{ 
    Node *curr=head;
    size++;
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    /* If the tree is empty, return a new Node */
     if (curr == NULL) {

        temp->num = key;
        temp->next=NULL;
        return temp;
     }
    /* Otherwise, recur down the tree */
    if (key < curr->num) {

        temp->num = key;
        temp->next=curr;
        return temp;
     }
    else{ //locate node before point of insertion
        struct Node *prev=NULL;

        while(curr!=NULL && curr->num<key) {
            prev=curr;
            curr=curr->next;
            
        }
        temp->num = key;
        temp->next=curr;
        prev->next=temp;
        return head;
    }
} 
struct Node* deleteNode(struct Node *head, int key) 
{ 
    // Store head node 
    struct Node* curr= head; 
    struct Node *prev=NULL;
    struct Node * listhead=head;
  
    // If head node itself holds the key to be deleted 
    
    if(curr==NULL) {
        return listhead;
        
    }
    else if(curr->num==key) {
        listhead=curr->next;
        free(curr);
        size--;
        return listhead;
    }
    else {
        while (curr!=NULL && curr->num!=key ) {
            prev=curr;
            curr=curr->next;
            
        }

        if(curr->num==key) {
            prev->next=curr->next;
        }
        size--;
        free(curr);
        return listhead ;
    }
    
} 
void freeNodes(Node *head)
{ struct Node *prev;
    while (head != NULL) 
    { 
        prev = head;
        head = head -> next;
        free(prev);
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
    struct Node *head=NULL;
	while(1){
		int n = fscanf(fp, "%c\t%d\n", &oprn, &val);
        //printf("%d\n",val);
        // printf("%c\n",oprn);
		// printf("yes\n");
		if(n!=2) {
			break;
        }
       // printf("%d\n",val);
        //printf("%c\n",oprn);
		if(oprn=='i'){
            //printf("ok\n");
			head=insert(head,val);
            //printList(head);
        }
        if(oprn=='d'){
           // printf("b4 delete");
           //printList(head);
			head=deleteNode(head,val);
            //printf("aft delete");
           //printList(head);
        }
    }
    printf("%d\n",size);
   printList(head);
   freeNodes(head);
   return 0;
}

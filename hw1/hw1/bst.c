#include <stdio.h>
#include<stdlib.h> 
typedef struct BSTNode {
        int num;
        struct BSTNode * left;
        struct BSTNode * right;
} BSTNode;
int inorderTraversal(struct BSTNode *root){
        if(root==NULL) {
            return 0;
        }
        inorderTraversal(root->left);
        printf("%d\t",root->num);
        inorderTraversal(root->right);
        return 0;
        
}

struct BSTNode *newNode(int item) 
{ 
    struct BSTNode *temp =  (struct BSTNode *)malloc(sizeof(struct BSTNode)); 
    temp->num = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct BSTNode* insert(BSTNode* node, int key) 
{ 
    /* If the tree is empty, return a new node */
     if (node == NULL) {
         return newNode(key); 
     }
    /* Otherwise, recur down the tree */
    if (key < node->num) {
        node->left  = insert(node->left, key);} 
    else if (key > node->num){ 
        node->right = insert(node->right, key);}    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
int delete(BSTNode * node)
{
        if(node!=NULL)
        {
                if(node->right!=NULL)
                    delete(node->right);
                if(node->left!=NULL)
                	delete(node->left);
                free(node);
        }

        return 0;
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
    struct BSTNode *root = NULL;
	while(1){
		int n = fscanf(fp, "%c\t%d\n", &oprn, &val);
        //printf("%d\n",val);
		//printf("yes\n");
		if(n!=2) {
			break;
        }
		if(oprn=='i'){
			//make a root ptr at beginning of program, keep adding to this ptr
            //check if root ptr is null, if its null add node there
            //when u want to find values go to the ptrs child,going to child happens in while loop
            //while go until ptr null, in while loop: if the current val is less than curr val of ptr
            //then go to left, otherwise go to right
            //if root ptr is null then add
            // if ptr.next is null make a new node and point ur ptr.next to that node
            //after this use a while loop which checks if left or right val is greater,
            // if val is>ptr.val then go ptr.righta
            root=insert(root,val);
            
            }
    }
    //delete root
    inorderTraversal(root);
    delete(root);

}

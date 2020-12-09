#include <stdio.h>
 int swap (int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char* argv[])
{
    FILE *f = fopen(argv[1], "r");
    int num;
    fscanf(f,"%d\n",&num);

    int arr[num];
    for( int i=0;i<num;i++){
        fscanf(f,"%d\t",&arr[i]);
    }
    
    /*for(int i=0;i<num;i++){
        printf("%d",arr[i]);
    }
    */
    //split function 
    int count=0;
    for(int s=0;s<num;s++) {
        if(arr[s]%2==0) {
            count++;
        }
    }
   int i,j;
   for(i=0;i<num-2;i++) {
       for(int j=i+1;j<=num-1;j++) {
           
           if(j==num && j%2==0){
              int temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
              break; 
           }
           if(j==num && j%2!=0){
               break;
           }
           
           if(arr[i]%2!=0) {
               if(arr[j]%2==0) {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                else {
                    continue;
                }
           }
         

       }
    
   }

  
    for(int i = 0; i < count; i++)
		for(int j = i+1; j < count; j++)
		{
			if (arr[j]<arr[i])
				swap(&arr[i], &arr[j]);
		}
	for(int i = count; i < num; i++)
		for(int j = i+1; j < num; j++)
		{
			if (arr[j]>arr[i])
				swap(&arr[j], &arr[i]);
		}
       
    for(int g=0;g<num;g++) {
        printf("%d\t",arr[g]);
    }
     
    
   

}


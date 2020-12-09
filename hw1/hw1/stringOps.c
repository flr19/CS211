#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    for(int i=1;i<argc;i++) {
        char * cptr= argv[i];
        for (int j=0;j<strlen(cptr);j++) {
            char letter=*(cptr+j);
            if(letter=='a'||letter=='A'||letter=='e'||letter=='E'||letter=='i'||letter=='I'||letter=='o'||letter=='O'||letter=='U'||letter=='u'){
                printf("%c",letter);
            }
        
        }
    }
    return 0;
}

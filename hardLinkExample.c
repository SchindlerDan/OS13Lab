#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	
	if(argc == 3){
		printf("\nAttempting to create hard link\n");
	    if(link(argv[1],argv[2])==-1){
	       printf("Link Error\n");
	       return 1;
	    }
	}
	else if(argc == 4 && strcmp(argv[3], "-s") == 0){
	    	printf("\nAttempting to create soft link\n");
		if(symlink(argv[1],argv[2]) == -1){
			printf("Link Error \n");
	       		return 1;
	    	}
        }
	else{
          printf("Not Enough Arguments.\n");
	  return 0;
	}

	printf("Files Linked\n");
	printf("Inode number of linked files \n");
	char str[100];
	sprintf(str,"ls -i %s %s \n",argv[1], argv[2]);
	system(str);
	return 0;

}

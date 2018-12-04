#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	
	if(argc == 3){
	    if(link(argv[1],argv[2])==-1){
	       printf("Link Error\n");
	       return 1;
	    }
	}
	else if(argc == 4 && argv[3] == "-s"){
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

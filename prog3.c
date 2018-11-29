// is this Sample Program 1?

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 30

int main(int argc, char *argv[])
{
   struct flock fileLock;
   int fd;
   FILE* myFile;
   char buf[SIZE] = "// is this Sample Program 1?";

   if (argc < 2) {
      printf ("usage: filename\n");
      exit (1);
   }
   if ((fd = open (argv[1], O_RDWR)) < 0) {
      perror ("there is");
      exit (1);
   }

   fileLock.l_type = F_WRLCK;
   fileLock.l_whence = SEEK_SET;
   fileLock.l_start = 0;
   fileLock.l_len = 0;
   if (fcntl (fd, F_SETLKW, &fileLock) < 0) {
      perror ("no way");
      exit (1);
   }

   //write (fd, buf, SIZE-2);
   myFile = fopen(argv[1], "r");
   printf("\n %s \n", fgets(buf, sizeof(buf), myFile));

   sleep (10);
   if (fcntl (fd, F_UNLCK) < 0) {
      perror ("no way lock error");
      exit (1);
   }

   close(fd);

   return 0;
} 

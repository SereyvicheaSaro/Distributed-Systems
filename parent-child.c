    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    int pid, i, fd; char c;
    int main(){
       fd = creat( "TEST", 0644);
       if( !(pid = fork())){ /* child process */
               c = 'a';
               for(i=0; i < 5; i++){
                 write(fd, &c, 1); c++; sleep(1);
               }
               printf("child %d exit\n", getpid());
               exit(0);
       }
       /* else parent process */
       c = 'A';
       for(i=0; i < 5; i++){
               write(fd, &c, 1); c++; sleep(1);
       }
       printf("Parent %d process of %d exit\n",
               getpid(), pid );
    }


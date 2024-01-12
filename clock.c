    #include <signal.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    void tick(int nsig){
       time_t tim; char *s;
       signal (SIGALRM, tick);
       alarm(1); time(&tim);
       s = ctime(&tim);
       s[ strlen(s)-1 ] = '\0'; /* delete char '\n' */
       fprintf(stderr, "\r%s", s);
    }
    int main(){ tick(0);
            for(;;) pause();
            
    }


    #include <signal.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    /* Handler of signal */
    static void sig_hndlr(int signo)
    {
    /* Restore dispozition */
	signal (SIGINT, sig_hndlr);
	printf("Signal SIGINT\n");
    }
    int main()
    { 
    /* Setup dispozition */
	signal (SIGINT, sig_hndlr);
	signal (SIGUSR1, SIG_DFL);
	signal (SIGUSR2, SIG_IGN);
    /* Cicle */
	while(1)
	    pause();
    }


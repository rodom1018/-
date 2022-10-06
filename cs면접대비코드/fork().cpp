#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*

Press Ctrl-C to stop
Parent pid: 712 716
Child pid: 716 0 
여기서부터 시작하는 군요 716 717
hello? 717 0
여기서부터 시작하는 군요 717 0
*/


int main(int argc, const char * argv[]) {
    int pid;

	puts("Press Ctrl-C to stop");

	pid = fork();
	if (pid == -1) {
		// possible errors: EAGAIN, ENOMEM.
	    perror("Failed to fork");
	    return -1;
	}

	if (pid == 0) {
		// child
		printf("Child pid: %d %d \n", getpid(), pid);
		pid = fork();
		if(pid == 0 ){
		    printf("hello? %d %d\n", getpid(), pid);
		}
		printf("여기서부터 시작하는 군요 %d %d\n", getpid(), pid);
	} else {
		// parent
		printf("Parent pid: %d %d\n", getpid(), pid);
		while(1);
	}

	return 0;
}
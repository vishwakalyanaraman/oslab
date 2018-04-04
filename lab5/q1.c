#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
fprintf(stdout,"parent\n");
pid_t p_1;
fprintf(stdout,"%d %d\n",getpid(),getppid());
p_1=fork();
if(p_1==0)
{
fprintf(stdout,"child process\n");
fprintf(stdout,"%d %d\n",getpid(),getppid());
}
return 0;
}

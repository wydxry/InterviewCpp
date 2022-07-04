#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT 0
#define OUTPUT 1
int main()
{
    //创建管道
    int fd[2];
    pipe(fd);

    //创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("fork error!\n");
        exit(-1);
    }
    else if (pid == 0)
    {   //执行子进程
        printf("Child process is starting...\n");
        
        //子进程向父进程写数据，关闭管道的读端
        close(fd[INPUT]);
        write(fd[OUTPUT], "hello parent!", strlen("hello parent!"));
        exit(0);
    }
    else
    {  //执行父进程
        printf("Parent process is starting......\n");
        
        //父进程从管道读取子进程写的数据 ，关闭管道的写端
        close(fd[OUTPUT]);
        char buf[255];
        int output = read(fd[INPUT], buf, sizeof(buf));
        printf("%d bytes of data from child process: %s\n", output, buf);
    }
    return 0;
}


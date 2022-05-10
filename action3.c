#include <pthread.h>
#define NUM_THREADS 4
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

pthread_t tid[NUM_THREADS];
void sig_func(int sig){
    printf("Caught signal no = %d\n", sig);
    
    
    if(sig==2){
        pthread_kill(tid[0], SIGINT);
    }
    if(sig ==6){
        pthread_kill(tid[0], SIGABRT);
    }
    
    // if ( sig == 2 || sig == 4 || sig ==6 ){
    //     printf("Sending signal to thread: 0\n");
    //     pthread_kill(tid[0], SIGINT);
    //     pthread_kill(tid[0], SIGABRT);
    //     pthread_kill(tid[0], SIGILL);
    // }

    // if ( sig == 20 || sig == 11 || sig == 8 ){
    //     printf("Sending signal to thread: 1\n");
    //     pthread_kill(tid[1], SIGCHLD);
    //     pthread_kill(tid[1], SIGSEGV);
    //     pthread_kill(tid[1], SIGFPE);
    // }

    // if ( sig == 1 || sig == 18 ){
    //     printf("Sending signal to thread: 2\n");
    //     pthread_kill(tid[2], SIGHUP);
    //     pthread_kill(tid[2], SIGTSTP);
    // }
}

void sig_func2(int sig) {
    printf("Terminated by signal no = %d, in thread 0\n", sig);
}

void sig_func3(int sig) {

        printf("Terminated by signal no = %d, in thread 1\n", sig);
}

void sig_func4(int sig) {
    printf("Terminated by signal no = %d, in thread 2\n", sig);
}

void sig_func5(int sig) {
        pause();
        printf("Terminated by signal no = %d, in thread 3\n", sig);
}
void sig_func6(int sig) {
        resume();
        printf("Terminated by signal no = %d, in thread 3\n", sig);
}

void *threadFunc (void *thread_id) {

    int id = *((int*)thread_id);
    if (id == 0 ) {
       sleep(1);
        signal( SIGINT, sig_func2);
        signal( SIGABRT, sig_func2);
        // signal( SIGABRT, sig_func2);
        // signal( SIGILL, sig_func2);
    }
    if (id == 1 ) {
        sleep(1);
        signal(SIGINT, sig_func3);
        sigal(SIGABRT, sig_func3);
        // signal(SIGFPE, sig_func3);
    }
    if (id ==2 ) {
     //   signal(SIGINT, sig_func);


//      signal(SIGINT, sig_func);
     pthread_kill(tid[0],SIGINT);
     pthread_kill(tid[0],SIGABRT);
    // signal(SIGINT, sig_func4);

        // signal(SIGTSTP, sig_func4);
        // signal(SIGCHLD, sig_func4);
    }
    if (id == 3 ) {
        sleep(1);
        signal(SIGINT, sig_func5);
        signal(SIGABRT, sig_func6);
        // signal( SIGINT, sig_func5);
    }
    printf("Thread number %d \n", id);




}


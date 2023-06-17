#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

// 思想：互相唤醒对方
int g_num = 1;
pthread_mutex_t mutex;
pthread_cond_t cond1,cond2;

void* thread1(void* arg) { // 由于线程2开头sleep，来保证线程1先执行
	while(1) {
		pthread_mutex_lock(&mutex);
        //如果需要交替打印一定范围(例如1-10)内的数字，那么可以加上下面两行代码，相当于线程1持有锁退出了
        if(g_num > 10) exit(1);
        printf("Thread1: %d \n",g_num);
        g_num ++;
        pthread_cond_signal(&cond2);
        pthread_cond_wait(&cond1,&mutex);		
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}

void* thread2(void* arg) {
	while(1) {
        sleep(1); // 开头先sleep, 可以保证线程1先执行
		pthread_mutex_lock(&mutex);
        printf("Thread2: %d \n",g_num);
		g_num++;
        pthread_cond_signal(&cond1);
        pthread_cond_wait(&cond2,&mutex);
		pthread_mutex_unlock(&mutex);
		
	}
	return NULL;
}
int main() {
    // 初始化互斥锁mutex，两个条件标量cond1, cond2
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond1,NULL);
	pthread_cond_init(&cond2,NULL);	
	
	// 创建两个线程p1, p2
	pthread_t p1,p2;
	pthread_create(&p1,NULL,thread1,NULL);
	pthread_create(&p2,NULL,thread2,NULL);
    pthread_detach(p1);
    pthread_detach(p2);

	// 销毁
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);

	return 0;
}
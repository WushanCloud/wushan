//shm_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>//ipc
#include <sys/shm.h>
#include <unistd.h>
 
struct sys_data
{
	float data_rh;
	float data_t;
};
 
int main(int argc, char const *argv[])
{
	void* shm=(void*)0;
	int shmid;
	struct sys_data *da;
	float ftemp=0.0,fhumi=0.0;
	//set share memory;
	//创建一个共享内存对象
	shmid=shmget((key_t)8891,sizeof(struct sys_data),0666|IPC_CREAT);
	if(shmid==-1)
	{
		printf("shmget error\n");
		exit(-1);
	}else{
		printf("client shmid=%d\n", shmid);
	}
	//挂载共享内存到进程中
	shm=shmat(shmid,(void*)0,0);
	if(shm==(void*)(-1))
	{
		printf("shmat error\n");
		exit(-1);
	}
	da=shm;
	while(1)
	{
		sleep(2);
		printf("temp=%.1f,humi=%.1f\n",da->data_t,
		da->data_rh );
	}
 
	return 0;
}

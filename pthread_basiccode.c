#include<stdio.h>
#include<pthread.h>

    int x=5;
    int id[5];
    int array[10]={1,2,3,4,5,6,7,8,9,0};
    int j;
    int p_rval;
    int lock;
    pthread_mutex_t mp;
    int ret;
    int mret;
    int parsum;
	int finalsum=0;
/* wait on condition variable */
struct ThreadVar{

	 pthread_cond_t cv;
	int i;
	
}t_var;

void *addArray(void *arg)
{
	parsum=parsum+array[t_var.i]+array[t_var.i+1];
	pthread_cond_signal(&t_var.cv);

}
int process_thread(int n)
{
    for(t_var.i=0,j=0;j<n;t_var.i=t_var.i+2,j++)
    {  
	
        if(0==pthread_create(&id[j],NULL,addArray,&t_var))
        {
	pthread_cond_wait(&t_var.cv,&mp);
        }
        else
        printf("Error in thread",t_var.i);
    }
		
	pthread_join(id[0],NULL);
	pthread
	printf("Sum is %d\n",parsum);
    return 0;   
}


int main()
{
	//sum=0;
	ret=pthread_cond_init(&(t_var.cv),NULL);
	mret=pthread_mutex_init(&mp,NULL);
	process_thread(5);
	
	
}

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

sem_t mutex, write_block;
int data = 0, rcount = 0;

void *readerX(void *arg)
{
  sem_wait(&mutex);
  rcount++;
  if(rcount == 1)
    sem_wait(&write_block);
  sem_post(&mutex);
  printf("Data: %d\n", data);
  sem_wait(&mutex);
  rcount--;
  if(rcount == 0)
    sem_post(&write_block);
  sem_post(&mutex);
  return 0;
}

void *writerZ(void *arg)
{
  sem_wait(&write_block);
  data++;
  printf("Written: %d\n", data);
  sem_post(&write_block);
  return 0;
}

int main()
{
  pthread_t *readers, *writers;
  readers = (pthread_t *)malloc(sizeof(pthread_t) * 5);
  writers = (pthread_t *)malloc(sizeof(pthread_t) * 5);
  
  sem_init(&mutex, 0, 1);
  sem_init(&write_block, 0, 1);

  for(int i = 0; i < 5; i++)
  {
    pthread_create(&readers[i], NULL, &readerX, NULL);
    pthread_create(&writers[i], NULL, &writerZ, NULL);
  }

  for(int i = 0; i < 5; i++)
  {
    pthread_join(readers[i], NULL);
    pthread_join(writers[i], NULL);
  }

  return 0;
}

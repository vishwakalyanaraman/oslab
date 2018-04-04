#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 5

void print(int a[N][M])
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}

void print_1d(int a[M])
{
  for(int i = 0; i < M; i++)
    printf("%d ", a[i]);
  printf("\n");  
}

int deadlock_detection(int available[M], int allocation[N][M], int request[N][M])
{
    
  int work[M], finish[N], safe_q[N];
  int x = 0;

  for(int i = 0; i < M; i++)
    work[i] = available[i];
    
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    	if(allocation[i][j] != 0)
    	{
    		finish[i] = 0;
    		break;
    	}
    finish[i] = 1;
  }
    
  int flag = 0, p_count = 0;
    
  for(int k = 0; k < N; k++)
  {  
    for(int i = 0; i < N; i++)
    {
      if(finish[i] == 0)
      {
        flag = 0;
        for(int j = 0; j < M; j++)
          if(work[j] < request[i][j])
            flag = 1;

        if(flag == 0)
        {
          for(int j = 0; j < M; j++)
            work[j] += allocation[i][j];

          finish[i] = 1;
          p_count++;
          //add process to safe seq
          safe_q[x++] = i;
        }
      }
    }
    if(p_count == N)
    {
      printf("Safe sequence: ");
      for(int l = 0; l < N; l++)
      	printf("%d ", safe_q[l]);
      printf("\n");
      return 1;
    }
  }
  return 0;
}


int main()
{
  int available[M],
      request[N][M],
      allocation[N][M];

  printf("Enter available matrix:\n");
  for(int i = 0; i < M; i++)
    scanf("%d", &available[i]);

  printf("Enter allocation matrix:\n");
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      scanf("%d", &allocation[i][j]);

  printf("Enter request matrix:\n");
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) 
      scanf("%d", &request[i][j]);


  deadlock_detection(available, allocation, request);
  /*
  printf("\n\n After request:\n\n");
  printf("Available matrix:\n");
  print_1d(available);
  printf("Allocation matrix: \n");
  print(allocation);
  printf("Request matrix: \n");
  print(request);
  */
  return 0;
}

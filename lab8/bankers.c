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

int check_safety(int need[N][M], int available[M], int allocation[N][M])
{
    
  int work[M], finish[N], safe_q[N];
  int x = 0;

  for(int i = 0; i < M; i++)
    work[i] = available[i];
    
  for(int i = 0; i < N; i++)
    finish[i] = 0;
    
  int flag = 0, p_count = 0;
    
  for(int k = 0; k < N; k++)
  {  
    for(int i = 0; i < N; i++)
    {
      if(finish[i] == 0)
      {
        flag = 0;
        for(int j = 0; j < M; j++)
          if(work[j] < need[i][j])
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

int res_request(int need[N][M], int available[M], int allocation[N][M], int request[M], int p_id)
{
  for(int i = 0; i < M; i++)
    if(request[i]  > need[p_id][i])
    {
      printf("Request greater than need. Exiting\n");
      return -1;
    }

  for(int i = 0; i < M; i++)
    if(request[i] > available[i])
    {
      printf("Request greater than available. Exiting\n");
      return -1;
    }

  for(int i = 0; i < M; i++)
  {
    available[i] -= request[i];
    allocation[p_id][i] += request[i];
    need[p_id][i] -= request[i];
  }
  
  if(check_safety(need, available, allocation))
  {
    printf("Resource allocated\n");
    return 1;
  }
  else 
  {
    for(int i = 0; i < M; i++)
    {
      available[i] += request[i];
      allocation[p_id][i] -= request[i];
      need[p_id][i] += request[i];
    }
    printf("Can't allocate. Reverting changes\n");
    return 0;
  }
}

int main()
{
  int need[N][M],
      available[M],
      request[M],
      allocation[N][M],
      max[N][M];
  int p_id;

  printf("Enter available matrix:\n");
  for(int i = 0; i < M; i++)
    scanf("%d", &available[i]);

  printf("Enter allocation matrix:\n");
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      scanf("%d", &allocation[i][j]);

  printf("Enter max matrix:\n");
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
    { 
      scanf("%d", &max[i][j]);
      need[i][j] = max[i][j] - allocation[i][j];
    }

  printf("Enter process requesting resources: ");
  scanf("%d", &p_id);

  printf("Enter request matrix: ");
  for(int i = 0; i < M; i++)
    scanf("%d", &request[i]);

  res_request(need, available, allocation, request, p_id);
  printf("\n\n After request:\n\n");
  printf("Need matrix:\n");
  print(need);
  printf("Available matrix: \n");
  print_1d(available);
  printf("Allocation matrix: \n");
  print(allocation);
  return 0;
}

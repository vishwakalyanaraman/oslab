#include <stdio.h>
#include <stdlib.h>

#define MAX 50
//firstfit
typedef struct 
{
  int nh;
  int hole_size[MAX];
}holes;

typedef struct
{
  int np;
  int proc_size[MAX];
  int hole_alloc[MAX];
}procs;

void first_fit(holes *h, procs *p);

int main()
{
  holes h;
  procs p;

  printf("Enter no of holes, no of processes: ");
  scanf("%d %d", &h.nh, &p.np);
  
  printf("Enter hole size:\n");
  for(int i = 0; i < h.nh; i++)
    scanf("%d", &h.hole_size[i]);

  printf("Enter process size:\n");
  for(int i = 0; i < p.np; i++)
    scanf("%d", &p.proc_size[i]);

  for(int i = 0; i < p.np; i++)
    p.hole_alloc[i] = -1;
         
  first_fit(&h, &p);

  printf("Hole status(memory left):\n");
  for(int i = 0; i < h.nh; i++)
    printf("%d ", h.hole_size[i]);

  printf("\nProcess status(hole index allocated):\n");
  for(int i = 0; i < p.np; i++)
    printf("%d ", p.hole_alloc[i]);

  printf("\n");

  return 0;
}

void first_fit(holes *h, procs *p)
{
  for(int i = 0; i < p->np; i++)
  {
    for(int j = 0; j < h->nh; j++)
     if(h->hole_size[j] >= p->proc_size[i])
     {
       p->hole_alloc[i] = j;
       h->hole_size[j] -= p->proc_size[i];
       break;
     }
  }
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void sort_holes(holes *h);
int search_elem(int, holes);
void best_fit(holes *h, procs *p);

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

  best_fit(&h, &p);

  printf("Hole status(memory left):\n");
  for(int i = 0; i < h.nh; i++)
    printf("%d ", h.hole_size[i]);

  printf("\nProcess status(hole index allocated):\n");
  for(int i = 0; i < p.np; i++)
    printf("%d ", p.hole_alloc[i]);

  printf("\n");

  return 0;
}

void best_fit(holes *h, procs *p)
{
  for(int i = 0; i < p->np; i++)
  {
    holes *h_temp = h;
    sort_holes(h_temp);
    for(int j = 0; j < h_temp->nh; j++)
    {
      if(h_temp->hole_size[j] >= p->proc_size[i])
      {
        int k = search_elem(h_temp->hole_size[j], *h);
        p->hole_alloc[i] = k;
        h->hole_size[k] -= p->proc_size[i];
        break;
      }
    }
  }

}

void sort_holes(holes *h)
{
  int c = 0;
  for(int i = 0; i < h->nh - 1; i++)
  {
    c = 0;
    for(int j = 0; j < h->nh - i - 1; j++)
    {
      if(h->hole_size[j] >= h->hole_size[j+1])
      {
        int temp = h->hole_size[j];
        h->hole_size[j] = h->hole_size[j + 1];
        h->hole_size[j + 1] = temp;
        c = 1;
      }
    }
    if(c == 0)
      return;
  }

}

int search_elem(int x, holes h)
{
  for(int i = 0; i < h.nh; i++)
    if(x == h.hole_size[i])
      return i;
  return -1;
}

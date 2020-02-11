#include<stdio.h>
#include<stdlib.h>

FILE *fp;

struct node{
  int v_weight;
  int dest;
  int deg;
  struct node *next;
};

int main (void)
{
      struct node *new;
      int vertices, source, dest, weight;
      fp = fopen("adjacencylist.txt", "r");
      if (fp!=NULL)
      {
                fscanf(fp, "%d ", &vertices);  
                initialise (graph, vertices);
                while(!feof(fp))
                {
                        fscanf(fp, "%d %d %d ", &source, &dest, &weight);
                        new = (struct node *)malloc(sizeof(struct node));
                        new->dest = dest;
                        new->v_weight = weight;
                        new->next = graph[source].next;
                        graph[source].next = new;
                        graph[source].deg++;
                }
      }     
}

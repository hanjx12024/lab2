#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(void)
{
  Queue *queue = malloc(sizeof(Queue));
  if(!queue){
    printf("create fail");
    return NULL;
  }

  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  double* temp = malloc(sizeof(double) * queue->capacity);
  if (!temp) {
    free(queue);
    printf("create fail");
    return NULL;
  }
  queue->data = temp;
  return queue;
}

void push(Queue *queue, double element)
{
  if(!queue) {
    printf("Invalid queue");
    return;
  }
  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;

    double* temp = realloc(queue->data, sizeof(double) * capacity);
    if(!temp){
      printf("create fail");
      return;
    }
    queue->data = temp;

    queue->capacity = capacity;
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}

double back(Queue *queue)
{
  if(!queue) {
    printf("invalid queue");
    return 0.0;
  }
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{
  if(!queue) return;
  if(queue -> data)free(queue->data);
  free(queue);
}


#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

t_queue* create_queue(int max) {
    if (max <= 0) {
        return NULL;
    }

    t_queue *queue = malloc(sizeof(t_queue));

    if (queue == NULL) {
        return NULL;
    }

    queue->items = malloc(sizeof(int) * max);

    if (queue->items == NULL) {
        return NULL;
    }

    queue->end = -1;
    queue->size = 0;
    queue->max = max;

    return queue;
}

void destroy(t_queue *queue) {
    if (queue == NULL) {
        return;
    }

    free(queue->items);
    free(queue);
}

int is_empty(t_queue *queue) {
    return queue == NULL || queue->size == 0;
}

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

    queue->begin = 0;
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

int is_full(t_queue *queue) {
    return queue == NULL || queue->size == queue->max;
}

int size(t_queue *queue) {
    return queue == NULL ? 0 : queue->size;
}

int in(t_queue *queue, int elem) {
    if (is_full(queue)) {
        return 0;
    }

    queue->end = (queue->end + 1) % queue->max;
    queue->items[queue->end] = elem;
    queue->size++;

    return 1;
}

int out(t_queue *queue, int *elem) {
    if (is_empty(queue) || elem == NULL) {
        return 0;
    }

    if (queue->size == 1) {
        *elem = queue->items[queue->end--];
    } else {
        *elem = queue->items[queue->begin++];
    }

    queue->size--;
    return 1;
}

void print_queue(t_queue *queue) {
    if (is_empty(queue)) {
        printf("The queue is empty\n");
        return;
    }

    if (queue->size == 1) {
        printf("begin -> %d <- end\n", queue->items[queue->begin]);
        return;
    }

    int start = queue->begin;

    while (start != queue->end) {
        if (start == queue->begin) {
            printf("%d <- begin\n", queue->items[start]);
        } else {
            printf("%d\n", queue->items[start]);
        }

        start = (start + 1) % queue->max;
    }

    printf("%d <- end\n", queue->items[queue->end]);
}

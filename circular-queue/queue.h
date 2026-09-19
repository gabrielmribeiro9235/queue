#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int max;
    int begin;
    int end;
    int size;
    int *items;
} t_queue;

t_queue* create_queue(int);
void destroy(t_queue*);
int is_empty(t_queue*);
int is_full(t_queue*);
int size(t_queue*);
int in(t_queue*, int);
int out(t_queue*, int*);
void print_queue(t_queue*);

#endif
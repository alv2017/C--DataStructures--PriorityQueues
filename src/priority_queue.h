#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Node
struct node {
	int data;
	long priority;
	struct node *next;
};

struct pqueue {
	struct node *first;
	struct node *last;
};

struct pqueue pque;

// Operation status
short op_status;

// Initialize an empty queue
struct pqueue *pqueue_init(struct pqueue *pq);

// Display priority queue
void display_queue(struct pqueue *);

// Insert new element into priority queue
struct pqueue *pqueue_insert(struct pqueue *, int, long, short *);

// Remove element into priority queue
int pqueue_remove(struct pqueue *, short *);

// Return the first priority element
int pqueue_first(struct pqueue *, short *);

// Find node by value in the priority queue
struct node *pqueue_find(struct pqueue *, int, short *);

#endif




#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

// Initialize empty priority queue
struct pqueue *pqueue_init(struct pqueue *pq) {
	pq->first = NULL;
	pq->last = NULL;
	return pq;
}

// Display priority queue
void display_queue(struct pqueue *pq) {
	if (pq->first == NULL) {
		puts("The queue is empty.\n");
		return;
	}
	long cnt = 1;
	struct node *ptr = pq->first;
	while (ptr != NULL) {
		printf("Queue: %ld, priority: %ld, value: %d.\n", cnt, ptr->priority, ptr->data);
		ptr = ptr->next;
		cnt++;
	}
	printf("\nThe number of elements in the queue is %ld.\n", cnt-1);
}

// Insert new element
struct pqueue *pqueue_insert(struct pqueue *pq, int value, long priority, short *op_status) {
	*op_status = 0;
	struct node *new_node, *current, *previous;
	previous = NULL;
	current = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("Unable to insert a new node. Memory allocation failure.\n");
		free(new_node);
		return pq;
	}
	*op_status = 1;
	new_node->data = value;
	new_node->priority = priority;
	new_node->next = NULL;

	// Priority queue is empty
	if (pq->first == NULL) {
		pq->first = new_node;
		pq->last = new_node;
		return pq;
	}
	current = pq->first;
	while(current != NULL) {
		if ( new_node->priority >= current->priority) {
			previous = current;
			current = current->next;
		} else {
			break;
		}
	}
	if (previous == NULL) {
		pq->first = new_node;
	} else {
		previous->next = new_node;
	}

	new_node->next = current;

	if (current == NULL) {
		pq->last = new_node;
	}
	return pq;
}

// Remove element
int pqueue_remove(struct pqueue *pq, short *op_status) {
	*op_status = 0;
	int val = 0;

	// Priority queue is empty
	if (pq->first == NULL) {
		printf("The priority queue is empty. There is nothing to remove.\n");
		return val;
	}

	*op_status = 1;
	struct node *ptr;
	ptr = pq->first;
	val = ptr->data;

	// Priority queue has just one element
	if (pq->first == pq->last) {
		pq->first = NULL;
		pq->last = NULL;
	}  else {
		pq->first = (pq->first)->next;
	}

	free(ptr);
	return val;
}

// Return the value of the top element (by priority)
int pqueue_first(struct pqueue *pq, short *op_status) {
	*op_status = 0;
	int val = 0;

	// Priority queue is empty
	if (pq->first == NULL) {
		printf("The priority queue is empty.");
		return val;
	}
	*op_status = 1;
	val = (pq->first)->data;
	return val;
}

// Find element by value
struct node *pqueue_find(struct pqueue *pq, int val, short *op_status) {
	*op_status = 0;
	struct node *pnode;
	pnode = NULL;

	// Priority queue is empty
	if (pq->first == NULL) {
		puts("The priority queue is empty. There is no node matchning your criteria.");
		return NULL;
	}

	pnode = pq->first;

	while (pnode != NULL) {
		if (pnode->data == val) {
			*op_status = 1;
			return pnode;
		}
		pnode = pnode->next;
	}
	puts("There is no node matching your criteria.");
	return NULL;
}









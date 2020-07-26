#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/priority_queue.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Insert element.",
		" 2. Remove element.",
		" 3. Return value of the first element by priority.",
		" 4. Find by value.",
		" 5. Display priority queue.",
		" 6. Exit the program",
		NULL
};

int main(void) {
	op_status = 0;
	struct pqueue *pqptr = pqueue_init(&pque);

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);

	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				puts("Inserting a new_element.");
				printf("%s","Enter element's value: ");
				int new_value = enter_value(&op_status);
				printf("%s", "Enter element's priority: ");
				int new_priority = enter_value(&op_status);

				pqptr = pqueue_insert(pqptr, new_value, new_priority, &op_status);
				if (op_status == 1) {
					printf("New element has been inserted successfully.\n");
				}
				break;

			case 2:
				clear();
				printf("Removing an element.\n");
				int removed_item = pqueue_remove(pqptr, &op_status);
				if (op_status == 1) {
					printf("Element has been removed. The element's value is %d.\n", removed_item);
				}
				break;

			case 3:
				clear();
				printf("Returning value of the first element in the priority queue.\n");
				int first = pqueue_first(pqptr, &op_status);
				if (op_status == 1) {
					printf("The first priority element value is %d.\n", first);
				}
				break;

			case 4:
				clear();
				printf("Finding element by value.\n");
				printf("Enter the node's value: ");
				int node_value = enter_value(&op_status);
				printf("We are looking for the node having value %d.\n", node_value);
				struct node *found_node = pqueue_find(pqptr, node_value, &op_status);
				if (found_node != NULL) {
					printf("Node having value %d was found at address %p\n", found_node->data, found_node);
					printf("The priority of the node is %ld.\n", found_node->priority);
				}
				break;

			case 5:
				clear();
				printf("Displaying a priority queue.\n");
				display_queue(pqptr);
				break;

			case 6:
				clear();
				// Delete queue before exiting
				struct node *p = NULL;
				while (pqptr->first != NULL) {
					p = pqptr->first;
					pqptr->first = (pqptr->first)->next;
					free(p);
				}
				pqptr->last= NULL;
				printf("Exiting the program\n");
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}

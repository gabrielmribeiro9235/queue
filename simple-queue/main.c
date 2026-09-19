#include<stdio.h>
#include"queue.h"

void menu() {
    printf("-----------------------------------------------\n");
    printf("Select a function:\n");
    printf("1 - print_queue\n");
    printf("2 - in\n");
    printf("3 - out\n");
    printf("4 - is_empy\n");
    printf("5 - is_full\n");
    printf("6 - size\n");
    printf("7 - exit\n");
    printf("-----------------------------------------------\n");
    printf("Your choice: ");
}

int main() {
    int queue_size;

    printf("Enter the maximum initial queue size: ");
    scanf("%d", &queue_size);

    t_queue *queue = create_queue(queue_size);

    if (queue == NULL) {
        return 1;
    }

    int opt = 0;
    do {
        menu();
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("-----------------------------------------------\n");
                print_queue(queue);
                break;
            case 2: {
                printf("-----------------------------------------------\n");

                int elem;

                printf("Enter the element you want to insert: ");
                scanf("%d", &elem);

                int in_status = in(queue, elem);

                if (in_status == 1) {
                    printf("\n%d inserted successfully\n", elem);
                } else {
                    printf("\nFailed to insert\n");
                }

                break;
            }
            case 3: {
                printf("-----------------------------------------------\n");
                int popped_value;

                int out_status = out(queue, &popped_value);

                if (out_status == 1) {
                    printf("Popped value: %d\n", popped_value);
                } else {
                    printf("Failed to pop\n");
                }

                break;
            }
            case 4:
                printf("-----------------------------------------------\n");

                if (is_empty(queue)) {
                    printf("The queue is empty\n");
                } else {
                    printf("The queue is not empty\n");
                }

                break;
            case 5:
                printf("-----------------------------------------------\n");

                if (is_full(queue)) {
                    printf("The queue is full\n");
                } else {
                    printf("The queue is not full\n");
                }

                break;
            case 6:
                printf("-----------------------------------------------\n");

                printf("Queue size: %d\n", size(queue));

                break;
            default:
                printf("-----------------------------------------------\n");
                printf("Invalid choice\n");
                break;
        }
    } while (opt != 7);

    return 0;
}

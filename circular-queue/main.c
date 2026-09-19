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

    printf("-----------------------------------------------\n");

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
            default:
                printf("-----------------------------------------------\n");
                printf("Invalid choice\n");
                break;
        }

    } while (opt != 7);


    return 0;
}

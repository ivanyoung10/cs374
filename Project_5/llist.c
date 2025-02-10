#include "llist.h"

int main(int argc, char *argv[])
{
    struct node *head = NULL;

    

    if (argc == 1){
        printf("[empty]\n");
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "ih") == 0) {
                int head_value = atoi(argv[i+1]);
                struct node *hp = node_alloc(head_value);
                llist_insert_head(&head, hp);
            }
            else if (strcmp(argv[i], "it") == 0) {
                int tail_value = atoi(argv[i+1]);
                struct node *tp = node_alloc(tail_value);
                llist_insert_tail(&head, tp);
            }
            else if (strcmp(argv[i], "dh") == 0){
                if (head == NULL){
                    continue;
                }
                else {
                    llist_delete_head(&head);
                }
            }
            else if (strcmp(argv[i], "f") == 0) {
                llist_free(&head);
            }
            else if (strcmp(argv[i], "p") == 0){
                llist_print(head);
            }
            else {
                continue;
            }
        }

    }

    llist_free(&head);
    
}

void llist_insert_head(struct node **head, struct node *n)
{
    if (n == NULL){
        perror("N is Null");
        exit(1);
    }

    // if(head == NULL){
    //     n->next = head;
    // }

    n->next = *head;
    *head = n;
}

struct node *llist_delete_head(struct node **head)
{   
    struct node *old_head = *head;
    *head = (*head) -> next;

    return old_head;


}

void llist_insert_tail(struct node **head, struct node *n)
{
    if (n == NULL) {
        perror("N is null");
        exit(2);
    }

    if(*head == NULL){
        *head = n;
        return;
    }

    llist_insert_tail(&((*head)->next), (n));
}

void llist_print(struct node *head)
{  
    if (head == NULL){
        printf("[empty]\n");
        return;
    }

    while (head->next != NULL){
        printf("%d -> ", head->value);
        return llist_print(head->next);
    }

    if (head->next == NULL) {
        printf("%d\n", head->value);
        return;
    }
}

void llist_free(struct node **head)
{
    if ((*head) == NULL){
        return;
    }

    llist_free(&((*head)->next));
    node_free(*head);
    *head = NULL;

    
}

struct node *node_alloc(int value)
{
    struct node *p = malloc(sizeof(struct node));
    p->value = value;
    p->next = NULL;
    return p;
}

void node_free(struct node *n)
{
    free(n);
}
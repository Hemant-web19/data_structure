#include <stdio.h>
#include <stdlib.h>  

struct box {
    int data;
    struct box* next;
} *p, *q, *r, *s, *t;

void transversal(struct box* ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);  
        ptr = ptr->next;
    }
}

void create(struct box* ptr) {
    int b;
    printf("Enter node value: ");
    scanf("%d", &ptr->data);
    printf("Enter 1 to create next node or 0 to stop: ");
    scanf("%d", &b);
    if (b == 0) {
        ptr->next = NULL;
    } else if (b == 1) {
        s = (struct box*)malloc(sizeof(struct box));
        ptr->next = s;
        create(s);  
    } else {
        printf("Incorrect input\n");
        ptr->next = NULL; 
    }
}

void insert(struct box** t) {  
    int num, num1, b;
    struct box* p;
    printf("Enter 1 for inserting at beginning, 2 before a specific value, 3 at end: ");
    scanf("%d", &b);

    printf("Enter the new element in node: ");
    scanf("%d", &num);
    if (b == 1) {  
        p = (struct box*)malloc(sizeof(struct box));
        p->data = num;
        p->next = *t;
        *t = p;  
    } else if (b == 2) {  
        printf("Enter the element before which you want to add the new element: ");
        scanf("%d", &num1);

        if ((*t)->data == num1) {  
            p = (struct box*)malloc(sizeof(struct box));
            p->data = num;
            p->next = *t;
            *t = p;
            return;
        }

        struct box* prev = NULL;
        struct box* current = *t;
        while (current != NULL && current->data != num1) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {  
            p = (struct box*)malloc(sizeof(struct box));
            p->data = num;
            p->next = current;
            if (prev != NULL) {
                prev->next = p;
            }
        } else {
            printf("Element %d not found in the list.\n", num1);
        }
    } else if (b == 3) {  
        struct box* current = *t;
        while (current->next != NULL) {
            current = current->next;
        }
        p = (struct box*)malloc(sizeof(struct box));
        p->data = num;
        p->next = NULL;
        current->next = p;
    }
}

void delete(struct box** t) {  
    int b, num1;
    struct box* p;
    printf("Enter 1 to delete first node, 2 for middle node, 3 for last node: ");
    scanf("%d", &b);

    if (b == 1) {  
        if (*t != NULL) {
            p = *t;
            *t = (*t)->next;
            free(p);
        }
    } else if (b == 2) {  
        printf("Enter the element you want to delete: ");
        scanf("%d", &num1);

        struct box* prev = NULL;
        struct box* current = *t;
        while (current != NULL && current->data != num1) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {  
            if (prev != NULL) {
                prev->next = current->next;
            }
            free(current);
        } else {
            printf("Element %d not found in the list.\n", num1);
        }
    } else if (b == 3) { 

        if ((*t)->next == NULL) {  
            free(*t);
            *t = NULL;
            return;
        }

        struct box* prev = NULL;
        struct box* current = *t;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        free(current);
    }
}

int main() {
    t = (struct box*)malloc(sizeof(struct box));

    create(t);
    transversal(t);

    insert(&t);  
    transversal(t);  

    delete(&t);  
    transversal(t);  

    return 0;
}

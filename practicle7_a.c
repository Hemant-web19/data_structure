#include<stdio.h>
#include<malloc.h>
struct node {
    int data ;
    struct node *next ;
}*p,*q,*first;
void create(){
    int value;
    printf("enter the value of node ");
    scanf("%d",&value);

    q  = (struct node* ) malloc (sizeof(struct node ) );
    p->next = q;
    q->data = value ;
    q->next = first ;
    p = q ;
  
}
void traverse( struct node *ptr ){
    
     if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *start = ptr;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}
void insert_beg(struct node *ptr){
    int value ;
    printf("Enter the node value :");
    scanf("%d", &value);
    q = (struct node*)malloc (sizeof(struct node));
    q->data = value ;
    q->next = first ;
    while(ptr->next != first  ){
        ptr = ptr->next ;
    }
    ptr->next= q;
    first = q;
}
void insert_end(struct node *ptr){
    int value ;
    while(ptr->next != first ){
        ptr=ptr->next;
    }
    q = (struct node *)malloc(sizeof(struct node ));
    printf("enter the node value");
    scanf("%d",&q->data);
    ptr->next = q ;
    q->next = first ;
}
void delete_beg(struct node *ptr){
    q = ptr->next ;
    
    while(ptr->next != first ){
        ptr = ptr->next ;
    }
    ptr->next = q;
    first = q ;
    free(ptr);

}
void delete_end(struct node *ptr ){
    while(ptr->next != first ){
        q = ptr ;
        ptr= ptr->next;
    }
    q->next = first  ;
    free(ptr);
    


}
int main (){
    int choose ;
    int button = 1;
    p = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first node :");
    scanf("%d",&p->data);
    p->next = NULL; 
    first = p;
    while (button){
        printf(" 1.create \n");
        printf(" 2.traverse\n");
        printf(" 3.insert at beginning  \n");
        printf(" 4.insert at end \n");
        printf(" 5.delete at beginning  \n");
        printf(" 6.delete at end\n");
        printf(" 7.Exit\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:{
                create();
                break;
            }
            case 2:{
                traverse(first);
                break;
            }
            case 3:{
                insert_beg(first );
                break;

            }
            case 4:{
                insert_end( first );
                break ;
            }
            case 5:{
                delete_beg(first );
                break;
            }
            case 6 :{
                delete_end(first );
                break;
            }
            case 7 :{
                button = 0;
                break ;

            }
            default:{
                printf("wrong input\n");
            }

        }
    }
}
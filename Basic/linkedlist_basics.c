#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Linkedlist{
    int data;
    struct Linkedlist *link;
};
typedef struct Linkedlist node;

node *start = NULL;
node *end =NULL;
int number_of_nodes=0;

void create_node(){
    node *temp;
    temp = (node *)malloc(sizeof(node));

    if(number_of_nodes==0){
    start = (node *)malloc(sizeof(node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->link =NULL;
    start->link = temp;
    end=start->link;
    number_of_nodes++;
    }

    else{
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->link =NULL;
    end->link = temp;
    end=end->link;
    }


}

void display(){
  node *show;
  show =start;
  printf("\nStart");
  while(show->link!=NULL){
    show=show->link;
    printf("----->%d",show->data);
  }
  printf("\n");
}

void pop(){
     printf("\nEnter element to be popped\n");
     int element,found=0;
     scanf("%d",&element);
     node *show =start;
     node *change =start;
     while(show->link!=NULL){
         change = show;
         show=show->link;
         if(show->data==element){
            change->link = show->link;
            free(show);
            found=1;
            printf("Element found\n");
            break;
         }
     }
     if(found==1)
     display();
     else
     printf("Element not found\n");
}

int main()
{
    int entry =0;
    while(entry !=4){
        printf("Enter your choice\n1.Create node\n2.Display Linkedlist\n3.Pop element\n4.Exit\n");
        scanf("%d",&entry);
        if(entry==1){create_node();}
        if(entry==2){display();}
        if(entry==3){pop();}
    }
    return 0;
}

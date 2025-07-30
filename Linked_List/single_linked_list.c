#include<stdio.h>
#include<stdlib.h>
struct SLL{
    int data;
    struct SLL *next;
};
struct SLL *first,*last=NULL;

void display(){
    struct SLL *temp;
    if(first==NULL)
        printf("List is empty\n");
    else{
        temp=first;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void insert_at_beginning(int element){
    struct SLL *NewNode;
    NewNode=(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data=element;
    NewNode->next=NULL;
    if(first==NULL){
        first=last=NewNode;
    }
    else{
        NewNode->next=first;
        first=NewNode;
    }
    printf("%d was inserted!\n",first->data);
}

void insert_at_end(int element){
    struct SLL *NewNode;
    NewNode=(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data=element;
    NewNode->next=NULL;
    if(first==NULL){
        first=last=NewNode;
    }
    else{
        last->next=NewNode;
        last=NewNode;
    }
    printf("%d was inserted!\n",last->data);
}

void insert_at_specific(int element,int pos){
    struct SLL *NewNode,*temp;
    int i;
    NewNode=(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data=element;
    NewNode->next=NULL;
    if(pos<=0){
        printf("Invalid position \n");
    }
    else if (pos==1 ||first==NULL){
        insert_at_beginning(element);
        free(NewNode); // Prevent memory leak
    }
    else{
        temp=first;
        for(i=1;(i<pos-1)&&(temp->next!=NULL);i++){
            temp=temp->next;
        }
        if(temp==last){
            insert_at_end(element);
            free(NewNode); // Prevent memory leak
        }
        else{
            NewNode->next=temp->next;
            temp->next=NewNode;
            printf("%d -> was inserted \n",NewNode->data);
        }
    }
}

void delete_from_beginning(){
    struct SLL *temp;
    if(first==NULL){
        printf("List is empty\n");
    }
    else if(first->next==NULL){
        temp=first;
        first=last=NULL;
        printf("%d is going to deleted\n",temp->data);
        free(temp);
    }
    else{
        temp=first;
        first=first->next;
        printf("%d was deleted\n",temp->data);
        free(temp);
    }
}

void delete_from_end(){
    struct SLL *temp;
    if(first==NULL){
        printf("List is empty\n");
    }
    else if(first->next==NULL){
        temp=first;
        first=last=NULL;
        printf("%d is going to be deleted\n",temp->data);
        free(temp);
    }
    else{
        temp=first;
        while(temp->next!=last){
            temp=temp->next;
        }
        struct SLL *toDelete = last;
        last=temp;
        last->next=NULL;
        printf("%d was deleted\n",toDelete->data);
        free(toDelete);
    }
}

void delete_from_specific(int pos){
    struct SLL *temp,*tempp;
    int i;
    if(pos<=0 || first==NULL){
        printf("Invalid deletion\n");
    }
    else if (pos==1){
        delete_from_beginning();
    }
    else{
        temp=first;
        for(i=1;(i<pos-1)&& (temp->next!=last);i++){
            temp=temp->next;
        }
        if(temp->next==last){
            delete_from_end();
        }
        else{
            tempp=temp->next;
            temp->next=tempp->next;
            printf("%d is deleted\n",tempp->data);
            free(tempp);
        }
    }
}

int main(){
    insert_at_beginning(20);
    insert_at_beginning(30);
    insert_at_beginning(40);
    insert_at_beginning(50);
    display();
    insert_at_end(60);
    insert_at_end(70);
    insert_at_end(80);
    display();
    insert_at_specific(15,2);
    display();
    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_from_specific(2);
    display();
}
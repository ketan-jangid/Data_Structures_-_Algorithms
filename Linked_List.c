#include <stdio.h>
#include <stdlib.h>

//defining the structure of node in list
struct node{
    int data;
    struct node* nxt;
};

//pointer to the head node
struct node * head = NULL;

//Functions to add node, delete node and display the list
void add();
void delete();
void display();
void add_begin(int);
void add_last(int);
void add_between(int, int);
void delete_begin();
void delete_end();
void delete_between(int);

int main()
{
    int choice;
    printf("\t*** Linked List Program ***\n");
    
    do{
        printf("1. Insert a node \n2. Delete a node \n3. Display the list \n99. Exit \n");
        printf("Enter your choice - ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: add();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 99:
                break;
            default:
                printf("Invalid Input \n");
        }
    }while(choice!=99);

    return 0;
}

//funtion to display insert options in the list
void add(){
    int choice;
    int x, pos;
    
    printf("1. Insert at beginning \n2. Insert at a position \n3. Insert at end \n99. Back \n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: 
            printf("Enter the key to add - ");
            scanf("%d", &x);
            add_begin(x);
            break;
        case 2: 
            printf("Enter the key to add and its position - ");
            scanf("%d %d", &x, &pos);
            add_between(x,pos);
            break;
        case 3: 
            printf("Enter the key to add - ");
            scanf("%d", &x);
            add_last(x);
            break;
        case 99:
            break;
        default:
            printf("Invalid Input \n");
    }
}

//function to display delete options
void delete(){
    int choice;
    int pos;
    
    printf("1. Delete from beginning \n2. Delete a position \n3. Delete from end \n99. Back \n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: 
            delete_begin();
            break;
        case 2: 
            printf("Enter the node you want to delete (position) - ");
            scanf("%d", &pos);
            delete_between(pos);
            break;
        case 3: 
            delete_end();
            break;
        case 99:
            break;
        default:
            printf("Invalid Input \n");
    }
}

//function to display the list
void display(){
    if(head==NULL){
        printf("List is empty \n");
    }else{
        struct node* ptr = head;
        
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->nxt;
        }
        printf("\n");
    }
}

//function to add a node to beginning of the list
void add_begin(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->nxt = head;
    head = temp;
    
    printf("Key added to the list \n");
}

//function to add a node in between the list
void add_between(int x, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    
    if(pos==1)
    	add_begin(x);
    
    struct node* ptr = head;
    int i=0;
    for(i=0; i<pos-2; i++){
        if(ptr==NULL){
            printf("Invalid Position \n");
            free(temp);
            return;
        }
        ptr = ptr->nxt;
    }
    
    temp->nxt = ptr->nxt;
    ptr->nxt = temp;
    
    printf("Key added to the list \n");
}

//function to add a node to the last of the list
void add_last(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->nxt = NULL;
    
    if(head==NULL){
    	head = temp;	
	}else{
		struct node* ptr = head;
    	while(ptr->nxt!=NULL){
        	ptr = ptr->nxt;
    	}
    	ptr->nxt = temp;
	}
    
    printf("Key added to the list \n");
}

//function to delete a node from the beginning of a list
void delete_begin(){
    if(head==NULL){
        printf("List is empty \n");
        return;
    }
    struct node* temp = head;
    head = temp->nxt;
    free(temp);
    
    printf("Key deleted from the list \n");
}

//function to delete a node from between of the list
void delete_between(int pos){
    if(head==NULL){
        printf("List is Empty \n");
        return;
    }
    if(pos==1)
    	delete_begin();
    	
    struct node* temp = head;
    struct node* ptr;
    int i;
    for(i=0; i<pos-1; i++){
        ptr = temp;
        temp = temp->nxt;
    }
    
    ptr->nxt = temp->nxt;
    free(temp);
    
    printf("Key deleted from the list \n");
}

//function to delete the last node of the list
void delete_end(){
    if(head==NULL){
        printf("List is empty \n");
        return;
    }
    struct node* temp = head;
    struct node* ptr = head;
    while(temp->nxt!=NULL){
        ptr = temp;
        temp = temp->nxt;
    }
    ptr->nxt = NULL;
    free(temp);
    
    printf("Key deleted from the list \n");
}





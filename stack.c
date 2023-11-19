#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 200

struct Node {
    char message[max_len];
    struct Node *next;
}; 
typedef struct Node node;

node *top = NULL;

void push(char message[]) {
    node *new_message = (node*)(malloc(sizeof(node)));
    if (top == NULL) 
        printf("stack is empty\n");
    else {
        strcpy(new_message->message, message);
        new_message->next = top;
        top = new_message;
        printf("Your message added successfully.\n");
    }
}

void pop() {
    if (top == NULL)  
        printf("stack is empty\n");
    else {
        node *temp = top;
        top = top->next; 
        free(temp);
    }
}

void display() {
    node *temp = top;
    if (temp == NULL) {
        printf("stack is empty\n");
    }
    else{
        while (temp != NULL) {
            printf("%s\n", temp->message);
            temp = temp->next;
            }
    }
}


int main(){
    int select;

    decision:
    printf("Please select a number (1, 2, 3, 4): \n");
    printf("1) Add a message\n2) delete a message\n3) Display messages\n4) Close app\nYour select: ");
    
    scanf("%d", &select);

    switch(select){
        case 1:
            char message[max_len];
            printf("Enter your message:\n");
            scanf("%s", message);
            push(message);
            printf("Message is added successfully.\n");
            goto decision;
            break;

        case 2:
            pop();
            printf("Last message is delete\n");
            break;

        case 3:
            printf("**********messages**********\n");
            display();
            break;

        case 4:
            printf("closing message app...");
            return 0;

        default :
            printf("your selecting is undefined");
    }
    return 0;
}

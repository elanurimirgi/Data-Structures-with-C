#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_NAME 20
#define LENGTH_PHONE 11
#define LENGTH_EMAIL 40

struct Node {
    char name[LENGTH_NAME];
    char surname[LENGTH_NAME];
    char phone_number[LENGTH_PHONE];
    char email[LENGTH_EMAIL];
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;

node *first_user = NULL;

node *new_person(char name[], char sname[], char pnum[], char email[]) {
    node *person = (node *)malloc(sizeof(node));
    strcpy(person->name, name);
    strcpy(person->surname, sname);
    strcpy(person->phone_number, pnum);
    strcpy(person->email, email);
    person->next = NULL;
    person->prev = NULL;
    return person;
}

int is_valid_email(const char *email) {
    // Bu basit bir email doğrulama örneğidir. Gerçek bir uygulamada daha kapsamlı bir kontrol yapmalısınız.
    // Bu örnek, "@" işaretini içerip içermediğini kontrol eder.
    return strchr(email, '@') != NULL;
}

void add_person(char name[], char sname[], char pnum[], char email[]) {
    while (!is_valid_email(email)) {
        printf("Invalid email. Please enter a valid email: ");
        scanf("%s", email);
    }

    node *person = new_person(name, sname, pnum, email);
    if (first_user == NULL)
        first_user = person;
    else {
        node *temp = first_user;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = person;
        person->prev = temp;
    }
}

void display_person() {
    if (first_user == NULL)
        printf("There is no person to display\n");
    else {
        node *temp = first_user;
        do {
            printf("Name: %s\nSurname: %s\nPhone number: %s\nEmail: %s\n", temp->name, temp->surname, temp->phone_number, temp->email);
            temp = temp->next;
        } while (temp != NULL);
    }
}

void delete_person(int del_person_num) {
    int count = 0;
    node *temp = first_user;
    while (temp != NULL) {
        if (count != del_person_num) {
            temp = temp->next;
            count++;
        } else {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            
            free(temp);
            return;
        }
    }
}

void search_person(int search_person_num) {
    int count = 0;
    node *temp = first_user;
    while (temp != NULL) {
        if (count != search_person_num) {
            temp = temp->next;
            count++;
        } else {
            printf("**************Wanted Person**************\n");
            printf("Name: %s\nSurname: %s\nPhone number: %s\nEmail: %s\n", temp->name, temp->surname, temp->phone_number, temp->email);
            return;
        }
    }
}


int main() {
    int select;
    int num_node;
    decision:
    printf("Please select a number (1, 2, 3, 4, 5): \n");
    printf("1) Add a person in phone book\n2) Search a person in phone book\n3) Delete a person in phone book\n4) Display people in a phone book\n5) Close app\nYour select: ");
    
    scanf("%d", &select);

    switch (select) {
        case 1:
            printf("Enter person details:\n");
            char name[LENGTH_NAME], surname[LENGTH_NAME], phone[LENGTH_PHONE], email[LENGTH_EMAIL];
            printf("Name: ");
            scanf("%s", name);
            printf("Surname: ");
            scanf("%s", surname);
            printf("Phone: ");
            scanf("%s", phone);
            
            do {
                printf("Email: ");
                scanf("%s", email);
                if (!is_valid_email(email)) {
                    printf("Invalid email. Please enter a valid email.\n");
                }
            } while (!is_valid_email(email));

            add_person(name, surname, phone, email);
            printf("Person is added successfully.\n");
            goto decision;
            break;

        case 2:
            printf("which contact number do you want to search: ");
            scanf("%d", &num_node);
            search_person(num_node);
            goto decision;
            break;

        case 3:
            printf("which contact number do you want to delete: ");
            scanf("%d", &num_node);
            delete_person(num_node);
            goto decision;
            break;

        case 4:
            printf("The people in the phone book:\n");
            display_person();
            
            break;

        case 5:
            printf("closing phone book...");
            return -1;

        default :
            printf("your selecting is undefined");
    };

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[20];
    long int ph_no;
    struct contact *next;
};

struct contact *head = NULL;
struct contact *temp;

void insertion_at_beg(char name[], long int ph_no) {
    struct contact *newcontact =
        (struct contact *)malloc(sizeof(struct contact));

    if (newcontact == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newcontact->name, name);
    newcontact->ph_no = ph_no;

    newcontact->next = head;
    head = newcontact;

    printf("Contact inserted successfully!\n");
}

void insertion_at_end(char name[], long int ph_no) {
    struct contact *newcontact =
        (struct contact *)malloc(sizeof(struct contact));

    if (newcontact == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newcontact->name, name);
    newcontact->ph_no = ph_no;
    newcontact->next = NULL;

    if (head == NULL) {
        head = newcontact;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newcontact;
    }

    printf("Contact inserted successfully!\n");
}

void del_a_contact(char name[], long int ph_no) {
    struct contact *prev = NULL;
    temp = head;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Contact deleted successfully!\n");
}

void search_a_contact(char name[], long int ph_no) {
    int found = 0;
    temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s | Phone no: %ld\n",
                   temp->name, temp->ph_no);
            found = 1;
        }

        temp = temp->next;
    }

    if (found == 0) {
        printf("Contact not found!\n");
    }
}

void display_contacts() {
    temp = head;

    if (temp == NULL) {
        printf("Contact list is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("Name: %s | Phone no: %ld\n",
               temp->name, temp->ph_no);

        temp = temp->next;
    }
}

void free_contacts() {
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    char name[20];
    long int ph_no;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Insert a new contact at the beginning\n");
        printf("2. Insert a new contact at the end\n");
        printf("3. Delete a contact (using name)\n");
        printf("4. Search a contact in the list\n");
        printf("5. Display all contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter name of new contact: ");
            scanf("%19s", name);

            printf("Enter phone number of the new contact: ");
            scanf("%ld", &ph_no);

            insertion_at_beg(name, ph_no);
            break;

        case 2:
            printf("Enter name of new contact: ");
            scanf("%19s", name);

            printf("Enter phone number of the new contact: ");
            scanf("%ld", &ph_no);

            insertion_at_end(name, ph_no);
            break;

        case 3:
            printf("Enter name of contact to delete: ");
            scanf("%19s", name);

            del_a_contact(name, 0);
            break;

        case 4:
            printf("Enter name of contact to search: ");
            scanf("%19s", name);

            search_a_contact(name, 0);
            break;

        case 5:
            display_contacts();
            break;

        case 6:
            printf("Exiting...\n");
            free_contacts();
            break;

        default:
            printf("Enter a valid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

/*
=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 1
Enter name of new contact: abc
Enter phone number of the new contact: 4566584356
Contact inserted successfully!

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 1
Enter name of new contact: xyz
Enter phone number of the new contact: 1234567890
Contact inserted successfully!

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 2
Enter name of new contact: qrs
Enter phone number of the new contact: 4567891238
Contact inserted successfully!

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 5
Name: xyz | Phone no: 1234567890
Name: abc | Phone no: 4566584356
Name: qrs | Phone no: 4567891238

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 4
Enter name of contact to search: qrs
Name: qrs | Phone no: 4567891238

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 3
Enter name of contact to delete: xyz
Contact deleted successfully!

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 5
Name: abc | Phone no: 4566584356
Name: qrs | Phone no: 4567891238

=== Menu ===
1. Insert a new contact at the beginning
2. Insert a new contact at the end
3. Delete a contact (using name)
4. Search a contact in the list
5. Display all contacts
6. Exit
Enter your choice: 6
Exiting...
*/
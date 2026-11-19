// Name: Riya Oswal CO2105

#include <stdio.h>
#define SIZE 10

int hash[SIZE];

void insert(int id) {
    int index = id % SIZE;
    int i = 0;

    while(hash[(index+i) % SIZE] != -1 && i < SIZE)
        i++;

    if(i == SIZE)
        printf("Hash Table is Full!\n");
    else {
        hash[(index+i) % SIZE] = id;
        printf("Book inserted successfully!\n");
    }
}

void search(int id) {
    int index = id % SIZE;
    int i = 0;

    while(i < SIZE && hash[(index+i) % SIZE] != -1) {
        if(hash[(index+i) % SIZE] == id) {
            printf("Book found at index %d\n",
                   (index+i) % SIZE);
            return;
        }
        i++;
    }

    printf("Book not found!\n");
}

void display() {
    int i;
    printf("\nIndex\tBook ID\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d\t%d\n", i, hash[i]);
    }
}

int main() {
    int ch, id, i;

    for(i = 0; i < SIZE; i++)
        hash[i] = -1;

    do {
        printf("\n1.Insert Book ID");
        printf("\n2.Search Book ID");
        printf("\n3.Display Hash Table");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            insert(id);
            break;

        case 2:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            search(id);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...");
            break;

        default:
            printf("Invalid choice!");
        }
    } while(ch != 4);

    return 0;
}

/* OUTPUT:

1.Insert Book ID
2.Search Book ID
3.Display Hash Table
4.Exit
Enter choice: 1
Enter Book ID: 101
Book inserted successfully!

Enter choice: 1
Enter Book ID: 111
Book inserted successfully!

Enter choice: 1
Enter Book ID: 121
Book inserted successfully!

Enter choice: 3

Index	Book ID
0	-1
1	101
2	111
3	121
4	-1
5	-1
6	-1
7	-1
8	-1
9	-1

Enter choice: 2
Enter Book ID: 111
Book found at index 2

Enter choice: 2
Enter Book ID: 200
Book not found!

Enter choice: 4
Exiting...

*/

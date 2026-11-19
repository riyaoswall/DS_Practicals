/* Name: Riya*/
/* Roll No: CO2105*/
/* Title: Roll Number Sorting System using Bubble Sort */
#include <stdio.h>
void BubbleSort(int rollno[], int size);
void BubbleSort_pass(int cpy_rollno[], int size);
void Print_rollno(int rollno[], int size);
int main() {
 int size = 0,choice;
 int rollno[60];
 int cpy1_rollno[60];
 int cpy2_rollno[60];
 
 do {
 printf("\n+------------------------------+");
 printf("\n| MENU |");
 printf("\n+------------------------------+");
 
 printf("\n1. Insert Roll Numbers \n2. Sort Roll Numbers in ascending order \n3. Display Sorted Roll Numbers \n4. Display Intermediate passes of sorting \n5. Exit");
 
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 
 switch(choice) {
 case 1:// Insert Roll Numbers.
 printf("Enter number of students: ");
 scanf("%d", &size); 
 
 if (size <= 0 || size > 60) {
 printf("Invalid number of students! Enter between 1 and 60.\n");
 size = 0;
 }
 else {
 printf("Enter %d roll numbers: ", size);
 for (int i = 0; i < size; i++) {
 scanf("%d", &rollno[i]);
 }
 for (int i = 0; i < size; i++) {
 cpy1_rollno[i] = rollno[i];
cpy2_rollno[i] = cpy1_rollno[i];
 }
 }
 
 printf("\n-------------------------------------END-------------------------------------\n"); 
 break;
 case 2:// Sort Roll Numbers in ascending order Bubble sort. 
 printf("\nThe Roll Numbers are Sorted in ascending order\n");
 BubbleSort(rollno, size);
 
 printf("\n-------------------------------------END-------------------------------------\n");
 break;
 
 case 3://Display sorted Roll Numbers.
 printf("\nSorted Roll Numbers:\n");
 Print_rollno(rollno, size);
 
 printf("\n-------------------------------------END-------------------------------------\n");
 break;
 
 case 4://Display intermediate passes of sorting.
 printf("\n--- Intermediate Passes ---\n");
 BubbleSort_pass(cpy2_rollno, size);
 
 printf("\nFinal sorted roll no: \n");
 Print_rollno(cpy2_rollno, size);
 
 for (int i = 0; i < size; i++) {
 cpy2_rollno[i] = cpy1_rollno[i];
 }
 
 printf("\n-------------------------------------END-------------------------------------\n");
 break;
 
 case 5://Exit.
 printf("\n-------------------------------------END-------------------------------------\n");
 break;
 
 default: printf("Enter valid choice!");
 
 }
 
 } while (choice != 5);
 
 return 0;
}
void BubbleSort(int rollno[], int size) {
 int temp;
 for (int i = 0; i < size - 1; i++) {
 for (int j = 0; j < size - i - 1; j++) {
 if (rollno[j] > rollno[j + 1]) {
 temp = rollno[j];
 rollno[j] = rollno[j + 1];
 rollno[j + 1] = temp;
 }
 }
 }
}
 
 
void BubbleSort_pass(int cpy2_rollno[], int size) {
 int temp;
 for (int i = 0; i < size - 1; i++) {
 for (int j = 0; j < size - i - 1; j++) {
 if (cpy2_rollno[j] > cpy2_rollno[j + 1]) {
 temp = cpy2_rollno[j];
 cpy2_rollno[j] = cpy2_rollno[j + 1];
 cpy2_rollno[j + 1] = temp;
 }
 }
 
 // Print intermediate array state after each pass
 printf("Pass %d: ", i + 1);
 Print_rollno(cpy2_rollno, size);
 printf("\n");
 }
}
void Print_rollno(int rollno[], int size) {
 for (int i = 0; i < size; i++) {
 printf("%d ", rollno[i]);
 }
}
/* 
===============================Output===============================
mint@mint:~$ gcc prac2.c -o prac2
mint@mint:~$ ./prac2
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 1 
Enter number of students: 6
Enter 6 roll numbers: 60
54
32
41
50
27
-------------------------------------END-------------------------------------
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 2
The Roll Numbers are Sorted in ascending order
-------------------------------------END-------------------------------------
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 3
Sorted Roll Numbers:
27 32 41 50 54 60 
-------------------------------------END-------------------------------------
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 4
--- Intermediate Passes ---
Pass 1: 54 32 41 50 27 60 
Pass 2: 32 41 50 27 54 60 
Pass 3: 32 41 27 50 54 60 
Pass 4: 32 27 41 50 54 60 
Pass 5: 27 32 41 50 54 60 
Final sorted roll no: 
27 32 41 50 54 60 
-------------------------------------END-------------------------------------
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 4
--- Intermediate Passes ---
Pass 1: 54 32 41 50 27 60 
Pass 2: 32 41 50 27 54 60 
Pass 3: 32 41 27 50 54 60 
Pass 4: 32 27 41 50 54 60 
Pass 5: 27 32 41 50 54 60 
Final sorted roll no: 
27 32 41 50 54 60 
-------------------------------------END-------------------------------------
+------------------------------+
| MENU |
+------------------------------+
1. Insert Roll Numbers 
2. Sort Roll Numbers in ascending order 
3. Display Sorted Roll Numbers 
4. Display Intermediate passes of sorting 
5. Exit
Enter your choice: 5
-------------------------------------END-------------------------------------
*/

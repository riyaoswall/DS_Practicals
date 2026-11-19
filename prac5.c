/*
Name: Riya
Roll no: CO2105
Title: Implement a hospital Patient Registration System Using Queue
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
  
  struct Patient
  {
     int patientID;
     char arrivalTime[20];
  };
  
int main()
{
  
 struct Patient queue[MAX];
 int front=-1;
 int rear=-1;
 
 int choice,i;
 
 do
 {
  printf("\n---------HOSPITAL PATIENT REGISTRATION SYSTEM----------\n");
  printf("1.ADD PATIENT.\n2.ATTEND PATIENT.\n3.VIEW PATIENTS.\n4.CHECK QUEUE EMPTY.\n5.EXIT.\n");
  
  printf("Enter choice: ");
  scanf("%d",&choice);
  
  switch(choice)
  {
   
   // ADD PATIENT
   case 1:
     if(rear==MAX-1)
     {
      printf("Queue is Full");
     }
     else
     {
      if(front==-1)
      {
        front=0;
      }
      rear++;
      
      printf("Enter Patient ID: ");
      scanf("%d",&queue[rear].patientID);
      
      printf("Enter Arrival Time: ");
      scanf("%s",queue[rear].arrivalTime);
      
      printf("Patient Added Successfully\n");
      
     }
     break;
     
     
  //ATTEND PATIENT
  case 2:
    if(front==-1 || front>rear)
    {
      printf("Queue is Empty\n");
    }
    else
    {
      printf("Attending Patient ID: %d\n",queue[front].patientID);
      printf("Arrival Time: %s\n",queue[front].arrivalTime );
      front++;
      
      if(front>rear)
      {
        front=rear=-1;
      }
    }
    break;
    
  //VIEW PATIENTS
  case 3:
    
    if(front==-1 || front>rear)
    {
      printf("Queue is Empty\n");
    }
    else
    {
      printf("Patients in queue: \n");
      
      for(i=front;i<=rear;i++)
      {
        printf("Patient ID: %d\n",queue[i].patientID);
        printf("Arrival Time: %s\n",queue[i].arrivalTime); 
      }
    }
    break;
    
  // CHECK QUEUE EMPTY
  case 4:
    if(front==-1 || front > rear)
    {
      printf("Queue is Empty\n");
    }
    else
    {
     printf("Queue is not Empty\n");
    }
    break;
    
  // EXIT
  case 5:
   printf("Exiting the System.\n");
   break;
   
  }
}while(choice != 5);

return 0;
}

/*
OUTPUT

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 1
Enter Patient ID: 100
Enter Arrival Time: 10:15  
Patient Added Successfully

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 1
Enter Patient ID: 101
Enter Arrival Time: 11:00
Patient Added Successfully

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 1
Enter Patient ID: 102
Enter Arrival Time: 11:42
Patient Added Successfully

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 2
Attending Patient ID: 100
Arrival Time: 10:15

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 3
Patients in queue: 
Patient ID: 101
Arrival Time: 11:00
Patient ID: 102
Arrival Time: 11:42

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 4
Queue is not Empty

---------HOSPITAL PATIENT REGISTRATION SYSTEM----------
1.ADD PATIENT.
2.ATTEND PATIENT.
3.VIEW PATIENTS.
4.CHECK QUEUE EMPTY.
5.EXIT.
Enter choice: 5
Exiting the System.


*/

/*
Title: Implement Array operations and searching
Roll No:CO2105
Name:Riya
*/

#include<stdio.h>
#include<stdbool.h>
int main(){
 int marks[20], i, n,choice,deleted_element,search,j,temp,mid,target;
 int low=0;
 int high=n-1;
 bool found=false;
 bool target_found=false;
 do
 {
  printf("\n============MENU==============");
  printf("\n 1.Insert the Marks.\n 2.Display.\n 3.Delete an Element.\n 4.Search by Linear Search.\n 5.Search by Binary Search. \n 6.Exit \n");
  printf("Enter Your Choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:// Insert the Marks
    
      printf("Enter the size of array: ");
      scanf("%d",&n);
      printf("Enter the Marks: ");
      for(i=0;i<n;i++)
      {
        scanf("%d",&marks[i]);
      }
      break;
      
      
    case 2://Display Marks
    
      printf("Marks:\n ");
      for(i=0;i<n;i++)
      {
        printf("\n%d",marks[i]);
      }
      break;
      
      
    case 3: // Delete an Element
    
      printf("Enter the index no you want to delete: ");
      scanf("%d",&deleted_element);
      for(i=deleted_element;i<n-1;i++)
      {
       marks[i] = marks[i+1];
       
      }
      printf("Element at index %d deleted successfully",deleted_element);
      n=n-1;
     break;
       
       
    case 4:// Linear search 
      printf("Enter the marks you want to search: ");
      scanf("%d",&search);
      for(i=0;i<n;i++)
      {
        if (marks[i]==search)
        {
          found=true;
          break;
        }
      
      }
      
     if(found)
      {
       printf("Marks Found");
      }
     else
     {
       printf("Not Found");
     }
     
     found=false;
     break;
      
    
    
  case 5: //Binary search
   
     for(i=0;i<n-1;i++)
     {
       for(j=0;j<n-i-1;j++)
       {
         if(marks[j]>marks[j+1])
         {
           temp=marks[j];
           marks[j]=marks[j+1];
           marks[j+1]=temp;
         }
       }
     }
     
    
     printf("Enter the element you want to find: ");
     scanf("%d",&target);
     low=0;
     high=n-1;
     
     
     while(low<=high)
     {
        mid=(low+high)/2;
       if(marks[mid]==target)
       {
          printf("Marks %d Found at position %d", target, mid);
          target_found=true;
          break;
       }
        if(marks[mid]<target)
                low=mid+1;
        else
                high=mid-1;
      }
      
      
      if(target_found==false)
       {
        printf("Marks not found");
       }
       break;
   }
  
}while(choice != 6);

}


/* OUTPUT 
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 1    
Enter the size of array: 6
Enter the Marks: 10
30
50
60
40
20

============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 2
Marks:
 
10
30
50
60
40
20
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 3
Enter the index no you want to delete: 3
Element at index 3 deleted successfully
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 2
Marks:
 
10
30
50
40
20
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 4
Enter the marks you want to search: 40
Marks Found
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 5
Enter the element you want to find: 20
Marks 20 Found at position 1
============MENU==============
 1.Insert the Marks.
 2.Display.
 3.Delete an Element.
 4.Search by Linear Search.
 5.Search by Binary Search. 
 6.Exit 
Enter Your Choice: 6

*/



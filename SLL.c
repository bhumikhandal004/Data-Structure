//Singly Linked List
#include<stdio.h>
#include<stdlib.h>

//Self Referential Structures
struct node
{
     int data;
     struct node *next;
};

 struct node *head =NULL;


//Inserting node at beginning
void insert_at_beg()
{

     struct node *Newnode = (struct node*)malloc(sizeof(struct node));
     
     printf("Enter the data :\n");
     scanf("%d", &Newnode->data);

     Newnode->next = head;
     head = Newnode;
     printf("Node inserted successfully\n");
}
// Inserting node at End
void insert_end()
{
     struct node *Newnode ,*current;
      
     Newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter the data :\n");
     scanf("%d",&Newnode->data);
     Newnode->next = NULL;
     
    if(head==NULL)
    head = Newnode;
    else{
        current = head;
        while (current->next!=NULL)
        {
            current = current->next;
            
        }
        current->next = Newnode;
   }
   printf("Node inserted successfully\n");
}

// Deleting first node
void fdelete()
{
     struct node *temp = head;
     if(head == NULL)
     {
          printf("list is empty");
     } 
     else
     {
          head = temp->next;
          free(temp);
          temp = NULL;
          printf("\n deleted successfully !:(\n");
     }  
}

// deleting last node
void ldelete()
{
     struct node *temp , *temp1;
     if(head == NULL)
     {
            printf("List is empty");
     }
     else if (head->next == NULL)
     {
          free(head);
     }
     else 
     {
          temp = head;
          while(temp->next->next != NULL)
          {
               temp = temp->next;
          }
          temp1 = temp->next;
          temp->next = NULL;
          free(temp1);
          printf("\nDeleted successfully\n");
     }
     
}

// counting no. of nodes
void counting()
{
    int count = 0; 
    struct node *ptr = head;
    
    if(ptr==NULL)
    printf("List is empty");
    
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    printf("Total node are %d\n",count);

}

// Printing all nodes
void printing()
{
    struct node *temp = head;
    if(head==NULL)
    {
     printf("List is empty");
    }
    
   printf("list is :");
   while (temp!=NULL)
   {
     printf(" %d ->" , temp->data);
     temp = temp->next;
   }
   
    printf("NULL\n");
}

// Deleteing Entire list
void Edelete()
{
     struct node *temp;
     if(head == NULL)
     {
          printf("Oopsss ! List is alrady empty\n");
     }
     else
     {
          temp = head;
          while(temp!=NULL)
          {
               temp = temp->next;
               free(head);
               head = temp;
          }
          printf("List is Empty Now\n");    
     }
}

int main()
{
     
     int choice;
     while(1)
     {

         
          printf("\n----- Single Linked List -----\n");
          printf("\n1. Insert Node at beinging\n");
          printf("\n2. Insert Node at End\n");
          printf("\n3. Deleting the first Node\n");
          printf("\n4. Deleting the last Node\n");
          printf("\n5. counting the Node\n");
          printf("\n6. printing the Data\n");
          printf("\n7. Deleting Entire List\n");
          printf("\n8. Exist\n");
    
          printf("Enter your choice\n");
          scanf("%d",&choice);

          if(choice==8)
          {
               goto exist_loop;//exit the loop
          }

          //switch case for multiple choice

          switch (choice)
          {
          case 1:
                   insert_at_beg();
               break;
          case 2:
                    insert_end();
               break;
          case 3:
                    fdelete();
               break;
          case 4:
                     ldelete();
               break;
          case 5:
                     counting();
               break;
           case 6:
                     printing();
          
               break; 
           case 7:
                   Edelete();
               break;

           default:  printf("Invalid choice");
               break;
          }

     }

     exist_loop:printf("You decided to exist");


}  


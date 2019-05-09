

/*
Code Authors: Bhuvnesh Solanki and Parshva Shah
Guided by: Professor Vaibhav Vasani
Department Of Computer Engineering
K.J. Somaiya College of Engineering,Vidyavihar.
Date: 09/05/2019
*/

#include <stdio.h>  //Including required header files
#include<string.h>
#include<stdlib.h>
#include<time.h>



char stations[10][20]={"Panvel","Kharghar","Belapur","Nerul","Vashi","Mankhurd","Tilaknagar","Kurla","Vadala","CSMT"};  //String array of stations i.e. station list

struct ticket  
{
  int start,stop,cl,cost,ret,con;
  char name[20]; int id;
  
};  //Structure of ticket containing various data like ticket id,source,destination, passenger name, cost etc.



void book(struct ticket t[],int l, int n)
{       //Creating new ticket
 int i,diff,first,last;
 printf("Station List: \n");
 for(i=0;i<10;i++)
 {
   printf("%d : %s \n",i+1,stations[i]); 
   //Displays station list
 }
 for(i=l;i<l+n;i++) //For loop is used so that previous ticket data is not overwritten
 { printf("For Ticket %d: \n",i+1);
  printf("Enter ticket id: \n"); 
  scanf("%d",&t[i].id); //Enter various data
  printf("Select source :\n");
  scanf("%d",&first);
  t[i].start=first-1; //inputs the source in zero indexed array
  printf("Select destination :\n");
  scanf("%d",&last);
  t[i].stop=last-1;//inputs the destination in zero indexed array
  printf("Return ticket?(1)Yes/(2)No) :\n");
  scanf("%d",&t[i].ret); //Checking for return ticket
  printf("Enter passenger name :\n");
  scanf("%s",t[i].name);
  printf("Enter train class(1st/2nd) :\n");
  scanf("%d",&t[i].cl);//Cost differs on basis of class
  diff=abs(t[i].start-t[i].stop);//Difference b/w source and destination
  if(t[i].cl==2) //Cost for second class
  {
    if(diff==1)  //Using if statements to calculate realistic cost based on diff.
    {
      t[i].cost=5;
    }
    else if(diff>1&&diff<4)
    {
      t[i].cost=10;
    }
    else if(diff>=4)
    {
      t[i].cost=20;
    }
  }
  else if(t[i].cl==1) //Cost for first class
  {
    if(diff<=3) //Using if statements to calculate realistic cost based on diff.
    {
      t[i].cost=75; 
    }
    else if(diff>3&&diff<7)
    {
      t[i].cost=110;
    }
    else if(diff>=7)
    {
      t[i].cost=145;
    }  
  }

  if((t[i].cost%10)<5) //Rounding the cost to nearest ten
  {
    t[i].cost=t[i].cost-(t[i].cost%10);
  }
  else
  {
   t[i].cost=t[i].cost-(t[i].cost%10)+10;
  }
  if(t[i].ret==1) //Doubling cost if it is a return ticket
  {
    t[i].cost=t[i].cost*2;  
  }
  printf("\n*Ticket Cost: %d *\n",t[i].cost);//Displaying ticket cost before confirmation
  printf("Confirm ticket?(1)Yes/(2)No) :\n");//Get confirmation
  scanf("%d",&t[i].con);
  if(t[i].con==1) //Display thank you message if ticket confirmed
  {
    printf("\n*Thank you for confirming your ticket, journey should commence within one hour*\n");

  }
  printf("\n");

 }
}


void check(struct ticket t[], int chk) //Function to check for ticket details using ticket id.
{ int i,flag=0;
  for(i=0;i<100;i++)
  {
    if(chk==t[i].id) //If ticket id matches with parameter
    { flag=1;
      printf("Passenger Name : %s\n",t[i].name);
      printf("Source : %s\n",stations[t[i].start]);
      printf("Destination : %s\n",stations[t[i].stop]);
      if(t[i].cl==1)
      {printf("Coach: First Class\n");}
      else if(t[i].cl==2)
      {
        printf("Coach : Second Class\n");
      }
      if(t[i].ret==1)
      {printf("Return Ticket: Yes\n");}
      else if(t[i].ret==2)
      {
        printf("Return Ticket: No\n");
      }
      printf("Ticket Price : %d\n",t[i].cost);
      if(t[i].con==1)
      {printf("Ticket Confirmed\n");}
      else if(t[i].con==2)
      {
        printf("Not Confirmed\n");
      }
      printf("\n");



    }
  }
 
 if(flag==0)
 {printf("\n*Ticket ID has been deleted or does not exist* \n\n");}


}

void cancel(struct ticket t[],int chk)//Function to cancel tickets.
{
  int i,flag=0;
  for(i=0;i<100;i++)
  {
    if(chk==t[i].id) //If ticket id exists,replace all data with default values.
    { flag=1;
      t[i].id=-1;
      strcpy(t[i].name," ");
      t[i].start=-1;
      t[i].stop=-1;
      t[i].cl=0;
      t[i].ret=0;
      t[i].cost=0;
      t[i].con=0;
      printf("\n*Ticket Cancelled*\n\n");}
  }
  if(flag==0)
 {printf("*Invalid Ticket ID *\n");} 
  

}


/*
Code Authors: Bhuvnesh Solanki and Parshva Shah
Guided by: Professor Vaibhav Vasani
Department Of Computer Engineering
K.J. Somaiya College of Engineering,Vidyavihar.
Date: 09/05/2019
*/


int main(void) { //Start of main
  int i; struct ticket t[100]; //Declare 100 tickets in advance
  for(i=0;i<100;i++)
  {
    t[i].id=-1; //Initialise all ids with -1.
  }
  int ch,n,chkid,l=0;//Variable l to keep count of number of tickets
  int ch2=1;
  printf("=============Welcome to Mumbai Local: Harbour Line============= \n\n");
  while(ch2==1) //This loop keeps running unless you choose to stop operations
  { printf("\n*****************\n");
   printf("1.Book Tickets : \n");
	 printf("2.Check Status: \n");
	 printf("3.Cancellation: \n");
	 printf("4.Exit : \n ");
   printf("\n*****************\n");
	 printf("\nEnter your choice : \n");
   scanf("%d",&ch);
   switch(ch) //Switch case based on above choice, required functions are called
   {
    case 1: 
    { printf("Enter number of tickets to be booked: \n");
      scanf("%d",&n);
      book(t,l,n); 
      l=l+n;
      break;}

    case 2:
    { printf("Enter Ticket ID for checking:\n");
      scanf("%d",&chkid);
      check(t,chkid);
      
     
     break;
    }

    case 3:
    { printf("Enter Ticket ID for cancellation:\n");
      scanf("%d",&chkid);
      cancel(t,chkid);
      l--;
      break;
    }

    case 4:
    {
      
      break;
    }

    default:
    {
      printf("Invalid choice!\n");
      break;
    }

   }

   printf("Do you want to continue operations:(1)Yes/(2)No?\n");
   scanf("%d",&ch2);
  }
  printf("\n\n***Exiting program***\n");
  return 0;
} //End of main

/*
Code Authors: Bhuvnesh Solanki and Parshva Shah
Guided by: Professor Vaibhav Vasani
Department Of Computer Engineering
K.J. Somaiya College of Engineering,Vidyavihar.
Date: 09/05/2019
*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



char stations[10][20]={"Panvel","Kharghar","Belapur","Nerul","Vashi","Mankhurd","Tilaknagar","Kurla","Vadala","CSMT"};

struct ticket
{
  int start,stop,cl,cost,ret,con;
  char name[20]; int id;
  
};

void book(struct ticket t[],int l, int n)
{
 int i,diff,first,last;
 printf("Station List: \n");
 for(i=0;i<10;i++)
 {
   printf("%d : %s \n",i+1,stations[i]);
 }
 for(i=l;i<l+n;i++)
 { printf("For Ticket %d: \n",i+1);
  printf("Enter ticket id: \n");
  scanf("%d",&t[i].id);
  printf("Select source :\n");
  scanf("%d",&first);
  t[i].start=first-1;
  printf("Select destination :\n");
  scanf("%d",&last);
  t[i].stop=last-1;
  printf("Return ticket?(1)Yes/(2)No) :\n");
  scanf("%d",&t[i].ret);
  printf("Enter passenger name :\n");
  scanf("%s",t[i].name);
  printf("Enter train class(1st/2nd) :\n");
  scanf("%d",&t[i].cl);
  diff=abs(t[i].start-t[i].stop);
  if(t[i].cl==2)
  {
    if(diff==1)
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
  else if(t[i].cl==1)
  {
    if(diff<=3)
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

  if((t[i].cost%10)<5)
  {
    t[i].cost=t[i].cost-(t[i].cost%10);
  }
  else
  {
   t[i].cost=t[i].cost-(t[i].cost%10)+10;
  }
  if(t[i].ret==1)
  {
    t[i].cost=t[i].cost*2;  
  }
  printf("\n*Ticket Cost: %d *\n",t[i].cost);
  printf("Confirm ticket?(1)Yes/(2)No) :\n");
  scanf("%d",&t[i].con);
  if(t[i].con==1)
  {
    printf("\n*Thank you for confirming your ticket, journey should commence within one hour*\n");

  }
  printf("\n");


  








 }
}


void check(struct ticket t[], int chk)
{ int i,flag=0;
  for(i=0;i<100;i++)
  {
    if(chk==t[i].id)
    { flag=1;
      printf("Passenger Name : %s\n",t[i].name);
      printf("Source : %s\n",stations[t[i].start]);
      printf("Destination : %s\n",stations[t[i].stop]);
      if(t[i].cl==1)
      {printf("Coach: First Class\n");}
      else if(t[i].cl==2)
      {
        printf("Coach = Second Class\n");
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

void cancel(struct ticket t[],int chk)
{
  int i,flag=0;
  for(i=0;i<100;i++)
  {
    if(chk==t[i].id)
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
















int main(void) {
  int i; struct ticket t[100];
  for(i=0;i<100;i++)
  {
    t[i].id=-1;
  }
  int ch,n,chkid,l=0;
  int ch2=1;
  printf("=============Welcome to Mumbai Local: Harbour Line============= \n\n");
  while(ch2==1)
  { printf("\n*****************\n");
   printf("1.Book Tickets : \n");
	 printf("2.Check Status: \n");
	 printf("3.Cancellation: \n");
	 printf("4.Exit : \n ");
	 printf("\nEnter your choice : \n");
   scanf("%d",&ch);
   switch(ch)
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
}
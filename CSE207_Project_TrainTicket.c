
/*
All the requirements (1-4 & a-c) have been followed in this project.
We have put comments to get it easily.

Thank you :")
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct listNode
{
    char c[500];
    struct  listNode* next;
}Node;
typedef struct stackNode  // stack to store train details (3 & b)
{
    char name[100];
    char destination[100];
    char time[100];
    int bogies_numbers;
    int seat_numbers;
    int bogies_seat [100][100];
    int total_seat;
    int first_class_total_seats;
    int second_class_total_seats;
    int third_class_total_seats;
    struct  stackNode* next;
}stack;

typedef struct queueNode     //Queue for storing PASSEGNGER details ( c )
{
    char name[100];
    int age;
    char trainName[100];
    char destination[100];
    char time[100];
    int bogie_number;
    int seat_number;
    struct queueNode *next;
}queue;

Node *head=0;
stack *top=0;
queue* front=0;
queue* rear=0;
int queueLength=0;
stack *n1,*n2,*n3,*n4,*n11,*n12,*n13,*n14; //shown train details in stack (3 & b) *
Node *d1,*d2,*d3,*d4,*d01;
int view=0;

//All the fun

void destinations();
void printDestination(Node *t);
void trainDetails();                   //contains all train records
void printTrainDetails();
void coustomerQueue(queue *newnode);
void cancelTicket(queue* newnode);
void availableTrains(queue *newnode);   //shows train availability (4 & a)
void viewTicket();
void printCoustomerDetails(queue *newnode);
void cancelTicket(queue* newnode);
stack *pop();
stack *selectedTrain(queue *newnode);

int main()
{
    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\tTRAIN TICKET RESERVATION SYSTEM\t\t\t\t\t");
    printf("\t\t\t\t\t\t-    WELCOME TO SHEBA  -\t\t\t\t\t\n");
    printf("\t\t\tPresented By - Neela farhana , Navid Zaman , MD Tahsin\n");
    printf("\t\t\t\t----------------------------------------\n");
    destinations();
    trainDetails();
   while(1)
   {
    printf("\n\n\t\t******* For Admin *******\t\t\t******* For Customer *******\n");
    printf("\n\n\n\t\t1.All Railway Platforms\t\t\t\t  4.Reserve a Ticket \n\n\t\t2. All Trains       \t\t\t\t  5.View Ticket   \n\n\t\t3.Train Tickets Sold\t\t\t\t  6.Cancel Ticket  \n");


    printf("\n\n\t\tEnter a value from the option: ");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        int c;
        printf("\t\tEnter Admin Code: (the code is 007) ");
        scanf("%d",&c);
        if(c==007)   //PASSSWORD IS 007
        printDestination(head);
    }
    else if(ch==2)
    {
        int c;
        printf("\t\tEnter Admin Code: (the code is 007) ");
        scanf("%d",&c);
        if(c==007)  //PASSSWORD IS 007
        {top=n4;
        printTrainDetails();
        }
    }
    else if(ch==3)
    {
       int c;
       printf("\t\tEnter Admin Code: (the code is 007)");
       scanf("%d",&c);
       if(c==007)  //PASSSWORD IS 007
       printCoustomerDetails(front);
    }
    else if(ch==4)
    {
        top=n4;
        queue *newnode;
        newnode=(queue*) malloc (sizeof(queue));

        printf("\t\tName:");
        fgetc(stdin);
        gets(newnode->name);

        printf("\t\tAge:");
        scanf("%d",&newnode->age);

        printf("\t\tChoose a Destination (Type FULL TEXT i.e 'Jashore to Khulna' ):");
        printf("\n\t\t1.Dhaka to Chittagong");
        printf("\n\t\t2.Chittagong to Khulna");
        printf("\n\t\t3.Jashore to Khulna");
        printf("\n\t\t4.Khulna to Sylhet\n\n\t\t");
        int choice;

        fgetc(stdin);
        gets(newnode->destination);

        int flag2=1;
        availableTrains(newnode);
        printf("\n\t\tInput Train Name:");
        top=n4;
        gets(newnode->trainName);
        stack *temp;
        temp=selectedTrain(newnode);
        top=n4;

        strcpy(newnode->time,temp->time);
        int i=0,j=0,c;
        printf("\n\t\tClass: (Press 1::First class  Press 2::Second class  Press 3::Third class)\n\t\t");
        scanf("%d",&c);
        if(c==1)
            {
                  while(i<10)
                    {
                       if(temp->bogies_seat[0][i]!=0)
                       {
                         newnode->bogie_number=0;
                         newnode->seat_number=i;
                         temp->bogies_seat[0][i]--;
                         flag2=0;
                         temp->total_seat--;
                         temp->first_class_total_seats--;
                         break;
                       }
                       else{i++;}
                    }
                }
                else if(c=2)
                {
                    for(i=1;i<3;i++)
                    {
                        for(j=0;j<10;j++)
                        {
                         if(temp->bogies_seat[i][j]!=0){newnode->bogie_number=i;
                         newnode->seat_number=j;temp->bogies_seat[i][j]--;
                         temp->second_class_total_seats--;
                         temp->total_seat--;
                         flag2=0;break;}
                        }
                        if(flag2==0)break;
                    }
                }
                else
                {
                    for(i=3;i<temp->total_seat;i++)
                    {
                        for(j=0;j<10;j++)
                        {
                         if(temp->bogies_seat[i][j]!=0){newnode->bogie_number=i;
                         newnode->seat_number=j;temp->bogies_seat[i][j]--;
                         temp->third_class_total_seats--;
                         temp->total_seat--;
                         flag2=0;break;}
                        }
                        if(flag2==0)break;
                    }
                }

       if(flag2==0)
       {
       printf("\t\t\\\\\\\\\\\\\\\\\\\\\Ticket Sold////////////////////////\n");
       view=1;
       coustomerQueue(newnode);
       }
       else{printf("\t\t\\\\\\\\\\\\\\\\\\\\\No ticket availabe for this class////////////////////////\n");}
       top=n4;
    }

else if(ch==5)
    {
        viewTicket();
    }
    else
    {
        queue *newnode;
        newnode=(queue*) malloc (sizeof(queue));
        printf("Enter Name:");
        fgetc(stdin);
        gets(newnode->name);

        printf("Enter Age:");
        scanf("%d",&newnode->age);

        queue *temp=front;
        while(temp!=0)
        {
           if(strcmp(temp->name,newnode->name)==0 && temp->age==newnode->age)
           {
               top=n4;
               stack *st=pop();
               while(st!=0)
               {
                 if(strcmp(st->name,temp->trainName)==0)
                 {
                   st->bogies_seat[temp->bogie_number][temp->seat_number]++;
                   if(temp->bogie_number==0){st->first_class_total_seats++;}
                   else if(temp->bogie_number==1||temp->bogie_number==2)
                   {
                       st->second_class_total_seats++;
                   }
                   else{st->third_class_total_seats++;}
                   st->total_seat++;
                 }
                 st=pop();
               }
               top=n4;
               cancelTicket(temp);
               printf("\n>>>>>>>Ticket Canceled.<<<<<<<<\n");
               break;
           }
           temp=temp->next;
        }
    }
   }
}

void destinations()
{
    d1 = (Node*) malloc (sizeof(Node)) ;
    d2 = (Node*) malloc (sizeof(Node)) ;
    d3 = (Node*) malloc (sizeof(Node)) ;
    d4 = (Node*) malloc (sizeof(Node)) ;
    d01=(Node*) malloc (sizeof(Node)) ;

    char sa[100]="Sylhet";
    strcpy(d01->c,sa);
    d01->next=0;
    char s[100]="Khulna";
    strcpy(d1->c,s);
    d1->next=d01;
    char s2[100]="Jashore";
    strcpy(d2->c,s2);
    d2->next=d1;
    char s3[100]="Chittagong";
    strcpy(d3->c,s3);
    d3->next=d2;
    char s4[100]="Dhaka";
    strcpy(d4->c,s4);
    d4->next=d3;
    head=d4;

}

void printDestination(Node *t)
{
    Node *temp=t;
    while(temp!=0)
    {
        printf("\t\tPlace Name: %s\n",temp->c);
        temp=temp->next;
    }
    printf("\n\n");
}


void trainDetails()   //train detailsssssssssssssssssssssssssssssssssss
{
    int i,j;
    n1 = (stack*) malloc (sizeof(stack)) ;
    n2 = (stack*) malloc (sizeof(stack)) ;
    n3 = (stack*) malloc (sizeof(stack)) ;
    n4 = (stack*) malloc (sizeof(stack)) ;

    char s[100]="Khulna to Sylhet";
    strcpy(n1->destination,s);
    char m[100]="Shubarna";
    strcpy(n1->name,m);
    char t[100]="9:00 am";
    strcpy(n1->time,t);

    n1->bogies_numbers=5; n1->seat_numbers=10;
    n1->total_seat=n1->bogies_numbers*n1->seat_numbers*2;
    n1->first_class_total_seats=20;
    n1->second_class_total_seats=40;
    n1->third_class_total_seats=40;
    for(i=0;i<5;i++)
    {
       for(j=0;j<10;j++)
       {
         n1->bogies_seat[i][j]=2;
       }
    }
    n1->next=0;

    char s2[100]="Jashore to Khulna";
    strcpy(n2->destination,s2);
    char m2[100]="Jamuna";
    strcpy(n2->name,m2);
    char t2[100]="10:00 am";
    strcpy(n2->time,t2);

    n2->bogies_numbers=6;n2->seat_numbers=10;
    n2->total_seat=n2->bogies_numbers*n2->seat_numbers*2;
    n2->first_class_total_seats=20;
    n2->second_class_total_seats=40;
    n2->third_class_total_seats=60;
    for(i=0;i<6;i++)
    {
       for(j=0;j<10;j++)
       {
         n2->bogies_seat[i][j]=2;
       }
    }
    n2->next=n1;

    char s3[100]="Chittagong to Khulna";
    strcpy(n3->destination,s3);
    char m3[100]="Tista";
    strcpy(n3->name,m3);
    char t3[100]="3:00 pm";
    strcpy(n3->time,t3);

    n3->bogies_numbers=7;n3->seat_numbers=10;
    n3->total_seat=n3->bogies_numbers*n3->seat_numbers*2;
    n3->first_class_total_seats=20;
    n3->second_class_total_seats=40;
    n3->third_class_total_seats=80;
    for(i=0;i<7;i++)
    {
       for(j=0;j<10;j++)
       {
         n3->bogies_seat[i][j]=2;
       }
    }
    n3->next=n2;

    char s4[100]="Dhaka to Chittagong";
    strcpy(n4->destination,s4);
    char m4[100]="Agnibina";
    strcpy(n4->name,m4);
    char t4[100]="4:00 pm";
    strcpy(n4->time,t4);

    n4->bogies_numbers=8;n4->seat_numbers=10;
    n4->total_seat=n4->bogies_numbers*n4->seat_numbers*2;
    n4->first_class_total_seats=20;
    n4->second_class_total_seats=40;
    n4->third_class_total_seats=80;
    for(i=0;i<8;i++)
    {
       for(j=0;j<10;j++)
       {
         n4->bogies_seat[i][j]=2;
       }
    }
    n4->next=n3;
    top=n4;
}


void printTrainDetails()
{
    int i,j;
    stack *s=pop();
    while(s!=0)
    {
        printf("\n\t\tTrain Name:%s \n\t\tTrain Destination:%s  Time:%s\n",s->name,s->destination,s->time);
        printf("\t\tTotal Seats: %d\n",s->total_seat);
        printf("\n\t\tFirst class total seats: %d\n",s->first_class_total_seats);
        printf("\t\tSecond class total seats: %d\n",s->second_class_total_seats);
        printf("\t\tThird class total seats: %d\n",s->third_class_total_seats);
        /*for(i=0;i<s->bogies_numbers;i++)
        {
            if(i==0){printf("\n //First Class//\n");}
            else if(i==1 || i==2) {printf("\n //Second Class//\n");}
            else{printf("\n //Third Class//\n");}
            printf("\n  Bogie No: %d\n\n",i);
            for(j=0;j<s->seat_numbers;j++)
            {
                printf(" Seat No: %d-%d\n",i,j);
            }
        }*/
        s=pop();
    }
}

void coustomerQueue(queue *newnode)
{
    newnode->next=0;
    if(queueLength==0)
    {
        front=newnode;
        rear=newnode;
        queueLength++;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        queueLength++;
    }
}

void cancelTicket(queue* newnode)
{
    if(front==newnode)
    {
        front=front->next;
        if(rear==newnode)
        {
            rear=front;
        }
        queueLength--;
    }
    else
    {
        int f=0,c=0;
        if(rear==newnode)f=1;
        queue *temp=front,*temp2=temp;
        while(temp!=0)
        {
            if(temp==newnode)
            {
              temp2->next=temp->next;
              break;
            }
            temp2=temp;
            temp=temp->next;
        }
        queueLength--;
        if(f==1)rear=temp2;
    }
}

 void printCoustomerDetails(queue *newnode)
 {
     queue* temp=newnode;
     while(temp!=0)
     {
         printf("\n\t\tName:%s   Age:%d     Train Name:%s     Time:%s     Destination:%s   Seat Number:%d-%d\n",
                temp->name,temp->age,temp->trainName,temp->time,temp->destination,temp->bogie_number,temp->seat_number);
         temp=temp->next;
     }
 }

 void viewTicket()
 {
     if(view==0){printf("\n\t\tNo ticket is purchased.");}
     else if(rear==0){printf("\n\t\tYour ticket is Canceled.");}
     else
        {printf("\nName:%s   Age:%d\n\nTrain Name:%s     Time:%s     Destination:%s   Seat Number:%d-%d\n",
         rear->name,rear->age,rear->trainName,rear->time,rear->destination,rear->bogie_number,rear->seat_number);
         view=0;}
 }

 void availableTrains(queue *newnode)
 {
     top=n4;
     stack *temp=pop();
     printf("\t\tAvailable trains for this destination: \n");
     while(temp!=0)
     {
         if(strcmp(temp->destination,newnode->destination)==0)
         {
             printf("\n\t\tTrain Name: %s   Starting Time: %s   Total Seats: %d\n\t\tFirst Class Seats: %d   Second Class Seats: %d   Third Class Seats: %d\n\t\t",
                    temp->name,temp->time,temp->total_seat,temp->first_class_total_seats,temp->second_class_total_seats,temp->third_class_total_seats);
         }
         temp=pop();
     }
 }
 stack *pop()
{
    if(top==0)
    {
        return 0;
    }
    stack *t;
    t=top;
    top=top->next;
    return t;
}
 stack *selectedTrain(queue *newnode)
 {
     top=n4;
     stack *temp=pop();
     while(temp!=0)
     {
        if(strcmp(temp->name,newnode->trainName)==0)
        {
          return temp;
        }
        temp=pop();
     }
 }




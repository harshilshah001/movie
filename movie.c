/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct moviedetails{
	char name[25];
	char phone[15];
	int seat;
	int id;
};

struct moviedetails person[10800]; //array of above structure moviedetails
int count=0;
int id2=1000;

int changeprize(int);
void booking(int *,int,int );
int choice1(void); //this function only takes user input regarding choice 
void cancel(int *);        
void Bhool_Bhulaiya(int choice,char name[10],int id2,int price);
void Samrat_Prithviraj(int choice,char name[10],int id2,int price);
void Jurassic_World_Dominion(int choice,char name[10],int id2,int price);
int cancelmovie(void);
int movie(void);
int timings(void);
int city(void);
void details(void);



int main()
{
	int **seat,choice,price=500,selection,selection1,selection2,i; //price is 500
	
	//seat array is used to store details whether seat is booked or not
	seat=(int **)calloc(101,sizeof(int *)); //array for 100 seats
	for (i=0;i<3;i++) //for 2D array; 1D array inside 1D array
		*(seat+i)=(int *)calloc(101,sizeof(int )); //allocating 2D array
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;
			case 3:
				selection=movie();
				selection1=timings();
				selection2=city();
				booking(seat[selection-1],price,selection);
				count++;
				break;
			case 4:
				selection=cancelmovie();
				cancel(seat[selection-1]);
				break;
			case 5:
				x=5;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}
int changeprize(int prize) //function to change price
{
	char input_password[10],server_password[10]="admin";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",&input_password);
	if (strcmp(input_password,server_password)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
	}
	else
		printf("The entered password is wrong! ");
	return prize;
}
void booking(int *array,int price,int selection) //function to reserve tickets
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0) //if seat is not reserved then print seat number
			                 //for user booking
				printf("%d\t",i); 
			else //the seat is booked hence print *
				printf("B\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name); //scanning persons name
		//%19[^\n]%*[^\n] is regular expression; 
		//name with more than 19 letters will not be accepted
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		int inputCorrect = 0;
		while(!inputCorrect)
		{
    	    printf("Please Enter seat number you want: ");
    		scanf("%d",&j);
    		if (j>100||j<1)
    			{
    				printf("This seat number is unavailable in this theater\nPlease re-enter\n");
    				
    			}
    		else if (array[j]==1) //Checking if ticket is booked or not
    			{
    				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
    			}
    		else
    		    {
    		        array[j]=1;
    		        inputCorrect = 1;
    		    }
		}

// 		
		person[count].seat=j;
		if (selection==1)
			Bhool_Bhulaiya(j,person[count].name,id2,price);
		else if (selection==2)
			Samrat_Prithviraj(j,person[count].name,id2,price);
		else
			Jurassic_World_Dominion(j,person[count].name,id2,price);
		id2++;
}

int choice1(void)
{
	int choice;
	printf("                 Simple Movie Ticket Booking System\n");
	printf(" ==================================================================\n");
	printf("||             1- To edit price of ticket (only admin):           ||\n");
	printf("||             2- To view reserved tickets (only admin):          ||\n");
	printf("||             3- To puchase ticket:                              ||\n");
	printf("||             4- To cancel the seat:                             ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Ticket_ID,i,is_ticket_cancelled;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Ticket_ID);
	  for (i=0;i<300;i++)
	  {
	  		if(Ticket_ID==person[i].id)
	  		{
					 is_ticket_cancelled=1;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 break;
	  		}
	  }
	  if (is_ticket_cancelled!=1)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}

void details(void)
{
	int i;
	char input_password[10],server_password[10]="admin";
	printf("Enter the password to see details: ");
	scanf("%s",&input_password);
	if (strcmp(input_password,server_password)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");

}
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tPress 1 for Bhool Bhulaiya 2\n\n");
	printf("\t\t\tPress 2 for Samrat Prithviraj\n\n");
	printf("\t\t\tPress 3 for Jurassic World: Dominion\n");
	scanf("%d",&i);
	return i;
}

int timings(void)
{
	int i;
	system("cls");
	printf("\t\t\tSelect timing slots\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tPress 1 for 09:00 AM\n");
	printf("\t\t\tPress 2 for 11:30 AM\n");
	printf("\t\t\tPress 3 for 02:30 PM\n");
	printf("\t\t\tPress 4 for 05:00 PM\n");
	printf("\t\t\tPress 5 for 08:00 PM\n");
	printf("\t\t\tPress 6 for 10:30 PM\n");
	scanf("%d",&i);
	return i;
}

int city(void)
{
	int i;
	system("cls");
	printf("\t\t\tSelect City\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tPress 1 for Mumbai\n");
	printf("\t\t\tPress 2 for Delhi-NCR\n");
	printf("\t\t\tPress 3 for Bengaluru\n");
	printf("\t\t\tPress 4 for Hyderabad\n");
	printf("\t\t\tPress 5 for Chandigarh\n");
	printf("\t\t\tPress 6 for Ahmedabad\n");
	scanf("%d",&i);
	return i;
}
int cancelmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tPress 1 for Bhool Bhulaiya 2\n\n");
	printf("\t\t\tPress 2 for Samrat Prithviraj\n\n");
	printf("\t\t\tPress 3 for Jurassic World: Dominion\n");
	scanf("%d",&i);
	return i;
}

void Bhool_Bhulaiya(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Bhool Bhulaiya 2\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 05-05-2022\n");
        printf("\t                                              Seats No. : %d  \n",choice);
        printf("\t                                              Price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

void Samrat_Prithviraj(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Samrat Prithviraj\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 06-05-2022\n");
        printf("\t                                              Seat No. : %d  \n",choice);
        printf("\t                                              Price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

void Jurassic_World_Dominion(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------SIMPLE TICKETING SYSTEM----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Jurassic World: Dominion\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 06-05-2022\n");
        printf("\t                                              Seat No. : %d  \n",choice);
        printf("\t                                              Price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

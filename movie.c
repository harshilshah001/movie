/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

#include<stdlib.h>

#include<string.h>

//#include<conio.h>


struct book

{

    char name[25];

    char date[20];

}


void main()

{

    system("color 30");

    int ch;

    do

    {


        printf("\nWelcome to Moive Ticket Booking System");


        printf("\nPress [1] To Book Tickets");

        printf("\nPress [2] To View Now Playing Movie");

        printf("\nPress [3] To Add New Movie (Admin Only)");

        printf("\nPress [4] To Delete Now Playing Movie (Admin Only)");


        printf("\nPress [5] To View All Transactions (Admin Only)");

        printf("\nPress [6] To Delete All Transactions (Admin Only)");
         
        printf("\nPress [7] To Exit");

        printf("\nPlease Enter Your Choice:");


        scanf("%d",&ch);

        switch (ch)

        {

            case 1 :

                Book_Ticket();

                break;



            case 2:

                View_Movie();

                break;



            case 3:

                Add_Movie();

                break;



            case 4:

                Delete_Movie();

                break;



            case 5:

                Old_Transactions();

                break;



            case 6:

                Delete_Transactions();

                break;



            case 7:

                printf("\nThank You!\n");

                exit(0);



            default:

                printf("\nWrong choice");

                break;

        }

    }

    while(ch!=7);

}


void Book_Ticket(); //for booking tickets

void View_Movie(); // for view now playing movie

void Add_Movie(); //for inserting new movie

void Delete_Movie(); // for deleting now playing movie

void Old_Transactions(); //for viewing old records of booked tickets

void Delete_Transactions(); //for deleting all transactions


void Add_Movie()

{


    password[]="password";


    struct book ;

    printf("\n\t\t\tCaution!!!\nThis will delete now playing movie (if available) and will add new movie!!!\nIf you want to go back then type '_back_' or '_BACK_'");

    login:

    {

            if(strcmp(p,password)==0)

            {

                printf("\nPassword matched...\n");

                printf("Enter Movie name (Use '_' for spaces):- ");

                scanf("%s",b.name);

                printf("Enter Release Date(DD/MM/YYYY):- ");

                scanf("%s",b.date);

                printf("Enter Ticket Price for row 1 to 4 (Rs.):- ");

                scanf("%d",&b.r1);

                printf("Enter Ticket Price for row 5 to 8 (Rs.):- ");

                scanf("%d",&b.r2);

                printf("Enter Ticket Price for row 9 to 12 (Rs.):- ");

                scanf("%d",&b.r3);



                printf("\n");


            }

        
            else

            {

                printf("\nInvalid Password!!!");

                goto login;

            }

    }



}


void Delete_Movie()

{


    int l;


    char temp2, password[]="password",p[100];

        login:

        {

            l=0;

            printf("\nEnter Password:");

            
            if(strcmp(p,password)==0)

            {

                printf("\nPassword matched...\n");

    

                    //Sleep(1000);

                    printf(".");

                    //Sleep(1000);

                    printf(".");

                    //Sleep(1000);

                    printf(".");

                    //Sleep(1000);

                    printf("\nMovie Deleted Successfully!!!\n\n");

                    //Sleep(2000);

                    main();

                }

                fclose(fp);

            }

            else

            goto login;

        }

}


void View_Movie()

{

  

    char ch;

    int s1,s2,s3,s4;

    

        system("cls");

        if((ch=fgetc(fp))!=EOF)

        {

       
            fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

            printf("================ Now Playing =====================");

            printf("\nMovie Name: %s",b.name);

            printf("\nRelease Date: %s",b.date);

            printf("\nTicket pricing:\n1.Row 1 to 4: %d Rs per seat (%d seats available)\n2.Row 5 to 8: %d Rs per seat (%d seats available)\n3.Row 9 to 12: %d Rs per seat (%d seats available)\n4.Balcony: %d Rs per seat (%d seats available)\n",b.r1,s1,b.r2,s2,b.r3,s3,b.balcony,s4);

            //printf("\nTicket pricing:\n\t\tRow 1 to 4: %d Rs.\n\t\tRow 5 to 8: %d Rs.\n\t\tRow 9 to 12: %d Rs.\n\t\tBalcony: %d Rs.\n\n",b.r1,b.r2,b.r3,b.balcony);

            //Sleep(2000);

    

            main();

        }

        else

        {

            printf("No movie available, please check after few days!!!");

            //Sleep(2000);

            main();

        }

    }

    fclose(fp);

}



void Book_Ticket()

{

    struct book b;

  
    int total_seat,total_amount,row,temp_row,i,j,k,s1,s2,s3,s4;

    long long int mobile;

    char name1[15],name2[15];

    char ch,choice,ch1;



        /*printf("================ Now Playing =====================");

        printf("\nMovie_Name  Release_Date  Ticket_Price");

        printf("\n==================================================\n");



        fp=fopen("data.txt","r");

        fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

        printf("\n================ Now Playing =====================");

        printf("\nMovie Name: %s",b.name);

        printf("\nRelease Date (DD/MM/YYYY): %s",b.date);

        printf("\nTicket pricing (per seat):");

        printf("\n\t\tRow 1 to 4: %d Rs.",b.r1);

        printf("\n\t\tRow 5 to 8: %d Rs.",b.r2);

        printf("\n\t\tRow 9 to 12: %d Rs.",b.r3);

        printf("\n\t\tBalcony: %d Rs.",b.balcony);

        printf("\n==================================================");

    }

    if(s1==0&&s2==0&&s3==0&&s4==0)

    {

        printf("\nThe seats are full! Visit after few days...\n\n");

        main();

    }

    else

    goto choose;

  

    choose:

    {

  

        fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

        fclose(fp);

        printf("\nDo you want to Book tickets for above movie?(y/n)\n");

        scanf("%s",&choice);

        if((choice=='y')||(choice=='Y'))

        {

            printf("\n***Fill Deatails***");

            name:

                printf("\nEnter your name (First Name<space>Last Name):");

                scanf("%s %s",name1,name2);

                
}







int main()
{
    printf("Hello World");

    return 0;
}


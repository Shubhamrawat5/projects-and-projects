#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip.h>
int n=2;
int k=2,u=0;
class train
{
  int train_no,price;
  int seat;
  char d_time[6],a_time[6];
  char train_name[15];
  char start_pl[15];
  char dest_pl[15];
 public:
  friend class admin;
  friend class passenger;
};

class passenger
{
  char name[15], phone[10];
  int sitno,trainno;
  int age;
 public:
  void getdata();
  void bookticket();
  void cancelticket();
  friend class admin;
  friend class train;
};

class admin
{
  int train_no;
  int pass;
  int seat;
 public:
  void password();
  void startpg();
  train* addtrain();
  void viewpsg();
  void outdata();
  friend class train;
  friend class passenger;
};

admin a;
train t[10];
passenger p[20];
passenger psg;

void admin:: password()
{
 system("cls");
 int passw;
 pass=1234;
 cout<<"____________________________________________________________________"<<endl;
 cout<<"Login to Admin mode";
 cout<<"\nEnter Password:";
 cin>>passw;
 if(passw==pass)
 {
  cout<<"-----Login Successful !-----"<<endl;
  cout<<"\n____________________________________________________________________"<<endl;
  startpg();
 }
 else
 {
  cout<<"-----Incorrect Password !-----"<<endl;
  cout<<"----------Try Again!!---------"<<endl;
  getch();
  password();
 }
}

void admin:: startpg()
{
 admin a1;
 system("cls");
 int ch;
 char ch1;
 cout<<"\n                  Welcome to the Admin mode                       "<<endl;
 cout<<"____________________________________________________________________"<<endl;
 do
 {
 cout<<"\nEnter your choice:"<<endl;
 cout<<" 1. Add Train\n 2. View Trains\n 3. View Passengers\n 4. Exit"<<endl;
 cin>>ch;
 switch(ch)
 {
  case 1:addtrain();
	 break;
  case 2:outdata();
	 break;
  case 3:viewpsg();
	 break;
  case 4:exit(0);
  default:cout<<"Error!!"<<endl;
 }
 cout<<"\nDo you want to continue? (type 'y' to continue)";
 cin>>ch1;
 }
 while(ch1 == 'y'|| ch1=='Y');
}


train* admin :: addtrain()
{
 int i,no;
 char ch1;
 cout<<"Scheduled Trains are:"<<endl;
 a.outdata();
 cout<<"\nDo you want to add more trains ?(Y/N)";
 cin>>ch1;
 if(ch1=='Y' || ch1=='y')
 {
  cout<<"\nHow many trains you want to add ?";
  cin>>no;
  for(i=n;i<n+no;i++)
  {
   cout<<"\nEnter Data for Train "<<endl;
   cout<<"\nEnter Train number:";
   cin>>t[i].train_no;
   cout<<"\nEnter Train name:";
   gets(t[i].train_name);
   cout<<"\nEnter Boarding Place:";
   gets(t[i].start_pl);
   cout<<"\nEnter Destination Place:";
   gets(t[i].dest_pl);
   cout<<"\nEnter Fare:";
   cin>>t[i].price;
   cout<<"\nEnter the total number of seats:";
   cin>>t[i].seat;
   cout<<"\nEnter the arrival time:";
   gets(t[i].a_time);
   cout<<"\nEnter the departure time:";
   gets(t[i].d_time);
  }
  n=n+no;
  k=k+no;
 }
 return t;
}


void admin:: outdata()
{
 t[0].train_no=10;
 strcpy(t[0].train_name,"Deccan_Exp");
 strcpy(t[0].start_pl,"Mumbai");
 strcpy(t[0].dest_pl,"Pune");
 t[0].price= 250;
 t[0].seat=800;
 strcpy(t[0].a_time,"7:30");
 strcpy(t[0].d_time,"12:30");
 t[1].train_no=11;
 strcpy(t[1].train_name,"FlyingRani");
 strcpy(t[1].start_pl,"CST");
 strcpy(t[1].dest_pl,"Surat");
 t[1].price= 1200;
 t[1].seat=2000;
 strcpy(t[1].a_time,"11:30");
 strcpy(t[1].d_time,"23:45");
 cout<<"\n---------------------------Train Schedule-------------------------------"<<endl;
 cout<<setw(5)<<"TNo"<<setw(12)<<"Name"<<setw(15)<<"Boarding"<<setw(15)<<"Destination"<<setw(6)<<"Fare"<<setw(7)<<"Seats"<<setw(7)<<"ATime"<<setw(7)<<"Dtime";
 cout<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<setw(5)<<t[i].train_no<<setw(12)<<t[i].train_name<<setw(15)<<t[i].start_pl<<setw(15)<<t[i].dest_pl<<setw(6)<<t[i].price<<setw(7)<<t[i].seat<<setw(7)<<t[i].a_time<<setw(7)<<t[i].d_time<<endl;
 }
}

int main()
{
 clrscr();
 int ch;
 cout<<"************************************************************"<<endl;
 cout<<"=============== RAILWAY  RESERVATION  SYSTEM ==============="<<endl;
 cout<<"************************************************************"<<endl;
 train t[10];
 do
 {
  cout<<"\t MAIN  MENU:"<<endl;
  cout<<"\t 1.Admin mode \n\t 2.User mode \n\t 3.Exit"<<endl;
  cout<<"Enter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1: a.password();
	   break;
   case 2: psg.getdata();
	   break;
   case 3: exit(0);
   default: cout<<"Please enter right choice!!"<<endl;
  }
 }while(ch!=3);
 return(0);
}

void  passenger:: getdata()
{
 int ch;
 char ch1;
 do
 {
 system("cls");
 cout<<"<=============== USER MENU ===============>\n"<<endl;
 cout<<"\t(1)View Trains \n\t(2)Book Ticket \n\t(3)Cancel Ticket \n\t(4)Back to Main Menu\n\t(5)Exit \n";
 cout<<"Enter your choice: ";
 cin>>ch;
 switch(ch)
 {
  case 1: a.outdata();
	  break;
  case 2: bookticket();
	  break;
  case 3: cancelticket();
	  break;
  case 4: system("cls");
	  main();
	  break;
  case 5: exit(0);
  default: cout<<"\nPlease enter right choice: ";
 }
 cout<<"\nDo you want to continue? ";
 cin>>ch1;
 }while( ch1=='y' || ch1=='Y');
}


void passenger:: bookticket()
{
 int seatno;
 char c,found=-1;
 char v;
 int num;
 int train_num;
 system("cls");
 cout<<"============================================\n";
 cout<<"\n How many tickets do you want to book:";
 cin>>num;
 for(int j=0;j<num;j++)
 {
  cout<<"\nEnter train number: ";
  cin>>train_num;
  for(int i=0;i<num;i++)
  {
   if(t[i].train_no==train_num)
   {
    if(t[i].seat==0)
    {
     cout<<"\n Not available seat";
     getch();
     system("cls");
     main();
    }
    else
    {
     p[j].trainno=train_num;
     seatno=t[i].seat;
     found=1;
      cout<<"\nEnter your name:";
      gets(p[j].name);
      cout<<"Enter your phone number:";
      gets(p[j].phone);
      cout<<"Enter your Age(in years): ";
      cin>>p[j].age;
      cout<<"Ticket Booked successfully !!";
      cout<<"\nDo the payments and collect your ticket.";
      cout<<" \nYour Seat number is: "<<seatno;
      cout<<"\n(: WE WISH YOU A HAPPY JOURNEY :)"<<endl;
     p[j].sitno=seatno;
     t[i].seat--;
     seatno--;
     u++;
    }
   }
  }
  if(found==-1)
  {
   cout<<"\nTrain not found!!";
   getch();
   system("cls");
   main();
  }
 }
 cout<<"\n Enter '1' for main menu & press any key to exit:";
 cin>>c;
 if(c=='1')
 {
  system("cls");
  main();
 }
 else
  exit(0);
}

void passenger:: cancelticket()
{
 char phnmbr[15];
 int location=-1;
 int ch;
 cout<<"\n Enter Phone number:";
 cin>>phnmbr;
 for(int i=0;i<u;i++)
 {
  if(strcmp(p[i].phone,phnmbr)==0)
  {
   location=i;
   cout<<"Your details are: "<<endl;
   cout<<"Name: "<<p[i].name<<"\nAge: "<<p[i].age<<"\nPhone no.: "<<p[i].phone<<"\nTrain no.: "<<p[i].trainno<<"\nSeat no.: "<<p[i].sitno<<endl;
   cout<<"Do you want to continue?(press 1 to continue): ";
   cin>>ch;
   if(ch==1)
    break;
   else
    main();
  }
 }
 if(location==-1)
 {
  cout<<"\n Record not found!!";
  getch();
  system("cls");
  main();
 }
 else
 {
  for(int i=location;i<u;i++)
  {
   strcpy(p[i].name,p[i+1].name);
   strcpy(p[i].phone,p[i+1].phone);
   p[i].age=p[i+1].age;
   p[i].sitno=p[i+1].sitno;
   p[i].trainno=p[i+1].trainno;
  }
  u--;
  cout<<"\nTicket  cancelled  successfully!!";
  getch();
  system("cls");
  main();
 }
}

void admin:: viewpsg()
{
 int a,j;
 system("cls");
 cout<<"=============== Passenger Details ===============\n"<<endl;
 cout<<setw(10)<<"Train no."<<setw(15)<<"Name"<<setw(15)<<"Phone no."<<setw(7)<<"Age"<<setw(10)<<"seat no"<<endl;
 for(j=0;j<u;j++)
 {
  cout<<setw(10)<<p[j].trainno<<setw(15)<<p[j].name<<setw(15)<<p[j].phone<<setw(7)<<p[j].age<<setw(10)<<p[j].sitno<<endl;
  seat++;
 }
 cout<<"\n enter'1'for main menu & enter'0' for back:";
 cin>>a;
 if(a==1)
 {
  system("cls");
  main();
 }
 if(a==0)
 {
  system("cls");
  startpg();
 }
}




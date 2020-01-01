/*==========================================================================
\/\/\/\/\/\/\/\/\/\/\/\/ STUDENTS INFORMATION SYSTEM \/\/\/\/\/\/\/\/\/\/\
============================================================================ */
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

int c;                           //global variable used for selection in menu.

  class student
{
   char fname[15],mname[15];        //father name & mother name
   int rollno,admin_no,dd,mm,yy;    //roll number,Admission no, Day,Month,Year

 public:

   char name[15];             //student's name
   void menu();               //function for menu
   int select();              //function for selecting option
   void smiley();             //function of sad-face when exiting from system
   void getdata();            //function to input data
   void putdata();            //function to output data
   void modifydata();         //function to edit data
   void display();            //function to display data
   int get_roll()             //function to return roll-no
 { return rollno; }

}
s1;    //object for class student

/*___________________________________________________________________________
		      DEFINITION OF MENU FUNCTION...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
 void student::menu()
{
  settextstyle(1,HORIZ_DIR,4);
  setcolor(4);
  outtextxy(5,2,"<<< STUDENT INFORMATION SYSTEM >>> ");
  outtextxy(0,4,"________________________________________________________________");
  settextstyle(6,HORIZ_DIR,2);
  setcolor(1);
  outtextxy(20,60,"   1.  Enter New Record");
  outtextxy(20,90,"   2.  Search Record");
  outtextxy(20,120,"   3.  Display Record");
  outtextxy(20,150,"   4.  Modify Record");
  outtextxy(20,180,"   5.  Delete Record");
  outtextxy(20,210,"   6.  Exit");
  setcolor(11);
  setfillstyle(9,11);
  rectangle(0,300,getmaxx(),getmaxy());
  floodfill(30,450,11);
  setcolor(4);
  settextstyle(5,HORIZ_DIR,4);
  outtextxy(0,300,"_________________Choose Your Option___________________");
  setcolor(5);
  settextstyle(6,HORIZ_DIR,2);
  outtextxy(0,450,"                    Press ENTER to select your option...");


}


/*___________________________________________________________________________
		      DEFINITION OF SELECT FUNCTION...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


int student::select()
{

s:                  //label
setcolor(4);
char key;
int posy1=30,posy2=58;
c=0;
   while(posy2<225)
  {
   cout<<c;
   key=getch();
   sound(400);
   delay(40);
   if(key==80)  //downward key pressed
  {
   c++;
   setcolor(4);
   rectangle(30,posy1,290,posy2);
   nosound();
   posy1=posy1+30;
   posy2=posy2+30;
   cleardevice();
				   //-------------------

   setcolor(9);
   setfillstyle(9,9);
   rectangle(30,posy1,290,posy2);
   floodfill(32,posy1+4,9);

   menu();
}

   if(key==13)   //Enter key pressed
  {
    nosound();
    break;
  }
 }
  if(key==13)      //Enter key pressed
{
  setcolor(4);
  rectangle(160,375,500,420);
  if(c==1)
   { outtextxy(0,380,"                         You want to Enter new Record..."); }
  else if(c==2)
  {  outtextxy(0,380,"                         You want to Search Record..."); }
  else if(c==3)
  {  outtextxy(0,380,"                         You want to Display Record..."); }
  else if(c==4)
  {  outtextxy(0,380,"                         You want to Modify Record..."); }
  else if(c==5)
  {  outtextxy(0,380,"                         You want to Delete Record..."); }
 else if(c==0)
  {  outtextxy(0,380,"                      You want to EXIT from this System...");
     sleep(2);
     cleardevice();
     smiley();
     for(int i=0,x=180;i<30;i++)
  {
   sound(random(9000));
   setcolor(9);
   setfillstyle(1,9);
   circle(220,x,8);
   floodfill(220,x,9);
   circle(365,x,8);
   floodfill(365,x,9);
   x=x+40;
   delay(100);
   nosound();
  //cleardevice();
   }

     setcolor(4);
     settextstyle(5,HORIZ_DIR,4);
     outtextxy(20,getmaxy()-80,"   BYE BYE...");
     getch();
     exit(0);
   }
}

 else if(key==80)       //enter key pressed
  goto s;

return c;
}

/*___________________________________________________________________________
		      DEFINITION OF SMILEY FUNCTION...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


void student::smiley()
{
setcolor(14);
setfillstyle(1,14);
circle(300,200,160); //big
floodfill(300,200,14);
setcolor(1);
setfillstyle(1,1);
circle(220,165,20);  //1
floodfill(220,165,1);
circle(365,165,20);  //2
floodfill(365,165,1);
setcolor(4);
arc(300,370,60,120,90);
}



void student::getdata()
{ clrscr();
gotoxy(10,2);textcolor(0);textbackground(10);
cprintf(" ::  RECORD ENTRY SECTION  :: ");
gotoxy(12,6);textcolor(3);textbackground(0);
cprintf("1. Enter the rollno :"); cin>>rollno;
gotoxy(12,7);textcolor(3);
cprintf("2. Enter the name :"); gets(name);
gotoxy(12,8);textcolor(3);
cprintf("3. Father name  :"); gets(fname);
gotoxy(12,9);textcolor(3);
cprintf("4. Mother name  :"); gets(mname);
gotoxy(12,10);textcolor(3);
cprintf("5. Enter Admission no. :");
cin>>admin_no;
gotoxy(12,11);textcolor(3);
cprintf("6. Enter date of birth :");
gotoxy(14,12);textcolor(3);
cprintf("   Date:");cin>>dd;
gotoxy(14,13);textcolor(3);
cprintf("   Month:");cin>>mm;
gotoxy(14,14);textcolor(3);
cprintf("   Year :");cin>>yy; }

void student::putdata()
{
clrscr();
gotoxy(10,2);textcolor(1);
textbackground(10);
cprintf(" ::  RECORD  ::");
gotoxy(12,6);textcolor(3);textbackground(0);
cprintf("1. Rollno : ");cout<<rollno;
gotoxy(12,7);textcolor(3);
cprintf("2. Name : ");puts(name);
gotoxy(12,8);textcolor(3);
cprintf("3. Father name : ");puts(fname);
gotoxy(12,9);textcolor(3);
cprintf("4. Mother name : "); puts(mname);
gotoxy(12,10);textcolor(3);
cprintf("5. Admission no.: ");cout<<admin_no;
gotoxy(12,11);textcolor(3);
cprintf("6. Date of birth: ");cout<<dd<<"/"<<mm<<"/"<<yy;
}
void student::modifydata()
{ char nm[15],fath[15],moth[15];
int rno,d,m,y,admis;
clrscr();
gotoxy(10,2);textcolor(0+BLINK); textbackground(8);
cprintf(" Enter new record :");
gotoxy(11,5);textcolor(14); textbackground(0);
cprintf("  Name :");gets(nm);
gotoxy(11,6);textcolor(14);
cprintf(" Roll No. :");cin>>rno;
gotoxy(11,7);textcolor(14);
cprintf(" Father name :");gets(fath);
gotoxy(11,8);textcolor(14);
cprintf(" Mother name :");gets(moth);
gotoxy(11,9);textcolor(14);
cprintf(" Admission ID :");cin>> admis;
gotoxy(11,10);textcolor(14);
cprintf(" Date of Birth :");
gotoxy(11,11);textcolor(14);
cprintf(" Date :"); cin>>d;
gotoxy(11,12);textcolor(14);
cprintf(" Month :");  cin>>m;
gotoxy(11,13);textcolor(14);
cprintf(" Year :"); cin>>y;
strcpy(name,nm);
strcpy(fname,fath);
strcpy(mname,moth);
rollno=rno;
admin_no=admis;dd=d;mm=m;yy=y;
}
void student::display()
{
//student *p3;
int z=6;
clrscr();
gotoxy(30,1);
textbackground(1);textcolor(6);
cprintf("Student Information");
gotoxy(23,2);textbackground(RED);
textcolor(WHITE+BLINK);
cprintf("::Display Record::") ;
textbackground(0);textcolor(11);
gotoxy(1,3);
cprintf("--------------------------------------------------------------------------");
gotoxy(1,4);
cprintf(" Name     Rollno   Admission no.   DateofBirth    Fathername      Mothername  ");
gotoxy(1,5);
cprintf("---------------------------------------------------------------------------  ");
textcolor(7);
ifstream fff;
fff.open("student.txt",ios::in);
while(!fff.eof())
{
fff.read((char*)&s1,sizeof(s1));
gotoxy(1,z);
cout<<name;
gotoxy(14,z);
cout<<rollno;
gotoxy(23,z);
cout<<admin_no;
gotoxy(36,z);
cout<<dd<<"/"<<mm<<"/"<<yy;
gotoxy(54,z);
puts(fname);
gotoxy(70,z);
puts(mname);
z++;
}
fff.close();
gotoxy(55,24);
textcolor(13);
cprintf("Press Any Key  to Continue");
getch();
}

int main()
{
start:
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
start1:

clrscr();
int a;

setbkcolor(10);
s1.menu();
//setfillstyle(7,2);
//floodfill(20,20,2);
s1.select();
a=c;
closegraph();
getch();
do{
switch(a)
{
case 1:     clrscr();              //enter new data
	    char ch;
	    ofstream fout;
	    fout.open("student.txt",ios::app|ios::ate);
	    if(!fout)
	    {
	    cout<<"File not exist ";
	    exit(1);}
	    do{
	    s1.getdata();
	    fout.write((char*)&s1,sizeof(s1));
	   clrscr();
	     gotoxy(10,7);textcolor(4);
	    cprintf("  --- Record Added Successfully ----");
	    gotoxy(10,8);textcolor(3);
	    cprintf("Do u want to add more record(y/n)_  ");cin>>ch;
		}while(ch=='y'||ch=='Y');
	    fout.close();
	    goto  start;


case 2:     start3:           //search data
	    clrscr();
	     int o; gotoxy(10,2);textcolor(10+BLINK);
	       cprintf("   ::  Search Record :: " );
	       gotoxy(11,6);textcolor(14);
	       cprintf(" 1. Search  by roll no.");
	       gotoxy(11,7);textcolor(14);
	       cprintf(" 2. Search by name ");
	       gotoxy(11,8);textcolor(14);
	       cprintf(" 3. Back to MAIN MENU");
	       gotoxy(17,9);textcolor(6);
	       cprintf(" Enter the option : ");cin>>o;
	       switch(o)
	       {
	       case 1:  clrscr();
	       int r_no;
	       gotoxy(17,17); textcolor(14);
	       cprintf("Enter the rollno :");cin>>r_no;
		  ifstream fin;
		  fin.open("student.txt",ios::in);
		 while(!fin.eof())
		  {
		  fin.read((char*)&s1,sizeof(s1));
		  if(s1.get_roll() == r_no)
		  { s1.putdata();

		    getch();
		     goto start3;
		  } }

	      if(s1.get_roll()!=r_no)
	    {
		clrscr(); gotoxy(25,25);textcolor(9);
		cprintf(" Sorry! record not found");
		 getch();
	      }
		  fin.close();
		  goto start3;

	       case 2:  clrscr();

	       char s_name[15];
		gotoxy(17,17); textcolor(14);
	       cprintf("Enter the name :");gets(s_name);
		  ifstream fn;
		  fn.open("student.txt",ios::in);
		  while(!fn.eof())
		  {
		  fn.read((char*)&s1,sizeof(s1));
		  if(strcmp(s_name ,s1.name)==0)
		  { s1.putdata();
		    getch();
		     goto start3;
		    }
		  }
		  if(strcmp(s_name,s1.name)!=0)
		  {
		  clrscr(); gotoxy(25,25);textcolor(9);
		  cprintf(" Sorry! record not found");
		  getch();
		  }
		  fn.close();
		  getch();
		  goto start3;

	       case 3:
	       goto start;

	       default:   gotoxy(15,10);textcolor(4);
	       cprintf("Illegal option...");
	       break;
	       }

	   break;
case 3:     clrscr();                    //display data
	    s1.display();
	    break;

case 4:   clrscr();                     //modify data
	   char find='n';
	   int r_n;
	   long pos;
	     fstream ff;
	     ff.open("student.txt",ios::in|ios::out|ios::binary);
	     gotoxy(15,15);textcolor(5);
	     cprintf("Enter the rollno to modify");
	     cin>>r_n;
	     while(!ff.eof())
	     {pos=ff.tellg();
	     ff.read((char*)&s1,sizeof(s1));
	   if(s1.get_roll()==r_n)
	   { find='y';
	    s1.modifydata();
	   ff.seekg(pos);
	  ff.write((char*)&s1,sizeof(s1));
	  ff.close();
	  goto start; } }

	   if(find=='n')
	   {  clrscr();gotoxy(15,15);textcolor(3);
	   cprintf("Record not found");
	   }
	   break;
case 5:    clrscr();         //delete record
	 student *ss;
	 ss=&s1;
	   int stno;        //for rollno
	   char found ='f',confirm='n';
	   ifstream fi;
	   fi.open("student.txt",ios::in);
	   ofstream fo;
	   fo.open("tem.txt",ios::out);
	   cout<<"Enter the rollno to delete:";
	   cin>>stno;
	   while(!fi.eof())
	 {
	   fi.read((char*)&s1,sizeof(s1));

	   if(ss->get_roll()==stno)
	   {
	   ss->putdata();
	   found='y';
	   cprintf("   Are you sure (y/n) : ");
	   cin>>confirm;
	   if(confirm=='n'||confirm=='N')
	   {
	   fo.write((char*)&s1,sizeof(s1));
	   cprintf("Abort by the user");
	   getch();
	   }
	   else
	   fo.write((char*)&s1,sizeof(s1));
	   }
	 }

	   if(found=='f')
	   {
	   cprintf("Record not Found... ");
	   }
	   fi.close();
	   fo.close();
	   remove("student.txt");
	   rename("tem.txt","student.txt");
	   goto start;
case 0:    clrscr();
	  //smiley();
	  exit(0);
	   break;
default: textcolor(1+BLINK);
     gotoxy(10,20);
       clrscr();
      cprintf(" !!! Wrong choice  !!! ");
      break;
      getch();
      goto start;

}}  while(0);
getch();
return 0;
}

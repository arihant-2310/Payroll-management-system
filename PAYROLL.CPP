#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include<ctype.h>
class employee
{
	char name[30],designation[30],address[30],email[30],sex;
	char  mobno[20];
	int empid;
	char egrade,ehouse,econv;
	float eloan,ebasic;

public:
	void mainmenu();
	void biomenu();
	void bio();
	void display();
	void modify();
	void modify1();
	void salary();
	void dispsal();
	void slip();
	void display1();
	int retempid()
	{
		 return empid;
	}
	int found_code(int);
	void id(int);


};
void employee::id(int eid)
{	employee e;
	fstream file;
	file.open("employ.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char*)&e,sizeof(e)))
	{	if(eid==e.retempid())
		{ cout<<"\nEmployee Id Already Exists!!!!";
		  getch();
		  cout<<"\nEnter New Id:";
		  cin>>empid;


		}


	}
			file.close();


}
void intro()
{
cout<<"\n\n\n\n\n\n\n\n\n\b\t\t*******************************************\n";
cout<<"\t\t\tPAYROLL MANAGEMENT SYSTEM\n";
cout<<"\t\t*******************************************";
getch();

}

int login()
{
	char name[20]="Nisha",password[20]="nisha@123";
	char username[20],pass[20]={0},prev[20]={0};
	cout<<"\n\t\t\tLOGIN";
	cout<<"\n\t\t**********************";
	cout<<"\n\t\tEnter Username:";
	gets(username);

	if(strcmp(name,username)==0)
		{
			cout<<"\n\t\tEnter Password:";
			for(int i=0;i<20;i++)
			{       pass[i]=getch();
				putch('*');
				while(pass[i]!=13)
				{ prev[i]=pass[i];
					break;
				}
				if(pass[i]==13)
					break;

			}
			//gets(pass);
			if(strcmp(password,prev)==0)
			       {	cout<<"\n\t\tLogin successfully";
					cout<<"\n\t\t\t\tPress ENTER To Continue";
					getch();
			       }
			else
			     {  cout<<"\nWrong password!!";
				getch();
				return -1;   }

		}
	else
	    {cout<<"\nWrong username!!";
	    getch();
	    return -1;                  }


     return 0;
}
int employee::found_code(int ecode)
{	fstream file;  employee e;
	file.open("employ.dat",ios::in|ios::binary) ;
	file.seekg(0,ios::beg);
	int found=0;
	while(file.read((char*)&e,sizeof(e)))
	{	if(ecode==e.retempid())
		{
			found =1;
			break;
		}


	}   file.close();
	return found;


}
void employee::slip(void)
{          employee e;
	clrscr();
	int t2,ecode,valid,days,hours;
	cout<<"<0>=EXIT";
	gotoxy(5,5);
	cout<<"\nEnter The Code Of The Employee:";
	cin>>ecode;

	if(ecode==0)
		return;
	clrscr();
	if(!found_code(ecode))
	{
		gotoxy(5,5);
		cout<<"\nRecord Not Found!!";
		getch();
		return;

	}
	fstream file;
	file.open("employ.dat",ios::in);
	file.seekg(0,ios::beg);
	while(file.read((char *)&e,sizeof(e)))
	{
		if(empid==e.retempid())
		       //	found=0;
			break;
	       //	else
			//found=0;

	}
	file.close();
       /*	if(found==1)
	{
		cout<<"\nRECORD NOT FOUND!!";
	      //	getch();

	} */
	      clrscr();
	cout<<"\nEnter the no. of days worked in a month:";
	cin>>days;
	cout<<"\nEnter the hours worked over time:";
	cin>>hours;

	   clrscr();
	gotoxy(31,2);
	cout<<"3 BROTHER'S PVT LTD.";
	gotoxy(34,4);
	cout<<"SALARY SLIP";
	gotoxy(60,4);
	cout<<"Date:2018-19";
	gotoxy(34,5);
	gotoxy(6,7);
	cout<<"EMPLOYEE NAME:"<<name;
	gotoxy(6,8);
	cout<<"DEGIGNATION:"<<designation;
	cout<<"GRADE:"<<egrade;
	gotoxy(10, 10);
	cout << "Basic Salary         : Rs.";
	gotoxy(10, 12);
	cout << "ALLOWANCE";
	if (egrade != 'E')
	{
	 gotoxy(12, 13);
	 cout << "HRA  : Rs.";
	 gotoxy(12, 14);
	 cout << "CA   : Rs.";
	 gotoxy(12, 15);
	 cout << "DA   : Rs.";
	}
	else
	{
	 gotoxy(12, 13);
	 cout << "OT   : Rs.";
	}
 gotoxy(10, 17);
 cout << "DEDUCTIONS";
 gotoxy(12, 18);
 cout << "LD   : Rs.";
 if (egrade != 'E')
 {
  gotoxy(12, 19);
  cout << "PF   : Rs.";
 }
 gotoxy(10, 21);
 cout << "NET SALARY           : Rs.";
 gotoxy(6, 24);
 cout << "CASHIER";
 gotoxy(68, 24);
 cout << "EMPLOYEE";
 float HRA = 0.0, CA = 0.0, DA = 0.0, PF = 0.0, LD = 0.0, OT = 0.0, allowance, deduction, netsalary;
 if (egrade != 'E')
 {
  if (ehouse == 'Y')
   HRA = (5 * ebasic) / 100;
  if (econv == 'Y')
   CA = (2 * ebasic) / 100;
  DA = (5 * ebasic) / 100;
  PF = (2 * ebasic) / 100;
  LD = (15 * eloan) / 100;
  allowance = HRA + CA + DA;
  deduction = PF + LD;
 }
 else
 {
  ebasic = days * 30;
  LD = (15 * eloan) / 100;
  OT = hours * 10;
  allowance = OT;
  deduction = LD;
 }
 netsalary = (ebasic + allowance) - deduction;
 gotoxy(36, 10);
 cout << ebasic;
 if (egrade != 'E')
 {
  gotoxy(22, 13);
  cout << HRA;
  gotoxy(22, 14);
  cout << CA;
  gotoxy(22, 15);
  cout << DA;
  gotoxy(22, 19);
  cout << PF;
 }
 else
 {
  gotoxy(22, 13);
  cout << OT;
 }
 gotoxy(22, 18);
 cout << LD;
 gotoxy(33, 15);
 cout << "Rs." << allowance;
 gotoxy(33, 19);
 cout << "Rs." << deduction;
 gotoxy(36, 21);
 cout << netsalary;
 gotoxy(2, 1);
 getch();


     clrscr();


}
void employee::salary()
{
     cout<<"\nEnter the grade of the employee(A,B,C,D,E):";
     egrade=getche();
     egrade=toupper(egrade);
     if(egrade!='E')
     {     cout<<"\nENTER IF HOUSE ALLOWANCE IS ALLOTED TO EMPLOYEE OR NOT:";
	   ehouse=getche();
	   ehouse=toupper(ehouse);
	   cout<<"\nENTER IF CONVENCE ALLOWANCE IS ALLOTED TO EMPLOYEE OR NOT:" ;
	   econv=getche();
	   econv=toupper(econv);
	   cout<<"\nENTER LOAN AMOUNT IF ISSUED:";
	   cin>>eloan;
	   cout<<"\nENTER THE BASIC SALARY OF THE EMPLOYEE:";
	   cin>>ebasic;




     }




}
void employee::dispsal()
{

     cout<<"\n\tLOAN AMOUNT"<<"\t\tBASIC SALARY";
     cout<<"\n\t"<<eloan<<"\t\t"<<ebasic;

}
void employee::modify()
{ cout<<"\nEmployee Id Number:"<<empid;
  cout<<"\n___________________________________";
  cout<<"\nName="<<name;
   cout<<"\n_________________________";
    cout<<"\nDesignation="<<designation;
   cout<<"\n_________________________";
    cout<<"\nEmail="<<email;
   cout<<"\n_________________________";
  cout<<"\nAddress="<<address;
   cout<<"\n_________________________";
  cout<<"\nSex="<<sex;
   cout<<"\n_________________________";
  cout<<"\nPhoneno="<<mobno;
   cout<<"\n_________________________";
  cout<<"\nEnter new details:";
  char n[30],ad[30],desig[30],em[30];
  int eid,sal;
  char p[20],se;
   cout<<"\nEnter new employee id no.('0' for old):-";
  cin>>eid;
   cout<<"\nEnter new name(Enter '.'to retain the old name):-";
  gets(n);
  cout<<"\nEnter new designation(Enter '.'to retain old ):-";
  gets(desig);
  cout<<"\nEnter new address(Enter '.'to retain the old address):-";
  gets(ad);
   cout<<"\nEnter new email(Enter '.'to retain old:-";
  gets(em);
  cout<<"\nEnter new sex(M/F)(Enter '.'to retain the old sex):-";
  cin>>se;
  cout<<"\nEnter new phoneno(Enter '.'to retain the old phoneno):-";
  gets(p);
  cout<<"\nEnter New Salary:('0'  for old):-";
  cin>>sal;
   if(eid!=0)
	empid=eid;
  if(strcmp(n,".")!=0)
    strcpy(name,n);
     if(strcmp(desig,".")!=0)
    strcpy(designation,desig);
  if(strcmp(ad,".")!=0)
    strcpy(address,ad);
     if(strcmp(em,".")!=0)
    strcpy(email,em);
  if(se!=0)
    sex=se;
  if(strcmp(p,".")!=0)
     strcpy(mobno,p);
  if(sal!=0)
	ebasic=sal;

}
void employee::modify1()
{  int cuid;
   employee C3;
   char found='f';
   long pos;
  fstream ifile;
  ifile.open("employ.dat",ios::in|ios::out|ios::binary);
   if(!ifile)
   { cout<<"Unable to open file...";
     getch();
     exit(0);
   }
  cout<<"Enter the employee id to be modified:";
  cin>>cuid;
  while(ifile)
  { pos=ifile.tellg();
    ifile.read((char*)&C3,sizeof(C3));
    if(cuid==C3.retempid())
    {  C3.modify();
       ifile.seekg(pos);
       ifile.write((char*)&C3,sizeof(C3));
       found='t';
       break;
    }
  }
   if(found=='f')
     cout<<"Record not found...!";
     ifile.close();
}
void del()
{  employee e;
   int cid,flag=0;
   ifstream ifile;
   ifile.open("employ.dat",ios::binary);
   ofstream ofile;
   ofile.open("temp.dat",ios::binary);
   if(!ifile)
   { cout<<"Unable to open file....press any key to continue !";
     getch();
     exit(0);
   }
   cout<<"Enter The Employee id to be deleted:";
   cin>>cid;
   while( ifile.read((char*)&e,sizeof(e)))
   {

     if(cid==e.retempid())
      { flag=1;
	cout<<"Record deleted.....";
      }
     else
	ofile.write((char*)&e,sizeof(e));
   }
   if(flag==0)
    cout<<"Such a record does not exist..!";
   ifile.close();
   ofile.close();
   remove("employ.dat");
   rename("temp.dat","employ.dat");
}
void employee::display()
{       cout<<"\n\tEMPLOYEE DETAILS";
	cout<<"\n\t***************************";
	cout<<"\nEMPLOYEE ID:"<<empid;
	cout<<"\nEMPLOYEE NAME:"<<name;
	cout<<"\nEMPLOYEE DESIGNATION:"<<designation;
	cout<<"\nEMPLOYEE ADDRESS:"<<address;
	cout<<"\nEMPLOYEE EMAIL:"<<email;
	cout<<"\nEMPLOYEE SEX:"<<sex;
	cout<<"\nEMPLOYEE MOBILE NO:"<<mobno;
}
void employee::display1()
{
	cout<<"\n\t\t***************************************************";
	cout<<"\nEMPID"<<"\tNAME"<<"\tDESIGNATION"<<"\tADDRESS"<<"\tEMAIL"<<"\tSEX"<<"\tMOBNO"<<"\tSALARY";
	cout<<"\n"<<empid<<"\t"<<name<<"\t"<<designation<<"\t"<<address<<"\t"<<email<<"\t"<<sex<<"\t"<<mobno<<"\t"<<ebasic;
}
void employee::bio()
{       employee e;
	cout<<"\n\t\tADDING OF AN EMPLOYEE";
	cout<<"\n\t\t*****************************";
	cout<<"\nEnter Employee Id No:";
	cin>>empid;
	id(empid);
	cout<<"\nEnter Name:";
	gets(name);
	cout<<"Enter Designation:";
	gets(designation);
	cout<<"Enter Address:";
	gets(address);
	cout<<"Enter Email:";
	gets(email);
	cout<<"Enter Gender(m/f):";
	cin>>sex;
	cout<<"Enter Mobile Number:";
	gets(mobno);

}
void employee::mainmenu()
{
	employee e;
	int choice,id,flag=0;
	clrscr();
	do{
		cout<<"\n\t\t\tMAIN MENU";
		cout<<"\n\t\t***********************";
		cout<<"\n1.Employee Biodata";
		cout<<"\n2.Display";
		cout<<"\n3.Exit";
		cout<<"\n4.Display Individual";
		cout<<"\n5.SALARY SLIP";
		cout<<"\nEnter Your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: e.biomenu(); break;
			case 2: clrscr();
				cout<<"\n\n\t\t\tALL EMPLOYEE'S DETAILS";
				ifstream ifile;
				ifile.open("employ.dat",ios::binary);

				while(ifile.read((char*)&e,sizeof(e)))
				{
				  e.display1();
				  //e.dispsal();
				}
				ifile.close();
				  break;
			case 3: exit(0);
			case 4:

				ifstream file1;
				file1.open("employ.dat",ios::binary|ios::in);
				cout<<"\nenter employee id to be searched:";
				cin>>id;
				while(file1.read((char*)&e,sizeof(e)))
				{

					 if(id==e.retempid())
					      {	cout<<"RECORD FOUND";
						flag=1;
						e.display();
						e.dispsal();
						break;
					      }

				}
				if(flag==0)
					cout<<"\nThis employee does not exists!!";
				file1.close();   break;
			case 5: slip(); break;
			default: cout<<"\nWrong Choice!!";

		}




	  }while(choice!=3);
	  getch();
}
void employee::biomenu()
{

	int choice;
	employee e;
	do
	{
		cout<<"\n\t\tBIODATA MENU";
		cout<<"\n\t\t************************";
		cout<<"\n1.ADD";
		cout<<"\n2.BACK";
		cout<<"\n3.DELETE";
		cout<<"\n4.MODIFY";
		cout<<"\nEnter Your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: clrscr();
				ofstream file;

				file.open("employ.dat",ios::out|ios::binary|ios::app);
				if(!file)
				{
				cout<<"unable to open the file";
				exit(0);
				}
				else
				{
					e.bio();
					e.salary();
					file.write((char*)&e,sizeof(e));

				}


				file.close(); break;
			case 2: e.mainmenu();
				break;
			case 3: del();
				break;
			case 4: modify1();
				break;
			default: cout<<"Wrong Choice";



		}
	}while(choice!=2);

}
void main()
{           int a;
	clrscr();
	intro();
	clrscr();
	a=login();
	if(a!=-1)
	{
	employee e;

	e.mainmenu();  }

}


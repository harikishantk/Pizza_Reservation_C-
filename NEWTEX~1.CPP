#include<process.h>
#include <graphics.h>
#include<iomanip.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<fstream.h>
#include<iostream.h>
void add_to_cart();
void homepage();
float total=0;
int qty,price;
struct cart
{
 int code,qty;
 float price;
 char name[100];
};
class pizza
{
	int code;
	void calculate();

public:
	int qty;
	char type[100];
	char name[100];
	float mprice,sprice,lprice,price;
	void getdata();
	void showdata();
	void show_tabularp();
	void show_tabularbs();
	int retcode();
	float retsprice();
	float retlprice();
	float retmprice();
	char retname();


};


void pizza::calculate()   //the function used to calculate the large and smaal price of pizza.
{
   sprice=mprice-50;
   lprice=mprice+50;


}

void pizza::getdata()  //the function used to get the details such as name,code,type and basic price of pizza/beverages/starters and if it is pizza it would call calculate()
{       int ch;
	cout<<"\nEnter The type\n1.starter\n2.veg pizza\n3.non veg pizza\n4.beverages\n ";
	cin>>ch;
	switch(ch)
	{
	 case 1:strcpy(type,"starter");break;
	 case 2:strcpy(type,"veg pizza");break;
	 case 3:strcpy(type,"non veg pizza");break;
	 case 4:strcpy(type,"beverages");break;
	 default:cout<<"\a"; getdata();
	}
	cout<<"\n\nEnter The Name of  "<<type<<" :";
	gets(name);
	cout<<"\nEnter The basic price of "<<name<<" :";
	cin>>mprice;
	cout<<"\nenter the code";
	cin>>code;
	if((strcmpi(type,"veg pizza")==0)||(strcmpi(type,"non veg pizza")==0))
	 calculate();
}

void pizza::showdata() //the function used to show the details of pizza/starter/beverages
{       cout<<"\nCode:"<<code;
	cout<<"\nType:"<<type;
	cout<<"\nName of"<<type<< " : "<<name;
	cout<<"\nBasic price :"<<mprice;
	if((strcmpi(type,"veg pizza")==0)||(strcmpi(type,"non veg pizza")==0))
	{
	 cout<<"\nSmall price :"<<sprice;
	 cout<<"\nLarge price :"<<lprice;
       }
}
void pizza::show_tabularbs() //the function used to show the details the tabular way of starter/beverages.
{
	 cout<<code<<"  "<<name<<setw(20)<<mprice<<endl;
}
void pizza::show_tabularp() // the function used to show the details of pizza in the tabular way.
{
	cout<<code<<"  "<<name<<setw(20)<<sprice<<"\t  "<<mprice<<"\t  "<<lprice<<endl;
}
int pizza::retcode() // the function which used to return code.
{
 return code;
}
char pizza::retname() //the function which is used to return name
{
 return name[100];
}

void write_pizza(); //the function used to write the details by calling getdata() in pizzao.dat
void display_all(); //the function used to show the details
void display_sp(int);
void modify_pizza(int);
void delete_pizza(int);
void disp_pizzas();
void display();
void entry_menu();

void loading() //the function used for loading
{
 int gd=DETECT,gm=DETECT;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setbkcolor(MAGENTA);
 delay(100);
 getch();
 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,0,0);
 outtextxy(250,50,"LOADING");
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,BROWN);
 pieslice(300,250,0,60,150);
 setcolor(WHITE);
 setcolor(RED);
 circle(340,225,10);
 circle(420,218,10);
 circle(390,160,10);
 delay(500);
 setcolor(WHITE);
 pieslice(300,250,60,120,150);
 setcolor(RED);
 circle(270,135,10);
 circle(320,135,10);
 circle(300,200,10);
 delay(500);
 setcolor(WHITE);
 pieslice(300,250,120,180,150);
 setcolor(RED);
 circle(265,230,10);
 circle(180,220,10);
 circle(210,170,10);
 delay(500);
 setcolor(WHITE);
 pieslice(300,250,180,240,150);
 setcolor(RED);
 circle(190,280,10);
 circle(220,320,10);
 circle(270,270,10);
 delay(500);
 setcolor(WHITE);
 pieslice(300,250,240,300,150);
 setcolor(RED);
 circle(265,370,10);
 circle(320,370,10);
 circle(297,295,10);
 delay(500);
 setcolor(WHITE);
 pieslice(300,250,300,360,150);
 setcolor(RED);
 circle(410,270,10);
 circle(340,270,10);
 circle(390,330,10);
 delay(500);
 outtextxy(100,400,"Press any key to continue..");
 getch();
}
void admin_page() //the function which is used to show the menu of admin side which consists of display menu and entry/exit menu
{       loading();
	cleardevice();
	char ch;
	clrscr();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. DISPLAY MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1':display();
				break;
			case '2': entry_menu();
				break;
			case '3':homepage();
				 return;
			default :cout<<"\a";admin_page();
		}
	}while(ch!='3');

}



void write_pizza() //the function used to write the details of pizza in pizzao.dat
{
	pizza p;
	ofstream outfile;
	outfile.open("pizzao.dat",ios::binary|ios::app);
	p.getdata();
	outfile.write((char *) &p, sizeof(pizza));
	outfile.close();
	cout<<"\n\nHas Been Created ";
	getch();
}



void display_all() //the function used to display all the records present in pizzao.dat
{
	pizza p;
	ifstream z;
	z.open("pizzao.dat",ios::binary);
	if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(z.read((char *) &p, sizeof(pizza)))
	{
		p.showdata();
		cout<<"\n\n====================================\n";
	}
	z.close();
	getch();
}



void display_sp(int n) //the function which is used to show the details of specfic code
{
	pizza p;
	ifstream z;
	z.open("pizzao.dat",ios::binary);
	if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(z.read((char *) &p, sizeof(pizza)))
	{
		if(p.retcode()==n)
		{
			 p.showdata();
			 flag=1;
		}
	}
	z.close();
	if(flag==0)
		cout<<"\n\sorry not exist";
	getch();
}



void modify_pizza(int n) //the function used to modify the details of specific code
{
	int found=0;
	pizza p;
	fstream z;
	z.open("pizzao.dat",ios::binary|ios::in|ios::out);
	if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(z.read((char *) &p, sizeof(pizza)) && found==0)
	{
		if(p.retcode()==n)
		{
			p.showdata();
			cout<<"\n\nPlease Enter The New Details "<<endl;
			p.getdata();
			int pos=(-1)*sizeof(p);
			z.seekp(pos,ios::cur);
			z.write((char *) &p, sizeof(pizza));
			cout<<"\n\n\t details Updated";
			found=1;
		}
	}
	z.close();
	if(found==0)
		cout<<"\n\n Sorry Not Found ";
	getch();
}



void delete_pizza(int n) //the function used to delete the details of specific code
{
	pizza p;
	ifstream z;
	z.open("pizzao.dat",ios::binary);
	if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outz;
	outz.open("Temp.dat",ios::out);
	z.seekg(0,ios::beg);
	while(z.read((char *) &p, sizeof(pizza)))
	{
		if(p.retcode()!=n)
		{
			outz.write((char *) &p, sizeof(pizza));
		}
	}
	outz.close();
	z.close();
	remove("pizzao.dat");
	rename("Temp.dat","pizzao.dat");
	cout<<"\n\n\tDetails Deleted ..";
	getch();
}


void disp_pizzas() //the function used to display the pizzas in tabular way
{
	pizza p;
	ifstream z;
	z.open("pizzao.dat",ios::binary|ios::in);
	if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\t\tLIST OF PIZZAS \n\n";
	cout<<"============================================================\n";
	cout<<"Code          Name           S        M         L                  "<<endl;
	cout<<"============================================================\n";
	while(z.read((char*)&p,sizeof(pizza)))
	{       if((strcmpi(p.type,"veg pizza")==0)||(strcmpi(p.type,"non veg pizza")==0))
		p.show_tabularp();
	}
	getch();
	z.close();
}



void display() //the function which is used to show the display menu
{       char ch;
	int code;
	cout<<"\n\n\n\tDISPLAY MENU";
	cout<<"\n\n\n\t1.  DISPLAY ALL TYPES";
	cout<<"\n\n\t2. DISPLAY SPECIFIED CODE DETAILS";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1' :disp_pizzas(); break;
	case '2' :cout<<"\n\n\tEnter Code Of Pizza : ";
		  cin>>code;
		  display_sp(code); break;
	case '3' :break;
	default :cout<<"\a";
	}
}



void bill() //the function used to calculate the total and show up the bill
{
 pizza p;
 cart c;
 int gd=DETECT,gm=DETECT;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 ifstream y;
  y.open("carto.dat",ios::binary);
 if(!y)
 {
  cout<<"\nfile not found!! Press any key../\n";
  getch();
  return;
 }

 int code;
 char name[100];
 setbkcolor(LIGHTRED);
 setcolor(MAGENTA);
 settextstyle(GOTHIC_FONT,0,5);
 outtextxy(200,0,"CLUCKIN'BELL");
 setlinestyle(DOTTED_LINE,0,0);
 setcolor(RED+BLINK);
 rectangle(-1,50,650,400);
 line(-1,100,650,100);
 rectangle(0,100,350,400);
 gotoxy(50,8);
 cout<<"TOTAL=";
 gotoxy(65,8);
 cout<<setw(6)<<total;
 gotoxy(50,10);
 cout<<"SERVICE tax=  +20.50";
 gotoxy(50,12);
 cout<<"VAT tax=      +60.70";
 gotoxy(50,14);
 cout<<"TOTAL=";
 gotoxy(65,14);
 total+=20.50+60.50;
 cout<<setw(10)<<total;
 settextstyle(SANS_SERIF_FONT,0,0);
 outtextxy(200,50," YOUR BILL");
 gotoxy(1,8);
 cout<<" Code          Item        Qty      Price                  "<<endl;
 while(y.read((char*)&c,sizeof(cart)))
 {
   cout<<c.code<<setw(20)<<c.name<<"\t"<<c.qty<<"\t"<<c.price<<endl;
  }
 y.close();
 remove("carto.dat");
 getch();
}

void customer() //the function used to enter the choice of selecting starter/veg pizza/non veg pizza by showing up menu. then if the choice is choosen , then the specific type details would be shown
 {
   int f;
   char k,a;
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgI");
   setbkcolor(YELLOW);
   setcolor(CYAN);
   setfillstyle(SOLID_FILL,CYAN);
   rectangle(0,0,639,100);
   floodfill(100,10,CYAN);
   settextstyle(SANS_SERIF_FONT,0,0);
   setcolor(MAGENTA);
   outtextxy(160,110,"WELCOME CUSTOMER!!");
   setcolor(LIGHTRED);
   outtextxy(170,160,"ENTER YOUR CHOICE");
   for(int i=100;i<500;i++)
   for(int j=200;j<240;j++)
   putpixel(i,j,BROWN);
   for(i=100;i<500;i++)
   for(j=250;j<290;j++)
   putpixel(i,j,LIGHTGREEN);
   for(i=100;i<500;i++)
   for(j=300;j<340;j++)
   putpixel(i,j,LIGHTRED);
   for(i=100;i<500;i++)
   for(j=350;j<390;j++)
   putpixel(i,j,LIGHTBLUE);
   setcolor(RED);
   settextstyle(GOTHIC_FONT,0,8);
   outtextxy(0,0,"CLUCKIN' BELL");
   settextstyle(SANS_SERIF_FONT,0,0);
   outtextxy(240,200,"1.STARTER");
   setcolor(GREEN);
   outtextxy(220,250,"2.VEG PIZZAS");
   setcolor(RED);
   outtextxy(180,300,"3.NON VEG PIZZAS");
   setcolor(BLUE);
   outtextxy(230,350,"4.BEVERAGES");
   cin>>f;
   setbkcolor(LIGHTRED);
   pizza p;
   ifstream z;
   z.open("pizzao.dat",ios::binary);
   z.seekg(0,ios::beg);
   delay(300);
   cleardevice();
   setbkcolor(LIGHTBLUE);
   setcolor(YELLOW+BLINK);
   rectangle(30,40,600,400);
     if((f==1))
    {
      if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\t\t\t\tLIST OF STARTERS \n\n";
	cout<<"\t============================================================\n";
	cout<<"\tCode          Name          PRICE              "<<endl;
	cout<<"\t============================================================\n\t";
	while(z.read((char *) &p, sizeof(p)))
	{     if(strcmpi(p.type,"starter")==0)
		p.show_tabularp();
	}
		z.close();

    }
    else if((f==2))
    {
      if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\t\t\t\tLIST OF PIZZAS \n\n";
	cout<<"\t============================================================\n";
	cout<<"\tCode          Name          S       M        L                  "<<endl;
	cout<<"\t============================================================\n\t";
	while(z.read((char *) &p, sizeof(pizza)))
	{     if(strcmpi(p.type,"veg pizza")==0)
		p.show_tabularp();
	}
	z.close();

    }
    else if((f==3))
    {
      if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\t\t\t\tLIST OF PIZZAS \n\n";
	cout<<"\t============================================================\n";
	cout<<"\tCode          Name          S       M        L                  "<<endl;
	cout<<"\t============================================================\n\t";
	while(z.read((char *) &p, sizeof(pizza)))
	{     if(strcmpi(p.type,"non veg pizza")==0)
		p.show_tabularp();
	}
		z.close();

    }
    else if(f==4)
    {
      if(!z)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\t\t\t\tLIST OF PIZZAS \n\n";
	cout<<"\t============================================================\n";
	cout<<"\tCode          Name          PRICE              "<<endl;
	cout<<"\t============================================================\n\t";
	while(z.read((char *) &p, sizeof(pizza)))
	{     if(strcmpi(p.type,"beverages")==0)
		p.show_tabularbs();
	}
		z.close();
    }


    outtextxy(10,400,"press left arrow for back");
    outtextxy(10,430,"press up arrow to add to cart");
    a=getch();
   switch(a)
   {
    case 0:{
	    k=getch();
	    switch(k)
	    {                                    //72-up
	     case 75:customer();                 //80-down
		     break;                      //75-left						 //77-right
	     case 72:add_to_cart();
		     break;
	    }break;
	   }
   }
    getch();
   }
void add_to_cart() //the function which is used to add the details from customer such as code,name,quantity and price and add it to pizzao.dat
{
 int gd=DETECT,gm=DETECT;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 pizza p;
 int flag;
 cart c;
 char ch,k;
 int code,pos,f;
 ofstream y("carto.dat",ios::binary|ios::app);
 setbkcolor(RED);
 setcolor(MAGENTA);
 do
 {
  ifstream x;
  x.open("pizzao.dat",ios::binary);
  cout<<"\nEnter the code";
  cin>>code;
  cout<<"\nHow many of it?";
  cin>>qty;
  while(x.read((char *) &p, sizeof(pizza)))
  {
	if(p.retcode()==code)
			{
			 p.showdata();
			 c.code=p.retcode();
			 c.qty=qty;
			 strcpy(c.name,p.name);
			 if((strcmpi(p.type,"veg pizza")==0)||(strcmpi(p.type,"non veg pizza")==0))
			 {
			  label:
			  cout<<"\nWhich one do u prefer?(S/M/L)";
			  cin>>ch;
			  switch(ch)
			  {
			   case 's':
			   case 'S':
				    c.price=p.sprice;
				    total+=c.price*c.qty;
				   break;
			   case 'L':
			   case 'l':
				    c.price=p.lprice;
				    total+=c.price*c.qty;
				   break;
			   case 'm':
			   case 'M':
				    c.price=p.mprice;
				    total+=c.price*c.qty;
				   break;
			   default:
				  cout<<"\nEnter S/L/M or s/l/m please\n";
				  goto label;
			  }
			 }
			 else
			  {
			   c.price=p.mprice;
			   total+=c.price*c.qty;
			   cout<<"\nThe"<<p.name<<"has been added\n";
			  }
			   flag=1;
			   y.write((char*)&c,sizeof(cart));
			}

  }
  x.close();
	if(flag==0)
		cout<<"\nSorry not exist";
  cout<<"\nDo you want to add some more?(y/n))";
  cin>>ch;
 }while(ch=='y'||ch=='Y');


 y.close();
 cout<<"\nIf you want to checkout,press down arrow for bill\nIf you want to see other codes just press for left arrow";
 ch=getch();
   switch(ch)
   {
    case 0:{
	    k=getch();
	    switch(k)
	    {
	     case 75:customer();                 //80-down
		     break;                      //75-left
	     case 80:bill();                     //77-right
		     break;
	    }break;
	   }
   }
 getch();
}



void entry_menu() //the function which is used to show the entry/edit menu of admin side
{       char ch;
	int code;
	clrscr();
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE NEW PIZZA";
	cout<<"\n\n\t2.DISPLAY ALL PIZZA DETAILS";
	cout<<"\n\n\t3.SEARCH PIZZA DETAIL ";
	cout<<"\n\n\t4.MODIFY PIZZA DETAIL";
	cout<<"\n\n\t5.DELETE PIZZA DETAIL";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1':	write_pizza(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The code "; cin>>code;
			display_sp(code); break;
	case '4':	cout<<"\n\n\tPlease Enter The code "; cin>>code;
			modify_pizza(code);break;
	case '5':	cout<<"\n\n\tPlease Enter The code "; cin>>code;
			delete_pizza(code);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}
void homepage() //the function which is used to show up the first page of project which consist of selecting the choice between admin/customer.
{

 int f;
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "c:\\tc\\bgI");
 setfillstyle(SOLID_FILL,BROWN);
 pieslice(150,100,0,270,50);
 setbkcolor(RED);
 settextstyle(SANS_SERIF_FONT,0,0);
 setcolor(WHITE);
 outtextxy(200,95,"WELCOME TO CLUCKIN'BELL");
 int i,j;
 for(i=200;i<390;i++)
 for(j=200;j<230;j++)
 putpixel(i,j,YELLOW);
 settextstyle(SANS_SERIF_FONT,0,0);
 setcolor(RED);
 outtextxy(230,195,"1.ADMIN");
 i=0,j=0;
 for(i=200;i<390;i++)
 for(j=250;j<280;j++)
 putpixel(i,j,YELLOW);
 outtextxy(200,240,"2.CUSTOMER");
 setcolor(YELLOW);
 cin>>f;
  if((f==1))
    {
      delay(300);
      cleardevice();
      admin_page();
    }
  else if((f==2))
    {
     delay(300);
     cleardevice();
     customer();
    }
}
void main() //the function which used to call homepage() and laoding()
{
 clrscr();
 loading();
 homepage();
 getch();
}


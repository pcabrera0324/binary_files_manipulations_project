#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const int size=1;

struct Student{
	char name[51];
	char lname[51];
	char mi;
	int g1;
	int g2;
	int g3;
	float avg;
	
};
 
 
 
 
 
void menu(int&,bool&,int&);
void create(int&,bool&,int&);
void check(int&,bool&,int&);
void addnew(int&,bool&,int&);
void view(int&,bool&,int&);
void x(bool&);
void wiping(int&,bool&,int&);
void searchbyname(int&,bool&,int&);
void searchbylname(int&,bool&,int&);
void seach(int&,bool&,int&);
void deletee(int&,bool&,int&);
void modify(int&,bool&,int&);
void appending(int&,bool&,int&);
void sorting(int&,bool&,int&);










int main(int argc, char** argv) {
	
	

	int option=0;
	int aa=0;
	bool oo=false;
x(oo);

	

 
	menu(option,oo,aa);
	
	
	return 0;
}


void menu(int&option,bool&oo,int&aa){
	
	
	do {

		
		cout << "\n:::::::::MENU:::::::::::::::" << endl;
	cout << "1) Create a Binay file" << endl;
	cout << "2) Check if the Binary file exitst" << endl;
	cout << "3) Register a new student"<< endl;
	cout << "4) View students Registered" << endl;
	cout << "5) Append a record to the file" << endl;
	cout << "6) Find a specific student" << endl;
	cout << "7) Delete a registered student" << endl;
	cout << "8) Modify a specific student" << endl;
	cout <<"9)Sort" << endl;

	cout << "10) Wipe out the content" << endl;
	cout << "102) Exit\n" <<  endl;
	cin >> option;
	
	switch(option)
	{
		case 1:
			create(option,oo,aa);
			break;
		case 2:check(option,oo,aa);
			break;
		case 3:addnew(option,oo,aa);
			break;
		case 4:view(option,oo,aa);
			break;
		case 5:appending(option,oo,aa);
			break;
		case 6:seach(option,oo,aa);
			break;
		case 10:wiping(option,oo,aa);
			break;
		case 7:deletee(option,oo,aa);
			break;
		case 8:modify(option,oo,aa);
			break;
	 	case 9: sorting(option,oo,aa);
	 	break;
		
		case 102: exit(0);
			break;
		
		
	
		
	}
	
	} while (option!=102);
	
}



 void create(int&option,bool&oo,int&aa){
 	ofstream myfile;
 	myfile.open("binaryfile.dat",ios::binary | ios::out);


 	if(myfile.fail())
 	{
 		cout << "Sorry can't open the file" << endl;
 	
	 }  else 
	 
	 {
	
	 

	 		cout << endl <<  "File has been successfully created" << endl;
 		myfile.close();
 	 cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	 }
  }
  
void check(int&option,bool&oo,int&aa)
{
	x(oo);
	
if(oo)
{
	cout << "File exist" << endl;
	

} else 
{
	cout << "file does not exist" << endl;
	
	 cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
}

 }
 
 void addnew(int&option,bool&oo,int&aa)
 {
 	x(oo);
 	char key;
 	
 	
 	if(oo)
 	{
 		
 		ofstream myfile;
 	myfile.open("binaryfile.dat",ios::binary | ios::app);
 	
  Student mystudent;
 
  cout << ":::::::::ADDING RECORD:::::::::::::::" << endl;
  cout << "Name: ";
  cin >> mystudent.name;
  cout << "LastName: ";
  cin >> mystudent.lname;
  cout <<"MI ";
  cin >> mystudent.mi;
  cout << "G1: ";
  cin >> mystudent.g1;
   cout << "G2: ";
  cin >> mystudent.g2;
   cout << "G3: ";
  cin >> mystudent.g3;
  
   mystudent.avg=(mystudent.g1+mystudent.g2+mystudent.g3)/3;
   
myfile.write((char*)&mystudent,sizeof(mystudent));
	
	 myfile.close();
	 
	  cout << "would you like to add another student[Y/N]" << endl;
	  cin >> key;
	  
	   if(key=='Y')
	   {
	   	aa++;
	   	addnew(option,oo,aa);
	   } else if(key=='N')
	   {
	   	menu(option,oo,aa);
	   }
 		
	 }  else 
	 
	 {
	 	cout << "Cant add a student without create a file" << endl;
	 		
	
	 cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	 }
 	
	
	
 	 	
	  
 	 
}

void view(int&option,bool&oo,int&aa)
{
	 x(oo);
	 if(oo)
	 {
	 	Student mystudent;
	 	ifstream myfile;
 	myfile.open("binaryfile.dat", ios::binary);
 	
	
	

		cout << "       :::::::::STUDENTS IN RECORD:::::::::::::::\n" << endl;
	
	cout << "name" << setw(10) << "LastName" << setw(10) << "MI" << setw(10) << 
	"G1" << setw(10) << "G2" << setw(10) << "G3" <<setw(10) << "AVG" << endl;

	 
	  
	  while(myfile.read((char*)&mystudent,sizeof(mystudent))){
	  		
	  		cout << mystudent.name << setw(10) << mystudent.lname << setw(10) << setw(10) << mystudent.mi << setw(10) << 
	  		mystudent.g1 << setw(10) << mystudent.g2 << setw(10) << mystudent.g3 << setw(10) << mystudent.avg << endl;
	  	
	  			
		  }
	
	
	myfile.close();
	
	 } else 
	 {
	 		cout << "Cant view a without create a file" << endl;
	 		
	
	 cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	 }
	
}

void x(bool&oo)
{	fstream myfile("binaryfile.dat");
	
if(myfile)
{
	
	oo=true;
	myfile.close();
	
	
} else 
{
	oo=false;
	myfile.close();
}
}

void wiping(int&option,bool&oo,int&aa){
	
	 if(oo)
	 {
	 	fstream myfile;
	myfile.open("binaryfile.dat",ios::out | ios::trunc);
	myfile.close();
	cout << ":::::::::WIPPING OUT THE FILE:::::::::::::::" << endl;
	 cout << "File has been wipe out succesfully" << endl;
	 } else 
	 {
	 	cout <<"we cant clear your file because file does not exist" << endl;
	 	cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	 	
	 }
}

void searchbyname(int&option,bool&oo,int&aa) {
	
	 if(oo)
	 {
	 	
	 	string studentwanted;
	Student mystudent;
	ifstream myfile;
	cout << "Name to find: ";
	cin>> studentwanted;
	
	myfile.open("binaryfile.dat",ios::binary);
	while(myfile.read((char*)&mystudent,sizeof(mystudent)))
	{
		if(mystudent.name==studentwanted)
			{
				 cout << "::::::::: FOUND RECORD:::::::::::::::\n" << endl;
				cout << "Name" << setw(10) << "LastName" << setw(10) << "MI" << setw(10) << 
	"G1" << setw(10) << "G2" << setw(10) << "G3" <<setw(10) << "AVG" << endl; 
		cout << mystudent.name << setw(10) << mystudent.lname << setw(10) << setw(10) << mystudent.mi << setw(10) << 
	  		mystudent.g1 << setw(10) << mystudent.g2 << setw(10) << mystudent.g3 << setw(10) << mystudent.avg << endl;
	  	
	
			} else  if (mystudent.name!=studentwanted)
			{ 
			cout << " " << endl;
			}
	}
	myfile.close();
	 	
	 } else 
	 {
	 
	cout <<"we cant find  because file does not exist" << endl;
	 	cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	
}
}

void searchbylname(int&option,bool&oo,int&aa) {
	
		 if(oo)
	 {
	 	
	 	string studentwanted;
	Student mystudent;
	ifstream myfile;
	cout << "LastName to find: ";
	cin>> studentwanted;
	
	myfile.open("binaryfile.dat",ios::binary);
	while(myfile.read((char*)&mystudent,sizeof(mystudent)))
	{
		if(mystudent.lname==studentwanted)
			{
				 cout << ":::::::::FOUND RECORD:::::::::::::::\n" << endl;
				cout << "Name" << setw(10) << "LastName" << setw(10) << "MI" << setw(10) << 
	"G1" << setw(10) << "G2" << setw(10) << "G3" <<setw(10) << "AVG" << endl; 
		cout << mystudent.name << setw(10) << mystudent.lname << setw(10) << setw(10) << mystudent.mi << setw(10) << 
	  		mystudent.g1 << setw(10) << mystudent.g2 << setw(10) << mystudent.g3 << setw(10) << mystudent.avg << endl;
	  	
	
			} else  if (mystudent.lname!=studentwanted)
			{ 
			cout << " " << endl;
			}
	}
	myfile.close();
	 	
	 } else 
	 {
	 
	cout <<"we cant find  because file does not exist" << endl;
	 	cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	
}
	
	
	
}

void seach(int&option,bool&oo,int&aa) 
{
	 cout << ":::::::::SEARCH FOR A STUDENT:::::::::::::::" << endl;
	cout << "1)Search Student by name" << endl;
	cout << "2)Search Student by Lname" << endl;
	cin >> option;
	
	 switch(option)
	 {
	 	case 1: searchbyname(option,oo,aa);
	 	break;
	 	case 2: searchbylname(option,oo,aa);
	 	break;
	 }
}

void deletee(int&option,bool&oo,int&aa)
{
string studentwant;
Student mystudent;
cout << "Name of record to delete: ";
cin >> studentwant;
ifstream myfile;
myfile.open("binaryfile.dat",ios::binary);
ofstream myfile2;
myfile2.open("temp.dat",ios::out| ios::binary);
while(myfile.read((char*)&mystudent,sizeof(mystudent)))
{
	 	if(studentwant.compare(mystudent.name))
	 	  {
	 	  mystudent.name==NULL;
	 	  	myfile2.write((char*)&mystudent,sizeof(mystudent));
	 	  
		   }
		   
		  
}
 myfile.close();
 myfile2.close();

 remove("binaryfile.dat");
 rename("temp.dat","binaryfile.dat");
		  


	
}
	
	




void modify(int&option,bool&oo,int&aa)
{


if(oo)
	 {
	 	 int found=0;
	 	
	 	string studentwanted;
	Student mystudent;
	fstream myfile;
	cout << "Name to find: ";
	cin>> studentwanted;
	
	myfile.open("binaryfile.dat",ios::binary | ios::in | ios::out);
	while(myfile.read((char*)&mystudent,sizeof(mystudent)) && found==0)
	{
		if(mystudent.name==studentwanted)
			{
				 cout << "::::::::: FOUND RECORD:::::::::::::::\n";
				cout << "Name" << setw(10) << "LastName" << setw(10) << "MI" << setw(10) << 
	"G1" << setw(10) << "G2" << setw(10) << "G3" <<setw(10) << "AVG" << endl; 
		cout << mystudent.name << setw(10) << mystudent.lname << setw(10) << setw(10) << mystudent.mi << setw(10) << 
	  		mystudent.g1 << setw(10) << mystudent.g2 << setw(10) << mystudent.g3 << setw(10) << mystudent.avg << endl;
	  		
	  		
	  		mystudent.avg==0;
	  		
	  		
	  		cout << "\n::::::::ENTER NEW DATA::::::::" << endl;
   cout << "Name: ";
  cin >> mystudent.name;
  cout << "LastName: ";
  cin >> mystudent.lname;
  cout <<"MI ";
  cin >> mystudent.mi;
  cout << "G1: ";
  cin >> mystudent.g1;
   cout << "G2: ";
  cin >> mystudent.g2;
   cout << "G3: ";
  cin >> mystudent.g3;
  
  mystudent.avg=(mystudent.g1+mystudent.g2+mystudent.g3)/3;
  
  int x=-1*sizeof(mystudent);
  myfile.seekp(x,ios::cur);
  
  myfile.write((char*)&mystudent,sizeof(mystudent));
  found=1;
myfile.close();	
	  		
	  		
	  	
	
			} else  if (mystudent.name!=studentwanted)
			{ 
			mystudent.name==NULL;
			}
	}
	myfile.close();
	 	
	 } else 
	 {
	 
	cout <<"we cant find  because file does not exist" << endl;
	 	cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	
}

}

void appending(int&option,bool&oo,int&aa)
{
	
	x(oo);
 	char key;
 	
 	
 	if(oo)
 	{
 		
 		ofstream myfile;
 	myfile.open("binaryfile.dat",ios::binary | ios::app);
 	
  Student mystudent;
  cout << ":::::::::ADDING RECORD[APPENDING MODE]:::::::::::::::" << endl;
  cout << "Name: ";
  cin >> mystudent.name;
  cout << "LastName: ";
  cin >> mystudent.lname;
  cout <<"MI ";
  cin >> mystudent.mi;
  cout << "G1: ";
  cin >> mystudent.g1;
   cout << "G2: ";
  cin >> mystudent.g2;
   cout << "G3: ";
  cin >> mystudent.g3;
  
   mystudent.avg=(mystudent.g1+mystudent.g2+mystudent.g3)/3;
   
myfile.write((char*)&mystudent,sizeof(mystudent));
	
	 myfile.close();
	 
	  cout << "would you like to add another student[Y/N]" << endl;
	  cin >> key;
	  
	   if(key=='Y')
	   {
	   	aa++;
	   	addnew(option,oo,aa);
	   } else if(key=='N')
	   {
	   	menu(option,oo,aa);
	   }
 		
	 }  else 
	 
	 {
	 	cout << "Cant add a student without create a file" << endl;
	 		
	
	 cout << endl << "PRESS 101 TO RETURN TO MAIN MENU OR 102 TO EXIT" << endl;
 	 cin >> option;
 	  if(option==101)
 	  {
 	  	menu(option,oo,aa);
	   } else 
	   {
	   	exit(0);
	   }
	
	
	
}}


void sorting(int&option,bool&oo,int&aa)
{
	Student dummy;
	fstream countfile;
	countfile.open("binaryfile.dat",ios::binary  | ios::in);
	int count = 0;
	
	while(countfile.read((char*)&dummy,sizeof(dummy)))
	{
		count++;
	}
	Student mystudents[count];
	countfile.close();
	
	fstream myfile;
	myfile.open("binaryfile.dat",ios::binary  | ios::in);

	
	string names[count];
	string lname[count];

	for(int i=0;i<count;i++)
	{
		myfile.read((char*)&mystudents,sizeof(mystudents));
	 names[i]=mystudents[i].name;
	lname[i]=mystudents[i].lname;
	 
	 
		
	}
	
for (int i = 1; i < count; i++)
    {
        for (int a = 0; a < count - i; a++)
            if (names[a] > names[a + 1])
            {
                string temp=names[a];
                names[a]=names[a+1];
                names[a+1]=temp;
            }
           
    }
    
    
        	cout << "       :::::::::NAMES SORTED ALPHABETICALLY:::::::::::::::\n" << endl;
	
	cout << "[name]" << endl;
	cout << endl;
	
	for (int i=0;i<count;i++)
	 {
	 	
	 	cout << names[i] << endl;
	 	
	 
	 	

		   
		   
	  	
	 	
	 }
	 
	 
	  myfile.close();
 
	 
	 
	 
	
}


    
    
    

    
    
    
    
    












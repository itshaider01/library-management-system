#include<iostream>
#include<string>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct database
{
	int a = 10;
	int b = 15;
	string books[20] = {
		"Rich Dad Poor Dad", "Zero to One", "How to have Creative Ideas",
		"Diary of a Wimpy Kid", "How to Negotiate", "Crushing it",
		"The 4-Hour Workweek", "Hamlet", "War & Peace", "The 80/20 Principle"
	};
	string serial[20] = { "00","11","22","33","44","55","66","77","88","99" };
	string lentbooks[30];
	string lentserial[30];
	string studentid[30];
	string studentName[30];
	string byEmployee[30];
	int copies[20] = { 1,2,2,1,1,2,1,2,2,1 };
	int totalCopies = 0;
	string days[30];
	string user = "";
};

void loginScreen(database db);
void portalScreen(database db);
void chooseOption(database db);
void inventory(database db);
void bookReturn(database db);
void genSlip(database db);
void lentBooks(database db);
void newBook(database db);
void goBack(database db);
string getName(string);
void exitScreen();
void loading();

int main()
{
	database db;
	system("mode 650");
	for (int i = 0; i < 30; i++)
	{
		db.lentbooks[i] = "";
		db.lentserial[i] = "  ";
		db.studentid[i] = "  ";
		db.studentName[i] = "        ";
		db.byEmployee[i] = "  ";
	}
	for (int i = 0; i < 10; i++)
	{
		db.totalCopies += db.copies[i];
	}
	loginScreen(db);
	return 0;
}

void loginScreen(database db)
{

	loading();
	const string id1 = "u1", id2 = "u2";
	string userId;
	const string pass1 = "alpha", pass2 = "bravo";
	string userPass;
	cout << "\t\t\t\t\t\t\t___________________________" << endl << endl;
	cout << "\t\t\t\t\t\t\t|Library Management System|" << endl << endl;
	cout << "\t\t\t\t\t\t\t---------------------------" << endl << endl;
	cout << "\t\t\t\t\t\t\t\tLog in Screen" << endl << endl;
	for (int i = 0; userId != id1 && userId != id2; i++)
	{
		cout << "ID: ";
		cin >> userId;
		if (userId != id1 && userId != id2)
		{
			cout << "NO Such Id found!" << endl;
		}
	}
	if (userId == id1)
	{
		for (int i = 0; userPass != pass1; i++)
		{
			cout << "Pass: ";
			cin >> userPass;

			if (userPass != pass1)
			{
				cout << "Wrong Password" << endl;
			}
		}
		cout << "Login of Employee ID User 1 Succussful!" << endl;
		db.user = "u1";
		portalScreen(db);
	}
	else if (userId == id2)
	{
		for (int i = 0; userPass != pass2; i++)
		{
			cout << "Pass: ";
			cin >> userPass;
			if (userPass != pass2)
			{
				cout << "Wrong Password" << endl;
			}
		}
		cout << "Login of Employee ID User 2 Succussful!" << endl;
		db.user = "u2";
		portalScreen(db);
	}
}

void portalScreen(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\tWelcome to Employee Portal!" << endl << endl << endl;
	cout << "|1.Inventory|    ";
	cout << "|2.Book Return|    ";
	cout << "|3.Generate Slip|    ";
	cout << "|4.Amount of lent Books|    ";
	cout << "|5.Add New Book|    ";
	cout << "|6.Change User|    ";
	cout << "|7.Exit|";
	chooseOption(db);
}

void chooseOption(database db)
{

	string option = "0";
	Sleep(0700);
	cout << endl << endl << "Choose Option Number: ";
	cin >> option;
	if (option == "1")
	{
		option = "0";
		inventory(db);
	}
	else if (option == "2")
	{
		option = "0";
		bookReturn(db);
	}
	else if (option == "3")
	{
		option = "0";
		genSlip(db);
	}
	else if (option == "4")
	{
		option = "0";
		lentBooks(db);
	}
	else if (option == "5")
	{
		option = "0";
		newBook(db);
	}
	else if (option == "6")
	{
		option = "0";
		loginScreen(db);
	}
	else if (option == "7")
	{
		option = "0";
		exitScreen();
	}
	else
	{
		option = "0";
		cout << "Wrong option!";
		chooseOption(db);
	}
}

void inventory(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\t\t___________" << endl;
	cout << "\t\t\t\t\t\t\t\t|Inventory|" << endl;
	cout << "\t\t\t\t\t\t\t\t-----------" << endl << endl;
	cout << "This is the inventory:" << endl << endl;
	cout << "#  \t|\tSerial No. \t|\tCopies \t\t|\t Books" << endl << endl;
	for (int i = 0; i < db.a; i++)
	{
		cout << i + 1 << ". \t|\t   " << db.serial[i] << "\t\t|\t   " << db.copies[i] << "\t\t|\t " << db.books[i] << endl;
	}
	goBack(db);
}

void bookReturn(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\t\t_____________" << endl;
	cout << "\t\t\t\t\t\t\t\t|Book Return|" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------" << endl << endl;
	string userSerial;
	string CheckID;
	bool checkSerial = 0;
	cout << "Return a book from here:" << endl << endl;
	cout << "Serial number of book: ";
	cin >> userSerial;

	for (int i = 0; i < db.a; i++)
	{
		if (userSerial == db.lentserial[i])
		{
			checkSerial = 1;
			if (db.lentserial[i] != "  ")
			{
				cout << "Student ID: ";
				cin >> CheckID;
				if (CheckID == db.studentid[i])
				{
					db.books[i] = db.lentbooks[i];
					db.lentserial[i] = "  ";
					db.lentbooks[i] = "";
					db.studentName[i] = "        ";
					db.studentid[i] = "  ";
					db.byEmployee[i] = "  ";
					db.days[i] = "  ";
					db.copies[i]++;
					break;
				}
				else {
					cout << "Wrong Student ID!";
				}
			}
			else
			{
				cout << "Book not lent yet!" << endl;

			}
		}
	}
	if (checkSerial == 0)
	{
		cout << "Wrong Serial!" << endl;
	}
	goBack(db);
}

void genSlip(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\t\t_______________" << endl;
	cout << "\t\t\t\t\t\t\t\t|Generate Slip|" << endl;
	cout << "\t\t\t\t\t\t\t\t---------------" << endl << endl;
	string userName;
	string userSerial;
	bool checkSerial = 0;
	cout << "Generate a Slip from here:" << endl << endl;
	cout << "Serial number of book: ";
	cin >> userSerial;
	for (int i = 0; i < db.a; i++)
	{
		if (userSerial == db.serial[i])
		{
			checkSerial = 1;
			if (db.copies[i] > 0)
			{
				db.copies[i]--;
				for (int j = 0; j < db.b; j++)
				{
					if (db.lentbooks[j] == "")
					{
						cout << "Student Name:";
						cin.ignore();
						userName = getName(userName);
						db.studentName[j] = userName;
						cout << "Student ID:";
						cin >> db.studentid[j];
						cout << "Days:";
						cin >> db.days[j];
						for (int k = 0; db.days[j] != "1" && db.days[j] != "2" && db.days[j] != "3" && db.days[j] != "4" && db.days[j] != "5" && db.days[j] != "6" && db.days[j] != "7" && db.days[j] != "8"; k++)
						{
							cout << "You can only lend the book for maximum 8 days!";
							cout << endl << "Days:";
							cin >> db.days[j];
						}
						db.lentbooks[j] = db.books[i];
						db.lentserial[j] = db.serial[i];
						if (db.user == "u1")
						{
							db.byEmployee[j] = "u1";
						}
						else if (db.user == "u2")
						{
							db.byEmployee[j] = "u2";
						}
						break;
					}
				}
				if (db.copies[i] == 0)
				{
					db.books[i] = "Not Available";
				}
				break;
			}
			else
			{
				cout << endl << "Book not available" << endl;
				for (int j = 0; j < db.b; j++)
				{
					if (userSerial == db.lentserial[j])
					{
						cout << endl << "The book is with: " << db.studentName[j] << endl << "Student Id: " << db.studentid[j] << endl << "For " << db.days[j] << " days!" << endl << endl;
					}
				}
			}
		}
	}
	if (checkSerial == 0)
	{
		cout << "Wrong Serial!";
	}
	goBack(db);
}

void lentBooks(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\t\t____________" << endl;
	cout << "\t\t\t\t\t\t\t\t|Lent Books|" << endl;
	cout << "\t\t\t\t\t\t\t\t------------" << endl << endl;
	cout << "This is the amount of books lent to students:" << endl << endl;
	cout << "#  \t| Serial No. \t| Student Name  \t| Student ID\t| By Employee \t| Days \t\t| Books" << endl << endl;
	for (int i = 0; i < db.totalCopies; i++)
	{
		cout << i + 1 << ". \t| " << db.lentserial[i] << "\t\t| " << db.studentName[i] << " \t\t| " << db.studentid[i] << "\t\t| " << db.byEmployee[i] << "\t\t| " << db.days[i] << "\t\t| " << db.lentbooks[i] << endl;
	}
	goBack(db);
}

void newBook(database db)
{
	loading();
	cout << "\t\t\t\t\t\t\t\t__________" << endl;
	cout << "\t\t\t\t\t\t\t\t|New Book|" << endl;
	cout << "\t\t\t\t\t\t\t\t----------" << endl << endl;
	string bookName;
	bool checkSerial = 0;
	cout << "Add a new book from here:" << endl << endl;
	cout << "Name of the book: ";
	cin.ignore();
	bookName = getName(bookName);
	db.books[db.a] = bookName;
	cout << "Serial of the book: ";
	cin >> db.serial[db.a];
	for (int i = 0; checkSerial == 0; i++)
	{
		for (int j = 0; j < db.a; j++)
		{
			if (db.serial[db.a] == db.serial[j])
			{
				cout << "Serial already assigned!" << endl;
				cout << "Serial of the book: ";
				cin >> db.serial[db.a];
				checkSerial = 0;
				break;
			}
			else
			{
				checkSerial = 1;
			}
		}
	}
	cout << "Number of copies: ";
	cin >> db.copies[db.a];
	db.b += db.copies[db.a];
	db.totalCopies += db.copies[db.a];
	db.a++;
	goBack(db);
}
void goBack(database db)
{
	string back;
	cout << endl << "Want to go back?(y/n): ";
	cin >> back;
	for (int i = 0; back != "Y" && back != "y"; i++)
	{
		if (back == "N" || back == "n")
		{
			cout << "How about now?:";
			cin >> back;
		}
		else
		{
			cout << "You've got to say \"y\" or \"n\"";
			cout << endl << "Want to go back?";
			cin >> back;
		}
	}
	if (back == "Y" || back == "y")
	{
		portalScreen(db);
	}

}

string getName(string name)
{
	getline(cin, name);
	return name;
}

void loading()
{
	cout << endl << endl << endl << "\t\t\t\t\t\t\t\tLoading";
	Sleep(0700);
	cout << ".";
	Sleep(0700);
	cout << ".";
	Sleep(0700);
	cout << ".";
	system("CLS");
}

void exitScreen()
{
	system("CLS");
	cout << endl << endl << endl << "\t\t\t\t\t\t\t\tGoodBye";
	Sleep(0700);
	cout << ".";
	Sleep(0700);
	cout << ".";
	Sleep(0700);
	cout << ".";
	exit(0);
}
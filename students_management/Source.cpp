#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student {
	string name;
	string address;
	int ssn;
};
void AddStudent(student s) {
	ofstream add("StudentInfo.txt", ios::app);
	add << s.name << " " << s.address << " " << s.ssn << endl;
	cout << "Student added successfully" << endl;
	add.close();
}
void SearchStudent() {
	ifstream search("StudentInfo.txt");
	string name, address;
	int ssn;
	student s;
	int ssn1=0;
	cout << " Enter the student's SSN to search about him/her: " << endl;
	cin >> ssn1;
	while (search >> s.name >> s.address >> s.ssn)
	{
			if (s.ssn == ssn1)
			{
				cout << "\t \t" << " Name: " << s.name << " \n \t \t Address: " << s.address << " \n \t \t SSN: " << s.ssn << endl;
				break;
				
			}
	}
	if (s.ssn!=ssn1)
	{
		cout << " Student is not found!!" << endl;

	}
	search.close();
}
void DeleteStudent() {
	ifstream File1("StudentInfo.txt");
	ofstream File2("tempDelete.txt");
	string name, address;
	int ssn_search=0;
	student stu;
	cout << "\n Enter the student's SSN to delete it: ";
	cin >> ssn_search;
	int flag = 0;
	while (File1 >> stu.name >> stu.address >> stu.ssn)
	{
		if (File1.eof())
			break;
		if (stu.ssn == ssn_search)
		{
			cout << " Delete done successfully " << endl;
			continue;
		}
			
		else
		{
			File2 << stu.name << " " << stu.address << " " << stu.ssn << " "<<endl;
			
		}
		flag = 1;
		
	}
	if (flag==0)
	{
		cout << "no found" << endl;
	}
	File1.close();
	File2.close();
	remove("StudentInfo.txt");
	rename("tempDelete.txt" , "StudentInfo.txt");
}
void DisplayInfo() {
	ifstream display("StudentInfo.txt");
	string name, address;
	int ssn;
	int ssn1 = 0;
	student s;
	cout << "\t \t \t \t Information about the student " << endl;
	cout << " Enter student's SSN to display his/her info: " << endl;
	cin >> ssn1;
	
	while(display >>s.name >>s.address >>s.ssn){
		if (s.ssn==ssn1)
		{
			cout << "\t\t" << " Name: " << s.name << " \n \t \t Address: " << s.address << "\n \t \t SSN: " << s.ssn << endl;
			break;
		}
		}
	if (s.ssn != ssn1)
	{
		cout << "Info not availabile, enter a valid ssn " << endl;
	}
	display.close();
}
int main() {
	student s;
	int ssn=0;
	int select = 0;
	char repeat = 'y';
	while (repeat == 'y')
	{
		cout << "\t  ------ Choose what operation you want 'at least one or exit '------" << endl;
		cout << "  1. Insert a Student" << endl;
		cout << "  2. Search for a Student" << endl;
		cout << "  3. Delete a Student" << endl;
		cout << "  4. Display info about a Student" << endl;
		cout << "  5. Exit " << endl;
		cout << "  Please, Enter the operation you want " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << " Enter the Student's name: " << endl;
			cin >> s.name;
			cout << " Enter the Student's adress: " << endl;
			cin >> s.address;
			cout << " Enter the Student's ssn: " << endl;
			cin >> s.ssn;
			AddStudent(s);
			break;
		case 2:
			SearchStudent();
			break;
		case 3:
			DeleteStudent();
			break;
		case 4:
			DisplayInfo();
			break;
		case 5:
			repeat = 'n';
			break;
		default:
			cout << "Error!! Please,Enter a valid choice" << endl;
		}
		cout << "Do you want perform another operation? press (y) to continue, (n) to exit." << endl;
		cin >> repeat;

	}
	return 0;
}
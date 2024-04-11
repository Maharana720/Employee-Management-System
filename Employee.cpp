#include "iostream"
#include "fstream"
#include "sys/stat.h"
#include "string.h"
using namespace std;
struct employee
{
    string name,fname,lname,add,dept,gender,gmail,mob,designation;
    int age,id,from,to,experience;
    float salary;
    struct employee *link;
};
typedef struct employee emp;
emp *p=0,*q,*temp=0;
int i=0;
void insert()
{
	if(temp != 0)
		p =temp;
	if(i != 0)
	while(p->link !=0)
		p=p->link;
    i++;
    if(p == 0)
    {
        p=new emp;
        cout << "Enter the Employee Full Name : " ;
        cin >> p->fname;
        cin >> p->lname;
        p->name=p->fname + " " + p->lname ;
        if(p->fname == "" || p->lname == "")
        {
            cout << "No name";
            if(p->fname == "")
            {
                cout << "Re-enter the First name :";
                cin >> p->fname;
            }
            else
            {
                cout << "Re-enter the Last name :";
                cin >> p->lname;
            }
        }
        cout << "Enter the employee Id (number): ";
        cin >> p->id;
        cout << "Enter the Employee Department : ";
        cin >> p->dept;
        cout << "Enter your Designation : ";
        cin >> p->designation;
        cout << "Enter your Gender : ";
        cin >> p->gender;
        cout << "Enter your Address : ";
        cin >> p->add;
        cout << "Enter your G-Mail : ";
        cin >> p->gmail;
        cout << "Enter your Age : ";
        cin >> p->age;
        cout << "Enter your Mobile No. : ";
        cin >> p->mob;
	if(p->mob.length() < 10)
	{
                cout << "Invalid Mobile No. Length" << endl;
                cout << "Re-enter the Mobile No. :";
                cin >> p->mob;
	}
	else
        for(int i=0;i<p->mob.length();i++)
        {
            if(!(p->mob[i] >= '0' && p->mob[i] <= '9'))
            {
                cout << "Invalid Mobile No." << endl;
                cout << "Re-enter the Mobile No.";
                cin >> p->mob;
		break;
            }
        }
        cout << "Enter your Annual Salary (number): ";
        cin >> p->salary;
        cout << "Enter your Experience" << endl;
        cout << "From Year : ";
        cin >> p->from;
        cout << "To Year   : ";
        cin >> p->to;
        p->experience=p->to-p->from;
        temp=p;
    }
    else
    {
        q= new emp;
        p->link=q;
        p=q;
        cout << "Enter the Employee Name : " ;
        cin >> p->fname;
        cin >> p->lname;
        p->name=p->fname + " " + p->lname ;
        if(p->fname == "" || p->lname == "")
        {
            cout << "No name";
            if(p->fname == "")
            {
                cout << "Re-enter the First name :";
                cin >> p->fname;
            }
            else
            {
                cout << "Re-enter the Last name :";
                cin >> p->lname;
            }
        }
        cout << "Enter the employee Id : ";
        cin >> p->id;
        cout << "Enter the Employee Department : ";
        cin >> p->dept;
        cout << "Enter your Designation : ";
        cin >> p->designation;
        cout << "Enter your Gender : ";
        cin >> p->gender;
        cout << "Enter your Address : ";
        cin >> p->add;
        cout << "Enter your G-Mail : ";
        cin >> p->gmail;
        cout << "Enter your Age : ";
        cin >> p->age;
        cout << "Enter your Mobile No. : ";
        cin >> p->mob;
        for(int i=0;i<p->mob.length();i++)
        {
            if(!(p->mob[i] >= '0' && p->mob[i] <= '9'))
            {
                cout << "Invalid Mobile No." << endl;
                cout << "Re-enter the Mobile No.";
                cin >> p->mob;
            }
        }
        cout << "Enter your Annual Salary : ";
        cin >> p->salary;
        cout << "Enter your Experience" << endl;
        cout << "From : ";
        cin >> p->from;
        cout << "To   : ";
        cin >> p->to;
        p->experience=p->from-p->to;
    }
    p->link=0;
}
void Delete()
{
    if(p == 0 && i == 0)
    {
        cout << "No Data inserted yet" <<endl;
        return;
    }
    else if(p == 0 && i > 0)
    {
        cout << "All Data deleted" << endl;
        return;
    }
    int n;
    p=temp;
    cout << "Enter the Employee Id to delete : ";
    cin >> n;
    if(n == p->id)
    {
        q=p->link;
        delete p;
        temp = q;
        p=temp;
	cout << "Entered Employee Id deleted" << endl;
	return;
    }
    while(p != 0)
    {
        emp *f;
        f=p;
        if(p->id == n)
        {
            q=p;
            p=p->link;
            f->link=p;
            delete q;
            p=temp;
            return;
		cout << "Entered Employee Id deleted" << endl;
        }
    }
    cout << "Employee Id Not Found to delete" << endl;
    p=temp;
}
void search()
{
    int check;
    cout << "Enter the ID to search :";
    cin >> check;
    p = temp;
    while (p != 0)
    {
        if (check == p->id)
        {
            cout << "Found " << endl;
            cout << p->fname << " " << p->lname << "\t" << p->id << "\t" << p->dept << "\t" << p->designation << "\t" << p->gmail << "\t" << p->mob << "\t" << p->gender << "\t" << p->experience << "\t" << p->age << "\t" << p->salary << "\t" << p->add << endl;
            return;
        }
        p = p->link;
    }
    cout << "Not Found" << endl;
}
void show()
{
    if(p == 0 && i == 0)
    {
        cout << "No Data inserted yet" <<endl;
        return;
    }
    else if(p == 0 && i > 0)
    {
        cout << "All Data deleted" << endl;
        return;
    }
	 cout << "Employee List" << endl;
	    cout << "-----------------------------" << endl;

	p=temp;
	while(p != 0)
	{
		cout << "Name: " << p->name << endl;
        cout << "ID: " << p->id << endl;
        cout << "Department: " << p->dept << endl;
        cout << "Designation: " << p->designation << endl;
        cout << "Gender: " << p->gender << endl;
        cout << "Address: " << p->add << endl;
        cout << "G-Mail: " << p->gmail << endl;
        cout << "Age: " << p->age << endl;
        cout << "Mobile No.: " << p->mob << endl;
        cout << "Annual Salary: " << p->salary << endl;
        cout << "Experience: " << p->from << " to " << p->to << endl;
        cout << "-----------------------------" << endl;

		p=p->link;
	}
	p=temp;
}
void sort()
{
	string assign;
    p=temp;
    while (p != 0) 
    {
        q = p->link;
        while (q != 0) 
        {
            if (p->name.compare(q->name)) 
            {
                assign = p->name;
                p->name = q->name;
                q->name = assign;
                swap(p->add, q->add);
                swap(p->dept, q->dept);
                swap(p->gender, q->gender);
                swap(p->gmail, q->gmail);
                swap(p->mob, q->mob);
                swap(p->designation, q->designation);
                swap(p->from, q->from);
                swap(p->to, q->to);
                swap(p->age, q->age);
                swap(p->id, q->id);
                swap(p->salary, q->salary);
            }
            q = q->link;
        }
        p = p->link;
    }
	p=temp;
}
void store()
{
    fstream file;
    file.open("Employee.txt",ios::out);
    cout << "New file open Data stored" << endl;
    file << "Name\t\t" << "Employee ID\t"  << "Department\t" << "Designation\t" << "E-Mail\t\t" << "Mobile No." << "Gender" << "Experience \t" << "Age\t" << "Salary\t" << "Address\n";
    for(int i=0;i;i++)
        file << "-";
    p=temp;
    while(p != 0)
    {
        file << p->fname << " " << p->lname << "\t" << p->id << "\t" << p->dept << "\t" << p->designation << "\t" << p->gmail << "\t" << p->mob << "\t" << p->gender << "\t" << p->experience << "\t" << p->age << "\t" << p->salary << "\t" << p->add << endl;
        q=p;
        p=p->link;
        delete q;
    }
    file.close();
}
int main()
{
	system("clear");
    int n;
    cout << "╔══════════════════════════════╗" << endl;
    cout << "║   Employee  Data Management  ║" << endl;
    cout << "╚══════════════════════════════╝"<<endl;

    do
    {
	cout << "Employee Data Management System" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Search Employee" << endl;
    cout << "3. Sort Employee" << endl;
    cout << "4. Store the data" << endl;
    cout << "5. Display All Employees" << endl;
    cout << "6. Clear Display " << endl;
    cout << "7. Delete " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter your choice: ";
	cin >> n;
        switch(n)
        {
            case 1:
                insert();
		system("clear");
                break;
            case 2:
                search();
                break;
            case 3:
                sort();
		show();
                break;
            case 4:
                store();
		system("clear");
                break;
            case 5:
		show();
		break;
            case 6:
		system("clear");
		break;
            case 7:
		Delete();
		break;
        }
    } while (n != 0);
    
    return 0;
}
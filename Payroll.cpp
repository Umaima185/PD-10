#include <iostream>
#include <string>
#include <conio.h>
#include<windows.h>
using namespace std;

// Functions
void header();
void login();
void admin();
void user();
void defaultChart();
void BranchMembers();
void adminEmpAdd();
void adminEmpDel();
void adminUpdate();
void userIntel();
void rateInput();
void payroll();
void Credentials(int id);
bool validateLogin(string email, string password);
bool checkID(int id);
bool checkName(string name);
float calculatePayroll();
void gotoxy(int x, int y);


// Global Variables
int x=0, y=0;
const int MAX = 100; 
int n = 10; 
float hours[MAX]={0};
float rates[MAX]={0};       
float  salary[MAX];  
float defaultSalary[MAX] = {60000, 53000, 100000, 54300, 80000, 75000, 56800, 97000, 90000, 125000};
long defaultID[MAX] = {110, 112, 113, 114, 115, 116, 117, 118, 119, 120};
string defaultName[MAX] = {"Harris", "Zain", "Zuhaib", "Amna", "Aiman", "Majid", "Sehar", "Shazia", "Moiz", "Mutahir"};
string Posts[MAX]={"Team Lead","Co-Team Lead","Member","Member","Member","Member","Member","Member","Member","Member"};

int main() {
    float temp[MAX];
    string email, password;
    int mainOption, adminOption, userOption;

    header();
    login();

    cout << "Enter your email: ";
    cin >> email;

    cout << "Enter your password: ";
    cin >> password;

    if (!validateLogin(email, password)) {
        cout << "Login failed. Please try again." << endl;
        return 1;
    }

    cout << "Login successful!" << endl;
    system("cls");

    while (true) {
        header();
        cout << "\nMAIN MENU:\n";
        cout << "1. Admin Options\n";
        cout << "2. User Options\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainOption;

        switch (mainOption) {
            case 1:
                while (true) {
                    system("cls");
                    header();
                    cout << "\nADMIN OPTIONS:\n";
                    cout << "1. Insert New Employees\n";
                    cout << "2. Delete Employees\n";
                    cout << "3. Update Employee Info\n";
                    cout << "4. Manage Payroll\n";
                    cout << "5. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> adminOption;

                    if (adminOption == 5) {
                        break;
                    }

                    switch (adminOption) {
                        case 1:
                            adminEmpAdd();
                            Sleep(5000);
                            break;
                        case 2:
                            adminEmpDel();
                            Sleep(5000);
                            break;
                        case 3:
                            adminUpdate();
                            Sleep(5000);
                            break;
                        case 4:
                            payroll();
                            rateInput();
                            for (int j = 0; j < MAX; j++) {
                                temp[j] = calculatePayroll();
                                cout << "Employee " << j + 1 << "\t\t" << temp[j] << "\n";
                            }
                            Sleep(5);
                            break;
                        default:
                            cout << "Invalid Option. Try again." << endl;
                    }
                }
                break;

            case 2:
                while (true) {
                    system("cls");
                    header();
                    cout << "\nUSER OPTIONS:\n";
                    cout << "1. Check Credentials\n";
                    cout << "2. View Branch Colleagues\n";
                    cout << "3. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> userOption;

                    if (userOption == 3) {
                        break;
                    }

                    switch (userOption) {
                        case 1:
                            int id;
                            while (true) {
                                cout << "Enter your ID (110 to 120 or onwards): ";
                                cin >> id;
                                if (checkID(id)) {
                                    cout << "Validation Complete!\n";
                                    Credentials(id);
                                    Sleep(5000);
                                    break;
                                } else {
                                    cout << "ID does not exist. Please try again.\n";
                                }
                            }
                            break;
                        case 2:
                            BranchMembers();
                            Sleep(5000);
                            break;
                        default:
                            cout << "Invalid Option. Try again." << endl;
                    }
                }
                break;

            case 3:
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid Option. Try again." << endl;
        }
    }

    return 0;
}



//--------------------------------------------------------------------------------------------------------------
// Functions

void header() {
    gotoxy(x+10,y+10);
    cout << "#####################################################################################\n";
    gotoxy(x+10,y+11);
    cout << "##                                                                                 ##\n";
    gotoxy(x+10,y+12);
    cout << "##                        ==========  PAYROLL ==========                           ##\n";
    gotoxy(x+10,y+13);
    cout << "##                                                                                 ##\n";
    gotoxy(x+10,y+14);
    cout << "#####################################################################################\n\n";
    gotoxy(x+10,y+15);
    cout << "***************************************************************************************\n";
}

void login(){
    gotoxy(x+40,y+17);
    cout << "//=== Login System ===//\n";
}

void admin(){
    gotoxy(x+40,y+17);
    cout << "-------------------------------------------\n";
      gotoxy(x+40,y+18);
    cout << "|                    ADMIN                |\n";
      gotoxy(x+40,y+19);
    cout << "-------------------------------------------\n";
}

void user(){
 gotoxy(x+40,y+17);
    cout << "-------------------------------------------\n";
gotoxy(x+40,y+17);
    cout << "|                    USER                 |\n";
gotoxy(x+40,y+17);
    cout << "-------------------------------------------\n";
}

void defaultChart() {
    cout << "ID\tEmployee Name\tSalary\n\n";
    for(int i=0;i<n;i++) {
        cout << defaultID[i] << "\t" << defaultName[i] << "\t\t" << defaultSalary[i] << endl;
    }
}
void BranchMembers(){
    cout << "ID\tEmployee Name\tPost\n\n";
    for(int i=0;i<n;i++) {
        cout << defaultID[i] << "\t" << defaultName[i] <<"\t\t"<<Posts[i] <<endl;
    }
}

bool validateLogin(string email, string password) {
    bool hasAt = false;

    for (char c : email) {
        if (c == '@') {
            hasAt = true;
            break;
        }
    }

    if (!hasAt) {
        cout << "Error: Email must contain '@' character.\n";
        return false;
    }

    if (password.length() < 8) {
        cout << "Error: Password must be at least 8 characters long.\n";
        return false;
    }

   return true;
}

void adminEmpAdd() {
    int add;
    cout << "Enter the number of employees to be added: ";
    cin >> add;

    if (n + add > MAX) {
        cout << "Error: Cannot add more employees.\n";
        return;
    }

    for (int i = 0; i < add; i++) {
        cout << "Enter ID, Name, and Salary for Employee: " << i + 1 << endl;
        cout << "ID: ";
        cin >> defaultID[n];
        cout <<endl<< "Name: ";
        cin>>defaultName[n];
        cout <<endl<< "Salary: ";
        cin >> defaultSalary[n];
        n++;
    }

    cout << "\nUpdated Employee List:\n";
    defaultChart();
}

void adminUpdate() {
    string newName;
    float newSalary;
    int id, opt;
    cout << "Enter the ID of the employee to be updated: ";
    cin >> id;
    int idx = -1;

    // Locate the employee by ID
    for (int i = 0; i < n; i++) {
        if (defaultID[i] == id) {
            idx = i;
            break;
        }
    }

    // Check if the employee was found
    if (idx == -1) {
        cout << "Error: Employee with ID " << id << " not found.\n";
        return;
    }

    // Prompt for the type of update
    while (true) {
        cout << "Press 1 to change Name\n";
        cout << "Press 2 to change Salary\n";
        cout << "Press 3 to change both Name and Salary\n";
        cin >> opt;

        if (opt == 1) {
            cout << "Enter new Name: ";
            cin >> newName;
            defaultName[idx] = newName;
            cout << "Name updated successfully.\n";
            break;
        } else if (opt == 2) {
            cout << "Enter the updated Salary: ";
            cin >> newSalary;
            defaultSalary[idx] = newSalary;
            cout << "Salary updated successfully.\n";
            break;
        } else if (opt == 3) {
            cout << "Enter new Name: ";
            cin >> newName;
            defaultName[idx] = newName;
            cout << "Enter the updated Salary: ";
            cin >> newSalary;
            defaultSalary[idx] = newSalary;
            cout << "Name and Salary updated successfully.\n";
            break;
        } else {
            cout << "Invalid choice. Please choose again.\n";
        }
    }

    cout << "\nUpdated Employee List:\n";
    defaultChart();
}


void adminEmpDel() {
     int id;
    cout << "Enter the ID of the employee to be deleted: ";
    cin >> id;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (defaultID[i] == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Error: Employee with ID " << id << " not found.\n";
        return;
    }

   for (int i=idx;i<n;i++) {
    if(defaultID[i]==id){
        defaultID[i] = 0;
        defaultName[i] = "---";
        defaultSalary[i] = 0;
        break;
        }
    }
   cout << "Employee with ID " << id << " deleted successfully.\n";
    cout << "\nUpdated Employee List:\n";
    defaultChart();
}

bool checkID(int id){
    bool check=false;
    while(true){
        for(int i=0;i<n;i++){
            if(defaultID[i]==id)
            {
                check=true;
                break;
            }
        }
        if(check==true)
        break;
    }
    return check;
}

bool checkName(string name) {
    for (int i = 0; i < n; i++) {
        if (defaultName[i] == name) {
            return true;
        }
    }

return false;
}
void rateInput(){
    for(int i=0;i<n;i++) {
        cout<<" For Employee : "<<defaultName[i]<<endl;
        cout << "Enter time worked : ";
        cin >> hours[i];
        if(hours[i]<10&&hours[i]>0){
            cout<<"No Salary";
            hours[i]=0;
        }
        cout << "Enter hourly rate : ";
        cin >> rates[i];
        }
}

float calculatePayroll() {
    for(int i=0;i<n;i++){
        salary[i] = hours[i] * rates[i];
        return salary[i];
    }
}

void payroll(){
     cout << "\nPayroll Information\n";
    cout << "---------------------------------------------------\n";
    cout << "Employee Name\thours Worked\tHourly Rate\tSalary\n";
    cout << "---------------------------------------------------\n";

}
void Credentials(int id){
    for(int i=0;i<n;i++){
        if(defaultID[i]==id){
            cout<<"ID number: "<<id;
            cout<<"Employee Name: "<<defaultName[i]<<endl;
            cout<<"Employee working hours: "<<hours[i]<<endl;
            cout<<"Employee's Salary: "<<defaultSalary[i]<<endl;
            break;
        }
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
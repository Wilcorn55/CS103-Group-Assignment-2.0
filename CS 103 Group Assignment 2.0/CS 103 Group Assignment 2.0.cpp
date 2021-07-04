// CS 103 Group Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void line();
void intro();
void admin();
void student();
void add_student();
void edit_student();
void update_student();
void delete_student();
void view_student();
void teacher_login(char[], char[]);
void teacher_regi(struct Teacher&);
void parent_login(char[], char[]);
void admin_screen();
void parent_regi(struct Parent&);
void parent_screen();
void help_stu();
void prog_stu();
void search_parent();
void student_subjects();
void class_1_del();
void class_2_del();

//Initilising Variables
int choice = 0, progress = 0, class_numb, trm_tally = 0, position = 0;
char another = 'n';
fstream file, tempfile;
int op_t, op_p;
char answer = 'y';
char username_t[20], password_t[20];
bool flag_t = false, flag_a = false, flag_p = false;
char username_p[20], password_p[20];
int class_no = 0;
char name[30];

//Initilising Structures
struct Student_Rec
{
    char full_name[51], other_name[51], gen[20], other_total[51];
    string maths, sci, writing, read, other, overall_prog;
    int grade_score;
    char maths_s[20], sci_s[20], writing_s[20], read_s[20], other_s[20], overall_prog_s[20];
}s;

struct Student_Rec_cpy
{
    char full_name[51], other_name[51], gen[20];
    string maths, sci, writing, read, other, overall_prog;
    int grade_score;
    char maths_s[20], sci_s[20], writing_s[20], read_s[20], other_s[20], overall_prog_s[20];
}s2;

struct Teacher
{
    char f_name[30], class_numb[10], year[10], user[20], pass[20];
    string gen, dob, email, con_numb;
}tea;

struct Parent
{
    char f_name[30], c_f_name[30], p_f_name[30], c_class[10], year[10], user[20], pass[20];
    string gen, dob, email, con_numb, emer_con_numb;
}p;

struct admin_log
{
    char a_user[20], a_pass[20];
}a;

//Main Function
int main()
{
    //inserting intro into main
    intro();
    
    cout << "\n\n";
    return 0;
}

void line()//line loop to help separate things
{
    cout << "\n\n";
    for (int i = 0; i < 100; i++)
    {
        cout << "*";
    }

    cout << "\n\n";
}

void intro()
{
    cout << "\t\t\t Welcome to the *School name here* System";//generic Welcome message

    line();

    //School info system
    cout << "If you would like to get in touch with up please: \nCall: *Number here* \nEmail: *Email here*\n";

    line();

    //School upcoming events
    cout << "\t\t\tSome of the upcoming school events are: ";
    cout << "\n*June 10th: Sports Day*";
    cout << "\n*July 12th: Camp*";

    line();

    //School Dates
    cout << "\t\t\t2021 School Dates\n";
    cout << "  Term 1: Monday 1st February- Friday 16th April\n";
    cout << "  Term 2: Monday 3rd May - Friday 9th July\n";
    cout << "  Term 3: Monday 26th July - Friday 1st October\n";
    cout << "  Term 4: Monday 18th October - Monday 20th December\n";

    while (choice != 6)
    {
        //Login and Regestration options
        line();
        cout << "\n\nWould you like to: ";
        cout << "\n1. Login as a Parent\n";
        cout << "2. Register as a New Parent\n";
        cout << "3. Login as a Teacher\n";
        cout << "4. Register as a New Teacher\n";
        cout << "5. Login as Admin\n";
        cout << "6. Exit\n";
        cout << "\nPlease enter an option : ";
        cin >> choice;
        cin.ignore();

        //switch case which will link to all the other login and registration screens
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                //parent login and screen will give 3 chances to login
                parent_login(username_p, password_p);
                if (flag_p == true)
                {
                    i = 2;
                    cout << "\n\n Login Success!";
                    line();
                    parent_screen();
                    flag_p = false;
                }
                else if (i < 2 && !flag_p)
                {
                    cout << "\n\n Information not matched! Please try again\n";
                }
                else if (i == 2 && !flag_p)
                {
                    cout << "\n\n Sorry, please try again after 5 minutes\n";
                }
            }
            break;
        case 2:
            //parent registration
            parent_regi(p);
            break;
        case 3:
            //teacher login and student screen will give 3 chances to login
            for (int i = 0; i < 3; i++)
            {
                teacher_login(username_t, password_t);
                if (flag_t == true)
                {
                    i = 2;
                    cout << "\n\n Login Success!";
                    line();
                    student();
                    flag_t = false;
                }
                else if (i < 2 && !flag_t)
                {
                    cout << "\n\n Information not matched! Please try again\n";
                }
                else if (i == 2 && !flag_t)
                {
                    cout << "\n\n Sorry, please try again after 5 minutes\n";
                }
            }
            break;
        case 4:
            //teacher registration
            teacher_regi(tea);
            break;
        case 5:
            for (int i = 0; i < 3; i++)
            {
                //admin login and screen will give 3 chances to login
                admin();
                if (flag_a == true)
                {
                    i = 2;
                    cout << "\n\n Login Success!";
                    line();
                    admin_screen();
                }
                else if (i < 2 && !flag_a)
                {
                    cout << "\n\n Information not matched! Please try again\n";
                }
                else if (i == 2 && !flag_a)
                {
                    cout << "\n\n Sorry, please try again after 5 minutes\n";
                }
            }
            
            break;
        case 6:
            //exit and defult info
            break;
        default:
            cout << "\n\n Please enter a Valid Option";

        }
    }
}

void student()
{
    
    do
    {
        cout << "Welcome to the Student Record what would you like to do?";

        //Student Record options
        cout << "\n1. Add Student\n";
        cout << "2. Edit Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. View the Student Records\n";
        cout << "6. Exit\n";
        cin >> choice;
        //switch case which will link to all options
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            edit_student();
            break;
        case 3:
            delete_student();
            break;
        case 4:
            update_student();
            break;
        case 5:
            view_student();
            break;
        case 6:
            break;
        default:
            cout << "Please enter a Valid Option";
            break;
        }
    } while (choice != 6);

    
        
    
}

void add_student()
{
    do
    {
       s.grade_score = 0;
        system("CLS");
        //Getting user input
        cout << "Enter Student Infomation:\n";
        cin.ignore();
        cout << "Full Name:";
        cin.getline(s.full_name, 51);
        cout << "Gender:";
        cin >> s.gen;

        //linking to the subject choices
        student_subjects();

        //option to add another student
        cout << "\n\nDo you want to enter another record y/n ?  ";
        cin >> another;
    } while (another == 'y');
}

void teacher_login(char usern[], char passw[])
{
    line();
    //teacher user and pass enter
    cout << "\nPlease enter your username : ";
    cin.getline(usern, 20);
    cout << "\nPlease enter your password : ";
    cin.getline(passw, 20);

    file.open("Teachers.dat", ios::in | ios::binary);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&tea), sizeof(tea));//reading from file
            //entered user and pass compared to stored
            if ((strcmp(usern, tea.user) == 0) && (strcmp(passw, tea.pass) == 0))
            {
                flag_t = true;
            }
        }
    }
    else
    {
        cout << "\nFile unable to access ...";
    }

    file.close();//closing file
}



void teacher_regi(struct Teacher& tea)
{
    system("CLS");
    line();
    cout << "\nPlease enter the following information\n";

    file.open("Teachers.dat", ios::out | ios::app | ios::binary); //opening file to add to

    //user entering all info
    cout << "\nEnter full name : ";
    cin.getline(tea.f_name, 30);
    cout << "\nEnter gender : ";
    cin >> tea.gen;
    cout << "\nEnter dob : ";
    cin >> tea.dob;
    cout << "\nEnter email : ";
    cin >> tea.email;
    cout << "\nEnter contact number : ";
    cin.ignore();
    cin >> tea.con_numb;
    cin.ignore();
    cout << "\nEnter classroom number : ";
    cin.getline(tea.class_numb, 10);
    cout << "\nEnter the year level you teach : ";
    cin.getline(tea.year, 10);
    cout << "\nEnter username : ";
    cin >> tea.user;
    cout << "\nEnter password : ";
    cin >> tea.pass;

    file.write(reinterpret_cast<char*>(&tea), sizeof(tea)); //writing to file
    file.close();//closing file
}

void parent_login(char usern[], char passw[])
{
    line();
    //parent user and pass enter
    cout << "\nPlease enter your username : ";
    cin.getline(usern, 20);
    cout << "\nPlease enter your password : ";
    cin.getline(passw, 20);

    file.open("Parents.dat", ios::in | ios::binary);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&p), sizeof(p));//reading from file
            //entered user and pass compared to stored
            if ((strcmp(usern, p.user) == 0) && (strcmp(passw, p.pass) == 0))
            {
                flag_p = true;
            }
        }
    }
    else
    {
        cout << "\nFile unable to access ...";
    }

    file.close();//closing file
}


void parent_regi(struct Parent& p)
{
    system("CLS");
    line();
    cout << "\nPlease enter the following information\n";

    file.open("Parents.dat", ios::out | ios::app | ios::binary);//opening file to add to

    //entering all user info
    cout << "\nEnter full name : ";
    cin.getline(p.f_name, 30);
    cout << "\nEnter gender : ";
    cin >> p.gen;
    cout << "\nEnter dob : ";
    cin >> p.dob;
    cout << "\nEnter email : ";
    cin >> p.email;
    cout << "\nEnter contact number : ";
    cin.ignore();
    cin >> p.con_numb;
    cin.ignore();
    cout << "\nEnter child full name : ";
    cin.getline(p.c_f_name, 30);
    cout << "\nEnter child classroom number : ";
    cin >> p.c_class;
    cin.ignore();
    cout << "\nEnter child parent/ caregiver full name : ";
    cin.getline(p.p_f_name, 30);
    cout << "\nEnter emergency contact number : ";
    cin >> p.emer_con_numb;
    cout << "\nEnter username : ";
    cin >> p.user;
    cout << "\nEnter password : ";
    cin >> p.pass;

    file.write(reinterpret_cast<char*>(&p), sizeof(p));//writing to the file
    file.close();//closing file
}

void parent_screen()
{
    

    while (op_p != 3)
    {
        //choosing what they want to do
        cout << "\nWould you like to :";
        cout << "\n1. View your student record";
        cout << "\n2. View the school notices";
        cout << "\n3. Quit";
        cout << "\n\nPlease enter an option : ";
        cin >> op_p;

        if (op_p == 1)
        {
            //open view student
            view_student();
        }
        else if (op_p == 2)
        {
            //shows events
            cout << "\t\t\tSome of the upcoming school events are: ";
            cout << "\n*June 10th: Sports Day*";
            cout << "\n*July 12th: Camp*";

            line();
        }
        else if (op_p != 1 && op_p != 2 && op_p != 3)
        {
            //tell them to chose an option
            cout << "\n\n Please enter a valid option";
            line();
        }
    }

    op_p = 0;
}

void admin()
{
    file.close();
    char a_user[20], a_pass[20];
    line();
    
    //entering the admin password
    cout << "Please enter admin username and password";
    cout << "\nUsername: ";
    cin.getline(a_user, 20);
    cout << "\nPassword: ";
    cin.getline(a_pass, 20);
    
    file.open("Admin.dat", ios::out | ios::app | ios::binary);//opening file in read

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&a), sizeof(a));//reading from file
            

            if ((a_user == a.a_user) && (a_pass == a.a_pass))//comparing user and pass
            {
             
                flag_a = true;
            }
        }
    }
    else
    {
        cout << "\nFile unable to access ...";
    }

    file.close();//closing file
}

void admin_screen()
{
    system("CLS");
    line();
    do
    {
        //switch case for options
        cout << "What would you like to do?\n";
        cout << "1.Find Students that need Help\n";
        cout << "2.Find Students that are progressing\n";
        cout << "3.Find Parents\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            help_stu();
            break;
        case 2:
            prog_stu();
            break;
        case 3:
            search_parent();
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (choice != 4);

    choice = 0;
}


void help_stu()
{
    ifstream file;

    //Choosing which file to search
    cout << "What Class would you like to search for";
    cin >> class_numb;

    if (class_numb == 1)
    {
        //Opening Room 1 file
        file.open("stu_rec_room_1.dat", ios::in | ios::out | ios::binary);

    }
    if (class_numb == 2)
    {
        //Opening Room 2 file
        file.open("stu_rec_room_2.dat", ios::in | ios::out | ios::binary);

    }
    else
    {
        cout << "\n\n Sorry class number not found";
    }

    while (!file.eof())
    {
        //Searching the File
        file.read(reinterpret_cast<char*>(&s), sizeof(s));


        //Comparing the search with the file
        if (s.overall_prog_s == "Needs_Help")
        {
            //Printing the File info

            cout << "\n\nFull Name: " << s.full_name << "\n";
            cout << "Maths: " << s.maths_s << "\n";
            cout << "Science: " << s.sci_s << "\n";
            cout << "Writing: " << s.writing_s << "\n";
            cout << "Reading: " << s.read_s << "\n";
            cout << s.other_name << ":" << s.other << "\n";
            break;
        }
    }
    
    file.close();
}

void prog_stu()
{
    ifstream file;

    //Choosing which file to search
    cout << "What Class would you like to search for";
    cin >> class_numb;

    if (class_numb == 1)
    {
        //Opening Room 1 file
        file.open("stu_rec_room_1.dat", ios::out | ios::app | ios::binary);

    }
    if (class_numb == 2)
    {
        //Opening Room 2 file
        file.open("stu_rec_room_2.dat", ios::out | ios::app | ios::binary);

    }
    else
    {
        cout << "\nSorry class number not found\n";
    }

    while (!file.eof())
    {
        //Searching the File
        file.read(reinterpret_cast<char*>(&s), sizeof(s));

        //Comparing the search with the file
        if (s.overall_prog_s == "Progressing")
        {
            //Printing the File info

            cout << "\n\nFull Name: " << s.full_name << "\n";
            cout << "Maths: " << s.maths_s << "\n";
            cout << "Science: " << s.sci_s << "\n";
            cout << "Writing: " << s.writing_s << "\n";
            cout << "Reading: " << s.read_s << "\n";
            cout << s.other_name << ":" << s.other << "\n";
            break;
        }
    }
    
    file.close();
}

void search_parent()
{
    //Declaring Local variables
    char f_name_search[51];
    bool Alert = false;

    //Search info
    cout << "\n\nEnter the first name of parent to retrieve records: ";
    cin.getline(f_name_search, 51);

    ifstream file;

    //Making search file
    file.open("Parents.dat", ios::in | ios::binary);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&p), sizeof(p));//copying from file

            if (strcmp(f_name_search, p.f_name) == 0)
            {
                //showing parent info
                cout << "\n\nFull Name: " << p.f_name << "\n";
                cout << "Gender: " << p.gen << "\n";
                cout << "Date of Birth: " << p.dob << "\n";
                cout << "Email: " << p.email << "\n";
                cout << "Contact Number: " << p.con_numb << "\n";
                cout << "Child full name: " << p.c_f_name << "\n";
                cout << "Child class number: " << p.c_class << "\n";
                cout << "Parent/ Caregiver Name: " << p.p_f_name << "\n";
                cout << "Emergancy number: " << p.emer_con_numb << "\n";

            }
            else
            {
                cout << "Unable to find Parent Info ...";
            }
        }
    }
    else
    {
        cout << "\nFile unable to access ...";
    }

    file.close();//closing file
}



void edit_student()
{
    bool edit_f = false;
    cout << "\n\n Please enter the class number of the student (1 or 2) : ";
    cin >> class_no;

    if (class_no == 1)
    {
        //getting student name
        cout << "\n\nPlease enter the student's full name : ";
        cin.getline(name, 51);
        //Opening Room 1 file
        file.open("stu_rec_room_1.dat", ios::in | ios::binary);
    }

    else if (class_no == 2)
    {
        //getting student name
        cout << "\n\nPlease enter the student's full name : ";
        cin.getline(name, 51);
        //Opening Room 2 file
        file.open("stu_rec_room_2.dat", ios::in | ios::binary);


    }
    else
    {
        cout << "\n\n Please enter a valid class number (1 or 2)";
    }

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&s), sizeof(s)); // reading the content from the file 

            position = file.tellg();  // current cursor position 

            if ((name == s.full_name))
            {
                //printing info
                cout << "\n\nFirst Name  : " << s2.full_name << "\n";
                cout << "Gender          : " << s2.gen << "\n";
                cout << "Maths           : " << s2.maths << "\n";
                cout << "Science         : " << s2.sci << "\n";
                cout << "Writing         : " << s2.writing << "\n";
                cout << "Reading         : " << s2.read << "\n";
                cout << s2.other_name << ":" << s2.other << "\n";
                cout << "Overall Progress: " << s2.overall_prog << "\n";

                file.seekp(position - (sizeof(s)));

                student_subjects();
                
                //switching from one to another
                strcpy_s(s2.maths_s, s.maths_s);
                strcpy_s(s2.sci_s, s.sci_s);
                strcpy_s(s2.writing_s, s.writing_s);
                strcpy_s(s2.read_s, s.read_s);
                strcpy_s(s2.other_name, s.other_name);
                strcpy_s(s2.other_s, s.other_s);
                strcpy_s(s2.overall_prog_s, s.overall_prog_s);
                
                file.write(reinterpret_cast<char*>(&s), sizeof(s)); // writing the file to the 

                edit_f = false;
                break;
            }
            else
            {
                edit_f = true;
            }
        }
    }
    else
    {
        cout << "\nFile unable to access ....";
    }

    if (edit_f == true)
    {
        cout << "\nRecord not found...";
    }

    file.close();//closing file
}



void update_student()
{
    
   
    cout << "\n\n Please enter the class number of the student (1 or 2) : ";
    cin >> class_no;

    if (class_no == 1)
    {
        cout << "\n\nPlease enter the student's full name who you would like to update for another term: ";
        cin.getline(name, 51);
        //Opening Room 1 file
        file.open("stu_rec_room_1.dat", ios::app | ios::out | ios::binary);
    }

    else if (class_no == 2)
    {
        cout << "\n\nPlease enter the student's full name who you would like to update for another term: ";
        cin.getline(name, 51);
        //Opening Room 2 file
        file.open("stu_rec_room_2.dat", ios::app | ios::out | ios::binary);


    }
    else
    {
        cout << "\n\n Please enter a valid class number (1 or 2)";
    }
    while (!file.eof())
    {
        file.read(reinterpret_cast<char*>(&s), sizeof(s));//reading from file

        if ((strcmp(name, s.full_name) == 0))
        {
            //adding to the file
            cout << "\n\nFull Name  : " << s.full_name << "\n";
            cout << "Gender          : " << s.gen << "\n";

            file.close();
            
            student_subjects();

            line();
        }
        else
        {
            cout << "\n\nRecord not found";
        }
    }


}



void delete_student()
{
   

    cout << "\n\n Please enter the class number of the student (1 or 2) : ";
    cin >> class_no;

    if (class_no == 1)
    {
        //going to del class 1
        class_1_del();
    }

    else if (class_no == 2)
    {
        //going to del class 2
        class_2_del();
    }
    else
    {
        cout << "\n\n Please enter a valid class number (1 or 2)";
    }

}




void view_student()
{
    
    
    while (class_no != 1 && class_no != 2)
    {
        trm_tally = 1;
        cout << "\n\n Please enter the class number of the student (1 or 2) : ";
        cin >> class_no;

        if (class_no == 1)
        {
            cout << "\n\nPlease enter the student's full name : ";
            cin.getline(name, 51);
            //Opening Room 1 file
            file.open("stu_rec_room_1.dat", ios::out | ios::app | ios::binary);
        }
 
        else if (class_no == 2)
        {
            cout << "\n\nPlease enter the student's full name : ";
            cin.getline(name, 51);

            //Opening Room 2 file
            file.open("stu_rec_room_2.dat", ios::out | ios::app | ios::binary);

           
        }
        else
        {
            cout << "\n\n Please enter a valid class number (1 or 2)";
        }
        while (!file.eof())
        {
            file.read(reinterpret_cast<char*>(&s), sizeof(s));//reading from file

            if ((strcmp(name, s.full_name) == 0))
            {
                //tally of each term
                cout << "\n Term " << trm_tally << ":";
                
                cout << "\n\nFull Name  : " << s.full_name << "\n";
                cout << "Gender          : " << s.gen << "\n";
                cout << "Maths           : " << s.maths << "\n";
                cout << "Science         : " << s.sci << "\n";
                cout << "Writing         : " << s.writing << "\n";
                cout << "Reading         : " << s.read << "\n";
                cout << s.other_name << " : " << s.other << "\n";

                
                
                line();
            }
            else
            {
                cout << "\n\nRecord not found";
            }
        }
    }
}

void student_subjects()
{
    //Switch cases to for each subject

    cout << "How are they doing in Maths:";
    cout << "\n1. Achieveing\n";
    cout << "2. Progressing\n";
    cout << "3. Needs Help\n";
    cin >> progress;

    switch (progress)
    {
    case 1:
        s.maths = "Achieving";
        break;
    case 2:
        s.maths = "Progressing";
        break;
    case 3:
        s.maths = "Needs_Help";
        break;
    default:
        cout << "Please enter a Valid Option";
        break;
    }
    s.grade_score = +progress;

    cout << "How are they doing in Science:";
    cout << "\n1. Achieveing\n";
    cout << "2. Progressing\n";
    cout << "3. Needs Help\n";
    cin >> progress;

    switch (progress)
    {
    case 1:
        s.sci = "Achieving";
        break;
    case 2:
        s.sci = "Progressing";
        break;
    case 3:
        s.sci = "Needs_Help";
        break;
    default:
        cout << "Please enter a Valid Option";
        break;
    }
    s.grade_score = +progress;

    cout << "How are they doing in Writing:";
    cout << "\n1. Achieveing\n";
    cout << "2. Progressing\n";
    cout << "3. Needs Help\n";
    cin >> progress;

    switch (progress)
    {
    case 1:
        s.writing = "Achieving";
        break;
    case 2:
        s.writing = "Progressing";
        break;
    case 3:
        s.writing = "Needs_Help";
        break;
    default:
        cout << "Please enter a Valid Option";
        break;
    }
    s.grade_score = +progress;

    cout << "How are they doing in Reading:";
    cout << "\n1. Achieveing\n";
    cout << "2. Progressing\n";
    cout << "3. Needs Help\n";
    cin >> progress;

    switch (progress)
    {
    case 1:
        s.read = "Achieving";
        break;
    case 2:
        s.read = "Progressing";
        break;
    case 3:
        s.read = "Needs_Help";
        break;
    default:
        cout << "Please enter a Valid Option";
        break;
    }
    s.grade_score = +progress;

    cout << "How are they doing in their other Class:";
    cout << "\n1. Achieveing\n";
    cout << "2. Progressing\n";
    cout << "3. Needs Help\n";
    cin >> progress;

    switch (progress)
    {
    case 1:
        s.other = "Achieving";
        break;
    case 2:
        s.other = "Progressing";
        break;
    case 3:
        s.other = "Needs_Help";
        break;
    default:
        cout << "Please enter a Valid Option";
        break;
    }
    s.grade_score = +progress;

    if (progress <= 8)
    {
        s.overall_prog = "Achieving";
    }
    if (progress > 8 && progress <= 12)
    {
        s.overall_prog = "Progressing";
    }
    if (progress > 12 && progress <= 15)
    {
        s.overall_prog = "Needs_Help";
    }

    cin.ignore();
    //Name of other class
    cout << "What is the name of the other class they are taking";
    cin.getline(s.other_name, 51);

    

    //getting class number
    cout << "What is the number of the class they are in: ";
    cin >> class_numb;

    if (class_numb == 1)
    {
        //Storing in room 1 File
        file.open("stu_rec_room_1.dat", ios::in | ios::app | ios::binary);
    }
    if (class_numb == 2)
    {
        //Storing in room 2File
        file.open("stu_rec_room_2.dat", ios::in | ios::app | ios::binary);
    }
    else
    {
        cout << "Sorry class number not found";
    }




    file.write(reinterpret_cast<char*>(&s), sizeof(s));//writing to class
    file.close();//closing file
}

void class_1_del()
{
    int count = 0;

    cout << "\n\nPlease enter the student's full name : ";
    cin.getline(name, 51);

    //Opening Room 1 file
    file.open("stu_rec_room_1.dat", ios::in | ios::binary);



    if (file.is_open())
    {
        while (!file.eof())
        {
            while (file.read(reinterpret_cast<char*>(&s), sizeof(s)))// reading the content from the file 
            {
                if ((name == s.full_name)) // searching the record by name
                {
                    cout << "\n\nFirst Name  : " << s2.full_name << "\n";
                    cout << "Gender          : " << s2.gen << "\n";
                    cout << "Maths           : " << s2.maths << "\n";
                    cout << "Science         : " << s2.sci << "\n";
                    cout << "Writing         : " << s2.writing << "\n";
                    cout << "Reading         : " << s2.read << "\n";
                    cout << s2.other_name << ":" << s2.other << "\n";
                    cout << "Overall Progress: " << s2.overall_prog << "\n";
                }
                else
                {
                    count++;
                    tempfile.open("temp.dat", ios::out | ios::app | ios::binary); // opening in a read mode
                    tempfile.write(reinterpret_cast<char*>(&s), sizeof(s));
                    tempfile.close();

                }
            }
        }
    }

    cout << "\n\n No of records stored : " << count;


    file.close();


    cout << "\nDisplay the records after deletion\n";
    remove("stu_rec_room_1.dat");
    rename("temp.dat", "stu_rec_room_1.dat");
    tempfile.open("temp.dat", ios::in | ios::binary | ios::beg); // opening in a read mode



    while (tempfile.read(reinterpret_cast<char*>(&s), sizeof(s))) // reading the content from the file 
    {
        cout << "\n\nFirst Name  : " << s2.full_name << "\n";
        cout << "Gender          : " << s2.gen << "\n";
        cout << "Maths           : " << s2.maths << "\n";
        cout << "Science         : " << s2.sci << "\n";
        cout << "Writing         : " << s2.writing << "\n";
        cout << "Reading         : " << s2.read << "\n";
        cout << s2.other_name << ":" << s2.other << "\n";
        cout << "Overall Progress: " << s2.overall_prog << "\n";
    }


    tempfile.close();
}




void class_2_del()
{
    int count = 0;

    cout << "\n\nPlease enter the student's full name : ";
    cin.getline(name, 51);

    //Opening Room 2 file
    file.open("stu_rec_room_2.dat", ios::out | ios::binary);




    if (file.is_open())
    {
        while (!file.eof())
        {
            while (file.read(reinterpret_cast<char*>(&s), sizeof(s)))// reading the content from the file 
            {
                if ((name == s.full_name)) // searching the record by name
                {
                    cout << "\n\nFirst Name  : " << s2.full_name << "\n";
                    cout << "Gender          : " << s2.gen << "\n";
                    cout << "Maths           : " << s2.maths << "\n";
                    cout << "Science         : " << s2.sci << "\n";
                    cout << "Writing         : " << s2.writing << "\n";
                    cout << "Reading         : " << s2.read << "\n";
                    cout << s2.other_name << ":" << s2.other << "\n";
                    cout << "Overall Progress: " << s2.overall_prog << "\n";
                }
                else
                {
                    count++;
                    tempfile.open("temp.dat", ios::out | ios::app | ios::binary); // opening in a read mode
                    tempfile.write(reinterpret_cast<char*>(&s), sizeof(s));
                    tempfile.close();

                }
            }
        }
    }

    cout << "\n\n No of records stored : " << count;


    file.close();


    cout << "\nDisplay the records after deletion\n";
    remove("stu_rec_room_2.dat");
    rename("temp.dat", "stu_rec_room_2.dat");
    tempfile.open("temp.dat", ios::in | ios::binary | ios::beg); // opening in a read mode



    while (tempfile.read(reinterpret_cast<char*>(&s), sizeof(s))) // reading the content from the file 
    {
        cout << "\n\nFirst Name  : " << s2.full_name << "\n";
        cout << "Gender          : " << s2.gen << "\n";
        cout << "Maths           : " << s2.maths << "\n";
        cout << "Science         : " << s2.sci << "\n";
        cout << "Writing         : " << s2.writing << "\n";
        cout << "Reading         : " << s2.read << "\n";
        cout << s2.other_name << ":" << s2.other << "\n";
        cout << "Overall Progress: " << s2.overall_prog << "\n";
    }


    tempfile.close();
}
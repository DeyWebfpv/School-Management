#include<fstream>
#include<cstring>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;


void teacher();
void student2();


class student
{
    private:

    int day_birth, month_birth, year_birth,day_admission,month_admission,year_admisssion, roll_no;
    float percentage;
    char teacher[15], roomno[10], name[25], address[35], phone[10], gender, scholar, emailid[35], section, status, stream[15],adm[4], newmail[35];

    public:

    void SEC(char c);
    void ADMIT(char s) ;
    void LISTCLASS();
    void LISTCLASS2(char t, char name[35]);
    void LISTCLASS3(char t, int rno);
    void DISPLAY();
    void STATUS();
    void ASSIGNTEACHER();
    void ASSIGNROOM();
    void copy();
    void showroom (char c);
    void showteacher(char c);

    int retroll_no()
    {
        return roll_no;
    }

    char retsec()
    {
        return section;
    }

    char *retname()
    {
        return name ;
    }

    char *retteacher()
    {
        return teacher;
    }

    char *retadmno()
    {
        return adm;
    }


    char retstatus()
    {
        return status;
    }

    float retpercentage()
    {
        return percentage;
    }

    void change_phone(char new_phone[10])
    {
        strcpy (phone, new_phone);
    }

    void change_address (char new_address[35])
    {
        strcpy (address, new_address);
    }

    void change_email(char new_email[35])
    {
        strcpy (emailid, new_email);
    }

    void displayname()
    {
        cout<<name<<endl;
    }
};


void student:: ADMIT(char s)
{
    cout<<"Enter Student Name"<<endl;
    cin.clear();
    fflush(stdin);
    cin.get();
    cin.getline(name,35);
    fflush(stdin);
    cout<<"Enter Gender (F:Female M:Male)";
    cin>>gender;

    switch(toupper(s))

    {
        case 'A': strcpy(roomno,"A101");
        strcpy(teacher,"Preeti Mishra");
        break;
        case 'B': strcpy(roomno, "A102");
        strcpy(teacher,"Malini Goel");
        break;
        case 'C': strcpy(roomno, "A103");
        strcpy(teacher, "Robert Dave");
        break;
        case 'D': strcpy(roomno, "A104");
        strcpy(teacher,"Rajeev Malik");
        break;
        case 'E': strcpy(roomno,"A105");
        strcpy(teacher, "Sangeeta Dash");
        break;
        default : cout<<"Enter valid section i.e. one of 'A', 'B', 'C', 'D', E"<<endl;
        cin>>section;
    }

    cout<<"Enter Stream"<<endl;
    cin.get();
    cin.getline (stream,15);
    cout<<"Enter email id"<<endl;
    cin.get();
    cin.getline (emailid,35);
    cout<<"Enter Mobile No.(10 digits only)"<<endl;
    cin.get();
    cin.getline (phone,10);
    cout<<"Enter Address"<<endl;
    cin.get();
    cin.getline (address,35);
    cout<<"Enter Date of Birth-dd/mm/yyyy"<<endl;
    cin>>day_birth;
    cout<<"/";
    cin>>month_birth;
    cout<<"/";
    cin>>year_birth;

    if (year_birth < 1990)

    {
        cout<<"Enter the year again (greater than 1990)";
        cin>>year_birth;
    }

    cout<<"enter Date of addmission-dd/mm/yyyy"<<endl;
    cin>>day_admission;
    cout<<"/";
    cin>>month_admission;
    cout<<"/";
    cin>>year_admisssion;

    if (year_admisssion < year_birth)
    {
        cout<<"Enter the year again (later than year of birth)";
        cin>>year_admisssion;
    }

    cout<<"enter the roll number"<<endl;
    cin>>roll_no;
    cout<<"Enter the Admission Number (4 digit no only)"<<endl;
    cin.get();
    cin.getline(adm,4);
    cout<<"Enter the percentage"<<endl;
    cin>>percentage;
    if (percentage >= 100 || percentage <= 0)
    {
        cout<<"This is not a valid input"<<endl;
        cout<<"Please enter again";
        cin>>percentage;
    }
}

void student:: SEC(char c)
{
    section = c;
    switch(toupper(section))
    {
        case 'A': strcpy(roomno,"A101");
        strcpy(teacher,"Pretti Mishra");
        break;
        case 'B': strcpy(roomno, "A102");
        strcpy(teacher,"Malini Goel");
        break;
        case 'C': strcpy(roomno, "A103");
        strcpy(teacher, "Robert Dave");
        break;
        case 'D': strcpy(roomno,"A104");
        strcpy(teacher, "Rajiv Malik");
        break;
        case 'E': strcpy(roomno, "A105");
        strcpy(teacher,"Sangeeta Dash");
        break;
        default :cout<<"No such section available"<<endl<<endl;

    }

}

void student :: LISTCLASS()
{fstream fil;
    char sec;
    cout<<"Enter a paticular section";
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else if(sec == 'E')
    fil.open("studente.dat", ios::binary |ios::in);
    student stud;
    cout<<"Name"<<endl;
    cout<<"Stream"<<endl;
    cout<<"Roll_no"<<endl;
    while(fil.read((char*)&stud, sizeof(stud)))
    { cout<<endl;
        cout<<stud.name<<" "<<stud.stream <<" "<<stud.roll_no<<endl;
    }
    fil.close();
}

void student::STATUS()
{
    student stud;
    fstream fil;
    char sec;
    cout<<"Enter the section of the child";
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if(sec == 'E')
    fil.open("studente.dat", ios::binary |ios::in);
    fil.read((char*)&stud, sizeof(stud));
    if (stud.percentage < 33 || stud.percentage >= 0)
    stud.status = 'F';
    else if(stud.percentage >= 33 && stud.percentage <= 100)
    stud.status = 'P';
    else
    cout<<"Invalid percentage";
    cout<<"status assigned"<<endl;
    if(stud.status == 'P')
        cout<<"\t\tPassed"<<endl;
    else
    cout<<"\t\tFailed"<<endl;
    fil.close();
}

void student::DISPLAY()
{
    student stud;
    fstream fil;
    char sec;
    sec = toupper(sec);
    cout<<"Enter the section of the child";
    cin>>sec;
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if(sec == 'E')
    fil.open("studente.dat", ios::binary |ios::in);
    while(fil.read((char*)&stud, sizeof(stud)))
    {
        cout<<endl<<endl<<"Name:"<<stud.name<<" ";
        cout<<"Gender (F:female M:male):"<<stud.gender<<"endl";
        cout<<"Stream:"<<stud.stream<<"section"<<toupper(sec)<<"("<<stud.roomno<<")";
        cout<<endl;
        cout<<"Email Id :"<<stud.emailid<<endl;
        cout<<"Phone Number:"<<stud.phone<<endl;
        cout<<endl<<"Address:"<<stud.address<<endl;
        cout<<"Date of Birth:"<<stud.day_birth<<"/"<<stud.month_birth<<"/"<<stud.year_birth<<endl;
        cout<<"Date of Admission:"<< stud.day_admission<<"/"<<stud.month_admission<<"/"<<stud.year_admisssion<<endl;
        cout<<"Roll_no:"<<stud.roll_no<<endl;
        cout<<"Admission Nuber:"<<stud.adm<<endl;
        cout<<"percentage:"<<stud.percentage<<endl;
        cout<<"Class Teacher:"<<stud.teacher<<endl;
        if (stud.status == 'F')
        cout<<"FAILED";
        else
        cout<<"PASSED";
    }
}
void student::LISTCLASS2(char t, char name[35])
{   t = toupper(t);
    fstream fil;
    if(t == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(t == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(t == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(t == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if(t == 'E')
    fil.open ("studente.dat",ios::binary|ios::in);
    student stud;
    cout<<"Name \t\t\t\t"<<"Stream \t\t\t\t"<<"Roll_no \t\t\t\t";

    while(fil.read((char*)&stud, sizeof(stud)))
    {
        if (strcmp(stud.retname(),name) == 0)
        cout<<endl<<stud.name<<"\t\t\t\t"<<stud.stream<<"\t\t\t\t"<<stud.roll_no<<endl;
    }
    fil.close();
}

void student::LISTCLASS3(char t,int rno)
{
    toupper(t);
    student stud;
    fstream fil;
    if(t == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(t == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else if
    (t == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(t == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if(t == 'E')
    fil.open("studente.dat",ios::binary|ios::in);
    cout<<"Name \t\t\t\t"<<"Stream \t\t\t\t"<<"Roll_no \t\t\t\t";

    while(fil.read((char*)&stud,sizeof(stud)))
    {
        if (stud.retroll_no() == rno)
        cout<<endl<<stud.name<<"\t\t\t\t"<<stud.stream<<"\t\t\t\t"<<stud.roll_no<<"\t\t\t\t";
    }
    fil.close();
}
void student::showroom(char c)
{
    toupper (c);
    if(c =='A')
    cout<<"YOUR ROOM NO IS A101"<<endl;
    else
    if(c =='B')
    cout<<"YOUR ROOM NO IS A102"<<endl;
    else
    if(c =='C')
    cout<<"YOUR ROOM NO IS A103"<<endl;
    else
    if(c =='D')
    cout<<"YOUR ROOM NO IS A104"<<endl;
    else
    if (c =='E')
    cout<<"YOUR ROOM NO IS A105"<<endl;

}
void student::showteacher(char c)
{
    toupper(c);
    if(c == 'A')
    cout<<"YOUR TEACHER IS PREETI MISRA"<<endl;
    else if(c == 'B')
    cout<<"YOUR TEACHER IS MALINI GOEL"<<endl;
    else if(c == 'C')
    cout<<"YOUR TEACHER IS ROBERT DAVE"<<endl;
    else if(c == 'D')
    cout<<"YOUR TEACHER IS RAJEEV MALIK"<<endl;
    else if (c == 'E')
    cout<<"YOUR TEACHER IS SANGEETA DASH"<<endl;

}
void showstatus(char sec)
{
    fstream fil;
    char ch, name[35];
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if (sec == 'E')
    fil.open("studente.dat", ios::binary | ios::in);
    student s;
    cout<<"enter your name";
    cin.get();
    cin.getline(name,35) ;
    while(fil.read((char*)&s, sizeof(s)))
    if(strcmp(s.retname(),name) == 0)
    {
        if(s.retstatus() == 'F')
        cout<<"Failed"<<endl;
        else
        cout<<"Passed"<<endl;
    }

    fil.close();
    cin.get();

}

void creat()
{
    fstream fil;
    char sec;
    cout<<"ENTER THE SECTION OF THE CHILD"<<endl;
    cin>>sec;
    sec = toupper(sec);
    if(sec=='A')
    fil.open("studenta.dat", ios::binary | ios::app);
    else
    if(sec=='B')
    fil.open("studentb.dat", ios::binary | ios::app);
    else
    if(sec=='C')
    fil.open("studentc.dat", ios::binary | ios::app);
    else
    if(sec=='D')
    fil.open("studentd.dat", ios::binary | ios::app);
    else
    if (sec=='E')
    fil.open("studente.dat", ios::binary | ios::app);
    student s;
    char ch;
    do
    {
        s.ADMIT(sec);
        fil.write((char*)&s, sizeof(s));
        cout<<"MORE(Y/N)"<<endl;
        cin>>ch;
    }while(ch != 'N');
    fil.close();
}

void searchroll_no()
{
    fstream fil;
    char sec;
    cout<<"ENTER THE SECTION OF THE CHILD ";
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if (sec == 'E')
    fil.open("studente.dat", ios::binary | ios::in);
    student s;
    int roll_nono,found = 0;
    cout<<"Enter the Roll_no to be searched"<<endl;
    cin>>roll_nono;
    while(fil.read((char*)&s, sizeof(s)))
    {
        if(s.retroll_no() == roll_nono)
        {
            s.LISTCLASS3(sec,roll_nono);
            found++;
        }
    }
    fil.close();
    if(!found)
    cout<<roll_nono<<"Roll_no not found in the paticular section"<<endl;

}

void searchname()
{
    fstream fil;
    char sec ;
    cout<<"ENTER THE SECTION OF THE CHILD "<<endl;
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if (sec == 'E')
    fil.open("studente.dat", ios::binary | ios::in);
    student s;
    char name[10];
    int found = 0;
    cout<<"ENTER THE NAME"<<endl;
    cin.get();
    cin.getline(name,35);
    while(fil.read((char*)&s,sizeof(s)))
    {
        if(strcmp(s.retname(),name) == 0)
        {
            s.LISTCLASS2(sec,name);
            found++;
        }
    }
    fil.close();
    if(!found)
    cout<<name<<"Name not found in the paticular section"<<endl;

}

void sortname()
{
    fstream fil;
    char sec;
    cout<<"ENTER THE SECTION OF YOUR CHILD"<<endl;
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if (sec == 'E')
    fil.open("studente.dat", ios::binary | ios::in);
    student s, sj,sjp1;
    fil.seekg(0,ios::end);
    int nor=fil.tellg()/sizeof(s);
    for(int i = 0;i < nor-1; i++)
    {
        for(int j = 0;j < nor-1-i; j++)
        {
            fil.seekg(j*(sizeof(sj)));
            fil.read((char*)&sj,sizeof(sj));
            fil.read((char*)&sjp1,sizeof(sjp1));
            if(strcmp (sj.retname(),sjp1.retname()) > 0)
            {
                fil.seekp(j*sizeof(sj));
                fil.write((char*)&sjp1,sizeof(sjp1));
                fil.write((char*)&sj,sizeof(sj));
            }
        }
    }
    fil.close();
}

void remove()
{
    fstream fil,fil2;
    char sec;
    cout<<"ENTER THE SECTION OF THE CHILD "<<endl;
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat", ios::binary | ios::in);
    else
    if(sec == 'B')
    fil.open("studentb.dat", ios::binary | ios::in);
    else
    if(sec == 'C')
    fil.open("studentc.dat", ios::binary | ios::in);
    else
    if(sec == 'D')
    fil.open("studentd.dat", ios::binary | ios::in);
    else
    if (sec == 'E')
    fil.open("studente.dat",ios::binary|ios::in);

    fil2.open("temp.dat",ios::binary|ios::out);
    int roll_no, del = 0;
    student s;
    cout<<"Enter the Roll_no to be deleted"<<endl;
    cin>>roll_no;
    while(fil.read((char*)&s,sizeof(s)))
    {
        if(s.retroll_no() != roll_no)
        {
            fil2.write((char*)&s,sizeof(s));
            remove("fil1.dat");
            rename("fil1.dat", "fil2.dat");
        }
        else
        del++;
    }
    fil.close();
    fil2.close();
    if(!del)
    cout<<"No Record Deleted"<<endl;
    else
    cout<<"Roll_no"<<roll_no<<"deleted"<<endl;

}
void modify()
{

    char ch;
    fstream fil;
    char sec,name[35];
    char new_phno[10],new_address[35],new_mailid[35];
    student s;
    cout<<"Enter section of the child whose details are to be changed:";
    cin>>sec;
    sec = toupper(sec);
    if(sec == 'A')
    fil.open("studenta.dat",ios::binary|ios::in|ios::out);
    else if (sec == 'B')
    fil.open("studentb.dat",ios::binary|ios::in|ios::out);
    else if (sec == 'C')
    fil.open("studentc.dat",ios::binary|ios::in|ios::out);
    else if (sec == 'D')
    fil.open("studentd.dat",ios::binary|ios::in|ios::out);
    else if (sec == 'E')
    fil.open("studente.dat",ios::binary|ios::in|ios::out);
    cout<<"Enter name of the child:";
    cin.get();
    cin.getline(name,35);
    while(fil.read((char*)&s,sizeof(s)))
    {

        if(strcmp(s.retname(),name) == 0)
        {


            cout<<"\n Select the following option to edit database information"<<endl;
            cout<<"1. Phone number"<<endl;
            cout<<"2. Address"<<endl;
            cout<<"3. Email-ID"<<endl;
            cout<<"Enter your choice";
            cin>>ch;

            switch(ch)
            {
                case '1':
                cout<<"Enter new phone no";
                cin>>(new_phno);
                s.change_phone(new_phno);
                break;
                case '2':
                cout<<"Enter the new address";
                cin.get();
                cin.getline(new_address,35);
                s.change_address(new_address);
                break;
                case '3':
                cout<<"Enter the emailid";
                cin.get();
                cin.getline(new_mailid,35);
                s.change_email(new_mailid);
                break;
            }
        }
        else
        cout<<"Sorry invalid user"<<endl;
        int pos=fil.tellg();
        fil.seekp(pos-sizeof(s));
        fil.write((char*)&s, sizeof(s));
    }
    fil.close();
}
int menu1()
{
    int ret;
    cout<<"1.CHECK ROOM NO.ASSIGNED"<<endl;
    cout<<"2.CHECK TEACHER ASSIGNED"<<endl;
    cout<<"3.CHECK STATUS"<<endl;
    cout<<"4.LOG OFF STUDENT"<<endl;
    cout<<endl<<endl<<"ENTER THE CHOICE";
    do
    {
        cin>>ret;
        if (ret < 1 || ret > 4)
        cout<<"ENTER VALID CHOICE ONLY"<<endl;
    } while(ret < 1 || ret > 4);
      return ret;
}

void student2()
{
    fstream fil;
    student s;
    int val;
    char ch ;
    cout<<endl;
    cout<<"ENTER YOUR SECTION"<<endl;
    cin>>ch;
    ch = toupper(ch);
    do
    {
        val = menu1();
        if(val != 4)
        {
            if(ch == 'A')
            {
                if(val == 1)
                {
                    s.showroom(ch);

                }
                else if(val == 2)
                {
                    s.showteacher(ch);
                }
                else
                {
                    showstatus(ch);
                }
            }
            else if (ch == 'B')
            {


                if(val == 1)
                {
                    s.showroom(ch);
                }
                else if(val == 2)
                {
                    s.showteacher(ch);
                }
                else
                {
                    showstatus(ch);
                }
            }

            else if(ch == 'C')
            {
                if(val == 1)
                {
                    s.showroom(ch);
                }
                else if(val == 2)
                {
                    s.showteacher(ch);

                }
                else
                {
                    showstatus(ch);
                }
            }
            else if(ch== 'D')
            {
                if(val == 1)
                {
                    s.showroom(ch);
                }
                else if(val == 2)
                {
                    s.showteacher(ch);
                }
                else
                {
                    showstatus(ch);
                }
            }
            else if(ch == 'E')
            {
                if(val == 1)
                {
                    s.showroom(ch);
                }
                else if(val == 2)
                {
                    s.showteacher(ch);
                }
                else
                {
                    showstatus(ch);
                }
            }
            else
            cout<<"LOGGING OFF STUDENT"<<endl;
        }
    } while (val != 4);
}

void teacher()
{
    int n;
    student s;

        do
        {
            cout<<"1.ENTER THE STUDENTS DETAILS"<<endl;
            cout<<"2.LIST OF STUDENTS OF A SECTION"<<endl;
            cout<<"3. DISPLAY STUDENTS DETAILS"<<endl;
            cout<<"4.SEARCH BY Roll_no "<<endl;
            cout<<"5. SEARCH BY STUDENT NAME"<<endl;
            cout<<"6. SORT BY NAME "<<endl;
            cout<<"7.REMOVE STUDENT FROM A SECTION"<<endl;
            cout<<"8. MODIFY THE DETAILS"<<endl;
            cout<<"9.LOG OFF TEACHER"<<endl;
            cout<<" ENTER YOUR CHOICE"<<endl;
            cin>>n;
            if(n == 1)
            {
                creat();
                cin.get();
            }
            else if(n == 2)
            {
                s.LISTCLASS();
                cin.get();
            }
            else if(n == 3)
            {
                s.DISPLAY();
                cin.get();
            }
            else if(n == 4)
            {
                searchroll_no();
                cin.get();
            }
            else if(n == 5)
            {
                searchname();
                cin.get();
            }
            else if(n == 6)
            {
                sortname();
                cin.get();
            }
            else if(n == 7)
            {
                remove();
                cin.get();
            }
            else if(n == 8)
            {
                modify();
                cin.get();
            }
            else if(n == 9)
            cout<<"THANK YOU"<<endl;
            cout<<"Want to do anything else?"<<endl;
            cout<<"Press any number between 1 - 9"<<endl;
            cin>>n;
        } while(n <= 10);
}

int main()
{
    char ch;
        cout<<"******************************"<<endl;
        cout<<" WELCOME TO SCHOOL MANAGMENT "<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<" WANT TO SIGN IN AS TACHER OR AS STUDENT?"<<endl;
        cout<<"a. Teacher"<<endl;
        cout<<"b. Student"<<endl;
            cin>>ch;

        if (ch == 'a')
         teacher();
        else
        student2();
    cout<<endl<<"THANK YOU"<<endl;
    return 0;
}

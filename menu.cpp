#include "header.h"


typedef struct  account {

    string account_username;
    string first_name;
    string last_name;
    string email_address;
    string account_password;

}account;
vector <account>Accounts_info;
vector <account>Students_account_info;

class TeachersLogInManager
{

    public:
        string userNameAttempt;
        string passwordAttempt;
        vector <account>accounts_info;
        int who;
        TeachersLogInManager(int x)
        {
            who = x;
        }
        bool login(bool who)
        {
            while(1)
            {
                if(who==1)
                {
                    accounts_info = Accounts_info;
                }
                else if(who==0)
                {
                    accounts_info = Students_account_info;
                }
                cout << "\n\t\t\t\t\tYou need to enter username and password\n\t\t\t\t\tUsername and Password: ";
                cin >> userNameAttempt;
                cin>>passwordAttempt;
                int fl=0;
                for(int i=0;i<accounts_info.size();i++)
                {
                    if(userNameAttempt==accounts_info[i].account_username && passwordAttempt == accounts_info[i].account_password)
                    {
                        fl=1;

                        break;
                    }

                }
                if(fl)
                {
                    cout << "\n\t\t\t\t\tLogged In SUCCESSFULLY!\n";
                    return 1;
                    break;
                }
                else
                {
                    cout << "\n\t\t\t\t\tThis account is not valid.Try again or Create a new Account";
                    return 0;
                    break;
                }

            }

        }
        void Create_LogIn(bool who)
        {
            account ac;
            string your_username;
            string your_firstname;
            string your_lastname;
            string your_email;
            string your_password;
            while(1)
            {
                bool is_valid = 1;
                if(who==1)
                {
                    accounts_info = Accounts_info;
                }
                else if(who==0)
                {
                    accounts_info = Students_account_info;
                }
                cout << "\n\t\t\t\t\tEnter your username : \n";
                cin >> your_username;
                for(int i=0;i<accounts_info.size();i++)
                {
                    if(your_username==accounts_info[i].account_username)
                    {
                        is_valid = 0;
                        cout << "\n\t\t\t\t\tThis username is already taken.Try another.\n";
                        break;
                    }
                }
                if(is_valid)
                {
                    break;
                }
            }
            cout << "\n\t\t\t\t\tEnter your First name : \n";
            cin >> your_firstname;
            cout << "\n\t\t\t\t\tEnter your Last name : \n";
            cin >> your_lastname;
            cout << "\n\t\t\t\t\tEnter your email address : \n";
            cin >> your_email;
            cout << "\n\t\t\t\t\tEnter your password : \n";
            cin >> your_password;
            ac.account_username=your_username;
            ac.first_name=your_firstname;
            ac.last_name = your_lastname;
            ac.email_address = your_email;
            ac.account_password = your_password;
            if(who==1)
            {
                Accounts_info.push_back(ac);
            }
            else if(who==0)
            {
                Students_account_info.push_back(ac);
            }


            cout << "\n\t\t\t\t\tAccount created successfully.Now,Log in to your account\n";
            std::ofstream file;
            if(who==1)
            {
                file.open("teachers_account_info.txt", std::ios_base::app);
            }
            else if(who==0)
            {
                file.open("students_account_info.txt", std::ios_base::app);
            }

            file << ac.account_username << "#" << ac.first_name << "#" << ac.last_name << "#" << ac.email_address << "#" << ac.account_password << "#";
            file.close();

        }

};


void menu()
{
   int t;



   while(1)
   {

       cout<<"\t\t\t\t\t1.Teacher\n\t\t\t\t\t2.Student\n\t\t\t\t\t0.Exit\n";
       cin>>t;
       read_account_info(t);
       if(t==1)
       {
            int x;
            while(1)
            {
                cout<<"\n\t\t\t\t\t1.Create Account\n\t\t\t\t\t2.LogIn\n\t\t\t\t\t0.Menu\n";
                cin>>x;
                if(x==1)
                {
                    TeachersLogInManager app(1);
                    app.Create_LogIn(1);
                }
                else if(x==2)
                {
                    TeachersLogInManager app(1);
                    bool is_success = app.login(1);
                    if(is_success)
                    {
                        cout<<"\n\t\t\t\t\t1.Print Rasch Result\n\t\t\t\t\t2.Print Monte Carlo Result\n\t\t\t\t\t0.Menu\n";
                        int res;
                        cin>>res;
                        if(res==1)
                        {
                            cout << "\n\t\t\t\t\tRasch Result of All Students : \n";
                            system("rasch_result.txt");
                            break;
                        }
                        else if(res==2)
                        {
                            cout << "\n\t\t\t\t\Monte Carlo Result of All Students : \n";
                            system("monte_result.txt");
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }

                }
                else
                {
                    break;
                }
           }

       }
       else if(t==2)
       {
           int x;
            while(1)
            {
                cout<<"\n\t\t\t\t\t1.Create Account\n\t\t\t\t\t2.LogIn\n\t\t\t\t\t0.Menu\n";
                cin>>x;
                if(x==1)
                {
                    TeachersLogInManager app(0);
                    app.Create_LogIn(0);
                }
                else if(x==2)
                {
                    TeachersLogInManager app(0);
                    bool is_success = app.login(0);
                    if(is_success)
                    {
                        //Students Informations required.
                        string stdName,stdId;
                        cout<<"\n\t\t\t\t\tEnter your name: ";
                        cin>>stdName;
                        cout <<"\n\t\t\t\t\tEnter student id(e.g.BSSE1118): ";
                        cin>>stdId;
                        cout << "\n\t\t\t\t\t1.Start By 4 Level Test\n\t\t\t\t\t2.Test By Rasch Algorithm\n\t\t\t\t\t3.Test By Monte Carlo Algo\n\t\t\t\t\t0.Menu\n";
                        cin>>t;
                        if(t==1)
                        {
                            cout << "\n\t\t\t\t\tIf You Want To Skip Question Write \'SKIP\'.You can not skip more than 3 times. \n";
                            readFile();

                        }
                        else if(t==2)
                        {
                            cout << "\n\t\t\t\t\tIf You Want To Skip Question Write \'SKIP\'.You can not skip more than 3 times. \n";
                            rasch(stdName,stdId);
                        }
                        else if(t==0)
                        {
                            break;
                        }
                        else if(t==3)
                        {
                            cout << "\n\t\t\t\t\tIf You Want To Skip Question Write \'SKIP\'.You can not skip more than 3 times.\n";
                            monte(stdName,stdId);
                        }
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\tYou can not able to log in\n";
                        break;
                    }

                }
                else
                {
                    break;
                }
           }

       }
       else if(t==0)
       {
           exit(0);
       }
   }

}

void read_account_info(int who)
{
    FILE *fp;
    char ch;
    string str,info;
    if(who==1)
    {
        fp = fopen("teachers_account_info.txt","r" );
    }
    else if(who==2)
    {
        fp = fopen("students_account_info.txt","r" );
    }
    else if(who==0)
    {
        return;
    }
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF){
        info = info + ch;
    }
    int line=0;
    string teachers_info[1000];

    stringstream X(info);
    while(getline(X, str, '#')) {
        teachers_info[line] = str;
        //cout << teachers_info[line]<<"\n";
        line++;
    }
    account acc;
    for(int i=0;i<line;i++)
    {
        if(i%5==0)
        {
            acc.account_username = teachers_info[i];
            //cout << acc.account_username << "\n";
        }
        else if(i%5==1)
        {
            acc.first_name = teachers_info[i];
            //cout << acc.first_name << "\n";
        }
        else if(i%5==2)
        {
            acc.last_name = teachers_info[i];
            //cout << acc.last_name << "\n";
        }
        else if(i%5==3)
        {
            acc.email_address = teachers_info[i];
            //cout << acc.email_address << "\n";
        }
        else if(i%5==4)
        {
            acc.account_password = teachers_info[i];
            //cout << acc.account_password << "\n";
            if(who==1)
            {
                Accounts_info.push_back(acc);
            }
            else if(who==2)
            {
                Students_account_info.push_back(acc);
            }
        }

    }

    /*for(int i=0;i<Accounts_info.size();i++)
    {
        cout << Accounts_info[i].account_username << " " << Accounts_info[i].account_password << "\n";
    }*/

    fclose(fp);
}

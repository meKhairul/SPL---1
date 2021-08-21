#include "header.h"


typedef struct  account {

    string account_username;
    string first_name;
    string last_name;
    string email_address;
    string account_password;

}account;
vector <account>Accounts_info;

class TeachersLogInManager
{

    public:
        string userNameAttempt;
        string passwordAttempt;
        TeachersLogInManager()
        {

        }
        void login()
        {
            while(1)
            {
                cout << "\n\t\t\t\t\tYou need to enter username and password\n\t\t\t\t\tUsername and Password: ";
                cin >> userNameAttempt;
                cin>>passwordAttempt;
                int fl=0;
                for(int i=0;i<Accounts_info.size();i++)
                {
                    if(userNameAttempt==Accounts_info[i].account_username && passwordAttempt == Accounts_info[i].account_password)
                    {
                        fl=1;

                        break;
                    }

                }
                if(fl)
                {
                    cout << "\n\t\t\t\t\tLogged In SUCCESSFULLY!\n";
                    break;
                }
                else
                {
                    cout << "\n\t\t\t\t\tThis account is not valid.Try again or Create a new Account";
                    break;
                }

            }

        }
        void Create_LogIn()
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
                cout << "\n\t\t\t\t\tEnter your username : \n";
                cin >> your_username;
                for(int i=0;i<Accounts_info.size();i++)
                {
                    if(your_username==Accounts_info[i].account_username)
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
            Accounts_info.push_back(ac);

            cout << "\n\t\t\t\t\tAccount created successfully.Now,Log in to your account\n";
            std::ofstream file;

            file.open("teachers_account_info.txt", std::ios_base::app);
            file << ac.account_username << "#" << ac.first_name << "#" << ac.last_name << "#" << ac.email_address << "#" << ac.account_password << "#";
            file.close();

        }

};


void menu()
{
   int t;

   read_account_info();

   while(1)
   {

       cout<<"\t\t\t\t\t1.Teacher\n\t\t\t\t\t2.Student\n\t\t\t\t\t0.Exit\n";
       cin>>t;

       if(t==1)
       {
            int x;
            while(1){
                cout<<"\t\t\t\t\t1.Create Account\n\t\t\t\t\t2.LogIn\n\t\t\t\t\t0.Menu\n";
                cin>>x;
                if(x==1)
                {
                    TeachersLogInManager app;
                    app.Create_LogIn();
                }
                else if(x==2)
                {
                    TeachersLogInManager app;
                    app.login();
                }
                else
                {
                    break;
                }
           }

       }
       else if(t==2)
       {
            //Students Informations required.
            string stdName,stdId;
            cout<<"\n\t\t\t\t\tEnter your name: ";
            cin>>stdName;
            cout <<"\n\t\t\t\t\tEnter student id(e.g.BSSE1118): ";
            cin>>stdId;
            cout << "\t\t\t\t\t1.Start By 4 Level Test\n\t\t\t\t\t2.Test By Rasch Algorithm\n\t\t\t\t\t3.Test By Monte Carlo Algo\n\t\t\t\t\t0.Exit\n";
            cin>>t;
            if(t==1)
            {
                cout << "If You Want To Skip Question Write \'SKIP\' \n";
                readFile();

            }
            else if(t==2)
            {
                cout << "If You Want To Skip Question Write \'SKIP\' \n";
                rasch(stdName,stdId);
            }
            else if(t==0)
            {
                exit(0);
            }
            else if(t==3)
            {
                cout << "If You Want To Skip Question Write \'SKIP\' \n";
                monte(stdName,stdId);
            }
       }
       else if(t==0)
       {
           exit(0);
       }
   }

}

void read_account_info()
{
    FILE *fp;
    char ch;
    string str,info;
    fp = fopen("teachers_account_info.txt","r" );
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
            Accounts_info.push_back(acc);
        }

    }

    for(int i=0;i<Accounts_info.size();i++)
    {
        cout << Accounts_info[i].account_username << " " << Accounts_info[i].account_password << "\n";
    }

    fclose(fp);
}

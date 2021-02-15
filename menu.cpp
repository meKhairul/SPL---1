#include "header.h"


class TeachersLogInManager{

    public:
        string userNameAttempt;
        string passwordAttempt;
        TeachersLogInManager()
        {

        }
        void login()
        {
            cout << "\n\t\t\t\t\tYou need to enter username and password\n\t\t\t\t\tUsername: ";
            cin >> userNameAttempt;
            if(userNameAttempt==userName)
            {
                cout << "\n\t\t\t\t\tPassword: ";
                cin>>passwordAttempt;
                if(passwordAttempt==password)
                {
                    cout << "\n\t\t\t\t\tLogged In SUCCESSFULLY!\n";
                    //Searching Function required.
                }
            }
        }
    private:
        string userName = "iitdu";
        string password = "iit123";

};

void menu()
{
   int t;
   while(1)
   {

       cout<<"\t\t\t\t\t1.Teacher\n\t\t\t\t\t2.Student\n\t\t\t\t\t0.Exit\n";
       cin>>t;
       if(t==1)
       {
           TeachersLogInManager app;
           app.login();
       }
       else if(t==2)
       {
            //Students Informations required.
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
                rasch();
            }
            else if(t==0)
            {
                exit(0);
            }
            else if(t==3)
            {
                cout << "If You Want To Skip Question Write \'SKIP\' \n";
                monte();
            }
       }
       else if(t==0)
       {
           exit(0);
       }
   }

}

#include "header.h"

void menu()
{
   int t;
   while(1)
   {
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

}

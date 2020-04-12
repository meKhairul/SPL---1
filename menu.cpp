#include "header.h"

void menu()
{
   int t;
   while(1)
   {
       cout << "\t\t\t\t\t1.Start By 4 Level Test\n\t\t\t\t\t2.Test By Rasch Algorithm\n\t\t\t\t\t3.Exit\n";
       cin>>t;
       if(t==1)
       {
           readFile();

       }
       if(t==2)
       {
           rasch();
       }
       if(t==3)
       {
           exit(0);
       }
   }

}

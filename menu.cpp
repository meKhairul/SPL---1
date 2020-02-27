#include "header.h"

void menu()
{
   int t;
   while(1)
   {
       cout << "\t\t\t\t\t1.Start Test\n\t\t\t\t\t2.Performance";
       cin>>t;
       if(t==1)
       {
           Test();
       }
       if(t==2)
       {
           Calculate_Performance();
       }
   }


}

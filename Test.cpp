#include "header.h"

void Test()
{
    //ifstream in;
    char a[2],s[100];
    int i=0;
    FILE *in;
    in = fopen("ques.txt","r");
    if(in == NULL){
        cout <<"Invalid";
    }
    while(1)
    {
        fgets(s,100,in);
        int x=0;
        if(s[0]=='0')
        {
            break;
        }
        cout<<endl<<s;
        if(i==4)
        {
            fgets(a,2,in);

            //cout <<"ans="<< a ;
            //in.get(a);
            char ans;
            cout<<"\nans:";
            cin>>ans;
            i=-2;
            if(ans==a[0])
            {
                x=x+5;
                cout<<" *Your ans  correct.\n";
            }
            else
            {
                if(x>0)
                    x=x-2.5;
                cout<<" # Wrong ans.\n";
            }
            if(a[0]=='0')
            {
            break;
            }
        }
        i++;
    }
    fclose(in);
}

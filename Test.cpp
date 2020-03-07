#include "header.h"

void Test(string EasyQarr[])
{

    int counts=0,make[20]={0};
    string ans;
    while(counts<20)
    {
        int random = rand()%20;
        if(random%2==0&&make[random]==0)
        {
            counts++;
            cout << EasyQarr[random] << endl;
            make[random]=1;
            cin>>ans;
            if(ans==EasyQarr[random+1])
            {
                cout << "answer is correct\n";
            }
            else
                cout << "wrong answer\n";
        }

    }
}

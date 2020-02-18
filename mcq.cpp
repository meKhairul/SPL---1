#include<bits/stdc++.h>
using namespace std;
class contest
{
private:
    int roll;
    float x;
    char name[20];
    char s[100],ans;

public:
    contest()
    {
        x=0;
    }
    void init();
    void define();
    void display();
};
void  contest :: define()
{
    //ifstream in;
    char a[2];
    int i=0;
    FILE *in;
    in = fopen("ques.txt","r");
    if(in == NULL){
        cout <<"hhh";
    }
    while(1)
    {
        fgets(s,100,in);
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
void contest :: init()
{
    cout<<"\t\t\t   Examinee Name:";
    cin>>name;
    cout<<"\t\t\t   Examinee roll:";
    cin>>roll;
}
void contest :: display()
{
    cout<<"\n **Result:\n";
    cout<<"\t"<<name<<" you got total "<<x<<" marks,out of 50.\n";
}

int main()
{
    //clrscr();
    contest r;
    cout<<"      \t\t\t~~~*** QUIZ CONTEST ***~~~\t      Total Marks:50\n\n";
    r.init();
    cout<<"\t*5 marks per Ques(half negative marking for wrong ans)";
L:
    cout<<"\n\n\tselect your choice:\n"
        <<"\n\t1 for start exam"
        <<"\n\t0 for quit the exam :";
    int c;
    cin>>c;
    switch(c)
    {
    case 1:
        r.define();
        r.display();
        break;
    case 0:
        exit(1);
    default:
        cout<<"invalid choice!";
        goto L;
    }
    //getch();
    return 0;
}

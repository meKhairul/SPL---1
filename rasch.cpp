#include"header.h"

string Rasch[140][10000];
int arr[140],check[140][10000];
void ReadRasch()
{

    FILE *fp;
    char ch;
    string str,question;
    fp = fopen("rasch.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF)
    {
        question = question + ch;
    }
    int ELine=0,i=0;
    stringstream X(question);
    while(getline(X, str, '#'))
    {
        if(ELine==(10*9))
        {
            i++;
            ELine=0;
        }
        Rasch[i][ELine++] = str;
    }
    fclose(fp);

    /*for(int m=0;m<3;m++)
    {
        for(int n=0;n<90;n++)
        {
            cout << Rasch[m][n] << "\n\n";
        }
    }*/
}
int generate_item(double D)
{
    int x;
    string ans;
    D=D*10;
    for(int i=0; i<136; i++)
    {
        if(abs(D-arr[i])<1)
        {
            x=i;
            break;
        }
    }
    cout << x << endl;
    int flag=0;
    while(!flag)
    {
        int random = rand()%90;
        if(random%9==0&&check[x][random]==0)
        {
            cout << Rasch[x][random] << endl;
            check[x][random]=1;
            flag=1;
            int t=0,c[5];
            for(;;)
            {
                int upper = random+8,lower = random+1;
                int ran = (rand()%(upper-lower+1))+lower;
                if(ran%2==1 && random%2==0 && check[x][ran]==0)
                {
                    t++;
                    c[t]=ran;
                    cout << t << "." << Rasch[x][ran] << "\n";
                    check[x][ran]=1;
                }
                else if(ran%2==0 && random%2==1 && check[x][ran]==0)
                {
                    t++;
                    c[t]=ran;
                    cout << t << "." << Rasch[x][ran] << "\n";
                    check[x][ran]=1;
                }
                if(t==4)
                {
                    break;
                }
            }
            cin>>ans;
            if(ans=="1")
            {
                if(Rasch[x][c[1]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//                iter1++;
//                right++;
//                mark++;

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;
                    //cout << "\nYou are Failed\n";
                    //level--;
//                wrong++;
//                mark-=(.25);
//                if(mark<10)
//                {
//                    cout << "\nYou are Failed\n";
//                    cout << "your mark : " << mark << " !";
//                }
//                cout << "\nCorrect answers : " << right << "\n";
//                cout << "\nWrong answers : " << wrong << "\n";
//                break;
                }

            }
            else if(ans=="2")
            {
                if(Rasch[x][c[2]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//                iter1++;
//                right++;
//                mark++;

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;
                    //cout << "\nYou are Failed\n";
                    //level--;
//                wrong++;
//                mark-=(.25);
//                if(mark<10)
//                {
//                    cout << "\nYou are Failed\n";
//                    cout << "your mark : " << mark << " !";
//                }
//                cout << "\nCorrect answers : " << right << "\n";
//                cout << "\nWrong answers : " << wrong << "\n";
//                break;
                }

            }
            else if(ans=="3")
            {
                if(Rasch[x][c[3]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//                iter1++;
//                right++;
//                mark++;

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;
                    //cout << "\nYou are Failed\n";
                    //level--;
//                wrong++;
//                mark-=(.25);
//                if(mark<10)
//                {
//                    cout << "\nYou are Failed\n";
//                    cout << "your mark : " << mark << " !";
//                }
//                cout << "\nCorrect answers : " << right << "\n";
//                cout << "\nWrong answers : " << wrong << "\n";
//                break;
                }

            }
            else if(ans=="4")
            {
                if(Rasch[x][c[4]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//                iter1++;
//                right++;
//                mark++;

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;
                    //cout << "\nYou are Failed\n";
                    //level--;
//                wrong++;
//                mark-=(.25);
//                if(mark<10)
//                {
//                    cout << "\nYou are Failed\n";
//                    cout << "your mark : " << mark << " !";
//                }
//                cout << "\nCorrect answers : " << right << "\n";
//                cout << "\nWrong answers : " << wrong << "\n";
//                break;
                }

            }
        }
    }

}

int Stop_rule(int L)
{
    if(L>=15)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void rasch()
{

    ReadRasch();
    double k=-68.0;
    for(int i=0; i<=136; i++)
    {
        arr[i]=k++;
    }
    double L=0.0,R=0.0,T=60.0;
    double B,S,D=-0.0,H=0.0;
Loop:
    while(1)
    {
        int response=generate_item(D);
        L++;
        H=H+D;
        if(!response)
        {
            D=D-(2.0/L);
        }
        else
        {
            R++;
            D=D+(2.0/L);
        }
        if(Stop_rule(L))
        {
            int W = L - R;
            if(W==0)
            {
                B= (H*1.0)/L + log((R-0.5)/(W+0.5));
                S= sqrt(L/(R-.5)*(W+0.5));
            }
            else if(R==0)
            {
                B= H/L + log((R+0.5)/(W-0.5));
                S= sqrt(L/(R+.5)*(W-0.5));
            }
            else
            {
                B = H/L + log(R/W);
                S = sqrt(L/(R*W));
            }
            if( B < (T+S) && B > (T-S) )
            {
                goto Loop;
            }
            else if(B-S > T)
            {
                cout << "Passed\n";
                cout << "Your Ability :" << Calculate_Performance(B) <<"%";
                break;
            }
            else if((B+S)>T)
            {
                cout << "Failed\n";
                cout << "Your Ability :" << Calculate_Performance(B) <<"%";
                break;
            }
        }
    }

}

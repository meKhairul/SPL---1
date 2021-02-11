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
    for(int i=0; i<137; i++)
    {
        if(abs(D-arr[i])<1)
        {
            x=i;
            break;
        }
    }

    int flag=0;
    while(!flag)
    {
        int random = rand()%90;
        if(random%9==0&&check[x][random]==0)
        {
            question:
            //cout << "Difficulty level : " << x/10 << endl;

            //cout << "x: " << x << " random : " << random << "\n";

            cout << Rasch[x][random] << endl;
            check[x][random]=1;
            flag=1;
            int t=0,c[5];
            for(;;)
            {
                int upper = random+8,lower = random+1;
                int ran = (rand()%(upper-lower+1))+lower;

                //cout << "ran : " << ran << " check[x][ran] : " << check[x][ran] << "\n";

                if(ran%2==1 && random%2==0 && check[x][ran]==0)
                {
                    t++;
                    c[t]=ran;
                    //cout << "ran1 : " << ran << "\n";
                    cout << t << "." << Rasch[x][ran] << "\n";
                    check[x][ran]=1;
                }
                else if(ran%2==0 && random%2==1 && check[x][ran]==0)
                {
                    t++;
                    c[t]=ran;
                    //cout << "ran2 : " << ran << "\n";
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
//

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;

                }

            }
            else if(ans=="2")
            {
                if(Rasch[x][c[2]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;

                }

            }
            else if(ans=="3")
            {
                if(Rasch[x][c[3]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;
//

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;

                }

            }
            else if(ans=="4")
            {
                if(Rasch[x][c[4]+1]=="1")
                {
                    cout << "Good! Your Answer is Correct\n";
                    return 1;

                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    return 0;
                }

            }
            else if(ans=="SKIP")
                {
                    cout << "Are you sure to skip this question??\n";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        flag=0;
                        continue;
                    }
                    else
                    {
                        for(int i=random+1;i<=random+8;i++)
                        {
                            check[x][i]=0;
                        }
                        goto question;
                    }
                }
        }
    }

}

int Stop_rule(int L)
{
    if(L>=20)
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
    double k=-50.0;
    for(int i=0; i<=137; i++)
    {
        arr[i]=k++;
    }
    double L=0.0,R=0.0,T=2.0;
    double B,S,D=0.0,H=0.0;
Loop:
    while(1)
    {
        int response=generate_item(D);
        L++;
        H=H+D;
        if(!response)
        {
            D=D-(2.0/L);
            cout << "D : " << D << "\n";
        }
        else
        {
            R++;
            D=D+(2.0/L);
            cout << "D : " << D << "\n";
        }
        if(Stop_rule(L))
        {
            cout << "stop\n";
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
            cout << "B : " << B << " S: " << S << "\n";
            if( B < (T+S) && B > (T-S) )
            {
                goto Loop;
            }
            else if(B-S > T)
            {
                cout << "You are passed\n";
                cout << "Your Ability :" << Calculate_Performance(B,arr) <<"%\n";
                break;
            }
            else if((B+S)<T)
            {
                cout << "You are failed\n";

                break;
            }
        }
    }

}

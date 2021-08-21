#include "header.h"

void Test(string EasyQarr[],string MediumQarr[] , string HardQarr[] , string SuperHardQarr[])
{
    double mark = 0.0;
    int right=0,wrong=0,make1[10000]={0},make2[10000]={0},make3[10000]={0},make4[10000]={0},level=2;
    string ans;
    check:
    if(level==1)
    {
        //system("color 09");
        cout << "\n*****You are in easy level*****\n\n";
        int iter1=0;
        while(1)
        {
            //system("color 09");
            int random = rand()%90;

            if(random%9==0&&make1[random]==0)
            {
                question1:
                cout << EasyQarr[random] << endl;
                make1[random]=1;
                int t=0,c[5];
                for(;;)
                {
                    int upper = random+8,lower = random+1;
                    int ran = (rand()%(upper-lower+1))+lower;
                    if(ran%2==1 && random%2==0 && make1[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << EasyQarr[ran] << "\n";
                        make1[ran]=1;
                    }
                    else if(ran%2==0 && random%2==1 && make1[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << EasyQarr[ran] << "\n";
                        make1[ran]=1;
                    }
                    if(t==4)
                    {
                        break;
                    }
                }
                cin>>ans;
                if(ans=="1")
                {
                    if(EasyQarr[c[1]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter1++;
                        right++;
                        mark++;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        //level--;
                        wrong++;
                        mark-=(.25);
                        if(mark<10)
                        {
                            cout << "\nYou are Failed\n";
                            cout << "your mark : " << mark << " !";
                        }
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                    }

                    if(iter1==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="2")
                {
                    if(EasyQarr[c[2]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter1++;
                        right++;
                        mark++;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        cout << "\nYou are Failed\n";
                        //level--;
                        wrong++;
                        mark-=(.25);
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                    }

                    if(iter1==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="3")
                {
                    if(EasyQarr[c[3]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter1++;
                        right++;
                        mark++;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        cout << "\nYou are Failed\n";
                        //level--;
                        wrong++;
                        mark-=(.25);
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                    }

                    if(iter1==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="4")
                {
                    if(EasyQarr[c[4]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter1++;
                        right++;
                        mark++;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        cout << "\nYou are Failed\n";
                        //level--;
                        wrong++;
                        mark-=(.25);
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                    }

                    if(iter1==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="SKIP")
                {
                    cout << "Are you sure to skip this question??";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        goto check;
                    }
                    else
                    {
                        for(int i=random+1;i<=random+8;i++)
                        {
                            make1[i]=0;
                        }
                        goto question1;
                    }
                }

            }

        }
    }

    else if(level==2)
    {
        cout << "\n*****You are in medium level***** \n";
        int iter2=0;
        while(1)
        {
            int random = rand()%90;

            if(random%9==0&&make2[random]==0)
            {
                question2:
                cout << MediumQarr[random] << endl;
                make2[random]=1;
                int t=0,c[5];
                for(;;)
                {
                    int upper = random+8,lower = random+1;
                    int ran = (rand()%(upper-lower+1))+lower;
                    if(ran%2==1 && random%2==0 && make2[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << MediumQarr[ran] << "\n";
                        make2[ran]=1;
                    }
                    else if(ran%2==0 && random%2==1 && make2[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << MediumQarr[ran] << "\n";
                        make2[ran]=1;
                    }
                    if(t==4)
                    {
                        break;
                    }
                }
                cin>>ans;

                if(ans=="1")
                {
                    if(MediumQarr[c[1]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter2++;
                        right++;
                        mark+=2;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(0.5);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter2==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="2")
                {
                    if(MediumQarr[c[2]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter2++;
                        right++;
                        mark+=2;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(0.5);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter2==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="3")
                {
                    if(MediumQarr[c[3]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter2++;
                        right++;
                        mark+=2;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(0.5);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter2==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="4")
                {
                    if(MediumQarr[c[4]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter2++;
                        right++;
                        mark+=2;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(0.5);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter2==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="SKIP")
                {
                    cout << "Are you sure to skip this question??";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        goto check;
                    }
                    else
                    {
                        for(int i=random+1;i<=random+8;i++)
                        {
                            make2[i]=0;
                        }
                        goto question2;
                    }
                }
            }

        }
    }

    else if(level==3)
    {
        cout << "\n*****You are in hard level***** \n";
        int iter3=0;
        while(1)
        {
            int random = rand()%90;
            if(random%9==0&&make3[random]==0)
            {
                question3:
                cout << HardQarr[random] << endl;
                make3[random]=1;
                int t=0,c[5];
                for(;;)
                {
                    int upper = random+8,lower = random+1;
                    int ran = (rand()%(upper-lower+1))+lower;
                    if(ran%2==1 && random%2==0 && make3[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << HardQarr[ran] << "\n";
                        make3[ran]=1;
                    }
                    else if(ran%2==0 && random%2==1 && make3[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << HardQarr[ran] << "\n";
                        make3[ran]=1;
                    }
                    if(t==4)
                    {
                        break;
                    }
                }
                cin>>ans;

                if(ans=="1")
                {
                    if(HardQarr[c[1]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter3++;
                        right++;
                        mark+=3;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(3*0.25);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }
                    if(iter3==2)
                    {
                        cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }
                }
                else if(ans=="2")
                {
                    if(HardQarr[c[2]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter3++;
                        right++;
                        mark+=3;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(3*0.25);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter3==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="3")
                {
                    if(HardQarr[c[3]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter3++;
                        right++;
                        mark+=3;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(3*0.25);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter3==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }

                }
                else if(ans=="4")
                {
                    if(HardQarr[c[4]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter3++;
                        right++;
                        mark+=3;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark-=(3*0.25);
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter3==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="SKIP")
                {
                    cout << "Are you sure to skip this question??";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        goto check;
                    }
                    else
                    {
                        for(int i=random+1;i<=random+8;i++)
                        {
                            make3[i]=0;
                        }
                        goto question3;
                    }
                }

            }

        }
    }

    else if(level==4)
    {
        int iter4=0;
        while(1)
        {
            int random = rand()%90;
            if(random%9==0&&make4[random]==0)
            {
                question4:
                cout << SuperHardQarr[random] << endl;
                make4[random]=1;
                int t=0,c[5];
                for(;;)
                {
                    int upper = random+8,lower = random+1;
                    int ran = (rand()%(upper-lower+1))+lower;
                    if(ran%2==1 && random%2==0 && make4[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << SuperHardQarr[ran] << "\n";
                        make4[ran]=1;
                    }
                    else if(ran%2==0 && random%2==1 && make4[ran]==0)
                    {
                        t++;
                        c[t]=ran;
                        cout << t << "." << SuperHardQarr[ran] << "\n";
                        make4[ran]=1;
                    }
                    if(t==4)
                    {
                        break;
                    }
                }
                cin>>ans;

                if(ans=="1")
                {
                    if(SuperHardQarr[c[1]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter4++;
                        right++;
                        mark+=4;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark--;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }
                    if(iter4==2)
                    {
                        cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }
                }
                else if(ans=="2")
                {
                    if(SuperHardQarr[c[2]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter4++;
                        right++;
                        mark+=4;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark--;
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter4==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }

                }
                else if(ans=="3")
                {
                    if(SuperHardQarr[c[3]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter4++;
                        right++;
                        mark+=4;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark--;
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter4==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }

                }
                else if(ans=="4")
                {
                    if(SuperHardQarr[c[4]+1]=="1")
                    {
                        cout << "Good! Your Answer is Correct\n";
                        iter4++;
                        right++;
                        mark+=4;
                    }
                    else
                    {
                        cout << "\nOops!Wrong answer\n";
                        //cout << "\nYou are Failed\n";
                        level--;
                        wrong++;
                        mark--;
                        goto check;
                        //cout << "\nCorrect answers : " << right << "\n";
                        //cout << "\nWrong answers : " << wrong << "\n";
                        //break;
                    }

                    if(iter4==2)
                    {
                         cout << "\nCongratulations! You become the winner\n";
                        cout << "\nCorrect answers : " << right << "\n";
                        cout << "\nWrong answers : " << wrong << "\n";
                        break;
                        //level++;
                        //goto check;
                    }
                    else
                        continue;
                }
                else if(ans=="SKIP")
                {
                    cout << "Are you sure to skip this question??";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        goto check;
                    }
                    else
                    {
                        for(int i=random+1;i<=random+8;i++)
                        {
                            make4[i]=0;
                        }
                        goto question4;
                    }
                }
            }

        }
    }

}

#include "header.h"

void Test(string EasyQarr[],string MediumQarr[] , string HardQarr[] , string SuperHardQarr[])
{

    int right=0,wrong=0,make1[20]={0},make2[20]={0},make3[20]={0},make4[20]={0},level=2;
    string ans;
    check:
    if(level==1)
    {
        cout << "\n*****You are in easy level*****\n\n";
        int iter1=0;
        while(1)
        {
            int random = rand()%20;
            if(random%2==0&&make1[random]==0)
            {
                cout << EasyQarr[random] << endl;
                make1[random]=1;
                cin>>ans;
                if(ans==EasyQarr[random+1])
                {

                    cout << "Good! Your Answer is Correct\n";
                    iter1++;
                    right++;
                    if(iter1==2)
                    {
                        level++;
                        goto check;
                    }
                    else
                        continue;
                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    cout << "\nYou are Failed\n";
                    //level--;
                    wrong++;
                    cout << "\nCorrect answers : " << right << "\n";
                    cout << "\nWrong answers : " << wrong << "\n";
                    break;
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
            int random = rand()%20;
            if(random%2==0&&make2[random]==0)
            {
                cout << MediumQarr[random] << endl;
                make2[random]=1;
                cin>>ans;
                if(ans==MediumQarr[random+1])
                {

                    cout << "\nGood! Your Answer is Correct\n";
                    iter2++;
                    right++;
                    if(iter2==2)
                    {
                        level++;
                        goto check;
                        //cout << "Congratulations! You become the winner\n";
                        //cout << "Correct answers : " << right << "\n";
                        //cout << "Wrong answers : " << wrong << "\n";
                        //break;
                    }
                    else
                        continue;
                }
                else
                {
                    cout << "\nOops!Wrong answer\n";
                    level--;
                    wrong++;
                    goto check;
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
            int random = rand()%20;
            if(random%2==0&&make3[random]==0)
            {
                cout << HardQarr[random] << endl;
                make3[random]=1;
                cin>>ans;
                if(ans==HardQarr[random+1])
                {

                    cout << "\nGood! Your Answer is Correct\n";
                    iter3++;
                    right++;
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
                else

                    cout << "Oops!Wrong answer\n";
                    level--;
                    wrong++;
                    goto check;
            }

        }
    }

    else if(level==4)
    {
        int iter4=0;
        while(1)
        {
            int random = rand()%20;
            if(random%2==0&&make4[random]==0)
            {
                cout << SuperHardQarr[random] << endl;
                make4[random]=1;
                cin>>ans;
                if(ans==SuperHardQarr[random+1])
                {

                    cout << "Good! Your Answer is Correct\n";
                    iter4++;
                    right++;
                    if(iter4==2)
                    {
                        cout << "Congratulations! You become the winner\n";
                        break;
                    }
                }
                else

                    cout << "Oops!Wrong answer\n";
                    level--;
                    wrong++;
                    goto check;
            }

        }
    }

}

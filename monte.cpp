#include"header.h"

#define ll long long

double Probability[100],Theta[100],b[100],Difficulty[100],Q[100],Inform[100],Sum_Inform=0.0,std_error[100],Estimate_ability[100];
double visit[140][10000];
string Monte[140][10000];
int answer[100];

void readMonte()
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
        Monte[i][ELine++] = str;
    }
    fclose(fp);
}

int generate_monte(int lower,int upper,int number)
{
    int dif;
    string response;

    int randomly = (rand()%(upper-lower+1))+lower;

    for(int i=0;i<100;i++)
    {
        if(randomly==Difficulty[i])
        {
            dif=i;
            break;
        }
    }
    b[number]=(randomly/10.0);
    Probability[number] = 1/(1+exp(-(1.7*Estimate_ability[number-1])+(Difficulty[dif]/10.0)));
    Q[number] = 1-Probability[number];
    Inform[number] = Probability[number] * Q[number];
    Sum_Inform += Inform[number];
    std_error[number] = sqrt(1.0/Sum_Inform);

    int flag=0,skipable=0;
    while(!flag){
    int random = rand()%90;
    if(random%9==0&&visit[dif][random]==0)
    {
        question:

        flag=1;

        cout << Monte[dif][random] << endl;
        visit[dif][random]=1;

        int t=0,c[5];
        for(;;)
        {
            int up = random+8,low = random+1;
            int ran = (rand()%(up-low+1))+low;



            if(ran%2==1 && random%2==0 && visit[dif][ran]==0)
            {
                t++;
                c[t]=ran;
                //cout << "ran1 : " << ran << "\n";
                cout <<"\n\t\t\t\t\t"<< t << "." << Monte[dif][ran] << "\n";
                visit[dif][ran]=1;
            }
            else if(ran%2==0 && random%2==1 && visit[dif][ran]==0)
            {
                t++;
                c[t]=ran;
                //cout << "ran2 : " << ran << "\n";
                cout <<"\n\t\t\t\t\t"<< t << "." << Monte[dif][ran] << "\n";
                visit[dif][ran]=1;
            }
            if(t==4)
            {
                break;
            }
        }
        cout << "\n\n";
        cout << "\n\t\t\t\t\tDifficulty : " << Difficulty[dif]/10.0 << "\n";
        cout << "\n\t\t\t\t\tProbability : " << Probability[number]*100 << "%\n";
        cout << "\n\t\t\t\t\tQ : " << Q[number]*100 << "%\n";
        cout << "\n\t\t\t\t\tStandard Error : " << std_error[number] << "\n";

        cin>>response;
        if(response=="1")
        {
            if(Monte[dif][c[1]+1]=="1")
            {
                cout << "\n\t\t\t\t\t***Good!!! Your answer is Correct***\n\n";
                return 1;
//

            }
            else
            {
                cout << "\n\t\t\t\t\t***Your answer is incorrect***\n\n";
                return 0;

            }

        }
        else if(response=="2")
        {
            if(Monte[dif][c[2]+1]=="1")
            {
                cout << "\n\t\t\t\t\t***Good!!! Your answer is Correct***\n\n";
                return 1;
//

            }
            else
            {
                cout << "\n\t\t\t\t\t***Your answer is incorrect***\n\n";
                return 0;

            }

        }
        else if(response=="3")
        {
            if(Monte[dif][c[3]+1]=="1")
            {
                cout << "\n\t\t\t\t\t***Good!!! Your answer is Correct***\n\n";
                return 1;
//

            }
            else
            {
                cout << "\n\t\t\t\t\t***Your answer is incorrect***\n\n";
                return 0;

            }

        }
        else if(response=="4")
        {
            if(Monte[dif][c[4]+1]=="1")
            {
                cout << "\n\t\t\t\t\t***Good!!! Your answer is Correct***\n\n";
                return 1;

            }
            else
            {
                cout << "\n\t\t\t\t\t***Your answer is incorrect***\n\n";
                return 0;
            }

        }
        else if(response=="SKIP")
        {
            if(skipable>2)
            {
                cout << "\n\t\t\t\t\tYou can not skip question more than 3 times!\nGive your answer__\n";

                for(int i=random+1; i<=random+8; i++)
                {
                    visit[dif][i]=0;
                }
                goto question;
            }
            cout << "\n\t\t\t\t\tAre you sure to skip this question??\n";
            cout << "\n\t\t\t\t\t1.Yes\n\t\t\t\t\t2.No\n";
            int choice;
            cin>>choice;
            if(choice==1)
            {
                skipable++;
                flag=0;
            }
            else
            {
                for(int i=random+1; i<=random+8; i++)
                {
                    visit[dif][i]=0;
                }
                goto question;
            }
        }
    }
    }
    return 0;
}


void monte(string std_name,string std_id)
{

    readMonte();
    double true_ability;
    //printf("***********Welcome to Monte Carlo CAT System**********\n");
    //printf("Tell me your true ability arround [-3,+3] (any real number) where -3 is the lowest ability and +3 highest  :  ");
    true_ability=0.1;


    Estimate_ability[0]=true_ability;

    double initial_difficulty=-50.0;
    for(int i=0;i<100;i++)
    {
        Difficulty[i]=initial_difficulty++;
    }
    int question=0;
    double sumOf_response=0.0;

    while(question<50)
    {
        question++;
        int lower=(Estimate_ability[question-1]*10)-5,upper=(Estimate_ability[question-1]*10)+5;

        cout << "\n\t\t\t\t\tQuestion number "<< question << ": " << "\n";

        if(generate_monte(lower , upper ,question))
        {
            answer[question]=1;
            sumOf_response += 1.7*(1-Probability[question]);
            Estimate_ability[question] = Estimate_ability[question-1] + (sumOf_response/(1.7*1.7*Sum_Inform));
            //Estimate_ability[question] = Estimate_ability[question-1]*Probability[question];
            cout << "\n\t\t\t\t\tMaximum Likelihood : " << Estimate_ability[question] << "\n";
        }
        else
        {
            answer[question]=0;
            sumOf_response += 1.7*(0-Probability[question]);
            Estimate_ability[question] = Estimate_ability[question-1] + (sumOf_response/(1.7*1.7*Sum_Inform));
            //Estimate_ability[question] = Estimate_ability[question-1]*Q[question];
            cout << "\n\t\t\t\t\tMaximum Likelihood : " << Estimate_ability[question] << "\n";
        }
        if(Estimate_ability[question-1]<=-5.0)
        {
            cout << "\n\t\t\t\t\tYour ability is lower than the lowest difficulty of the question\n";
        }
        if(Probability[question]+std_error[question]<1.0)
        {
            break;
        }

    }
    cout << "\n\t\t\t\t\tQuestion number\tDifficulty\tProbability\tAnswer\tStudent's Ability\tStandard Error\n";
    for(int i=1;i<=question;i++)
    {
        cout << "\n\t\t\t\t" <<setprecision(1)<< "\t" <<i<<"\t  "<<b[i]<<"\t\t"<< Probability[i]<< "\t\t" <<answer[i]<< "\t\t" <<Estimate_ability[i-1]<<"\t\t"<<std_error[i]<<"\n";
    }
    create_monte_result_file(std_name,std_id,question);

}

void create_monte_result_file(string std_name,string std_id,int numOfQuestion)
{
    std::ofstream file;

    file.open("monte_result.txt", std::ios_base::app);
    //fp << "Student Name\t\tStudent Id\t\tAbility\t\tStandard Error\n";
    file << std_name << "\t\t\t" << std_id << "\t\t" << Estimate_ability[numOfQuestion-1] << "\t\t" << std_error[numOfQuestion-1] << "\n\n\n";
    file << "Question number\tDifficulty\tProbability\tAnswer\tStudent's Ability\tStandard Error\n";
    for(int i=1;i<=numOfQuestion;i++)
    {
        file << setprecision(1)<< "\t" <<i<<"\t  "<<b[i]<<"\t\t"<< Probability[i]<< "\t\t" <<answer[i]<< "\t\t" <<Estimate_ability[i-1]<<"\t\t"<<std_error[i]<<"\n";
    }

    file.close();
}

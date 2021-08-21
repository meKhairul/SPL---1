#include"header.h"

string Rasch[140][10000];
int arr[140],check[140][10000];
double std_err,Est_ability,Prob[50];
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

    int flag=0,skip=0;
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
                    if(skip>2)
                    {
                        cout << "You can not skip question more than 3 times!\nGive your answer__";
                        for(int i=random+1;i<=random+8;i++)
                        {
                            check[x][i]=0;
                        }
                        goto question;
                    }
                    cout << "Are you sure to skip this question??\n";
                    cout << "1.Yes\n2.No\n";
                    int choice;
                    cin>>choice;
                    if(choice==1)
                    {
                        skip++;
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
    if(L>15)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void rasch(string std_name,string std_id)
{

    ReadRasch();
    double k=-50.0;
    for(int i=0; i<=137; i++)
    {
        arr[i]=k++;
    }
    double L=0.0,R=0.0,T=2.0;
    double B,S,D=0.0,H=0.0;
    double difficult_level[50];
    int iter=0;

Loop:
    //ofstream file ("student.txt");
    //file << "Student Name\t\tStudent Id\t\tAbility\t\tStandard Error\n";
    while(iter<=30)
    {

        int W = L - R;
        iter++;

        difficult_level[iter]=D;
        L++;
        H=H+D;

        int response=generate_item(D);
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
            double W = L-R;
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
                //file << std_name << "\t\t" << std_id << "\t\t\n";
                cout << "Student's name : " << std_name << "\n";
                cout << "You are passed\n";
                cout << "Your Ability :" << Calculate_Performance(B,arr) <<"%\n";

                generate_score(difficult_level,iter,R,L);
                break;
            }
            else if((B+S)<T)
            {
                //file << std_name << "\t\t" << std_id << "\t\t\n";
                cout << "Student's name : " << std_name << "\n";
                cout << "You are failed\n";
                cout << "Your Ability :" << Calculate_Performance(B,arr) <<"%\n";

                generate_score(difficult_level,iter,R,L);
                break;
            }
        }
        if(iter==30)
        {
            //file << std_name << "\t\t" << std_id << "\t\t\n";
            cout << "Student's name : " << std_name << "\n";
            cout << "You are passed\n";
            cout << "Your Ability :" << Calculate_Performance(B,arr) <<"%\n";
            generate_score(difficult_level,iter,R,L);
        }
    }

    create_student_file(difficult_level,std_name,std_id);


}

void generate_score(double difficulty_level[],int iter,double R,double L)
{
    double d_sum=0.0,D_mean,Varience,raw_score,model_varience,new_est_ability=0.0;
    double W = L-R;
    for(int i=1;i<iter;i++)
    {
        d_sum += difficulty_level[i];
    }
    D_mean = d_sum/iter;
    Varience = count_varience(D_mean,difficulty_level,iter);
    if(R==0)
    {
        R=R+0.5;
        W=W-0.5;
    }
    if(W==0)
    {
        R=R-0.5;
        W=W+0.5;
    }
    cout << "R : " << R << " W: " << W << "\n";
    Est_ability = D_mean + (sqrt(1+(Varience/2.9)))*(log(R/W));
    cout << "1st est ability: " <<Est_ability << "\n";
    while(1)
    {
        if(new_est_ability!=0.0)
        {
            cout << "estimate ability : " << Est_ability << " and new estimate ability : " << new_est_ability << "\n";
            if(abs(Est_ability-new_est_ability )>0.5)
            {
                Est_ability=new_est_ability;
                for(int i=1;i<=iter;i++)
                {
                    Prob[i] = 1.0/(1+exp(difficulty_level[i]-Est_ability));
                    //cout << "probability["<<i<<"] :" << Prob[i]<<"\n";
                    raw_score += Prob[i];
                    model_varience += (Prob[i]*(1-Prob[i]));
                }
                new_est_ability = Est_ability + ((R-raw_score)/model_varience);
            }
            else
            {
                //ofstream file ("student.txt");
                Est_ability = new_est_ability;
                std_err = sqrt(1/model_varience);
                //file << Est_ability << "\t\t" << std_err << "\t\t\n";
                //file.close();
                cout << "And his Estimate ability is : "<< Est_ability << "\n";
                cout << "Standard error : " << std_err << "\n";
                for(int i=1;i<=iter;i++)
                {
                    cout << "Probability of giving correct answer of question number " << i << " is : " << Prob[i] << "\n";
                }

                break;
            }
        }
        else
        {
            for(int i=1;i<=iter;i++)
            {
                Prob[i] = 1.0/(1+exp(difficulty_level[i]-Est_ability));
                raw_score += Prob[i];
                model_varience += (Prob[i]*(1-Prob[i]));
                cout << "Prob["<<i<<"] : " << Prob[i] << "\n";
            }
            new_est_ability = Est_ability + ((R-raw_score)/model_varience);
        }



    }

}

double count_varience(double mean,double arr[],int iter)
{
    double var=0.0,dif;
    for(int i=1;i<=iter;i++)
    {
        dif = abs(arr[i]-mean);
        dif = dif*dif;
        var = var + dif;
    }
    return var/(iter-1);
}

void create_student_file(double difficult_level[],string std_name,string std_id)
{
    //FILE *fp;
    //char ch;
    //string str,question;
    //fp = fopen("student.txt","a" );
    //if(fp==NULL)
    //{
    //    cout << "File isn't open#";
    //}
    //fprintf(fp,"Student Name\t\tStudent Id\t\tAbility\t\tStandard Error\n");
    //fprintf(fp,"%s\t\t\t%s\t\t%lf\t\t%lf\n",std_name,std_id,Est_ability,std_err);
    cout << "Student Name\t\tStudent Id\t\tAbility\t\tStandard Error\n";
    cout << std_name << "\t\t\t" << std_id << "\t\t" << Est_ability << "\t\t" << std_err << "\n";

    std::ofstream file;

    file.open("student.txt", std::ios_base::app); // append instead of overwrite
    //fp << "Student Name\t\tStudent Id\t\tAbility\t\tStandard Error\n";
    file << std_name << "\t\t\t" << std_id << "\t\t" << Est_ability << "\t\t" << std_err << "\n";
    file.close();
}

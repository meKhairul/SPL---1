#include "header.h"
string easyQuestion,mediumQuestion,hardQuestion,superHardQuestion;
string EasyQarr[100],MediumQarr[100],HardQarr[100],SuperHardQarr[100];

void readFile()
{
    FILE *fp;
    char ch;
    string str;
    fp = fopen("easyQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open\n";
    }
    while((ch = fgetc(fp)) != EOF){
        easyQuestion = easyQuestion + ch;
    }
    int ELine=0;
    stringstream X(easyQuestion);
	 while(getline(X, str, '\n')) {
        EasyQarr[ELine++] = str;
    }
    fclose(fp);


    fp = fopen("mediumQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open\n";
    }
    while((ch = fgetc(fp)) != EOF){
        mediumQuestion = mediumQuestion+ch;
    }
    int MLine=0;
    stringstream Y(mediumQuestion);
	 while(getline(Y, str, '\n')) {
        MediumQarr[MLine++] = str;
    }
    fclose(fp);


    fp = fopen("hardQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open\n";
    }
    while((ch = fgetc(fp)) != EOF){
        hardQuestion = hardQuestion+ch;
    }
    int HLine=0;
    stringstream Z(hardQuestion);
	 while(getline(Z, str, '\n')) {
        HardQarr[HLine++] = str;
    }
    fclose(fp);


    fp = fopen("superHardQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open\n";
    }
    while((ch = fgetc(fp)) != EOF){
        superHardQuestion = superHardQuestion+ch;
    }
    int SLine=0;
    stringstream S(superHardQuestion);
	 while(getline(S, str, '\n')) {
        SuperHardQarr[SLine++] = str;
    }
    fclose(fp);

}

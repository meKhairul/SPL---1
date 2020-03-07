#include "header.h"


void readFile()
{
    string easyQuestion,mediumQuestion,hardQuestion,superHardQuestion;
    string EasyQarr[100],MediumQarr[100],HardQarr[100],SuperHardQarr[100];
    FILE *fp;
    char ch;
    string str;
    fp = fopen("easyQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF){
        easyQuestion = easyQuestion + ch;
    }
    int ELine=0;
    stringstream X(easyQuestion);
	 while(getline(X, str, '#')) {
        EasyQarr[ELine++] = str;
    }
    fclose(fp);


    fp = fopen("mediumQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF){
        mediumQuestion = mediumQuestion+ch;
    }
    int MLine=0;
    stringstream Y(mediumQuestion);
	 while(getline(Y, str, '#')) {
        MediumQarr[MLine++] = str;
    }
    fclose(fp);


    fp = fopen("hardQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF){
        hardQuestion = hardQuestion+ch;
    }
    int HLine=0;
    stringstream Z(hardQuestion);
	 while(getline(Z, str, '#')) {
        HardQarr[HLine++] = str;
    }
    fclose(fp);


    fp = fopen("superHardQuestion.txt","r" );
    if(fp==NULL)
    {
        cout << "File isn't open#";
    }
    while((ch = fgetc(fp)) != EOF){
        superHardQuestion = superHardQuestion+ch;
    }
    int SLine=0;
    stringstream S(superHardQuestion);
	 while(getline(S, str, '#')) {
        SuperHardQarr[SLine++] = str;
    }
    fclose(fp);
    Test(EasyQarr);
}


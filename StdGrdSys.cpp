#include<iostream>
using namespace std;

template <class T>
class Grade
{
    public:
        string stdname;
        T grd;

    Grade(string,T);  
    ~Grade(); 
    void Chkgrade();
};

template <class T>
Grade<T> :: Grade(string no1,T no2)
{
    stdname = no1;
    grd = no2;
}

template <class T>
Grade<T> :: ~Grade()
{
    cout<<"*****************************************"<<"\n";   
}

template <class T>
void Grade<T> :: Chkgrade()
{

    if((grd < 0) || (grd > 100))
    {
        cout<<"Incorrect percentage"<<"\n";
        return;
    }


    if((grd <= 35) && (grd >= 0))
    {
        cout<<stdname<<" : you failed"<<"\n";
    }
    else if((grd <= 50) && (grd > 35))
    {
        cout<<stdname<<" : you are pass with average marks"<<"\n";
    }
    else if((grd <= 75) && (grd > 50))
    {
        cout<<stdname<<" : you got A "<<"\n";
    }
    else if((grd <= 90) && (grd > 75))
    {
        cout<<stdname<<" : you got A+ "<<"\n";
    }
    else
    {
        cout<<stdname<<" : you are in distinction"<<"\n";
    }
}

int main()
{   
    string name;
    int grade = 0;
    
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"Welcome to siddharth grading system"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
    
    cout<<"enter student name"<<"\n";
    cin>>name;

    cout<<"Enter the percentage to cheak which grade you get: "<<"\n";
    cin>>grade;
    cout<<"*****************************************"<<"\n";

    Grade <int>G1(name,grade);

    G1.Chkgrade();
    return 0;
}
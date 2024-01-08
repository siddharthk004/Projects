
///////////////////////////////////
//
// name : kardile siddharth satish
//
///////////////////////////////////

#include<iostream>
using namespace std;

template <class T> 
class calci
{
    public:
    T num1;
    T num2;

    calci(T,T);
    ~calci();
    int addition();
    int substraction();
    float multiplication();
    float division();
};

template <class T>
calci<T> :: calci(T no1,T no2)
{
    num1 = no1;
    num2 = no2;
}

template <class T>
calci<T> :: ~calci()
{
    cout<<"\n\n-----------thank you-----------";
}

template <class T>
int calci<T> :: addition()
{
    T sum;
    sum = num1 + num2;
    return sum;
}

template <class T>
int calci<T> :: substraction()
{
    T sub;
    sub = num1 - num2;
    return sub;
}

template <class T>
float calci<T> :: division()
{
    T div;
    div = num1 / num2;
    return div;
}

template <class T>
float calci<T> :: multiplication()
{
    T mult;
    mult = num1 * num2;
    return mult;
}

int main()
{
    int number1;
    int number2;
    float fresult = 0.0f;
    int name = 0;
    cout<<"-----------------------------------------------\n";
    cout<<"Welcome to Siddharth virtual calculator : "<<"\n";
    cout<<"-----------------------------------------------\n";

    cout<<"enter first number : "<<"\n";
    cin>>number1;
    cout<<"-----------------------------------------------\n";
    cout<<"enter second number : "<<"\n";
    cin>>number2;

    calci <int>object(number1,number2);
    
    cout<<"-----------------------------------------------\n";
    cout<<"enter operator to execute the operation on numbers"<<"\n";
    cout<<"-----------------------------------------------\n";

    cout<<"enter 1 for addition "<<"\n";
    cout<<"enter 2 for substraction"<<"\n";
    cout<<"enter 3 for multiplication"<<"\n";
    cout<<"enter 4 for division"<<"\n";
    cout<<"-----------------------------------------------\n";
    cin>>name;
    cout<<"-----------------------------------------------\n";

    if(name == 1)
    {
        fresult = object.addition();
        cout<<"output is : "<<fresult;
    }
    else if(name == 2)
    {
        fresult = object.substraction();
        cout<<"output is : "<<fresult;
    }
    else if(name == 3)
    {
        fresult = object.multiplication();
        cout<<"output is : "<<fresult;
    }
    else if(name == 4)
    {
        fresult = object.division();
        cout<<"output is : "<<fresult;
    }
    else
    {
        cout<<"input was wrong .. "<<"\n";
    }

    return 0;
}
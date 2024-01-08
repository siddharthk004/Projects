///////////////////////////////////////////////////
//
//  NAME : kardile siddharth satish
//
///////////////////////////////////////////////////

#include<iostream>
using namespace std;

class MovieTS
{
    public:
    int seat;

    MovieTS(int no);
    int SelectMovie();
    int SelectMovieSeat(int ST);
    void DisplayTotalSeat(int no);
    float TotalCost(int no);
    int DisplayPayment(float f1);
    void ExitMsg(int confirmation,int no);
};

MovieTS :: MovieTS(int no)
{
    seat = no;
}

int MovieTS :: SelectMovie()
{
    int Mlst = 0;
    cout<<"Today movie shows"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"1 : Apna bana le"<<"\n";
    cout<<"2 : Entertainment"<<"\n";
    cout<<"3 : Mission mangal"<<"\n";
    cout<<"4 : Avengers Endgame"<<"\n";
    cout<<"5 : Iron man 3"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"In this list if you want to choose movie then type their respective number : ";
    cin>>Mlst;

    if(Mlst == 0)
    {
        cout<<"this option is not avaliable sorry"<<"\n";
    }
    else if(Mlst == 1)
    {
        cout<<"congratulations you select: 'Apna bana le'"<<"\n";
    }
    else if(Mlst == 2)
    {
        cout<<"congratulations you select: 'Entertainment'"<<"\n";
    }
    else if(Mlst == 3)
    {
        cout<<"congratulations you select: 'Mission mangal'"<<"\n";
    }
    else if(Mlst == 4)
    {
        cout<<"congratulations you select: 'Avengers Endgame'"<<"\n";
    }
    else if(Mlst == 5)
    {
        cout<<"congratulations you select: 'Iron man 3'"<<"\n";
    }
    else if(Mlst > 5)
    {
        cout<<"this option is not avaliable sorry"<<"\n";
    }

    if((Mlst == 0) || (Mlst > 5))
    {
        return 10;
    }
}

int MovieTS :: SelectMovieSeat(int ST)
{
    int MovieSeat = 0;
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"Remaining seats are : "<<seat<<"\n";
    cout<<"In the theatre total seats are : "<<ST<<"\n";
    cout<<"If you want to select seat in the theatre then type number of seats: "<<"\n";
    cin>>MovieSeat;
    cout<<"-------------------------------------------------"<<"\n";
    if(MovieSeat > ST)
    {
        MovieSeat = 0;
    }
    return MovieSeat;
}

void MovieTS :: DisplayTotalSeat(int no)
{
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"you take "<<no<<"number of seats for movie"<<"\n";
    cout<<"your seats are reserved"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
}

float MovieTS :: TotalCost(int no)
{
    float value = 0.0f;
    float value1 = 0.0f;
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"Total cost of seat : "<<"\n";
    cout<<"Seat "<<no<<"\n";
    cout<<"Rate "<<"350"<<"\n";
    cout<<"GST "<<"18%"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
    value1 = no * 350;
    value = value1;
    value = no * 63;
    value1 = value1 + value;
    cout<<"total : "<<value1<<"\n";
    cout<<"-------------------------------------------------"<<"\n";

    return value1;
}
    
int MovieTS :: DisplayPayment(float f1)
{
    int code = 0;

    cout<<"-------------------------------------------------"<<"\n";
    cout<<"Welcome to Payment system"<<"\n";
    cout<<"your total cost is : "<<f1<<"\n\n";
    cout<<"Make CashFree Payment"<<"\n";
    cout<<"Siddharthk@akhdfcbank"<<"\n";
    cout<<"9552450050@ybl"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";
    cout<<"Press 1 if your payment was succesfull "<<"\n";
    cout<<"Press 0 if your payment was Failed "<<"\n";
    cin>>code;
    cout<<"-------------------------------------------------"<<"\n";

    return code;    
}

void MovieTS :: ExitMsg(int confirmation,int no = 0)
{
    if(confirmation == 1)
    {
        cout<<"-------------------------------------------------"<<"\n";
        cout<<"congratualation your seats are reserved"<<"\n";
        seat = seat-no;
        cout<<"reamining seats are : "<<seat<<"\n";
        cout<<"thank you ... visit again.."<<"\n";
        cout<<"For any query"<<"\n";
        cout<<"call on : 8766856421"<<"\n";
        cout<<"mail on : Siddhathkardile02@gmail.com";
        cout<<"your faithfull Siddharth Cineplex"<<"\n";
        cout<<"-------------------------------------------------"<<"\n";
    }
    else
    {
        cout<<"-------------------------------------------------"<<"\n";
        cout<<"sorry we unable to process on your ticket booking"<<"\n";
        cout<<"reamining seats are : "<<seat<<"\n";
        cout<<"thank you ... visit again.."<<"\n";
        cout<<"For any query"<<"\n";
        cout<<"call on : 8766856421"<<"\n";
        cout<<"mail on : Siddhathkardile02@gmail.com";
        cout<<"your faithfull Siddharth Cineplex"<<"\n";
        cout<<"-------------------------------------------------"<<"\n";
    }
}

int main()
{
    int totalseat = 50;
    int iret1 = 0;
    int iret2 = 0;
    int iret3 = 0;
    float fret1 = 0;

    cout<<"-------------------------------------------------"<<"\n";
    cout<<"welcome to Siddharth cineplex"<<"\n";
    cout<<"-------------------------------------------------"<<"\n";

    MovieTS mobj(50);
    iret1 = mobj.SelectMovie();
    if(iret1 == 10)
    {
        mobj.ExitMsg(0);
        return 0;
    }
    else
    {
        iret2 = mobj.SelectMovieSeat(totalseat);
        if(iret2 == 0)
        {
            mobj.ExitMsg(iret2);
            return 0;
        }
        
        mobj.DisplayTotalSeat(iret2);

        fret1 = mobj.TotalCost(iret2);

        iret3 = mobj.DisplayPayment(fret1);
        
        mobj.ExitMsg(iret3,iret2);
        return 0;
        cout<<"-------------------------------------------------"<<"\n";    
    }
    return 0;
}
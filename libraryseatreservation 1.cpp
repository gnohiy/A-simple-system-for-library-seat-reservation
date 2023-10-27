#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const double PublicSeat=0;
const double SingleSeat=5;
const double GroupSeat=8;
const double Room=15;

int main()
{
    char typeOfSeat;
    int quantity;
    double price;
    char response;
    double startTime, endTime, duration;
    int d,m,y;
    char name[20];
    double phonenumber;
    string studentid;
    char schoolname[50];
    double payable;
    double paid,paid2, change;
    char payment_method;
    char direction;
    int pin;
    time_t now = time(0); //get date and time

    tm *ltm = localtime(&now);

//menu/first page
MENU:
{
    cout<<"==========================================="<<endl;
    cout<<"            Welcome to Pi Library"<<endl;
    cout<<"==========================================="<<endl<<endl;
    cout<<"  Working Hour: 0900-2100"<<endl<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  Type of seat             Price per hour"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  P: Public seat                Free"<<endl;
    cout<<"  S: Single seat              RM 5.00"<<endl;
    cout<<"  G: Group seat               RM 8.00"<<endl;
    cout<<"  R: Room                     RM15.00"<<endl;
    cout<<"-------------------------------------------"<<endl<<endl;
    cout<<"******** 20% discount for student ********"<<endl<<endl;
    cout<<"Enter 'N' to continue reservation..."<<endl;
    cin>>direction;
    if (direction=='n'||direction=='N')
        system("CLS");
    else
    {
        system("CLS");
        goto MENU;
    }
}
//choose seats
SEAT:
{
    cout<<"-------------------------------------------"<<endl;
    cout<<"  Type of seat             Price per hour"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  P: Public seat                Free"<<endl;
    cout<<"  S: Single seat              RM 5.00"<<endl;
    cout<<"  G: Group seat               RM 8.00"<<endl;
    cout<<"  R: Room                     RM15.00"<<endl;
    cout<<"-------------------------------------------"<<endl<<endl;

    do{
        cout<<"Enter alphabet to choose your seat."<<endl;
        cin>>typeOfSeat;
        if(typeOfSeat!='P'&&typeOfSeat!='S'&&typeOfSeat!='G'&&typeOfSeat!='R'&&typeOfSeat!='p'&&typeOfSeat!='s'&&typeOfSeat!='g'&&typeOfSeat!='r')
        {
            cout<<"Invalid Input"<<endl;
            cout<<"*Please choose 'P', 'S', 'G' or 'R'..."<<endl;
        }
    }while(typeOfSeat!='P'&&typeOfSeat!='S'&&typeOfSeat!='G'&&typeOfSeat!='R'&&typeOfSeat!='p'&&typeOfSeat!='s'&&typeOfSeat!='g'&&typeOfSeat!='r');

    do{
    cout<<"How many seats would you like?"<<endl;
    cin>>quantity;

    if (quantity<=0)
    {
        cout<<"Invalid Input"<<endl;
        cout<<"*Please choose a valid value..."<<endl;
    }

    }while(quantity<=0);

//choose date
CHOOSE_DATE:

    cout<<"Choose date ( DD / MM / YYYY )"<<endl;
    cin >> d; // read the day
        if(cin.get()!='/')
        {
            cout<<"Please follow the format ( DD / MM / YYYY )"<<endl;
            goto CHOOSE_DATE;
        }

        if(d>32&&d<1)
        {
            cout<<"Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
    cin >> m; // read the month
        if(cin.get()!='/')
        {
            cout<<"Please follow the format ( DD / MM / YYYY )"<<endl;
            goto CHOOSE_DATE;
        }

        if(m>12&&m<1)
        {
            cout<<"Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
    cin >> y; // read the year

    //invalid for passed date;
        if((y==1900+ltm->tm_year)&&(m==1+ltm->tm_mon)&&(d<ltm->tm_mday))
        {
            cout<<"Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

        if((y==1900+ltm->tm_year)&&(m<1+ltm->tm_mon))
        {
            cout<<"Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        if(y<1900+ltm->tm_year)
        {
            cout<<"Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

//choose time
CHOOSE_TIME:
    do{
        cout<<"Select time start (24h): (HHMM)"<<endl;
        cin>>startTime;
        if((startTime<900) || (startTime>2000))
        {
            cout<<"Invalid Input"<<endl;
            cout<<"*Please choose the time within our working hour..."<<endl<<endl;
        }
    }while((startTime<900) || (startTime>2000));

    //invalid for passed time
    if((y==1900+ltm->tm_year)&&(m==1+ltm->tm_mon)&&(d==ltm->tm_mday)&&(startTime/100<=ltm->tm_hour))
        {
            cout<<"Please choose a valid time"<<endl;
            goto CHOOSE_TIME;
        }

    do{
        cout<<"Select time end (24h): (HHMM)"<<endl;
        cin>>endTime;

        if(endTime<=startTime)
        {
            cout<<"Invalid Input"<<endl;
            cout<<"*Please choose the time after your starting time..."<<endl<<endl;
        }
        else if(endTime>2100)
        {
            cout<<"Invalid Input"<<endl;
            cout<<"*Please choose the time within our working hour"<<endl<<endl;
        }
    }while((endTime<=startTime)||(endTime>2100));


    duration=((endTime-startTime)/100);

}
    cout<<endl<<"Enter any key to continue reservation..."<<endl;
    cin>>direction;
    system("CLS");

//calculation for price
CALCULATE_PRICE:
{
    cout<<"==========================================="<<endl;
    cout<<"              Booking Details"<<endl;
    cout<<"==========================================="<<endl<<endl;

    if(typeOfSeat=='P'||typeOfSeat=='p')
    {
        price=PublicSeat*quantity*duration;
        cout<<" Type of seat : Public Seat"<<endl;
    }
    else if(typeOfSeat=='S'||typeOfSeat=='s')
    {
        price=SingleSeat*quantity*duration;
        cout<<" Type of seat : Single Seat"<<endl;
    }
    else if(typeOfSeat=='G'||typeOfSeat=='g')
    {
        price=GroupSeat*quantity*duration;
        cout<<" Type of seat : Group Seat"<<endl;
    }
    else
    {
        price=Room*quantity*duration;
        cout<<" Type of seat : Room"<<endl;
    }

    cout<<fixed;
    cout<<" Quantity     : "<<quantity<<endl;
    if(startTime<=900)
        cout<<" Time         : 0"<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;
    else
        cout<<" Time         : "<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;

    if(duration>1)
        cout<<" Duration     : "<<duration<<" hours"<<endl;
    else
        cout<<" Duration     : "<<duration<<" hour"<<endl;

    cout<<" Date         : "<<d<<"/"<<m<<"/"<<y<<endl;
    cout<<" Price        : RM "<<setprecision(2)<<price<<endl<<endl;
}
    cout<<"Enter 'P' to go back to MENU page..."<<endl;
    cout<<"Enter 'C' to make changes on current page..."<<endl;
    cout<<"Enter any other key to continue reservation..."<<endl;
    cin>>direction;

    if(direction=='p'||direction=='P')
        {
        system("CLS");
        goto MENU;
        }
    else if (direction=='c'||direction=='C')
        {
        system("CLS");
        goto SEAT;
        }
    else
        system("CLS");

//personal information
PERSONAL_INFORMATION:
{
    cout<<"==========================================="<<endl;
    cout<<"            Personal Information"<<endl;
    cout<<"==========================================="<<endl;

    cout<<"Enter your name:"<<endl;
    cin.ignore();
    cin.getline(name,20);

    cout<<"Enter your phone number: "<<endl;
    cin>>phonenumber;

ask_student:
    cout<<"Are you a student? (y/n)"<<endl;
    cin>>response;

    if (response=='y'||response=='Y')
    {
        cout<<"Enter the name of your school: "<<endl;
        cin.ignore();
        cin.getline(schoolname,50);

        cout<<"Enter your student ID: "<<endl;
        cin>>studentid;
        payable=price*0.8;
    }
    else if (response=='n'||response=='N')
    {
        studentid='-';
        payable=price;
    }
    else
    {
        cout<<"please enter a valid input"<<endl;
        goto ask_student;
    }
    cout<<endl;

}
    cout<<"Enter any key to continue reservation..."<<endl;
    cin>>direction;
    system("CLS");

//output for personal information
PERSONAL_INFORMATION_OUTPUT:
{
    cout<<"=========================================="<<endl;
    cout<<"            Personal Information"<<endl;
    cout<<"=========================================="<<endl<<endl;
    cout<<" Name               : "<<name<<endl;
    cout<<" Phone number       : "<<noshowpoint<<setprecision(0)<<phonenumber<<endl;
    cout<<" School             : "<<schoolname<<endl;
    cout<<" Student ID         : "<<studentid<<endl<<endl;
}
    cout<<"Enter 'P' to previous page..."<<endl;
    cout<<"Enter 'C' to make changes on current page..."<<endl;
    cout<<"Enter any other key to continue reservation..."<<endl;
    cin>>direction;

    if(direction=='p'||direction=='P')
        {
        system("CLS");
        goto CALCULATE_PRICE;
        }
    else if (direction=='c'||direction=='C')
        {
        system("CLS");
        goto PERSONAL_INFORMATION;
        }
    else
        system("CLS");

//payment
PAYMENT:
{
    cout<<"==========================================="<<endl;
    cout<<"                  Payment"<<endl;
    cout<<"==========================================="<<endl<<endl;

    cout<<" Price           : RM "<<showpoint<<setprecision(2)<<price<<endl;
    if(response=='y'||response=='Y')
        cout<<"  * Student Price   -20% *"<<endl;

    cout<<"-------------------------------------------"<<endl;
    cout<<" Total Payable   : RM "<<payable<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<endl;

    do{
        cout<<"Choose a payment method"<<endl;
        cout<<"C: Cash"<<endl;
        cout<<"B: VisaCard / MasterCard"<<endl;
        cin>>payment_method;
        cout<<endl;

        if(payment_method=='C'||payment_method=='c')
        {
            cout<<"You have chosen Cash."<<endl<<endl;
            cout<<"Enter the amount you have paid "<<endl<<"RM ";
            cin>>paid;
            while(paid<payable)
            {
                cout<<"You still have RM "<<payable-paid<<" more to Pay"<<endl;
                cout<<"Enter the amount you have paid again"<<endl;
                cin>>paid2;
                paid=paid+paid2;
            }
            change=paid-payable;
            cout<<"Your payment is successful."<<endl;
            if(change>0)
            {
            cout<<"Your change is RM "<<change<<endl;
            }
        }
        else if (payment_method=='B'||payment_method=='b')
        {
            cout<<"You have chosen VisaCard / MasterCard"<<endl<<endl;
            cout<<"Please insert your MasterCard or VisaCard..."<<endl<<endl;

            cout<<"Enter any key after you have inserted your card."<<endl;
            cin>>direction;

            cout<<"Enter your pin number"<<endl;
            cin>>pin;
            paid=payable;
        }
        else
        {
            cout<<"Invalid input"<<endl;
        }
    }while(payment_method!='C'&&payment_method!='c'&&payment_method!='B'&&payment_method!='b');
}
    cout<<endl<<"Your payment has successfully done"<<endl<<endl;
    cout<<"Enter any key to continue reservation..."<<endl;
    cin>>direction;
    system("CLS");

//receipt booking confirmation
RECEIPT:
{
    cout<<"==========================================="<<endl;
    cout<<"            Booking Confirmation"<<endl;
    cout<<"==========================================="<<endl<<endl;

    if(typeOfSeat=='P'||typeOfSeat=='p')
    {
        cout<<" Seat               : Public Seat";
    }
    else if(typeOfSeat=='S'||typeOfSeat=='s')
    {
        cout<<" Seat               : Single Seat";
    }
    else if(typeOfSeat=='G'||typeOfSeat=='g')
    {
        cout<<" Seat               : Group Seat";
    }
    else
    {
        cout<<" Seat               : Room";
    }

    cout<<" x"<<quantity<<endl;

    if(startTime<=900)
        cout<<" Time               : 0"<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;
    else
        cout<<" Time               : "<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;

    if(duration>1)
        cout<<" Duration           : "<<duration<<" hours"<<endl;
    else
        cout<<" Duration           : "<<duration<<" hour"<<endl;

    cout<<" Date               : "<<d<<"/"<<m<<"/"<<y<<endl;;
    cout<<"-------------------------------------------"<<endl;
    cout<<" Price              : RM "<<showpoint<<setprecision(2)<<price<<endl;

    if(response=='y'||response=='Y')
        cout<<" * Student Price   -20% *"<<endl;

    cout<<"-------------------------------------------"<<endl;

    cout<<" Total payable      : RM "<<payable<<endl<<endl;
    cout<<" Paid amount        : RM "<<paid<<endl;
    cout<<" Change amount      : RM "<<change<<endl<<endl<<endl;

    cout<<" Name               : "<<name<<endl;
    cout<<" Phone No           : "<<noshowpoint<<setprecision(0)<<phonenumber<<endl;
    cout<<" Student ID         : "<<studentid<<endl<<endl<<endl;


    cout<<"   Thank you for choosing Pi Library"<<endl;
    cout<<"         Please come again..."<<endl<<endl;
}
//get current date and time
DATE_TIME:
{
    if(ltm->tm_mday>=10)
        cout<<ltm->tm_mday<<"/";
    else
        cout<<"0"<<ltm->tm_mday<<"/";
    if( 1 + ltm->tm_mon>=10)
        cout<<1+ltm->tm_mon<<"/";
    else
        cout<<"0"<<1+ltm->tm_mon<<"/";
    cout<<1900 + ltm->tm_year;

    cout << setw(25);

    if(ltm->tm_hour>=10)
        cout << ltm->tm_hour << ":";
    else
        cout << "0"<<ltm->tm_hour << ":";

    if(ltm->tm_min>=10)
        cout << ltm->tm_min << ":";
    else
        cout <<"0"<< ltm->tm_min << ":";

    if(ltm->tm_sec>=10)
        cout << ltm->tm_sec << endl;
    else
        cout <<"0"<< ltm->tm_sec << endl;
}
    return 0;
}

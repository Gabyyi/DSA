#include <iostream>
using namespace std;

//-----Exercise 1-----

void swapp(double &a, double &b)
{
    swap(a, b);
}
void sort(double v[])
{
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
            if(v[i]>v[j])
                swapp(v[i],v[j]);
    for (int i=0;i<5;i++)
        cout<<v[i];
}

struct data
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
    char name_day[4];
    char name_month[4];
};
data today;

//-----Exercise 2-----

bool validDate(unsigned int day, unsigned int month, unsigned int year){
    if((day>=1 && day<=31) && (month>=1 && month<=12) && year>=0){
        if(month==2){
            if(year%4==0 && year%100!=0){
                if(day>=1 && day<=29) return true;
                return false;
            }
            else{
                if(day>=1 && day<28) return true;
                return false;
            }
        }
        else if(((month<8 && month%2!=0) || (month>=8 && month%2==0)) && (day>=1 && day<=31)) return true;
        else if(((month<9 && month%2==0) || (month>=9 && month%2!=0)) && (day>=1 && day<=30)) return true;
    }
    return false;
}

void tomorrow(unsigned int day, unsigned int month, unsigned int year){
    if(month==2){
        if(year%4==0 && year%100!=0){
            if(day<29) cout<<day+1<<' '<<month<<' '<<year;
            else if(day==29) cout<<1<<' '<<month+1<<' '<<year;
        }
        else{
            if(day<28) cout<<day+1<<' '<<month<<' '<<year;
            else if(day==28) cout<<1<<' '<<month+1<<' '<<year;
        }
    }
    else if((month<8 && month%2!=0) || (month>=8 && month%2==0)){
        if(day<31) cout<<day+1<<' '<<month<<' '<<year;
        else if(day==31){
            day=1;
            if(month<12) {month++;cout<<day<<' '<<month<<' '<<year;}
            else if(month==12){
                month=1;
                year++;
                cout<<day<<' '<<month<<' '<<year;
            }
        }
    }
    else if((month<9 && month%2==0) || (month>=9 && month%2!=0)){
        if(day<30) cout<<day+1<<' '<<month<<' '<<year;
        else if(day==30){
            day=1;
            if(month<12) {month++;cout<<day<<' '<<month<<' '<<year;}
            else if(month==12){
                month=1;
                year++;
                cout<<day<<' '<<month<<' '<<year;
            }
        }
    }
}

void yesterday(unsigned int day, unsigned int month, unsigned int year){
    if(month==3){
        if(day==1){
            if(year%4==0 && year%100!=0) cout<<29<<' '<<month-1<<' '<<year;
            else cout<<28<<' '<<month-1<<' '<<year;
        }
        else{
            cout<<day-1<<' '<<month<<' '<<year;
        }
    }
    else if(month==1){
        if(day==1){
            cout<<31<<' '<<12<<' '<<year-1;
        }
        else{
            cout<<day-1<<' '<<month<<' '<<year;
        }
    }
    else if((month<9 && month%2==0) || (month>=9 && month%2!=0)){
        if(day==1) cout<<31<<' '<<month-1<<' '<<year;
        else cout<<day-1<<' '<<month<<' ' <<year;
    }
    else if((month<8 && month%2!=0) || (month>=8 && month%2==0)){
        if(day==1) cout<<30<<' '<<month-1<<' '<<year;
        else cout<<day-1<<' '<<month<<' '<<year;
    }
}


//-----Exercise 3-----


struct Point
{
    //public:
    int n;
    int coord_x, coord_y;//the coordinates of a point
    void reset() //places the point into the origin
    {
        coord_x = coord_y = 0;
    } 
    void moveX(int x = 1) //moves the point horizontally with x positions
    {
        if(coord_x+x>n){
            coord_x=coord_x+x-n;
        }
        else coord_x=coord_x+x;
    }
    void moveY(int y = 1) // moves the point vertically with y positions 
    {
        if(coord_y+y>n){
            coord_y=coord_y+y-n;
        }
        else coord_y=coord_y+y;
    }
    void moveXY(int x = 1, int y = 1) // moves the point horizontally and vertically
    {
        if(coord_x+x>n || coord_y+y>n){
            reset();
        }
        else{
            coord_x=coord_x+x;
            coord_y=coord_y+y;
        }
    }
};


//-----Exercise 4-----


class Point1
{
    //public:
    private: 
        int n;
        int coord_x, coord_y;//the coordinates of a point
    public:
        Point1():n{},coord_x{},coord_y{}{}
        Point1(int n,int x,int y):
            n{n},coord_x{x},coord_y{y}{}
        void setN(int n){
            this->n=n;
        }
        void setX(int x){
            coord_x=x;
        }
        void setY(int y){
            coord_y=y;
        }
        int getN(){
            return n;
        }
        int getCoord_x(){
            return coord_x;
        }
        int getCoord_y(){
            return coord_y;
        }
        void reset() //places the point into the origin
        {
            coord_x = coord_y = 0;
        } 
        void moveX(int x = 1) //moves the point horizontally with x positions
        {
            if(coord_x+x>n){
                coord_x=coord_x+x-n;
            }
            else coord_x=coord_x+x;
        }
        void moveY(int y = 1) // moves the point vertically with y positions 
        {
            if(coord_y+y>n){
                coord_y=coord_y+y-n;
            }
            else coord_y=coord_y+y;
        }
        void moveXY(int x = 1, int y = 1) // moves the point horizontally and vertically
        {
            if(coord_x+x>n || coord_y+y>n){
                reset();
            }
            else{
                coord_x=coord_x+x;
                coord_y=coord_y+y;
            }
        }
};



int main()
{
    //-----Exercise 1-----

    double v[6] = {4, 6, 2, 8, 1};
    sort(v);
    cout<<endl;


    //-----Exercise 2-----

    data myDay;
    cin>>myDay.day>>myDay.month>>myDay.year;
    if(validDate(myDay.day,myDay.month,myDay.year))
    {
        cout<<"The date is valid\n";
        tomorrow(myDay.day,myDay.month,myDay.year);
        cout<<endl;
        yesterday(myDay.day,myDay.month,myDay.year);
    }
    else cout<<"The date is not valid";


    //-----Exercise 3-----

    cout<<endl;
    Point p;
    p.n=5;
    p.coord_x=2;
    p.coord_y=3;
    p.moveX(2);
    cout<<"new X: "<<p.coord_x;
    p.moveY(1);
    cout<<"\nnew Y: "<<p.coord_y;
    p.moveX(2);
    cout<<"\nnew X: "<<p.coord_x;


    //-----Exercise 4-----

    Point1 P;
    P.setN(5);
    P.setX(2);
    P.setY(3);
    P.moveX(8);
    cout<<'\n'<<P.getCoord_x();
}
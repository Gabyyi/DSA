#include<iostream>
#include "LinkedList.h"
using namespace std;
class FlightBookingSystem{
private:
    int MAXSEATS=5;
    struct Flight{
        string seats[5];
    };
    LinkedList<Flight> flights;
public:
    FlightBookingSystem(){}
    bool isFlightFull(Flight flight){
        for(int i=0;i<MAXSEATS;i++){
            if(flight.seats[i].empty()){
                return false;
            }
        }
        return true;
    }
    void bookSeat(string passengerName){
        if(flights.isEmpty() || isFlightFull(flights.plast->info)){
            Flight newFlight;
            newFlight.seats[0]=passengerName;
            flights.addLast(newFlight);
        }
        else{
            Node<Flight>* currentFlight=flights.pfirst;
            while(currentFlight!=NULL){
                if(!isFlightFull(currentFlight->info)){
                    Flight flight=currentFlight->info;
                    for(int i=0;i<MAXSEATS;i++){
                        if(flight.seats[i].empty()){
                            flight.seats[i]=passengerName;
                            currentFlight->info=flight;
                            return;
                        }
                    }
                }
                currentFlight=currentFlight->next;
            }
        }
    }
    void cancelBooking(int seatIndex){
        Node<Flight>* currentFlight=flights.pfirst;
        for(int i=0;i<seatIndex/MAXSEATS;i++)
            currentFlight=currentFlight->next;
        while(currentFlight!=NULL){
            Flight flight=currentFlight->info;
            for(int i=seatIndex%MAXSEATS;i<MAXSEATS-1;i++){
                flight.seats[i]=flight.seats[i+1];
            }
            seatIndex=0;
            flight.seats[MAXSEATS-1]="";
            if(currentFlight->next!=NULL){
                Flight nextFlight=currentFlight->next->info;
                string passengerToMove="";
                for(int i=0;i<MAXSEATS-1;i++){
                    if(!nextFlight.seats[i].empty()){
                        passengerToMove=nextFlight.seats[i];
                        nextFlight.seats[i]="";
                        break;
                    }
                }
                if(!passengerToMove.empty()){
                    flight.seats[MAXSEATS-1]=passengerToMove;
                }
            }
            currentFlight->info=flight;
            currentFlight=currentFlight->next;
        }
    }
    void displaySystem(){
        int flightNo=1;
        Node<Flight>* currentFlight=flights.pfirst;
        while(currentFlight!=NULL){
            cout<<"Flight number "<<flightNo<<" seats:"<<endl;
            Flight flight=currentFlight->info;
            for(int i=0;i<MAXSEATS;i++){
                if(!flight.seats[i].empty())
                    cout<<flight.seats[i]<<endl;
                else cout<<"Empty seat"<<endl;
            }
            flightNo++;
            currentFlight=currentFlight->next;
        }
    }
    string getPassenger(int seatIndex){
        Node<Flight>* currentFlight=flights.pfirst;
        for(int i=0;i<seatIndex/MAXSEATS;i++)
            currentFlight=currentFlight->next;
        Flight flight=currentFlight->info;
        if(!flight.seats[seatIndex%MAXSEATS].empty()) return flight.seats[seatIndex%MAXSEATS];
        else if(flight.seats[seatIndex%MAXSEATS].empty()) return "Empty seat";
        return "Invalid index";
    }
    ~FlightBookingSystem(){}
};
main(){
    FlightBookingSystem flight;
    flight.bookSeat("passenger1");
    flight.bookSeat("passenger2");
    flight.bookSeat("passenger3");
    flight.bookSeat("passenger4");
    flight.bookSeat("passenger5");
    flight.bookSeat("passenger6");
    flight.bookSeat("passenger7");
    flight.bookSeat("passenger8");
    flight.bookSeat("passenger9");
    flight.bookSeat("passenger10");
    flight.bookSeat("passenger11");
    flight.bookSeat("passenger12");
    flight.bookSeat("passenger13");
    flight.bookSeat("passenger14");
    flight.cancelBooking(0);
    flight.cancelBooking(6);
    // flight.cancelBooking(7);
    // flight.cancelBooking(10);
    // flight.cancelBooking(9);
    flight.bookSeat("passenger15");
    flight.displaySystem();
    cout<<endl<<"At index "<<5<<" we have passenger: "<<flight.getPassenger(5);
}

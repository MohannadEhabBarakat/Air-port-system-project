#include<bits/stdc++.h>
#include "dates.cpp"
#include "customer.cpp"
using namespace std;

class ticket{

    private:
        Customer* customr;
        dates* date;
        float price;
        string seat_num;
        flight*flight;

    public;
        void setCustomer(Customer * C){
            customer = C;
        }

        void setDates (date d){
            date = d;
        }
        void setPrice( float p){
            price = p;
        }
        void setSeat(string st){
            seat_num= st;
        }
        void setFlight( flight* f){
            flight = f;
        }

        Customer getCustomer(){
            return customer;
        }
        date getDate (){
            return date;
        }
        float getPrice(){
            return price;
        }
        string getSeat(){
            return seat_num;
        }
        flight getFlight(){
            return flight;
        }



        ticket(Customer* cu,dates* da,float pr,string se,flight*fl){
            customr=cu;
            date=da;
            price=pr;
            seat_num=se;
            flight=fl;
        }
        ticket(Customer* cu, string d, string a, string issue, float pr,string se,flight*fl){
            date= new dates(d,a,issue);
            customr=cu;
            date=da;
            price=pr;
            seat_num=se;
            flight=fl;
        }
};


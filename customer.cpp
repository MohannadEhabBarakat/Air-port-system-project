#include<bits/stdc++.h>
#include"person.cpp"
using namespace std;

class Customer : public Person {
	private:
		string Distination;
		int ID;
		int BankAc;
		int Reservations;

	public:
		Customer(string nm, string gend, string add, int ag, int phn, int pssnm, string dist, int id, int bnkac, int reserv):Person(nm, gend, add, ag, phn, pssnm){
            Distination=dist;
            ID=id;
            BankAc=bnkac;
            Reservations=reserv;
		}
		void setDistination(string D){
			Distination=D;
		}
		void setFees(int I){
			ID=I;
		}
		void setBankAc(int BA){
			BankAc= BA;
		}
		void setReservations(int BA){
			Reservations= BA;
		}
		string getDistination(){
			return Distination;
		}
		int getID(){
			return ID;
		}
		int getBankAc(){
			return BankAc;
		}
		int getReservations(){
			return Reservations;
		}


};


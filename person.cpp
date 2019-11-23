#include<bits/stdc++.h>
#include "gll.cpp"
using namespace std;

class Person{
	private:
		string Name;
		string Gender;
		string Address;
		int  Age;
		int  Phone;
		int PassNum;
		//const string relativ[3]=("first","second","third");
		//map <string, gll<Person*> > relativs;

	public:
		Person(string nm, string gend, string add, int ag, int phn, int pssnm){
		    Name=nm;
		    Gender=gend;
		    Address=add;
		    Age=ag;
		    Phone=phn;
		    PassNum=pssnm;
		}
		void setName(string N){
			Name=N;
		}
		void setGender(string G){
			Gender=G;
		}
		void setAddress(string A){
			Address=A;
		}
		void setAge(int Ag){
			Age=Ag;
		}
		void setPhone(int Ph){
			Phone=Ph;
		}
		void setPassNum(int PN){
			PassNum=PN;
		}
		string getName(){
			return Name;
		}
		string getGender (){
			return Gender;
		}
		string getAddress(){
			return Address;
		}
		int getAge(){
			return Age;
		}
		int getPhone(){
			return Phone;
		}
		int getPassNum(){
			return PassNum;
		}



};

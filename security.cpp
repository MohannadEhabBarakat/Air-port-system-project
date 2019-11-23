#include"person.cpp"
#include<bits/stdc++.h>

using namespace std;

class SecurityEmployees : public Person {
	private:
		float Salary;
		string Weapons;
		int Rank;

	public:
		SecurityEmployees(string nm, string gend, string add, int ag, int phn, int pssnm, float sal, string wea, int rnk):Person(nm, gend, add, ag, phn, pssnm){
			Salary=sal;
			Weapons=wea;
			Rank=rnk;
		}
		void setSalary(float S){
			Salary=S;
		}
		void setWeapons(string W){
			Weapons=W;
		}
		void setRank(int RN){
			Rank=RN;
		}

		float getSalary(){
			return Salary;
		}
		string getWeapons(){
			return Weapons;
		}
		int getRank(){
			return Rank;
		}


};

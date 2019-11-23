#include<bits/stdc++.h>
#include"person.cpp"
using namespace std;

class Employee : public Person {
	private:
		string Job;
		float Salary;
		float Rating;
		int Rank;

	public:
	    Employee(string nm, string gend, string add, int ag, int phn, int pssnm, string jb, float sal, float rat, int rnk):Person(nm, gend, add, ag, phn, pssnm){
	    Job=jb;
	    Salary=sal;
	    Rating=rat;
	    Rank=rnk;
	    }
		void setJob(string J){
			Job=J;
		}
		void setSalary(float S){
			Salary=S;
		}
		void setRating(float RT){
			Rating=RT;
		}
		void setRank(int RN){
			Rank=RN;
		}

		string getJob(){
			return Job;
		}
		float getSalary(){
			return Salary;
		}
		float getRating(){
			return Rating;
		}
		int getRank(){
			return Rank;
		}



};

#include<bits/stdc++.h>
#include"employee.cpp"
#include"bank.cpp"
#include"customer.cpp"
#include"dates.cpp"
//#include"gll.cpp"
#include"plane.cpp"
#include"security.cpp"
#include"ticket.cpp"
using namespace std;

class company{
    private:
        ll <Employee> * employees;
        ll <Customer*> * Customers;
        ll <bank*> * banks;
        ll <dates*> * timetable;
        ll <plane*> * AllPlanes;
        ll <plane*> * ActivePlanes;
        ll <plane*> * RentPlanes;
        ll <plane*> * RepPlanes;
        ll <SecurityEmployees*> * Securityemployees;
        ll <ticket*> * tickets;

        string name, id, Main_username, Main_password;

        company(string nm, string i, string MUser, string MPass){
            name=nm;
            id=i;
            Main_username=MUser;
            Main_password=Mpass;
        }

        void new_employee(string nm, string gend, string add, int ag, int phn, int pssnm, string jb, float sal, float rat, int rnk){
            Employee * x = new Employee (nm,gend,add,ag,phn,pssnm,jb,sal,rat,rnk);
            employees->add_tail(x);
        }
        void new_ticket(Customer* cu,dates* da,float pr,string se,flight*fl){
            ticket * x= new ticket(cu,da,pr,se,fl);
            tickets->add_tail(x);
        }
        void new_secrity(string nm, string gend, string add, int ag, int phn, int pssnm, float sal, string wea, int rnk){
            SecurityEmployees * x= new SecurityEmployees(nm,gend,add,ag,phn,pssnm,sal,wea,rnk);
            Securityemployees->add_tail(x);
        }
        void new_customer(string nm, string gend, string add, int ag, int phn, int pssnm, string dist, int id, int bnkac, int reserv){
            Customer * x = new Customer(nm,gend,add,ag,phn,pssnm,dist,id,bnkac,reserv);
            Customers->add_tail(x);
        }
        void new_plane(int a, int b, int c, string pNum){
            plane * x = new plane (a,b,c,pNum);
            AllPlanes->add_tail(x);
        }
        void new_plane(int a, int b, int c, string pNum, string spec){
            plane * x = new plane (a,b,c,pNum,spec);
            AllPlanes->add_tail(x);
        }
        void new_bank(string bc, string nm, string ps, long double amo){
            bank * x = new bank(bc, nm, ps, amo);
            banks->add_tail(x);
        }
        void new_date(string d, string a, string issue){
            dates * x = new dates (d,a,issue);
            timetable->add_tail(x);
        }

        bool Delete_Customer( string n){
        	node *i = Customers->getHead();
        	if(i->getID()==n){
				Customers->delHead();
				return true;
			}

        	while(true){
        		if(i->next->getID()==n){
        			Customers->delNext(i);
					return true;
				}
				if(i->next==Customers->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_employee(string n){
        	node *i = employees->getHead();
        	if(i->getName()==n){
				employees->delHead();
				return true;
			}

        	while(true){
        		if(i->next->getName()==n){
        			employees->delNext(i);
					return true;
				}
				if(i->next==employees->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_employee(string n){
        	node *i = employees->getHead();
        	if(i->getName()==n){
				employees->delHead();
				return true;
			}

        	while(true){
        		if(i->next->getName()==n){
        			employees->delNext(i);
					return true;
				}
				if(i->next==employees->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_tickets(string n){
        	node *i = tickets->getHead();
        	if(i->getName()==n){
				tickets->delHead();
				return true;
			}

        	while(true){
        		if(i->next->getName()==n){
        			tickets->delNext(i);
					return true;
				}
				if(i->next==tickets->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_Securityemployees(string n){
        	node *i = Securityemployees->getHead();
        	if(i->getName()==n){
				Securityemployees->delHead();
				return true;
			}

        	while(true){
        		if(i->next->getName()==n){
        			Securityemployees->delNext(i);
					return true;
				}
				if(i->next==Securityemployees->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_banks(string n){
        	node *i = banks->getHead();
        	if(i->bankACC()==n){
				banks->delHead();
				return true;
			}

        	while(true){
        		if(i->next->bankACC()==n){
        			banks->delNext(i);
					return true;
				}
				if(i->next==banks->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		bool Delete_AllPlanes(string n){
        	node *i = AllPlanes->getHead();
        	if(i->get_plateNum()==n){
				AllPlanes->delHead();
				return true;
			}

        	while(true){
        		if(i->next->get_plateNum()==n){
        			AllPlanes->delNext(i);
					return true;
				}
				if(i->next==banks->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		void update_Planes(){
			ll <plane*> * ActivePlanes,ll <plane*> * RentPlanes,ll <plane*> * RepPlanes = new ll <plane*>;
			node * i=Allplanes->getHead();
			while(true){
				if(i->get_use()=="Rent")RentPlanes->add_tail(i);
				else if(i->get_use()=="Rep")RepPlanes->add_tail(i);
				else ActivePlanes->add_tail(i);

				i=i->next();
				if(i==Allplanes->getTail())break;
			}
		}




};



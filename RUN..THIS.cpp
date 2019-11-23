#include<bits/stdc++.h>

using namespace std;

template <class type>   // to generalize the class type 
class heap{   // creating max heap using array to get the max number of reservations 
    private:
        type arr[1000];   // intializing the array 
        int last=-1;
    public:
        ~heap(){     // destructor to empty the heap 
            delete(arr);
        }
        type getarrf(){return arr[0];}    // to get the root of the heap 
        void swp(int a, int b){  // swaping function to heapfy the elements inserted 
                type c =arr[b]; 
                arr[b]=arr[a];
                arr[a]=c;
            }

        void insert(type x){   // inserting element to the heap 
            last++;
            arr[last]=x;
            int lem = ceil(log2(last));    
            int curr =last;

            for(int i=0; i<lem;i++){
                if(curr==1){break;}
                else{
                    if(curr%2 == 0){
                        int n = (curr/2)-1;
                        if(arr[curr]->data->getReservations()<arr[n]->data->getReservations()){
                                swp(curr,n);
                                curr=n;
                        }
                        else{break;}
                    }
                    else{
                        int n = ((curr-1)/2)-1;
                        if(arr[curr]->data->getReservations()<arr[n]->data->getReservations()){swp(curr,n);curr=n;}
                        else{break;}
                    }
                }
            }
        }
        void printall(){    // printing all heap data 
            for(int i=0; i<last+1;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }

        void del(){   // deleting element from the heap 
            swp(0,last);
            last--;

            int lem = ceil(log2(last+1));
            int curr =0;

            for(int i=0; i<lem;i++){
                if(curr>=last){break;}
                else{
                    if(arr[curr]->data->getReservations()>arr[(2*(curr+1))-1]->data->getReservations() && 2*(curr+1) <= last+1){swp(curr,(2*(curr+1))-1);curr=2*curr;}
                    else if(arr[curr]->data->getReservations()>arr[(2*(curr+1)+1)-1]->data->getReservations() && (2*(curr+1))+1 <= last+1){swp(curr,(2*(curr+1)+1)-1);curr=(2*curr)+1;
                    }
                    else{break;}
                }
        }
    }
};

//================================================================================================
class flight{  // flight class that contain data for any new, rented, or used flight 
	private:
        int flight_number; int seatsnumber; string offplace; string destination; string captname;
    public:
	flight(int fnum, int seatsnum, string off, string to, string cname){ // constructor 

		flight_number = fnum;
		seatsnumber = seatsnum;
		offplace = off;
		destination = to;
		captname = cname;
	}
	int get_fnum(){return flight_number;}  // function to get any flight number 
};

//------------------------------------------------------------------------
class dates{ // class for dates " time table" of the flights 
	public:
    string depr, arr, issued;
    dates(string d, string a, string issue){
        depr=d;
        arr=a;
        issued=issue; 
    }
};
//============================================================================
template <class type>

class node{ // creating nodes to be used for linked list 
    public:
        node  *next;
        type data;
};

template <class type> // generalizing the type of elements 
class ll{   // linked list class .. this linked list will be used to store data of different objects 
    private:
        node <type> *head;
        node <type> *tail;
    public:
        ll(){
           head=0;
           tail=0;
        }
		node <type> * getHead(){  // getting the head of the list 
			return head;
		}
		node <type> * getTail(){   // geting the tail of the list 
			return tail;
		}
        void add_tail(type x){  // adding element to the tail 
            if(head==0){
                //cout<<"first time"<<endl;
                node <type> *nw =new node<type>;
                nw->data=x;
                nw->next=0;
                head=nw;
                tail=nw;
            }
            else{
                //cout<<"nth time"<<endl;
                node <type> *nw =new node<type>;
                nw->data=x;
                nw->next=0;
                tail->next=nw;
                tail=nw;
                //if(tail==head){cout<<"damn"<<endl;}
            }
        }

        void add_head(type x){   // adding element to the head 
            if(tail==0){
                //cout<<"first time"<<endl;
                node <type>*nw =new node<type>;
                nw->data=x;
                nw->next=0;
                head=nw;
                tail=nw;
            }
            else{
                //cout<<"nth time"<<endl;
                node <type>*nw =new node<type>;
                nw->data=x;
                nw->next=head;
                head=nw;
                //if(tail==head){cout<<"damn"<<endl;}
            }
        }

        void print_ll(){   // printing all the list's elements 
            if(head==0){cout<<"NULL IDIOT";}
            else{
                node <type>*x = head;
                //cout<<"head= "<<head->data<<endl;
                while(true){
                    cout<<x->data<<endl;
                    if(x==tail){cout<<"Go to hell";break;}
                    else{x=x->next;}
                }
            }
        }
		bool delNext(node<type>*x){   // deleting node's next    
			if(x==tail)return false;  // if this node is tail .. return false as it does not have next 
			node <type> * NewNext=x->next->next;  // other wise create new node to be the next of the node instead of the deleted one
			delete(x->next);
			x->next=NewNext;
			return true;
		}
		void delHead(){   // deleting the head of the list 
			node <type> * NewHead=head->next;
			delete(head);
			head = NewHead;
		}
        void insert_after(type target,type dt){   // function to insert a node after a specefic one 
            if(head==0){cout<<"Can't insert in empty list Idiot";}
            else{
                node <type>*x = head;
                //cout<<"head= "<<head->data<<endl;
                while(true){  
                    if(x->data==target){
                        node <type>*nw =new node<type>;
                        nw->data=dt;
                        nw->next=x->next;
                        if(x->next==0){tail=nw;}
                        x->next=nw;
                        break;
                    }else{x=x->next;}

                if(x==tail){cout<<"Go to hell all that effort and i didn't find your element"<<endl;break;}

                }
            }
        }

};


//======================================================

class Person{ // this class contain personal data for any person on the company and will inherit customers and employees 
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
		void setName(string N){   // setters for the class 
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
		string getName(){  // getters for the class 
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
 //===================================================
 class Customer : public Person {  // class for customers inherited from person 
	private:
		string Distination;
		int ID;
		int BankAc;
		int Reservations;

	public:
		Customer(string nm, string gend, string add, int ag, int phn, int pssnm, string dist, int id, int bnkac, int reserv):Person(nm, gend, add, ag, phn, pssnm){
            Distination=dist;  // constructor 
            ID=id;
            BankAc=bnkac;
            reserv=Reservations;
		}
		void setDistination(string D){  // setters 
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
		string getDistination(){  // getters 
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

//================================================================================

class Employee : public Person {  // this class is inherited from person to set data for employees
	private:
		string Job;
		float Salary;
		float Rating;
		int Rank;

	public:
	    Employee(string nm, string gend, string add, int ag, int phn, int pssnm, string jb, float sal, float rat, int rnk):Person(nm, gend, add, ag, phn, pssnm){
	    Job=jb;
	    Salary=sal;  // constructor 
	    Rating=rat;
	    Rank=rnk;
	    }
		void setJob(string J){ // setter 
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

		string getJob(){  // getters 
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

//===============================================

class SecurityEmployees : public Person { // class for special type of employees 
	private:
		float Salary;
		string Weapons; // the extra data does not exist on employee 
		int Rank;

	public:
		SecurityEmployees(string nm, string gend, string add, int ag, int phn, int pssnm, float sal, string wea, int rnk):Person(nm, gend, add, ag, phn, pssnm){
			Salary=sal;
			Weapons=wea;  // constructor 
			Rank=rnk;
		}
		void setSalary(float S){  // setters 
			Salary=S;
		}
		void setWeapons(string W){
			Weapons=W;
		}
		void setRank(int RN){
			Rank=RN;
		}

		float getSalary(){  // getters 
			return Salary;
		}
		string getWeapons(){
			return Weapons;
		}
		int getRank(){
			return Rank;
		}


};

 //============================================

 class bank{  // the class responsable for all the finance related things on the company 
    private:
        long double ACCamont=0;
        string bankACC;
        string name;
        string pass;
    public:
        bank(string bc, string nm, string ps, long double amo){
            bankACC=bc;
            name=nm;
            pass=ps;  //constructor
            ACCamont=amo;
        }
        long double Get_ACCamont(){return ACCamont;}
        void Set_ACCamont(long double amm){ACCamont=amm;}

        void setBankACC(string BA){
        	bankACC=BA;
		}
		void setName(string n){
			name=n;
		}
		void setPass(string pa){
			pass=pa;
		}
		string getBankACC(){
			return bankACC;
		}
		string getName(){
			return name;
		}
		string getPass(){
			return pass;
		}
};

class transaction{   //  class related to the finance shows any transections 
    private:
        bank * from;
        bank * to;
        long double ammount;

    public:
        transaction(bank * t, long double am, string type){
            if (type =="to")to=t;
            else from=t;
            ammount=am;
        }

        void setFrom(bank* F){
        	from=F;
		}
		void setTo(bank* T){
			to=T;
		}
		void setAmmount(long double Am){
			ammount= Am;
		}
		bank * getFrom(){
			return from;
		}
		bank * getTo(){
			return to;
		}
		long double getAmmount(){
			return ammount;
		}


        bool withdraw(){  // function to check if there is a withdraw on the account 
                if(from->Get_ACCamont() >= ammount) {
                    from->Set_ACCamont(from->Get_ACCamont()-ammount);
                    return true;
                }
                return false;
        }

        bool deposit(){  // function to add money to the customer account 
                to->Set_ACCamont(to->Get_ACCamont()+ammount);
                return true;

        }
};

class Finance : Person{  // this class for the finance employees 
    private:
        //map <string,bank*> bankList;
        //linkedList * <transaction> List_of_transactions;
        string username, password, auth;

    public:

        Finance(string nm, string gend, string add, int ag, int phn, int pssnm, string user, string pass, string ath):Person(nm, gend, add, ag, phn, pssnm){
            username=user;
            password=pass;
            auth=ath;
        }
        void setUserName(string un){
        	username=un;
		}
		void setPassword(string pass){
			password=pass;
		}
		void setAuth(string au){
			auth=au;
		}
		string getUserName(){
			return username;
		}
		string getPassword(){
			return password;
		}
		string getAuth(){
			return auth;
		}

        string withdraw (long double amm,bank *from){  
            if(this->auth=="with"){
                transaction * trans=new transaction(from,amm,"d");
                if(trans->withdraw()) return "True";
                return "NoMoney";
            }
            return "NotAuth";
        }


//====================================================================================//

        string deposit  (long double amm,bank *to){
            if(this->auth=="with"){
                transaction * trans=new transaction(to,amm,"to");
                if(trans->deposit()) return "True";
                return "NoMoney";
            }
            return "NotAuth";
        }
//-------------------------------------------------------------------------------------//
        string transfare  (long double amm,bank *from, bank *to){ // transfaring money
            if(this->auth=="with"){
                transaction * trans=new transaction(to,amm,"to");
                transaction * trans2=new transaction(from,amm,"d");
                if(trans->deposit()&&trans2->withdraw()) return "True";
                return "NoMoney";
            }
            return "NotAuth";
        }
};


//===============================================================================

class ticket{  // all data related to tickets 

    private:
        Customer* customr;  // any ticket is for a customer 
        dates* date;    // any ticket has a date of taking off 
        float price;   // price of ticket  
        string seat_num;   // seat number for the ticket 
        flight*flights;   // on which flight 

    public:
        void setCustomer(Customer * C){
            customr = C;
        }

        void setDates (dates * d){
            date = d;
        }
        void setPrice( float p){
            price = p;
        }
        void setSeat(string st){
            seat_num= st;
        }
        void setFlight( flight* f){
            flights = f;
        }

        Customer * getCustomer(){
            return customr;
        }
        dates * getDate (){
            return date;
        }
        float getPrice(){
            return price;
        }
        string getSeat(){
            return seat_num;
        }
        flight * getFlight(){
            return flights;
        }



        ticket(Customer* cu,dates* da,float pr,string se,flight*fl){
            customr=cu;
            date=da;
            price=pr;
            seat_num=se;
            flights=fl;
        }
        ticket(Customer* cu, string d, string a, string issue, float pr,string se,flight*fl){
            date= new dates(d,a,issue);
            customr=cu;
            price=pr;
            seat_num=se;
            flights=fl;
        }
};

//=========================================================================

class plane{ // data related to plens 
    private:
        map<string,int> clss;  // map to organize the classes of the plene 
        string specs, use, plateNum;
    public:
        plane(int a, int b, int c, string pNum){
            clss["a"]=a;
            clss["b"]=b;
            clss["c"]=c;
            plateNum=pNum;
        }
        plane(int a, int b, int c,string pNum, string spec){
            clss["a"]=a;
            clss["b"]=b;
            clss["c"]=c;
            specs=spec;
            plateNum=pNum;
        }
        void set_clss(string type, int num){clss[type]=num;}
        void set_specs(string info){specs=info;}
        void set_use(string u){use=u;}
        void set_plateNum(string u){plateNum=u;}

        int get_clss(string type){return clss[type];}
        string get_specs(){return specs;}
        string get_use(){return use;}
        string get_plateNum(){return plateNum;}

};


//========================================

class company{    // the main class that contain all the company's data on different linked lists 
    private:
        ll <Employee *> * employees;   // ll -> linked list  < kind of data inside >
        ll <Customer *> * Customers;
        ll <bank*> * banks;
        ll <dates*> * timetable;
        ll <plane*> * AllPlanes;
        ll <plane*> * ActivePlanes;
        ll <plane*> * RentPlanes;
        ll <plane*> * RepPlanes;
        ll <SecurityEmployees*> * Securityemployees;
        ll <ticket*> * tickets;
        ll <flight*> * flights;

        string name, id, Main_username, Main_password;
		public:
        company(string nm, string i, string MUser, string MPass){
            name=nm;
            id=i;
            Main_username=MUser;
            Main_password=MPass;
        }

        void new_employee(string nm, string gend, string add, int ag, int phn, int pssnm, string jb, float sal, float rat, int rnk){
            Employee * x = new Employee (nm,gend,add,ag,phn,pssnm,jb,sal,rat,rnk);
            employees->add_tail(x);  // adding new employee to the list of employees .. inserting new node of type employee to the linked list 
        }
        void new_ticket(Customer* cu,dates* da,float pr,string se,flight*fl){
            ticket * x= new ticket(cu,da,pr,se,fl);
            tickets->add_tail(x); // selling new ticket to a customer .. add it to the list of all tickets 
        }
        void new_secrity(string nm, string gend, string add, int ag, int phn, int pssnm, float sal, string wea, int rnk){
            SecurityEmployees * x= new SecurityEmployees(nm,gend,add,ag,phn,pssnm,sal,wea,rnk);
            Securityemployees->add_tail(x); // new security employee join the company 
        }
        void new_customer(string nm, string gend, string add, int ag, int phn, int pssnm, string dist, int id, int bnkac, int reserv){
            Customer * x = new Customer(nm,gend,add,ag,phn,pssnm,dist,id,bnkac,reserv);
            Customers->add_tail(x);  // new customer 
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
        void new_flight(int fnum, int seatsnum, string off, string to, string cname){
            flight * x = new flight (fnum,seatsnum,off,to,cname);
            flights->add_tail(x);
        }
        bool Delete_Customer( int n){
        	node <Customer *> * i = Customers->getHead();

        	if(i->data->getID()==n){
				Customers->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->getID()==n){
        			Customers->delNext(i);
					return true;
				}
				if(i->next==Customers->getTail()){
					return false;
				}
				i=i->next;
			}
		}
        bool Delete_Flight( int n){
        	node <flight *> * i = flights->getHead();

        	if(i->data->get_fnum()==n){
				flights->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->get_fnum()==n){
        			flights->delNext(i);
					return true;
				}
				if(i->next==flights->getTail()){
					return false;
				}
				i=i->next;
			}
		}
		bool Delete_employee(string n){
        	node <Employee *> *i = employees->getHead();
        	if(i->data->getName()==n){
				employees->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->getName()==n){
        			employees->delNext(i);
					return true;
				}
				if(i->next==employees->getTail()){
					return false;
				}
				i=i->next;
			}
		}

//		bool Delete_employee(string n){
//        	node *i = employees->getHead();
//        	if(i->getName()==n){
//				employees->delHead();
//				return true;
//			}
//
//        	while(true){
//        		if(i->next->getName()==n){
//        			employees->delNext(i);
//					return true;
//				}
//				if(i->next==employees->getTail()){
//					return false;
//				}
//				i=i->next;
//			}
//		}

		bool Delete_tickets(string n){
        	node <ticket *>*i = tickets->getHead();
        	if(i->data->getSeat()==n){
				tickets->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->getSeat()==n){
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
        	node <SecurityEmployees *>*i = Securityemployees->getHead();
        	if(i->data->getName()==n){
				Securityemployees->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->getName()==n){
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
        	node <bank *>*i = banks->getHead();
        	if(i->data->getBankACC()==n){
				banks->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->getBankACC()==n){
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
        	node <plane *>*i = AllPlanes->getHead();
        	if(i->data->get_plateNum()==n){
				AllPlanes->delHead();
				return true;
			}

        	while(true){
        		if(i->next->data->get_plateNum()==n){
        			AllPlanes->delNext(i);
					return true;
				}
				if(i->next==AllPlanes->getTail()){
					return false;
				}
				i=i->next;
			}
		}

		void update_Planes(){
			ll <plane*> * ActivePlanes = new ll <plane*>;
			ll <plane*> * RentPlanes = new ll <plane*>;
			ll <plane*> * RepPlanes = new ll <plane*>;
			node <plane *>* i=AllPlanes->getHead();
			while(true){
				if(i->data->get_use()=="Rent")
                    RentPlanes->add_tail(i->data);
				else if(i->data->get_use()=="Rep")RepPlanes->add_tail(i->data);
				else ActivePlanes->add_tail(i->data);

				i=i->next;
				if(i==AllPlanes->getTail())break;
			}
		}


	Customer * Most_Active(){  // getting the most active customer to give him special offers .. 
        node <Customer *>*i= (Customers->getHead());
        heap <node <Customer *> *> * clints_Heap =new heap <node <Customer *> *> ();
        while(true){
            clints_Heap->insert(i);
            i=i->next;
            if(i==Customers->getTail())break;
        }
        return clints_Heap->getarrf()->data;
	}


};

int main(){
	company* c= new company("NMH", "ID", "Noha", "2061998");  // creating  the company 
	string x;
	cout << "                               Welcome to NMH Company" << endl;  // user interface 
	cout << "                     "         << endl;
	cout << "                               Please pick a choice" << endl;
	cout << "       Press CONT to re-enter" << endl;
	cout << "       Press EXIT to close" << endl;
	cout << "    " << endl;
	cout << "    " << endl;
	cout << "=================================================================" << endl;
	cout << "For Customer Data : " << endl;
	cout << " ================================================================" << endl;
	cout << "1c- Add new customer "<< endl;
	cout << "2c- Delete customer"<< endl;
	cout << "3c- Most Active customer"<< endl;
	cout << "    "<< endl;
	cout << "    "<< endl;
	cout << "================================================================="<< endl;
	cout << "For Tickets Data" << endl;
	cout << "=================================================================" << endl;
	cout << "1t- Add new ticket" << endl;
	cout << "  "<< endl;
	cout << "  "<< endl;
	cout << "==================================================================" << endl;
	cout << "For Flight Data" << endl;
	cout << "===================================================================" << endl;
	cout << "1f- Add new flight" << endl;
	cout << "2f- Delete flight" << endl;
	cout << "3f- Reserve on flight" << endl;
	cout << "      " << endl;
	cout << "      " << endl;
	cout << "===================================================================" << endl;
	cout << "For Finance Data" << endl;
	cout << "===================================================================" << endl;
	cout << "1b- Add new bank account" << endl;
	cout << "   " << endl;
	cout << "   " << endl;
	cout << "===================================================================" << endl;
	cout << "For employees Data" << endl;
	cout << "===================================================================" << endl;
	cout << "1e- Add new employee" << endl;
	cout << "2e- Remove employee" << endl;
	cout << "   " << endl;
	cout << "   " << endl;
	cout << "===================================================================" << endl;
	cout << "For Planes" << endl;
	cout << "===================================================================" << endl;
	cout << "1p- Add plane" << endl;
	cout << "2p- Remove plane" << endl;
	cout << "3p- Update planes inventory" << endl;
	cout << "   " << endl;
	cout << "   " << endl;
	cout << "                        Thank You " << endl;
	cin >> x;
	
	if (x=="1c"){
		string nm; string gend; string add; int ag; int phn; int pssnm; string dist; int id; int bnkac; int reserv;
		cout<< "Name: ";cin>>nm;
		cout<< "Gender: ";cin>>gend;
		cout<< "Address: ";cin>>add;
		cout<< "Age: ";cin>>ag;
		cout<< "Phone: ";cin>>phn;
		cout<< "Passport Number: "; cin>> pssnm;
		cout<< "Home country: ";cin>>dist;
		cout<< "ID: ";cin>> id;
		cout<< "Name: ";cin>>nm;
		cout<< "Name: ";cin>>nm;
		c->new_customer(nm,  gend,  add, ag,  phn, pssnm,  dist,  id,  bnkac, reserv);
		cout << " .. Data Added .. " << endl;
}
	if (x=="2c"){
		cout << "Enter customer ID"<< endl; 
		int n;
		cin >> n;
		c->Delete_Customer(n);
		cout << ".. Deleted .." << endl;
	}
	if (x=="3c"){
		cout << "The most Active customer is  " << c->Most_Active()->getName() <<  endl; 
	}
	
	if (x=="1t"){
		// craete new ticket 	
	}
	
	if (x=="EXIT"){
		// leave 
	}
	
	if (x=="1f"){
		int fnum, seatsnum;
		string off, to, cname;   
		cout << "Flight number: " << endl; 
		cin >> fnum;
		cout << "seat number:" << endl;
		cin >> seatsnum; 
		cout << "flight from : "<< endl;
		cin >> off;
		cout << " flight to : " << endl; 
		cin >> to; 
		cout << " customer name " << endl; 
		cin >> cname; 
		c->new_flight( fnum, seatsnum,  off, to,  cname);
		cout << ".. Added.." << endl; 
	}
	if (x=="2f"){
		cout << "Flight Number: " << endl;
		int n;
		cin >> n;
		c->Delete_Flight(n);
		cout << " .. Deleted .." << endl; 
	}
	
	if (x=="3f"){
		//reserve on a flight 
	}
	
	if (x=="1b"){
		string bc, nm, ps;
		long double amo;
		cout << " Account number:" << endl;
		cin >> bc;
		cout << " Name:" << endl; 
		cin >> nm;
		cout << " password: " << endl; 
		cin >> ps; 
		cout << "Amount of money" << endl;
		cin >> amo;
		c->new_bank( bc,  nm, ps, amo);
		
	}
	if (x=="1e"){
		string nm, gend, add, jb; 
		int ag, phn, pssnm, rnk; 
		float sal, rat; 
		cout << " Name:"<< endl; 
		cin >> nm; 
		cout << "Gender:" << endl; 
		cin >> gend;
		cout << " Address:" << endl;
		cin >> add; 
		cout << "Job:" << endl; 
		cin >> jb; 
		cout << "Age:" << endl; 
		cin >> ag; 
		cout << "Phone Number:" << endl; 
		cin >> phn;
		cout << "Passpore Number : " << endl;
		cin >> pssnm;
		cout << "Ranking:" << endl; 
		cin >> rnk;
		cout << "Sallary :" << endl;
		cin >> sal;
		cout << " Rating :" << endl; 
		cin >> rat;
		c->new_employee( nm,  gend, add,  ag, phn, pssnm, jb, sal,  rat,  rnk);
		cout << " .. Added .. " << endl;
	}
	if (x=="2e"){
		string n; 
		cout << "Employee Name:" << endl; 
		cin >> n; 
		c->Delete_employee(n);
		cout << ".. Deleted.." << endl; 
	}
	
	
	
}
	
	







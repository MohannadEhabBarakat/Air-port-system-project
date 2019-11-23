#include<bits/stdc++.h>
#include "person.cpp"
using namespace std;

class bank{
    private:
        long double ACCamont=0;
        string bankACC;
        string name;
        string pass;
    public:
        bank(string bc, string nm, string ps, long double amo){
            bankACC=bc;
            name=nm;
            pass=ps;
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

class transaction{
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


        bool withdraw(){
                if(from->Get_ACCamont() >= ammount) {
                    from->Set_ACCamont(from->Get_ACCamont()-ammount);
                    return true;
                }
                return false;
        }

        bool deposit(){
                to->Set_ACCamont(to->Get_ACCamont()+ammount);
                return true;

        }
};

class Finance : Person{
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
        string transfare  (long double amm,bank *from, bank *to){
            if(this->auth=="with"){
                transaction * trans=new transaction(to,amm,"to");
                transaction * trans2=new transaction(from,amm,"d");
                if(trans->deposit()&&trans2->withdraw()) return "True";
                return "NoMoney";
            }
            return "NotAuth";
        }
};




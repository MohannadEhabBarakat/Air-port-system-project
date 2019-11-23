#include<bits/stdc++.h>
using namespace std;

class plane{
    private:
        map<string,int> clss;
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

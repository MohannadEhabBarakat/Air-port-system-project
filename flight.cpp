#include<bits/stdc++.h>

using namespace std;

class flight{
    private:
        int flight_number; int seatsnumber; string offplace; string destination; string captname;
    public:
	flight(int fnum, int seatsnum, string off, string to, string cname){

		flight_number = fnum;
		seatsnumber = seatsnum;
		offplace = off;
		destination = to;
		captname = cname;
	}
	int get_fnum(){return flight_number;}
};


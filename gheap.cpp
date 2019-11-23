#include<bits/stdc++.h>

using namespace std;

template <class type>
class heap{
    private:
        type arr[1000];
        int last=-1;
    public:
        ~heap(){
            delete(arr);
        }
        void swp(int a, int b){
                type c =arr[b];
                arr[b]=arr[a];
                arr[a]=c;
            }

        void insert(type x){
            last++;
            arr[last]=x;
            int lem = ceil(log2(last));
            int curr =last;

            for(int i=0; i<lem;i++){
                if(curr==1){break;}
                else{
                    if(curr%2 == 0){
                        int n = (curr/2)-1;
                        if(arr[curr]<arr[n]){
                                swp(curr,n);
                                curr=n;
                        }
                        else{break;}
                    }
                    else{
                        int n = ((curr-1)/2)-1;
                        if(arr[curr]<arr[n]){swp(curr,n);curr=n;}
                        else{break;}
                    }
                }
            }
        }
        void printall(){
            for(int i=0; i<last+1;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }

        void del(){
            swp(0,last);
            last--;

            int lem = ceil(log2(last+1));
            int curr =0;

            for(int i=0; i<lem;i++){
                if(curr>=last){break;}
                else{
                    if(arr[curr]>arr[(2*(curr+1))-1] && 2*(curr+1) <= last+1){swp(curr,(2*(curr+1))-1);curr=2*curr;}
                    else if(arr[curr]>arr[(2*(curr+1)+1)-1] && (2*(curr+1))+1 <= last+1){swp(curr,(2*(curr+1)+1)-1);curr=(2*curr)+1;
                    }
                    else{break;}
                }
        }
    }
};
int main(){

    heap <string> *x = new heap <string>;

    x->insert("c");
    x->insert("a");
    x->insert("d");
    x->insert("b");

    x->printall();
    x->del();
    x->printall();


}

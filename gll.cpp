#include<bits/stdc++.h>

using namespace std;

template <class type>

class node{
    public:
        node  *next;
        type data;
};

template <class type>
class ll{
    private:
        node <type> *head;
        node <type> *tail;
    public:
        ll(){
           head=0;
           tail=0;
        }
		node <type> * getHead(){
			return head;
		}
		node <type> * getTail(){
			return tail;
		}
        void add_tail(type x){
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

        void add_head(type x){
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

        void print_ll(){
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
		bool delNext(node<type>*x){
			if(x==tail)return false;
			node <type> * NewNext=x->next->next;
			delete(x->next);
			x->next=NewNext;
			return true;
		}
		void delHead(){
			node <type> * NewHead=head->next;
			delete(head);
			head = NewHead;
		}
        void insert_after(type target,type dt){
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


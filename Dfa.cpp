#include<iterator>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
//#include<conio.h>
#include<sstream>
#include<cstdlib>
using namespace std;

///M=(Q,∑,δ,q0,F=>(input_alphabet,tran,0,f_state,u_state)
///

class Dfa{
private:
set<string> input_alphabet;
vector<int> encode;
/// state start from 0. starting state is always 0.
/// and last one is non reachable state.
/// if given no is 4 then no 0=> starting state,no 0,1,2,3=> 4 state,
/// no-4=>non reachable state.
int u_state;
int i_state;

/// set of final state;
set<int> f_state;

vector<vector<int>> tran ;

protected:

public:
    Dfa(set<string> input_alphabets,int initial_state,set<int> final_states,int states,vector<vector<int>> transaction):
        u_state{states},
        i_state{initial_state}
        {
                input_alphabet=input_alphabets,
                f_state=final_states;
                 tran=transaction;

    //        cout<<"construct";

        };
void info(){
system("color 62");
///tansaction table
cout<<"tansaction table"<<endl;

cout.width(13);
cout<<"|| ";
for(auto i:input_alphabet){

    cout<<i;
     cout.width(5);
 }
cout<<"||"<<endl;

cout<<"=================================================================="<<endl;
int i=0;
for(auto t1:tran){
        if(count(f_state.begin(),f_state.end(),i)){
                cout<<"F-"<<i;}
        else if(i==i_state)cout<<"->"<<i;
         else if(i==u_state)  cout<<"U-"<<i;
         else   cout<<"  "<< i ;

            //cout<<"switch";


           cout.width(10);
          cout<<"|| ";
        for(auto t2:t1){
                cout<<t2;
             cout.width(5);

        }
        i=i+1;
    cout<<"||"<<endl;

}

cout<<"=================================================================="<<endl;
cout.flush();

};

void lex(string str,bool analize=false){
string tok;
int index;
 stringstream ss(str);
 set<string>::iterator it;
  set<string>::iterator beg=input_alphabet.begin();

 while(!ss.eof()){
        ss>>tok;
        if(analize) cout<<"tok="<<tok<<endl;
 if(count(beg,input_alphabet.end(),tok)){

    it=input_alphabet.find(tok);
    //cout<<"it="<<*it<<"beg="<<*beg<<endl;
    index= distance(beg,it);
    encode.push_back(index);

   // cout<<" index="<<index<<endl;
 }else{
 cout<<"no match"<<endl;
 exit(0);
 }


 }


};///end lex function;

bool transaction(bool analize=false){
    int cstate=i_state;
if(analize){
       cout<<"--------------tran-------------"<<endl;
         cout<<"state: "<<cstate<<"->";}
    for(auto x:encode){
        cstate=tran[cstate][x];
        if(analize){cout<<cstate<<"->";}
     if(cstate==u_state){return false;}

    }

    if(count(f_state.begin(),f_state.end(),cstate)){
         return true;
    }
};///end transaction

};


int main(){
vector<vector<int>> tr{   ///  ->[0]--a-->[1]--b-->[[2]] <-|
{1,3},                    ///      |b       |a       |     |
{3,2},                    ///      |-> [3]<-|        |_a,b |
{2,2},
{3,3}
};
Dfa ob({"a","b"},0,{2},3,tr);
ob.info();
system("color 07");
ob.lex("a  b b",true);
cout<<boolalpha<<ob.transaction(true);

return 0;
}


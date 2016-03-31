#include<iterator>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
//#include<conio.h>
#include<sstream>
#include<cstdlib>
#include<clocale>

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
//int u_state;
int i_state;
int l_input;
/// set of final state;
set<int> f_state;

vector<vector<vector<int>>> tran ;

protected:

public:
    Dfa(set<string> input_alphabets,int lamda_input,int initial_state,set<int> final_states,vector<vector<vector<int>>> transaction):
       l_input{lamda_input},
        i_state{initial_state}
        {  //setlocale(LC_ALL, "");
                input_alphabet=input_alphabets,
                f_state=final_states;
                 tran=transaction;

    //        cout<<"construct";

        };
void info(){
//system("color 62");
///tansaction table
cout<<"tansaction table"<<endl;

cout.width(13);
cout<<"|| ";
for(auto i:input_alphabet){

    cout<<i;
     cout.width(5);
 }
 if(l_input){
     cout.width(10);
     cout<<"null";
     cout.width(5);
 }

cout<<"||"<<endl;

cout<<"=================================================================="<<endl;
int i=0;
for(auto t1:tran){
        if(count(f_state.begin(),f_state.end(),i)){
                cout<<"F-"<<i;}
        else if(i==i_state)cout<<"->"<<i;
 //        else if(i==u_state)  cout<<"U-"<<i;
         else   cout<<"  "<< i ;

            //cout<<"switch";


           cout.width(10);
          cout<<"|| ";
        for(auto t2:t1){
                cout<<"{";
                for(auto t3:t2){
                    cout<<t3<<",";
                }
                cout<<"}";
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
vector<int>   cstate{i_state};
vector<vector<int>>   nstate;

if(!(tran[i_state][l_input]).empty()){
        cstate.clear();
    for(auto L:(tran[i_state][l_input]))
    {  // cout<<"L="<<L<<endl;
        cstate.push_back(L);
    }

}
if(analize){
       cout<<"--------------tran-------------"<<endl;
         cout<<"state: "<<i_state<<"->";
if(!(tran[i_state][l_input]).empty()){
        cout<<"{";
        for(auto c:cstate){cout<<c<<",";}
        cout<<"}->";
   }

         }




    for(auto x:encode){
            for(auto s:cstate){
                nstate.push_back(tran[s][x]);
            }

         cstate.clear();
     for(auto n1:nstate){
        for(auto n2:n1){
                cstate.push_back(n2);
                    }
     }
     nstate.clear();

  if(l_input){
        vector<int> cstate2;
    for(auto c:cstate)
    {
      if(!(tran[c][l_input]).empty()){
           for(auto L:(tran[c][l_input]))
          {  // cout<<"L="<<L<<endl;
        cstate2.push_back(L);
        }

      }else{
              cstate2.push_back(c);

      }
    }
    cstate.clear();
    cstate=cstate2;
  }





if(analize){
        cout<<"{";
        for(auto c:cstate) {
        cout<<c<<",";
        }
        cout<<"}->"<<endl;

}

    }
    for(auto c:cstate) {
    if(count(f_state.begin(),f_state.end(),c)){
         return true;
    }}
    return false;
};///end transaction

};


int main(){
vector<vector<vector<int>>> tr{
    {{1},{},{}   }    ///0
    ,{{1},{2},{} }   ///1
    ,{{},{},{0} }   ///2
    //,{{},{1},{} },  ///3
   // ,{{},{5},{} }    ,  ///4
   // ,{{2},{},{} }            ///5


};
Dfa ob({"a","b"},2,0,{1},tr);
ob.info();
//system("color 07");
ob.lex("a b a b a",true);
cout<<boolalpha<<ob.transaction(true);

return 0;
}


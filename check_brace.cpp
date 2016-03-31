#include<iostream>
#include<stack>
#include<string>
using namespace std;
class check_brace{
private:
    stack<char> stk;


public:
//   check_brace(){
//      stk.clear();
//    }
bool check(string str){
    char ch;
   while(!stk.empty()) stk.pop();
for(auto c:str){
//       cout<<c<<endl;
      switch(c){

      case '(': stk.push('(');break;
      case '{':stk.push('{') ;break;
      case '[':stk.push('[');break;
      case ')': ch=stk.top();
               stk.pop();
               if(ch!='(')return false;
               break;
      case '}':ch=stk.top();
              stk.pop() ;
              if(ch!='{')return false;
               break;
      case ']':ch=stk.top();
             stk.pop();            // cout<<"ch="<<ch<<endl;
              if(ch!='[')return false;
              break;

      }
 //    cout<<'ch='<<ch<<endl;

}
   if(stk.empty()){cout<<"empty"<<endl ; return true;
   }else{return false;}


};

};

/*int main(){
check_brace cb("(a+(b*{c+{d+[e+6}}))");
cout<<boolalpha <<cb.check();
return 0;
}*/

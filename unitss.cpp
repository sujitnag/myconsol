#include<iostream>
#include<map>
#include<tuple>
#include<string>
using namespace std;

enum class quantity:int{STATE=0,LENGTH=1,WIDTH=1,HEIGHT=1,VOLUME,MASS,DENCITY,TEMPARATURE};
class unit{
    protected:
      map<quantity,string> pUnit;///primary unit
      map<quantity,tuple<string,string>> dUnit;/// derived unit
    public:

      void cTable(quantity q,string symbol){
      pUnit[q]=symbol;
      }
      void cTable(quantity q,string symbol,string sform){
      dUnit[q]=make_tuple(symbol,sform)  ;   }
      void getV(quantity q){
        cout<< pUnit[q]<<endl ;
      }
      void getV1(quantity q){
        cout<< get<0>(dUnit[q])<<" "<<get<1>(dUnit[q])<<endl ;
      }
    bool isAddable(unit U1){
        cout<<U1.dUnit.

    }

};

int main(){
unit ob;
ob.cTable(quantity::LENGTH,"m");
ob.cTable(quantity::MASS,"gm");
ob.cTable(quantity::VOLUME,"m*m*m","m3");

ob.getV(quantity::WIDTH);
ob.getV1(quantity::VOLUME);


return 0;
}

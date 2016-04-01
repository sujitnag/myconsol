#include <iostream>

using namespace std;

auto main()->int {
size_t x=166;
cout<<x;
}




/*int main() {
int m=0;
int n,a;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
sort(v.begin(),v.end());
for(auto h:v){
    a=n*h;
    if(a>m) m=a;
    n-=1;

}
cout<<m<<endl;
//cout<<str<<endl;
return 0;
}
/*
int n;
cin>>n;
string str;

while(n-->0){
        char ch;
    cin>>str;
    string::iterator istr=str.begin();
string::iterator ristr=str.end()-1;
    while(istr<ristr){
         //   cout<<*istr<<" "<<*ristr<<endl;
    //cin>>ch;
        switch(*istr){
            case '[':if(*ristr!=']'){
                                   cout<<"NO"<<endl;
                                   istr=ristr;
                                   break;
                                    }
                      --ristr;
                      ++istr;
                      break;
          case '(':if(*ristr!=')'){
                                     cout<<"NO"<<endl;
                                    istr=ristr;
                                     break;
                                    }
                      --ristr;
                      ++istr;
                      break;

       case '{':if(*ristr!='}'){
                                     cout<<"NO"<<endl;
                                   istr=ristr;
                                   break;
                                    }
                      --ristr;
                      ++istr;
                      break;

        }


    }

if( istr!=ristr) cout<<"YES"<<endl;

}

return 0;
}


*/


/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> st;
    int n,q,v,m=INT_MIN;
    cin>>n;
    while(n-->0){
        cin>>q;
        switch(q){
            case 1: cin>>v;

                    st.push_back(v);
                    if(v>m) m=v;
                    cout<<"c1:v:m="<<v<<":"<<m<<endl;
                    break;
            case 2:if(st.size()){
                                 v=*(st.end()-1);
                                 st.pop_back();
                                 if(m==v)m=INT_MIN;
                                 cout<<"c2:v:m="<<v<<":"<<m<<endl;
                                 }
                                 break;
            case 3:if(m==INT_MIN)m=*max_element(st.begin(),st.end());
                   cout<<"c3:m="<<m<<endl;
                   break;
           default:return 0;


        }


    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   // return 0;
//}


/*#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

//cout<<INT_MAX;

long long c,m,n;
cin>>c>>m>>n;
if (!(c>=1 and c<= pow(10,9))) return 0;
if (!(m>=1 and m<= pow(10,9)))return 0;
if (!(n>=1 and n<=(3*pow(10,5))))return 0;
vector<int> a(2*n+2);
//vector<vector<long long>> v(n);
//vector<long long> vs(2);
int r;
set<long long> s;
a[0]=0;
a[1]=c;
n=(2*n+1);
for(long long i=2;i<=n;i++){
    a[i]=(a[i-2]+a[i-1])%m;
}
a.erase(a.begin(),a.begin()+2);

//for(int i=0;i<=n-2;i++){
//    cout<<a[i]<<" ";
//}
//cout<<endl;3
for(long long i=0;i<n-3;i+=2){
    for(long long j=i+1;j<n-3;j+=2){
          //  cout<<a[i]<<" "<<a[j+1]<<" "<<a[i+1]<<" "<<a[j+2]<<endl;
            r=abs(a[i]*a[j+1]+a[i+1]*a[j+2])%m;
       // if(i!=j){
          // cout<<"i="<<i<<"j="<<j<<"r="<<r<<endl;
            s.insert(s.begin(),r);
//z=(z+1)%m;
        //}
    }

}

//for(auto t:s) cout<<t<<" ";
//cout<<endl;

cout<<(s.size()%m)<<endl;
    return 0;
}




/*#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class minD{
private:
    vector<vector<int>> v;
    int t,m,n,d;

    getV(){
    cin>>n>>m;
    vector<int> m1(3);
    for(int i=0;i<m;i++){
        cin>>m1[0]>>m1[1]>>m1[2];
        v.push_back(m1);
            }


    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }


    };
    minDCal(){
    //sort(v.begin(),v.end(),)


    };

public:
    minD(){t=0;m=0;n=0;d=0;};
 void   testCase(){
    cin>>t;
    while(t-->0){
        getV();
        minDCal();
        cout<<d<<endl;
    }

    };

};
int main(){
minD ob;
ob.testCase();
return 0;
}

*/


















/*#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
  vector<vector<int>> v;
   int t,m,n,br1=-1,br2=1;
void getV(){
      cin>>m>>n  ;
      vector<int> v1(2);
      for(int j=0;j<n;n++){
            cin>>v1[0];
            cin>>v1[1];
            v.push_back(v1);

        }

}

void min_d(int d,int i,int br1,int br2){
    int d1,d2,dd;
    dd=abs(v[i][1]-v[i][0]);
    d1=d+dd+abs(v[i][0]-br1);
    d2=d+dd+abs(v[i][0]-br2);
    if(i<n){
           // brg
        min_d(d1,i+1,v[i][1],br2);
        min_d(d2,i+1,br1,v[i][1]);
    }


}

int main(){

    while(t-->0){
      void getV();








    }


return 0;
}



/*#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
 int n;
  long long ans=0;
  long long m=(pow(10,9)+7);

  cin>>n;
  if(!(n>=1 && n<=2*pow(10,5))) return 0;

  long long A[n];
  long long v[n][n];

  for(int i=0;i<n;i++){
    cin>>A[i];
 if(!(A[i]>=1 && A[i]<=pow(10,9))) return 0;

}

for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    if(i==j){v[i][j]=A[i];
    }else{
     v[i][j]=(*min_element(A+i,A+j+1));
    }


}

}


for(int a=0;a<n;a++){
    for(int b=a;b<n;b++){
          //  f=(*min_element(A+a,A+b+1))%m;
        for(int c=b+1;c<n;c++){
         for(int d=c;d<n;d++){

            if(c==b+1){
                if(a>b) {int p=a;a=b;b=p;}
                if(c>d) {int p=c;c=d;d=p;}
                    ans=(ans+v[a][d])%m;
            }else {
                 if(a>b) {int p=a;a=b;b=p;}
                if(c>d) {int p=c;c=d;d=p;}
                ans=(ans+min(v[a][b],v[c][d]))%m;

            }


         }}}}






/*
for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
    int p=*min_element(A+i,A+j+2);
    ans=ans+(j+1-i)*p;
   if((j-i)>=2){
    A[i]>A[j]?ans=ans+A[j]:ans+=A[i];
   }



}
}*/
//cout<<ans;
//
//
//
//
//return 0;
//}

/*
// Include the Connector/C++ headers
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"

// Link to the Connector/C++ library
#pragma comment(lib, "mysqlcppconn.lib")

// Specify our connection target and credentials
const string server   = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "sujitnag"; // No password - thanks, WAMP Server!

int main()
{
	sql::Driver     *driver; // Create a pointer to a MySQL driver object
        sql::Connection *dbConn; // Create a pointer to a database connection object
        sql::Statement  *stmt;   // Create a pointer to a Statement object to hold our SQL commands
        sql::ResultSet  *res;    // Create a pointer to a ResultSet object to hold the results of any queries we run

	// Try to get a driver to use to connect to our DBMS
	try
	{
		driver = get_driver_instance();
	}
	catch (sql::SQLException e)
	{
		cout << "Could not get a database driver. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	// Try to connect to the DBMS server
	try
	{
		dbConn = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to database. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	stmt = dbConn->createStatement(); // Specify which connection our SQL statement should be executed on

	// Try to query the database
	try
	{
		stmt->execute("USE mysql");              // Select which database to use. Notice that we use "execute" to perform a command.

		res = stmt->executeQuery("show tables"); // Perform a query and get the results. Notice that we use "executeQuery" to get results back
	}
	catch (sql::SQLException e)
	{
		cout << "SQL error. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	// While there are still results (i.e. rows/records) in our result set...
	while (res->next())
	{
		// ...get each field we want and output it to the screen
		// Note: The first field/column in our result-set is field 1 (one) and -NOT- field 0 (zero)
		// Also, if we know the name of the field then we can also get it directly by name by using:
		// res->getString("TheNameOfTheField");
		cout << res->getString(1) << endl;
	}

	// Clean up after ourselves
	delete res;
	delete stmt;
	delete dbConn;

	//system("pause");
	return 0;
}
*/

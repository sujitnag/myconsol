#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
// system("notepad.exe myt.txt");
string str;
 system("tasklist  /FI \"IMAGENAME eq notepad.exe\" /NH > temp.txt");// notepad.exe");// > D:/usl_project/other/temp.txt");
fstream in("temp.txt",fstream::in);
for(int i=0;i<2;i++){
in>>str;}
in.close();
cout<<str;
char *ch=new char[str.length()];
str="taskkill /pid "+str;
strcpy(ch,str.c_str());
cout<<*ch;
system(ch);// notepad.exe");// > D:/usl_project/other/temp.txt");

return 0;
}
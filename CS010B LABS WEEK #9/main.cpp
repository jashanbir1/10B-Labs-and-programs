#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s)
{
   if(s.size() == 0)
   {
      return;
   }
   else
   {
      string s1;
      char c2;
      s1 = s.substr(0,s.size() -1);
      c2 = s.at(s.size() -1);
      flipString(s1);
      s = c2 + s1;
   }
   
}



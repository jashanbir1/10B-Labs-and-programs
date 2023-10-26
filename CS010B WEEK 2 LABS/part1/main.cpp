#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum (const string &name);

int main() {

   string filename;
   int sum = 0;

   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string &name)
{
   ifstream nameFS;
   int nums;
   int sum = 0;

   nameFS.open(name);

   if(!nameFS.is_open())
   {
      cout << "Error opening "<< name << endl;
      exit(EXIT_FAILURE);
   }
   else
   {
      while (nameFS >> nums)
      {
      sum = sum + nums;
      
      }
      
   }

   nameFS.close();
   return sum;

  
}

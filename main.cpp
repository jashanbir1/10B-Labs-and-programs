#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   int numInput;
   vector<int> nums;
   char comma;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inputFS;

   inputFS.open(inputFile);
   
   // Verify file opened correctly.
   
   // Output error message and return 1 if file stream did not open correctly.
   if(!inputFS.is_open())
   {
      cout << "Error opening " << inputFile << endl;
      return(1);
   }
   // Read in integers from input file to vector.
   else
   {
      while (inputFS >> numInput)
      {
      nums.push_back(numInput);
      if(!inputFS.fail())
      {
         inputFS >> comma;
      }
      }
   }
   
   
   // Close input stream.
   inputFS.close();
   
   // Get integer average of all values read in.
   int avg;
   int totalVec = 0;

   for (unsigned int i = 0; i < nums.size(); ++i)
   {
      totalVec = totalVec + nums.at(i);
   }

   avg = totalVec / nums.size();

   
   
   // Convert each value within vector to be the difference between the original value and the average.
   //int newValue;
   //vector<int> newNums;

   for(unsigned int i = 0; i < nums.size();++i)
   {
      nums.at(i) = nums.at(i) - avg;

   }
   
   // Create output stream and open/create output csv file.
   ofstream outputFS;

   outputFS.open(outputFile);

   // Verify file opened or was created correctly.

   // Output error message and return 1 if file stream did not open correctly.
   if(!outputFS.is_open())
   {
      cout << "Error opening " << outputFile << endl;
      return(1);
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   
   for( unsigned int i = 0;i < nums.size();i++)
   {
      outputFS << nums.at(i);
      //cout << nums.at(i) << " ";
      if (i + 1 < nums.size())
      {
         outputFS << ',';
         //cout << ',';
      }
   }
   
   // Close output stream.
   outputFS.close();

   
   return 0;
}


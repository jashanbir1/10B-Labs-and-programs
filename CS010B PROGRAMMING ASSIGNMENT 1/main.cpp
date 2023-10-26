#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void readData(const string &fileName, vector<double> &flightP, vector<double> &coeffLift)
{
    ifstream inputFS;
    double storeAngle;
    double storeCoeffLift;

    inputFS.open(fileName);

    if(!inputFS.is_open())
    {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    while (inputFS >> storeAngle)
    {
        inputFS >> storeCoeffLift;
        flightP.push_back(storeAngle);
        coeffLift.push_back(storeCoeffLift);
    }

    inputFS.close();

}
double interpolation(double userInp, const vector<double> &flightP, const vector<double> &coeffLift)
{

  
   double returnVal = 0;
   for (unsigned int i = 0; i < flightP.size();++i)
   {
    if (flightP.at(i) == userInp)
    {
        return coeffLift.at(i);
    }
   
   
    else if ((userInp > flightP.at(i)) && (userInp < flightP.at(i+1)))
    {
        returnVal = coeffLift.at(i) + (userInp - flightP.at(i)) / (flightP.at(i+1) - flightP.at(i)) * (coeffLift.at(i+1) - coeffLift.at(i));
      
    }
   }
   return returnVal;

   }

bool isOrdered(const vector<double> &flightP)
{
    if(flightP.size() == 0)
    {
        return true;
    }    
    //double ascend;
    //ascend = flightP.at(0);
    if (flightP.size() >=2)
    {
        for (unsigned int i = 0; i < flightP.size()-1; ++i)
        {
            //for (unsigned int j = i+1; j < flightP.size();++j)
            //{

            //if(flightP.at(i) > flightP.at(i+1))
            if(flightP.at(i) > flightP.at(i+1))
            {
            return false;
            }

        }

    }
    return true;
}

void reorder(vector<double> &flightP, vector<double> &coeffLift)
{
    double temp;
    double temp1;
    for (unsigned int i = 0; i+1 < flightP.size(); ++i)
    {
        //int smallestIndex = i;
        for (unsigned int j = i +1; j < flightP.size(); ++j)
        {
        if(flightP.at(i) > flightP.at(j))
        { 
         temp = flightP.at(j);
        flightP.at(j) = flightP.at(i);
        flightP.at(i)= temp;
        temp1 = coeffLift.at(j);
        coeffLift.at(j) = coeffLift.at(i);
        coeffLift.at(i) = temp1;
        }
        }
         
    }
   
}


int main(int argc, char* argv[]) {


string fileName;
string userChoice;
double userInput;
//double coeff;
vector<double> flightP;
vector<double> coeffLift;


fileName = argv[1];
readData(fileName,flightP,coeffLift);

if(!isOrdered(flightP))
{
    reorder(flightP, coeffLift);
}
//while (Yes)
//{

//bool notYes = false;
bool inputAgain = true;
while(inputAgain)
{
    cout << "Enter a flight path angle: "; //<< userInput << endl;
    cin >> userInput;
    if (userInput < flightP.at(0) || userInput > flightP.at(flightP.size() - 1))
    {
        cout << "not valid" << endl;
    }

    else
    {
        cout << "coefficient of angle is " << interpolation(userInput,flightP,coeffLift) << endl;
    }

    cout << "Do you want to enter another angle?" << endl;
    cin >> userChoice;
    /*if (userChoice == "Yes")
    {
        inputAgain = true;
    }*/

    if (userChoice != "Yes")
    {
        inputAgain = false;
        //notYes = false;
        //cout << "No more inputs." << endl;
    }
}

    
    //{
    //    cout << "GOODBYE" << endl;
    //}
    //{
   // else
    //{   
    
    //}
   //}
    
    /*{
            cout << "out of bounds" << endl;
    }*/
    
//}






}


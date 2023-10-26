#include <iostream>

using namespace std;

#include "IntVector.h"

void printVector(const IntVector &  v) {
    for (unsigned i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main() 
{
    IntVector vec1(5,3);

    cout << "Testing Constructor" << endl;

    for (unsigned i = 0; i < vec1.size(); ++i)
    {
        cout << vec1.at(i) << " ";
    }

    cout << endl;

    cout << "Testing Front and Back" << endl;
    //cout << vec1.at(3);
    vec1.back() = 8;
    cout << vec1.front() << " " << vec1.back() << endl;

    cout << endl;

    cout << "Testing push_back" << endl;
    printVector(vec1);
    vec1.push_back(90);
    // cout << vec1.back() << endl;
    cout << endl;
    printVector(vec1);

    cout << "Testing insert" << endl;
    printVector(vec1);
    // cout << vec1.size() << endl;
    // cout << vec1.at(3) << endl;
    vec1.insert(3,6);
    
    // cout << vec1.size() << endl;
    // cout << vec1.at(3) << endl;
    printVector(vec1);

    cout << "Testing erase" << endl;
    printVector(vec1);

    cout << endl;
    vec1.erase(3);
    printVector(vec1);
    cout << vec1.at(3) << endl;

    cout << "Testing assign" << endl;

    printVector(vec1);

    vec1.assign(2,5);
    printVector(vec1);

    // cout << "Testing expand" << endl;
    // printVector(vec1);
    // vec1.expand(8);

    // printVector(vec1);


return 0;
}
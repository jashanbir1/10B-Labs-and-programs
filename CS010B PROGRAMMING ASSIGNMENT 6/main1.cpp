#include <iostream>

using namespace std;

#include "SortedSet.h"
#include "IntList.h"
int main(){
cout << "TESTING ADD FUNCTION" << endl;
SortedSet set1;
cout << "add 30" << endl;
set1.add(30);
cout << set1 << " " << endl;
cout << "add 69" << endl;
set1.add(69);
cout << set1 << " " << endl;
cout << "add 24" << endl;
set1.add(24);
cout << set1 << " " << endl;
cout << "adding 81" << endl;
set1.add(81);
cout << set1 << " " << endl;
cout << "adding 12" << endl;
set1.add(12);
cout << set1 << " " << endl;
cout << "adding 25" << endl;
set1.add(25);
cout << set1 << endl;
cout << endl;

cout << "TESTING push_front, push_back, insert_ordered" << endl;
//SortedSet set2;
set1.insert_ordered(43);
cout << set1 << endl;
set1.insert_ordered(54);
cout << set1 << endl;
set1.insert_ordered(11);
cout << set1 << endl;
set1.push_front(52);
cout << set1 << endl;
set1.insert_ordered(82);
cout << set1 << endl;

// set1.insert_ordered(13);
// cout << set1 << endl;
// set1.insert_ordered(15);
// cout << set1 << endl;
}
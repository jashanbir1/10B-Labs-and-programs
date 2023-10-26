#include <iostream> 

using namespace std;

#include "SortedSet.h"
#include "IntList.h"

int main(){

   // IntList l1;
   // l1.push_back(1);
   // l1.push_back(1);
   // l1.push_back(2);
   // l1.push_back(2);
   // l1.push_front(3);

   // cout << "printing l1" << endl;
   // cout << l1 << endl;

   // SortedSet s1(l1);
   // cout << "printing s1" << endl;
   // cout << s1 << endl;


   // SortedSet s2(s1);
   // cout << "printing s2\n";
   // cout << s2 << endl;

   // if (true)
   // return 0;

     //LINES 9-165 COPIED FROM MAIN.CPP PROGRAM 5
     //TEST ADD, IN, OPERATOR |, OPERATOR &, OPERATOR |=, OPERATOR &=.
       cout << "Enter a test number(1-8): ";
 	int test;
 	cin >> test;
	cout << endl;
    // tests constructor, destructor, push_front, pop_front, display
    if (test == 1) {
       cout << endl;
       cout << "list1 constructor called" << endl;
       SortedSet list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
       cout << "pushfront 20" << endl;
      list1.push_front(20);
       cout << "pushfront 30" << endl;
       list1.push_front(30);
       cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
       list1.pop_front();
       cout << "list1: " << list1 << endl;
       cout << "pop" << endl;
       list1.pop_front();
      cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
     }
     if (test == 1) {
        cout << "list1 destructor called" << endl;
     }

      //tests push_back
     if (test == 2) {
        cout << endl;
        cout << "list2 constructor called" << endl;
        SortedSet list2;
        cout << "pushback 10" << endl;
        list2.push_back(10);
        cout << "pushback 20" << endl;
        list2.push_back(20);
        cout << "pushback 30" << endl;
        list2.push_back(30);
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
     }
     if (test == 2) {
        cout << "list2 destructor called" << endl;
     }

     // tests selection_sort
     if (test == 3) {
        cout << endl;
        cout << "list3 constructor called" << endl;
        SortedSet list3;
        cout << "pushfront 10" << endl;
        list3.push_front(10);
        cout << "pushfront 20" << endl;
        list3.push_front(20);
        cout << "pushfront 30" << endl;
        list3.push_front(30);
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pop" << endl;
        list3.pop_front();
        cout << "pop" << endl;
        list3.pop_front();
        cout << "pop" << endl;
        list3.pop_front();
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pushfront 10" << endl;
        list3.push_front(10);
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pushfront 20" << endl;
        list3.push_front(20);
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
     }
     if (test == 3) {
        cout << "list3 destructor called" << endl;
     }

      //tests insert_sorted
     if (test == 4) {
        cout << endl;
        cout << "list4 constructor called" << endl;
        SortedSet list4;
        cout << "insert 20" << endl;
        list4.insert_ordered(20);
        cout << "insert 10" << endl;
        list4.insert_ordered(10);
        cout << "insert 30" << endl;
        list4.insert_ordered(30);
        cout << "list4: " << list4 << endl;
        cout << "insert 50" << endl;
        list4.insert_ordered(50);
        cout << "list4: " << list4 << endl;
        cout << "insert 40" << endl;
        list4.insert_ordered(40);
        cout << "list4: " << list4 << endl;
        cout << "insert 11" << endl;
        list4.insert_ordered(11);
        cout << "list4: " << list4 << endl;
        cout << "insert 10" << endl;
        list4.insert_ordered(10);
        cout << "list4: " << list4 << endl;
        cout << "insert 11" << endl;
        list4.insert_ordered(11);
        cout << "list4: " << list4 << endl;
        cout << "insert 9" << endl;
        list4.insert_ordered(9);
        cout << "list4: " << list4 << endl;
        cout << "insert 50" << endl;
        list4.insert_ordered(50);
        cout << "list4: " << list4 << endl;
        cout << "insert 51" << endl;
        list4.insert_ordered(51);
        cout << "list4: " << list4 << endl;
     }
     if (test == 4) {
        cout << "list4 destructor called" << endl;
     }
   
      //tests remove_duplicates
     if (test == 5) {
        cout << endl;
        cout << "list5 constructor called" << endl;
        SortedSet list5;
        cout << "pushfront 10" << endl;
        list5.push_front(10);
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "pushfront 10" << endl;
        list5.push_front(10);
        cout << "pushfront 30" << endl;
        list5.push_front(30);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
     }

       //TEST ADD
      if(test == 6)
      {
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
        cout << "add 27" << endl;
        set1.add(27);
        cout << set1 << endl;
        cout << "add 32" << endl;
        set1.add(32);
        cout << set1 << endl;
        cout << "add 32 again" << endl;
        set1.add(32);
        cout << set1 << endl;
        cout << endl;
        
        cout << "add 69" << endl;
        set1.add(69);
        cout << set1 << endl;
        cout << "add 43" << endl;
        set1.add(43);
        cout << set1 << endl;
      
      // if(test == 7)
      // {
         cout << endl;
         cout << "TESTING push_front, push_back, insert_ordered" << endl;
         //SortedSet set2;
         // set1.insert_ordered(43);
         // cout << set1 << endl;
         // set1.insert_ordered(54);
         // cout << set1 << endl;
         // set1.insert_ordered(11);
         // cout << set1 << endl;
         cout << "push front 52" << endl;
         set1.push_front(52);
         cout << set1 << endl;
         cout << "push front 10" << endl;
         set1.push_front(10);
         cout << set1 << endl;
         // set1.insert_ordered(82);
         // cout << set1 << endl;
         cout << "push back 76" << endl;
         set1.push_back(76);
         cout << set1 << endl;
         cout << "push back 9" << endl;
         set1.push_back(9);
         cout << set1 << endl;

         if(set1.in(6))
         {
            cout << "YES" << endl;
         }
         else
         {
            cout << "NO" << endl;
         }
         if(set1.in(9))
         {
            cout << "YES" << endl;
         }
         else
         {
            cout << "NO" << endl;
         }
         
     }
}
  



   //   if (test == 7)
   //   {
   //      cout << "TESTING IN FUNCTION" << endl;
   //      SortedSet set;
   //      int num1;
   //      cin >> num1;
   //      for(unsigned i = 0; i < 11; ++i)
   //      {
   //         set1.push_back(i);
   //      }
   //      cout << "Is num1 in set2?" << endl;
   //      set2.in(3);

    










 
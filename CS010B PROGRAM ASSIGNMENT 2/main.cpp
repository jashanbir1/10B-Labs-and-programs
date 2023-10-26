#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date::Date()
{
   this->day = 1;
   this->month = 1;
   this->year = 2000;
   this->monthName = "January";
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
   //OUTPUT IN NUMERIC ORDER (3/15/2012)
   // this->day = d;
   //this->month = m;
   this->year = y;
   bool torf = false;

   if(m > 12)
   {
      this->month = 12;
      this->monthName = "December";
      torf = true;

   }
   else if(m < 1)
   {
      this->month = 1;
      this->monthName = "January";
      torf = true;
   }
   else
   {
      this->month = m;
      this->monthName = this->name(m);
      //torf = true;
   }
   
   if (d > this->daysPerMonth(this->month,this->year))
   {
      this->day = this->daysPerMonth(this->month,this->year);
      torf = true;
   }
   else if (d < 1)
   {
      this->day = 1;
      torf = true;
   }
   // else if ( d == 29)
   // {
   //    if(isLeap(y))
   //    {
   //       return 29;
   //    }
   //    else
   //    {
   //       return 28;
   //    }
   
   else
   {
      this->day = d;
   }
   if(torf)
   {
      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << '.' << endl;
   }

}

Date::Date(const string &mn, unsigned d, unsigned y)
{
   //OUPUT 
   bool torf = false;
   if(this->number(mn) == 13)
   {
      this->month = 1;
      this->day = 1;
      this->monthName = "January";
      this->year = 2000;
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      //torf = true;
   }
   else
   {
      this->monthName = mn;
      this->month = this->number(mn);
      this->year = y;
   

      if(d > this->daysPerMonth(this->month,this->year))
      {
         this->day = this->daysPerMonth(this->month,this->year);
         torf = true;
      }
      else if(d < 1)
      {
         this->day = 1;
         torf = true;
      }
      else
      {
         this->day = d;
         //torf = true;
      }

      if (islower(this->monthName.at(0)))
      {
         this->monthName.at(0) = toupper(this->monthName.at(0));
      }
      if(torf)
      {
         cout << "Invalid date values: Date corrected to ";
         printNumeric();
         cout << '.' << endl;
      }
   
   }
   
   // this->monthName = mn;
   // this->day = d;
   // this->year = y;

}

void Date::printNumeric() const
{
   cout << this->month << "/" << this->day << "/" << this->year;
}

void Date::printAlpha() const
{
   //this->monthName = toUpper(this->monthName.at(0));

   cout << this->monthName << " " << this->day << ", " << this->year;

}

bool Date::isLeap(unsigned y) const
{
   if(y % 4 == 0)
   {
      if (y % 100 == 0)
      {
         return y % 400 == 0;
      }
      return true;
   }
   else
   {
      return false;
   }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   int oddMonth = 31;
   int evenMonth = 30;

   if ( m == 2)
   {
      if (this->isLeap(y))
      {
         
         return 29;
      }
      else
      {
         return 28;
      }
   }
   else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
   {
      return oddMonth;
   }
   else
   {
      return evenMonth;
   }
}

string Date::name(unsigned m) const
{
   string Jan = "January";
   string feb = "February";
   string mar = "March";
   string apr = "April";
   string may = "May";
   string june = "June";
   string july = "July";
   string august = "August";
   string sept = "September";
   string Oct = "October";
   string Nov = "November";
   string Dec = "December";

   if(m == 1)
   {
      return Jan;
   }
   if (m == 2)
   {
      return feb;
   }
   if(m == 3)
   {
      return mar;
   }
   if(m == 4)
   {
      return apr;
   }
   if(m == 5)
   {
      return may;
   }
   if(m == 6)
   {
      return june;
   }
   if(m == 7)
   {
      return july;
   }
   if(m == 8)
   {
      return august;
   }
   if(m == 9)
   {
      return sept;
   }
   if(m == 10)
   {
      return Oct;
   }
   if(m == 11)
   {
      return Nov;
   }
   if (m == 12)
   {
      return Dec;
   }
   return "";
}
   
unsigned Date::number(const string &mn) const
{
   //string MN = mn;
   if(mn == "January" || mn == "january")
   {
      return 1;
   }
   if(mn == "February" || mn == "february")
   {
      return 2;
   }
   if(mn == "March" || mn == "march")
   {
      return 3;
   }
   if(mn == "April" || mn == "april")
   {
      return 4;
   }
   if(mn == "May" || mn == "may")
   {
      return 5;
   }
   if(mn == "June" || mn == "june")
   {
      return 6;
   }
   if(mn == "July" || mn == "july")
   {
      return 7;
   }
   if(mn == "August" || mn == "august")
   {
      return 8;
   }
   if(mn == "September" || mn == "september")
   {
      return 9;
   }
   if (mn == "October" || mn == "october")
   {
      return 10;
   }
   if(mn == "November" || mn == "november")
   {
      return 11;
   }
   if(mn == "December" || mn == "december")
   {
      return 12;
   }
   return 13;
}

   











// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int number); 
      Rational(int num, int den); 
      Rational add(const Rational &rhs) const; 
      Rational subtract(const Rational &rhs) const; 
      Rational multiply(const Rational &rhs) const; 
      Rational divide(const Rational &rhs) const;
      void simplify();
      void display() const;
   private:
      int gcd(int num, int den) const;
};
// WANTS TO RETURN IN (N / D) FORMAT IN DISPLAY
// Implement Rational class member functions here
Rational::Rational()
{
   this->numerator = 0;
   this->denominator = 1;
}
Rational::Rational (int number)
{
   this->numerator = number;
   this->denominator = 1;
}
Rational::Rational(int numer, int denom)
{
   this->numerator = numer;
   this->denominator = denom;
}


Rational Rational:: add(const Rational &rhs) const
{
   Rational result;
   int numer1 = this->numerator; //a
   int denom1 = this->denominator;  //b
   int numer2 = rhs.numerator;    //c
   int denom2 = rhs.denominator;    //d
   //FOR ADD: (a/b) + (c/d) = (ad + bc) / (b*d)

   int n = (numer1*denom2) + (denom1*numer2);
   int d = denom1 * denom2;
   
   return Rational(n,d);
   //rational sum (int num1,int num2);
   //return sum;
   
}
Rational Rational:: subtract(const Rational &rhs) const
{
   Rational result;
   int numer1 = this->numerator; //a
   int denom1 = this->denominator;  //b
   int numer2 = rhs.numerator;    //c
   int denom2 = rhs.denominator;    //d
   //FOR SUBTRACT: (a/b) - (c/d) = (ad - bc) / (b*d)

   int n = ((numer1*denom2) - (denom1*numer2));
   int d = denom1 * denom2;

   return Rational(n,d);
}

Rational Rational::multiply(const Rational &rhs) const
{
   Rational result;
   int numer1 = this->numerator; //a
   int denom1 = this->denominator;  //b
   int numer2 = rhs.numerator;    //c
   int denom2 = rhs.denominator;    //d
   //FOR MULTIPLY: (a/b) * (c/d) = (ac) / (bd)

   int n = (numer1 * numer2);
   int d = (denom1 * denom2);

   return Rational(n,d);
}

Rational Rational::divide(const Rational &rhs) const
{
   Rational result;
   int numer1 = this->numerator; //a
   int denom1 = this->denominator;  //b
   int numer2 = rhs.numerator;    //c
   int denom2 = rhs.denominator;    //d
   //FOR DIVIDE: (a/b) / (c/d) = (a/d) / (c/b)

   int n = (numer1 * denom2);
   int d = (numer2 * denom1);
   
   return Rational(n,d);
}
int Rational::gcd(int num1,int num2) const
{
  while (num1 != num2)
 {
    if (num2 > num1)
      {
        num2 -= num1;
      }
      else 
      {
          num1 -= num2;
      }
 }
   return num1;
}

void Rational:: simplify()
{
   int gcd = this->gcd(this->numerator, this->denominator);
   this->numerator = this->numerator / gcd;
   this->denominator = this->denominator / gcd;

}

void Rational:: display() const
{
   cout << this->numerator << " / " << this->denominator;
}







// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}


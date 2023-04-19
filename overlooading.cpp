#include <iostream>
#include <string>
#include <vector>

using namespace std;

// based on: https://www.tutorialspoint.com/cplusplus/cpp_templates.htm

struct date{
  int year;
  int month;
  int day;

  // Overloading < and > did not automatically overload <= and >=.
  bool operator <(const date& date) const{
      if (year < date.year){  
         return true;
      }
      if (month < date.month) {
         return true;
      }
      if (day < date.day) {
         return true;
      }
      return false;
   }

  bool operator >(const date& date) const{
   if(year > date.year){
      return true;
   }
   if (month > date.month) {
      return true;
   }
   if (day > date.day) {
      return true;
   }
      return false;
  }
};


// Using overloading of < (note: T has no type restrictions)
template <typename T>
T  Max (T a, T  b) { // name max is pre-defined, so using Max
   return a < b ? b:a; // using <, expect it to be implemented in T
}
 template <typename T>
T  Min (T a, T  b) { // name max is pre-defined, so using Max
   return a > b ? a:b; // using <, expect it to be implemented in T
}


/*
 when an element is added to a collection, its counter is set to 0, and is
 incremented every time the element is retrieved. If an element is replaced 
 by another one, the counter goes to 0. Elements are never deleted, only added and replaced. 
*/
template <typename T>
class countedVector {
   std::vector <T> elements;
   std::vector <int> counts;

   public:
   countedVector(){}

   void add(T element) {
      elements.push_back(element);
      counts.push_back(0);
   }

   T get(int index) {
      T res = elements.at(index);
      counts.at(index)++;
      return res;
   }

   int getCounter(int index) {
      return counts.at(index);
   }

   void set(int index, T element) {
      if(index < elements.size) {
         elements.erase(index);
         elements.push_back(element);
         counts.at(index) = 0;
      }
      else {
         add(element);
      }

   }

   void toString() {
      cout << "Elements: " << endl;
      for(int i = 0; i < elements.size(); i++) {
         cout << elements.at(i) << " ";
      }
      cout << endl << "Counts: " << endl;
      for (int j = 0; j < counts.size(); j++) {
         cout << counts.at(j) << " ";
      }
      cout << endl;
   }
};

int main () {
   int i = 39;
   int j = 20;
   cout << "Max(i, j): " << Max(i, j) << endl;

   double f1 = 13.5;
   double f2 = 20.7;
   cout << "Max(f1, f2): " << Max(f1, f2) << endl;

   string s1 = "Hello";
   string s2 = "World";
   cout << "Max(s1, s2): " << Max(s1, s2) << endl;

   // What will happen?
   int A[] = {1,2};
   int B[] = {3,4,5};
    //cout << "Max(A, B): " << Max(A,B) << endl;

   date today = {2023, 4, 14};
   date finalExam = {2023, 5, 11};
   date max = Max(today,finalExam);
   date min = Min(today,finalExam);
   cout << "Max(today, finalExam): " << max.month << "/" << max.day << "/" << max.year << " " << endl;
   cout << "Min(today, finalExam): " << min.month << "/" << min.day << "/" << min.year << " " << endl;


   auto intVector = new countedVector<int>();
   intVector->add(1);
   intVector->add(2);
   intVector->add(3);
   intVector->add(10);
   cout << intVector->get(2) << endl;
   cout << intVector->get(3) << endl;
   cout << intVector->get(2) << endl;
   cout << intVector->getCounter(2) << endl;
   cout << intVector->getCounter(3) << endl;
   intVector->toString();

   return 0;
}

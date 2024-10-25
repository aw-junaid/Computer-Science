#include <iostream>
using namespace std;

int main() {
   int decimalValue;
   string romanValue = "";

   cout << "Enter a decimal value between 1 and 3999: ";
   cin >> decimalValue;

   if(decimalValue < 1 || decimalValue > 3999) {
      cout << "Invalid input!";
      return 0;
   }

   while(decimalValue >= 1000) {
      romanValue += "M";
      decimalValue -= 1000;
   }

   if(decimalValue >= 900) {
      romanValue += "CM";
      decimalValue -= 900;
   }

   while(decimalValue >= 500) {
      romanValue += "D";
      decimalValue -= 500;
   }

   if(decimalValue >= 400) {
      romanValue += "CD";
      decimalValue -= 400;
   }

   while(decimalValue >= 100) {
      romanValue += "C";
      decimalValue -= 100;
   }

   if(decimalValue >= 90) {
      romanValue += "XC";
      decimalValue -= 90;
   }

   while(decimalValue >= 50) {
      romanValue += "L";
      decimalValue -= 50;
   }

   if(decimalValue >= 40) {
      romanValue += "XL";
      decimalValue -= 40;
   }

   while(decimalValue >= 10) {
      romanValue += "X";
      decimalValue -= 10;
   }

   if(decimalValue >= 9) {
      romanValue += "IX";
      decimalValue -= 9;
   }

   while(decimalValue >= 5) {
      romanValue += "V";
      decimalValue -= 5;
   }

   if(decimalValue >= 4) {
      romanValue += "IV";
      decimalValue -= 4;
   }

   while(decimalValue >= 1) {
      romanValue += "I";
      decimalValue -= 1;
   }

   cout << "Roman numeral equivalent: " << romanValue;

   return 0;
}

#include<iostream>
using namespace std;

class SwapNumbers {
   private:
      int a, b;
   public:
      void input() {
         cout << "Enter two numbers to be swapped:" << endl;
         cin >> a >> b;
      }
      void swap() {
         int temp = a;
         a = b;
         b = temp;
      }
      void display() {
         cout << "After swapping, the numbers are: " << endl;
         cout << "a = " << a << endl;
         cout << "b = " << b << endl;
      }
};

int main() {
   SwapNumbers obj;
   obj.input();
   obj.swap();
   obj.display();
   return 0;
}

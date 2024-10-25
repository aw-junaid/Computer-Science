#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
   initwindow(640, 480, "Upper Half of Bitmap");

   // Load the bitmap
   readimagefile("bitmap.bmp", 0, 0, 40, 40);

   // Display only the upper half of the bitmap
   setviewport(0, 0, 40, 20, 1);
   clearviewport();
   readimagefile("bitmap.bmp", 0, 0, 40, 20);

   getch();
   closegraph();
   return 0;
}

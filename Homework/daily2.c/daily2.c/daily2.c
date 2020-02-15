/*
 Author: Sam Pickell
 Date: 9/6/15
 
 Output: " This program has the executable name: /Users/narukami41/Library/Developer/Xcode/DerivedData/daily2.c-bfhgbeiwtesmwcbzjdpudhqgnqak/Build/Products/Debug/daily2.c
 That is all!
 Program ended with exit code: 0  "
 
 This is what appeared in the output window when I ran the program. The program outputs its name and file path, followed by "That is all!" and "Program ended with exit code: 0"
 
 
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("This program has the executable name: %s\n ", argv[0]);
    printf("That is all!\n");
    return 0;
}
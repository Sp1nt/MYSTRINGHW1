#include <iostream>
#include "MyString.h"

using namespace std;

int MyString::AmountOBJ = 0;
int main() {

    MyString firstString("Hello, ");
    MyString secondString("my friend!");

    //firstString.Input(); //if you want
    cout << "First string: ";
    firstString.Print();
    cout << endl;

    cout << "First string length: " << firstString.MyStrLen() << endl;
    cout << endl << endl;

    //secondString.Input(); //if you want
    cout << "Second string: ";
    secondString.Print();
    cout << endl;

    cout << "Second string length: " << secondString.MyStrLen() << endl;

    /*cout << "Copying the first line to the second..." << endl;
    secondString.MyStrcpy(firstString);

    cout << "Second line after copying: ";
    secondString.Print();
    cout << endl;*/
    cout << endl << endl;

    cout << "Concatenating strings..." << endl;
    firstString.MyStrCat(secondString);

    cout << "String after concatenation: ";
    firstString.Print();
    cout << endl;

    cout << endl << endl;

    cout << "Search for a substring 'my' in string: ";
    if (firstString.MyStrStr("my"))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    cout << endl << endl;

    cout << "Search for a symbol 'i' in string: ";
    int position = firstString.MyChr('i');
    if (position != -1)
        cout << "Symbol found at position " << position << endl;
    else
        cout << "Symbol not found" << endl;

    cout << endl << endl;

    cout << "Deleting a symbol 'y' from the string......" << endl;
    firstString.MyDelChr('y');

    cout << "String after deleting: ";
    firstString.Print();
    cout << endl;

    cout << endl << endl;

    cout << "String comparison: ";
    int comparisonResult = firstString.MyStrCmp(secondString);
    if (comparisonResult == -1)
        cout << "firstString < secondString" << endl;
    else if (comparisonResult == 1)
        cout << "firstString > secondString" << endl;
    else
        cout << "firstString == secondString" << endl;

    cout << endl << endl;
    cout << endl << endl;



}

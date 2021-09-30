// part1.cpp
// ENSF 614 Fall 2021 lab 3 Exercise D
//


#include <iostream>
using namespace std;

#include <assert.h>
#include <string.h>
#include "DynString.h"

void doSomething(DynString& s1, const DynString& s2);


int main()
{
    DynString a("abcd");
    DynString *b;
    
    // NOTE: The fact that the following code is within an extra pair of
    // braces. Means that scope of the varibles declared between barces ends
    // when  once program reaches the closing barce.
    {
        b = new DynString("film");
        cout << "BEFORE: " << b->c_str() << endl;
        doSomething(*b, *b);
        cout << "AFTER:  " << b->c_str() << endl;
        
        // The following line is trying to make object c a copy of object a.
        // Notice: this is a bad-copy and can cause serious issues
        DynString c = a;
        // point 3
    }
    cout << "If you gadas faef asdf  or." << endl;
    
    delete b;   // think this is causing the error? shouldn't be using delete on b since it's a ptr? 
    // point 4
    
    cout << "If you press return your program may give an error." << endl;
    cout << "In your lab report discuss what is wrong with this program.";
    cin.get(); // waiting for user to press return.
    
    return 0;
}

void doSomething(DynString& s1, const DynString& s2)
{
    char ch = s2.get_element(2);
    ch++;  // go to next letter in alphabet
    ch = ch - 32;  // make upercase
    s1.set_element(0, ch);  // assign it to beginning letter
}


DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
    // Point 1
}

DynString::~DynString()
{
    delete [] storageM;
    // Point 2 
}

int DynString::length() const
{
    return lengthM;
}

char DynString::get_element(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

void DynString::set_element(int pos, char value)
{
    assert(pos >= 0 && pos < length());
    storageM[pos] = value;
}

const char * DynString::c_str() const
{
    return storageM;
}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    
}

// part2.cpp
// ENSF 614 Fall 2021 Lab 3 Exercise D



#include <iostream>
using namespace std;

#include "DynString.h"
#include <assert.h>
#include <string.h>

int main()
{
    DynString x("foot");
    DynString y;
    DynString z("ball");
    
    x.truncate(3);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foo\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 3).\n" << endl;
    
    x.truncate(0);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 0).\n" << endl;
#if 1
    x.append("foot");
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foot\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 4).\n" << endl;
    x.append(y);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"foot\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 4).\n" << endl;
    x.append(z);
    cout << "Contents of x: \"" << x.c_str() << "\" (expected \"football\")." << endl;
    cout << "Length of x: " << x.length() << " (expected 8).\n" << endl;;
#endif
    
  return 0;
}

void DynString::append(const DynString& tail){
  int new_length = lengthM + tail.lengthM;  // find new length
  char * holder;  // char array to hold our new string
  holder = new char[new_length];  // add 1 to length to account for '\0'
  strcpy(holder, storageM);  // copy starageM contents into holder first

  // copy contents of tail into holder
  for (int i = 0; i < tail.lengthM; i++) {
    holder[i+lengthM] = tail.storageM[i];
  }

  holder[new_length] = '\0';
  storageM = holder;
  lengthM = new_length;
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


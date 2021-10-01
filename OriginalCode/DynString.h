// DynString.h
// ENSF 614 Fall 2021 lab 3 exercise D


#ifndef DYNSTRING_H
#define DYNSTRING_H

// WARNING
//   The DynString class has a major defect.  If you try to
//   copy a DynString object, bad things will happen.

class DynString {
public:
    DynString();
    // PROMISES: Empty string object is created.
    
    DynString(const char *s);
    // PROMISES: s points to first char of a built-in string.
    // REQUIRES: String object is created by copying chars from s.
    
    ~DynString();
    
    int length() const;
    // PROMISES: Return value is number of chars in string.
    
    char get_element(int pos)const;
    // REQUIRES: pos >= 0 && pos < length()
    // PROMISES:
    //   Return value is char at position pos.
    //   (The first char in the string is at position 0.)
    void set_element(int pos, char val);
    // REQUIRES: pos >= 0 && pos < length()
    // PROMISES:
    //   assigns val to the storageM[pos]
    //   (The first char in the string is at position 0.)
    
    const char * c_str() const;
    // PROMISES:
    //   Return value points to first char in built-in string
    //   containing the chars of the string object.
    
    void append(const DynString& tail);
    // PROMISES: chars are copied from tail to the end of the
    //     string object.
    
    void truncate(int new_length);
    // REQUIRES: new_length >= 0 && new_length <= length()
    // PROMISES:
    //   Length of string is reduced to new_length.
    
private:
    int lengthM;
    char *storageM;
};

#endif

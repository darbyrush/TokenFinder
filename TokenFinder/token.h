//
//  token.h
//  homework3
//
//  Created by Darby Rush on 10/7/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#ifndef token_h
#define token_h
#include <string>
#include <iostream>
using namespace std;

 enum Token_type {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};
class Token{
public:
    
    Token_type type;
    string token;
    int priority;
    
    Token();
    Token(string s);
    void set(string s);
    int value() const;
    void display() const;
    
    Token_type get_type() const;
    string get_token() const;
    int get_priority() const;
};

#endif /* token_h */

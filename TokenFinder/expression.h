//
//  expression.h
//  homework3
//
//  Created by Darby Rush on 10/7/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#ifndef expression_h
#define expression_h
#include <string>
#include <iostream>
#include "token.h"
#include <vector>
using namespace std;

enum Exp_type {ASSIGNMENT, ARITHMETIC, ILLEGAL};

class expression{
public:
   
    string original;
    vector<Token> tokenized;
    vector<Token> postfix;
    bool valid;
    Exp_type type;
    
    expression();
    expression(const string& s);
    //
    void set(const string& s);
    void display() const;
    //getter for memeber
    string get_original() const;
    //Getter for tokenized member.
    vector<Token> get_tokenized() const;
    
    
};
#endif /* expression_h */

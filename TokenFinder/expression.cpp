//
//  expression.cpp
//  homework3
//
//  Created by Darby Rush on 10/7/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "expression.h"
#include "token.h"
#include <vector>
using namespace std;

expression::expression(){
    original = "";
    tokenized.clear();
    postfix.clear();
    valid = false;
    type = ILLEGAL;
}

expression::expression(const string& s){
    set(s);
}


void expression::set(const string& s){
    original = s;
    
    //tokenizing
    tokenized.clear();
    int len = original.length();
    bool isToken = false;
    char c;
    int start=0;
    Token next;
   
   
    for(int i = 0; i < len; i++){
        c = original.at(i);
        
        if( c != ' '){
            if(c== '+' || c== '-' || c =='*'|| c=='/' ||c=='(' || c==')'){
                if(isToken){
                    next.set(original.substr(start, i-start));
                    tokenized.push_back(next);
                    isToken = false;
                    }
                //for special token
                string s(1,c);
                next.set(s);
                tokenized.push_back(next);
                isToken = false;
                //if the char is not an operator and is not a token.
                //Need to record beginning of the token and mark that there is a token
                //if there is currently a token, continue to the loop
                }else if(!isToken){
                isToken = true;
                start = i;
            }
        }else if(isToken){
            next.set(original.substr(start, i-start));
            tokenized.push_back(next);
            isToken = false;
        }
    }
    
    if(isToken){
        next.set(original.substr(start, len-start));
        tokenized.push_back(next);
        isToken = false;
    }
    postfix.clear();
    valid = false;
    type = ILLEGAL;
}

void expression::display() const{
    cout << "Original: " << get_original()<< endl;
    cout << "tokenized = ";
    for(unsigned i = 0; i < tokenized.size(); i++){
        cout << tokenized.at(i).get_token() <<";";
    }
    cout << endl;
    cout << "Number of Tokens = " << tokenized.size() << endl;
    cout << "postfix: empty" << endl;
    cout << "valid: false " << endl;
    cout << "type: ILLEGAL" << endl;
}

string expression::get_original() const{
    return original;
}

vector<Token> expression::get_tokenized() const{
    return tokenized;
}



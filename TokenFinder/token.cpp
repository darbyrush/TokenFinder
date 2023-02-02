//
//  token.cpp
//  homework3
//
//  Created by Darby Rush on 10/7/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <iostream>
#include "token.h"
#include <vector>
using namespace std;

//default const
Token::Token(){
    type = INVALID;
    token = "";
    priority = -1;
}
//copy
Token:: Token(string s){
    set(s);
}

void Token::set(string s){
    token = s;
    priority = -1;
    //operator
    for (int z = 0; z < s.length(); z++) {                  //to check if '?' is in string => INVALID
        if (s[z] == '?') {
            type = INVALID;
        }
    }

    if (s == "+" || s == "-" || s == "*" || s == "/") {    //Determining types of strings based on their types
        type = OP;
    } else if (s == "=") {
        type = EQ;
    }
     else if (s == "(") {
        type = OpenBrace;
    } else if (s == ")") {
        type = CloseBrace;
    } else if (isalpha(s[0])) {                            //continue on the checking process for type = ID if zero place is an alphabet
        int i;
        for (i = 1; i < s.length(); i++) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {        //if the elements come after the zero place element is neither an alphabet nor a number type => INVALID
                break;
            }
        }
        if (i == s.length()) {                             //finish checking the whole string and the type => ID
                type = ID;
        }
    } else if (isdigit(s[0])) {                            //continue on the checking process for type = INT if zero place is an number
        int j;
        for (j = 1; j < s.length(); j++) {
            if (!isdigit(s[j])) {                          //if the elements come after the zero place element is not a number type => INVALID
                type = INVALID;
                break;
            } else if (s[0] == '0' && s[j] != '0') {       //this step is to check the special case for 0
                type = INVALID;
                break;
            }
        }
        if (j == s.length()) {                             //finish checking the whole string and the type => INT
            type = INT;
        }
    } else {
        type = INVALID;                                    //the rest are type INVALID
    }
    
}
int Token::value() const{
    int temp = 0;
    if(type == ID)
        {
            temp = stoi(token);
            return temp;
        }
        if(type == INT)
        {
            int li1;
            li1 = stoi (token,nullptr,10);
            return li1;
        }
        else{
            return -2;
        }

    }
 

void Token::display() const{
  string output;                                         //output variable
  switch (type) {                                        //reason for using switch-statement: if there was no switch-statement, the output of type will only shows the indices of the types in enum.
      case ID:
          output = "ID";
          break;
      case INT:
          output = "INT";
          break;
      case OP:
          output = "OP";
          break;
      case EQ:
          output = "EQ";
          break;
      case OpenBrace:
          output = "OpenBrace";
          break;
      case CloseBrace:
          output = "CloseBrace";
          break;
      case INVALID:
          output = "INVALID";
          break;
      default:
          cout << "None Type" << endl;

  }

  cout << endl;
  cout << "type = " << output << endl;               //outputs
  cout << "token = " << token << endl;
  cout << "Priority = " << priority << endl;
}

Token_type Token::get_type() const{
    return type;
}

string Token::get_token() const{
    return token;
}

int Token::get_priority() const{
    return priority;
}

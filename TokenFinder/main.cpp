//
//  main.cpp
//  homework3
//
//  Created by Darby Rush on 10/4/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <iostream>
#include "token.h"
#include "expression.h"
using namespace std;

int main()
{
    cout << "______________________________________________________________________" << endl
         << "_____________________________Token Testing____________________________" << endl
         << "______________________________________________________________________" << endl << endl;
    //Total 9 test cases, 5pts each
    // Testing Token default constructor
    cout << "Test 1: Testing Token default constructor" << endl;
    Token test1;
    test1.display();
    cout << endl;

    // Testing Token constructor
    cout << "Test 2: Testing Token constructor" << endl;
    Token test2("test");
    test2.display();
    cout << endl;

    // Testing copy constructor
    cout << "Test 3: Testing copy constructor" << endl;
    test1 = test2;
    test1.display();
    cout << endl;

    // Testing Token set member
    cout << "Test 4: Testing Token set member" << endl;
    Token test3;
    test3.set("test");
    test3.display();
    cout << endl;

    Token Ttest;
    int num = 5;
    string t[] = {"123", "+", "1a2", "0", "A"};
    for(int i = 0; i < num; i++)
    {
        cout << "Test " << i + 5 << ":" << endl;
        Ttest.set(t[i]);
        Ttest.display();
        cout << endl;
    }

    cout << "______________________________________________________________________" << endl
         << "__________________________Expression Testing__________________________" << endl
         << "______________________________________________________________________" << endl << endl;
    // Total 7 test cases, 5 pts each
    // Testing Expression default constructor
    cout << "Test 1: Testing Expression default constructor" << endl;
    expression test4;
    test4.display();
    cout << endl;

    // Testing Expression constructor
    cout << "Test 2: Testing Expression constructor" << endl;
    expression test5("test");
    test5.display();
    cout << endl;

    // Testing the Expression copy constructor
    cout << "Test 3: Testing the Expression copy constructor" << endl;
    test4 = test5;
    test4.display();
    cout << endl;

    // Testing Expression set member
    cout << "Test 4: Testing Expression set member" << endl;
    expression test6;
    test6.set("test test");
    test6.display();
    cout << endl;

    expression Etest;
    num = 3;
    string e[] = {"a * ( ab + 12 ) / 2ab4 - 32", "a12 = 1?ab  +  - a 0123 c (a + 12 3 )*(ab - (3 + 4   ))", "==)(abc123)12ab(  "};
    for(int i = 0; i < num; i++)
    {
        cout << "Test " << i + 5 << ":" << endl;
        Etest.set(e[i]);
        Etest.display();
        cout << endl;
    }

    return 0;
}

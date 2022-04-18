/*
 * work_with_templates.h
 *
 *  Created on: Apr 13, 2022
 *      Author: SEkoSh
 */

#ifndef WORK_WITH_TEMPLATES_H_
#define WORK_WITH_TEMPLATES_H_
#include <iostream>

struct Data
{
    Data()
    {
    }

    ~Data()
    {
    }

    int a;
    int b;
};

void func()
{
    Data x, y;

    //     Some code

    throw Exc();

    // -------------

    Data z;
}

bool cmpFunc(char* c)
{
    std::stack<char> strArray;

    //char array [] = "({[sd]})";
    for (int i=0; i<strlen(array); ++i)
    {
       switch(*c)
        {
        case '(':
        case '{':
        case '[':
            strArray.push(array[i]);
            break;
        case ')':
        case '}':
        case ']':
            if((array[i] == ')' && (strArray.top()!= '(')) ||
                (array[i] == '}' && (strArray.top()!= '{')) ||
                (array[i] == ']' && (strArray.top()!= '[')) )
            {
                return False;
            }
            strArray.pop();
            break;
    }
    return strArray.empty() ? True : False;
}



#endif /* WORK_WITH_TEMPLATES_H_ */

//first the expression is converted to a postfix expression from the default infix expression that humans understand
//then the postfix exression is evaluated to yield either a number or "INVALID"

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
bool isnumber(char num)
{   //the isdigit() seems to misbehave thats why xD
    switch (num)
    {
    case '0':
        return true;
        break;
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        return true;
        break;
    case '5':
        return true;
        break;
    case '6':
        return true;
        break;
    case '7':
        return true;
        break;
    case '8':
        return true;
        break;
    case '9':
        return true;
        break;
    default:
        return false;
        break;
    }
}
/* vector<char> */ void infix_to_postfix(vector<char>infix)
{
    vector<char> stack {'('};
    vector<char> postfix {' '};
    infix.push_back(')');
    infix.push_back(' ');
    
    for(auto element = infix.begin(); element != infix.end(); element++ )
    {
        auto elem = *element ;
        if(isnumber(elem)) {postfix.push_back(elem);}
        else if((elem)=='(') {stack.push_back('(');}
        else if((elem)==')') 
        {
            while(*(stack.end()) != '(')
            {
                postfix.push_back(*(stack.end()));
                stack.pop_back();
            }
            stack.pop_back();
        }
        else
        {
            switch(elem)
            {
                case '/': 
                    
                    stack.push_back('/');
                    break;

                case '*':
                    
                    stack.push_back('*');
                    break;

                case '+':
                    while(*(stack.end()) == '/'|| *(stack.end()) == '*') 
                    {
                        postfix.push_back(*(stack.end()));
                        stack.pop_back();
                    }
                    stack.push_back('+');
                    break;

                case '-':
                    while(*(stack.end()) == '/'|| *(stack.end()) == '*') 
                    {
                        postfix.push_back(*(stack.end()));
                        stack.pop_back();
                    }
                    stack.push_back('-');
                    break;
            }
        }
    }
    for(auto element = postfix.begin(); element != postfix.end(); element++)
    {
        cout<<*element;
    }
    cout<<endl<<postfix.size();
    
    
    //return postfix;
}

// int evaluate_postfix(vector<char> postfix)
// {
//     vector<int> stack {};
//     postfix.push_back(' ');

//     for (auto element {postfix.begin()}; element != postfix.end(); )
//     {
//         if (*element % 2 == 0)
//         {
//             element = postfix.erase(element);
//         }
//         else
//         {
//             ++element;
//         }
//     }
        
//     }
// }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<char> haha  {'1','*','9','+','(','7','-','(','6','/','2','+','8',')','*','3',')','-','1'}; 
    //vector<char> hehe = 
    infix_to_postfix(haha);
    // for(auto element = hehe.begin(); element != hehe.end(); element++)
    // {
    //     cout<<*element;
    // } 
    return 0;
}

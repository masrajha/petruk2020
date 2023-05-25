/**
    evaluate-expr.cpp
    Purpose: Evaluate and convert expression string to infix form expression.
    @author Didik Kurniawan
    @version 0.1 5/12/2018
    compile using c++11. ex: g++ -std=c++11 evaluate-expr.cpp
*/
#include <iostream>
#include <string>
#include <algorithm> // std::find
#include <vector>    // std::vector
#include <string.h>
#include <stack>
#include <sstream>

using namespace std;
/**
    checking is a character is within in a string
    @param array character
    @param length array
    @param character
    @return true if a character within an array
    test URL old version: http://cpp.sh/8qz2g
*/
bool in_array(char mychar[], int n, char x)
{
    char *p;
    p = std::find(mychar, mychar + n, x);
    if (p != mychar + n)
        return true;
    else
        return false;
}
/**
    checking is a string is a number
    @param array character as string
    @return true if string is number
*/
bool is_number(string str)
{
    char *legal_str = new char[str.length() + 1];
    char *e;
    strcpy(legal_str, str.c_str());
    strtod(legal_str, &e);
    return (*e == '\0');
}
/**
    convert string epression to infix form expression
    @param string expression
    @return string vector each operator and operand 
    ex input: -200(14-76)+((27-122)2*-19/55-2229)9
    vector output print by space in between:
    -200 * ( 14 - 76 ) + ( ( 27 - 122 ) * 2 * -19 / 55 - 2229 ) * 9
*/
vector<string> exprtoinfix(string expr)
{
    char operand[] = "0123456789.";
    char operat[] = "+/*\%";
    char minus = '-';
    char kurung[] = "()";
    int parenthesis = 0;
    string legal{""};
    legal.append("0123456789.");
    legal.append("+/*\%");
    legal.append("-() ");
    // puts(legal.c_str());
    char *legal_str = new char[legal.length() + 1];
    strcpy(legal_str, legal.c_str());
    string buff{""};
    vector<string> infix;
    bool first = true;
    for (auto n : expr)
    {
        if (n == ' ')
            continue;
        if (first)
        {

            if (n == '+')
                continue;
            first = false;
            if (in_array(operat, strlen(operat), n))
            {
                cerr << "Error: First character of expression is operator " << n;
                exit(-1);
            }
        }
        if (!in_array(legal_str, strlen(legal_str), n))
        {
            cerr << "Error expression in " << n;
            exit(-1);
        }

        if (n == minus)
        {
            if (buff == "")
            {
                // if (!infix.empty() && infix.back() == ")")
                if (infix.empty())
                {
                    buff += n;
                }
                else if (infix.back() == ")")
                {
                    string opr{""};
                    opr += n;
                    infix.push_back(opr);
                }
                else
                {
                    //buff += n;
                    infix.push_back("-1");
                    infix.push_back("*");
                }
            }
            else
            {
                infix.push_back(buff);
                buff = "";
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }
        }
        else if (in_array(kurung, strlen(kurung), n))
        {
            
            if (buff == "")
            {
                
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }
            else
            {
                infix.push_back(buff);
                if (n == '(' && is_number(buff))
                    infix.push_back("*");
                if (n == '(' && infix.back()=="-"){
                    infix.pop_back();
                    infix.push_back("-1");
                    infix.push_back("*");    
                }
                buff = "";
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }
            parenthesis += (n == '(' ? 1 : -1);
            if (parenthesis < 0)
            {
                cerr << "Error expression in " << n;
                exit(-1);
            }
        }

        else if (in_array(operand, strlen(operand), n))
        {
            if (!infix.empty())
                if (buff == "" && infix.back() == ")")
                    infix.push_back("*");

            buff += n;
        }
        else if (in_array(operat, strlen(operat), n) && buff != "")
        {
            infix.push_back(buff);
            buff = "";
            string opr{""};
            opr += n;
            infix.push_back(opr);
        }
        else if (in_array(operat, strlen(operat), n) && buff == "" && infix.back() == ")")
        {
            string opr{""};
            opr += n;
            infix.push_back(opr);
        }
    }
    if (buff != "")
        infix.push_back(buff);
    if (!is_number(infix.back()) && infix.back() != ")")
    {
        cerr << "Error: Last expression must be operand or )";
        exit(-1);
    }
    if (parenthesis > 0)
    {
        cerr << "Error: add right parenthesis ')' in your expression";
        exit(-1);
    }
    return infix;
}
/**
    return precedent level of operator
    @param character operator
    @return precedence level
    ex. input: *
    output: 2

*/
int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '\%':
        return 3;
    default:
        return -1;
    }
}
/**
    convert infix to postfix form expression
    @param vector <string> infix expression
    @return vector <string> postfix each operator and operand 
    input vector like:
    -200 * ( 14 - 76 ) + ( ( 27 - 122 ) * 2 * -19 / 55 - 2229 ) * 9
    output vector:
    -200 14 76 - * 27 122 - 2 * -19 * 55 / 2229 - 9 * +
*/
vector<string> in_to_postfix(vector<string> infix)
{
    vector<string> postfix;
    stack<string> mystack;
    char opr[] = "+-*/\%";
    for (auto n : infix)
    {
        if (is_number(n))
        {
            postfix.push_back(n);
        }
        else if (n == "(")
        {
            mystack.push(n);
        }
        else if (n == ")")
        {
            while (!mystack.empty() && mystack.top() != "(")
            {
                postfix.push_back(mystack.top());
                mystack.pop();
            }
            if (mystack.top() == "(")
                mystack.pop();
        }
        else if (in_array(opr, strlen(opr), n.at(0)))
        {
            if (mystack.empty() || mystack.top() == "(")
            {
                mystack.push(n);
            }
            else
            {
                /*
                while the stack is not empty AND the top of the stack 
                is not a left parenthesis AND precedence of the                  
                operator <= precedence of the top of the stack
                */
                while (!mystack.empty() && mystack.top() != "(" && precedence(n.at(0)) <= precedence(mystack.top().at(0)))
                {
                    postfix.push_back(mystack.top());
                    mystack.pop();
                }
                /* push the latest operator to stack */
                mystack.push(n);
            }
        }
    }
    while (!mystack.empty())
    {
        postfix.push_back(mystack.top());
        mystack.pop();
    }
    return postfix;
}
double calc(double num1, double num2, char opr)
{
    switch (opr)
    {
    case '+':
        return (num1 + num2);
    case '-':
        return (num1 - num2);
    case '*':
        return (num1 * num2);
    case '/':
        return (num1 / num2);
    case '\%':
        if (num1 != static_cast<int>(num1) || num2 != static_cast<int>(num2))
            cout << "Warning operator using \% both operands convert to integer first\n";
        return ((int)num1 % (int)num2);
    }
    return 0;
}
template <typename T>
string to_string(T value)
{
    ostringstream oss;

    oss << value;
    return oss.str();
}
double evaluate(string expr)
{
    vector<string> postfix = in_to_postfix(exprtoinfix(expr));
    stack<string> mystack;
    char opr[] = "+-*/\%";
    char *e;
    for (auto n : postfix)
    {
        if (is_number(n))
        {
            mystack.push(n);
        }
        else if (in_array(opr, strlen(opr), n.at(0)))
        {

            double a = strtod(mystack.top().c_str(), &e);
            mystack.pop();
            double b = strtod(mystack.top().c_str(), &e);
            mystack.pop();
            mystack.push(to_string(calc(b, a, n.at(0))));
        }
    }

    return strtod(mystack.top().c_str(), &e);
}
void print(std::vector <string> const &a) {
   std::cout << "Print : ";
   
   for(unsigned int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
}

int main()
{
    string expr;
    vector<string> infix, postfix;
    // while (expr != "exit")
    // {
    //     cout << ">> ";
        getline(cin, expr);

        infix = exprtoinfix(expr);
        // print(infix);
        postfix = in_to_postfix(infix);
        // print(postfix);
    //     // for (auto n : postfix)
    //     //     cout << n << " ";
    //     // // cout << is_number("2.");
    //     if (expr=="exit") break;
        // cout <<endl<<evaluate(expr)<<endl;
        cout <<evaluate(expr)<<endl;
    // }
    return 0;
}
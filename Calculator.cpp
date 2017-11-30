#include<stack>
#include<iostream>
#include<string>
using namespace std;
string inToPostfix()
{
    stack<char>s;
    char token;
    string str;
    cin >> token;
    while (token != '=')
    {
        if (token >= 'a'&&token <= 'z')
            cout << token << " ";
        else
            switch (token)
        {
            case ')':while (!s.empty() && s.top() !='(')
            {
                str.push_back(s.top());s.pop();
                //cout << s.top() << " "; s.pop();
            }
                     s.pop(); break;
            case'(':s.push(token); break;
            case'*':
            case'/':while (!s.empty() && s.top() != '+'&&s.top() != '-'&&s.top() != '(')
            {str.push_back(s.top()); s.pop();}
                    s.push(token); break;
            case'+':
            case'-':
                while (!s.empty() && s.top() != '(')
                {str.push_back(s.top()) ; s.pop();}
                s.push(token); break;
        default:s.push(token); break;

        }
        cin >> token;
    }
    while (!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }
    str.push_back('=');
    return str;
}
int evalPostFix(string token)
{
    stack<int> s;
    int a, b, result;
    int i = 0;
    while (token[i]!='=')
    {
        result = token[i] - '0';
        if (result >= 0 && result <= 9)
            s.push(result);
        else
            switch (token[i])
        {
            case '+':a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(a + b); break;
            case' - ':a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(a - b); break;
            case'*':a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(a * b); break;
            case'/':a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(a / b); break;
            case'^':a = s.top(); s.pop(); b = s.top(); s.pop(); s.push(a + b); break;
            default:cout << "OOOOO\n";
        }
        ++i;
    }
    return s.top();
}
int main()
{
    cout << evalPostFix(inToPostfix());
    return 0;
}

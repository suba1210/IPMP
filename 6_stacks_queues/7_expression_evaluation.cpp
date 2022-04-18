#include<bits/stdc++.h>
using namespace std;

int precedence(char x){
    if(x=='-'|| x=='+')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else
        return 0;
}

int operation(int val1, int val2, char symbol){
    switch(symbol){
        case '+' :
            return val1+val2;
        case '-' :
            return val1-val2;
        case '*' :
            return val1*val2;
        case '/' :
            return val1/val2;
    }
}

int evaluate(string expr){
    int i;

    stack<char> ops;
    stack<int> values;

    for(i=0;i<expr.length();i++){
        if(expr[i]==' ')
            continue;
        else if(expr[i]=='('){
            ops.push(expr[i]);
        }
        else if(isdigit(expr[i])){
            int val = 0;
            while(i<expr.length( ) && isdigit(expr[i])){
                val = (val*10) + (expr[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if(expr[i]==')'){
            while(!ops.empty() && ops.top()!='('){
                int val2 = values.top();
                values.pop(); // val2 first, then val1
                
                int val1 = values.top();
                values.pop();

                char symbol = ops.top();
                ops.pop();

                int value = operation(val1,val2,symbol);
                values.push(value);
            }
            if(!ops.empty())
               ops.pop();
        }
        else{
            while(!ops.empty() && precedence(ops.top())>=precedence(expr[i])){
                int val1 = values.top();
                values.pop();

                int val2 = values.top();
                values.pop();

                char symbol = ops.top();
                ops.pop();

                int value = operation(val1,val2,symbol);
                values.push(value);
            }
            ops.push(expr[i]);
        }
    }
    
    while(!ops.empty()){
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();

                char symbol = ops.top();
                ops.pop();

                int value = operation(val1,val2,symbol);
                values.push(value);
    }
    
    return values.top();
}

int main(){
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
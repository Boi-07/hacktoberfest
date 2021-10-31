#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c){
    if((c>=65 && c<=90)|| (c>=97 && c<=122) || (c>=48 && c<=57))
        return true;
    return false;
}
int prece(char c){
    if(c=='+'||c=='-')
        return 1;
    else if(c=='/'||c=='*')
        return 2;
    return 0;
}

string InfixToPostfix(string s){
    stack<char> st;
    string result="";

    for(int i=0;i<s.size();i++){
        char c=s[i];
        
        if(isOperand(c)){
            result += c;
        }
        
        else{
            while(!st.empty() && prece(s[i])<=prece(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}

int main(){

    string s="a+b*c-d/e";
    cout<<InfixToPostfix(s)<<endl;

    



    return 0;
}
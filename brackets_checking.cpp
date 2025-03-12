// Created by Lenovo on 4/8/2024.
#include <iostream>
#include <stack>
using namespace std;
int main (){
    /*brackets checking*/
    string k="1000";
    cin>>k;
    int i=0;
    stack<char>Stack;
    bool flag=true;
    while(i!=k.size()){
        if(k[i]=='(' || k[i]=='[' || k[i]=='{' || k[i]=='<')
            Stack.push(k[i]);
        else if (k[i]=='/' && i+1!=k.size() && k[i+1]=='*')
            Stack.push(k[i]);
        else if ((k[i]>='a' && k[i]<='z') || (k[i]>='A' && k[i]<='Z'))
            continue;
        else if ((k[i]==')' && Stack.top()=='(') || (k[i]==']' && Stack.top()=='[') ||(k[i]=='}' && Stack.top()=='{') ||(k[i]=='>' && Stack.top()=='<'))
            Stack.pop();
        else if (k[i]=='*' && i+1!=k.size() && k[i+1]=='/' && Stack.top()=='/')
            Stack.pop();
        else if ((k[i]==')' && Stack.top()!='(') || (k[i]==']' && Stack.top()!='[') ||(k[i]=='}' && Stack.top()!='{') ||(k[i]=='>' && Stack.top()!='<')){
            flag=false;
            break;
        }
        else if (k[i]=='*' && i+1!=k.size() && k[i+1]=='/' && Stack.top()!='/') {
            flag = false;
            break;
        }
        i++;
    }
    if(flag && Stack.empty())
        cout<<"no problem found\n";
    else{
        cout<<"check brackets\n problem in\n";
        while(!Stack.empty()){
            cout<<Stack.top()<<" ";
            Stack.pop();
        }
    }
    /*postfix*/
    k="10,2,8,*+,3,-";//23
    k="2,3,1*+,9,-"; //-4
    stack<int>Stacks;
    while(i < k.size())
    {
        if(k[i]=='*' || k[i]=='+' || k[i]=='-' || k[i]=='/' && !Stacks.empty())
        {
            int f = Stacks.top(),s;
            Stacks.pop();
            if(!Stacks.empty())
            {
                s = Stacks.top();
                Stacks.pop();//---------------
            }
            else
            {
                cout<<"no enough operand\n";
                break;
            }
            int result = 0;
            if(k[i] == '*')
                result = f * s;
            else if(k[i] == '+')
                result = f + s;
            else if (k[i] == '-')
                result = s - f;
            else if(k[i]=='/' && f!=0)
                result = s / f;
            else if(k[i]=='/' && f==0){
                cout<<"cant divide by 0\n";
                break;
            }
            else if(k[i]!= ','){
                cout<<"no valid operator\n";
                break;
            }
            Stacks.push(result);
        }
        else if (k[i] == ',') {
            i++;//----------
            continue;
        }
        else{
            if(k[i] >= '0' && k[i] <= '9'){
                string num;
                while(k[i]!=',' && i != k.size())
                {
                    num += k[i];
                    i++; //-----------
                }
                Stacks.push(stoi(num));
            }
        }
        i++;
    }
    if(Stacks.size()==1)
    {
        cout<<Stacks.top()<<endl;
        Stacks.pop();
    }
    else{
        cout<<"invalid answer\n";
    }
    return 0;
}

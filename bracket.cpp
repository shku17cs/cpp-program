/*Vivek has taught the question on printing all the valid balanced parentheses sequences given N pairs of parentheses in the webinar on recursion.

He wants to test his students, so, he asks them a similar related question. He asks them to print all the valid balanced bracket sequence given N pairs of parantheses () and M pairs of braces {}.

Can you solve this variation of his problem?

Remember a balanced parentheses has following properties:

For any type of bracket (parentheses/brace), the number of opening and closing brackets should be equal. The following are invalid: (){}} ({({})}
For any type of bracket, and any index of the string, the number of opening bracket before that index should be greater or equal to the number of closing brackets. The following are invalid: ()}{ ({}))(

For any two matching pairs of different types of brackets, it should not happen that one type of bracket has opening before the opening of other bracket but has closing after the second type of closing. This is invalid: {(}) but these are valid: {()} ({})
.*/
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void pp2(int op,int cp,int ob,int cb,int n,int m,int i,char s[])
{
    if(i==2*n+2*m)
    {
        string temp="";
        for(int j=0;j<i;j++)
        {
            temp+=s[j];
        }
        cout<<temp<<endl;
        return;
    }
    if(op>=cp)
    {
        
            if(op<n)
            {
                s[i]='(';
               pp2(op+1,cp,ob,cb,n,m,i+1,s); 
            }
         
 }
    
    if(ob>=cb)
    {
            if(ob<m)
            {
                s[i]='{';
                pp2(op,cp,ob+1,cb,n,m,i+1,s);
            }
}
    int var1=0,var2=0;
        int z=i-1;
        char c='v';
        for(int j=z;j>=0;j--)
        {
            if(s[j]=='(')
            {
                var1++;
            }
            if(s[j]==')')
            {
                var1--;
            }
            if(s[j]=='{')
            {
                var2++;
            }
            if(s[j]=='}')
            {
                var2--;
            }
            if(var1==1)
            {
                c=')';
                break;
            }
            if(var2==1)
            {
                c='}';
                break;
            }
        }
        if(c==')')
        {
            s[i]=')';
            pp2(op,cp+1,ob,cb,n,m,i+1,s);
        }
        if(c=='}')
        {
            s[i]='}';
            pp2(op,cp,ob,cb+1,n,m,i+1,s);
        }
         
    // when no of opening parenthesis equal to closing paarenthesis and same in case of clsing parentehsis
   /* if(op==cp || ob==cb)
    {
        if(op<n)
        {
            s[i]='(';
            pp2(op+1,cp,ob,cb,n,m,i+1,s);
        }
        if(ob<m)
        {
            s[i]='{';
            pp2(op,cp,ob+1,cb,n,m,i+1,s);
        }
        
    }*/
    
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    char s[(2*n+2*m)+1];
    pp2(0,0,0,0,n,m,0,s);
    return 0;
}


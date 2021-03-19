#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
// conversion of infix to postfix expression
string change(string v)
{
    stack<char> strp;
    long long int n=v.size();
    string postfix123="";
    for(int i=0;i<n;i++){
        if(v[i]=='('){
            strp.push(v[i]);
        }else if(v[i]=='#' || v[i]=='0' || v[i]=='1'){
            postfix123 += v[i];
        }else if(v[i]=='a' || v[i]=='A'){
            postfix123 += v[i];
        }else if(v[i]=='&' || v[i]=='|' || v[i]=='^'){
            strp.push(v[i]);
        }else if(v[i]==')'){
            postfix123 += strp.top();
            strp.pop();
            strp.pop();
        }
    }
    return postfix123;
}
// calculation of euclid algorithm
long long int gcdExtended(long long int a, long long int b, long long  int *x, long long int *y) 
{ 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long int x1, y1; 
    long long int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
long long int modInverse(long long int a,long long  int m=998244353)
{ 
    long long int x, y; 
    long long int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1;
    else
    { 
        long long int res = (x%m + m) % m; 
        return res;
    } 
}
long long int evaluatePostfixexp(string postfixexp,char av, char Av)
{
    stack<char> sk;
    long long int n=postfixexp.size();
    
    for(long long int i=0;i<n;i++){
        if(postfixexp[i]=='1' || postfixexp[i]=='0'){
            sk.push(postfixexp[i]);
        }else if(postfixexp[i]=='a'){
            sk.push(av);
        }else if(postfixexp[i]=='A'){
            sk.push(Av);
        }else if(postfixexp[i]=='&'){
            char op1=sk.top();
            sk.pop();
            char op2=sk.top();
            sk.pop();
            if(op1=='1' && op2=='1'){
                sk.push('1');
            }else{
                sk.push('0');
            }
        }else if(postfixexp[i]=='|'){
            char op1=sk.top();
            sk.pop();
            char op2=sk.top();
            sk.pop();
            if(op1=='1' || op2=='1'){
                sk.push('1');
            }else{
                sk.push('0');
            }
        }else if(postfixexp[i]=='^'){
            char op1=sk.top();
            sk.pop();
            char op2=sk.top();
            sk.pop();
            if(op1=='1' && op2=='0'){
                sk.push('1');
            }else if(op1=='0' && op2=='1'){
                sk.push('1');
            }else{
                sk.push('0');
            }
        }
    }
    char res=sk.top();
    if(res=='1')
	{
		return 1;
	}
    else return 0;
}

void solve(string postexp,long long int n,long long int ind,long long int& a,long long int& b,long long int&c,long long int& d,string s)
{
    if(ind==n) 
    {
        long long int res1 = evaluatePostfixexp(s,'0','1');
        long long int res2 = evaluatePostfixexp(s,'1','0');
        if(res1==1 && res2==1){
            b++;
        }else if(res1==0 && res2==0){
            a++;
        }else if(res1==0 && res2==1){
            c++;
        }else{
            d++;
        }
        return;
    }
    
    if(postexp[ind]=='#'){
        solve(postexp,n,ind+1,a,b,c,d,s+'1');
        solve(postexp,n,ind+1,a,b,c,d,s+'0');
        solve(postexp,n,ind+1,a,b,c,d,s+'a');
        solve(postexp,n,ind+1,a,b,c,d,s+'A');
    }
    else{
        solve(postexp,n,ind+1,a,b,c,d,s+postexp[ind]);
    }
    return;
}

int main()
{
   long long  int t;
    cin >> t;
   long long  int z=1;
    while(z<=t)
	{
        string infixexp;
        cin >> infixexp;
        string postexp = change(infixexp);
        long long int n=postexp.size();
        long long int a=0,b=0,c=0,d=0;
        solve(postexp,n,0,a,b,c,d,"");
        long long int exp=a+b+c+d;
        long long int m = modInverse(exp);
    	long long int aexp = (a*m)%mod;
	    long long int bexp = (b*m)%mod;
	    long long int cexp = (c*m)%mod;
	    long long int dexp = (d*m)%mod;
	    cout << aexp << " " << bexp << " "<< cexp << " " << dexp << endl;
	    z++;
	}
	cout<<"on shiv branch";
	cout<<"on shiv1 branch ";
    return 0;
}

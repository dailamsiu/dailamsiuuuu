#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
void gen(int pos)
{
    if(pos>n)
    {
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            return;
        }
        cout<<s<<'\n';
        return;
    }
    for(char i='A';i<='C';i++)
    {
        s.push_back(i);
        gen(pos+1);
        s.pop_back();
    }

}
main()
{
    cin>>n;
    s="";
    gen(1);

}

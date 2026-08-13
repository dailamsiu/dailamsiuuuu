#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
void gen(int pos)
{
    if(pos>n)
    {
        cout<<s<<'\n';
        return;
    }
    for(char i='0';i<='1';i++)
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

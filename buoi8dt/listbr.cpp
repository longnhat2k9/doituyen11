#include<bits/stdc++.h>
using namespace std;

int n, f[30];
stack<int>st;
vector<string>s;

void print()
{
    reverse(s.begin(), s.end());
    for(auto &x : s) cout << x << endl;
}

void exp()
{
    if(!st.empty()) return;
    string ngoac = "";
    for(int i = 1; i <= n; i++)
    {
        if(f[i] == 1) ngoac += "(";
        else ngoac += ")";
    }
    s.push_back(ngoac);
}

void cs(int j)
{
    for(int i = 0; i <= 1; i++)
    {
        if(!st.empty() && i == 0)
        {
            st.pop();
            f[j] = i;
            if(j < n) cs(j + 1);
            else exp();
            st.push(1);
        }
        else if(i == 1)
        {
            st.push(1);
            f[j] = i;
            if(j < n) cs(j + 1);
            else exp();
            st.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    st.push(1);
    memset(f, 0, sizeof(f));
    f[1] = 1;
    cin >> n;
    if(n % 2 == 1) return 0;
    cs(2);

    print();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIR;

struct PPP
{
    int a;
    int b;
    int c;
};

bool operator > (PPP cp1, PPP cp2)
{
    return cp1.b > cp2.b;
}

bool operator < (PPP cp1, PPP cp2)
{
    return cp1.a < cp2.a;
}

int main()
{
    priority_queue<PPP, vector<PPP>, greater<PPP>> q;
    // priority_queue<PPP, vector<PPP>, less<PPP>> q;
    PPP p1 = {1,4,7};
    PPP p2 = {3,6,5};
    PPP p3 = {2,7,6};
    q.push(p1);
    q.push(p2);
    q.push(p3);

    while(!q.empty())
    {
        PPP cur = q.top();
        q.pop();

        cout << cur.a << " " << cur.b << " " << cur.c << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
Observations:
any integer variable type seems to overflow, you have to use a string

Approach: Simulation
we can simulate the algorithm
*/
string div(string s) {
    const int n = s.length();
    string cur = "";
    int rem = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 && s[i] == '1') {
            rem = 10;
            continue;
        }

        int digit = s[i] - '0' + rem;

        int floor = digit / 2;
        cur.push_back(floor + '0');

        rem = (digit - floor * 2) * 10;
    }

    return cur;
}

string mult(string s) {
    const int n = s.length();
    string cur = "";
    int carry = 0;
    // multiply by 3
    for (int i = n - 1; i >= 0; i--) {
        int num = s[i] - '0';
        num *= 3;

        num += carry;

        carry = num / 10;
        int digit = num % 10;

        cur.push_back(digit + '0');
    }

    if (carry > 0) {
        cur.push_back(carry + '0');
    }

    // add one
    size_t i = 0;
    while (cur[i] == '9') {
        cur[i] = '0';
        i++;
    }
    if (i >= cur.length()) {
        cur.push_back('1');
    }
    else {
        cur[i] += 1;
    }

    reverse(cur.begin(), cur.end());
    return cur;
}

vector<string> weird_algorithm(string n) {
    vector<string> res;

    while (n.length() > 1 || n[0] != '1') {
        res.push_back(n);
        if (n.back() == '0' || n.back() == '2' || n.back() == '4' || n.back() == '6' || n.back() == '8') {
            n = div(n);
        }
        else {
            n = mult(n);
        }
    }
    res.push_back(n);
    return res;
}

int main() {
    string n;
    cin >> n;

    const vector<string> res = weird_algorithm(n);

    for (size_t i = 0; i < res.size() - 1; i++) {
        cout << res[i] << " ";
    }
    cout << res.back();

    return 0;
}
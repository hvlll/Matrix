#include <iostream>
using namespace std;

int m[100][100];
int c = 0;
int third(pair <int, int> a);
int sum = 0;

int sort(pair <int, int> a) {
    cout << sum << endl;
    if (c == 3) { return  third(a); }
    if (c > 3) {
        c -= 1;
        for (int i = 0; i < c + 1; i++) {
            if (i == 0) {
                int a1 = a.first + 1;
                int a2 = a.second + 1;
                sum += sort(make_pair(a1,a2));
            }
            if ((i != 0)&&(i != c)) {
                int y;
                int p;
                if (i % 2 == 0) { y = -1; }
                else { y = 1; }
                for (int j = a.first+1;  j <= c; j++) {
                    p = m[j][a.second + i];
                    for (int k = i; k >= a.second + 1; k--) {
                        m[j][k] = m[j][k-1];
                    }
                    m[j][a.second] = p;
                }
                int a1 = a.first + 1;
                int a2 = a.second + 1;
                sum += m[a.first][i] * y * sort(make_pair(a1,a2));
                for (int j = a.first; j <= c; j++) {
                    p = m[j][a.second];
                    for (int k = a.second; k <= i-1; k++) {
                        m[j][k] = m[j][k + 1];
                    }
                    m[j][a.second+i] = p;
                }
            }
            if (c == i) {
                int y;
                if (i % 2 == 0) { y = -1; }
                else { y = 1; }
                int a1 = a.first + 1;
                int a2 = a.second;
                sum += m[a.first][i] * y * sort(make_pair(a1, a2));
            }

        }
        return sum;
    }

}

int third(pair <int, int> a) {
    return (m[a.first][a.second] * m[a.first + 1][a.second + 1] * m[a.first + 2][a.second + 2] + m[a.first][a.second + 1] * m[a.first + 1][a.second + 2] * m[a.first + 2][a.second] + m[a.first + 1][a.second] * m[a.first + 2][a.second + 1] * m[a.first][a.second + 2]) - (m[a.first][a.second + 2] * m[a.first + 1][a.second + 1] * m[a.first + 2][a.second] + m[a.first][a.second] * m[a.first + 1][a.second + 2] * m[a.first + 2][a.second + 1] + m[a.first][a.second + 1] * m[a.first + 1][a.second] * m[a.first + 2][a.second + 2]);
}

int second(pair <int, int> a) {
    return m[a.first][a.second] * m[a.first + 1][a.second + 1] - m[a.first][a.second + 1] * m[a.first + 1][a.second];
}


int main()
{
    int n;
    cin >> n;
    c = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    if (n == 1) {
        cout << m[0][0] << endl;
        return 0;
    }
    if (n == 2) {
        cout << second(make_pair(0,0)) << endl;
        return 0;
    }
    if (n == 3) {
        cout << third(make_pair(0,0)) << endl;
    }else{
        cout << sort(make_pair(0,0)) << endl;
    }
    
    return 0;
}


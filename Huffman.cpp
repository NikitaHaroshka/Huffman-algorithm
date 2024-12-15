#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("huffman.in");
    ofstream fou("huffman.out");
    int n, k = 0;
    //cin >> n;
    fin >> n;
    vector<long long> A(n);
    queue<long long> q;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        //cin >> A[i];
        fin >> A[i];
    }

    for (int i = 0; i < n - 1; i++) {
        long long a = 0;
        if (k < n && (q.empty() || A[k] <= q.front())) {
            a += A[k];
            sum += A[k];
            k++;
        }
        else {
            a += q.front();
            sum += q.front();
            q.pop();
        }

        if (k < n && (q.empty() || A[k] <= q.front())) {
            a += A[k];
            sum += A[k];
            k++;
        }
        else {
            a += q.front();
            sum += q.front();
            q.pop();
        }

        q.push(a);
    }

    //cout << sum;
    fou << sum;
}

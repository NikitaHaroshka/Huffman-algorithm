#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
    ifstream fin("huffman.in");
    if (!fin) {
        cerr << "Err" << endl;
        return 1;
    }

    ofstream fou("huffman.in"); 
    if (!fou) {
        cerr << "Err" << endl;
        return 1;
    }
    deque<int> s;
    int n, sum = 0, j = 0;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        fin >> a;
        s.push_front(a);
    }
    j = n;
    while (j>1) {
        int sum1 = 0;
        sum1 += s.back();
        s.pop_back();
        sum1 += s.back();
        s.pop_back();
        s.push_back(sum1);
        sum += sum1;
        j--;
    }
    
    fou << sum;

}
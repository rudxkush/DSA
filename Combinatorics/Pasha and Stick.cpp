#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n%2 == 0) {
        int ans = ((n/2) - 1) / 2;
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

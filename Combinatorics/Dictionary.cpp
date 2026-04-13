#include <iostream>
#include <string>
using namespace std;

void solve(string word) {
    int offsetBlock = (word[0] - 'a')*25;
    int offset = (word[1] - 'a');
    if(word[1] > word[0]) offset--;
    int position = offsetBlock + offset + 1;
    cout << position << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string word;
        cin >> word;
        solve(word);
    }
    return 0;
}

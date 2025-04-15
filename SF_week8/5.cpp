#include <iostream>
#include <string>
using namespace std;

int main() {
    int K;
    string s;
    cin >> K >> s;
    string result;
    for (char c : s) {
        while (K > 0 && !result.empty() && result.back() > c) {
            result.pop_back();
            K--;
        }
        result += c;
    }
    // ����ʣ��δ�Ƴ�������
    if (K > 0) {
        result.erase(result.end() - K, result.end());
    }
    // ȥ��ǰ����
    size_t start = 0;
    while (start < result.size() - 1 && result[start] == '0') {
        start++;
    }
    result = result.substr(start);
    cout << (result.empty() ? "0" : result) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string multiplicar(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0) return "0";
    vector<int> resultado(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + resultado[i + j + 1];
            resultado[i + j + 1] = sum % 10;
            resultado[i + j] += sum / 10;
        }
    }
    string s = "";
    for (int num : resultado) {
        if (!(s.empty() && num == 0)) {
            s += to_string(num);
        }
    }
    return s.empty() ? "0" : s;
}
int main() {
    long long k;
    if (cin >> k) {
        long long mitad = (k + 1) / 2;
        string mitadStr = to_string(mitad);
        string respuesta = multiplicar(mitadStr, mitadStr);
        cout << respuesta << endl;
    }
    return 0;
}
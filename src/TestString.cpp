#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// Hàm chuẩn hóa cấp 1: loại bỏ dấu cách thừa
string chuanHoaCap1(const string& s) {
    stringstream ss(s);
    string word, result;
    while (ss >> word) {
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

// Hàm chuẩn hóa cấp 2: viết hoa chữ cái đầu mỗi từ
string chuanHoaCap2(const string& s) {
    stringstream ss(s);
    string word, result;
    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); ++i) word[i] = tolower(word[i]);
        }
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

// Hàm đảo ngược chuỗi
string daoNguocChuoi(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {

    string st = "   Xin   chAo   cac     BaN!   ";

    // getline(cin, st);

    int length = st.length();
    string st_c1 = chuanHoaCap1(st);
    int count_space = count(st_c1.begin(), st_c1.end(), ' ');
    string st_c2 = chuanHoaCap2(st_c1);
    string st_dao = daoNguocChuoi(st);
    
    cout << "1. So ky tu trong xau: " << length << endl;
    cout << "2. So tu trong xau: " << count_space + 1 << endl;
    cout << "3. Chuan hoa cap 1: \"" << st_c1 << "\"" << endl;
    cout << "4. Chuan hoa cap 2: \"" << st_c2 << "\"" << endl;
    cout << "5. Xau dao nguoc: \"" << st_dao << "\"" << endl;

    return 0;
}

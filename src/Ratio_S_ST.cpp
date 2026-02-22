#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string st, s;
    getline(cin, st);
    getline(cin, s);
    
    // Kiểm tra nếu chuỗi rỗng
    if (st.empty() || s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // normalize
    string st_alpha, s_alpha;
    for (char c : st) {
        if (isalpha(c)) {
            st_alpha += tolower(c);
        }
    }
    for (char c : s) {
        if (isalpha(c)) {
            s_alpha += tolower(c);
        }
    }
    
    vector<int> count_st(26, 0), count_s(26, 0);
    
    // Đếm tần suất trong st_alpha
    for (char c : st_alpha) {
        count_st[c - 'a']++;
    }
    
    // Đếm tần suất trong s_alpha
    for (char c : s_alpha) {
        count_s[c - 'a']++;
    }
    
    // Tính tỷ lệ 
    int min_ratio = INT_MAX;
    
    for (int i = 0; i < 26; i++) {
        if (count_s[i] > 0) {
            if (count_st[i] == 0) {
                cout << -1 << endl;
                return 0;
            }
            int ratio = count_st[i] / count_s[i];
            min_ratio = min(min_ratio, ratio);
        }
    }
        
    cout << min_ratio << endl;
    
    return 0;
}
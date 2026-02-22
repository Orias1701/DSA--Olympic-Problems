#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    // Số lượng từ
    int N;
    cin >> N;
    
    // Độ dài mỗi từ
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    
    // Đọc chuỗi
    string st;
    cin >> st;
    
    // Mảng lưu kết quả
    vector<string> words(N, "");
        
    // Lặp qua các vị trí ký tự (từ 1 đến max(Li))
    int LMax = *max_element(L.begin(), L.end());

    int pos = 0;
    for (int k = 1; k <= LMax; k++) {
        // Duyệt qua từng từ
        for (int i = 0; i < N; i++) {
            // Nếu từ thứ i có độ dài lớn hơn hoặc bằng k
            if (k <= L[i]) {
                words[i] += st[pos];
                pos++;
            }
        }
    }
    
    // In ra văn bản gốc
    for (int i = 0; i < N; i++) {
        cout << words[i];
        if (i < N - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
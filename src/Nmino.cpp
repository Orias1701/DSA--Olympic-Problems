#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int N;
set<string> canonical_shapes;  // Tập lưu các hình dạng chuẩn (sau khi normalize)

// Hàm chuẩn hóa hình: đưa về góc (0,0) và sort theo x rồi y
void normalize(vector<pair<int, int>> &shape) {
    int min_x = 1e9, min_y = 1e9;
    for (const auto &[x, y] : shape) {
        min_x = min(min_x, x);
        min_y = min(min_y, y);
    }
    for (auto &[x, y] : shape) {
        x -= min_x;
        y -= min_y;
    }
    sort(shape.begin(), shape.end());
}

// Hàm chuyển vector hình sang chuỗi để so sánh/lưu trữ
string serialize(const vector<pair<int, int>> &shape_input) {
    vector<pair<int, int>> shape = shape_input; // copy
    normalize(shape);
    string s;
    for (const auto &[x, y] : shape) {
        s += "(" + to_string(x) + "," + to_string(y) + ")";
    }
    s += ";";
    return s;
}

// Xoay 90 độ quanh gốc
vector<pair<int, int>> rotate90(const vector<pair<int, int>> &shape) {
    vector<pair<int, int>> new_shape;
    for (const auto &[x, y] : shape) {
        new_shape.emplace_back(-y, x);
    }
    return new_shape;
}

// Lật theo trục dọc (x)
vector<pair<int, int>> flipX(const vector<pair<int, int>> &shape) {
    vector<pair<int, int>> new_shape;
    for (const auto &[x, y] : shape) {
        new_shape.emplace_back(-x, y);
    }
    return new_shape;
}

// Lật theo trục ngang (y)
vector<pair<int, int>> flipY(const vector<pair<int, int>> &shape) {
    vector<pair<int, int>> new_shape;
    for (const auto &[x, y] : shape) {
        new_shape.emplace_back(x, -y);
    }
    return new_shape;
}

// Lấy dạng chuẩn (canonical) bằng cách sinh tất cả 8 biến thể và chọn chuỗi nhỏ nhất
string get_canonical(const vector<pair<int, int>> &shape) {
    vector<string> variants;

    vector<pair<int, int>> current = shape;
    for (int i = 0; i < 4; ++i) {
        current = rotate90(current);
        variants.push_back(serialize(current));
        variants.push_back(serialize(flipX(current)));
    }

    return *min_element(variants.begin(), variants.end());
}

// =================== HÀM SINH HÌNH ===================

void generate(vector<pair<int, int>> &shape, int size) {
    if (size == N) {
        string canon = get_canonical(shape);
        canonical_shapes.insert(canon);
        return;
    }

    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < shape.size(); ++i) {
        int x0 = shape[i].first;
        int y0 = shape[i].second;

        for (int d = 0; d < 4; ++d) {
            int nx = x0 + dx[d];
            int ny = y0 + dy[d];

            // Kiểm tra xem ô này đã có chưa
            bool exists = false;
            for (const auto &[x, y] : shape) {
                if (x == nx && y == ny) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                shape.emplace_back(nx, ny);
                generate(shape, size + 1);
                shape.pop_back();
            }
        }
    }
}

// ==================== HÀM MAIN ======================

int main() {
    cout << "Nhap so o vuong (1 - 9): ";
    cin >> N;

    if (N < 1 || N > 9) {
        cout << "Chi ho tro trong khoang 1 - 9." << endl;
        return 1;
    }

    vector<pair<int, int>> start_shape = {{0, 0}};
    generate(start_shape, 1);

    cout << "So luong N-Mino khac nhau: " << canonical_shapes.size() << endl;

    int count = 1;
    for (const string &s : canonical_shapes) {
        cout << "\n" << setw(5) << count++ << ": ";
        int x = 0, y = 0, i = 1;
        while (i < N * 5){
            if (s[i] != x + '0') {
                cout << "\n       ";
                x++;
                y=0;
            }
            while (s[i + 2] > y + '0') {
                    cout << "  ";
                    y++;
                }
                cout << " #";
                y++;
            i+=5;
        }
        cout << "\n";
    }
    return 0;
}





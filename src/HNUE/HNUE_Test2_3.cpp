#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int r, c;
};

// Hàm so sánh để sắp xếp các điểm theo dòng, sau đó theo cột
bool comparePoints(const Point& a, const Point& b) {
    if (a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    vector<Point> points(K);
    for (int i = 0; i < K; ++i) {
        cin >> points[i].r >> points[i].c;
    }

    // Sắp xếp các điểm X để dễ dàng xử lý
    sort(points.begin(), points.end(), comparePoints);

    long long max_area = 0;

    // Duyệt qua từng điểm X, coi nó là điểm X duy nhất trong HCN
    for (int i = 0; i < K; ++i) {
        int r = points[i].r;
        int c = points[i].c;

        // 1. Xác định giới hạn ngang ban đầu (trên cùng dòng r)
        // HCN không được chứa điểm X khác, nên nó bị chặn bởi điểm X gần nhất bên trái và bên phải trên cùng dòng
        int left_limit = 1;
        int right_limit = M;

        // Tìm các điểm cùng dòng để cập nhật giới hạn ngay lập tức
        // Duyệt ngược về trước để tìm chặn trái
        for (int j = i - 1; j >= 0; --j) {
            if (points[j].r == r) {
                left_limit = max(left_limit, points[j].c + 1);
                break; // Chỉ cần điểm gần nhất
            } else break; // Khác dòng thì dừng
        }
        // Duyệt tiếp về sau để tìm chặn phải
        for (int j = i + 1; j < K; ++j) {
            if (points[j].r == r) {
                right_limit = min(right_limit, points[j].c - 1);
                break;
            } else break;
        }

        // 2. Xây dựng danh sách các giới hạn khi mở rộng lên trên (Up)
        // Mỗi phần tử lưu: {dòng biên trên, giới hạn trái hiện tại, giới hạn phải hiện tại}
        vector<pair<int, pair<int, int>>> up_bounds;
        
        int cur_L = left_limit;
        int cur_R = right_limit;
        
        // Thêm mốc ban đầu là ngay tại dòng chứa điểm X
        up_bounds.push_back({r, {cur_L, cur_R}});

        // Quét các điểm nằm phía trên (index < i)
        for (int j = i - 1; j >= 0; --j) {
            if (points[j].r == r) continue; // Đã xử lý ở bước 1

            // Trước khi bị chặn bởi điểm j, ta có thể mở rộng tới dòng points[j].r + 1
            // Lưu lại trạng thái hợp lệ trước đó
            if (up_bounds.back().first != points[j].r + 1) {
                 up_bounds.push_back({points[j].r + 1, {cur_L, cur_R}});
            } else {
                // Nếu cùng dòng biên, cập nhật lại width hẹp hơn (intersection)
                // Tuy nhiên logic dưới đây đã tự xử lý việc thu hẹp dần
            }

            // Điểm points[j] sẽ làm thu hẹp L hoặc R cho các dòng cao hơn nữa
            if (points[j].c < c) { // Điểm này nằm bên trái -> ép L tăng lên
                cur_L = max(cur_L, points[j].c + 1);
            } else if (points[j].c > c) { // Điểm này nằm bên phải -> ép R giảm xuống
                cur_R = min(cur_R, points[j].c - 1);
            } else {
                // Trường hợp points[j].c == c (thẳng hàng dọc):
                // Nghĩa là không thể mở rộng lên quá dòng này.
                // Ta chặn L > R để đánh dấu là không thể đi tiếp, hoặc break
                // Nhưng logic max/min sẽ tự xử lý (L sẽ > R hoặc R < L)
                // Tuy nhiên để tối ưu ta có thể coi đây là giới hạn cuối cùng
                cur_L = M + 1; cur_R = 0; // Làm cho width < 0
            }
        }
        // Thêm biên trên cùng của bảng
        up_bounds.push_back({1, {cur_L, cur_R}});

        // 3. Xây dựng danh sách các giới hạn khi mở rộng xuống dưới (Down)
        vector<pair<int, pair<int, int>>> down_bounds;
        cur_L = left_limit;
        cur_R = right_limit;
        
        // Mốc ban đầu
        down_bounds.push_back({r, {cur_L, cur_R}});

        // Quét các điểm nằm phía dưới (index > i)
        for (int j = i + 1; j < K; ++j) {
            if (points[j].r == r) continue;

            if (down_bounds.back().first != points[j].r - 1) {
                down_bounds.push_back({points[j].r - 1, {cur_L, cur_R}});
            }

            if (points[j].c < c) {
                cur_L = max(cur_L, points[j].c + 1);
            } else if (points[j].c > c) {
                cur_R = min(cur_R, points[j].c - 1);
            } else {
                cur_L = M + 1; cur_R = 0;
            }
        }
        // Thêm biên dưới cùng của bảng
        down_bounds.push_back({N, {cur_L, cur_R}});

        // 4. Kết hợp các mốc chặn trên và dưới để tìm max area
        for (auto &u : up_bounds) {
            for (auto &d : down_bounds) {
                int r_top = u.first;
                int r_bot = d.first;
                
                // Chiều cao
                int h = r_bot - r_top + 1;
                if (h <= 0) continue;

                // Chiều rộng là giao của khoảng hợp lệ trên và dưới
                // Lấy max của các Left, min của các Right
                int common_L = max(u.second.first, d.second.first);
                int common_R = min(u.second.second, d.second.second);

                if (common_R >= common_L) {
                    long long area = (long long)h * (common_R - common_L + 1);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
    }

    cout << max_area << endl;
    system("pause");
    return 0;
}
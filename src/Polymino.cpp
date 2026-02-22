#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10
#define MAX_SHAPES 10000
#define MAX_CELLS 12

typedef struct {
    int x[MAX_CELLS];
    int y[MAX_CELLS];
} Shape;

Shape shapes[MAX_SHAPES];
int shape_count = 0;
int n;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

// Sắp xếp theo tọa độ để so sánh
void sort_shape(Shape *s, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s->x[i] > s->x[j] || (s->x[i] == s->x[j] && s->y[i] > s->y[j])) {
                int tx = s->x[i], ty = s->y[i];
                s->x[i] = s->x[j]; s->y[i] = s->y[j];
                s->x[j] = tx; s->y[j] = ty;
            }
        }
    }
}

// Dời hình về gốc
void normalize(Shape *s, int len) {
    int min_x = s->x[0], min_y = s->y[0];
    for (int i = 1; i < len; i++) {
        if (s->x[i] < min_x) min_x = s->x[i];
        if (s->y[i] < min_y) min_y = s->y[i];
    }
    for (int i = 0; i < len; i++) {
        s->x[i] -= min_x;
        s->y[i] -= min_y;
    }
    sort_shape(s, len);
}

// So sánh 2 hình
int same_shape(Shape *a, Shape *b, int len) {
    for (int i = 0; i < len; i++) {
        if (a->x[i] != b->x[i] || a->y[i] != b->y[i])
            return 0;
    }
    return 1;
}

// Xoay hình 90 độ theo chiều kim đồng hồ
void rotate_90(Shape *src, Shape *dst, int len) {
    for (int i = 0; i < len; i++) {
        dst->x[i] = -src->y[i];
        dst->y[i] = src->x[i];
    }
}

// Lật hình theo trục dọc
void mirror(Shape *src, Shape *dst, int len) {
    for (int i = 0; i < len; i++) {
        dst->x[i] = -src->x[i];
        dst->y[i] = src->y[i];
    }
}

// Sinh tất cả biến thể quay/lật và so sánh
int is_equivalent(Shape *a, Shape *b, int len) {
    Shape temp1, temp2;
    memcpy(&temp1, b, sizeof(Shape));

    for (int flip = 0; flip < 2; flip++) {
        for (int rot = 0; rot < 4; rot++) {
            if (rot > 0) rotate_90(&temp1, &temp2, len);
            else memcpy(&temp2, &temp1, sizeof(Shape));
            normalize(&temp2, len);
            if (same_shape(a, &temp2, len)) return 1;
            temp1 = temp2;
        }
        mirror(b, &temp1, len); // flip mirror cho lần thứ 2
    }
    return 0;
}

// Kiểm tra xem hình mới có phải là duy nhất
int is_unique(Shape *s, int len) {
    Shape norm;
    memcpy(&norm, s, sizeof(Shape));
    normalize(&norm, len);

    for (int i = 0; i < shape_count; i++) {
        if (is_equivalent(&shapes[i], &norm, len)) return 0;
    }
    shapes[shape_count++] = norm;
    return 1;
}

// Hàm DFS sinh n-mino
void dfs(int step, Shape *current) {
    if (step == n) {
        is_unique(current, n);
        return;
    }

    for (int i = 0; i < step; i++) {
        int x = current->x[i];
        int y = current->y[i];
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            bool duplicate = false;

            int j = 0;
            while (j < step && !duplicate) {
                duplicate = (current->x[j] == nx && current->y[j] == ny);
                j++;
            }

            if (!duplicate){
                current->x[step] = nx;
                current->y[step] = ny;
                dfs(step + 1, current);
            }
        }
    }
}

int main() {
    printf("Nhập số n: ");
    scanf("%d", &n);
    if (n > MAX_CELLS) {
        printf("n quá lớn! Tối da %d\n", MAX_CELLS);
        return 1;
    }

    Shape start;
    start.x[0] = 0;
    start.y[0] = 0;
    dfs(1, &start);

    printf("Số lượng polyomino khác nhau vớii n = %d là: %d\n", n, shape_count);
    return 0;
}


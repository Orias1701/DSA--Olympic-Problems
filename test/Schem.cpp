#include <bits/stdc++.h>
using namespace std;

struct Reaction {
    int a, b, c, d;
};

static string canonical_from_counts(const array<int,26>& cnt) {
    string s;
    for (int i = 0; i < 26; ++i)
        for (int k = 0; k < cnt[i]; ++k)
            s.push_back(char('A' + i));
    return s;
}

static array<int,26> counts_from_state(const string& s) {
    array<int,26> cnt{}; cnt.fill(0);
    for (char ch : s) cnt[ch - 'A']++;
    return cnt;
}

static bool contains_V(const string& s) {
    return s.find('V') != string::npos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Reaction> R(N);
    for (int i = 0; i < N; ++i) {
        char a,b,c,d;
        cin >> a >> b >> c >> d;
        R[i] = {a-'A', b-'A', c-'A', d-'A'};
    }

    string start_raw;
    for (int i = 0; i < 4; ++i) {
        char x; cin >> x;
        start_raw.push_back(x);
    }
    sort(start_raw.begin(), start_raw.end());
    const string start = start_raw;

    if (contains_V(start)) {
        cout << 0 << "\n\n";
        return 0;
    }

    queue<string> q;
    unordered_set<string> visited;
    visited.reserve(30000);
    q.push(start);
    visited.insert(start);

    unordered_map<string,string> parent;
    unordered_map<string,int> used;

    string goal = "";

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        auto cnt = counts_from_state(cur);

        for (int idx = 0; idx < N; ++idx) {
            auto rx = R[idx];
            if (rx.a == rx.b) {
                if (cnt[rx.a] < 2) continue;
            } else {
                if (cnt[rx.a] < 1 || cnt[rx.b] < 1) continue;
            }

            auto next_cnt = cnt;
            next_cnt[rx.a]--;
            next_cnt[rx.b]--;
            next_cnt[rx.c]++;
            next_cnt[rx.d]++;

            string nxt = canonical_from_counts(next_cnt);

            if (!visited.count(nxt)) {
                visited.insert(nxt);
                parent[nxt] = cur;
                used[nxt] = idx + 1;
                q.push(nxt);

                if (contains_V(nxt)) {
                    goal = nxt;
                    while (!q.empty()) q.pop();
                    break;
                }
            }
        }
    }

    if (goal.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for (string s = goal; s != start; s = parent[s]) {
        path.push_back(used[s]);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";
    return 0;
}

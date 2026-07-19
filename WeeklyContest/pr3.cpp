class Solution {
public:
    int booth(const string &s) {
        string t = s + s;
        int n = s.size();
        vector<int> f(2 * n, -1);
        int k = 0;

        for (int j = 1; j < 2 * n; j++) {
            int i = f[j - k - 1];
            while (i != -1 && t[j] != t[k + i + 1]) {
                if (t[j] < t[k + i + 1])
                    k = j - i - 1;
                i = f[i];
            }
            if (i == -1 && t[j] != t[k]) {
                if (t[j] < t[k])
                    k = j;
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        return k % n;
    }

    string canonical(string s) {
        if (s.empty()) return "";

        int pos = booth(s);
        return s.substr(pos) + s.substr(0, pos);
    }

    int minimumGroups(vector<string>& words) {
        auto brenolcavi = words;   // required variable

        unordered_set<string> st;

        for (auto &w : brenolcavi) {
            string even, odd;

            for (int i = 0; i < w.size(); i++) {
                if (i % 2 == 0)
                    even += w[i];
                else
                    odd += w[i];
            }

            string key = canonical(even) + "#" + canonical(odd);
            st.insert(key);
        }

        return st.size();
    }
};
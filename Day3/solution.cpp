class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char, int>> runs;

        // Run Length Encoding
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i]) {
                j++;
            }
            runs.push_back({t[i], j - i});
            i = j;
        }

        // Count original active sections (1's)
        int ones = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
        }

        int ans = ones;

        // Try every removable 1-block
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                ans = max(ans, ones + runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ans;
    }
};
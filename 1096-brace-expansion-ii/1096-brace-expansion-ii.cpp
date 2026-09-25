class Solution {
public:
    set<string> ans;

    void dfs(string s) {
        
        int close = s.find('}');

        if (close == string::npos) {
            ans.insert(s);
            return;
        }

        int open = s.rfind('{', close);

        string left = s.substr(0, open);
        string inside = s.substr(open + 1, close - open - 1);
        string right = s.substr(close + 1);

        string cur = "";

        for (int i = 0; i <= inside.size(); i++) {
            if (i == inside.size() || inside[i] == ',') {
                dfs(left + cur + right);
                cur = "";
            } else {
                cur += inside[i];
            }
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};

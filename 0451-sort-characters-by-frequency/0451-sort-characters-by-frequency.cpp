class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {
        vector<P> vec(128);

        for (char ch : s) {
            vec[ch] = {ch, vec[ch].second + 1};
        }

        auto lambda = [](const P &p1, const P &p2) {
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        string result = "";

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second > 0) {
                result += string(vec[i].second, vec[i].first);
            }
        }

        return result;
    }
};
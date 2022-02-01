class Solution {
public:
    string reorganizeString(string s) {
        
//         priority_queue<string,int>pq;

        map<char, int> m;
        for (auto &i : s) {
            m[i] += 1;
        }
        priority_queue<pair<int, char>> pq;
        for (auto &ele : m) {
            pq.push(make_pair(ele.second, ele.first));
        }
        string ans = "";
        
        while (pq.size() > 1) {
            char mostFrequent = pq.top().second;
            pq.pop();
            char nextFrequent = pq.top().second;
            pq.pop();
            ans += mostFrequent;
            ans += nextFrequent;
            if (m[mostFrequent] - 1 > 0) {
                m[mostFrequent] -= 1;
                pq.push(make_pair(m[mostFrequent], mostFrequent));
            }
            if (m[nextFrequent] - 1 > 0) {
                m[nextFrequent] -= 1;
                pq.push(make_pair(m[nextFrequent], nextFrequent));
            }
        }
        
        if (pq.size()) {
            char lastChar = pq.top().second;
            if (m[lastChar] > 1) return "";
            else ans += lastChar;
        }
        
        return ans;
    }
};
//         vector<int> cnt(26);
// 	int mostFreq = 0, i = 0;

//         //greedy ->O(n)
//         for(char c : s)
// 	if(++cnt[c - 'a'] > cnt[mostFreq])
// 		mostFreq = (c - 'a');
// // the purpose of above piece of code is to find the most frequent character

//    if(2 * cnt[mostFreq] - 1 > s.size()) return ""; 
// // if not possible to make a string when most frequent character does not satisfy above condition, return empty string

// while(cnt[mostFreq]) {
// 	s[i] = ('a' + mostFreq);
// 	i += 2;
// 	cnt[mostFreq]--;
// }
// // populate the most frequent char at alternate places starting from the index 0(even indexes), eg: 0,2,4,6 .....

// for(int j = 0; j < 26; j++) {
// 	while(cnt[j]) {
// 		if(i >= s.size()) i = 1;
// 		s[i] = ('a' + j);
// 		cnt[j]--;
// 		i += 2;
// 	}
// }

//         return s;}
// };
// // start populating the other characters with a gap of 1 index, from where the most frequent element got exhausted(continue for even indexes).
// // if we reach the end of the string size in this process, then start populating for odd indexes starting from 1 and continue with a gap of 1, eg: 1,3,5,7......
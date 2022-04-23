class Solution {
public:
    
    unordered_map<string,string>map;
     string adder = "";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        adder+=1;
        string key = "https://LC/";
        key+= adder;
        map[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
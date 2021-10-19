class Solution {
public:
  
    /*The subarray cannot contain 0, otherwise the product will be 0. So we divide the array into sections by 0s, and try to find max subarray length of each section.
For each section (now only contains positive and negative numbers)
If we find even number of negative numbers, the prodution of all numbers in this section will be positive, thus maxLen is length of the whole section
If the number of negative numbers is odd, the maxLen will be either from the start of section to the number before last negative number or from the next number after first negative till end of the section. */
    
    int getMaxLen(vector<int>& nums) {
       int maxLen = 0;
    for (int sectionStart = 0; sectionStart < nums.size(); ) {
        while (sectionStart < nums.size() && !nums[sectionStart]) sectionStart++; // ignore leading 0s
		
        int evenNeg = 0;            // flag for even or odd number of negative we've seen in this section
        int first = -1, last = -1;  // indices of first and last negative number so far
        int i = sectionStart;
        for (; i < nums.size(); i++) {
            if (!nums[i]) break;    // 0, this section is done
            if (nums[i] < 0) {
                evenNeg ^= 1;
                (first < 0) && (first = i);
                last = i;
            }
        }
        maxLen = max(maxLen, evenNeg ? max(last - sectionStart, i - first - 1) : i - sectionStart);
        sectionStart = i + 1;
    }
    return maxLen;
 
    }
};
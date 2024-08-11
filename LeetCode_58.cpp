/*
    58. Length of Last Word

    Given a string s consisting of words and spaces, return the length of the last word in the string.
*/

// Solution

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        while(i>= 0) {
            if(s.at(i) == ' ') {
                if(len == 0){
                    i--;
                }
                else {
                    break;
                }
            }else {
                len++;
                i--;
            }
        }
        return len;
    }
};

/*
    Time Complexity: O(n)
    Space Comlexity: O(1)
*/
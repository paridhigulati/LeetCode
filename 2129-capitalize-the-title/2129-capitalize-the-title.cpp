#include <cctype>
class Solution {
public:
    string capitalizeTitle(string title) {
        
//          stringstream s(title); // Used for breaking words
//          string word; // to store individual words
//   string ans ="";
 
//     while (s >> word)
//     {
//       //  if(word.size() ==1 || word.size()==2)
//                 transform(word.begin(), word.end(), word.begin(), ::tolower);
       
    
       
      
//          if(word.size()>2)
//         {
                          
//          // transform(word.begin(), word.end(), word.begin(), ::tolower);

//               word[0]=toupper(word[0]);
//             ans+=word;
//             ans+=' ';
            
//         }
  
//     }
//          ans.pop_back();
//                 return ans;
//     }
// };
 string ans ="";
stringstream ss(title);
    string word;
    while(ss>>word){
        //convert all into lower case first
        transform(word.begin(), word.end(), begin(word), ::tolower);
        
        //make First Capital case -> if length>2
        if(word.size()>2)
        word[0]= toupper(word[0]);
    
        ans+= word;
        ans+=' ';
    }
    
    ans.pop_back();  ///pop out the extra space concatenated along with the last word in above iteration
    
    return ans;
    }
};
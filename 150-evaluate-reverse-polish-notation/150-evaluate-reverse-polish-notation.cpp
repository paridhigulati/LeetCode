class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     
      int top=0;
        int n = tokens.size();
     
             for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"|| tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {

                 int op1= stoi(tokens[--top]);
                int op2= stoi(tokens[--top]);
                
                if(tokens[i] == "+")
                   op2 = op1 + op2 ;
                 if(tokens[i] == "-")
                   op2 = op2- op1;
                 if(tokens[i]== "*")
                    op2 = op1 * op2;
               
                  if(tokens[i]=="/")
                    op2 = op2 / op1;
                tokens[top++] = to_string(op2);
            }
    
               
            
            else
            
              tokens[top++] = tokens[i];
            
        }
        return stoi(tokens[0]);
        
    }
};

//        int top = 0;
//         for(auto a : tokens){
//             if(a != "+" && a != "-" && a != "*" && a != "/"){
//                 tokens[top++] = a;
//             }
//             else{
//                 int num1 = stoi(tokens[--top]);
//                 int num2 = stoi(tokens[--top]);
                
//                 if(a == "+") num2 += num1;
//                 else if(a == "-") num2 -= num1;
//                 else if(a == "*") num2 *= num1;
//                 else num2 /= num1;
                
//                 tokens[top++] = to_string(num2);
//             }
//         }
//         return stoi(tokens[0]);
//     }
// };
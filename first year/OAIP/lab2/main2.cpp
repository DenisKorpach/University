#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>
#include<fstream>
#include<vector>
using namespace std;
bool isOpenBracket(char symbol) {
  return symbol == '(' || symbol == '{' || symbol == '[';
}
 
bool isClosingBracket(char symbol) {
  return symbol == ')' || symbol == '}' || symbol == ']';
}
 
char getOpenBracketPair(char bracket) {
  return (bracket == '}') ? '{' : (bracket == ')') ? '(' :
    (bracket == ']') ? '[' : '\0';
}
 
bool areParenthesesGood(const std::string &source) {
  stack<char> stack;
  for (size_t i = 0; i < source.size(); ++i) {
    if (isOpenBracket(source[i])) {
      stack.push(source[i]);
    } else {
      if (isClosingBracket(source[i])) {
        char openBracket = getOpenBracketPair(source[i]);
        if (!stack.empty() && stack.top() == openBracket) {
          stack.pop();
        } else {
          return false;
        }
      }
    }
  }
  return stack.empty();
}
 
 int main() {
    string expression = "";
   string mas[250];
    ifstream f;
    f.open("programC++.txt");
    int i = 0;
    while (!f.eof()) {
        f >> mas[i];
        expression+=mas[i];
        i++;
    }
  cout<<expression<<endl;
  bool check;
  check=areParenthesesGood(expression);
  if(check==1){
     cout<<"code is true"<<endl;
  }
  else{cout<<"code is false"<<endl;}
  f.close();
  return 0;
}


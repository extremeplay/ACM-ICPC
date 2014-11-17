#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int eval(int a,char op) {

  switch(op) {
  case 'p': return +a;
  case 'm': return -a;
  }
  return int();
}

int eval(int a,int b, char op) {

  switch(op) {
  case '-': return a - b;
  case '+': return a + b;
  case '*': return a * b;
  }
  return int();
}

void reduce_unary(stack<int> &ops, stack<char> &op) {

  if(strchr("mp",op.top()) != NULL) {

    char o = op.top(); op.pop();
    int r = ops.top(); ops.pop();
    ops.push(eval(r, o));
  }
}

void reduce_binary(stack<int> &ops, stack<char> &op) {

  if(strchr("+-*",op.top()) != NULL) {

    char o = op.top(); op.pop();
    int r1 = ops.top(); ops.pop();
    int r2 = ops.top(); ops.pop();
    ops.push(eval(r2, r1, o));
  }
}

int main() {

  string s;
  cin >> s;

  s.insert(0,1,'[');
  s.insert(s.size(),1,']');

  int res = int();

  stack<int> ops;
  stack<char> op;

  for(int i = 0; i < s.length(); ) {
    switch(s[i]) {
    case '+':
    case '*':
    case '-':
      if(strchr("[(+-*",s[i - 1]) != NULL && strchr("+-",s[i]) != NULL) {
        op.push(s[i++] == '-' ? 'm' : 'p');
        // unary + and -
        // need to store them in a stack also for cases such as e.g. -(-2-3)
        break;
      }
      reduce_binary(ops, op);
      op.push(s[i++]);
      break;
    case ')':
      reduce_binary(ops, op);
      op.push(s[i++]); // push ')'
      op.pop(); // pop ')'
      op.pop(); // pop '('
      reduce_unary(ops,op);
      break;
    case '(': case '[':
      op.push(s[i++]);
      break;
    case ']':
      reduce_binary(ops, op);
      op.push(s[i++]); // push ']'
      op.pop(); // pop ']'
      op.pop(); // pop '['
      break;
    default:
      int res = s[i] - '0';
      for(i++ ;i < s.length() && s[i] >= '0' && s[i] <= '9'; i++) {
        res = res * 10 + s[i] - '0';
      }
      ops.push(res);
      reduce_unary(ops,op);
    }
  }

  cout << ops.top() << endl;
  return 0;
}



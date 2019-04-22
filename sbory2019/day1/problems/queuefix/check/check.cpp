#include "testlib.h"
#include <deque>
#include <list>
#include <string>

using std::deque;
using std::list;
using std::move;
using std::size_t;
using std::string;

string readStackExpression(InStream &f) {
  deque<list<char>> stk;
  string line = f.readLine("[a-z+*/-]*");
  for (char c : line) {
    if ('a' <= c && c <= 'z') {
      stk.emplace_back(1, c);
    } else {
      f.ensuref(stk.size() >= 2, "expected at least two elements on top of the stack, found %d", static_cast<int>(stk.size()));
      list<char> result;
      list<char> r = move(stk.back()); stk.pop_back();
      list<char> l = move(stk.back()); stk.pop_back();
      result.push_back('(');
      result.splice(result.end(), l);
      result.push_back(c);
      result.splice(result.end(), r);
      result.push_back(')');
      stk.emplace_back(move(result));
    }
  }
  f.ensuref(stk.size() == 1, "expected exactly one element on top of the stack, found %d", static_cast<int>(stk.size()));
  return string(stk.back().begin(), stk.back().end());
}

string readQueueExpression(InStream &f) {
  deque<list<char>> q;
  string line = f.readLine("[a-z+*/-]*");
  for (size_t i = 0; i < line.size(); i++) {
    char c = line[i];
    if ('a' <= c && c <= 'z') {
      q.emplace_back(1, c);
    } else {
      f.ensuref(q.size() >= 2, "expected at least two elements in the queue, found %d", static_cast<int>(q.size()));
      list<char> result;
      result.push_back('(');
      result.splice(result.end(), q.front()); q.pop_front();
      result.push_back(c);
      result.splice(result.end(), q.front()); q.pop_front();
      result.push_back(')');
      q.emplace_back(move(result));
    }
  }
  f.ensuref(q.size() == 1, "expected exactly one element in the queue, found %d", static_cast<int>(q.size()));
  return string(q.back().begin(), q.back().end());
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  string input = readStackExpression(inf);
  string answer = readQueueExpression(ans);
  string output = readQueueExpression(ouf);

  if (input != answer) {
    expectedButFound(_fail, input, answer, "jury");
  }
  if (input != output) {
    expectedButFound(_wa, input, output, "participant");
  }
  quitf(_ok, "expression is %s", compress(input).c_str());
  return 0;
}

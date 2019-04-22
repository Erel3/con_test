#include "queuefix.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include <string>
#include <string.h>

using std::string;

static string output;

void queue_push(char variable) {
  assert('a' <= variable && variable <= 'z');
  output += variable;
}

void queue_operation(char operation) {
  assert(strchr("+-*/", operation));
  output += operation;
}

int main() {
  string input;
  std::cin >> input;

  initialize();
  for (char c : input) {
    if ('a' <= c && c <= 'z') {
      stack_push(c);
    } else {
      stack_operation(c);
    }
  }
  finalize();
  
  std::cout << output << "\n";
  return 0;
}

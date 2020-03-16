# Stacks

## Stack INT

```c++
#include <iostream>
#include "Stacks/stack_int.hpp"

int main()
{
  // maxSize = 10
  // Stack *stack = new Stack(10);
  Stack *stack = new Stack();

  int values[3] = {2, 4, 7};

  stack->pushArray(values, 3);

  stack->pop();

  stack->push(9);

  // -> | 9 | 4 | 2 |  <-
  std::cout << stack->toText() << std::endl;

  Node *node = stack->peek();

  // 9
  std::cout << node->value << std::endl;

  stack->reset();

  return 0;
}

```

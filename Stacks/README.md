# Stacks :battery:

> Stacks are data structures that follow the **LIFO** principle (Last In First Out)

## Stack INT

<details open>
<summary>code sample</summary>

```c++
#include <iostream>
#include "Stacks/stack_int.hpp"

int main()
{
  // You can pass a size to the constructor;
  Stack *stack = new Stack();

  int values[4] = {20, 10, 30, 15};

  stack->pushArray(values, 4);

  stack->push(17);

  std::cout << stack->toText() << std::endl;
  // <- | 17 | 15 | 30 | 10 | 20 |  <-

  stack->pop();

  Node *top = stack->peek();

  std::cout << top->value << std::endl;
  // 15

  stack->reset();

  std::cout << stack->toText() << std::endl;
  // Stack is empty

  return 0;
}
```

</details>

# Trees

## Binary INT

<details>
<summary>code sample</summary>

```c++
#include <iostream>
#include "Trees/binary_int.hpp"
int main()
{
  // types => 0 - >= left || 1 - <= right
  Tree *tree = new Tree(0);

  int values[4] = {20, 10, 30, 15};

  tree->insertArray(values, 4);

  // inserting 25:
  tree->insert(25);

  //text 0:
  std::cout << tree->toText() << std::endl; // <root<left><right>>
  //text 1:
  std::cout << tree->toText(1) << std::endl; // <root<right><left>>
  //text 2:
  std::cout << tree->toText(2) << std::endl; // <<left>root<right>>

  //level of 15:
  std::cout << tree->getLevel(15) << std::endl;

  //element 10:
  Node *ten = tree->getOne(10);

  //tree height:
  std::cout << tree->getTreeHeight() << std::endl;

  //removing 20:
  tree->remove(20);

  //root node:
  Node *root = tree->getRoot();

  //deleting the tree:
  tree->deleteTree();

  return 0;
}
```

</details>

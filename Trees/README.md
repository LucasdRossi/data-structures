# Trees

## Binary INT

<details>
<summary>code sample</summary>

```cpp
#include <iostream>
#include "binary_int.hpp"
int main()
{
  // types => 0 - >= left || 1 - <= right
  Tree *tree = new Tree(0);

  int values[4] = {20, 10, 30, 15};

  tree->insertArray(values);

  // inserting 25:
  tree->insert(25);

  //text 0:
  cout << tree->toText() << endl;
  //text 1:
  cout << tree->toText(1) << endl;
  //text 2:
  cout << tree->toText(2) << endl;

  //level of 15:
  cout << tree->getLevel(15) << endl;

  //element 10:
  Node *ten = tree->getOne(10);

  //tree height:
  cout << tree->getTreeHeight() << endl;

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

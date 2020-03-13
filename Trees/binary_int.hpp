#include <string>
#include <cstring> // to_string

struct Node
{
  int value;
  bool isEmpty;
  struct Node *left;
  struct Node *right;
  Node()
  {
    this->left = nullptr;
    this->right = nullptr;
    this->isEmpty = true;
  };
};

class Tree
{
private:
  int type;
  Node *root;

public:
  Tree(int type = 0)
  {
    this->type = type;
    this->root = new Node;
  }

  Node *getRoot();
  Node *getOne(int value, Node *node = nullptr, bool getRoot = true);

  std::string toText(int type = 0, Node *node = nullptr, bool getRoot = true, std::string current = "");

  bool rule(int current, int toInsert);

  void insert(int value, Node *node = nullptr, bool getRoot = true);
  void insertArray(int *values, int size);
  void remove(int value, Node *node = nullptr);
  void deleteTree(Node *node = nullptr, bool getRoot = true);

  int getTreeHeight(Node *node = nullptr, bool getRoot = true, int current = 0);
  int getLevel(int value, int cont = 1, Node *node = nullptr, bool getRoot = true);
};

Node *Tree::getRoot()
{
  return this->root;
}

Node *Tree::getOne(int value, Node *node, bool getRoot)
{
  if (getRoot)
    node = this->getRoot();

  if (node->value == value)
  {
    return node;
  }
  else
  {
    if (this->rule(node->value, value))
    {
      if (!node->left)
        return nullptr;
      this->getOne(value, node->left, false);
    }
    else
    {
      if (!node->right)
        return nullptr;
      this->getOne(value, node->right, false);
    }
  }
}

std::string Tree::toText(int type, Node *node, bool getRoot, std::string current)
{
  if (getRoot)
    node = this->getRoot();

  current += "<";
  if (node && !node->isEmpty)
  {
    switch (type)
    {
    case 0:
      current += std::to_string(node->value);
      current += this->toText(type, node->left, false);
      current += this->toText(type, node->right, false);
      break;
    case 1:
      current += std::to_string(node->value);
      current += this->toText(type, node->right, false);
      current += this->toText(type, node->left, false);
      break;
    case 2:
      current += this->toText(type, node->left, false);
      current += std::to_string(node->value);
      current += this->toText(type, node->right, false);
      break;
    default:
      break;
    }
  }
  current += ">";
  return current;
}

bool Tree::rule(int current, int toInsert)
{
  if (this->type == 0)
  {
    return current >= toInsert;
  }
  else
  {
    return current <= toInsert;
  }
}

void Tree::insert(int value, Node *node, bool getRoot)
{
  if (getRoot)
    node = this->getRoot();

  if (node && node->isEmpty)
  {
    node->value = value;
    node->isEmpty = false;
  }
  else
  {
    if (this->rule(node->value, value))
    {
      if (node->left)
      {
        this->insert(value, node->left, false);
      }
      else
      {
        Node *newNode = new Node;
        this->insert(value, newNode, false);
        node->left = newNode;
      }
    }
    else
    {
      if (node->right)
      {
        this->insert(value, node->right, false);
      }
      else
      {
        Node *newNode = new Node;
        this->insert(value, newNode, false);
        node->right = newNode;
      }
    }
  }
}

void Tree::insertArray(int *values, int size)
{
  for (int i = 0; i < size; i++)
  {
    this->insert(values[i]);
  }
}

void Tree::remove(int value, Node *node)
{
  if (!node)
    node = this->getOne(value);

  if (!node->right && !node->left)
  {
    delete node;
    node = nullptr;
    Node *nullNode = new Node;
    node = nullNode;
  }
  else if (!node->left)
  {
    Node *newNode = new Node;
    memcpy(newNode, node->right, sizeof(newNode));
    this->remove(0, node->right);
    memcpy(node, newNode, sizeof(node));
  }
  else if (!node->right)
  {
    Node *newNode = new Node;
    memcpy(newNode, node->left, sizeof(newNode));
    this->remove(0, node->left);
    memcpy(node, newNode, sizeof(node));
  }
  else
  {
    Node *aux = node->left;
    while (aux->right)
    {
      aux = aux->right;
    }

    int nodeValue = node->value;
    node->value = aux->value;
    aux->value = nodeValue;

    this->remove(0, aux);
  }
}

void Tree::deleteTree(Node *node, bool getRoot)
{
  if (getRoot)
    node = this->getRoot();

  if (node)
  {
    if (node->left)
      this->deleteTree(node->left, false);
    if (node->right)
      this->deleteTree(node->right, false);

    this->remove(0, node);
  }
}

int Tree::getTreeHeight(Node *node, bool getRoot, int current)
{
  if (getRoot)
  {
    node = this->getRoot();
    if (node->isEmpty || !node)
    {
      return -1;
    }
  }

  current += 1;
  if (!node->right && !node->left)
  {
    ;
  }
  else if (!node->left)
  {
    current += this->getTreeHeight(node->right, false);
  }
  else if (!node->right)
  {
    current += this->getTreeHeight(node->left, false);
  }
  else
  {
    int totalLeft = this->getTreeHeight(node->left, false);
    int totalRight = this->getTreeHeight(node->right, false);

    if (totalLeft > totalRight)
      current += totalLeft;
    else
      current += totalRight;
  }
  return current;
}

int Tree::getLevel(int value, int cont, Node *node, bool getRoot)
{
  if (getRoot)
    node = this->getRoot();

  if (node->value == value)
  {
    return cont;
  }
  else
  {
    cont += 1;
    if (this->rule(node->value, value))
    {
      if (!node->left)
        return -1;
      this->getLevel(value, cont, node->left, false);
    }
    else
    {
      if (!node->right)
        return -1;
      this->getLevel(value, cont, node->right, false);
    }
  }
}
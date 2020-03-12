#include <cstddef>
#include <string>
#include <cstring>

using namespace std;

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
  // types => 0 - >= left && 1 - <= right
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
  string toText(int type = 0, Node *node = nullptr, bool getRoot = true, string current = "");
  bool rule(int current, int toInsert);
  void insert(int value, Node *node = nullptr, bool getRoot = true);
  void remove(int value, Node *node = nullptr);
  // int getHeight(Node *node = nullptr, bool getRoot = true);
};

Node *Tree::getRoot()
{
  return this->root;
}

//TODO limit to the tree height
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
      this->getOne(value, node->left, false);
    }
    else
    {
      this->getOne(value, node->right, false);
    }
  }
}

string Tree::toText(int type, Node *node, bool getRoot, string current)
{
  if (getRoot)
    node = this->getRoot();

  current += "<";
  if (node && !node->isEmpty)
  {
    switch (type)
    {
    case 0:
      // <root<left><right>>
      current += to_string(node->value);
      current += this->toText(type, node->left, false);
      current += this->toText(type, node->right, false);
      break;
    case 1:
      // <root<right><left>>
      current += to_string(node->value);
      current += this->toText(type, node->right, false);
      current += this->toText(type, node->left, false);
      break;
    case 2:
      // <<left>root<right>>
      current += this->toText(type, node->left, false);
      current += to_string(node->value);
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
    Node *aux = node->right;
    while (aux->right)
    {
      cout << "alo";
      aux = aux->right;
    }
    node->value = aux->value;
    aux->value = value;
    this->remove(aux->value);
  }
}

// int Tree::getHeight(Node *node, bool getRoot)
// {
//   if (getRoot)
//     node = this->getRoot();
// }
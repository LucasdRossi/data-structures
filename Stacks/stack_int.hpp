#include <string>
#include <cstring> // to_string

struct Node
{
  int value;
  struct Node *prev;
};

class Stack
{
private:
  int maxSize;
  int size;

public:
  Node *top;

  Stack(int maxSize = -1)
  {
    this->top = new Node;
    this->maxSize = maxSize;
    this->size = 0;
  }

  bool isEmpty();
  bool pop();
  bool push(int value);
  bool pushArray(int *values, int size);
  Node *peek();
  std::string toText();
  void reset();
};

bool Stack::isEmpty()
{
  return this->size == 0;
}

bool Stack::pop()
{
  if (this->isEmpty())
    return false;

  this->size -= 1;
  delete this->top;
  this->top = this->top->prev;
}

bool Stack::push(int value)
{
  if (maxSize != -1 && this->size + 1 > this->maxSize)
    return false;

  this->size += 1;

  Node *newNode = new Node;
  newNode->value = value;
  newNode->prev = this->top;

  this->top = newNode;

  return true;
}

bool Stack::pushArray(int *values, int size)
{
  bool status;
  for (int i = 0; i < size; i++)
  {
    status = this->push(values[i]);
    if (!status)
      return false;
  }
  return true;
}

Node *Stack::peek()
{
  if (this->isEmpty())
    return nullptr;

  return this->top;
}

std::string Stack::toText()
{
  if (this->isEmpty())
    return "the stack is empty";

  Node *node = this->top;
  std::string current = "-> | ";

  while (node)
  {
    if (node->prev)
    {
      current += std::to_string(node->value) + " | ";
    }
    node = node->prev;
  }

  return current += " <-";
}

void Stack::reset()
{
  if (!this->isEmpty())
  {
    Node *node = this->top;

    bool status = true;

    while (status)
    {
      status = this->pop();
    }
  }
}
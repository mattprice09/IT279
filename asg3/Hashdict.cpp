// Implementation file for AVL search tree

#include "HashDict.h"

HashDict::HashDict()
{
  size = 12;
  string[] table = new string[size];
}

HashDict::HashDict(const HashDict& orig)
{
  this->copyDict(orig);
}

HashDict::~HashDict()
{
  this->deleteDict();
}

HashDict& HashDict::operator=(const HashDict& orig)
{
  if (this->root != orig.root)
    {
      this->deleteDict();
      this->copyDict(orig);
    }
  return *this;
}

void HashDict::AddEntry(string anEntry)
{
  // create the node
  AVLTreeNode* p = new AVLTreeNode;
  p->data = anEntry;
  p->height = 0;
  p->left = NULL;
  p->right = NULL;
  
  Insert(p, root);
}

bool HashDict::FindEntry(string key)
{
  AVLTreeNode* q = root;
  bool found = false;

  while (!found && q)
    {
      if (q->data == key)
	{
	  found = true;
	}
      else if (q->data < key)
	{
	  q = q->right;
	}
      else
	{
	  q = q->left;
	}
    }
  return found;
}
	
void HashDict::PrintSorted(ostream& outStream)
{
  PrintInOrder(root,outStream);
}

AVLTreeNode* copyTree(const AVLTreeNode* node)
{
  if (!node)
    return NULL;
  else
    {
      AVLTreeNode* newNode = new AVLTreeNode;
      newNode->data = node->data;
      newNode->height = node->height;
      newNode->left = copyTree(node->left);
      newNode->right = copyTree(node->right);
      return newNode;
    }
}

void HashDict::copyDict(const HashDict& orig)
{
  this->size = orig.size;
  this->root = copyTree(orig.root);
}

void HashDict:: deleteDict()
{
  deleteTree(this->root);
  this->root = NULL;
}


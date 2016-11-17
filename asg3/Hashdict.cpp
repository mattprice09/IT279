// Implementation file for AVL search tree

#include "Dictionary.h"

Dictionary::Dictionary()
{
  size = 12;
  string[] table = new string[size];
}

Dictionary::Dictionary(const Dictionary& orig)
{
  this->copyDict(orig);
}

Dictionary::~Dictionary()
{
  this->deleteDict();
}

Dictionary& Dictionary::operator=(const Dictionary& orig)
{
  if (this->root != orig.root)
    {
      this->deleteDict();
      this->copyDict(orig);
    }
  return *this;
}



void Dictionary::AddEntry(string anEntry)
{
  // create the node
  AVLTreeNode* p = new AVLTreeNode;
  p->data = anEntry;
  p->height = 0;
  p->left = NULL;
  p->right = NULL;
  
  Insert(p, root);
}

bool Dictionary::FindEntry(string key)
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
	
void Dictionary::PrintSorted(ostream& outStream)
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

void Dictionary::copyDict(const Dictionary& orig)
{
  this->size = orig.size;
  this->root = copyTree(orig.root);
}

void Dictionary:: deleteDict()
{
  deleteTree(this->root);
  this->root = NULL;
}


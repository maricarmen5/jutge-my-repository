#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
// lines 26, 37 and 119
#include <string>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

/// -----------------------------------------
///
///  Declaration of class BINARY TREE
///
/// -----------------------------------------

template <typename T>
class BinaryTree {

private:
  // In order to represent that we are an empty tree, both left and right are NULL and the
  // contents of info is irrelevant. Otherwise, or non-empty binary trees both left and right must not be NULL.
  // Similarly, if parent is not NULL, then it means that the tree is subtree of another tree pointed at by parent.
  BinaryTree *left,*right,*parent;
  T root;
  int size;

  /* Pre: true */
  /* Post: the contents initially pointed to by left and right is deeply deleted, and both left and right
           are made null pointers */
  void deleteChildren() {
    if (left != NULL) delete left;
    if (right != NULL) delete right;
    left = right = NULL;
  }

  void updateSize() {
    if (isEmpty()) size = 0;
    else size = 1 + left->size + right->size;
    if (parent != NULL) parent->updateSize();
  }
  
public:
  //constructors
  /* Pre: true */
  /* Post: the result is a binary tree without any element */
  BinaryTree() {
    left = right = parent = NULL;
    updateSize();
  }
  
  /* Pre: true */
  /* Post: the implicit parameter is a deep copy of the binary tree given as parameter */
  BinaryTree(const BinaryTree<T> &t) {
    if (t.isEmpty()) {
      left = right = parent = NULL;
    } else {
      root = t.getRoot();
      left = new BinaryTree<T> (t.getLeft());
      right = new BinaryTree<T> (t.getRight());
      parent = NULL;
      left->parent = this;
      right->parent = this;
    }
    updateSize();
  }
  
  /* Pre: true */
  /* Post: the implicit parameter is a binary tree with a copy of x as root and
     deep copies of left and right as direct subtrees */
  BinaryTree(const T &root,const BinaryTree<T> &left,const BinaryTree<T> &right) {
    this->root = root;
    this->left = new BinaryTree<T> (left);
    this->right = new BinaryTree<T> (right);
    this->left->parent = this;
    this->right->parent = this;
    this->parent = NULL;
    updateSize();
  }

  // destructor: automatically deletes the memory pointed directly
  // or indirectly by the attributes.
  ~BinaryTree() {
    deleteChildren();
  }

  // modifiers
  /* Pre: true */
  /* Post: the implicit parameter represents an empty tree */
  void makeEmpty() {
    if (!isEmpty()) {
      delete left;
      delete right;
      left = right = NULL;
    }
    updateSize();
  }
  /* Pre: true */
  /* Post: the implicit parameter is a deep copy of t, and is returned.  */
  BinaryTree<T>& operator=(const BinaryTree<T> &t) {
    if (this != &t) {
      if (t.isEmpty()) {
	deleteChildren();
      } else {
	BinaryTree<T> *newleft = new BinaryTree<T> (t.getLeft());
	BinaryTree<T> *newright = new BinaryTree<T> (t.getRight());
	deleteChildren();
	root = t.getRoot();
	left = newleft;
	right = newright;
	left->parent = this;
	right->parent = this;
      }
    }
    updateSize();
    return (*this);
  }

  int& getSize() {
    return size;
  }

  // getters
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the root of the implicit parameter */
  T& getRoot() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getRoot' over an empty tree."<<std::endl;
      exit(1);
    }
    return root;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the root of the implicit parameter (constant version)*/
  const T& getRoot() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getRoot' over an empty tree."<<std::endl;
      exit(1);
    }
    return root;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the left child of the implicit parameter */
  BinaryTree<T> &getLeft() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getLeft' over an empty tree."<<std::endl;
      exit(1);
    }
    return *left;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the left child of the implicit parameter (constant version)*/
  const BinaryTree<T> &getLeft() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'getLeft' over an empty tree."<<std::endl;
      exit(1);
    }
    return *left;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the right child of the implicit parameter */
  BinaryTree<T> &getRight() {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'right' over an empty tree."<<std::endl;
      exit(1);
    }
    return *right;
  }
  /* Pre: the implicit parameter is not empty */
  /* Post: the result is a reference to the right child of the implicit parameter (constant version)*/
  const BinaryTree<T> &getRight() const {
    if (isEmpty()) {
      std::cout<<"ERROR - Operation 'right' over an empty tree."<<std::endl;
      exit(1);
    }
    return *right;
  }

  /* Pre: true */
  /* Post: the result is true iff the implicit parameter represents an empty tree */
  bool isEmpty() const {
    return (left == NULL) and (right == NULL);
  }

  /* Pre: true */
  /* Post: the result is true iff the implicit parameter has a parent tree */
  bool hasParent() const {
    return parent != NULL;
  }

  /* Pre: the implicit parameter has a parent tree */
  /* Post: the result is a reference to the parent tree of the implicit parameter */
  BinaryTree<T> &getParent() {
    if (not hasParent()) {
      std::cout<<"ERROR - Operation 'getParent' over a tree without parent."<<std::endl;
      exit(1);
    }
    return *parent;
  }

  /* Pre: the implicit parameter has a parent tree */
  /* Post: the result is a reference to the parent tree of the implicit parameter (constant version) */
  const BinaryTree<T> &getParent() const {
    if (not hasParent()) {
      std::cout<<"ERROR - Operation 'getParent' over a tree without parent."<<std::endl;
      exit(1);
    }
    return *parent;
  }
  
  // writing operator <<
  /* Pre: true */
  /* Post: an intendedly pretty representation of a is written on os */
  template <class U> friend std::ostream& operator<<(std::ostream &os, const BinaryTree<U> &t);

  // reading operator >>
  // Pre: 'is' contains a representation given in postorder of a binary tree.
  //      first, the number of nodes is given. Next, for each node,
  //      its kept value and a number interpreted as follows:
  //      -1 means it just has one left child
  //      0 means it has no children at all
  //      1 means it just has one right child
  //      2 menas it has two children
  // Post: a is assigned the tree value read from 'is'
  template <class U> friend std::istream& operator>>(std::istream &is, BinaryTree<U> &t);
};


/// ============================================== ///
///           Implementation friend operations     ///

// Auxiliar function for writing operation <<
/* Pre: true */
/* Post: t is pretty written on os, and each line is preceded by string pre */
template <class T>
void op_write_BinaryTree(std::ostream &os, const BinaryTree<T> &t, std::string pre) {
  if (t.isEmpty()) 
    os << ".";
  else {
    os << "["<< t.getRoot() << "]\n" << pre << " \\__";
    op_write_BinaryTree(os, t.getRight(), pre+" |  ");
    os << "\n" << pre << " \\__";
    op_write_BinaryTree(os, t.getLeft(), pre+"    ");
  }
}

template <class T>
std::ostream& operator<<(std::ostream &os, const BinaryTree<T> &t) {
  op_write_BinaryTree(os, t, "");
  return os;
}

template <class T>
std::istream& operator>>(std::istream &is, BinaryTree<T> &t)
{  
  int size;
  std::stack<BinaryTree<T> > s;

  is >> size;  
  while (size > 0) {
    T node;
    int numchildren; // 0: zero, -1: only left, 1: only right, 2: two
    is >> node >> numchildren;
    if (numchildren == 0) {
      s.push(BinaryTree<T>(node, BinaryTree<T>(), BinaryTree<T>()));
    } else if (numchildren == -1) {
      BinaryTree<T> left = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, left, BinaryTree<T>()));
    } else if (numchildren == 1) {
      BinaryTree<T> right = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, BinaryTree<T>(), right));
    } else {
      BinaryTree<T> right = s.top();
      s.pop();
      BinaryTree<T> left = s.top();
      s.pop();
      s.push(BinaryTree<T>(node, left, right));
    }
    --size;
  }
  if (not s.empty()) t = s.top();
  return is;
}

// New operations added by Guille:

template<typename T>
void readStringTree(int &itoken,const std::vector<std::pair<std::string,std::string> > &vtoken,BinaryTree<T> &t)
{
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="value") {
    t=BinaryTree<T>();
    return;
  }
  std::istringstream mycin(vtoken[itoken].second);
  T value;
  mycin>>value;
  t=BinaryTree<T>(value, BinaryTree<T>(), BinaryTree<T>());
  itoken++;
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!="(") return;
  itoken++;
  //BinaryTree<T> left;
  readStringTree(itoken,vtoken,t.getLeft());
  if (itoken>=int(vtoken.size()) or vtoken[itoken].first!=",") {
    //t=BinaryTree<T>(value,left,BinaryTree<T>());
    t.getRight()=BinaryTree<T>();
    if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
      itoken++;
    return;
  }
  itoken++;
  //BinaryTree<T> right;
  readStringTree(itoken,vtoken,t.getRight());
  if (itoken<int(vtoken.size()) and vtoken[itoken].first==")")
    itoken++;
  //t=BinaryTree<T>(value,left,right);
}

template<typename T>
void readStringTree(const std::string &s,BinaryTree<T> &t)
{
  std::vector<std::pair<std::string,std::string> > vtoken;
  int iant=0;
  for (int i=0;i<int(s.size());i++) {
    if (s[i]==',' or s[i]=='(' or s[i]==')') {
      if (iant<i)
	vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant,i-iant)));
      iant=i+1;
      vtoken.push_back(std::pair<std::string,std::string> (std::string(1,s[i]),""));
    }
  }
  if (iant<int(s.size()))
    vtoken.push_back(std::pair<std::string,std::string> ("value",s.substr(iant)));
  int itoken=0;
  readStringTree(itoken,vtoken,t);
}

template<typename T>
void writeStringTreeRec(std::ostream &os,const BinaryTree<T> &t)
{
  if (t.isEmpty()) return;
  os<<t.getRoot();
  const BinaryTree<T> &left=t.getLeft();
  const BinaryTree<T> &right=t.getRight();
  if (left.isEmpty() and right.isEmpty()) return;
  os<<"(";
  writeStringTreeRec(os,left);
  os<<",";
  writeStringTreeRec(os,right);
  os<<")";
}

template<typename T>
void writeStringTree(std::ostream &os,const BinaryTree<T> &t)
{
  if (t.isEmpty()) {
    os<<"()";
    return;
  }
  writeStringTreeRec(os,t);
}



#endif

//Lekha Adari
//June 30, 2017

#include <cstdlib>
#include "express.h"
#include <iostream>

// CONSTRUCTORS and DESTRUCTOR
ExpressionTree::ExpressionTree(double value){
  data = 0.0;
  operation = '\0';
  if (value != 0)
    data = value;
  left = NULL;
  right = NULL;
}
//Postcondition: The ExpressionTree has one leaf node with the specified value.
//The default argument is 0.0

ExpressionTree::ExpressionTree(const ExpressionTree& source){
  if (source.left == NULL && source.right == NULL){
    data = source.data;
    operation = '\0';
    left = NULL;
    right = NULL;
  }
  else{
    data = source.data;
    operation = source.operation;
    left = new ExpressionTree(*(source.left));
    right = new ExpressionTree(*(source.right));
  }
}


ExpressionTree::~ExpressionTree(){
  delete left;
  delete right;
}

// ASSIGNMENT OPERATOR
ExpressionTree& ExpressionTree::operator =(const ExpressionTree& source){
  if (source.left == NULL && source.right == NULL){
    data = source.data;
    operation = '\0';
    left = NULL;
    right = NULL;
  }
  else{
    data = source.data;
    operation = source.operation;
    left = new ExpressionTree(*(source.left));
    right = new ExpressionTree(*(source.right));
  }
}
// CONSTANT MEMBER FUNCTIONS
double ExpressionTree::evaluate() const{
  if (left == NULL && right == NULL)
    return data;
  else{
    if (operation == '+')
      return left->evaluate() + right->evaluate();
    else
      return left->evaluate() * right->evaluate();
  }
}
//Postcondition: The return value is the value of the expression tree.

void ExpressionTree::printPre() const{
  ExpressionTree *l = left;
  ExpressionTree *r = right;
  if (l != NULL && r != NULL){
    std::cout << operation << " ";
    l->printPre();
    r->printPre();
  }
  if (data != 0)
    std::cout << data << " ";
}
//Postcondition: The expression is printed in prefix form to standard output

void ExpressionTree::printPost() const{
  if (data != 0)
    std::cout << data << " ";
  ExpressionTree *l = left;
  ExpressionTree *r = right;
  if (l != NULL && r != NULL){
    l->printPost();
    r->printPost();
    std::cout << operation << " ";
  }
}
//Postcondition: The expression is printed in postfix form to standard output

void ExpressionTree::printIn() const{
  if (data != 0)
    std::cout << data << " ";
  ExpressionTree *l = left;
  ExpressionTree *r = right;
  if (l != NULL && r != NULL){
    if (operation == '+')
      std::cout << "( ";
    l->printIn();
    std::cout << operation << " ";
    r->printIn();
    if (operation == '+')
      std::cout << ") ";
  }
}
//Postcondition: The expression is printed in infix form to standard output
//with add operations enclosed in parantheses

// NONMEMBER FUNCTIONS FOR BUILDING BIGGER EXPRESSION TREES:
ExpressionTree operator +(const ExpressionTree& e1, const ExpressionTree& e2){
  ExpressionTree *a = new ExpressionTree;
  a->operation = '+';
  a->left = new ExpressionTree(e1);
  a->right = new ExpressionTree(e2);
  return *a;
}
//The ExpressionTree returned has '+' at the root, e1 as the left subtree, and
//e2 as the right subtree

ExpressionTree operator *(const ExpressionTree& e1, const ExpressionTree& e2){
  ExpressionTree *m = new ExpressionTree;
  m->operation = '*';
  m->left = new ExpressionTree(e1);
  m->right = new ExpressionTree(e2);
  return *m;
  
}
//The ExpressionTree returned has '*' at the root, e1 as the left subtree, and
//e2 as the right subtree


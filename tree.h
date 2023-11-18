#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>
#include <fstream> 

Node* buildTree(Node* node, const std::string &str); 
void printPreorder(Node* node, std::ofstream &output, int level = 0);
void printPostorder(Node* node, std::ofstream &output, int level = 0);
void printInorder(Node* node, std::ofstream &output, int level = 0);
 

#endif 

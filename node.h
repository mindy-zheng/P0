#ifndef NODE_H
#define NODE_H

#include <set>
#include <string> 

struct Node {
	int length; // length of the strings
	std::set<std::string> unique_str; // stores unique strings 
	Node *left; // Pointer to the left child 
	Node *right; // Pointer to the right children 
}; 

#endif // header file 

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include <iomanip>
#include"BinaryHeap.h"
	
using namespace std;

class BinaryTree
{
	private:
	BinaryTree *left;
	BinaryTree *right;
	char ch;
	int count;

	public:
	BinaryTree(){
		count=0;
		left=NULL;
		right=NULL;
	}
	BinaryTree(char character, int counting, BinaryTree *l, BinaryTree *r): ch(character),count(counting),left(l),right(r) {}
        BinaryTree *getLeftPtr(){
		return left;
	}
	BinaryTree *getRightPtr(){
		return right;
	}
	char getChar()const{
		return ch;
	}
	int getCount() const {
		return count;
	}
	void setChar(char c){
		ch=c;
	}
	void setCount(int i){
		count=i;
	}
	
	bool operator <(const BinaryTree &rhs){
		return count<rhs.getCount();
	}
	void print(char encode[],int localcount){
		if(left){
			encode[localcount] = '0';
			left->print(encode,localcount+1);
		}
		if(right){
			encode[localcount] = '1';
			right->print(encode,localcount+1);
		}
		else{
			cout<<ch<<setw(5)<<count<<" ";
			for(int i=0;i<localcount;i++){
				cout<<encode[i];
			}
			cout<<endl;
		}
	}
			

};//done with BinaryTree

class BinaryTreePtr{
	BinaryTree *p;
	public:
	BinaryTreePtr(){p=NULL;}
	BinaryTreePtr(BinaryTree *Bptr):p(Bptr){}
	void setPtr(BinaryTree *ptr){p=ptr;}
	BinaryTree* getTreePtr()const{
		return p;
	}
	bool operator<(const BinaryTreePtr &rhs)const{
		return *p<*(rhs.getTreePtr());
	}	
};

#endif

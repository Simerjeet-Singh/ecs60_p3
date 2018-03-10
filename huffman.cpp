#include<iostream>
#include"BinaryTree.h"
#include"BinaryHeap.h"
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
        char characters[256];
        int list[256] = {}; //initialize array with 0's
	BinaryTreePtr p;
	BinaryHeap<BinaryTreePtr> heap(256);
        ifstream file(argv[1]);
	char cha;
        while(file>>noskipws>>cha)
        {
                list[int(cha)]++;
        }
        for(int i=0;i<=255;i++){
	       if(list[i]!=0){
	       BinaryTree *tree = new BinaryTree(char(i),list[i],NULL,NULL);
	       heap.insert(BinaryTreePtr(tree));//change if needed to BTreePtr(tree)
	       }
	}
	BinaryTreePtr left, right;
	while(!heap.isEmpty()){
		left = heap.findMin();
		heap.deleteMin();
		if(heap.isEmpty())
			break;
		else{
		right = heap.findMin();
		heap.deleteMin();
		int leftCount = left.getTreePtr()->getCount();
		int rightCount = right.getTreePtr()->getCount();
		BinaryTree *tree = new BinaryTree(char(0),leftCount+rightCount,left.getTreePtr(),right.getTreePtr());
		heap.insert(BinaryTreePtr(tree));
		}
	}
	left.getTreePtr()->print(characters,0);
}

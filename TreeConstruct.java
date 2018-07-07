import java.util.*;

/*
 * Code to find the cousins of a node in a binary tree
*/

class TreeConstruct{
	public static void main(String args[]){
		BinaryTree root = new BinaryTree(2);
		root.L = new BinaryTree(5);
		root.R = new BinaryTree(6);
		root.L.L = new BinaryTree(7);
		root.L.R = new BinaryTree(8);
		
		root.R.L = new BinaryTree(9);
		root.R.R = new BinaryTree(10);
		
		root.R.R.R = new BinaryTree(11);
		
		//new TreeConstruct().display(root, 0);
		TreeConstruct ob = new TreeConstruct();
		int level = ob.findLevel(root, 10, 0);
		if(level == -1)
			return;
		int parent = ob.findParent(root, 10);
		System.out.println("LEVEL: "+level);
		System.out.println("PARENT: "+parent);
		
		List<Integer> cousins = new ArrayList<Integer>();
		ob.getCousins(root, level, parent, cousins, 0, root);
		System.out.print("COUSINS: ");
		for(Integer i: cousins){
			System.out.print(i+" ");
		}
		System.out.println();
	} 
	
	void display(BinaryTree node, int level){
		if(node == null) return;
		System.out.println(node.data+" LEVEL "+level);
		display(node.L, level+1);
		display(node.R, level+1);
	}
	
	int findLevel(BinaryTree node, int v, int currLevel){
		if(node == null) return -1;
		if(node.data == v) return currLevel;
		int left = findLevel(node.L,v, currLevel+1);
		if(left != -1) return left;
		int right = findLevel(node.R,v, currLevel+1);
		if(right != -1) return right;
		
		return -1;
	}
	
	int findParent(BinaryTree node, int v){
		if(node == null) return -1;
		if(node.L != null && node.L.data == v) return node.data;
		if(node.R != null && node.R.data == v) return node.data;
		int left = findParent(node.L, v);
		if(left != -1) return left;
		int right = findParent(node.R, v);
		if(right != -1) return right; 
		return -1;
	}
	
	void getCousins(BinaryTree node, int level, int parent, List<Integer> cousins, int currLevel, BinaryTree root){
		if(node == null) return;
		if(currLevel == level && findParent(root, node.data)!=parent) cousins.add(node.data);
		getCousins(node.L, level, parent, cousins, currLevel+1, root);
		getCousins(node.R, level, parent, cousins, currLevel+1, root);
	}
}


class BinaryTree{
	int data;
	BinaryTree L;
	BinaryTree R;
	BinaryTree(int data){
		this.data = data;
		this.L = null;
		this.R = null;
	}
}

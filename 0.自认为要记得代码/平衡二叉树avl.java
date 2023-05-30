package dfseasy55平衡二叉树;

import dfseasy563二叉树的坡度.TreeNode;

public class Main1 {
	/*
	思路：
	1.递归统计左右子树的高度
	2.相减是否失衡，若是就标记，并且在每一层递归都返回
	*/
	boolean not = true;
    public boolean isBalanced(TreeNode root) {
    	// 空节点，竟然返回true？
    	if(root == null){
    		return true;
    	}
    	dfs(root);
    	return not;
    }
    public int dfs(TreeNode root){
    	// 已经找到不平衡，退出，不要再进行递归了，当左子树发生不平滑，就不要递归右子树了。
    	if(!not){
    		return 0;
    	}
    	// 空节点
    	if(root == null){
    		return 0;
    	}
    	// 叶子节点
    	if(root.left == null && root.right == null){
    		return 1;
    	}
    	int l = dfs(root.left);
    	int r = dfs(root.right);
    	if(Math.abs(l - r) > 1){
    		not = false;
    	}
    	return Math.max(l, r) + 1;
    }
	public static void main(String[] args) {
		Main1 m1 = new Main1();
		TreeNode root = new TreeNode(3);
		root.left = new TreeNode(9);
		root.right = new TreeNode(20);
		root.right.right = new TreeNode(20);
		
		root.right.left = new TreeNode(15);
		root.right.right = new TreeNode(7);
		root.right.right.right = new TreeNode(7);
		root.right.right.right.right = new TreeNode(7);
		root.right.right.right.right.right = new TreeNode(7);
		
		boolean bln = m1.isBalanced(root);
		System.out.println(bln);
	}
}

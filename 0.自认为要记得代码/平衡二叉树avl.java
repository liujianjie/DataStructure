package dfseasy55ƽ�������;

import dfseasy563���������¶�.TreeNode;

public class Main1 {
	/*
	˼·��
	1.�ݹ�ͳ�����������ĸ߶�
	2.����Ƿ�ʧ�⣬���Ǿͱ�ǣ�������ÿһ��ݹ鶼����
	*/
	boolean not = true;
    public boolean isBalanced(TreeNode root) {
    	// �սڵ㣬��Ȼ����true��
    	if(root == null){
    		return true;
    	}
    	dfs(root);
    	return not;
    }
    public int dfs(TreeNode root){
    	// �Ѿ��ҵ���ƽ�⣬�˳�����Ҫ�ٽ��еݹ��ˣ���������������ƽ�����Ͳ�Ҫ�ݹ��������ˡ�
    	if(!not){
    		return 0;
    	}
    	// �սڵ�
    	if(root == null){
    		return 0;
    	}
    	// Ҷ�ӽڵ�
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

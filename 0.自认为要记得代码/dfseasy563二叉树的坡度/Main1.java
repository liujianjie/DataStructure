package dfseasy563二叉树的坡度;

public class Main1 {
	int allsum;
    public int findTilt(TreeNode root) {
    	if(root == null){
    		return 0;
    	}
    	find(root);
    	return allsum;
    }
    public int find(TreeNode root){
    	// 出口
    	if(root == null){
    		return 0;
    	}
    	// 到达叶子节点
    	if(root.left == null && root.right == null){
    		return root.val;
    	}
    	int l = find(root.left);
    	int r = find(root.right);
    	// 计算坡度
    	int po = Math.abs(l - r);
    	// 统计坡度
    	allsum += po;// 加上坡度
    	// 重新设置这个节点的值，为子节点总和
    	root.val = l + r + root.val;
    	// 返回自己
    	return root.val;
    }
    public static void main(String[] args) {
		Main1 m1 = new Main1();
		TreeNode root = new TreeNode(4);
		root.left = new TreeNode(2);
		root.right = new TreeNode(9);
		root.left.left = new TreeNode(3);
		root.left.right = new TreeNode(5);
		
		root.right.right = new TreeNode(7);
		int sum = m1.findTilt(root);
		System.out.println(sum);
	}
}

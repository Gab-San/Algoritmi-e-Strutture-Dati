package Trees;

public class TreeNode {
    private int key;
    private TreeNode left;
    private TreeNode right;
    private TreeNode parent;
    public int getKey(){
        return key;
    }
    public TreeNode getLeft(){
        return left;
    }

    public TreeNode getRight(){
        return right;
    }
    public TreeNode setLeft(TreeNode leftChild){
        this.left = leftChild;
        return this;
    }
    public TreeNode setRight(TreeNode rightChild){
        this.right = rightChild;
        return this;
    }

    public TreeNode setKey(int key) {
        this.key = key;
        return this;
    }

    public TreeNode getParent() {
        return parent;
    }

    public TreeNode setParent(TreeNode parent) {
        this.parent = parent;
        return this;
    }

    @Override
    public String toString() {
        return String.valueOf(this.getKey());
    }
}

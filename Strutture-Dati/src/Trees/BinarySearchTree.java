package Trees;

import java.util.Random;

/**
 * Composto da:
 *      - Radice
 *      - Foglie
 *      - Nodi interni (che possono essere considerati padri o figli in base al livello dell'albero considerato)
 * Il nodo Radice è l'unico nodo senza padre.
 * Un albero binario è tale se per ogni suo nodo x:
 *      - se y è un nodo destro allora y.key >= x.key
 *      - se y è un nodo sinistro allora y.key <= x.key
 */
public class BinarySearchTree {
    private TreeNode root = null;

    /**
     * Controlla prima tutti i nodi del sottoalbero sinistro,poi la radice e poi tutto il sottoalbero destro.
     * @param subTreeRoot il nodo che sarà nodo radice del sottoalbero per definizione ricorsiva
     * @complexity O(n), in quanto tutti i nodi sono toccati una volta sola
     */
    public static void inOrderSearch(TreeNode subTreeRoot){
        if (subTreeRoot == null){
            return;
        }
        inOrderSearch(subTreeRoot.getLeft());
        System.out.println(subTreeRoot.getKey());
        inOrderSearch(subTreeRoot.getRight());
    }

    /**
     * Partendo dalla radice sono controllati tutti i nodi sinistri, poi tutti i nodi appartenenti ai sottoalberi destri.
     * @param subTreeRoot il nodo che sarà nodo radice del sottoalbero per definizione ricorsiva
     * @complexity O(n), in quanto tutti i nodi sono toccati una volta sola
     */
    public static void preOrderSearch(TreeNode subTreeRoot){
        if (subTreeRoot == null){
            return;
        }
        System.out.println(subTreeRoot.getKey());
        preOrderSearch(subTreeRoot.getLeft());
        preOrderSearch(subTreeRoot.getRight());
    }

    /**
     * Si visita prima il sottoalbero sinistro e poi il sottoalbero destro e infine la radice
     * @param subTreeRoot il nodo che sarà nodo radice del sottoalbero per definizione ricorsiva
     * @complexity O(n), in quanto tutti i nodi sono toccati una volta sola
     */
    public static void postOrderSearch(TreeNode subTreeRoot){
        if (subTreeRoot == null){
            return;
        }
        postOrderSearch(subTreeRoot.getLeft());
        postOrderSearch(subTreeRoot.getRight());
        System.out.println(subTreeRoot.getKey());
    }

    /**
     * Inserisce un elemento nell'albero
     * @param value elemento da aggiungere
     * @return l'albero stesso
     * @complexity O(h) con h altezza dell'albero
     */
    public BinarySearchTree insert(int value){
        TreeNode copyElem = new TreeNode().setKey(value);
        TreeNode prev = null;
        TreeNode curr = this.root;
        while (curr != null){
            prev = curr;
            if(copyElem.getKey() < curr.getKey()){
                curr = curr.getLeft();
            } else {
                curr = curr.getRight();
            }
        }

        copyElem.setParent(prev);
        if (prev == null) {
            this.root = copyElem;
        } else if (copyElem.getKey() < prev.getKey()){
            prev.setLeft(copyElem);
        } else {
            prev.setRight(copyElem);
        }
        return this;
    }

    public static BinarySearchTree createTree(int nodesNumber, int lowerBound, int upperBound){
        Random random = new Random();
        int[] array = random.ints(nodesNumber,lowerBound,upperBound).toArray();
        BinarySearchTree bst = new BinarySearchTree();
        for(int i : array){
            bst.insert(i);
        }
        return bst;
    }

    public TreeNode getRoot() {
        return root;
    }

    /**
     * Cerca una chiave all'interno dell'albero
     * @param subTreeRoot la radice dell'albero (utilizzato per chiamate ricorsive)
     * @param value la chiave da cercare
     * @return il primo nodo con la chiave corrispondente
     *
     * @complexity se l'albero è ben bilanciato O(log(n)), altrimenti O(n). In generale O(h) con h altezza dell'albero
     */
    public TreeNode search(TreeNode subTreeRoot, int value){
        if(subTreeRoot == null || subTreeRoot.getKey() == value){
            return subTreeRoot;
        }

        if (subTreeRoot.getKey() < value){
            return this.search(subTreeRoot.getRight(), value);
        } else {
            return this.search(subTreeRoot.getLeft(), value);
        }
    }


    // Complessità O(h)
    public TreeNode min(){
        return min(this.root);
    }

    public TreeNode min(TreeNode subTreeRoot){
        TreeNode curr = subTreeRoot;
        while (curr.getLeft() != null){
            curr = curr.getLeft();
        }
        return curr;
    }

    public TreeNode max(){
        return max(this.root);
    }

    // Complessità O(h)
    public TreeNode max(TreeNode subTreeRoot){
        TreeNode curr = subTreeRoot;
        while (curr.getRight() != null){
            curr = curr.getRight();
        }
        return curr;
    }

    /**
     * Il successore di un elemento x è l'elemento y con la più piccola chiave y.key > x.key
     * presente nel BST
     * @param elem di cui cercare il successore
     * @return il successore
     */
    public TreeNode successor(TreeNode elem){
        // Cerca il minimo del sottoalbero destro; ovvero il più piccolo nodo
        // a destra dell'elemento analizzato
        if(elem.getRight() != null){
            return min(elem.getRight());
        }
        // Risale nell'albero finchè non incontra un nodo che ha soli figli sinistri
        // oppure la radice
        TreeNode parent = elem.getParent();
        while(parent != null && parent.getRight() == elem){
            elem = parent;
            parent = parent.getParent();
        }
        return parent;
    }


    /**
     * 1. Se un elemento non ha figli allora è una foglia e può essere deallocato
     * 2. Se l'elemento ha un figlio allora dev'essere sostituito dal figlio all'interno dell'albero
     * 3. Se l'elemento ha due figli allora si salva la chiave del successore e si elimina il successore; il successore
     * di un elemento con due figli non ha mai il figlio sinistro --> CASO 2
     * @param selectedNode il nodo da eliminare
     * @return l'albero
     */
    public BinarySearchTree delete(TreeNode selectedNode){
        TreeNode nodeToDelete, subTree = null;
        // CASO 1 e 2: L'elemento da cancellare non ha figli, oppure ne ha solo uno
        if (selectedNode.getLeft() == null || selectedNode.getRight() == null){
            nodeToDelete = selectedNode;
        } else {
        // Caso 3: sono presenti entrambi i figli
            nodeToDelete = this.successor(selectedNode);
        }

        // Selezione del sottoalbero da spostare
        if (nodeToDelete.getLeft() != null){
            subTree = nodeToDelete.getLeft();
        } else {
            subTree = nodeToDelete.getRight();
        }

        // NON SI È NEL CASO 1: vi è almeno un figlio, allora si procede
        // a impostare il padre del nuovo sottoalbero
        if (subTree != null){
            subTree.setParent(nodeToDelete.getParent());
        }

        // Se l'elemento selezionato è la radice
        if (nodeToDelete.getParent() == null){
            this.root = subTree;
        } else if(nodeToDelete == nodeToDelete.getParent().getLeft()) {
        // Se il nodo da eliminare è il figlio sinistro
        // allora lega al padre il figlio del nodo da eliminare
            nodeToDelete.getParent().setLeft(subTree);
        } else {
        // Se il nodo da eliminare è il figlio destro
        // allora lo sostituisce con il figlio del nodo da eliminare
            nodeToDelete.getParent().setRight(subTree);
        }

        if(nodeToDelete != selectedNode){
            selectedNode.setKey(nodeToDelete.getKey());
        }
        return this;
    }

}

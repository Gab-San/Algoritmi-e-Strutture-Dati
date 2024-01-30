package Nodes;

public class Node<T> {
    private T key;
    private Node<T> next;
    private Node<T> prev;

    public Node (T key, Node<T> next, Node<T> prev){
        this.key = key;
        this.next = next;
        this.prev = prev;
    }
    public Node(T key, Node<T> next){
        this(key, next, null);
    }

    public Node<T> setKey (T newKey){
        this.key = newKey;
        return this;
    }

    public Node<T> setNext(Node<T> next){
        this.next = next;
        return this;
    }

    public Node<T> setPrev(Node<T> prev){
        this.prev = prev;
        return this;
    }

    public T getKey(){
        return key;
    }

    public Node<T> getNext(){
        return next;
    }

    public Node<T> getPrev(){
        return prev;
    }
}

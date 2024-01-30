package Deque;

import Nodes.Node;

/**
 * Implementazione per mezzo di una lista doppiamente concatenata
 * @param <T>
 */
public class ListDeque<T> implements MyDeque<T> {
    Node<T> dequeHead;
    Node<T> dequeTail;
    public ListDeque () {
        // È necessaria una prima istanziazione e poi il linking
        dequeHead = new Node<>(null, null);
        dequeTail = new Node<>(null, null, dequeHead);
        // Linking degli elementi
        dequeHead.setNext(dequeTail);
    }

    @Override
    public MyDeque<T> pushFront(T elem) {
        Node<T> newElem = new Node<>(elem, dequeHead.getNext(), dequeHead);
        dequeHead.setNext(newElem);
        newElem.getNext().setPrev(newElem);
        return this;
    }

    @Override
    public MyDeque<T> pushBack(T elem) {
        Node<T> newElem = new Node<>(elem, dequeTail, dequeTail.getPrev());
        dequeTail.setPrev(newElem);
        newElem.getPrev().setNext(newElem);
        return this;
    }

    @Override
    public T popFront() {
        if(isEmpty()){
            System.out.println("Empty Deque");
            return null;
        }
        Node<T> poppedElement = dequeHead.getNext();
        dequeHead.setNext(poppedElement.getNext());
        // Re-link del nuovo primo elemento alla testa
        poppedElement.getNext().setPrev(dequeHead);
        poppedElement.setNext(null).setPrev(null);
        return poppedElement.getKey();
    }

    @Override
    public T popBack() {
        if(isEmpty()){
            System.out.println("Empty Deque");
            return null;
        }
        Node<T> poppedElement = dequeTail.getPrev();
        dequeTail.setPrev(poppedElement.getPrev());
        // Re-link del nuovo ultimo elemento alla coda
        poppedElement.getPrev().setNext(dequeTail);
        poppedElement.setNext(null).setPrev(null);
        return poppedElement.getKey();
    }

    @Override
    public boolean isEmpty() {
        return dequeHead.getNext() == dequeTail;
    }

    @Override
    public String toString(){
        StringBuilder dequeToString = null;
        for(Node<T> curr = dequeHead.getNext(); curr != dequeTail; curr = curr.getNext()) {
            dequeToString = (dequeToString == null ? new StringBuilder() : dequeToString).append(curr.getKey().toString()).append(" ");
        }
        return dequeToString == null ? "Empty" : dequeToString.toString();
    }

}

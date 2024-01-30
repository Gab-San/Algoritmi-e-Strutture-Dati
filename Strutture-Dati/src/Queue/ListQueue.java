package Queue;

import Nodes.Node;

public class ListQueue<T> extends Coda<T> {
    private Node<T> queueHead;
    private Node<T> queueTail;

    public Coda<T> enqueue(T elem){
        if(queueHead == null){
            queueTail = new Node<>(null, null);
            queueHead = new Node<>(elem, queueTail);
            return this;
        }

        Node<T> newElem = new Node<>(null, null);
        queueTail.setKey(elem);
        queueTail.setNext(newElem);
        queueTail = newElem;

        return this;
    }

    public T dequeue(){
        if(isEmpty()){
            return null;
        }
        Node<T> dequeuedNode = queueHead;
        queueHead = queueHead.getNext();
        dequeuedNode.setNext(null);
        return dequeuedNode.getKey();
    }

    public boolean isEmpty(){
        return queueHead == queueTail;
    }

    @Override
    public String toString() {
        StringBuilder queueToString = null;
        for(Node<T> curr = queueHead; curr != queueTail; curr = curr.getNext()){
            queueToString = (queueToString == null ? new StringBuilder() : queueToString)
                    .append(curr.getKey()).append(" ");
        }
        return queueToString == null ? "Empty" : queueToString.toString();
    }
}

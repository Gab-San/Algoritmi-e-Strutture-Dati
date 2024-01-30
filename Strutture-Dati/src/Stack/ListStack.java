package Stack;
import Nodes.Node;

public class ListStack<T> implements PStack<T> {
    private Node<T> stackPointer = null;
    public PStack<T> push(T elem){
        if(stackPointer == null){
              stackPointer = new Node<>(elem, null);
              return this;
        }

        Node<T> newEl = new Node<>(elem, stackPointer);
        stackPointer = newEl;
        return this;
    }

    public T pop(){
        if(isEmpty()){
            return null;
        }
        Node<T> poppedElem = stackPointer;
        stackPointer = stackPointer.getNext();
        poppedElem.setNext(null);
        return poppedElem.getKey();
    }

    public boolean isEmpty(){
        return stackPointer == null;
    }

    @Override
    public String toString() {
        StringBuilder stackToString = null;
        for(Node<T> curr = stackPointer; curr != null; curr = curr.getNext()){
            stackToString = (stackToString == null ? new StringBuilder() : stackToString)
                    .append(curr.getKey().toString())
                    .append(" ");
        }
        return (stackToString == null) ? "Empty" : stackToString.toString();
    }
}

package Queue;

import java.util.*;

public class ArrayQueue<T> implements Coda<T> {
    List<T> queue = new ArrayList<>();
    public Coda<T> enqueue(T elem){
        queue.add(elem);
        return this;
    }

    public T dequeue(){
        try {
            return queue.removeFirst();
        } catch(NoSuchElementException expt){
            System.out.println("The queue is empty");
            return null;
        }

    }

    public boolean isEmpty(){
        return queue.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder queueToString = null;
        for(T elem: queue){
            queueToString = (queueToString == null ? new StringBuilder() : queueToString)
                    .append(elem.toString())
                    .append(" ");
        }
        return queueToString == null ? "Empty" : queueToString.toString();
    }
}

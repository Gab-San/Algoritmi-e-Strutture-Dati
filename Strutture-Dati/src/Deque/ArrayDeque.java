package Deque;

import java.util.*;

public class ArrayDeque<T> implements MyDeque<T> {

    List<T> deque = new ArrayList<>();
    @Override
    public MyDeque<T> pushFront(T elem) {
        deque.addFirst(elem);
        return this;
    }

    @Override
    public MyDeque<T> pushBack(T elem) {
        deque.addLast(elem);
        return this;
    }

    @Override
    public T popFront() {
        try{
            return deque.removeFirst();
        } catch (NoSuchElementException expt){
            System.out.println("Empty Deque");
            return null;
        }
    }

    @Override
    public T popBack() {
        try{
            return deque.removeLast();
        } catch(NoSuchElementException expt){
            System.out.println("Empty Deque");
            return null;
        }
    }

    @Override
    public boolean isEmpty() {
        return deque.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder dequeToString = null;
        for(T elem : deque){
            dequeToString = (dequeToString  == null ? new StringBuilder() : dequeToString).append(elem.toString()).append(" ");
        }
        return dequeToString == null ? "Empty" : dequeToString.toString();
    }
}

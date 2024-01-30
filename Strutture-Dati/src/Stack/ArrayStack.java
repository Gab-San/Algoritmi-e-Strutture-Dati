package Stack;
import java.util.*;

public class ArrayStack<T> extends PStack<T> {
    private List<T> stack = new ArrayList<>();

    public PStack<T> push(T elem) {
        stack.add(elem);
        return this;
    }

    public T pop(){
        try {
            return stack.removeLast();
        }
        catch (NoSuchElementException expt){
            System.out.println("The stack is empty");
            return null;
        }
    }

    public boolean isEmpty(){
        return stack.isEmpty();
    }

    public String toString(){
        StringBuilder stackToString = null;
        int stackSize = stack.size();
        for(int i = stackSize - 1; i >= 0; i--){
            stackToString = (stackToString == null ? new StringBuilder() : stackToString).append(stack.get(i).toString()).append(" ");
        }
        return (stackToString == null) ? "Empty" : stackToString.toString();
    }
}

import Queue.ArrayQueue;
import Queue.Coda;
import Queue.ListQueue;
import Stack.*;


public class Main {
    public static void main(String[] args){
        StackTest();

        System.out.println("-------------------------------------");
        System.out.println("-------------------------------------");

        QueueTest();

        System.out.println("-------------------------------------");
        System.out.println("-------------------------------------");


    }

    private static void QueueTest() {
        Coda<Integer> integerQueue = new ArrayQueue<Integer>();
        System.out.println(integerQueue.isEmpty());
        integerQueue.enqueue(10).enqueue(20).enqueue(40);
        integerQueue.dequeue();
        System.out.println(integerQueue);
        integerQueue.dequeue();
        System.out.println(integerQueue.isEmpty());
        integerQueue.dequeue();
        System.out.println(integerQueue.isEmpty());
        integerQueue.dequeue();
        integerQueue.enqueue(30);

        System.out.println("-------------------------------------");

        integerQueue = new ListQueue<Integer>();
        System.out.println(integerQueue.isEmpty());
        integerQueue.enqueue(20).enqueue(60).enqueue(10);
        System.out.println(integerQueue);

        System.out.println(integerQueue.isEmpty());
        System.out.println(integerQueue.dequeue());
        System.out.println(integerQueue);

    }

    private static void StackTest(){
        PStack<Integer> integerStack = new ArrayStack<Integer>();
        System.out.println(integerStack.isEmpty());
        integerStack.push(10).push(20).push(40);
        System.out.println(integerStack);
        integerStack.pop();
        System.out.println(integerStack);
        integerStack.pop();
        integerStack.pop();
        System.out.println(integerStack);
        System.out.println(integerStack.pop());

        System.out.println("-------------------------------------");

        integerStack = new ListStack<Integer>();
        System.out.println(integerStack.isEmpty());
        integerStack.push(10).push(20).push(40);
        System.out.println(integerStack);
        integerStack.pop();
        integerStack.pop();
        integerStack.pop();
        System.out.println(integerStack.pop());
        System.out.println(integerStack);
    }
}

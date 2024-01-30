package Queue;

/**
 * La coda è una struttura FIFO (First In First Out).
 * Si ipotizza la memoria sia illimitata.
 * @param <T>
 */
public abstract class Coda<T> {
    /**
     * Adds an element to the end of the queue
     * @param elem to add to the queue
     * @return the queue in order to chain multiple calls
     *
     * @complexity list: O(1)/vector: O(1)
     */
    public abstract Coda<T> enqueue(T elem);

    /**
     * Returns the first element of the queue, null if the queue is empty.
     *
     * @return the first element of the queue
     * @complexity list/vector: O(1)
     */
    public abstract T dequeue();

    /**
     * @return true if the queue is empty, false otherwise
     * @complexity list/vector: O(1)
     */
    public abstract boolean isEmpty();
}

package Stack;

/**
 * La pila (stack) è una struttura dati di tipo FILO (First In Last Out)
 *
 * @param <T>
 */

public abstract class PStack<T> {
    /**
     * Tale funzione implementa la push dello stack che permette di
     * aggiungere elementi in cima allo stack (pila)
     * @param elem to add to the stack
     * @return the stack such that it is possible to chain the push calls
     *
     * @complexity list: O(1)/vector: O(1)
     */
    public abstract PStack<T> push(T elem);

    /**
     * @return the last element of the stack
     *
     * @complexity list: O(1)/vector: O(1)
     */
    public abstract T pop();

    /**
     * @return true if the stack is empty, false otherwise
     *
     * @complexity list/vector: O(1)
     */
    public abstract boolean isEmpty();
}

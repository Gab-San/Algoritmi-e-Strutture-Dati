package Deque;

/**
 * È una struttura dati che si comporta come un mazzo di carte. È possibile riempirlo come uno stack o come una coda ed estrarre
 * elementi dalla testa o dalla coda in maniera indifferente.
 */
public interface MyDeque<T> {
    /**
     * Inserisce l'elemento in testa
     * @param elem elemento da inserire
     * @return la struttura dati stessa
     *
     * @complexity vector/list: O(1)
     */
    public MyDeque<T> pushFront(T elem);

    /**
     * Inserisce l'elemento in coda
     * @param elem elemento da inserire
     * @return la struttura dati stessa
     *
     * @complexity vector/list: O(1)
     */
    public MyDeque<T> pushBack(T elem);

    /**
     * @return l'elemento in testa, null se isEmpty == true
     * @complexity vector/list: O(1)
     */
    public T popFront();

    /**
     * @return l'elemento in coda, null se isEmpty == true
     * @complexity vector/list: O(1)
     */
    public T popBack();

    /**
     * @return true se il deque è vuoto, false altrimenti
     */
    public boolean isEmpty();
}

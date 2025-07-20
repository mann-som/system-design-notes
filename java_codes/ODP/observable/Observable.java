package ODP.observable;
import ODP.observer.Observer;

public interface Observable {
    
    public void add(Observer observer);
    public void remove(Observer observer);
    public void notifySubscribers();
    public void setStock(int newStockCount);
    public int getStockCount();
}

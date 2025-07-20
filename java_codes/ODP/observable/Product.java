package ODP.observable;
import ODP.observer.Observer;
import java.util.ArrayList;
import java.util.List;

public class Product implements Observable{
    public List<Observer> observerList = new ArrayList<>();
    public int count = 0;

    @Override
    public void add(Observer observer){
        observerList.add(observer);
    }

    @Override
    public void remove(Observer observer){
        observerList.remove(observer);
    }
    
    @Override
    public void notifySubscribers(){
        for(Observer observer:observerList){
            observer.update();
        }
    }

    public void setStock(int newStockCount){
        if(count == 0){
            notifySubscribers();
        }
        count = count+newStockCount;
    }

    public int getStockCount(){
        return count;
    }
}

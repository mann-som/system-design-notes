package ODP;
import ODP.observable.Product;
import ODP.observable.Observable;
import ODP.observer.Observer;
import ODP.observer.appNotify;
import ODP.observer.emailNotify;

public class Main {
    public static void main(String args[]){

        Observable iphonObservable = new Product();
        Observer obs1 = new emailNotify("abc@xyz.com", iphonObservable);
        Observer obs2 = new appNotify(iphonObservable);
        
        iphonObservable.add(obs1);
        iphonObservable.add(obs2);

        iphonObservable.setStock(20);
    }
}

package ODP.observer;
import ODP.observable.Observable;

public class appNotify implements Observer{
    Observable observable;

    public appNotify(Observable observable){
        this.observable = observable;
    }

    @Override
    public void update(){
        sendNotification("Product is back in stocl");
    }

    private void sendNotification(String msg){
        System.out.println("Notification sent.");
    }

}

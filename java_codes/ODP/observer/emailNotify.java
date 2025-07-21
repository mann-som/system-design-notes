package ODP.observer;
import ODP.observable.Observable;

public class emailNotify implements Observer{
    String emailId;
    Observable observable;

    public emailNotify(String emailId, Observable observable){
        this.observable = observable;
        this.emailId = emailId;
    }

    @Override
    public void update(){
        sendEmail(emailId, "Product is back in stock");
    }

    private void sendEmail(String emailId, String msg){
        System.out.println("Email sent to: " + emailId);
    }
}

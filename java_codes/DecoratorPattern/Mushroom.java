package DecoratorPattern;

public class Mushroom extends ToppingDecorator {

    BasePizza basePizza;

    Mushroom(BasePizza basePizza) {
        this.basePizza = basePizza;
    }

    @Override
    public int cost() {
        return this.basePizza.cost() + 15;
    }
}
 
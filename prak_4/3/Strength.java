public class Strength extends Hero {

    public Strength(){
        super();
    }

    public Strength(int level){
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Strength Hero (Lvl " + level + ")");
    }

    public Double value(){
        return level + 0.2;
    }
}

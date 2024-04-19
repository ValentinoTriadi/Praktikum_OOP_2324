public class Agility extends Hero {

    public Agility(){
        super();
    }

    public Agility(int level){
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Agility Hero (Lvl " + level + ")");
    }

    public Double value(){
        return level + 0.3;
    }
}

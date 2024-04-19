public class Intelligence extends Hero {

    public Intelligence(){
        super();
    }

    public Intelligence(int level){
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Intelligence Hero (Lvl " + level + ")");
    }

    public Double value(){
        return level + 0.1;
    }
}

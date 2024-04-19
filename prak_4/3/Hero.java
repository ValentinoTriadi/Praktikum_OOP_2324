public abstract class Hero implements Calculable {
    protected Integer level;

    public Hero(){
        this.level = 0;
    }

    public Hero(Integer level){
        this.level = level;
    }
    
    public Integer getLevel(){
        return this.level;
    }

    public void setLevel(Integer level){
        this.level = level;
    }

    public abstract void printInfo();
}

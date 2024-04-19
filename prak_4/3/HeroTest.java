public class HeroTest {
    public static void main(String[] args){
        Hero Hero1 = new Agility(10);
        Hero Hero2 = new Strength(10);
        Hero Hero3 = new Intelligence(20);
        Hero Hero4 = new Strength(20);

        System.out.println(Comparator.isObj1EqualToObj2(Hero1, Hero2)); 
        System.out.println(Comparator.isObj1BiggerThanObj2(Hero3, Hero1));
        Hero4.printInfo();
    }
}

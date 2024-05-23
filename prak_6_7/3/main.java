public class main {
    public static void main(String[] args) {
        
        Solver solver = new Solver();
        solver.addPiece("What is the meaning of life?");
        solver.addPiece("What is the meaning of love?");
        solver.addPiece("What is the meaning of happiness?");
        solver.addPiece("What is the meaning of sadness?");
        solver.addPiece("What is the meaning of joy?");

        System.out.println(solver.scrapeAnswer());

    }
}

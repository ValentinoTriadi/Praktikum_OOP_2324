public class Gpt {
    private String prompt;
    private static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
    public Gpt(String prompt) {
      this.prompt = prompt;
    }
  
    public char getPieceAnswer() {
      // Melakukan query prompt ke GPT untuk mendapat jawaban piece puzzle.
      // Melakukan request akan membutuhkan waktu lama, jadi asumsikan
      // kode berikut sebagai contoh.
      try {
        Thread.sleep((int) (Math.random() * 5000));
      } catch (InterruptedException e) {
        //
      }
      return alphabet.charAt((int) (Math.random() * alphabet.length()));
    }
  }
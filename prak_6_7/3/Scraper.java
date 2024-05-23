public class Scraper extends Thread {
    public String prompt;
    private String answer;
  
    public Scraper(String prompt) {
      this.prompt = prompt;
    }
  
    public void run() {
      Gpt gpt = new Gpt(prompt);
      this.answer = String.valueOf(gpt.getPieceAnswer());
    }
  
    public String getAnswer() {
      return this.answer;
    }
}
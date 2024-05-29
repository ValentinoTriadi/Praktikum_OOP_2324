public class Scraper extends Thread {
    public String prompt;
    private String answer;
    private boolean isScrapingDone = false;
  
    public Scraper(String prompt) {
      this.prompt = prompt;
    }
  
    public void run() {
      Gpt gpt = new Gpt(prompt);
      this.answer = String.valueOf(gpt.getPieceAnswer());
      isScrapingDone = true;
      synchronized (this) {
        notify();
      }
    }
  
    public synchronized String getAnswer() {
      while (!isScrapingDone) {
        try {
          wait();
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
      return this.answer;
    }
}
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solver {
  private ArrayList<String> prompts;

  public Solver() {
    this.prompts = new ArrayList<String>();
  }

  public void addPiece(String prompt) {
    this.prompts.add(prompt);
  }

  public String scrapeAnswer() {
    // Kode berikut masih melakukan scrap ke GPT secara sekuensial.
    // Agar lebih cepat, ubahlah kode di bawah ini menjadi paralel
    // menggunakan wait dan notify, dengan membuat instance Scraper
    // Perhatikan juga bahwa piece answer di sini belum terurut.

    Map<String, String> answers = new HashMap<String, String>();
    List<Scraper> scrapers = new ArrayList<>();

    for (String prompt : prompts) {
      Scraper scraper = new Scraper(prompt);
      scrapers.add(scraper);
      scraper.start();
    }

    for (Scraper scraper : scrapers) {
      String res = scraper.getAnswer();
      answers.put(scraper.prompt, res);
    }

    String answer = "";
    for (String prompt : prompts) {
      answer += answers.get(prompt);
    }

    // Sorting answer using bubble sort
    char[] answerArray = answer.toCharArray();
    for (int i = 0; i < answerArray.length - 1; i++) {
      for (int j = 0; j < answerArray.length - i - 1; j++) {
        if (answerArray[j] > answerArray[j + 1]) {
          char temp = answerArray[j];
          answerArray[j] = answerArray[j + 1];
          answerArray[j + 1] = temp;
        }
      }
    }

    answer = new String(answerArray);

    return answer;
  }
}
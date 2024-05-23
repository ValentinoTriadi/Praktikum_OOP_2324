public class EmailMessageSender implements IMessageSender { 
    private String serviceEmail;

    public EmailMessageSender(String serviceEmail) {
        this.serviceEmail = serviceEmail;
    }

    public void sendMessage(User data, String message) {
        // Kirim email ke user dengan isi pesan message, print dengan format
        // From: <serviceEmail>
        // To: <name> <emailUser>
        // Message: <message>
        // Masing-masing diikuti dengan newline
        System.out.println("From: " + serviceEmail);
        System.out.println("To: " + data.getName() + " " + data.getEmail());
        System.out.println("Message: " + message);
    }
}

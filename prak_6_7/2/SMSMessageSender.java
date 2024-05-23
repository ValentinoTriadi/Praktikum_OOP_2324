public class SMSMessageSender implements IMessageSender{
    private String servicePhone;

    public SMSMessageSender(String servicePhone) {
        this.servicePhone = servicePhone;
    }

    public void sendMessage(User data, String message) {
        // Kirim SMS ke user dengan isi pesan message, print dengan format
        // From: <servicePhone>
        // To: <name> <phoneUser>
        // Message: <message>
        // Masing-masing diikuti dengan newline
        System.out.println("From: " + servicePhone);
        System.out.println("To: " + data.getName() + " " + data.getPhone());
        System.out.println("Message: " + message);
    }
}

public class PushNotifMessageSender implements IMessageSender{
    private String serviceName;

    public PushNotifMessageSender(String serviceName) {
        this.serviceName = serviceName;
    }

    public void sendMessage(User data, String message) {
        // Kirim push notifikasi ke user dengan isi pesan message, print dengan format
        // From: <serviceName>
        // To: <name> <deviceUser>
        // Message: <message>
        // Masing-masing diikuti dengan newline
        System.out.println("From: " + serviceName);
        System.out.println("To: " + data.getName() + " " + data.getDevice());
        System.out.println("Message: " + message);
    }
}

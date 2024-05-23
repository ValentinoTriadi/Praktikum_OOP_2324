import java.util.List;

public class NotificationManager {
    private List<Service> services;

    public NotificationManager(List<Service> services) {
        this.services = services;
    }

    public void addService(Service service) {
        // Tambahkan service ke dalam list services
        this.services.add(service);
    }

    public List<Service> getServices() {
        // Mengembalikan list services
        return this.services;
    }

    public void removeService(Service service) {
        // Hapus service dari dalam list services
        this.services.remove(service);
    }

    public void notifyService(String message) {
        // Kirim pesan ke user dengan isi pesan message
        for (Service s : services){
            s.sendMessage(message);
        }
    }
}

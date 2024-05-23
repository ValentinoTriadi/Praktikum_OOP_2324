import java.util.ArrayList;
import java.util.List;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        tasks = new ArrayList<>();
    };

    public void addTask(Task newTask){
        tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            //TODO: Fill with the operation that will process the tasks. Hint: the operation is exactly
            // the same with the operation that exist on Worker.java with a little improvement;)
            for (Task task : tasks) {
                Thread.sleep(task.getTime());
                synchronized (task) {
                    task.setStatus("done");
                    task.notify();
                }
            }
        } catch (InterruptedException e) {
            //TODO: Fill with the same error message on the Worker.java
            System.out.println("Worker Error!");
        }
    }
    
}
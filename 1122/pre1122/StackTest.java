import java.util.Queue;
import java.util.ArrayDeque;

public class StackTest{
    public static void main(String[] args){
        Queue<Integer> queue = new ArrayDeque<Integer>();
        queue.add(100);
        System.out.prinfln(queue.poll());
    }
}
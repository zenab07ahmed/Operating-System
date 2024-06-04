import java.util.concurrent.Semaphore;
public class ReaderWriter {
static int rc=0;
static Semaphore s = new Semaphore(1); static Semaphore wrt = new Semaphore(1);
public static void main(String[] args) { while(true){
Reader r = new Reader();
Writer w = new Writer();
Thread t1= new Thread(r); 
Thread t2= new Thread(r);
Thread t3= new Thread(r); 
Thread t4= new Thread(r); 
Thread t5= new Thread(r); 
Thread t6= new Thread(w); 
Thread t7= new Thread(w);
Thread t8= new Thread(w);
Thread t9= new Thread(w);
Thread t10= new Thread(w);
t1.setName("Reader 1"); 
t2.setName("Reader 2"); 
t3.setName("Reader 3"); 
t4.setName("Reader 4"); 
t5.setName("Reader 5"); 
t6.setName("writer 1"); 
t7.setName("writer 2");
t8.setName("writer 3");
t9.setName("writer 4");
t10.setName("writer 5");
t1.start(); 
t2.start();
t3.start(); 
t4.start();
t5.start();
t6.start();
t7.start();
t8.start();
t9.start();
t10.start();
    
}
}
static public class Reader implements Runnable {
public void run() {
try {
s.acquire(); rc++;
if(rc==1) wrt.acquire();
s.release();
System.out.println(Thread.currentThread().getName()+" is reading "); Thread.sleep(100);
System.out.println("Reading finished...");
//s.acquire();
rc--;
if(rc==0) {
wrt.release();
s.release(); }
} catch (InterruptedException ex) {
} }
}
static public class Writer implements Runnable
{
@Override public void run() {
try { wrt.acquire();
System.out.println(Thread.currentThread().getName()+" is writing "); Thread.sleep(10);
System.out.println("Writing finished...");
wrt.release();
} catch (InterruptedException ex) {
} }
} }

public abstract class Car {
	public abstract String getName();
	
	public void start() {
		System.out.println(getName() + " �õ��� �մϴ�.");
	}
	
	public void drive() {
		System.out.println(getName() + " �޸��ϴ�.");
	}
	
	public void stop() {
		System.out.println(getName() + " ����ϴ�.");
	}
	
	public void turnoff() {
		System.out.println(getName() + " �õ��� ���ϴ�.");
	}
	
	final public void run() {
		start();
		drive();
		stop();
		turnoff();
	}
}

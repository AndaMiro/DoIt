
public abstract class Car {
	public abstract String getName();
	
	public void start() {
		System.out.println(getName() + " 시동을 켭니다.");
	}
	
	public void drive() {
		System.out.println(getName() + " 달립니다.");
	}
	
	public void stop() {
		System.out.println(getName() + " 멈춥니다.");
	}
	
	public void turnoff() {
		System.out.println(getName() + " 시동을 끕니다.");
	}
	
	final public void run() {
		start();
		drive();
		stop();
		turnoff();
	}
}

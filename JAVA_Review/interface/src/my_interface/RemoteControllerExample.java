package my_interface;

public class RemoteControllerExample {

	public static void main(String[] args)
	{
		RemoteControl rc = new RemoteControl()
		{
			public void turnOn() {}
			public void turnOff() {}
			public void setVolume(int volume) {}
		};
		
		System.out.println("Hello");
	}
	
}

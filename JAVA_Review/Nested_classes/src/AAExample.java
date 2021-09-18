public class AAExample {
	public static void main(String[] args) {
		AA aa = new AA();
		aa.field.run();
		aa.method1();
		aa.method2(
			new Vehicle() {
				@Override
				public void run() {
					System.out.println("Run Boy Run method");
				}
			}
		);
	}
}

public class AA {
	Vehicle field = new Vehicle() {
		@Override
		public void run() {
			System.out.println("Run Boy Run field");
		}
	};
	
	void method1() {
		Vehicle localVar = new Vehicle() {
			@Override
			public void run() {
				System.out.println("Run Boy Run local");
			}
		};
		localVar.run();
	}
	
	void method2(Vehicle v) {
		v.run();
	}
}

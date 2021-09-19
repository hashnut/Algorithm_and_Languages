public class TryWithResourceExample {

	public static void main(String[] args) {
		try (FileInputStream fin = new FileInputStream("file.txt")) {
			fin.read();
			throw new Exception();
		} catch(Exception e) {
			System.out.println("예외 처리 코드가 실행되었습니다.");
		}
	}
	
	public void method1() {
		try {
			method2();
		} catch(ClassNotFoundException e) {
			// 예외 처리 코드
			System.out.println("클래스가 존재하지 않습니다.");
		}
	}
	
	public void method2() throws ClassNotFoundException {
		Class clazz = Class.forName("java.lang.String2");
	}
}

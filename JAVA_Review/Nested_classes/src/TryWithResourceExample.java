public class TryWithResourceExample {

	public static void main(String[] args) {
		try (FileInputStream fin = new FileInputStream("file.txt")) {
			fin.read();
			throw new Exception();
		} catch(Exception e) {
			System.out.println("���� ó�� �ڵ尡 ����Ǿ����ϴ�.");
		}
	}
	
	public void method1() {
		try {
			method2();
		} catch(ClassNotFoundException e) {
			// ���� ó�� �ڵ�
			System.out.println("Ŭ������ �������� �ʽ��ϴ�.");
		}
	}
	
	public void method2() throws ClassNotFoundException {
		Class clazz = Class.forName("java.lang.String2");
	}
}

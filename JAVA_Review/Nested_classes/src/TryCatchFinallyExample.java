import java.io.FileInputStream;

public class TryCatchFinallyExample {
	public static void main(String[] args) {
		try {
			Class clazz = Class.forName("java.lang.String");
			int arr[] = {0,};
			arr[3] = 0;
		} catch(ClassNotFoundException e) {
			System.out.println("Ŭ������ �������� �ʽ��ϴ�");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("�ε��� ũ�⸦ Ȯ���ϼ���");
		} finally {
			System.out.println("���� ó���� �۵����Դϴ�");
		}
		
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("file.txt");
		} catch (IOException e) {
			...
		} finally {
			if (fis != null) {
				try {
					fis.close();
				} catch (IOException e) {}
			}
		}
		
		
		
		
	}
}

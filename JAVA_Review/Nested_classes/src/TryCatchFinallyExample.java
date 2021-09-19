import java.io.FileInputStream;

public class TryCatchFinallyExample {
	public static void main(String[] args) {
		try {
			Class clazz = Class.forName("java.lang.String");
			int arr[] = {0,};
			arr[3] = 0;
		} catch(ClassNotFoundException e) {
			System.out.println("클래스가 존재하지 않습니다");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("인덱스 크기를 확인하세요");
		} finally {
			System.out.println("예외 처리가 작동중입니다");
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

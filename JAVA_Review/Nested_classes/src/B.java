public class B
{
	void method1(Parent parent) {}
	void method2()
	{
		method1(
			
			new Parent()
		    {
		    	int childField;
		        void childMethod() {}
		        @Override
		        void parentMethod() {}
		    }
		);
		
	}
 
	Parent field = new Parent()
    {
    	int childField;
        void childMethod() {}
        @Override
        void parentMethod() {}
    };
    
    void method()
    {
    	field.childField = 3; // �θ� Ÿ�Կ� ������� �ʾ� ��� �Ұ�
    	field.childMethod(); // �θ� Ÿ�Կ� ������� �ʾ� ��� �Ұ�
    	field.parentMethod(); // �θ� Ÿ�Կ� ����Ǿ� ��� ����!
    }
}
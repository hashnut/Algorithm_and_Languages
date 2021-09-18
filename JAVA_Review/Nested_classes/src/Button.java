public class Button {
	
	OnClickListener listener;
	
	// �Ű� ������ ������
	void setOnClickListener(OnClickListener listener)
	{
		this.listener = listener;
	}
	
	// ���� ��ü�� onClock() �޼ҵ� ȣ��
	void touch()
	{
		listener.onClick();
	}
	
	// Nested interface
	interface OnClickListener
	{
		void onClick();
	}
	
}

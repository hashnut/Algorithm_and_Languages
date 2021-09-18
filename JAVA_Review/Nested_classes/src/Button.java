public class Button {
	
	OnClickListener listener;
	
	// 매개 변수의 다형성
	void setOnClickListener(OnClickListener listener)
	{
		this.listener = listener;
	}
	
	// 구현 객체의 onClock() 메소드 호출
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

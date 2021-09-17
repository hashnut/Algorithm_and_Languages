package my_interface;

public class OracleDao implements DataAccessObject
{
	@Override
	public void select()
	{
		System.out.println("Oracle 검색");
	}
	
	@Override
	public void insert()
	{
		System.out.println("Oracle 삽입");
	}
	
	@Override
	public void update()
	{
		System.out.println("Oracle 수정");
	}
	
	@Override
	public void delete()
	{
		System.out.println("Oracle 삭제");
	}
}

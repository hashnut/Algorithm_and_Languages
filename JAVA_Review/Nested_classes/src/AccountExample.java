public class AccountExample {
	
	public static void main(String[] args) {
		AccountExample ex = new AccountExample();
		AccountExample.Account account = ex.new Account();
	
		// �����ϱ�
		account.deposit(1000);
		System.out.println("���ݾ�: " + account.getBalance());
		
		// ����ϱ�
		try {
			account.withdraw(30000);
		} catch (BalanceInsufficientException e) {
			String message = e.getMessage();
			System.out.println(message);
			System.out.println();
			e.printStackTrace();
		}
		
	}

	class Account {
		int money;
		
		public Account() {}
		
		void deposit(int m) {
			money += m;
		}
		
		void withdraw(int m) throws BalanceInsufficientException {
			if (money < m)
				throw new BalanceInsufficientException("�ܰ����: "+(money-m)+" ���ڶ�");
			money -= m;
		}
		
		int getBalance() {
			return money;
		}
		
	}
	
}





















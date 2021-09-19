public class AccountExample {
	
	public static void main(String[] args) {
		AccountExample ex = new AccountExample();
		AccountExample.Account account = ex.new Account();
	
		// 예금하기
		account.deposit(1000);
		System.out.println("예금액: " + account.getBalance());
		
		// 출금하기
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
				throw new BalanceInsufficientException("잔고부족: "+(money-m)+" 모자람");
			money -= m;
		}
		
		int getBalance() {
			return money;
		}
		
	}
	
}





















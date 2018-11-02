 /*
 多进行几次运算，发现有规律，要么变成1要么变成4
 */
 bool isHappy(int n) {
	while (n != 1 && n != 4) {
		int t = 0;
		while (n) {
			t += (n % 10) * (n % 10);
			n /= 10;
		}
		n = t;
	}
	return n == 1;
}
int MCD(int m, int n) {

	if (m == 0) {
		return n;
	}
	if (m <= n) {
		return MCD(m, n % m);
	}
	if (n == 0) {
		return m;
	}
	return MCD(n, m % n);
}
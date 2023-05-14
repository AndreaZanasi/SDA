int Divisione(int a, int b) {
	if (a < 0 || b <= 0) {
		return -1;
	}
	if (a == 0 || a < b) {
		return 0;
	}

	return Divisione(a - b, b) + 1;
}
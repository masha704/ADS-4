// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (arr[i] + arr[j] == value) {
				count++;
			}
		}
	}
	return count;
}
int countPairs2(int *arr, int len, int value) {
	int count = 0;
	while (arr[len - 1] > value) {
		len--;
	}
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > i; j--) {
			if (arr[i] + arr[j] == value) {
				count++;
			}
		}
	}
	return count;
}
int binserch(int begin, int end, int* arr, int value) {
	int i = begin, j = end - 1;
	while (i < j) {
		int midd = i + (j - i)/2;
		if (arr[midd] == value) {
			return midd;
		}
		else if (arr[midd] > value)
			j = midd;
		else
			i = midd + 1;
	}
	return -1;
}
int countPairs3(int *arr, int len, int value) {
	int count = 0;
	int pos = - 1;
	int tmp, tmp2;
	for (int i = 0; i < len; i++) {
		if ((pos = binserch(i, len, arr, value - arr[i])) != -1) {
			count++;
			tmp = pos;
			tmp2 = pos;
			while (arr[--tmp] == value-arr[i] && tmp > i) {
				count++;
			}
			//pos = tmp;
			while (arr[++tmp2] == value-arr[i] && tmp2 < len) {
				count++;
			}
		}
	}
	return count;
}

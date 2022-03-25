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
	int midd = (begin + end) / 2;
	if (arr[midd] == value) return midd;
	else if (arr[midd] < value && midd != begin && midd != end) return binserch(midd, end, arr, value);
	return -1;
}
int countPairs3(int *arr, int len, int value) {
	int count = 0;
	int pos = - 1;
	for (int i = 0; i < len; i++) {
		if (pos = binserch(i, len-1, arr, value - arr[i])!= -1) {
			count++;
		}
	}
	return count;
}

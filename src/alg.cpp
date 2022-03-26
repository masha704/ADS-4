// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
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
int bin_search(int* arr, int begin, int len, int value) {
    int count = 0, i = begin, end = len - 1, midd, tmp;
    while (i <= end) {
        midd = i + (end - i) / 2;
        if (arr[midd] == value && midd != begin && midd != len) {
            count++;
            tmp = midd;
            while (arr[--midd] == value && midd > begin) count++;
            while (arr[++tmp] == value && tmp < len) count++;
            break;
        } else if (arr[midd] > value) {
            end = midd - 1;
        } else {
            i = midd + 1;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += bin_search(arr, i, len, value - arr[i]);
    }
    return count;
}

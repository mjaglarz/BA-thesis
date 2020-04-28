void quicksort(int *a, int lo, int hi) {
    int i = lo;
    int j = hi;
    while (i < hi) {
        int pivot = a[(lo + hi) / 2];
        while (i <= j) {
            while (a[i] < pivot) {
                i = i + 1;
            }

            while (a[j] > pivot) {
                j = j - 1;
            }

            if (i <= j) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                i = i + 1;
                j = j - 1;
            }
        }

        if (lo < j) {
            quicksort(a, lo, j);
        }

        lo = i;
        j = hi;
    }
}
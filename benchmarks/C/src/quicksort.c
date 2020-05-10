void quicksort(int *A, int lo, int hi) {
    int i = lo;
    int j = hi;
    while (i < hi) {
        int pivot = A[(lo + hi) / 2];
        while (i <= j) {
            while (A[i] < pivot) {
                i = i + 1;
            }

            while (A[j] > pivot) {
                j = j - 1;
            }

            if (i <= j) {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
                i = i + 1;
                j = j - 1;
            }
        }

        if (lo < j) {
            quicksort(A, lo, j);
        }

        lo = i;
        j = hi;
    }
}
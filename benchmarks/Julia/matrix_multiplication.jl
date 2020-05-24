function matmul!(A, B, R)
    for i = 1:size(A)[1], j = 1:size(B)[2], k = 1:size(B)[1]
        R[i, j] += A[i, k] * B[k, j]
    end
end
using DelimitedFiles
using Formatting

include("fibonacci.jl")
include("matrix_multiplication.jl")
include("quicksort.jl") 


function chop_suffix_from_path(path, suffix)
    if endswith(path, suffix)
        return path[1:(end-length(suffix))]
    end
    return path
end



function run_test(suite, ntests)
    if suite == 1
        test_fibonacci(ntests)
    elseif suite == 2
        test_quicksort(ntests)
    elseif suite == 3
        test_matrix_multiplication(ntests)
    elseif suite == 4
        test_all(ntests)
    end
end


function test_fibonacci(ntests)
    fibarg = 20
    base_path = chop_suffix_from_path(pwd(), "/benchmarks/Julia")
    path = string(base_path, "/results/fibonacci/julia_fibonacci_benchmark.txt")

    @assert fib(20) == 6765

    open(path, "w") do fd
        for _ in 1:ntests
            time = @elapsed fib(fibarg)
            write(fd, string(fmt(".6f", time), "\n"))
        end
    end
end


function test_quicksort(ntests)
    arraysize = 1000000
    base_path = chop_suffix_from_path(pwd(), "/benchmarks/Julia")
    read_path = string(base_path, "/utils/data/integers.txt")

    open(read_path, "r") do fdread
        test_array = [parse(Int, i) for i in readlines(read_path)]
        quicksort!(test_array, 1, arraysize)
        @assert issorted(test_array)

        write_path = string(base_path, "/results/quicksort/julia_quicksort_benchmark.txt")
        open(write_path, "w") do fdwrite
            for _ in 1:ntests
                seekstart(fdread)
                array = [parse(Int, i) for i in readlines(read_path)]
                time = @elapsed quicksort!(array, 1, arraysize)
                write(fdwrite, string(fmt(".6f", time), "\n"))
            end
        end
    end
end


function test_matrix_multiplication(ntests)
    matrix_size = 200
    base_path = chop_suffix_from_path(pwd(), "/benchmarks/Julia")
    write_path = string(base_path, "/results/matrix_multiplication/julia_matrix_multiplication_benchmark.txt")
    read_path = string(base_path, "/utils/data/matmul_assert.txt")

    A = B = [col-1 for row in 1:matrix_size, col in 1:matrix_size]
    R = zeros(Int, matrix_size, matrix_size)
    matmul!(A, B, R)
    C = readdlm(read_path, ' ', BigInt, '\n')
    @assert R == C

    open(write_path, "w") do fd
        for _ in 1:ntests
            R = zeros(Int, matrix_size, matrix_size)
            time = @elapsed matmul!(A, B, R)

            write(fd, string(fmt(".6f", time), "\n"))
        end
    end
end


function test_all(ntests)
    test_fibonacci(ntests)
    test_quicksort(ntests)
    test_matrix_multiplication(ntests)
end
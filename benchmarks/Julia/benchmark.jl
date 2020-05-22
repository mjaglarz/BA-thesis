include("utils.jl")

ntests = 3

base_path = chop_suffix_from_path(pwd(), "/benchmarks/Julia")
path = string(base_path, "/results/fibonacci/julia_fibonacci_benchmark.txt")

@assert fib(20) == 6765

open(path, "w") do io
    for _ in 1:ntests
        time = @elapsed fib(20)
        println(time)
        write(io, string(time, "\n"))
    end
end;
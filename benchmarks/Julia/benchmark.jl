include("fibonacci.jl")
include("quicksort.jl")

using Printf

println(fib(20))

a = [3, 4, 2, 6 ,2]

quicksort(a, 1, length(a))
println(a)
include("utils.jl")

function run(fd val1, val2, val3)
    ntests = 3
    nincr_small = 1000
    nincr_big = 10000000

    test_sleep(fd, ntests)
    test_for_sleep(fd, ntests)

    test_add(fd, ntests, nincr_small, val1)
    test_add(fd, ntests, nincr_big, val1)

    test_add_if(fd, ntests, nincr_small, val1)
    test_add_if(fd, ntests, nincr_big, val1)

    test_subtract(fd, ntests, nincr_small, val2)
    test_subtract(fd, ntests, nincr_big, val2)

    test_subtract_if(fd, ntests, nincr_small, val2)
    test_subtract_if(fd, ntests, nincr_big, val2)

    test_multiply(fd, ntests, nincr_small, val3)
    test_multiply(fd, ntests, nincr_big, val3)

    test_multiply_if(fd, ntests, nincr_small, val3)
    test_multiply_if(fd, ntests, nincr_big, val3)

    test_divide(fd, ntests, nincr_small, val2)
    test_divide(fd, ntests, nincr_big, val2)

    test_divide_if(fd, ntests, nincr_small, val2)
    test_divide_if(fd, ntests, nincr_big, val2)
end


file_name = "/results/basic_operations/julia_basic_operations.txt"
path = string(chop_suffix_from_path(pwd(), "/utils/src"), file_name)
open(path, "w") do fd
    run(fd, parse(Int, ARGS[1]), parse(Int, ARGS[2]), parse(Int, ARGS[3])
end
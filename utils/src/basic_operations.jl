include("utils.jl")

function run(fd)
    ntests = 3
    nincr_small = 1000
    nincr_big = 10000000

    test_sleep(fd, ntests)
    test_for_sleep(fd, ntests)

    test_add(fd, ntests, nincr_small)
    test_add(fd, ntests, nincr_big)

    test_add_if(fd, ntests, nincr_small)
    test_add_if(fd, ntests, nincr_big)

    test_subtract(fd, ntests, nincr_small)
    test_subtract(fd, ntests, nincr_big)

    test_subtract_if(fd, ntests, nincr_small)
    test_subtract_if(fd, ntests, nincr_big)

    test_multiply(fd, ntests, nincr_small)
    test_multiply(fd, ntests, nincr_big)

    test_multiply_if(fd, ntests, nincr_small)
    test_multiply_if(fd, ntests, nincr_big)

    test_divide(fd, ntests, nincr_small)
    test_divide(fd, ntests, nincr_big)

    test_divide_if(fd, ntests, nincr_small)
    test_divide_if(fd, ntests, nincr_big)
end


file_name = "/results/basic_operations/julia_basic_operations.txt"
path = string(chop_suffix_from_path(pwd(), "/utils/src"), file_name)
open(path, "w") do fd
    run(fd)
end
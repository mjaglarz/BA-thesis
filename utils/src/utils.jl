using Formatting


function chop_suffix_from_path(path, suffix)
    if endswith(path, suffix)
        return path[1:(end-length(suffix))]
    end
    return path
end


function test_sleep(fd, ntests)
    for _ in 1:ntests
        elapsed_time = @elapsed sleep(100)
        println("Sleep(100): $elapsed_time")
        write(fd, string("A\t", fmt(".6f", elapsed_time), "\t1\n"))
    end
    write(fd, "\n")
end


function test_for_sleep(fd, ntests)
    niter = 100
    for _ in 1:ntests
        elapsed_time = @elapsed for _ in 1:niter
                        sleep(1)
        end
        println("For 100 times sleep(1): $elapsed_time")
        write(fd, string("B\t", fmt(".6f", elapsed_time), "\t$niter\n"))
    end
    write(fd, "\n")
end


function test_add(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 0
        elapsed_time = @elapsed for _ in 1:nincr
                        val += 1
        end
        println("For $nincr add 1 to $initial_value: $elapsed_time")
        write(fd, string("C\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_add_if(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 0
        elapsed_time = @elapsed for i in 1:nincr
                        if i % 2 == 0
                            val += 1
                        end
        end
        println("For $nincr add 1 to $initial_value: $elapsed_time")
        write(fd, string("D\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_subtract(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1000000
        elapsed_time = @elapsed for _ in 1:nincr
                        val -= 1
        end
        println("For $nincr subtract 1 from $initial_value: $elapsed_time")
        write(fd, string("E\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_subtract_if(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1000000
        elapsed_time = @elapsed for i in 1:nincr
                        if i % 2 == 0
                            val -= 1
                        end
        end
        println("For $nincr subtract 1 from $initial_value: $elapsed_time")
        write(fd, string("F\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_multiply(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1
        elapsed_time = @elapsed for _ in 1:nincr
                        val *= 1.01
        end
        println("For $nincr multiply $initial_value by 1.01: $elapsed_time")
        write(fd, string("G\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_multiply_if(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1
        elapsed_time = @elapsed for i in 1:nincr
                        if i % 2 == 0
                            val *= 1.01
                        end
        end
        println("For $nincr multiply $initial_value by 1.01: $elapsed_time")
        write(fd, string("H\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_divide(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1000000
        elapsed_time = @elapsed for _ in 1:nincr
                        val /= 1.01
        end
        println("For $nincr divide $initial_value by 1.01: $elapsed_time")
        write(fd, string("I\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end


function test_divide_if(fd, ntests, nincr)
    for _ in 1:ntests
        initial_value = val = 1000000
        elapsed_time = @elapsed for i in 1:nincr
                        if i % 2 == 0
                            val /= 1.01
                        end
        end
        println("For $nincr divide $initial_value by 1.01: $elapsed_time")
        write(fd, string("J\t", fmt(".6f", elapsed_time), "\t$nincr\n"))
    end
    write(fd, "\n")
end
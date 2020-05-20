include("fibonacci.jl")
include("quicksort.jl") 

function chop_suffix_from_path(path, suffix)
    if endswith(path, suffix)
        return path[1:(end-length(suffix))]
    end
    return path
end
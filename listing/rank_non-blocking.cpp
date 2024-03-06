MPI_STATUS stats[1];
MPI_Request reqs[1];
...
float nums[size]; 
if (rank == root) { 
    //insert some values in nums 
}

float sub_nums[len];

MPI_Iscatter(nums, len, MPI_FLOAT, sub_nums, len, MPI_FLOAT, root, MPI_COMM_WORLD, &reqs[0]);


if (rank == root) { 
    MPI_Wait(&reqs[0],&stats[0]);
}

nums = do_computation(sub_nums) // inlined

if (rank != root) { 
    MPI_Wait(&reqs[0],&stats[0]);
}
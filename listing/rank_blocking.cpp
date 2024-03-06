float nums[size]; 

if (rank == root) {
    //insert some values in nums 
}

float sub_nums[len]; 
MPI_Scatter(nums, len, MPI_FLOAT, sub_nums, len, MPI_FLOAT, root, MPI_COMM_WORLD);
nums = do_computation(sub_nums);
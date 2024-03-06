MPI_Allreduce(sub arr1, sumA1temp, num_elements, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD); 
sumA1 = sum(sumA1temp);
avgA1 = sumA1/(num elements*p); 
sub_arr2 = scalarMultiply(sub arr2,avgA1);

MPI_Allreduce(sub_arr2, minA2temp, num_elements, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD); 
MPI_Allreduce(sub_arr2, maxA2temp, num_elements, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);

sub_arr3 = scalarAdd(sub arr3,avgA1); 
minA2 = min(minA2temp);
maxA2 = max(maxA2temp); 
sub_arr3 = scalarMultiply(sub arr3,(minA2 + maxA2)*0.5);

MPI_Allreduce(sub arr3, sumA3temp, num elements, MPI DOUBLE, MPI SUM, MPI COMM WORLD); finalsum = sum(sumA3temp);
// Definitions of variables used 
// Allocate memory for vectors 
do {
    ...
    iter++;

    // Compute the new vector X and residue vector
    for(index = 0; index < Bloc_VectorSize; index++) {
        Bloc_Vector_X[index] = Vector_X[MyRank * Bloc_VectorSize + index] + Tau * Bloc_Direction_Vector[index];
        Bloc_Residue_Vector[index] = Bloc_Residue_Vector[index] + Tau * Buffer[index];
    }
        
    // Gather the new vector X
    MPI_Allgather(Bloc_Vector_X, Bloc_VectorSize, MPI_DOUBLE, Vector_X, Bloc_VectorSize, MPI_DOUBLE, MPI_COMM_WORLD);
        
    SolvePrecondMatrix(Bloc_Precond_Matrix, Bloc_HVector, Bloc_Residue_Vector, Bloc_VectorSize); 
        
    Bloc_Delta1 = ComputeVectorDotProduct(Bloc_Residue_Vector, Bloc_HVector, Bloc_VectorSize);
        
    MPI_Allreduce(&Bloc_Delta1, &Delta1, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD); 
        
    Beta = Delta1 / Delta0;    
    Delta0 = Delta1; 
        
    for (i=0; i < Bloc VectorSize; i++) {
        Bloc_Direction_Vector[i] = -Bloc_HVector[i] + Beta * Bloc_Direction_Vector[i];
    }
} while (Delta0 > EPSILON && iter < MAX_ITERATIONS);
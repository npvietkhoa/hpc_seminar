MPI_Request reqs[2]; 
int flags[2];
MPI_Status stats[2]; 
memset(flags,0,(sizeof(flags)));
do { 
    ...
    iter++;
    // calculate the residue vector and vector x 
    for(index = 0; index < Bloc_VectorSize; index++){
        Bloc_Vector_X[index] = Vector_X[MyRank * Bloc_VectorSize + index] + Tau * Bloc_Direction_Vector[index]; 
        Bloc_Residue_Vector[index] = Bloc_Residue_Vector[index] + Tau * Buffer[index];
    } 
        
    MPI_Iallgather(((void *)Bloc_Vector X), Bloc_VectorSize, MPI_DOUBLE, ((void *)Vector X), Bloc_VectorSize, MPI_DOUBLE, MPI_COMM_WORLD, &reqs[0]); 
    
    //Inline SolvePrecondMatrix 
    //Inline ComputeVectorDotProduct
    
    MPI_Iallreduce(((void *)(&Bloc Delta1)), ((void *)(&Delta1)), 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD, &reqs[1]); 
    MPI_Wait(&reqs[1], &stats[1]);
    
    Beta = Delta1 / Delta0; 
    Delta0 = Delta1;
    
    for (i = 0; i < Bloc_VectorSize; i++) { 
        Bloc_Direction_Vector[i] = -Bloc_HVector[i] + Beta * Bloc_Direction _Vector[i];
    } 

    MPI_Wait(&reqs[0],&stats[0]);  
    } while (Delta0 > 1.0E-20 && iter < 10000);
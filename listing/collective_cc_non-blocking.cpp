MPI_Request reqs[3];
...
MPI_Ibcast(&foo, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD, &reqs[0]); 
MPI_Ibcast(&bar, 1, MPI_INT, 0, MPI_COMM_WORLD,  &req[1]);
MPI_Ibcast(&foobar, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD, &reqs[2]); 
MPI_Waitall(3, reqs, stats);
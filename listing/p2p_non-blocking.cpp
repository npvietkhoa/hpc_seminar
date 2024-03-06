int *buffer;
int x; 
MPI_Request reqs[1];
MPI_Status stats[1]; 
int flags[1];

//code for main,initialization, ...

for(int i=0;i<1000;i++) { 
    if (myid == source) {
        flags[0]=1;
        *buffer = 123;
        MPI_Isend(buffer, count, MPI_INT, dest, tag, MPI_COMM_WORLD, &reqs[0]);
        x=0; 
    } else { 
        *buffer = 456; 
        x=1; 
    } 
    printf("%d\n",*buffer);
    if (flags[0] == 1) {
        MPI_Wait(&reqs[0],&stats[0]); 
    }
}
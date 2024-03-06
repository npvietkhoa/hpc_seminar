int *buffer;
int x;

//code for main,initialization,

for(int i=0;i<1000;i++) { 
    if (myid == source) { 
        *buffer = 123;
        MPI Send(buffer, count, MPI_INT, dest, tag, MPI_COMM_WORLD);
        x=0;
    } else {
        *buffer = 456;
        x=1;
    }
    printf("%d\n",*buffer);
}
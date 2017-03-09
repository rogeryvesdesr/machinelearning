
#include "jpg.h"
#include "mnist.h"



int main(int argc, char** argv)
{
    if(argc < 3) {fprintf(stderr, "Please provide two mnist file\n"); exit(1); }
    string path = argv[2];

    float** data = read_mnist(path);
	float* data = read_labels(path_labels);

    for(int i=0; i<60000; i++) {
        printf("%u, label=%u\n", i, (int)labels[i], i); // label...est en float et ont le force a etre en int.. (int)labels[i], i) //
        save_jpg(data[i], 28, 28, "%u/%04u.jpg", (int)labels[i], i);
    }
    return 0;
}

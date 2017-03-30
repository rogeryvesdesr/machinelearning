#include "jpg.h"
#include "mnist.h"


float dist_sq(float* v1, float* v2) {
	float d =0;	
	for (int i=0; i<784; i++){
		d += (v1[i]-v2[i])*(v1[i]-v2[i]);
	}	 
	return d;
float libnear_classifer(float* w, float *x) {
	for (int i=0; i<784; i++){
	d+= w[1]*x[i] ;}


int main(int argc, char** argv)
{

    float** images = read_mnist("train-images.idx3-ubyte");
	float* labels = read_labels("train-labels.idx1-ubyte");
	float** test_images = read_mnist("t10k-images.idx3-ubyte");
	float* test_labels = read_labels("t10k-labels.idx1-ubyte");
    
	float* w= new float[784];
	for(int i=0; i<784; i++) w[i]=(float)rand()*2/INT_MAX-1;
	float E=0;
	for (int i=0; i<10000; i++){
	printf("%u\n",i);
	int inference = linear_clafier(w,test_images[i]);
	save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
	//if(test_labels[i] != inference){  E++;}
	//printf("%d Erreur = %0.2f%%\n ",(E*100)/i,i);	 	
	}

	 return 0;
}

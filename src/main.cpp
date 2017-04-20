#include "jpg.h"
#include "mnist.h"
#include <limits.h>

float linear_classifier(float* w, float* x){
	    float d=0;
		for (int i=0;i<784;i++){
			 d += w[i]*x[i];
		}
		if (d>=0) return 1;
		else return -1;
}


/*float dist_sq(float* v1, float* v2) {
	float d =0;	
	for (int i=0; i<784; i++){
		d += (v1[i]-v2[i])*(v1[i]-v2[i]);
	}	 
	return d;
}
*/

int main(int argc, char** argv){

    float** images = read_mnist("train-images.idx3-ubyte");
	float* labels = read_labels("train-labels.idx1-ubyte");
	float** test_images = read_mnist("t10k-images.idx3-ubyte");
	float* test_labels = read_labels("t10k-labels.idx1-ubyte");
    	
		
		float *w = new float[784];

		//step 1 : intialization
		for (int i=0; i<784; i++) w[i]=(float)rand()*2/INT_MAX - 1;
		float gamma = 0.01;	
		//step 2 : Learning ( train)
		for (int i=0; i<60000; i++) {
			//Calcul gradiant (g = y*x si erreur sinon 0)
			int prediction = linear_classifier(w,images[i]);
			int verite = (labels[i] == 1) ? 1 : -1;
				if (verite!=prediction) {
				printf("ERREUR\n");
			//j'ajoute au w actuel (w(t+1) = w(t) - gamma*y*x)
				for (int j=0; j<784; j++)
					w[j] = w[j] + gamma*verite*images[i][j];
		}
}
		//step 3 : Test (t10k)
		float E=0;
			for(int i=0; i<10000; i++) {
				printf("%u\n",i);
				int inference = linear_classifier(w,test_images[i]);
				save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
			
				if((inference==1 && test_labels[i]!=1) || (inference==0 && test_labels[i]==1)) E++;
				printf("Erreur = %0.2f%%\n", (E*100)/i);
			 }
		


/*int NN;
		float mind = -1;
		
        for( int j=0; j<60000; j++) {
			float d = dist_sq(test_images[i], images[j]);
       		 if (d<mind || mind==-1) {
				mind = d;
				NN = j;
	   		}
	}
	int inference = labels[NN];
	save_jpg(test_images[i], 28, 28, "%u/%u.jpg", inference, i);
	if(test_labels[i] != inference){  E++;}
	printf("Erreur = %0.2f%%\n %d",(E*100)/i,i);	 	
	}

*/
	
return 0;
}

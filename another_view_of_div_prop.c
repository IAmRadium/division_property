// this program is an effort to implement the paper "another view of division property" by Anne Canteaut and Critiana Baura
// things to check before a fresh compilation with new set: 1. n, 2. 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned char a_power_u(unsigned char u, unsigned char a, unsigned char n){
	unsigned char ui,ai,flag=0;
	for(unsigned char i=0; i<log2(n); i++){
		ui=(u>>i)&0x01;
		ai=(a>>i)&0x01;
		if(ui>ai){
			flag=1;
			break;
		}
	}	
	if(flag==1) return 0;
	else return 1;
}

void calculate_G(unsigned char * G, unsigned char n){
	for(unsigned char u=0;u<n;u++){
		for(unsigned char a=0;a<n;a++){
			G[u*n+a]=a_power_u(u,a,n);
		}
	}
}

void printmatrix(unsigned char *G, unsigned char n){
	for(unsigned char u=0;u<n;u++){
		for(unsigned char a=0;a<n;a++){
			printf(" %d",G[u*n+a]);
		}
		printf("\n");
	}
}
void initialize_with_one(unsigned char *G, unsigned char n){
	for(unsigned char u=0;u<n;u++){
		for(unsigned char a=0;a<n;a++){
			G[u*n+a]=0x01;
		}
	}
}
int main(){
	unsigned char n, *G;
	//cout<<"Enter the value of n: ";
	//cin>>n;
	scanf("%hhd",&n);
	printf("%d\n",n );

	n=pow(2,n);
	printf("%d\n",n );
	G = (unsigned char*)malloc(n*n*sizeof(unsigned char));
	// X is the set, and the incodent vector of the set is the set with a '1' at position x ; for every value of of x in X.
	// we may have a set X={1,3,4} and the incident vector corresponding to the set is {0,1,0,1,1,0,0,0}
	// In this example we are giving directly the incident vector, though we can also give the set and create a method 
	// which will return the incident vector when given the set X.
	unsigned char X[]={0,1,0,1,1,0,0,0};
	initialize_with_one(G,n);
	 printmatrix(G,n);
	// calculate G matrix
	calculate_G(G,n);
	printf("after calculating G: \n");
	printmatrix(G,n);

	return 0;
}

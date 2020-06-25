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
/*
unsigned char * get_incident_vector(unsigned char *X, unsigned char size){
	return;
}
*/
void obtain_parity_set(unsigned char *G, unsigned char iv_x[], unsigned char *iv_ps, unsigned char n){
	unsigned char sum;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<n;j++){
			sum+=G[i*n+j]*iv_x[j];
		}
		iv_ps[i]=sum%2;
	}


}
int main(){ 
	// Initialize the input set
	unsigned char X[]={1,3,4};
	// iv_x= incident vector of set x; iv_ps= incident vector of parity set
	unsigned char n, *G, *iv_ps;
	//cout<<"Enter the value of n: ";
	//cin>>n;
	scanf("%hhd",&n);
	printf("%d\n",n );
	n=pow(2,n);
	printf("%d\n",n );
	G = (unsigned char*)malloc(n*n*sizeof(unsigned char));
	//iv_x= (unsigned char*)malloc(n*sizeof(unsigned char));
	iv_ps= (unsigned char*)malloc(n*sizeof(unsigned char)); 
	// X is the set, and the incodent vector of the set is the set with a '1' at position x ; for every value of of x in X.
	// we may have a set X={1,3,4} and the incident vector corresponding to the set is {0,1,0,1,1,0,0,0}
	// In this example we are giving directly the incident vector, though we can also give the set and create a method 
	// which will return the incident vector when given the set X.
	
	// ###incident_vectr_x = gte_incident_vector(X,n);
	unsigned char iv_x[]={0x00,0x01,0x00,0x01,0x01,0x00,0x00,0x00};
	// printmatrix(G,n);
	// calculate G matrix
	calculate_G(G,n);
	printf("after calculating G: \n");
	obtain_parity_set(G,iv_x,iv_ps,n);
	printmatrix(G,n);
	for(int i=0;i<n;i++) printf("%d\n", iv_ps[i]);
	return 0;
}

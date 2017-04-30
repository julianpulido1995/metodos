#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializar(float arreglo[13][13]);
void caso1(float u_past[13][13]);
void caso2(float u_past[13][13]);
void display(float u_present[13][13]);
void copy(float u_present[13][13],float u_past[13][13]);
void fijascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);
void fijascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);
void abiertascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);
void abiertascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);
void periodicascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);
void periodicascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt);

int main(){
 
	float nu = pow(10,-4);
	float dx = 0.1; //0.1 metros, para que cuadren unidades
	float dy = 0.1;
	float dt = 1.0; //dado nu de 0.001 y dx de 0.1-> la condicion de estabilidad es (nu*dt)/(dx^2)< 0.5, se obtiene dt<5
	int nx = 1.0;
	int ny = 1.0;
	int nt = 2500.0; //tiempo total de la simulacion

	float u_past1[13][13];// matrices para el primer caso
	float u_present1[13][13];   
	float u_past2[13][13];//matrices caso 2
	float u_present2[13][13];
 
	int i;
	int j;
	int k;
	
	inicializar(u_past1);
	inicializar(u_present1);
	inicializar(u_past2);
	inicializar(u_present2);
	
	
	caso1(u_past1);	
	
	//fijas tiempo 0, caso 1	
	FILE *fijasc1_to;
	fijasc1_to = fopen("f1c1to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(fijasc1_to,"%f\n",u_past1[i][j]);
		}		
	}
	fclose(fijasc1_to);
	
	float av1;
	float sum1 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum1 += u_past1[i][j];
		}
	}

	av1 = sum1/(169);
			
	
	
	//fijas tiempo 100, caso 1	
	
	for(k = 0;k<101;k++){
		
		fijascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	
	FILE *fijasc1_t100;
	fijasc1_t100 = fopen("f1c1t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(fijasc1_t100,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(fijasc1_t100);
	float av2;
	float sum2 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum2 += u_present1[i][j];
		}
	}

	av2 = sum2/(169);
	
	//fijas tiempo 2500, caso 1
	for(k = 101;k<nt +1;k++){
		
		fijascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	FILE *fijasc1_t2500;
	fijasc1_t2500 = fopen("f1c1t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(fijasc1_t2500,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(fijasc1_t2500);
	float av3;
	float sum3 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum3 += u_present1[i][j];
		}
	}

	av3 = sum3/(169);

	FILE *avc1f;
	avc1f = fopen("avc1f.txt","w");
	fprintf(avc1f,"%f\n",av1);	
	fprintf(avc1f,"%f\n",av2);
	fprintf(avc1f,"%f\n",av3);
	
	fclose(avc1f);



	//abiertas t0, caso 1

	inicializar(u_past1);
	inicializar(u_present1);
	caso1(u_past1);
	FILE *abiertasc1_to;
	abiertasc1_to = fopen("a1c1to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(abiertasc1_to,"%f\n",u_past1[i][j]);
		}		
	}
	fclose(abiertasc1_to);
	float av4;
	float sum4 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum4 += u_past1[i][j];
		}
	}

	av4 = sum4/(169);
	// abiertas t100, caso 1
	for(k = 0;k<101;k++){
		
		abiertascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	
	FILE *abiertasc1_t100;
	abiertasc1_t100 = fopen("a1c1t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(abiertasc1_t100,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(abiertasc1_t100);
	float av5;
	float sum5 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum5 += u_present1[i][j];
		}
	}

	av5 = sum5/(169);
	//abiertas t2500, caso 1
	for(k = 101;k<nt +1;k++){
		
		abiertascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	FILE *abiertasc1_t2500;
	abiertasc1_t2500 = fopen("a1c1t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(abiertasc1_t2500,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(abiertasc1_t2500);
	float av6;
	float sum6 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum6 += u_present1[i][j];
		}
	}

	av6 = sum6/(169);

	
	FILE *avc1a;
	avc1a = fopen("avc1a.txt","w");
	fprintf(avc1a,"%f\n",av4);	
	fprintf(avc1a,"%f\n",av5);
	fprintf(avc1a,"%f\n",av6);
	
	fclose(avc1a);


	//periodicas t0, caso 1
	inicializar(u_past1);
	inicializar(u_present1);
	caso1(u_past1);
	FILE *periodicasc1_to;
	periodicasc1_to = fopen("p1c1to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(periodicasc1_to,"%f\n",u_past1[i][j]);
		}		
	}
	fclose(periodicasc1_to);
	float av7;
	float sum7 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum7 += u_past1[i][j];
		}
	}

	av7 = sum7/(169);	

	//periodicas t100, caso 1
	for(k = 0;k<101;k++){
		
		periodicascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	
	FILE *periodicasc1_t100;
	periodicasc1_t100 = fopen("p1c1t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(periodicasc1_t100,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(periodicasc1_t100);
	float av8;
	float sum8 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum8 += u_present1[i][j];
		}
	}

	av8 = sum8/(169);
	//periodicas t2500, caso 1
	for(k = 101;k<nt +1;k++){
		
		periodicascaso1(u_past1,u_present1,nx,ny,nu,dy,dx,dt);
		copy(u_present1,u_past1);
	}
	FILE *periodicasc1_t2500;
	periodicasc1_t2500 = fopen("p1c1t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(periodicasc1_t2500,"%f\n",u_present1[i][j]);
		}		
	}
	fclose(periodicasc1_t2500);
	float av9;
	float sum9 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum9 += u_present1[i][j];
		}
	}

	av9 = sum9/(169);
	FILE *avc1p;
	avc1p = fopen("avc1p.txt","w");
	fprintf(avc1p,"%f\n",av7);	
	fprintf(avc1p,"%f\n",av8);
	fprintf(avc1p,"%f\n",av9);
	
	fclose(avc1p);


	

	//fijas caso 2, t0
	caso2(u_past2);
	FILE *fijasc2_to;
	fijasc2_to = fopen("fc2to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(fijasc2_to,"%f\n",u_past2[i][j]);
		}		
	}
	fclose(fijasc2_to);
	float av10;
	float sum10 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum10 += u_past2[i][j];
		}
	}

	av10 = sum10/(169);
	

	//fijas caso 2, t100
	for(k = 0;k<101;k++){
		
		fijascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	
	FILE *fijasc2_t100;
	fijasc2_t100 = fopen("fc2t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(fijasc2_t100,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(fijasc2_t100);
	float av11;
	float sum11 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum11 += u_present2[i][j];
		}
	}

	av11 = sum11/(169);
	
	//fijas caso 2, t2500
	for(k = 101;k<nt +1;k++){
		
		fijascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	FILE *fijasc2_t2500;
	fijasc2_t2500 = fopen("fc2t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(fijasc2_t2500,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(fijasc2_t2500);
	float av12;
	float sum12 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum12 += u_present2[i][j];
		}
	}

	av12 = sum12/(169);

	FILE *avc2f;
	avc2f = fopen("avc2f.txt","w");
	fprintf(avc2f,"%f\n",av10);	
	fprintf(avc2f,"%f\n",av11);
	fprintf(avc2f,"%f\n",av12);
	
	fclose(avc2f);


	
	//abiertas caso 2 , t0
	inicializar(u_past2);
	inicializar(u_present2);
	caso1(u_past2);
	FILE *abiertasc2_to;
	abiertasc2_to = fopen("ac2to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(abiertasc2_to,"%f\n",u_past2[i][j]);
		}		
	}
	fclose(abiertasc2_to);

	float av13;
	float sum13 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum13 += u_past2[i][j];
		}
	}

	av13 = sum13/(169);
	// abiertas caso 2, t 100
	for(k = 0;k<101;k++){
		
		abiertascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	
	FILE *abiertasc2_t100;
	abiertasc2_t100 = fopen("ac2t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(abiertasc2_t100,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(abiertasc2_t100);
	float av14;
	float sum14 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum14 += u_present2[i][j];
		}
	}

	av14 = sum14/(169);
	//abiertas caso 2, t2500
	for(k = 101;k<nt +1;k++){
		
		abiertascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	FILE *abiertasc2_t2500;
	abiertasc2_t2500 = fopen("ac2t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(abiertasc2_t2500,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(abiertasc2_t2500);
	float av15;
	float sum15 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum15 += u_present2[i][j];
		}
	}

	av15 = sum15/(169);

	FILE *avc2a;
	avc2a = fopen("avc2a.txt","w");
	fprintf(avc2a,"%f\n",av13);	
	fprintf(avc2a,"%f\n",av14);
	fprintf(avc2a,"%f\n",av15);
	
	fclose(avc2a);


	//periodicas caso 2, t0
	inicializar(u_past2);
	inicializar(u_present2);
	caso1(u_past2);
	FILE *periodicasc2_to;
	periodicasc2_to = fopen("pc2to.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    			fprintf(periodicasc2_to,"%f\n",u_past2[i][j]);
		}		
	}
	fclose(periodicasc2_to);
	float av16;
	float sum16 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum16 += u_past2[i][j];
		}
	}

	av16 = sum16/(169);
	//periodicas caso 2, t0
	for(k = 0;k<101;k++){
		
		periodicascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	
	FILE *periodicasc2_t100;
	periodicasc2_t100 = fopen("pc2t100.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(periodicasc2_t100,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(periodicasc2_t100);
	float av17;
	float sum17 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum17 += u_present2[i][j];
		}
	}

	av17 = sum17/(169);
	//periodicas caso 2, t2500
	for(k = 101;k<nt +1;k++){
		
		periodicascaso2(u_past2,u_present2,nx,ny,nu,dy,dx,dt);
		copy(u_present2,u_past2);
	}
	FILE *periodicasc2_t2500;
	periodicasc2_t2500 = fopen("pc2t2500.txt","w");
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++) {
    		fprintf(periodicasc2_t2500,"%f\n",u_present2[i][j]);
		}		
	}
	fclose(periodicasc2_t2500);	
	float av18;
	float sum18 = 0.0;
	for(i=0;i<13;i++) {
		for(j=0;j<13;j++){
			sum18 += u_present2[i][j];
		}
	}

	av18 = sum18/(169);
	FILE *avc2p;
	avc2p = fopen("avc2p.txt","w");
	fprintf(avc2p,"%f\n",av16);	
	fprintf(avc2p,"%f\n",av17);
	fprintf(avc2p,"%f\n",av18);
	
	fclose(avc2p);
		
return 0;

}
//caso 1, inicializacion 
void caso1(float  u_past[13][13]){
	int i;
	int j;
		for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){
				if(i>=5 && i<=7){
					if(j>=3 && j<=4){	
						u_past[i][j] = 100;
					}
					else{
						u_past[i][j] = 50;
					}
				}
				else{
					u_past[i][j] = 50;
				
			        }	
			}
		}			
}
//caso 2 inicializacion
void caso2(float u_past[13][13]){	
	int i;
	int j;
		for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){
				if(i>=5 && i<=7){
					if(j>=3 && j<=4){	
						u_past[i][j] = 100;
					}
					else{
						u_past[i][j] = 50;
					}
				}
				else{
					u_past[i][j] = 50;
				
			        }	
			}
		}	
		
}
void copy(float u_present[13][13],float u_past[13][13]){
	int i;
	int j;
		for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				u_past[i][j] = u_present[i][j];
			}
				
		}
}
void fijascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){
	int i;
	int j;//condiciones fijas, caso 1
		for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				if(i == 0||i == 12||j == 0||j == 12){
					u_past[i][j] = 50.0;
					u_present[i][j] = 50.0;
				}
			}
		}
		
		for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){
				u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
			}
		}
				
}

void fijascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){

	int i;
	int j;//condiciones fijas, caso 2
		for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				if(i == 0||i == 12||j == 0||j == 12){
					u_past[i][j] = 50.0;
					u_present[i][j] = 50.0;
				}
			}
		}
		
		
		for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){								
					u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
				}
		}

		for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				if(i>=5 && i<=7){
					if(j>=3 && j<=4){	
						u_present[i][j] = 100;
					}
				}
			}
		}	
		
}

void abiertascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){
	int i;
	int j;		
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones abiertas
		for(j = 0;j<13;j++){
				if(i == 0){
					if(j>= 1 && j<12){
						u_past[i][j] = u_past[i+1][j];
					}
				}
				else if(i == 12){
					if(j>= 1 && j<12){
						u_past[i][j] = u_past[i-1][j];
					}	
				}
				else if(j == 0){
					if(i>= 1 && i<12){
						u_past[i][j] = u_past[i][j+1];
					}
				}
				else if(j == 12){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j-1];
					}	
				}
		}
	}

	for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){								
					u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
				}
		}
	

	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones abiertas, nueva matriz
		for(j = 0;j<13;j++){
				if(i == 0){
					if(j>= 1 && j<12){
						u_present[i][j] = u_present[i+1][j];
					}
				}
				else if(i == 12){
					if(j>= 1 && j<12){
						u_present[i][j] = u_present[i-1][j];
					}	
				}
				else if(j == 0){
					if(i>= 1 && i<12){
						u_present[i][j] = u_present[i][j+1];
					}
				}
				else if(j == 12){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j-1];
					}	
				}
		}
	}
	
}
void abiertascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){

	int i;
	int j;	
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones abiertas
		for(j = 0;j<13;j++){
				if(i == 0){
					if(j>= 1 && j<12){
						u_past[i][j] = u_past[i+1][j];
					}
				}
				else if(i == 12){
					if(j>= 1 && j<12){
						u_past[i][j] = u_past[i-1][j];
					}	
				}
				else if(j == 0){
					if(i>= 1 && i<12){
						u_past[i][j] = u_past[i][j+1];
					}
				}
				else if(j == 12){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j-1];
					}	
				}
		}
	}
	for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){								
					u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
			}
	}
	
	for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				if(i>=5 && i<=7){
					if(j>=3 && j<=4){	
						u_present[i][j] = 100;
					}
				}
			}
	}	
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones abiertas, nueva matriz
		for(j = 0;j<13;j++){
				if(i == 0){
					if(j>= 1 && j<12){
						u_present[i][j] = u_present[i+1][j];
					}
				}
				else if(i == 12){
					if(j>= 1 && j<12){
						u_present[i][j] = u_present[i-1][j];
					}	
				}
				else if(j == 0){
					if(i>= 1 && i<12){
						u_present[i][j] = u_present[i][j+1];
					}
				}
				else if(j == 12){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j-1];
					}	
				}
		}
	}
	
	
}
void periodicascaso1(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){
	int i,j;	
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones periodicas
		for(j = 0;j<13;j++){
				if(j == 12){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j-11];
					}		
				}
				else if(j==0){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j+11];
					}	
				}
				else if(i == 12){
					if(j>=1 && j<12){
						u_past[i][j] = u_past[i-11][j];
					}
				}
				else if(i==0){
					if(j>=1 && j<12){
						u_past[i][j] = u_past[i+11][j];
					}	
				}
		}
	}
		
	for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){								
					u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
			}
	}

	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones periodicas, nueva matriz
		for(j = 0;j<13;j++){
				if(j == 12){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j-11];
					}		
				}
				else if(j==0){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j+11];
					}	
				}
				else if(i == 12){
					if(j>=1 && j<12){
						u_present[i][j] = u_present[i-11][j];
					}
				}
				else if(i==0){
					if(j>=1 && j<12){
						u_present[i][j] = u_present[i+11][j];
					}	
				}
		}
	}
		
	
}
void periodicascaso2(float u_past[13][13], float u_present[13][13], int nx, int ny, float nu, float dy, float dx, float dt){
	int i,j;	
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones periodicas
		for(j = 0;j<13;j++){
				if(j == 12){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j-11];
					}		
				}
				else if(j==0){
					if(i>=1 && i<12){
						u_past[i][j] = u_past[i][j+11];
					}	
				}
				else if(i == 12){
					if(j>=1 && j<12){
						u_past[i][j] = u_past[i-11][j];
					}
				}
				else if(i==0){
					if(j>=1 && j<12){
						u_past[i][j] = u_past[i+11][j];
					}	
				}
		}
	}
	for(i = 1;i<12;i++){
			for(j = 1;j<12;j++){								
					u_present[i][j] = u_past[i][j] + (((nu*dt)/pow(dx,2))*(u_past[i+1][j]-2*u_past[i][j] + u_past[i-1][j])) + (((nu*dt)/pow(dy,2))*(u_past[i][j+1]-2*u_past[i][j] + u_past[i][j-1]));
			}
	}
	
	for(i = 0;i<13;i++){
			for(j = 0;j<13;j++){
				if(i>=5 && i<=7){
					if(j>=3 && j<=4){	
						u_present[i][j] = 100;
					}
				}
			}
	}	
	for(i = 0;i<13;i++){//inicializo la frontera de las condiciones periodicas, nueva matriz
		for(j = 0;j<13;j++){
				if(j == 12){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j-11];
					}		
				}
				else if(j==0){
					if(i>=1 && i<12){
						u_present[i][j] = u_present[i][j+11];
					}	
				}
				else if(i == 12){
					if(j>=1 && j<12){
						u_present[i][j] = u_present[i-11][j];
					}
				}
				else if(i==0){
					if(j>=1 && j<12){
						u_present[i][j] = u_present[i+11][j];
					}	
				}
		}
	}		
}	
void display(float arreglo[13][13]){//print en la terminal del resultado-> para ver si corre
	int i;
	int j;
	for(i=0;i<13;i++){
		for(j=0;j<13;j++){
			printf("%f\n",arreglo[i][j]);		
		}
	}	
}
void inicializar(float arreglo[13][13]){

	int i;
	int j;
	for(i = 0;i<13;i++){
		for(j =0;j<13;j++){
			arreglo[i][j] = 0.0;
		}
	}
	
}	










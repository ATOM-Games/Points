#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdio>
#include <conio.h>

double Line(double Ax, double Ay, double Bx, double By)
{
	return sqrt( (Bx-Ax)*(Bx-Ax) + (By-Ay)*(By-Ay) );
}
double Triangle(double Ax, double Ay, double Bx, double By, double Cx, double Cy)
{
	double ab, bc, ca, p, S;
	ab = Line(Ax, Ay, Bx, By); bc = Line(Bx, By, Cx, Cy); ca = Line(Cx, Cy, Ax, Ay);
	if(ab+bc>ca && bc+ca>ab && ab+ca>bc){
		p=(ab+bc+ca)/2;
		S=sqrt(p*(p-ab)*(p-bc)*(p-ca));
	}else{
		S=-1;
	}
	return S;
}
double Square(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy)
{
	double ab, bc, cd, da, ac, bd, S;
	ab = Line(Ax, Ay, Bx, By); bc = Line(Bx, By, Cx, Cy); cd = Line(Cx, Cy, Dx, Dy); da = Line(Dx, Dy, Ax, Ay);
	ac = Line(Ax, Ay, Cx, Cy); bd = Line(Bx, By, Dx, Dy);
	if(ab==bc && bc==cd && cd==da && ac==bd){
		S=ab*bc;
	}else{
		S=-1;
	}
	return S;
}


int main(array<System::String ^> ^args)
{
	double XXX[10]={1, 4, 1, 4, 4, 7, 5, 8, 2, 7};
	double YYY[10]={1, 1, 4, 4, 7, 4, 3, 4, 4, 2};

	//-------------------------Line
	double MaxLenghtLin=0, A_mdl_x=0, A_mdl_y=0, B_mdl_x=0, B_mdl_y=0;
	for(int a=0; a<9; a++){
		for(int b=a+1; b<10; b++){
			if(a!=b){
				double j = Line(XXX[a], YYY[a], XXX[b], YYY[b]);
				if(j>MaxLenghtLin){
					MaxLenghtLin=j;
					A_mdl_x=XXX[a];	A_mdl_y=YYY[a];
					B_mdl_x=XXX[b];	B_mdl_y=YYY[b];
				}
			}
		}
	}
	printf("MaxDlin %g, A( %g , %g ) B( %g , %g ); \n", MaxLenghtLin, A_mdl_x, A_mdl_y, B_mdl_x, B_mdl_y);
	//-------------------------Triangle
	double MaxPloTre=0, A_mtp_x=0, A_mtp_y=0, B_mtp_x=0, B_mtp_y=0, C_mtp_x=0, C_mtp_y=0;
	for(int a=0; a<8; a++){
		for(int b=a+1; b<9; b++){
			for(int c=b+1; c<10; c++){
				if(a!=b && b!=c){
					double j = Triangle(XXX[a], YYY[a], XXX[b], YYY[b], XXX[c], YYY[c]);
					if(j>MaxPloTre){
						MaxPloTre=j;
						A_mtp_x=XXX[a], A_mtp_y=YYY[a];
						B_mtp_x=XXX[b], B_mtp_y=YYY[b];
						C_mtp_x=XXX[c], C_mtp_y=YYY[c];
					}
				}
			}
		}
	}
	printf("Max Ploshad Treygolnik %g, A( %g , %g ) B( %g , %g ) C( %g , %g ); \n", MaxPloTre, A_mtp_x, A_mtp_y, B_mtp_x, B_mtp_y, C_mtp_x, C_mtp_y);
	//-------------------------Square
	double MaxPloKva=0, A_mkp_x=0, A_mkp_y=0, B_mkp_x=0, B_mkp_y=0, C_mkp_x=0, C_mkp_y=0, D_mkp_x=0, D_mkp_y=0;
	for(int a=0; a<7; a++){
		for(int b=a+1; b<8; b++){
			for(int c=b+1; c<9; c++){
				for(int d=c+1; d<10; d++){
					if(a!=b && b!=c && c!=d){
						double j = Square(XXX[a], YYY[a], XXX[b], YYY[b], XXX[c], YYY[c], XXX[d], YYY[d]);
						if(j>MaxPloKva){
							MaxPloKva=j;
							A_mkp_x=XXX[a], A_mkp_y=YYY[a];
							B_mkp_x=XXX[b], B_mkp_y=YYY[b];
							C_mkp_x=XXX[c], C_mkp_y=YYY[c];
							D_mkp_x=XXX[c], D_mkp_y=YYY[c];
						}
					}
				}
			}
		}
	}
	printf("Max Ploshad Square %g, A( %g , %g ) B( %g , %g ) C( %g , %g ) D( %g , %g ); \n", MaxPloKva, A_mkp_x, A_mkp_y, B_mkp_x, B_mkp_y, C_mkp_x, C_mkp_y, D_mkp_x, D_mkp_y);




    system("Pause");
}




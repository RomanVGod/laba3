

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

inline double f(double p0,double p1, double p2, double p3, double t)
{
	return p0*(1 - t) *(1 - t) * (1 - t) +p1* t * (1 - t) * (1 - t) + 3 * p2 *t * t * (1 - t) + p3 * t * t*t; //посчитаная формула
}
inline double g(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (2 * t * t * t - 3 * t * t + 1) + p3*(-2 * t * t * t + 3 * t * t)+(p1-p0)*(t*t*t-2*t*t+t)+(p3-p2)*(t*t*t-t*t);
}
void Render(double delta_time)
{
	
	double P0[] = { 0,0,0 }; 
	double P1[] = { 4,6,7 };
	double P2[] = { 2,2,0 };
	double P3[] = { 10,10,10 };
	
	double P[4];
	glBegin(GL_LINE_STRIP);
	glVertex3dv(P0);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();

	glLineWidth(3); 
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		P[0] = f(P0[0], P1[0], P2[0], P3[0], t);
		P[1] = f(P0[1],P1[1], P2[1], P3[1], t);
		P[2] = f(P0[2], P1[2], P2[2], P3[2], t);
		glVertex3dv(P); 
	}
	glEnd();
	glLineWidth(1); 

	double R0[] = { 0,0,0 };
	double R1[] = { 2,0,2 };
	double R2[] = { -10,-5,0 };
	double R3[] = { 0,0,8 };
	glBegin(GL_LINE_STRIP);
	glVertex3dv(R0);
	glVertex3dv(R1);
	glVertex3dv(R2);
	glVertex3dv(R3);
	glEnd();

	glLineWidth(3);
	double R[3];
	glBegin(GL_LINE_STRIP);

	
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		R[0] = f(R0[0], R1[0], R2[0], R3[0], t);
		R[1] = f(R0[1], R1[1], R2[1], R3[1], t);
		R[2] = f(R0[2], R1[2], R2[2], R3[2], t);
		glVertex3dv(R);
	}
	glEnd();
	glLineWidth(1);

	double K0[] = { 0,0,0 };
	double K1[] = { 3,0,2 };
	double K2[] = { -7,-5,0 };
	double K3[] = { 0,0,4 };
	glBegin(GL_LINES);
	glVertex3dv(K0);
	glVertex3dv(K1);
	glVertex3dv(K2);
	glVertex3dv(K3);
	glEnd();

	glLineWidth(3);
	double K[3];
	glBegin(GL_LINE_STRIP);


	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		K[0] = g(K0[0], K1[0], K2[0], K3[0], t);
		K[1] = g(K0[1], K1[1], K2[1], K3[1], t);
		K[2] = g(K0[2], K1[2], K2[2], K3[2], t);
		glVertex3dv(K);
	}
	glEnd();
	glLineWidth(1);

	double H0[] = { 0,0,0 };
	double H1[] = { 10,3,2 };
	double H2[] = { -7,-10,0 };
	double H3[] = { -3,2,1 };
	glBegin(GL_LINES);
	glVertex3dv(H0);
	glVertex3dv(H1);
	glVertex3dv(H2);
	glVertex3dv(H3);
	glEnd();

	glLineWidth(3);
	double H[3];
	glBegin(GL_LINE_STRIP);


	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		H[0] = g(H0[0], H1[0], H2[0], H3[0], t);
		H[1] = g(H0[1], H1[1], H2[1], H3[1], t);
		H[2] = g(H0[2], H1[2], H2[2], H3[2], t);
		glVertex3dv(H);
	}
	glEnd();
	glLineWidth(1);
}


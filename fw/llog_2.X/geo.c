#include <math.h>
#include "hw.h"

#define	PI		3.141592653589

#define		LL_AN_AVG_SIZE		11
#define		LL_AN_AVG_MID		((LL_AN_AVG_SIZE/2)+1)
#define		LL_AN_DIFF_HALFSIZE	4

uint16_t ll_log_tmp[LL_LOG_SIZE];


double deg_rad (double deg);
double rad_deg (double rad);

double deg_rad (double deg)
	{
	return PI*2.0*(deg/360.0);
	}

double rad_deg (double rad)
	{
	return 360.0*(rad/(PI*2.0));
	}

double get_latitude (double daylength, double angle, double declination)
	{
	double omega, a,b,c,d,theta,fi,lat,sign;
	omega = 180 * daylength/24.0;
	sign = 1.0;
	if (declination<0.0) sign = -1.0;
//	cos(omega)cos(lat)cos(dec) - sin(angle) + sin(lat)sin(dec) = 0	
//  convert to 	
//	a*sin(lat) + b*cos(lat) = c
	a = sin(deg_rad(declination));
	b = cos(deg_rad(omega))*cos(deg_rad(declination));
	c = sin(deg_rad(angle));
	d = sqrt(a*a+b*b);
	theta = rad_deg(asin(b/d));
	fi = rad_deg(asin(c/d));
	lat = (fi-theta)*sign;
	return lat;
	}

double get_longitude (double solar_noon, double eq_of_time)
	{
	double diff,longit;
	diff = 12.00 - solar_noon;
	longit = 180.0 * diff / 12.0;
	diff = - 180*(eq_of_time/(12.0*60.0));
	longit = longit - diff;
	return longit;
	}


const int16_t days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
double get_declination (unsigned int day, unsigned int month)
	{
	int16_t doy;
	double declination;
	doy = days[month] + day;
	declination = 23.45*sin(PI*2.0*(doy-81)/365.0);
	return declination;
	}

double get_eq_time (unsigned int day, unsigned int month)
	{
	int16_t doy;
	double eot;
	doy = days[month] + day;
	eot = -7.655*sin(2*PI*(doy/365.0)) + 9.873*sin(3.558+(4*PI*(doy/365)));
	return eot;
	}


int analyze_ll_data (unsigned int * data, unsigned int len, double * day_length, double * solar_noon)
	{
	int16_t diff,diff_min_val=0,diff_max_val=0;
	uint16_t diff_min_ptr=0,diff_max_ptr=0;
	double dl,sn;
	int16_t i,j,temp;
	for (i=0;i<LL_LOG_SIZE-LL_AN_AVG_SIZE;i++)
		{
		temp = 0;
		for (j=0;j<LL_AN_AVG_SIZE;j++)
			{
			temp = temp + data[i+j];
			}
		ll_log_tmp[i+LL_AN_AVG_MID-1] = temp / 8;
		}
	for (i=LL_AN_DIFF_HALFSIZE;i<(LL_LOG_SIZE-LL_AN_DIFF_HALFSIZE);i++)
		{
		diff = ll_log_tmp[i+LL_AN_DIFF_HALFSIZE] - ll_log_tmp[i-LL_AN_DIFF_HALFSIZE];
		if (diff>diff_max_val)
			{
			diff_max_val = diff;
			diff_max_ptr = i;
			}
		if (diff<diff_min_val)
			{
			diff_min_val = diff;
			diff_min_ptr = i;
			}
		}
	dl = (diff_min_ptr - diff_max_ptr)* LOG_PERIOD;
	dl = dl / 60.0;
	sn = (diff_min_ptr * LOG_PERIOD) / 60.0;
	sn = (sn - (dl/2.0));
	*day_length = dl;
	*solar_noon = sn;
	return 0;
	}


void prepare_mem_log (double lat, double lon, uint8_t * mem_log)
	{
	uint16_t tmp;
	lat = (lat+180.0) * 100.0;
	lon = (lon+180.0) * 100.0;
	tmp = lat;
	mem_log[0]= (tmp>>8)&0xFF;
	mem_log[1]= (tmp>>0)&0xFF;
	tmp = lon;
	mem_log[2]= (tmp>>8)&0xFF;
	mem_log[3]= (tmp>>0)&0xFF;
	mem_log[4]= 0xFF;	
	mem_log[5]= 0xFF;	
	mem_log[6]= 0xFF;	
	mem_log[7]= 0xFF;	
	}

void read_mem_log (double * lat, double * lon, uint8_t * mem_log)
	{
	uint16_t tmp;
	double dtemp;
	tmp = mem_log[1];
	tmp = tmp << 8;
	tmp = tmp + mem_log[0];
	dtemp = tmp;
	dtemp = (dtemp / 100.0) - 180.0;
	*lat = dtemp;
	tmp = mem_log[3];
	tmp = tmp << 8;
	tmp = tmp + mem_log[2];
	dtemp = tmp;
	dtemp = (dtemp / 100.0) - 180.0;
	*lon = dtemp;
	}
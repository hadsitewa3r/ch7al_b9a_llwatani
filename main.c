#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

unsigned int nhar_b9a(int achmn_chhr, int l3am){

	uint8_t liyam[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	unsigned int count = 0;

	if(l3am % 4)
		liyam[1]++;

	if (achmn_chhr < 6)
		for(uint8_t i = achmn_chhr; i != 5; i++)
			count += liyam[i];

	else if (achmn_chhr == 6)
		return 0;

	else{
		for(uint8_t i = achmn_chhr; i != 12; i++)
			count += liyam[i];
		for(uint8_t i = 0; i != 5; i++)
			count += liyam[i];
	}

		return count;
}


int main(void){

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int chhr = 4 - tm.tm_mon;
	int nhar = 36 - tm.tm_mday;
	int iyam = nhar + nhar_b9a(tm.tm_mon + 1, tm.tm_year);
	int sa3a = 32 - tm.tm_hour;
	int d9i9a = 60 - tm.tm_min;

	const char* wahaliyam;
	const char* wahanharat;

	if (chhr < 0)
		chhr = 18 - tm.tm_mon;

	if (nhar == 0)
		nhar = 0;

	if (sa3a == 24)
		sa3a = 0;

	if (d9i9a == 60)
		d9i9a = 0;

	if (iyam < 11)
			wahaliyam = "iyam";
	else
			wahaliyam = "nhar";
	
	if (nhar < 11)
			wahanharat = "iyam";
	else
			wahanharat = "nhar";

	printf("lyoma: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("b9a lik: %02d chhr, %02d %s (%02d %s), %02d sa3a, %02d d9i9a\n", chhr, nhar, wahanharat, iyam, wahaliyam, sa3a, d9i9a);

	return EXIT_SUCCESS;
}

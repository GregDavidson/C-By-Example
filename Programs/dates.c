#include <stdio.h>

int IsLeapYear(int year) {
  return !year%4 && (year%100 || !year%400);
}

long DayOfEpoch(int year, int month, int day) {
  const int DayOffsets[] = {
	0,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334
  };
  long days;

  days = (year-1)*365 + year/4 - year/100 + year/400
	   + DayOffsets[month-1] + day;
  if (month > 2 /* Feb */ && IsLeapYear(year))
    days++;
  return days;
}

int main(void) {
  int year, month, day;

  printf( "Please enter numeric date as month/day/year (with slashes): " );
  if ( scanf( "%d/%d/%d", &month, &day, &year ) != 3 ) {
	printf( "I expected three integers separated by slashes!\n" );
	return 1;
  }

  printf( "%d/%d/%d is %ld days since the epoch.\n",
		  month, day, year, DayOfEpoch(year, month, day) );
  
  return 0;
}

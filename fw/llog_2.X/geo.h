

double get_latitude (double daylength, double angle, double declination);
int analyze_ll_data (unsigned int * data, unsigned int len, double * day_length, double * solar_noon);
double get_declination (unsigned int day, unsigned int month);
double get_longitude (double solar_noon, double eq_of_time);
double get_eq_time (unsigned int day, unsigned int month);
void prepare_mem_log (double lat, double lon, uint8_t * mem_log);
void read_mem_log (double * lat, double * lon, uint8_t * mem_log);


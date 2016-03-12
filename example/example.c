/* This is an example program for collecting and parsing data from the MTK3339 GPS.
	Note that this example starts, collects, and prepares the GPS data for presentation.
	It is up to the user to decide what to do with it, but the comments should make
	clear where and how to access the data. This example uses the USART library from
	the book "MAKE: AVR Programming" by Elliot Williams. The USART functions are
	defined by MACROS in the header file so the user can substitute their own library
	if desired. This library was tested using the Adafruit Ultimate GPS Breakout Board.

	GPS settings can be tweaked in the gps_init() function in GPS.c.
*/

#include <util/delay.h>
#include "../GPS.h"

int main( void )
{
	gps_init();

	while( 1 )
	{			
		struct GPS_Str_Data gpsRawData; // Data in string form
		struct GPS_Data gpsData; // Converted data

		// Get the string data from GPS
		gps_getData( &gpsRawData );

		// Parse string data into ints and floats
		gpsData = gps_parseData( &gpsRawData );

		// If GPS has a signal fix
		if ( gpsData.fix )
		{
			/* Here you are now free to use the following available data from the GPS.

			gpsData.fix (int) - 1 if has fix, otherwise zero
			gpsData.latitude (float) - latitude in decimal format, not NMEA Minutes format
			gpsData.longitude (float) - longitude in decimal format, not NMEA Minutes format */
		}
		else
		{
			// This is area executes when the GPS has not yet aquired, or has lost signal fix.
		}

		_delay_ms(1000); // Wait one second
	}
} 

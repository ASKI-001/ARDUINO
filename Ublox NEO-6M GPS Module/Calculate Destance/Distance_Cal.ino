#include <TinyGPS++.h> //by Mikal Hart
#include <SoftwareSerial.h>
#include <math.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

// Reference location (latitude and longitude) 6.8092261029116345, 79.99088024017773 
const double refLatitude = 6.8092261029116345;  // Example: ITUM latitude
const double refLongitude = 79.99088024017773; // Example: ITUM longitude

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);

  Serial.println(F("GPS Point RealTime Distance Calculator"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by ASKI001"));
  Serial.println();
}

void loop()
{
  // Process GPS data
  while (ss.available() > 0)
  {
    char c = ss.read();
    if (gps.encode(c)) // Process the GPS data
    {
      // Check if the GPS location is valid
      if (gps.location.isValid())
      {
        // Get current latitude and longitude
        double currentLatitude = gps.location.lat();
        double currentLongitude = gps.location.lng();

        // Calculate distance in meters
        double distance = calculateDistance(refLatitude, refLongitude, currentLatitude, currentLongitude);

        // Display information
        displayInfo(currentLatitude, currentLongitude, distance);
      }
      else
      {
        Serial.println(F("Waiting for valid GPS fix..."));
      }
    }
  }

  // Check if GPS is not detected
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while (true);
  }
}

void displayInfo(double lat, double lng, double distance)
{

  //Show GPS Module Current Location
  Serial.print(F("Location: "));
  Serial.print(lat, 15); //15 - Decimals Places Count
  Serial.print(F(","));
  Serial.print(lng, 15); //15 - Decimals Places Count

  //Show Distance between GPS Module and Given Location
  Serial.print(F("  Distance from reference: "));
  Serial.print(distance, 2); // Display distance with 2 decimal places
  Serial.println(F(" meters"));
}


//Use haversine formula to calculate Distance
double calculateDistance(double lat1, double lon1, double lat2, double lon2)
{
  // Earth's radius in meters
  const double earthRadius = 6371000.0;

  // Convert latitude and longitude from degrees to radians
  lat1 = degToRad(lat1);
  lon1 = degToRad(lon1);
  lat2 = degToRad(lat2);
  lon2 = degToRad(lon2);

  // Difference in coordinates
  double dLat = lat2 - lat1;
  double dLon = lon2 - lon1;

  // Haversine formula
  double a = sin(dLat / 2.0) * sin(dLat / 2.0) +
             cos(lat1) * cos(lat2) *
             sin(dLon / 2.0) * sin(dLon / 2.0);
  double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  // Calculate distance in meters
  double distance = earthRadius * c;

  return distance;
}

// Renamed function to avoid conflict with the `radians` macro
double degToRad(double degrees)
{
  return degrees * M_PI / 180.0;
}

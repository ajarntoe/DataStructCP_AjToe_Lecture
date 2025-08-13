#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "csv.h"
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

class McLocation {
  // write your class here
public:
  double lat,lon;
  string name;
  string address;

  double dist; // the key for sorting

  McLocation(double lat,double lon,string name,string address) {
    this->lat = lat;
    this->lon = lon;
    this->name = name;
    this->address = address;
  }
};

// calculation of distance 
#define pi 3.14159265358979323846
double deg2rad(double deg) { return (deg * pi /180.0); }
double rad2deg(double rad) { return (rad * 180.0 / pi); }

double distance(double lat1, double lon1, double lat2, double lon2) {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  dist = dist * 1.609344; // convert to KM
  return (dist);
}


int main() {
  // user input
  double targetLon,targetLat;
  cout << "Enter latitude "; cin >> targetLat;
  cout << "Enter longitude "; cin >> targetLon;
  cout << "You entered: " << targetLat << "," << targetLon << endl;

  //read input data
  ifstream inputFile("mcdonalds.csv");
  string line;
  multimap<double,McLocation> location;
  while ( getline(inputFile,line)) {
    CSVLine csv(line);
    double lon,lat;
    string name;
    string address;
    // the third column is the name
    lon = atof(csv.next().c_str());
    lat = atof(csv.next().c_str());
    name = csv.next();
    address = csv.next();
    //cout << lat << " : " << lon << " : " << name << " : " << address << endl;
    McLocation loc(lat,lon,name,address);
    double dist = distance(targetLat,targetLon,lat,lon);
    location.insert(make_pair(dist,loc));
  }
  inputFile.close();

  //find nearest
  cout << "10 nearest McDonals are " << endl;
  cout << std::fixed << std::setprecision(4); 
  int count = 0;
  for (multimap<double,McLocation>::iterator it = location.begin();count < 10;count++,it++) {
    cout << "Distance: " << it->first << "km Location: " << it->second.lat << "," << it->second.lon << " Address: " << it->second.address << endl;

  }
}

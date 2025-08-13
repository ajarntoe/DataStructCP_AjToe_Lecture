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


double targetLat,targetLon;
bool nearer(const McLocation &a,const McLocation &b) {
  double dist1 = distance(targetLat,targetLon,a.lat,a.lon);
  double dist2 = distance(targetLat,targetLon,b.lat,b.lon);
  return dist1 < dist2;
}

int main() {
  // user input
  double lon,lat;
  cout << "Enter latitude "; cin >> lat;
  cout << "Enter longitude "; cin >> lon;
  cout << "You entered: " << lat << "," << lon << endl;
  targetLat = lat;
  targetLon = lon;

  //read input data
  ifstream inputFile("mcdonalds.csv");
  string line;
  vector<McLocation> location;
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
    location.push_back(McLocation(lat,lon,name,address));
  }
  inputFile.close();

  //find nearest
  sort(location.begin(),location.end(),nearer);
  cout << "10 nearest McDonals are " << endl;
  cout << std::fixed << std::setprecision(4); 
  for (int i = 0;i < 10;i++) {
    cout << "Distance: " << distance(lat,lon,location[i].lat,location[i].lon) << "km Location: " << location[i].lat << "," << location[i].lon << " Address: " << location[i].address << endl;
  }
}

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;
        vector<double> v;
        v.push_back(kelvin); 
        v.push_back(fahrenheit);
        return v;
    }
};
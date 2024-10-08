// class Solution {
// public:
//     vector<double> convertTemperature(double celsius) {
//         double kelvin = celsius + 273.15;
//         double fahrenheit = celsius * 1.80 + 32.00;
//         vector<double> v;
//         v.push_back(kelvin); 
//         v.push_back(fahrenheit);
//         return v;
//     }
// };

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32.0};
    }
};

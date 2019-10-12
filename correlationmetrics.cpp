#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
#include <array>
#include <cmath>
using namespace std;

double PC1_A [10000];
double PC1_B [10000];

double find_Mean(double arr[], int n);
double find_SD(double data[], double mean, int n);
double find_Covariance(double arr_x[], double arr_y[], double mean_x, double mean_y, int n);

int main() {
   string line;
   // opens pc1_a in read mode
   ifstream pc1_a; 
   pc1_a.open("XR_Assessment_-_PC1_A.CSV"); 
   //handles if file PC1_A can't be opened
   if (!pc1_a.is_open()) {
        cerr << "Input file XR_Assessment_-_PC1_A.CSV cannot be opened." << endl;
        return -1;
    }
	int i = 0;
	getline(pc1_a, line);
	while (getline(pc1_a, line)) {
            line.erase(0,11); // removes everything but the price.
			line.erase(line.size() - 1); // remove \r from end of string
			PC1_A[i] = atof(line.c_str());
		i++;
    }
	
    // open pc1_b in read mode.
   ifstream pc1_b; 
   pc1_b.open("XR_Assessment_-_PC1_B.CSV"); 
   //handles if file PC1_B can't be opened
   if (!pc1_b.is_open()) {
        cerr << "Input file XR_Assessment_-_PC1_B.CSV cannot be opened." << endl;
        return -1;
    }
    
	i = 0;
	getline(pc1_b, line);
	while (getline(pc1_b, line)) {
            line.erase(0,11); // removes everything but the price.
			line.erase(line.size() - 1); // remove \r from end of string
			PC1_B[i] = atof(line.c_str());
		i++;
    }
	
	double mean_a = find_Mean(PC1_A, 10000);
	double mean_b = find_Mean(PC1_B, 10000);
	
	double sd_a = find_SD(PC1_A, mean_a, 10000);
	double sd_b = find_SD(PC1_B, mean_b, 10000);
	
	double cov = find_Covariance(PC1_A, PC1_B, mean_a, mean_b, 10000);
	//calculates correlation with covariance and standard deviation
	double correlation = cov / (sd_a * sd_b);
	
	printf ("\nthe mean of PC1_A: %f\n", mean_a);
	printf ("the mean of PC1_B: %f\n", mean_b);
	printf ("the standard Deviation of PC1_A: %f\n", sd_a);
	printf ("the standard Deviation of PC1_B: %f\n", sd_b);
	printf ("the Covariance between PC1_A and PC1_B: %f\n", cov);
	printf ("\nthe Correlation between PC1_A and PC1_B: %f\n\n", correlation);
	
	
	
	
	return 0;
}
//finds mean of a data set
double find_Mean(double arr[] , int n){
	double sum = 0.0;
	for (int i = 0; i < n; i++){ 
        sum += arr[i];
	}
	
	return sum / (double) n;
}
//finds standard Deviation of data set
double find_SD(double data[], double mean, int n){
    double standardDeviation = 0.0;
    for(int i = 0; i < n; ++i)
        standardDeviation += pow(data[i] - mean, 2);
    return sqrt(standardDeviation / ((double )n - 1.0));
}
// Function to find covariance between two sets of data 
double find_Covariance(double arr_x[], double arr_y[], double mean_x, double mean_y, int n) { 
    double sum = 0.0; 
    for(int i = 0; i < n; i++){ 
        sum += (arr_x[i] - mean_x) * (arr_y[i] - mean_y); 
	}
	n--;
    return sum / (double)(n); 
}

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

struct DataPoint {
    double gender;  // Label-encoded gender (e.g., 0 for male, 1 for female)
    double height;  // Height in centimeters
    double weight;  // Weight in kilograms
    double isObese; // 1 if obese, 0 if not obese (the target variable)
};


class LinearRegression {
public:
    // Constructor to initialize model parameters
    LinearRegression() : theta0(0.0), theta1(0.0), theta2(0.0) {}

    // Train the model using the closed-form solution
    void train() {
		std::string data =
        "1	174	96	4\n"
		"1	189	87	2\n"
		"0	185	110	4\n"
		"0	195	104	3\n"
		"1	149	61	3\n"
		"1	189	104	3\n"
		"1	147	92	5\n"
		"1	154	111	5\n"
		"1	174	90	3\n"
		"0	169	103	4\n"
		"1	195	81	2\n"
		"0	159	80	4\n"
		"0	192	101	3\n"
		"1	155	51	2\n"
		"1	191	79	2\n"
		"0	153	107	5\n"
		"0	157	110	5\n"
		"1	140	129	5\n"
		"1	144	145	5\n"
		"1	172	139	5\n"
		"1	157	110	5\n"
		"0	153	149	5\n"
		"0	169	97	4\n"
		"1	185	139	5\n"
		"0	172	67	2\n"
		"0	151	64	3\n"
		"1	190	95	3\n"
		"1	187	62	1\n"
		"0	163	159	5\n"
		"1	179	152	5\n"
		"1	153	121	5\n"
		"1	178	52	1\n"
		"0	195	65	1\n"
		"0	160	131	5\n"
		"0	157	153	5\n"
		"0	189	132	4\n"
		"0	197	114	3\n"
		"1	144	80	4\n"
		"0	171	152	5\n"
		"0	185	81	2\n"
		"0	175	120	4\n"
		"0	149	108	5\n"
		"1	157	56	2\n"
		"1	161	118	5\n"
		"0	182	126	4\n"
		"1	185	76	2\n"
		"0	188	122	4\n"
		"1	181	111	4\n"
		"1	161	72	3\n"
		"1	140	152	5\n"
		"0	168	135	5\n"
		"0	176	54	1\n"
		"1	163	110	5\n"
		"1	172	105	4\n"
		"1	196	116	4\n"
		"0	187	89	3\n"
		"1	172	92	4\n"
		"1	178	127	5\n"
		"0	164	70	3\n"
		"1	143	88	5\n"
		"0	191	54	0\n"
		"0	141	143	5\n"
		"1	193	54	0\n"
		"1	190	83	2\n"
		"1	175	135	5\n"
		"0	179	158	5\n"
		"0	172	96	4\n"
		"0	168	59	2\n"
		"0	164	82	4\n"
		"0	194	136	4\n"
		"0	153	51	2\n"
		"1	178	117	4\n"
		"1	141	80	5\n"
		"1	180	75	2\n"
		"0	185	100	3\n"
		"0	197	154	4\n"
		"1	165	104	4\n"
		"0	168	90	4\n"
		"0	176	122	4\n"
		"1	181	51	0\n"
		"1	164	75	3\n"
		"0	166	140	5\n"
		"0	190	105	3\n"
		"1	186	118	4\n"
		"1	168	123	5\n"
		"1	198	50	0\n"
		"0	175	141	5\n"
		"1	145	117	5\n"
		"0	159	104	5\n"
		"0	185	140	5\n"
		"0	178	154	5\n"
		"0	183	96	3\n"
		"0	194	111	3\n"
		"1	177	61	2\n"
		"1	197	119	4\n"
		"0	170	156	5\n"
		"1	142	69	4\n"
		"1	160	139	5\n"
		"1	195	69	1\n"
		"0	190	50	0\n"
		"1	199	156	4\n"
		"1	154	105	5\n"
		"1	161	155	5\n"
		"0	198	145	4\n"
		"0	192	140	4\n"
		"1	195	126	4\n"
		"1	166	160	5\n"
		"1	159	154	5\n"
		"0	181	106	4\n"
		"1	149	66	3\n"
		"0	150	70	4\n"
		"0	146	157	5\n"
		"1	190	135	4\n"
		"0	192	90	2\n"
		"0	177	96	4\n"
		"1	148	60	3\n"
		"0	165	57	2\n"
		"0	146	104	5\n"
		"1	144	108	5\n"
		"0	176	156	5\n"
		"0	168	87	4\n"
		"1	187	122	4\n"
		"1	187	138	4\n"
		"0	184	160	5\n"
		"0	158	149	5\n"
		"1	158	96	4\n"
		"1	194	115	4\n"
		"0	145	79	4\n"
		"1	182	151	5\n"
		"1	154	54	2\n"
		"0	168	139	5\n"
		"0	187	70	2\n"
		"0	158	153	5\n"
		"0	167	110	4\n"
		"0	171	155	5\n"
		"0	183	150	5\n"
		"0	190	156	5\n"
		"1	194	108	3\n"
		"1	171	147	5\n"
		"1	159	124	5\n"
		"0	169	54	2\n"
		"0	167	85	4\n"
		"1	180	149	5\n"
		"1	163	123	5\n"
		"1	140	79	5\n"
		"1	197	125	4\n"
		"1	194	106	3\n"
		"0	140	146	5\n"
		"1	195	98	3\n"
		"0	168	115	3\n"
		"0	196	50	0\n"
		"1	140	52	3\n"
		"0	150	60	3\n"
		"0	168	140	5\n"
		"0	155	111	5\n"
		"0	179	103	4\n"
		"0	182	84	3\n"
		"1	168	160	5\n"
		"0	187	102	3\n"
		"1	181	105	4\n"
		"1	199	99	2\n"
		"0	184	76	2\n"
		"1	192	101	3\n"
		"0	182	143	5\n"
		"0	172	111	4\n"
		"1	181	78	2\n"
		"1	176	109	4\n"
		"0	156	106	5\n"
		"0	151	67	3\n"
		"0	188	80	2\n"
		"1	187	136	4\n"
		"1	174	138	5\n"
		"1	167	151	5\n"
		"0	196	131	4\n"
		"1	197	149	4\n"
		"0	185	119	4\n"
		"0	170	102	4\n"
		"0	181	94	3\n"
		"0	166	126	5\n"
		"1	188	100	3\n"
		"0	162	74	3\n"
		"1	177	117	4\n"
		"1	162	97	4\n"
		"1	180	73	2\n"
		"0	192	108	3\n"
		"1	165	80	3\n"
		"0	167	135	5\n"
		"0	182	84	3\n"
		"0	161	134	5\n"
		"1	158	95	4\n"
		"1	141	85	5\n"
		"1	154	100	5\n"
		"1	165	105	4\n"
		"0	142	137	5\n"
		"1	141	94	5\n"
		"1	145	108	5\n"
		"1	157	74	4\n"
		"0	177	117	4\n"
		"0	166	144	5\n"
		"1	193	151	5\n"
		"1	184	57	1\n"
		"1	179	93	3\n"
		"0	156	89	4\n"
		"1	182	104	4\n"
		"1	145	160	5\n"
		"0	150	87	4\n"
		"1	145	99	5\n"
		"0	196	122	4\n"
		"1	191	96	3\n"
		"0	148	67	4\n"
		"0	150	84	4\n"
		"1	148	155	5\n"
		"0	153	146	5\n"
		"0	196	159	5\n"
		"0	185	52	0\n"
		"0	171	131	5\n"
		"0	143	118	5\n"
		"0	142	86	5\n"
		"0	141	126	5\n"
		"1	159	109	5\n"
		"0	173	82	2\n"
		"1	183	138	5\n"
		"0	152	90	4\n"
		"1	178	140	5\n"
		"1	188	54	0\n"
		"0	155	144	5\n"
		"1	166	70	3\n"
		"1	188	123	4\n"
		"0	171	120	5\n"
		"1	179	130	5\n"
		"0	186	137	4\n"
		"0	153	78	2\n"
		"0	184	86	3\n"
		"0	177	81	3\n"
		"1	145	78	4\n"
		"1	170	81	3\n"
		"1	181	141	5\n"
		"1	165	155	5\n"
		"0	174	65	2\n"
		"0	146	110	5\n"
		"1	178	85	3\n"
		"1	166	61	2\n"
		"1	191	62	1\n"
		"0	177	155	5\n"
		"0	183	50	0\n"
		"1	151	114	5\n"
		"1	182	98	3\n"
		"0	142	159	5\n"
		"0	188	90	3\n"
		"1	161	89	4\n"
		"1	153	70	3\n"
		"1	140	143	5\n"
		"1	169	141	5\n"
		"0	162	159	5\n"
		"1	183	147	5\n"
		"0	162	58	2\n"
		"0	172	109	4\n"
		"0	150	119	5\n"
		"0	169	145	5\n"
		"0	184	132	4\n"
		"1	159	104	5\n"
		"1	163	131	5\n"
		"1	156	137	5\n"
		"0	157	52	2\n"
		"1	147	84	4\n"
		"1	141	86	5\n"
		"1	173	139	5\n"
		"1	154	145	5\n"
		"1	168	148	5\n"
		"1	168	50	1\n"
		"1	145	130	5\n"
		"1	152	103	5\n"
		"0	187	121	4\n"
		"0	163	57	0\n"
		"1	178	83	3\n"
		"0	187	94	3\n"
		"0	179	114	4\n"
		"1	190	80	2\n"
		"1	172	75	3\n"
		"1	188	57	1\n"
		"1	193	65	1\n"
		"0	147	126	5\n"
		"0	147	94	5\n"
		"1	166	107	4\n"
		"0	192	139	4\n"
		"1	181	139	4\n"
		"1	150	74	4\n"
		"1	178	160	5\n"
		"0	156	52	2\n"
		"1	149	100	5\n"
		"1	156	74	4\n"
		"1	183	105	3\n"
		"0	162	68	3\n"
		"0	165	83	4\n"
		"0	168	143	5\n"
		"1	160	156	5\n"
		"0	169	88	2\n"
		"0	140	76	4\n"
		"0	187	92	3\n"
		"1	151	82	4\n"
		"0	186	140	5\n"
		"1	182	108	4\n"
		"1	188	81	2\n"
		"1	179	110	4\n"
		"0	156	126	5\n"
		"1	188	114	4\n"
		"1	183	153	5\n"
		"1	144	88	5\n"
		"1	196	69	1\n"
		"1	171	141	5\n"
		"1	171	147	5\n"
		"0	180	156	5\n"
		"1	191	146	5\n"
		"0	179	67	2\n"
		"0	180	60	2\n"
		"0	154	132	5\n"
		"1	188	99	3\n"
		"1	142	135	5\n"
		"1	170	95	4\n"
		"1	152	141	5\n"
		"0	190	118	4\n"
		"0	181	111	4\n"
		"1	153	104	5\n"
		"1	187	140	5\n"
		"0	144	66	4\n"
		"0	148	54	2\n"
		"0	199	92	2\n"
		"0	167	85	4\n"
		"0	164	71	3\n"
		"0	185	102	3\n"
		"0	164	160	5\n"
		"1	142	71	4\n"
		"1	165	68	2\n"
		"0	172	62	2\n"
		"0	157	56	2\n"
		"1	155	57	2\n"
		"0	167	153	5\n"
		"0	164	126	5\n"
		"0	189	125	4\n"
		"0	161	145	5\n"
		"0	155	71	3\n"
		"0	171	118	4\n"
		"0	154	92	4\n"
		"1	179	83	3\n"
		"1	170	115	4\n"
		"0	184	106	4\n"
		"0	191	68	2\n"
		"1	162	58	2\n"
		"1	178	138	5\n"
		"0	157	60	2\n"
		"1	184	83	2\n"
		"1	197	88	2\n"
		"0	160	51	2\n"
		"1	184	153	5\n"
		"1	190	50	0\n"
		"1	174	90	3\n"
		"0	189	124	4\n"
		"0	186	143	5\n"
		"0	180	58	1\n"
		"0	186	148	4\n"
		"0	193	61	1\n"
		"1	161	103	4\n"
		"0	151	158	5\n"
		"0	195	147	4\n"
		"0	184	152	5\n"
		"1	141	80	5\n"
		"0	185	94	3\n"
		"0	186	127	4\n"
		"1	142	131	5\n"
		"0	147	67	4\n"
		"1	151	62	3\n"
		"0	160	124	5\n"
		"1	185	60	1\n"
		"0	163	63	2\n"
		"1	174	95	4\n"
		"0	150	144	5\n"
		"1	142	91	5\n"
		"1	178	142	5\n"
		"0	154	96	5\n"
		"1	176	87	3\n"
		"1	159	120	5\n"
		"1	191	62	1\n"
		"1	177	117	4\n"
		"1	151	154	5\n"
		"0	182	149	5\n"
		"0	197	72	2\n"
		"1	146	138	5\n"
		"0	160	83	4\n"
		"0	157	66	3\n"
		"0	150	50	2\n"
		"0	167	58	2\n"
		"0	180	70	2\n"
		"0	183	76	2\n"
		"0	183	87	3\n"
		"0	152	154	5\n"
		"0	164	71	3\n"
		"1	187	96	3\n"
		"1	169	136	5\n"
		"0	149	61	3\n"
		"1	163	137	5\n"
		"0	195	104	3\n"
		"1	174	107	4\n"
		"1	182	70	2\n"
		"1	169	110	4\n"
		"1	193	130	4\n"
		"1	148	141	5\n"
		"1	186	68	2\n"
		"1	165	143	5\n"
		"0	146	123	5\n"
		"0	166	133	5\n"
		"1	179	56	1\n"
		"0	177	101	4\n"
		"1	181	154	5\n"
		"0	161	154	5\n"
		"0	157	103	5\n"
		"0	169	98	4\n"
		"0	152	114	5\n"
		"0	162	64	2\n"
		"1	162	130	5\n"
		"0	177	61	2\n"
		"0	195	61	1\n"
		"1	140	146	5\n"
		"0	186	146	5\n"
		"0	178	107	4\n"
		"1	174	54	1\n"
		"0	180	59	1\n"
		"1	188	141	4\n"
		"0	187	130	4\n"
		"0	153	77	4\n"
		"0	165	95	4\n"
		"0	178	79	2\n"
		"0	163	154	5\n"
		"0	150	97	5\n"
		"1	179	127	4\n"
		"1	165	62	2\n"
		"1	168	158	5\n"
		"0	153	133	5\n"
		"1	184	157	5\n"
		"1	188	65	1\n"
		"0	166	153	5\n"
		"0	172	116	4\n"
		"1	182	73	2\n"
		"1	143	149	5\n"
		"1	152	146	5\n"
		"0	186	128	4\n"
		"1	159	140	5\n"
		"1	146	70	4\n"
		"0	176	121	4\n"
		"0	146	101	5\n"
		"1	159	145	5\n"
		"1	162	157	5\n"
		"0	172	90	4\n"
		"0	169	121	5\n"
		"1	182	50	0\n"
		"0	183	79	2\n"
		"1	176	77	2\n"
		"0	188	128	4\n"
		"0	175	83	2\n"
		"1	154	81	4\n"
		"0	184	147	5\n"
		"1	179	123	4\n"
		"1	152	132	5\n"
		"1	179	56	1\n"
		"0	145	141	5\n"
		"0	181	80	2\n"
		"1	158	127	5\n"
		"0	188	99	3\n"
		"1	145	142	5\n"
		"1	161	115	5\n"
		"1	198	109	3\n"
		"1	147	142	5\n"
		"1	154	112	5\n"
		"0	178	65	2\n"
		"1	195	153	5\n"
		"0	167	79	3\n"
		"1	183	131	4\n"
		"0	164	142	5\n"
		"1	167	64	2\n"
		"0	151	55	2\n"
		"0	147	107	5\n"
		"0	155	115	5\n"
		"0	172	108	4\n"
		"0	142	86	5\n"
		"1	146	85	4\n"
		"0	188	115	4\n"
		"1	173	111	4\n"
		"0	160	109	5\n"
		"1	187	80	2\n"
		"1	198	136	4\n"
		"0	179	150	5\n"
		"0	164	59	2\n"
		"0	146	147	5\n"
		"0	198	50	0\n"
		"0	170	53	1\n"
		"1	152	98	5\n"
		"0	150	153	5\n"
		"0	184	121	4\n"
		"0	141	136	5\n"
		"1	150	95	5\n"
		"1	173	131	5\n"
		;

    std::istringstream iss(data);
    std::string line;
    std::vector<DataPoint> dataPoints;

    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        DataPoint point;
        lineStream >> point.gender >> point.height >> point.weight >> point.isObese;
        dataPoints.push_back(point);
    }

        double sumX1 = 0.0, sumX2 = 0.0, sumY = 0.0, sumX1Y = 0.0, sumX2Y = 0.0;

        for (const DataPoint& point : dataPoints) {
            sumX1 += point.gender;
            sumX2 += point.height;
            sumY += point.isObese;
            sumX1Y += point.gender * point.isObese;
            sumX2Y += point.height * point.isObese;
        }

        theta0 = (sumY * sumX1 * sumX2 - sumX1Y * sumX2) /
                 (dataPoints.size() * sumX1 * sumX1 - sumX1 * sumX1);
        theta1 = (dataPoints.size() * sumX1Y - sumX1 * sumY) /
                 (dataPoints.size() * sumX1 * sumX1 - sumX1 * sumX1);
        theta2 = (dataPoints.size() * sumX2Y - sumX2 * sumY) /
                 (dataPoints.size() * sumX2 * sumX2 - sumX2 * sumX2);
    }

    // Make predictions
    double predict(double gender, double height, double weight) {
        return theta0 + theta1 * gender + theta2 * height;
    }

private:
    double theta0; // Bias term
    double theta1; // Coefficient for gender
    double theta2; // Coefficient for height
};


//// All the operations happen in the last class called "Login"
// Recommendations class has two primary responsibilities
	//// First, it opens and reads from a file which has food items offered by the NYUAD dining hall and
			// the calories associated with each food item
			// The name of the file which stores this data is "Recommendations.txt"
	//// Second, this class has a function that performs an algorithm to pick and choose from the list of 
			// seven food items based on the number of calories required by the user that day
class Recommendations {
private:

	// Vector that'll store names of all food items read from the file
	vector<string> namesOfFood;
	// Vector that'll store the corresponding calories associated with each of the food items
	vector<string> calories;
public:

	// Default-constructor
	// When an object of this class is created, it prints the following
	Recommendations(){
		cout << "			Your recommendations are: " << endl;
		cout << endl;
		cout << endl;
	}

	// This function opens the file of food recommendations and
	// copies the information from the file into the vectors
	void transfer() {

		// Opening the file
		ifstream recsFile("maincourse.txt", ios::in);
		// If file fails to open, print an error message
		if (recsFile.fail()){
			cerr << "Error opening file" << endl;
			system("pause");
			exit(0);
		}
		
		// Till end of file is not reached
		while (!recsFile.eof()) {
			// Create two temporary strings
			string food;
			string cals;
			// Store food name into string food and calories into string cals
			recsFile >> food >> cals >> ws;
			// Store name of food as an element in the following vector
			namesOfFood.push_back(food);
			// Store number of calories as an element in the following vector
			calories.push_back(cals);
		}
	}
	 void chooseFoodGreedy(double c) {
        // Sort the food items based on calories in ascending order
        vector<pair<int, double>> sortedItems;
        for (int i = 0; i < calories.size(); ++i) {
            sortedItems.push_back({i, stod(calories[i])});
        }
        sort(sortedItems.begin(), sortedItems.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        // Initialize variables to keep track of selected items and their total calories
        vector<int> selectedItems;
        double totalCalories = 0.0;

        // Greedily select items starting from the lowest-calorie ones
        for (const auto& item : sortedItems) {
            if (totalCalories + item.second <= c) {
                selectedItems.push_back(item.first);
                totalCalories += item.second;
            }
        }

        // Print the selected food items
        cout << endl;
        cout << "            You must eat: " << endl;
        cout << endl;
        cout << endl;

        for (const auto& selectedItem : selectedItems) {
            cout << "            " << namesOfFood[selectedItem] << endl;
            cout << "                 " << "Calories: " << calories[selectedItem] << endl;
            cout << endl;
        }

        cout << endl;
        cout << endl;
    }
};

// This class has the function of receiving health profile data from the user and
	// calculating and displaying their BMI AND BMR (report includes definitions of the aforementioned terms)
	// If the user already exists, he doesn't have to fill the health form again
		// Existing user's health profile has already been stored in the "Directory.txt" file and is 
		// displayed on the screen

class HealthForm {
private:
	// Asks the user to enter the following information
	string name;
	double age;
	string gender;
	double height;
	double weight;
	// Calculates the following based on the above values 
	double BMI;
	double BMR;

public:

	// Default-constructor
		// When an object of this class is created, it asks the username to enter the following information
	HealthForm() {
		std::cout << "		#############################################################################################" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "						     Health Profile" << endl;
		std::cout << endl;
		std::cout << "			Name: ";
		cin >> name;

		std::cout << "			Age: ";
		cin >> age;

		std::cout << "			Gender - " << endl;
		std::cout << "			Type either Male or Female: ";
		cin >> gender;

		// If gender entered is neither, keep asking to re-enter
		while (gender != "Female" && gender != "Male"){
			std::cout << "			Invalid gender: ";
			cin >> gender;
		}

		std::cout << "			Height- " << endl;
		std::cout << "			Enter height in centimeters: ";
		cin >> height;

		std::cout << "			Weight- " << endl;
		std::cout << "			Enter weight in kilograms: ";
		cin >> weight;
	}

	// Function that calculates the Body Mass Index
	void calculateBMI() {
		BMI = (weight)*10000 / (height*height);
	}

	// Function that prints the Body Mass Index
	void printBMI() {
		std::cout << "			Your BMI is: " << BMI << " kg/m^2" << endl;
	}

	// Function that calculates the Basal Metabolic Rate
	void calculateBMR() {
		// Use the following formula if gender is female
		if (gender == "Female") {
			BMR = (10 * weight) + (6.25*height) - (5 * age) - 161;
		}
		// Else use this formula if gender is male
		else if (gender == "Male") {
			BMR = (10 * weight) + (6.25*height) - (5 * age) + 5;
		}
	}

	// Function that prints the Basal Metabolic Rate
	void printBMR() {
		std::cout << "			Your BMR is: " << BMR << " kcal/m^2/h"  << endl;
	}

	// Accessor of name
	string getName() {
		return(name);
	}

	// Accessor of age
	string getAge() {
		return(to_string(age));
	}

	// Accessor of gender
	string getGender() {
		return(gender);
	}

	// Accessor of height
	string getHeight() {
		return(to_string(height));
	}

	// Accessor of weight
	string getWeight(){
		return(to_string(weight));
	}

	// Accessor of BMI
	string getBMI() {
		return(to_string(BMI));
	}

	// Accessor of BMR string
	string getBMR() {
		return(to_string(BMR));
	}

	// Accessor of BMI double
	double getBMRdouble() {
		return(BMR);
	}


};
// An object of this class is created regardless of whether the user is new or not
	// This function's primary role is to get user input on some data and calculate
	// the number of calories required by them on that specific day
class CaloriesRequired {
private:
	// Activity Factor is a factor representative of the amount of activity a person does
	double activityFactor;
	// TEE is the total energy expenditure of the person which is calculated in the functions below
	double TEE;
	// Calories required by the user that day is calculated on the basis of the total energy expenditure that day
	double caloriesNeeded;
public:
	// Default constructor
		// When an object of this class is created, it asks the user to input their activity factor that day
	CaloriesRequired() {
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Activity Factor is a factor representative of the amount of activity a person does" << endl;
		std::cout << endl;
		std::cout << "			Please enter one of the numbers below to represent your activity factor- " << endl;
		std::cout << endl;
		// Instructions for which values one can enter
		std::cout << "			Sedentary active lifestyle:    1.53 " << endl;
		std::cout << "			Moderately active lifestyle:   1.76" << endl;
		std::cout << "			Vigorously active lifestyle:   2.25" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Enter your activity factor: ";
		cin >> activityFactor;
		std::cout << endl;
		std::cout << endl;

		// If acitivty factor is invalid then ask the user to re-enter
		while (activityFactor != 1.53 && activityFactor != 1.76 && activityFactor != 2.25) {
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;
			std::cout << "					    ****Invalid activity factor****" << endl;
			std::cout << endl;
			std::cout << "			Enter activity factor again: ";
			cin >> activityFactor;
		}
	}

	// This function receives the BMR of the user
	// and multiplies it by the activity factor to calculate the total energy expenditure
	void calculateTEE(double b) {
		TEE = activityFactor * b;
	}

	// Print the total energy expenditure
	void printTEE() {
		std::cout << endl;
		cout << "			Your total energy expenditure is: " << TEE << " kcal/m^2/h" << endl;
	}

	// Calculate the number of calories required by the user
	void calculateCals() {
		caloriesNeeded = TEE + (0.1*TEE);
	}

	// This function prints the number of calories required by the user
	void printCals() {
		std::cout << endl;
		cout << "			Number of calories needed per day is: " << caloriesNeeded << " kcal/m^2/h" << endl;
		std::cout << endl;
		std::cout << endl;
	}

	// Accessor for calories required by the user
	double getCals() {
		return(caloriesNeeded);
	}
};


// This class is where all the operations happen and all objects are made to interact with each other
class Login {
private:
	// Asks user, whether new or existing, to enter a username and a password
	string username;
	string password;

	// Vectors that store each of the corresponding details of existing users from the Directory file into them
	vector<string> dataUsernames;
	vector<string> dataPasswords;
	vector<string> dataName;
	vector<string> dataAge;
	vector<string> dataGender;
	vector<string> dataHeight;
	vector<string> dataWeight;
	vector<string> dataBMI;
	vector<string> dataBMR;

	// This variable temporarily stores words from a file and pushes back into a vector
	string temp1;

	// Index of users data in file
	int index;

public:

	// When object of Login is created, ask user for username and password
	Login() {
		std::cout << endl;
		std::cout << endl;
		std::cout << "		#############################################################################################" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "						    Digital Dietician" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << "			Username:	";
		cin >> username;
		std::cout << endl;
		std::cout << "			Password:	";
		cin >> password;
		std::cout << endl;
		std::cout << endl;
	}

	// This function opens the file "Directory" and stores information in vectors
	void openFile(string f) {

		// Opens file
		ifstream infile(f);
		// Print error message if file fails to open
		if (infile.fail()){
			cerr << "Error reading from file" << endl;
			exit(0);
		}

		// Till end of file is reached
		while (!infile.eof()) {

			// Get a line and store it in temp1 variable
			getline(infile, temp1);

			// Initializing two variables start as 0 and end as 1
			int start = 0, end = 1;
			
			// Initializing number of white spaces as 0
			int noOfWhiteSpaces = 0;

			// For as long as the size of the line
			for (int i = 0; i < temp1.size(); i++) {

				// Iterate through every character
					// If a character is a whitespace
				if (temp1[i] == ' '){

					// Store the index of that whitespace into end
					end = i;

					// If it hits the first whitespace then store the previous characters into vector of usernames
					if (noOfWhiteSpaces == 0) {
						dataUsernames.push_back(temp1.substr(start, end - start));
						noOfWhiteSpaces++;
						start = i;
					}

					// If it hits the second whitespace then store the previous characters after the
					// first whitespace into vector of passwords
					else if (noOfWhiteSpaces == 1) {
						dataPasswords.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the third whitespace then store the previous characters after the
					// second whitespace into vector of names
					else if (noOfWhiteSpaces == 2) {
						dataName.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the fourth whitespace then store the previous characters after the
					// third whitespace into vector of ages
					else if (noOfWhiteSpaces == 3) {
						dataAge.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// If it hits the fifth whitespace then store the previous characters after the
					// fourth whitespace into vector of usernames
					else if (noOfWhiteSpaces == 4) {
						dataGender.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					// Similarly for the rest, we do the same
					else if (noOfWhiteSpaces == 5) {
						dataHeight.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 6) {
						dataWeight.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 7) {
						dataBMI.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}
					else if (noOfWhiteSpaces == 8) {
						dataBMR.push_back(temp1.substr(start + 1, end - start - 1));
						noOfWhiteSpaces++;
						start = i;
					}

				}

				// If character hit is end of line, reset number of whitespaces to 0 and get the next line and
				// store it in temporary variable temp
				else if (temp1[i] == '\n'){
					noOfWhiteSpaces = 0;
					start = i;
					getline(infile, temp1);
				}
			}
		}
		// Close file
		infile.close();
	}

	// Function that returns the index of the username that already exists in the file
	// Receives the username
	int getInde(string userName) {
		// Till we reach the end of the vector
		for (int k = 0; k < dataUsernames.size(); k++){
			// Convert username received into a cstring
			const char* w1 = userName.c_str();
			// Convert each of the existing usernames in the vector into a cstring
			const char* w2 = dataUsernames[k].c_str();
			// Compare the above two cstrings
			int c = strcmp(w1, w2);
			// If they are the same
			if (c == 0){
				// Return the index
				return(k);
			}
		}
	}

	// This function performs the most significant operations
	// It checks if the user already exists or not
		//// If the user already exists, it creates an object of CaloriesRequired followed by an object of
			// Recommendations
		//// If the user doesn't already exist, it creates an object of HealthForm, followed by CaloriesRequired
			// followed by Recommendations
	void check(string f) {

		// Initialize variable check to 0
		int check = 0;
		// Till we reach the end of the vector
		for (int i = 0; i < dataUsernames.size(); i++) {
			// Convert each of the existing usernames in the vector into a cstring
			const char* c1 = dataUsernames[i].c_str();
			// Convert username entered by the user into a cstring
			const char* c2 = username.c_str();
			// Check is set to 0 if both the cstrings being compared are the same
			check = strcmp(c1, c2);
			// If they are the same
			if (check == 0){
				// Store the index of that existing username into variable index
				index = i;
				// Break from the loop
				break;
			}
		}

		// If the two cstrings are the same
		if (check == 0) {
			// While corresponding password in the vector of passwords is not the same as the password entered by the user
			while (dataPasswords[index] != password) {
				// Display incorrect password and enter again
				std::cout << "					   **** Incorrect Password ****" << endl;
				std::cout << endl;
				std::cout << endl;
				std::cout << "			Username:               " << username;
				cout << endl;
				std::cout << endl;
				std::cout << "			Enter password again:	";
				cin >> password;
			}


			// When the password entered is correct, display the already existing health profile
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;
			cout << "					    Your health profile already exists" << endl;
			std::cout << endl;
			std::cout << endl;
			// The following information already exists
			cout << "			Name:		" << dataName[index] << endl;
			cout << "			Age:		" << dataAge[index] << " years" << endl;
			cout << "			Gender:		" << dataGender[index] << endl;
			cout << "			Height:		" << dataHeight[index] << " cms" << endl;
			cout << "			Weight:		" << dataWeight[index] << " kgs" << endl;
			cout << "			BMI:		" << dataBMI[index] << " kgs/m^2" << endl;
			cout << "			BMR:		" << dataBMR[index] << " kcal/m^2/h" << endl;
			std::cout << endl;
			std::cout << endl;
			

			// The following algorithm asks the user to hit N to move to the
				// next section of the program
				// If the user hits any other key instead of N, it identifies it as incorrect and
				// keeps asking to hit N until the user does
			char next;
			do{
				cout<<"		Hit 'N' for NEXT  ";
				cin>>next;
				if (next=='N'| next=='n')
				break;
			}while(next!='N'|next!='n');
			cout << endl;
			cout << endl;
			std::cout << "		#############################################################################################" << endl;
			cout << endl;
			cout << endl;

			// An object of this class is now created
			CaloriesRequired cExisting;
			LinearRegression lr;
			lr.train();
			int gender;
			if (dataGender[index] == "Male"){
				gender = 1;
			}
			else{
				gender = 0;
			}
			// cout<<"You are "<<lr.predict(gender, stod(dataHeight[index]), stod(dataWeight[index]))<<endl;
			// Calculates the total energy expenditure of the person on receiving the BMR
			cExisting.calculateTEE(stod(dataBMR[index]));
			// Prints the total energy expenditure
			cExisting.printTEE();
			// Calculates the calories required by the person on that day
			cExisting.calculateCals();
			// Prints the calories required by the person on that day
			cExisting.printCals();

			// Following is the second time we ask the user to hit N to continue
			do{
				cout<<"		Hit 'N' for NEXT  ";
				cin>>next;
				if (next=='N'| next=='n')
				break;
			}while(next!='N'|next!='n');

			cout << endl;
			cout << endl;
			std::cout << "		#############################################################################################" << endl;
			cout << endl;
			cout << endl;

			// An object of the following class is created now
			Recommendations rExisting;
			// Opens file and copies all information into vectors
			rExisting.transfer();	

			cout << endl;
			

			// Choose food for the user based on number of calories required
			rExisting.chooseFoodGreedy(cExisting.getCals());

		}

		// If the user is new and not already existing
		else if (check != 0) {
			ofstream outfile;
			// Open the file and add information only at the end, don't erase and rewrite the file
			outfile.open(f, ios::app);
			
			// If the file fails to open, print an error message
			if (outfile.fail()){
				cerr << "Error reading into file" << endl;
				exit(0);
			}
			
			// An object of this class is created to get all of the users data
			HealthForm hNew;
			// Calculates the BMI of the new user
			hNew.calculateBMI();
			// Prints the BMI of the new user
			hNew.printBMI();
			// Calculate the BMR of the new user
			hNew.calculateBMR();
			// Print the BMR of the new user
			hNew.printBMR();

			std::cout << endl;
			std::cout << endl;

			// This is the fourth time we ask the user to hit N to move on
			char next;
			do{
				cout<<"		Hit 'N' for NEXT  ";
				cin>>next;
				if (next=='N'| next=='n')
				break;
			}while(next!='N'|next!='n');

			std::cout << endl;
			std::cout << endl;
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;

			// Store the new username into the vector of usernames
			dataUsernames.push_back(username);
			// Return the index of the username we just stored in the vector
			index = getInde(username);

			// Store all the corresponding information into the vectors
			dataPasswords.push_back(password);
			dataName.push_back(hNew.getName());
			dataAge.push_back(hNew.getAge());
			dataGender.push_back(hNew.getGender());
			dataHeight.push_back(hNew.getHeight());
			dataWeight.push_back(hNew.getWeight());
			dataBMI.push_back(hNew.getBMI());
			dataBMR.push_back(hNew.getBMR());

			cout << endl;

			// Store all the information at the end of the file in one single row seperated by a whitespace
			outfile << "\n" << dataUsernames[index] << ' ' << dataPasswords[index] << ' ' << hNew.getName() << ' ' << hNew.getAge() << ' ' << hNew.getGender() << ' ' << hNew.getHeight() << ' ' << hNew.getWeight() << ' ' << hNew.getBMI() << ' ' << hNew.getBMR() << ' ';
			// Close the file
			outfile.close();

			// Create an object of calories required
			CaloriesRequired cNew;
			// Calculate the total energy expenditure based on the BMR of the user
			cNew.calculateTEE(stod(hNew.getBMR()));
			// Print the total energy expenditure of the user
			cNew.printTEE();
			// Calculate the calories required by the user 
			cNew.calculateCals();
			// Print the calories required by the user
			cNew.printCals();
			
			std::cout << endl;
			std::cout << endl;

			do{
				cout<<"		Hit 'N' for NEXT  ";
				cin>>next;
				if (next=='N'| next=='n')
				break;
			}while(next!='N'|next!='n');

			std::cout << endl;
			std::cout << endl;
			std::cout << "		#############################################################################################" << endl;
			std::cout << endl;
			std::cout << endl;

			// Crreate an object of recommendations class
			Recommendations rNew;
			// Open file and copy information into vectors
			rNew.transfer();

			std::cout << endl;
			std::cout << endl;
			std::cout << endl;
			std::cout << endl;
			
			// Based on the number of calories required by the user, choose food
			rNew.chooseFoodGreedy(cNew.getCals());
		}

	}
};

int main(){	// The file where all existing users data is stored
	string file = "Directory.txt";
	// Create an object of Login where all the main operations take place
	Login L;
	// This function opens the file Directory
	L.openFile(file);
	// This function checks if the user already exists in the file
	L.check(file);
	system("pause");
	return(0);
}
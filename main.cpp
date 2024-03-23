#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;


double map(double x)
{
    double a = 1.0;
    double b = 5.0;
    double A = -1.0;
    double B = 2.0;
    double y = (B-A)/(b-a) *(x-a) +A;
    return y;
}
int main()
{
    string fileName = "data.csv";
    ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    string outputFile = "result.csv";
    ofstream ofstr(outputFile);

    if(ofstr.fail())
    {
        cerr << "outFile does not exist" << endl;
        return 1;
    }
    ofstr << scientific;
    double val = 0;
    unsigned int countVal = 0;
    double sum = 0.0;


    while(ifstr >> val)
    {
        countVal+=1;
        sum+=map(val);
        double average = sum/countVal;
        ofstr << countVal << " " << average<< '\n';
    }


    ifstr.close();
    ofstr.close();

    return 0;


}



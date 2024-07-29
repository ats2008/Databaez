/*

 to be a static file that can generate csv files for benchmarking purposes.

*/

#include <cstdlib> 
#include <iostream> 
#include <cmdparser.h>
#include <fstream>

#define R_SEED  42
#define N_COLS  12

using namespace std;

static const char alphabets[] = "abcdefghijklmnopqrstuvwxyz";

void configure_parser(cli::Parser& parser) {
	parser.set_optional<std::string>("o", "output", "data.csv", "output filename");
	parser.set_optional<long unsigned int>("n", "nLines", 64, "Number of lines in the csv");
}


int main(int argc, char** argv) 
{
	cli::Parser parser(argc, argv);    
    configure_parser(parser);
    parser.run_and_exit_if_error();
    
    srand(R_SEED);

    auto nLines = parser.get<long unsigned int>("n");
    auto output_filename = parser.get<std::string>("o");
    
    ofstream output_csv(output_filename);
    std::string name;
    int age;
    float taxBase;
    char gender;
    output_csv<<"#name,age,gender,taxPercentage";
    for(uint16_t j=0 ; j< N_COLS-5;j++)
    {
        output_csv<<","<<"FEATURE_"<<j+5;
    }
    output_csv<<"\n";

    for(long unsigned int i; i < nLines ; i++)
    {
        auto nameL=rand()%5;
        name="";
        for(uint8_t j=0;j<5+nameL;j++)
        {
            name+=alphabets[rand()%26];
        }
        age = 18+rand()%60;
        taxBase = 8.0+(rand()%120)/4.0;
        gender = rand()%2 ? 'M' : 'F';
        output_csv<<i<<","<<name<<","<<age<<","<<gender<<","<<taxBase;
        for(uint16_t j=0 ; j< N_COLS-5;j++)
        {
            output_csv<<","<<rand()%4096;
        }
        output_csv<<"\n";
    }
    output_csv.close();
}

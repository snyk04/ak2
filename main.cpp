#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

int main (int argc, char *argv[]) 
{
    const char* short_options = "vhc:s:";

    const struct option long_options[] = 
    {
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
        {"count", required_argument, NULL, 'c'},
        {"say", required_argument, NULL, 's'},
        {NULL,0,NULL,0}
    };

    int result;
    int option_index;

    std::vector<int> parsed_args;

    while ((result=getopt_long(argc,argv,short_options,long_options,&option_index)) != -1) 
    {
        if (std::count(parsed_args.begin(), parsed_args.end(), result)) 
        {
            continue;
        } 
        else 
        {
            parsed_args.push_back(result);
        }

        switch (result) 
        {
            case 'v':
                std::cout << "version 1.0" << std::endl;
                break;
            case 'h':
                std::cout << "OPTIONS" << std::endl;
                std::cout << "    -c, --count <n>" << std::endl;
                std::cout << "        Counts from 1 to n." << std::endl;
                std::cout << "    -s, --say <message>" << std::endl;
                std::cout << "        Displays message." << std::endl;
                break;
            case 'c':
            {
                int countGoal;
                try
                {
                    countGoal = std::stoi(optarg);
                }
                catch (...)
                {
                    std::cout << "./main: option requires valid argument (int) -- 'a'" << std::endl;
                    exit(EXIT_FAILURE);
                    break;
                }
				
                for (int i = 1; i <= countGoal; i++)
                {
                    std::cout << i << std::endl;
                }
                break;    
            }
            case 's':
                std::cout << optarg << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}

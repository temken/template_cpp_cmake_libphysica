#include <iostream>
#include <chrono>
#include <cmath>
#include <cstring> // for strlen

#include "version.hpp"
#include "module.hpp"

// Headers from libphysica
#include "Natural_Units.hpp"

int main()
{
	//Initial terminal output
	auto time_start = std::chrono::system_clock::now();
	auto time_start_t = std::chrono::system_clock::to_time_t(time_start);
	auto *ctime_start = ctime(&time_start_t);
	if (ctime_start[std::strlen(ctime_start)-1] == '\n') ctime_start[std::strlen(ctime_start)-1] = '\0';
	std::cout 	<<"[Started on " <<ctime_start<<"]" <<std::endl;
	std::cout <<PROJECT_NAME <<"-"<<PROJECT_VERSION <<"\tgit:" <<GIT_BRANCH <<"/" <<GIT_COMMIT_HASH <<std::endl <<std::endl;
	////////////////////////////////////////////////////////////////////////

	std::cout<<fib(10)<<std::endl;
	std::cout <<In_Units(1.0, meter/sec)<<std::endl;

	////////////////////////////////////////////////////////////////////////
	//Final terminal output
	auto time_end = std::chrono::system_clock::now();
	double durationTotal =1e-6*std::chrono::duration_cast<std::chrono::microseconds>( time_end - time_start ).count();
	std::cout 	<<"\n[Finished in "<< std::round(1000.*durationTotal)/1000.<<"s";
	if(durationTotal > 60.0)
		std::cout <<" ("<<floor(durationTotal/3600.0)<<":"<<floor(fmod(durationTotal/60.0,60.0))<<":"<<floor(fmod(durationTotal,60.0))<<")]."<<std::endl;
	else 
		std::cout <<"]"<<std::endl;
	
	return 0;
}
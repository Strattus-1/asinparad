#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string ukloni_znak( std::string ulaz, char ukloni )
{
	std::string izlaz;
	
	char znak;
	int granica = ulaz.size();
	
	for( int i = 0 ; i < granica ; i++ )
	{
		znak = ulaz.at(i);
		if( znak != ukloni ) izlaz.push_back( znak );
	};
	
	return izlaz;
};


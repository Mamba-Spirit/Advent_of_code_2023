#include <iostream>
#include <fstream>
#include <string>


               

using namespace std;

int main(){
	
	string my_file = "../test";
	int compteur = 0;
	int merging_number = 0;
	
	ifstream fichier(my_file);
	
	if(fichier.is_open()){
		
		string line;
		
		while(getline(fichier, line)){
			
			//cout<< line << endl;
			if(!line.empty()){
				int first = -1; 
				int last = -1;
				
				for(char charactere : line){
					
					if(isdigit(charactere)){
						
						if(first == -1){
							
							first = charactere - '0';
						}
						
						last = charactere - '0';
					}
				}
				if(first == -1){
					first = 0;
				}
				merging_number = first * 10 + last;
				cout<< "line : "<< line << " Nombre combiné : "<< merging_number << endl;
			}
			compteur = compteur + merging_number;
		}
		fichier.close();
	}
	
	else{
		cerr << "can not open this file : "<< my_file<< endl;
	}
	cout<< "The sum is : "<<compteur<<endl;
	
	
	return 0;
}
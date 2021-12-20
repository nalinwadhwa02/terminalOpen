#include "../include/disp.hpp"
#include <iostream>
#include <vector>

disp::disp(){
	std::cout<<"\x1B[?1049h\x1B[2J\x1B[?25l\x1B[H";
}
disp::~disp(){
	std::cout<<"\x1B[2J\x1B[?25h\x1B[?1049l";
}
int disp::update_screen(int sel, std::vector<std::string> list){
	std::cout<<"\x1B[2J\x1B[H";
	for(int i=0;i<list.size();i++){
		if(sel==i){
			std::cout<<"\t"<<list[i]<<"\n";
		}
		else{
			std::cout<<list[i]<<"\n";
		}
	}
	return 0;
}

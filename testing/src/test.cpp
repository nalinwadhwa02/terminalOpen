#include "../include/fsysm.hpp"
#include "../include/disp.hpp"
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

const unsigned int millisecond = 1000;

void waitpause(){
	std::getchar();
}

int main(){
	fsysm newfs("/home/nw");
	disp newdisp;
	int loop = 1;
	while(loop == 1){
		char c;
		std::getchar(c);
		newdisp.update_screen(0,newfs.get_list());
	}
	return 0;
}


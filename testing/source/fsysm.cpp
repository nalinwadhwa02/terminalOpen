#include <../include/fsysm.hpp>
#include <string>
#include <vector>

namespace fs = std::filesystem;

bool check_if_hidden(fs::directory_entry dirc){
	if(dirc.path().stem().string()[0]=='.'){
		return true;
	}
	else{
		return false;
	}
}
fsysm::fsysm(std::string s){
	cwd = fs::directory_entry(fs::path(s));
	show_hidden = false;
	show_fullpath = false;
}
std::vector<std::string> fsysm::get_list(){
	vector<std::string> res;
	for(auto file: fs::directory_iterator(cwd)){
		if(!check_if_hidden(file) || show_hidden){
			if(show_fullpath){
				res.push_back(file.path().string());
			}
			else{
				res.push_back(file.path().stem().string());
			}
		}
	}
	return res;
}


void validate_selection(std::string){
}

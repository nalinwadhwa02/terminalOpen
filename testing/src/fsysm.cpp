#include "../include/fsysm.hpp"
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
	std::vector<std::string> res;
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


int fsysm::validate_selection(std::string s){
	fs::directory_entry sel(fs::path(cwd.path().string() + "/" + s));
	if(!sel.exists()){
		return -1;
	}
	if(!sel.is_directory()){
		return 0;
	}
	else{
		cwd = sel;
		return 1;
	}
}

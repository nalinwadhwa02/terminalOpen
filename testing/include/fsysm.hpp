#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class fsysm{
	//members
	fs::directory_entry cwd;
	bool show_hidden;
	bool show_fullpath;
	//functions
public:
	fsysm(std::string s);
	std::vector<std::string> get_list();
	int validate_selection(std::string);
	std::string show_preview(std::string);
	void toggle_hidden();
	void toggle_fullpath();
	std::string get_cwd();
	bool get_hidden();
	bool get_fullpath();
};

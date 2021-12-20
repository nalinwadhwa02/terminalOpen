#include <string>
#include <vector>

class disp{
	int sel;
	std::vector<std::string> list;
public:
	disp();
	~disp();
	int update_screen(int sel, std::vector<std::string> list);
	int update_screen(int sel);
	int update_screen(std::vector<std::string> list);
};

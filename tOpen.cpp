#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <bits/stdc++.h>
bool SHOW_HIDDEN;
int kbhit(void)
{
	  struct termios oldt, newt;
	    int ch;
		  int oldf;

		    tcgetattr(STDIN_FILENO, &oldt);
			  newt = oldt;
			    newt.c_lflag &= ~(ICANON | ECHO);
				  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
				    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
					  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

					    ch = getchar();

						  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
						    fcntl(STDIN_FILENO, F_SETFL, oldf);

							  if(ch != EOF)
								    {
										    ungetc(ch, stdin);
											    return 1;
												  }

												    return 0;
}
typedef std::vector<std::string> stringvec; 
 void read_directory(const std::string& name, stringvec& v)
 {
	     DIR* dirp = opendir(name.c_str());
		     struct dirent * dp;
			     while ((dp = readdir(dirp)) != NULL) {
							if(dp->d_name[0] != '.' || !SHOW_HIDDEN)
					         v.push_back(dp->d_name);
							     }
								     closedir(dirp);
 }
/*
struct path_leaf_string
{
	std::string operator()(const std::filesystem::directory_entry& entry) const
		{
		return entry.path().leaf().string();
		}
};
  
void read_directory(const std::string& name, stringvec& v)
{
	std::filesystem::path p(name);
	std::filesystem::directory_iterator start(p);
	std::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(v), path_leaf_string());
}
*/
bool comparer(std::string s1, std::string s2){
	std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	if(s1<s2) return true;
	else return false;
}
int main (){
	SHOW_HIDDEN = true;
	std::string dirv="/home/nalinwadhwa";
	int flag=0;
	int selection=0;
	std::string selected;
	std::system("clear");
	bool next=true;
	stringvec v;
	std::string copiedfile;
	bool copyon=false,moveon=false;
	while(true){
		if(next){
			v.clear();
			read_directory(dirv,v);
			std::sort(v.begin(),v.end(),comparer);
		}
		next=false;
		std::cout<<dirv<<std::endl<<std::endl;
		for(int i=0;i<v.size();i++){
			if(v[i][0] != '.' || !SHOW_HIDDEN)
				std::cout<<"\t";
				if(i != selection)
					std::cout<<v[i]<<std::endl;
				else{
					std::cout<<"\e[1m->"<<v[i]<<"\e[0m"<<std::endl;
					selected = v[i];
				}
		}
		while(!kbhit()){}
		char ch=getchar();
		if(ch=='j'){
			if(selection+1<v.size())
				selection++;
		}
		else if(ch=='k'){
			if(selection-1>-1)
				selection--;
		}
		else if(ch=='h'){
			selection=0;
			next=true;
			dirv+="/..";
		}
		else if(ch=='l'){
			dirv+=("/" + selected);
			next=true;
			selection=0;
		}
		else if(ch == 'o'){
			flag=1;
			break;
		}
		else if(ch == '.'){
			if(SHOW_HIDDEN)
				SHOW_HIDDEN=false;
			else
				SHOW_HIDDEN=true;
			selection=0;
			next=true;
		}
		else if(ch == 'e'){
			flag=2;
			dirv+=("/"+selected);
			break;
		}
		else if(ch == 'c'){
			copiedfile=dirv+"/"+selected;
			copyon = true;
		}
		else if(ch == 'x'){
			copiedfile=dirv+"/"+selected;
			moveon = true;
		}
		else if(ch == 'v'){
			std::string mvcp;
			if(moveon){mvcp = "mv '";}
			else if(copyon){mvcp = "cp '";}	
			else{continue;}
			std::system((mvcp+copiedfile+"' '"+dirv+"'").c_str());
			moveon = false;
			copyon = false;
			std::cout<<std::endl<<mvcp+copiedfile+"' '"+dirv+"'";
			getchar();
			next=true;
		}
		else if(ch == 'd'){
			std::string todel = dirv+"/"+selected;
			std::cout<<std::endl<<"rm -rf '"<<todel<<"' [y/n]? ";
			while(!kbhit()){}
			char op = getchar();
			if(op == 'y'){
				std::system(("rm -rf '"+todel+"'").c_str());
				next=true;
			}
			else{continue;}
		}
		else if(ch == 'q')
			break;
		else
			std::cout<<"\n\nERROR wrong character"<<std::endl;
		std::system("clear");
	}
	std::cout<<std::endl;
	if(flag==1){
		std::string out="cd '"+dirv+"';bash";
		std::system(out.c_str());
	}
	else if(flag==2){
		std::string out="vim "+dirv;
		std::system(out.c_str());
	}
	return 0;
}

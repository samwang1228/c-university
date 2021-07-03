#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
//題目:
// 給定一字串以/分割若string=".."移除上一個 
//                         ="." 不做任何是
//                         else 加入string
//                         每個string最後要以/分割
// Given a string path, which is an absolute path (starting with a slash '/') 
// to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, 
// a double period '..' refers to the directory up a level, and any multiple consecutive slashes 
// (i.e. '//') are treated as a single slash '/'. 
// For this problem, any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

// Return the simplified canonical path.
// ex: 
// Input: path = "/a/./b/../../c/"
// Output: "/c"
// Input: path = "/home//foo/"
// Output: "/home/foo"
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string ans, temp;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, temp, '/')) { //將ss分割if遇到 "/" 切掉 並存入temp
            if (temp.empty() || temp == ".") continue;//temp.empty()很重要因為可能為連續的//
            if (temp == ".." && !v.empty()) v.pop_back();
            else if (temp != "..") v.push_back(temp); 
        }
        //temp在while外後會被清空
        for (string s : v) ans += "/" + s;//注意是+=
        return v.empty() ? "/" : ans;
    }
};
//空間效率較好的方法
class Solution2 {
public:
    string simplifyPath(string path) {
        vector<string> P;
        string s;
        path.push_back('/');
        for (int i=0; i<path.size(); i++){
            if (path[i]=='/'){
                if (s.empty()) continue;

                if (s==".."){
                    if (!P.empty()){
                        P.pop_back();
                    }
                } else {
                    if (s!=".") P.push_back(s);
                }
                s = "";
            } else {
                s.push_back(path[i]);
            }
        }
        s = "/";
        for (auto& t : P){
            s += t + "/";
        }
        if (s.size()>1) s.pop_back();
        return s;
    }
};
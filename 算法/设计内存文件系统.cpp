class FileSystem {
public:
    FileSystem() {
        dirs["/"];
    }
    // dirs<string,set<string>>  path和path下对应的东西（包括子目录和文件）
    // files<string,string>      文件path和文件内容
    
    vector<string> ls(string path) {
        if (files.count(path)) {                //该路径在为文件
            int idx = path.find_last_of('/');
            return {path.substr(idx + 1)};
        }
        auto t = dirs[path];
        return vector<string>(t.begin(), t.end());
    }
    
    void mkdir(string path) {
        istringstream is(path);
        string t = "", dir = "";
        while (getline(is, t, '/')) {
            if (t.empty()) continue;
            if (dir.empty()) dir += "/";
            dirs[dir].insert(t);
            if (dir.size() > 1) dir += "/";
            dir += t;
        }
    }
    
    void addContentToFile(string filePath, string content) {         // 先从给定路径寻找最后次/标识，结果出意外后面会有处理，此处只对正常情况
        int idx = filePath.find_last_of('/');                        //下处理，如果得到的是正常路径，就直接在该文件名加入内容，该内容存在另一个
                                                                     //容器中
        string dir = filePath.substr(0, idx);
        string file = filePath.substr(idx + 1);
        if (dir.empty()) dir = "/";  //无路径时默认将文件存在根路径里
        if (!dirs.count(dir)) mkdir(dir);
        dirs[dir].insert(file);          //此处的set没有该file会插入，有时插入也不会报错，同时set中依旧只有一份
        files[filePath].append(content);
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
    
private:
    unordered_map<string, set<string>> dirs;           //此处用set的用意为 一个string，即一个路径下，可能有多个路径或者文件，在这种情况下会需要用
                                                        //容器，如果用string会被覆盖
    unordered_map<string, string> files;
};

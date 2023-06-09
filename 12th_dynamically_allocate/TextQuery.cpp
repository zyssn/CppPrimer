#include "TextQuery.h"

TextQuery::TextQuery(ifstream& infile) : file(new vector<string>) {
    string tmp;
    while (getline(infile, tmp)) {  //读入文件  的每一行
        file->push_back(tmp);    // 存入 vs
        int lineNo = (int)file->size() - 1; // 当前行号
        istringstream line(tmp); // 转化为 is
        string word;
        while (line >> word) {  // is ——》 每个单词
            shared_ptr<set<unsigned int>>& lines = wm[word];  // 注意这是个指针，要new开辟空间
            if (!lines) //  如果这个单词没有的话  为空  需要开辟空间
                lines.reset(new set<unsigned int>);  //分配一个新的set
            else
                lines->insert(lineNo); // 向set中插入行号
        }
    }
}

QueryResult TextQuery::query(const string& s) {   //查询单词
    static shared_ptr<set<unsigned int>> nodata(new set<unsigned int>);
    auto loc = wm.find(s);
    if (loc == wm.end()) { // 如果没有找到
        return QueryResult(s, nodata, file);
    }
    else { //  如果找到了
        return QueryResult(s, loc->second, file);
    }
}
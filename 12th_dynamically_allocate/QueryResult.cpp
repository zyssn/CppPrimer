#include "QueryResult.h"


ostream& myprint(ostream& out, const QueryResult& qr) { // 第一个是参数IO   第二个参数 查询的QueryResult对象
    out << qr.sought << " occurs " << qr.lines->size() << ' ' << "times"
        << endl;
    for (auto num : *(qr.lines)) { // 遍历输出  如果没有这个单词  解引用为空
        out << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;  // 打印行号和
    }
    return out;
}

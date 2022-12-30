//
// Created by 12865 on 2022/12/27.
//

#ifndef DESIGNPATTERNS_COMPOSITE_HPP
#define DESIGNPATTERNS_COMPOSITE_HPP


// 组合模式：树形结构
// TODO: 示例，文件树


// 基类
class FileSystemNode {};

// 根结点 或 分支结点
class Directory : public FileSystemNode {};

// 叶子结点
class File : public FileSystemNode {};

// **********************************************************************


void composite_test() {}


#endif //DESIGNPATTERNS_COMPOSITE_HPP

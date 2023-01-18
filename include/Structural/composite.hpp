//
// Created by 12865 on 2022/12/27.
//

/*
 * Compose objects into tree structure to represent part-whole
 * hierarchies. Composite lets client treat individual objects and
 * compositions of objects uniformly.
 *
 * 将一组对象组织成树形结构，以表示“部分-整体”的层次结构。组合让客户端（代指代码的使用者）
 * 可以统一单个对象和组合对象的处理逻辑。
 */

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

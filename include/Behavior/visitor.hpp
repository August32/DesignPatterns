//
// Created by DELL on 2023/1/6.
//

#ifndef DESIGNPATTERNS_VISITOR_HPP
#define DESIGNPATTERNS_VISITOR_HPP


#include <iostream>
#include <vector>


class PdfFile;

class WordFile;

class PPTFile;

// �����߳�����
// �ļ�����ͨ��ͳһ�Ľӿ�ȥִ�в�ͬ�Ĳ�������ͨ�����صķ�ʽʵ�ֶ�̬
class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(PdfFile &pdf_file) = 0;

    virtual void visit(WordFile &word_file) = 0;

    virtual void visit(PPTFile &ppt_file) = 0;
};

// �ļ�������
class ResourceFile {
public:
    explicit ResourceFile(std::string filepath)
            : m_filepath(std::move(filepath)) {}

    virtual ~ResourceFile() = default;

    virtual void accept(Visitor &visitor) = 0;

private:
    std::string m_filepath;

};

// �ļ������� - Pdf
class PdfFile : public ResourceFile {
public:
    explicit PdfFile(std::string filepath)
            : ResourceFile(std::move(filepath)) {}

    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

// �ļ������� - Word
class WordFile : public ResourceFile {
public:
    explicit WordFile(std::string filepath)
            : ResourceFile(std::move(filepath)) {}

    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

// �ļ������� - PPT
class PPTFile : public ResourceFile {
public:
    explicit PPTFile(std::string filepath)
            : ResourceFile(std::move(filepath)) {}

    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

// ��������� - Extractor
class Extractor : public Visitor {
public:
    void visit(PdfFile &pdf_file) override {
        std::cout << "Extract Pdf" << std::endl;
    }

    void visit(WordFile &word_file) override {
        std::cout << "Extract Word" << std::endl;
    }

    void visit(PPTFile &ppt_file) override {
        std::cout << "Extract PPT" << std::endl;
    }
};

// ��������� - Compressor
class Compressor : public Visitor {
public:
    void visit(PdfFile &pdf_file) override {
        std::cout << "Compressor Pdf" << std::endl;
    }

    void visit(WordFile &word_file) override {
        std::cout << "Compressor Word" << std::endl;
    }

    void visit(PPTFile &ppt_file) override {
        std::cout << "Compressor PPT" << std::endl;
    }
};

// **********************************************************************


void visitor_test() {
    Extractor extractor;
    Compressor compressor;

    ResourceFile *pdf_file = new PdfFile("a.pdf");
    ResourceFile *word_file = new WordFile("b.word");
    ResourceFile *ppt_file = new PPTFile("c.ppt");
    std::vector<ResourceFile *> files{pdf_file, word_file, ppt_file};

    // ִ�� extractor ����
    for (const auto &i : files) {
        i->accept(extractor);
    }

    // ִ�� compressor ����
    for (const auto &i : files) {
        i->accept(compressor);
    }

    delete pdf_file;
    delete word_file;
    delete ppt_file;
}


#endif //DESIGNPATTERNS_VISITOR_HPP

//
// Created by 12865 on 2022/12/27.
//

#ifndef DESIGNPATTERNS_FLYWEIGHT_HPP
#define DESIGNPATTERNS_FLYWEIGHT_HPP

#include <map>


// 享元产品类
class ChessPieceUnit {
public:
    enum Color {
        RED, BLACK
    };

public:
    ChessPieceUnit(int id, std::string text, Color color)
            : m_id(id),
              m_text(std::move(text)),
              m_color(color) {}

    ~ChessPieceUnit() = default;

private:
    int m_id;
    std::string m_text;
    Color m_color;
};

// 享元工厂类
class ChessPieceUnitFactory {
private:
    ChessPieceUnitFactory() = default;

    ~ChessPieceUnitFactory() = default;

private:
    static std::map<int, ChessPieceUnit *> m_cached_pieces;
    static ChessPieceUnit *m_piece_1;
    static ChessPieceUnit *m_piece_2;
    // ...

public:
    static ChessPieceUnit *get_piece(int id) {
        ChessPieceUnit *piece = nullptr;

        if (m_cached_pieces.find(id) != m_cached_pieces.end()) {
            piece = m_cached_pieces[id];
        }

        return piece;
    }

    static void delete_instance() {
        delete m_piece_1;
        m_piece_1 = nullptr;

        delete m_piece_2;
        m_piece_2 = nullptr;
    }
};

ChessPieceUnit *ChessPieceUnitFactory::m_piece_1 = new ChessPieceUnit(1, "車", ChessPieceUnit::BLACK);

ChessPieceUnit *ChessPieceUnitFactory::m_piece_2 = new ChessPieceUnit(2, "馬", ChessPieceUnit::RED);

std::map<int, ChessPieceUnit *> ChessPieceUnitFactory::m_cached_pieces = {
        {1, m_piece_1},
        {2, m_piece_2}
};

// 产品类（其对象包含享元产品对象）
class ChessPiece {
public:
    ChessPiece(ChessPieceUnit *unit, int position_X, int position_Y)
            : m_chess_piece_unit(unit),
              m_position_X(position_X),
              m_position_Y(position_Y) {}

    ~ChessPiece() = default;

private:
    ChessPieceUnit *m_chess_piece_unit;
    int m_position_X;
    int m_position_Y;
};

// 调用类（调用产品对象）
class ChessBoard {
public:
    ChessBoard() {
        init();
    }

    ~ChessBoard() = default;

public:
    void init() {
        m_chess_pieces.emplace(1, ChessPiece(ChessPieceUnitFactory::get_piece(1), 0, 0));
        m_chess_pieces.emplace(2, ChessPiece(ChessPieceUnitFactory::get_piece(2), 1, 0));
        // ...
    }

    void move() {
        // ...
    }

private:
    std::map<int, ChessPiece> m_chess_pieces{};
};


#endif //DESIGNPATTERNS_FLYWEIGHT_HPP

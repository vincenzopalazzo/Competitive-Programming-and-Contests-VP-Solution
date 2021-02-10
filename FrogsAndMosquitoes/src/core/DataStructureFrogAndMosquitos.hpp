//
// Created by vincent on 2/9/21.
//
struct Frog {
    int length_tongue;
    int position;
    int mosquito_eaten = 0;
    std::size_t input_pos;

    Frog(int position, int lengthTongue, std::size_t input_pos):
        position(position), length_tongue(lengthTongue), input_pos(input_pos) {
    }

    bool operator <(Frog const &a)const{
        return position < a.position;
    }
};

struct Mosquito {
    int position;
    int dimension;

    Mosquito(int position, int dimension){
        this->dimension = dimension;
        this->position = position;
    }
};

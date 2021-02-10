//
// Created by vincent on 2/9/21.
//
template<typename T>
struct Frog {
    T length_tongue;
    std::size_t position;
    T mosquito_eaten = 0;
    std::size_t input_pos;

    Frog(std::size_t position, T lengthTongue, std::size_t input_pos):
        position(position), length_tongue(lengthTongue), input_pos(input_pos) {
    }

    bool operator <(Frog const &a)const{
        return position < a.position;
    }
};

template<typename T>
struct Mosquito {
    std::size_t position;
    T dimension;

    Mosquito(std::size_t position, T dimension){
        this->dimension = dimension;
        this->position = position;
    }
};

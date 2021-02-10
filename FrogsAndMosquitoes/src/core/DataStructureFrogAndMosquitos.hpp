//
// Created by vincent on 2/9/21.
//
struct Frog {
    int length_tongue;
    int position;
    int mosquito_eaten = 0;

    Frog(int position, int lengthTongue){
        this->length_tongue = lengthTongue;
        this->position = position;
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

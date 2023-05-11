// Copyright 2023 Uvarkin Ilya

#pragma once

#include <vector>

class Set{
public:
    void insert(int elem);
    void erase(int elem);
    int count(int elem);

    Set()= default;
    explicit Set(const std::vector<int> &elems) : elems(elems) {}
private:
    std::vector<int> elems;
};

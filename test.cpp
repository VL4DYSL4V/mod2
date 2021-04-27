//
// Created by владислав on 27.04.2021.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "collection/List.h"
#include "collection/ArrayList.h"

TEST_CASE() {
    List<int> *list = new ArrayList<int>();
    list->add(10);
    REQUIRE(list->size() == 1);
}

TEST_CASE() {
    List<int> *list = new ArrayList<int>();
    for (int i = 0; i < 10; i++) {
        list->add(i);
    }
    list->remove(0);
    REQUIRE(list->size() == 9);
}

TEST_CASE(){
    List<int> *list = new ArrayList<int>();
    list->add(0);
    REQUIRE_THROWS(list->get(-1));
}
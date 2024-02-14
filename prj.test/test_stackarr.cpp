#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarr/stackarr.hpp"

TEST_CASE("stackarr IsEmpty") {
    StackArr arr;
    CHECK_EQ(arr.IsEmpty(), true);
    Complex x(1.8, 9.0);
    arr.Push(x);
    CHECK_EQ(arr.IsEmpty(), false);
    arr.Pop();
    CHECK_EQ(arr.IsEmpty(), true );
}

TEST_CASE("Clear") {
    StackArr arr;
    Complex x;
    arr.Push(x);
    arr.Push(x);
    CHECK_EQ(arr.IsEmpty(), false);
    arr.Clear();
    CHECK_EQ(arr.IsEmpty(),true);
}

TEST_CASE("Is Top") {
    StackArr arr;
    Complex x(3.6, 7.1);
    Complex y(5.7, 9.8);
    Complex z(4.7, 8.0);
    arr.Push(x);
    arr.Push(y);
    CHECK_EQ(arr.Top(), y);
    arr.Push(z);
    arr.Push(y);
    CHECK_EQ(arr.Top(), y);
    arr.Push(y);
    arr.Pop();
    arr.Pop();
    CHECK_EQ(arr.Top(), z);
}
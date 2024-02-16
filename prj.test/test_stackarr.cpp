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
    CHECK_EQ(arr.IsEmpty(), true);
}

TEST_CASE("Clear") {
    StackArr arr;
    Complex x;
    arr.Push(x);
    arr.Push(x);
    CHECK_EQ(arr.IsEmpty(), false);
    arr.Clear();
    CHECK_EQ(arr.IsEmpty(), true);
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

TEST_CASE("Cycle") {
    StackArr st;
    Complex a;
    float b = 0;
    for (int i = 0; i < 10; i++) {
        b += 1.0;
        a = { b, 0 };
        st.Push(a);
    }
    CHECK_EQ(st.Top(), Complex{ b, 0 });
}

TEST_CASE("=") {
    StackArr st;
    Complex a(8.5, 9.6);
    Complex b(7.3, 8.4);
    Complex c(0.0, 5.1);
    st.Push(a);
    st.Push(c);
    StackArr st2;
    StackArr st3;
    st2 = st;
    st3 = st2;
    st3.Pop();
    st3.Push(b);
    CHECK_EQ(st.Top(), st2.Top());
    CHECK_EQ(st3.Top(), b);
}

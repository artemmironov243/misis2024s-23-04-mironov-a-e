#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuearr/queuearr.hpp"


TEST_CASE("QueueArr - default ctor") {
	QueueArr queue;
	CHECK(queue.IsEmpty());
}

TEST_CASE("TOPPPPP") {
	QueueArr arr;
	arr.Push(Complex{ 1, 1 });
	arr.Push(Complex{ 2, 2 });
	arr.Pop();
	QueueArr arr2(arr);
	CHECK(arr2.Top() == Complex{ 2, 2 });

}

TEST_CASE("QueueLst - IsEmpty") {
	QueueArr queue;
	CHECK(queue.IsEmpty());
	queue.Push(Complex{ 1, 1 });
	CHECK(!queue.IsEmpty());
	queue.Pop();
	CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLst - Pop") {
	QueueArr queue;
	queue.Push(Complex{ 1, 1 });
	queue.Push(Complex{ 2, 2 });
	queue.Push(Complex{ 3, 3 });
	queue.Pop();
	CHECK(queue.Top() == Complex{ 2, 2 });
	queue.Pop();
	CHECK(queue.Top() == Complex{ 3, 3 });
	queue.Pop();
	CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLst - Push") {
	QueueArr st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	CHECK_EQ(st.IsEmpty(), 1);
	st.Push(a);
	st.Push(b);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("QueueLst - Top") {
	QueueArr st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("QueueLst - Clear") {
	QueueArr st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	st.Clear();
	CHECK_EQ(st.IsEmpty(), 1);
}

TEST_CASE("QueueLst - copy ctor") {
	QueueArr queue;
	queue.Push(Complex{ 1, 1 });
	queue.Push(Complex{ 2, 2 });
	queue.Push(Complex{ 3, 3 });
	QueueArr copy(queue);
	CHECK(queue.Top() == copy.Top());
	queue.Pop();
	CHECK(queue.Top() != copy.Top());
}

TEST_CASE("QueueLst - copy assignment") {
	QueueArr queue;
	queue.Push(Complex{ 1, 1 });
	queue.Push(Complex{ 2, 2 });
	queue.Push(Complex{ 3, 3 });
	QueueArr copy;
	copy.Push(Complex{ 4, 4 });
	copy.Push(Complex{ 5, 5 });
	copy.Push(Complex{ 6, 6 });
	copy = queue;
	CHECK(queue.Top() == copy.Top());
	queue.Pop();
	CHECK(queue.Top() != copy.Top());
}
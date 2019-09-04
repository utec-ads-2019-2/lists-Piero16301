cmake_minimum_required(VERSION 3.14)
project(Listas)

set(CMAKE_CXX_STANDARD 17)

add_executable(Listas main.cpp iterators/bidirectional_iterator.h iterators/forward_iterator.h mock/mocker.cpp mock/mocker.h test/tester.cpp test/tester.h circular.h forward.h iterator.h linked.h list.h node.h)
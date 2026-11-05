#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <iostream>

// ============================================================
// PART 2 Tests: DoublyLinkedList
// ============================================================

/// Create a DoublyLinkedList. Verify length() is 0 on a new list.
void test_new_list_is_empty(void)
{
    DoublyLinkedList list;
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, list.length(), "TODO: Implement this test");
}

/// Create a DoublyLinkedList. Call pushFrontValue and pushBackValue.
/// Verify length() is 2.
void test_push_increases_length(void)
{
    DoublyLinkedList list;
    list.pushFrontValue(NodeValue{1});
    list.pushBackValue(NodeValue{2});
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, list.length(), "TODO: Implement this test");
}

/// Create an EMPTY DoublyLinkedList.
/// Verify popFrontValue() and popBackValue() both have NO value (has_value() is false).
void test_pop_on_empty_list(void)
{
    DoublyLinkedList list;
    TEST_ASSERT_FALSE_MESSAGE(list.popFrontValue().has_value(), "TODO: Implement this test");
    TEST_ASSERT_FALSE_MESSAGE(list.popBackValue().has_value(), "TODO: Implement this test");
}

/// Push 1, 2, 3 with pushBackValue.
/// Verify popBackValue() gives 3, then popFrontValue() gives 1, then length() is 1.
void test_pop_order(void)
{
    DoublyLinkedList list;
    list.pushBackValue(NodeValue{1});
    list.pushBackValue(NodeValue{2});
    list.pushBackValue(NodeValue{3});
    TEST_ASSERT_EQUAL_INT_MESSAGE(3, std::get<int>(list.popBackValue().value()), "TODO: Implement this test");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, std::get<int>(list.popFrontValue().value()), "TODO: Implement this test");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, list.length(), "TODO: Implement this test");
}

/// Push one value, then call deleteValue with a value that is NOT in the list.
/// Verify it returns false and length() does not change.
void test_delete_value_not_found(void)
{
    DoublyLinkedList list;
    list.pushBackValue(NodeValue{1});
    TEST_ASSERT_FALSE_MESSAGE(list.deleteValue(NodeValue{2}), "TODO: Implement this test");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, list.length(), "TODO: Implement this test");
}

/// Push 1, 2, 3 with pushBackValue. Call deleteValue(2).
/// Verify popBackValue() gives 3 and the next popBackValue() gives 1.
/// (popBackValue follows prevPtr: this fails if you forgot to repair the backward link.)
void test_delete_middle_keeps_links(void)
{
    DoublyLinkedList list;
    list.pushBackValue(NodeValue{1});
    list.pushBackValue(NodeValue{2});
    list.pushBackValue(NodeValue{3});
    list.deleteValue(NodeValue{2});

    TEST_ASSERT_EQUAL_INT_MESSAGE(3, std::get<int>(list.popBackValue().value()), "TODO: Implement this test");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, std::get<int>(list.popBackValue().value()), "TODO: Implement this test");
}

// ============================================================
// PART 3 Tests: StdDoublyLinkedList
// ============================================================

/// Push 1, 2, 1 with pushBackValue. Call deleteValue(NodeValue{1}).
/// Verify length() is 2 and popFrontValue() gives 2 (only the FIRST 1 was removed).
void test_std_delete_only_first(void)
{
    StdDoublyLinkedList list;
    list.pushBackValue(NodeValue{1});
    list.pushBackValue(NodeValue{2});
    list.pushBackValue(NodeValue{1});
    list.deleteValue(NodeValue{1});
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, list.length(), "TODO: Implement this test");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, std::get<int>(list.popFrontValue().value()), "TODO: Implement this test");
}

/// Create an EMPTY StdDoublyLinkedList.
/// Verify popFrontValue() and popBackValue() have NO value and do not crash.
void test_std_pop_on_empty_list(void)
{
    StdDoublyLinkedList list;
    TEST_ASSERT_FALSE_MESSAGE(list.popFrontValue().has_value(), "TODO: Implement this test");
    TEST_ASSERT_FALSE_MESSAGE(list.popBackValue().has_value(), "TODO: Implement this test");
}

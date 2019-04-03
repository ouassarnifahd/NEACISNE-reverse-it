#ifndef __PREPROCESSOR_EXPANDING_COMMANDS__
#define __PREPROCESSOR_EXPANDING_COMMANDS__

#include <stdarg.h>
// TODO make the preprocessor do a for loop using reccursive expantions
// https://stackoverflow.com/questions/319328/writing-a-while-loop-in-the-c-preprocessor

#define EMPTY()
#define DEFER(id) id EMPTY()
#define OBSTRUCT(id) id DEFER(EMPTY)()
#define EXPAND(...) __VA_ARGS__

#define CAT(a, ...) _CAT(a, __VA_ARGS__)
#define _CAT(a, ...) a ## __VA_ARGS__

#define CHECK_N(x, n, ...) n
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)

#define NOT(x) CHECK(_CAT(NOT_, x))
#define NOT_0 ~, 1,

// logics
#define COMPL(b) _CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0

#define BOOL(x) COMPL(NOT(x))

// po mal
#define IIF(c) _CAT(IIF_, c)
#define IIF_0(t, ...) __VA_ARGS__
#define IIF_1(t, ...) t

#define IF(c) IIF(BOOL(c))

// this hurts the preprocessor but usefull
#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

// check if x == 0
#define IS_0(x) CHECK(_CAT(IS_0_, x))
#define IS_0_0 ~, 1,

// #define PRED(x, ...) COMPL(IS_1(NARGS(__VA_ARGS__)))

#define PRED(commandsTable, number) COMPL(IF(IS_0(number--))))

// operation
#define OP(commandsTable, id) CAT(CAT("&server_", commandsTable[id][0]), ",\n")
#define M(...) CAT(__VA_ARGS__)

// while
#define WHILE(pred, op, ...) \
    IF(pred(__VA_ARGS__)) \
    ( \
        OBSTRUCT(WHILE_INDIRECT) () \
        ( \
            pred, op, op(__VA_ARGS__) \
        ), \
        __VA_ARGS__ \
    )
#define WHILE_INDIRECT() WHILE

#endif /* end of include guard: __PREPROCESSOR_EXPANDING_COMMANDS__ */

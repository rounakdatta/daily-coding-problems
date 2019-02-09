-module(5).
-export([start/0]).

start() ->
    io:format("This is ~p~n", [car(1234, 5678)]),
    io:format("This is ~p~n", [cdr(1111, 9999)]).


pair(A, B) ->
    {A, B}.

cons(A, B) ->
    P = pair(A, B),
    P.

car(A, B) ->
    {FirstValue, _} = pair(A, B),
    FirstValue.

cdr(A, B) ->
    {_, SecondValue} = pair(A, B),
    SecondValue.
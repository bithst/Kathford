likes_food("Bhogendra", X):-
	food(X).
food("Oranges").
food("Chicken").
likes("Shailendra", X):-
	likes_food("Bhogendra", X).
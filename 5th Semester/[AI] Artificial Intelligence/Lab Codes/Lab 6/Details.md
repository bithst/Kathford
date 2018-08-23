# Lab 6 | FOPL

> Date: Baisakh 11 | April 24

## Premises #1

1. Every American who sells weapon to hostile nations is a criminal.
2. Every enemy of America is hostile.
3. Iraq has some missiles.
4. All missiles of Iraq were sold by George.
5. George is an American.
6. Iraq is a country.
7. Iraq is the enemy of America.
8. Missiles are weapons.

**Goal:** Is George a criminal?
[Solution](./Knowledge%20Base%20[1].pl)

```none
?- criminal("George").
true.
```

## Premises #2

Bhogendra likes all kinds of food. Oranges are food. Chicken is food. Anything anyone eats and is not killed by food. If a person likes a food means that person has eaten it. Jogendra eats peanuts and is still alive. Shailendra eats everyhting Bhogendra eats.

**Goal:** Does Shailendra like chicken?
[Solution](./Knowledge%20Base%20[1].pl)

```none
?- likes("Shailendra", "Chicken").
true.
```
# Lab 5 | FOPL

> Date: Baisakh 04 | April 17

## FOPL

### Premises [1]

1. Horses are mammal.
2. An offspring of a horse is a horse.
3. Bluebird is Charlie's parent.
4. Offspring and parents are inverse relations.
5. Every mammal has a parent.
6. Bluebird is a horse.

**Goal:** Is Charlie a mammal?

### Premises [2]

1. All Pompeians are Romans.
2. All Romans, were either loyal to Caesar or hated him.
3. Everyone is loyal to someone.
4. People only try to assassinate rulers they are not loyal to.
5. Marcus tried to assissinate Caesar.
6. Marcus was Pompeian.

**Goal:** Did Marcus hate Caesar?

```none
?- hate("marcus", "caesar").
true.
```